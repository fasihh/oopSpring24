#include <iostream>

class Graphics {
public:
    void render() { std::cout << "Rendering graphics..." << std::endl; }
};

class InputHandler {
public:
    void movement() { std::cout << "Handling input for movement..." << std::endl; }
};

class Physics {
public:
    void run() { std::cout << "Simulating physics..." << std::endl; }
};

class Game {
private:
    Graphics graphics;
    InputHandler inputHandler;
    Physics physics;
public:
    void run() {
        // usually in a game loop
        graphics.render();
        inputHandler.movement();
        physics.run();
    }
};

int main() {
    Game game;
    game.run();

    return 0;
}