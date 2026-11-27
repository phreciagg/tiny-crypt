#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>

int main() {
    sf::VideoMode mode({800, 600});
    sf::RenderWindow window(mode, "tiny-crypt");
    sf::RectangleShape player({40.f, 40.f});
    player.setPosition({380, 280});
    sf::Clock frameClock({});
    while (window.isOpen()) {
        auto elapsed = frameClock.restart();
        float deltaSeconds = elapsed.asSeconds();
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
            player.move({direction.x * (200.f * deltaSeconds),
                         direction.y * (200.f * deltaSeconds)});
            window.clear();
            window.draw(player);
            window.display();
        }
    }
    return 0;
}
