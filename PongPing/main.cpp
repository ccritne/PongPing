#include <SFML/Graphics.hpp>
#include <iostream>

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 500;

const float PLAYER_WIDTH = 10.f;
const float PLAYER_HEIGTH = 120.f;

const int speed = 5;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong Ping");
    sf::RectangleShape pLeft(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGTH));
    sf::RectangleShape pRight(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGTH));

    pLeft.setPosition(0, float(WIN_HEIGHT) / 2.f - PLAYER_HEIGTH / 2.f);
    pRight.setPosition(WIN_WIDTH - PLAYER_WIDTH, float(WIN_HEIGHT) / 2.f - PLAYER_HEIGTH / 2.f);

    //Maybe I can create a class
    float lUp = pLeft.getPosition().y;
    float rUp = pRight.getPosition().y;

    float lDown = pLeft.getPosition().y + PLAYER_HEIGTH;
    float rDown = pRight.getPosition().y + PLAYER_HEIGTH;
    std::cout << "Initial condition: " << std::endl;
    std::cout << "L: (" << lUp << ", " << lDown << ") R: (" << rUp << ", " << rDown << ")" << std::endl;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && lUp > 0)
                    pLeft.move(0, -speed), lUp -= speed, lDown -= speed;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && lDown < WIN_HEIGHT)
                    pLeft.move(0, speed), lUp += speed, lDown += speed;

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rUp > 0)
                    pRight.move(0, -speed), rUp -= speed, rDown -= speed;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rDown < WIN_HEIGHT)
                    pRight.move(0, speed), rDown += speed, rDown += speed;
            
                std::cout << "L: (" << lUp << ", " << lDown << ") R: (" << rUp << ", " << rDown << ")" << std::endl;
            }
                
        }

        window.clear();
        window.draw(pLeft);
        window.draw(pRight);
        window.display();
    }

    return 0;
}