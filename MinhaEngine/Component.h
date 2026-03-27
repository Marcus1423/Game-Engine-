#pragma once

class GameObject;

class Component {
public:
    GameObject* owner = nullptr;

    virtual void start() {}
    virtual void update(float deltaTime) {}
    virtual void render() {}

    virtual ~Component() {}
};