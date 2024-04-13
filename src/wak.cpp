#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <iostream>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "W.A.K" };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
}

void main_menu()
void help_menu()
void game_loop(sf::RenderWindow &window)
{
    int num = 0;
    char cpu_choice;
    char player_choice;

    num = rand() % 100;

    if (num <= 33)
        cpu_choice = 'w';
    else if (num >= 34 && num <= 66)
        cpu_choice = 'k';
    else if (num >= 67 && num <= 99 )
        cpu_choice = 'a';

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::KeyReleased(sf::Keyboard::W))
                player_choice = 'w';
            else if (event.type == sf::Event::KeyReleased(sf::Keyboard::K))
                player_choice = 'k';
            else if (event.type == sf::Event::KeyReleased(sf::Keyboard::A))
                player_choice = 'a'
        }
    }
}