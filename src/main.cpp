#include <iostream>
#include "express-draw-opengl-glfw/OpenGL_GLFW_Context.h"
#include "express-draw/Draw.h"
#include "express-draw/DrawTypes.h"
#include "express-draw/Frame.h"
#include "express-draw/Camera.h"
#include "express-draw/CameraTypes.h"

int main() {

    auto setupWindowHints = [](){
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE); //see-through window
        glfwWindowHint(GLFW_FLOATING, GLFW_TRUE); // always on top window
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
    static const auto pixelsPerMeter = 10.F;
    const auto camera = Draw::OrthographicSceneCamera{
            .zoom=1.F/pixelsPerMeter
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

        Draw::draw(context, Draw::Quad{
                .transform =Draw::Transform2D::from(
                        -15.F, -15.F,
                        0.F,
                        10.F, 1.F),
                .color{1.F, 0.F, 0.F, 1.F},
                .pivotPoint=Draw::PIVOT_POINT::CENTER
        });

        Draw::draw(context, Draw::Quad{
                .transform =Draw::Transform2D::from(
                        -15.F, -15.F,
                        0.F,
                        1.F, 10.F),
                .color{0.F, 1.F, 0.F, 1.F},
                .pivotPoint=Draw::PIVOT_POINT::CENTER
        });


        Draw::endFrame(context);
    }

    return 0;
}
