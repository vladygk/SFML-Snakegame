#include <iostream>
#include <SFML/Graphics.hpp>

const int WIDTH = 800;
const int HEIGHT = 500;
const int WALL_TILE_WIDTH = 10;
const int WALL_TILE_HEIGHT = 10;
sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake game");

int startGame();
void generateWalls(bool& isWallDone);

int main() {
    startGame();
    return 0;
}

int startGame() {
    bool isWallDone = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        // Draw here

        if(!isWallDone) {
            generateWalls(isWallDone);
        }


    }
    return 0;
}

void generateWalls(bool& isWallDone){
    const int DESIRED_TILE_NUMBER_BY_WIDTH = WIDTH / WALL_TILE_WIDTH;
    const int DESIRED_TILE_NUMBER_BY_HEIGHT = HEIGHT / WALL_TILE_HEIGHT;
    const int UPPER_WALL_Y = 0;
    const int LOWER_WALL_Y = HEIGHT-WALL_TILE_HEIGHT;
    const int LEFT_WALL_X = 0;
    const int RIGHT_WALL_X = WIDTH-WALL_TILE_WIDTH;
    
    for (int i = 0; i < DESIRED_TILE_NUMBER_BY_WIDTH; ++i) {
        sf::RectangleShape tileUp(sf::Vector2f(WALL_TILE_WIDTH, WALL_TILE_HEIGHT));
        sf::RectangleShape tileDown(sf::Vector2f(WALL_TILE_WIDTH, WALL_TILE_HEIGHT));

        if(i%2==0){
            tileDown.setFillColor(sf::Color::Green);
            tileUp.setFillColor(sf::Color::Red);
        }else{
            tileDown.setFillColor(sf::Color::Red);
            tileUp.setFillColor(sf::Color::Green);
        }

        tileUp.setPosition(WALL_TILE_WIDTH * i, UPPER_WALL_Y);
        tileDown.setPosition(WALL_TILE_WIDTH * i ,LOWER_WALL_Y);
        
        window.draw(tileUp);
        window.draw(tileDown);

        window.display();
        sf::sleep(sf::Time(sf::milliseconds(20)));
    }
    
    for (int i = 0; i < DESIRED_TILE_NUMBER_BY_HEIGHT; ++i) {
        sf::RectangleShape tileLeft(sf::Vector2f(WALL_TILE_WIDTH, WALL_TILE_HEIGHT));
        sf::RectangleShape tileRight(sf::Vector2f(WALL_TILE_WIDTH, WALL_TILE_HEIGHT));

        if(i%2==0){
            tileRight.setFillColor(sf::Color::Green);
            tileLeft.setFillColor(sf::Color::Red);
        }else{
            tileRight.setFillColor(sf::Color::Red);
            tileLeft.setFillColor(sf::Color::Green);
        }
        
        tileLeft.setPosition(LEFT_WALL_X, WALL_TILE_HEIGHT * i);
        tileRight.setPosition(RIGHT_WALL_X, WALL_TILE_HEIGHT * i);

        window.draw(tileLeft);
        window.draw(tileRight);

        window.display();
        sf::sleep(sf::Time(sf::milliseconds(15)));
    }
    isWallDone = true;
}
