#include <iostream>
#include "express-draw-opengl-glfw/OpenGL_GLFW_Context.h"
#include "express-draw/Draw.h"
#include "express-draw/DrawTypes.h"
#include "express-draw/Frame.h"
#include "express-draw/Camera.h"
#include "express-draw/CameraTypes.h"
#include "OverlayInputHandler.h"
#include "State.h"


void drawBorder(Draw::OpenGL_GLFW_Context& context) {
    Draw::drawWireframe(context, Draw::Quad{
            .transform =Draw::Transform2D::from(
                    1.F,1.0F,
                    0.F,
                    context.openglWindow->width-2.F, context.openglWindow->height-2.0F),
            .color{1.F, 0.F, 0.F, 0.8F},
            .pivotPoint=Draw::PIVOT_POINT::TOP_LEFT
    });

    Draw::drawWireframe(context, Draw::Quad{
            .transform =Draw::Transform2D::from(
                    11.F,11.F,
                    0.F,
                    context.openglWindow->width-22.F, context.openglWindow->height-22.0F),
            .color{0.5F, 0.F, 0.F, 0.4F},
            .pivotPoint=Draw::PIVOT_POINT::TOP_LEFT
    });
}


int main() {
    auto* state = new State{};

    auto setupWindowHints = [](){
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE); //see-through window
        glfwWindowHint(GLFW_FLOATING, GLFW_TRUE); // always on top window
    };

    auto context = Draw::OpenGL_GLFW_Context{
        OpenGLWindow::Props{
            .title{"window"},
            .size{1024, 768},
            .preCreateWindowHook = setupWindowHints
        }
    };
    context.clearColor = glm::vec4(0.F, 0.F, 0.F, 0.F);

    context.addDirectoryToFileHashes("assets/");
    auto camera = Draw::OrthographicSceneCamera{
            .zoom=1.F
    };
    const auto uiCamera = Draw::OrthographicSceneCamera{
            .position = {300, -200},
            .zoom=1.F
    };

    auto* input = new OverlayInputHandler{*state};
    context.openglWindow->setInputHandler(input);

    while(context.isRunning()) {
        Draw::startFrame(context);
        const auto width = context.openglWindow->width;
        const auto height = context.openglWindow->height;
        camera.position = {width/2.F, -height/2.F};
        Draw::setCamera(context, camera, {
            .size{width, height},
            .up = Draw::UP_AXIS::NEGATIVE_Y
        });

        drawBorder(context);

        for(const auto& segment: state->lines) {
            for (int i = 0; i+1 < segment.size(); i++) {
                Draw::drawWireframe(context, Draw::Line{
                    .startPosition = segment[i],
                    .endPosition = segment[i+1],
                    .color = glm::vec4{0.F, 0.F, 1.F, 1.F},
                    .lineWidth = 3.F
                });
            }
        }

        Draw::endFrame(context);
    }

    return 0;
}
