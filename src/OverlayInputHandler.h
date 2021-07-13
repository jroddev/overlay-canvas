#ifndef OVERLAY_CANVAS_OVERLAY_INPUT_HANDLER_H
#define OVERLAY_CANVAS_OVERLAY_INPUT_HANDLER_H

#include "express-draw-opengl-glfw/OpenGL_GLFW_Context.h"
#include "State.h"
#include <set>
#include <vector>

class OverlayInputHandler : public InputHandler {
public:
    explicit OverlayInputHandler(State& _state);
    void receiveKeyboardInput(int key, int scancode, int action, int mods) override;
    void receiveMouseButton(int button, int action, int mods) override;
    void receiveMousePosition(double xPos, double yPos) override;

private:
    State& state;
};


#endif //OVERLAY_CANVAS_OVERLAY_INPUT_HANDLER_H
