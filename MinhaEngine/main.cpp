#include "Engine.h"
#include "GameScene.h"

int main() {
    Engine engine;

    if (!engine.init()) return -1;

    Scene* scene = new GameScene();

    engine.setScene(scene);

    engine.run();
    engine.clean();

    return 0;
}