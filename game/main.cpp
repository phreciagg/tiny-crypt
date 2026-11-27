#include <SFML/Graphics/RenderWindow.hpp>

int main() {
    sf::VideoMode mode({800, 600});
    sf::RenderWindow window(mode, "tiny-crypt");
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }
    return 0;
}
