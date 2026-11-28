#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <array>

int main() {
    sf::VideoMode mode({800, 600});
    sf::RenderWindow window(mode, "tiny-crypt");
    sf::RectangleShape player({40.f, 40.f});
    player.setPosition({380, 280});
    sf::RectangleShape rightWall({24, 320});
    rightWall.setPosition({560, 140});
    sf::RectangleShape leftWall({24, 320});
    leftWall.setPosition({240, 140});
    sf::RectangleShape topWall({344, 24});
    topWall.setPosition({240, 140});
    sf::RectangleShape bottomWall({344, 24});
    bottomWall.setPosition({240, 436});
    std::array walls{rightWall, leftWall, topWall, bottomWall};
    sf::Clock frameClock({});
    while (window.isOpen()) {
        auto elapsed{frameClock.restart()};
        float deltaSeconds{elapsed.asSeconds()};
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        if (window.isOpen()) {
            sf::Vector2f direction({0.f, 0.f});
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                direction.x += 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                direction.x -= 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                direction.y += 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                direction.y -= 1.f;
            }
            if (direction.x != 0 || direction.y != 0) {
                direction = direction.normalized();
            }
            auto previousPosition{player.getPosition()};
            auto stepX{direction.x * (200.f * deltaSeconds)};
            auto stepY{direction.y * (200.f * deltaSeconds)};
            player.move({stepX, 0.f});
            auto playerBounds{player.getGlobalBounds()};
            for (const auto& wall : walls) {
                if (playerBounds.findIntersection(wall.getGlobalBounds())) {
                    player.setPosition(previousPosition);
                    break;
                }
            }
            previousPosition = player.getPosition();
            player.move({0.f, stepY});
            playerBounds = player.getGlobalBounds();
            for (const auto& wall : walls) {
                if (playerBounds.findIntersection(wall.getGlobalBounds())) {
                    player.setPosition(previousPosition);
                    break;
                }
            }
            window.clear();
            for (const auto& wall : walls) {
                window.draw(wall);
            }
            window.draw(player);
            window.display();
        }
    }
    return 0;
}
