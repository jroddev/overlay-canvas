#include <iostream>
#include "express-draw-opengl-glfw/OpenGL_GLFW_Context.h"
#include "express-draw/Draw.h"
#include "express-draw/DrawTypes.h"
#include "express-draw/Frame.h"
#include "express-draw/Camera.h"
#include "express-draw/CameraTypes.h"


void drawBorder(Draw::OpenGL_GLFW_Context& context) {
    Draw::drawWireframe(context, Draw::Quad{
            .transform =Draw::Transform2D::from(
                    0.F,0.0F,
                    0.F,
                    context.openglWindow->width-2.F, context.openglWindow->height-2.0F),
            .color{1.F, 0.F, 0.F, 0.8F},
            .pivotPoint=Draw::PIVOT_POINT::CENTER
    });

    Draw::drawWireframe(context, Draw::Quad{
            .transform =Draw::Transform2D::from(
                    0.F,0.F,
                    0.F,
                    context.openglWindow->width-22.F, context.openglWindow->height-22.0F),
            .color{0.5F, 0.F, 0.F, 0.4F},
            .pivotPoint=Draw::PIVOT_POINT::CENTER
    });
}


int main() {

    auto setupWindowHints = [](){
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE); //see-through window
        glfwWindowHint(GLFW_FLOATING, GLFW_TRUE); // always on top window
//        glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    };

    auto context = Draw::OpenGL_GLFW_Context{
        OpenGLWindow::Props{
            .title{"window"},
            .size{600, 400},
            .preCreateWindowHook = setupWindowHints
        }
    };
    context.clearColor = glm::vec4(0.F, 0.F, 0.F, 0.F);

    context.addDirectoryToFileHashes("assets/");
    const auto camera = Draw::OrthographicSceneCamera{
            .zoom=1.F
    };
    const auto uiCamera = Draw::OrthographicSceneCamera{
            .position = {300, -200},
            .zoom=1.F
    };


    while(context.isRunning()) {

        Draw::startFrame(context);
        Draw::setCamera(context, camera, {
            .size{context.openglWindow->width, context.openglWindow->height},
            .up = Draw::UP_AXIS::NEGATIVE_Y
        });

        drawBorder(context);

        Draw::endFrame(context);
    }

    return 0;
}
