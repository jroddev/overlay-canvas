#ifndef OVERLAY_CANVAS_STATE_H
#define OVERLAY_CANVAS_STATE_H

struct State {
    bool drawing = false;
    std::vector<std::vector<glm::vec2>> lines;
};

#endif //OVERLAY_CANVAS_STATE_H
