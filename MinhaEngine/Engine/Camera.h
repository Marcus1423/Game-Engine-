#pragma once
class Camera {
public:
    float x = 0;
    float y = 0;

    float width = 800;
    float height = 600;

    void follow(float targetX, float targetY);
};