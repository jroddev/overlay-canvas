#include "OverlayInputHandler.h"
#include <iostream>

void OverlayInputHandler::receiveMousePosition(double xPos, double yPos) {
    if (state.drawing) {
        const auto mousePos = glm::vec2{xPos, yPos};
        auto& segment = state.lines[state.lines.size()-1];
        if (segment.empty()  || glm::distance(segment[segment.size()-1], mousePos) > 10.F) {
            segment.emplace_back(glm::vec2{xPos, yPos});
        }
    }
}

void OverlayInputHandler::receiveMouseButton(int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "Start drawing" << std::endl;
        state.drawing = true;
        state.lines.emplace_back(std::vector<glm::vec2>{});
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        std::cout << "Stop drawing" << std::endl;
        state.drawing = false;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
        state.lines.clear();
    }
}

void OverlayInputHandler::receiveKeyboardInput(int key, int scancode, int action, int mods) {

}

OverlayInputHandler::OverlayInputHandler(State &_state):state(_state) {

}
