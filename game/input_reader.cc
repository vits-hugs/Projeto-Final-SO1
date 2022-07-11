#include "input_reader.h"
#include <iostream>
#include <SFML/Graphics.hpp>

short int InputReader::get_inputs() {
    sf::Event event;
    switch (event.type) {
            case sf::Event::Closed:
                 //window.close();
                 break;
            
            // key pressed
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    std::cout << "Keyboard esquerda!" << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
                } else
                    std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                break;
            
            }
}