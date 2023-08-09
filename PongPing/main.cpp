#include <SFML/Graphics.hpp>
#include <iostream>

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 500;

const float PLAYER_WIDTH = 10.f;
const float PLAYER_HEIGTH = 120.f;

const float BALL_RADIUS = 5.f;

const float speed = 5.f;

class Player : public sf::Drawable, public sf::Transformable{
    private:
        sf::RectangleShape player;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            target.draw(player);
        }
    public:
        float coordUp, coordDown;
        Player();
        void move(float x, float y);
        sf::Vector2f getPosition();
        void setPosition(float x, float y);
        
};

Player::Player() {

    player.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGTH));

    sf::RectangleShape pRight(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGTH));

}

void Player::move(float x, float y) {
    player.move(x, y);
}

sf::Vector2f Player::getPosition() {
    return player.getPosition();
}

void Player::setPosition(float x, float y) {
    player.setPosition(x, y);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong Ping");
    window.setVerticalSyncEnabled(true);

    Player left, right;
    sf::CircleShape ball(BALL_RADIUS);
    ball.setPosition(float(WIN_WIDTH) / 2 - BALL_RADIUS, float(WIN_HEIGHT) / 2 - BALL_RADIUS);

    left.setPosition(0, float(WIN_HEIGHT) / 2.f - PLAYER_HEIGTH / 2.f);
    right.setPosition(WIN_WIDTH - PLAYER_WIDTH, float(WIN_HEIGHT) / 2.f - PLAYER_HEIGTH / 2.f);

    left.coordUp = left.getPosition().y;
    right.coordUp = right.getPosition().y;

    left.coordDown = left.getPosition().y + PLAYER_HEIGTH;
    right.coordDown = right.getPosition().y + PLAYER_HEIGTH;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && left.coordUp > 0)
            left.move(0, -speed), left.coordUp -= speed, left.coordDown -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && left.coordDown < WIN_HEIGHT)
            left.move(0, speed), left.coordUp += speed, left.coordDown += speed;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && right.coordUp > 0)
            right.move(0, -speed), right.coordUp -= speed, right.coordDown -= speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && right.coordDown < WIN_HEIGHT)
            right.move(0, speed), right.coordUp += speed, right.coordDown += speed;

        window.clear();
        window.draw(left);
        window.draw(ball);
        window.draw(right);
        window.display();
    }

    return 0;
}