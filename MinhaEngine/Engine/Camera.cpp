#include "Camera.h"

void Camera::follow(float targetX, float targetY) {
    x = targetX - width / 2;
    y = targetY - height / 2;
}