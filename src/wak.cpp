#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <iostream>

int main()
{
    auto window = sf::RenderWindow{ { 900u, 900u }, "W.A.K" };
    window.setFramerateLimit(144);
    sf::Texture title_txt;
    sf::Sprite title;
    sf::Font font;
    sf::Text menu;

    title_txt.loadFromFile("/textures/Title.png");
    title.setTexture(title_txt);
    title.setPosition(sf::Vector2f(200.f, 50.f));
    font.loadFromFile("/Font/ARIAL.TTF");
    menu.setFont(font);
    menu.setString("Press 'P' to play or 'Q' to quit");
    menu.setCharacterSize(30);
    menu.setFillColor(sf::Color::White);
    menu.setPosition(sf::Vector2(700.f, 50.f));


    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased(sf::Keyboard::P))
                game_loop(sf::RenderWindow& window);
            if (event.type == sf::Event::KeyReleased(sf::Keyboard::Q))
                {
                    window.clear();
                    window.close();
                }
        }

        window.clear();
        window.draw(title);
        window.draw(menu);
        window.display();
    }
}

void game_loop(sf::RenderWindow& window)
{
    int num = 0;
    char cpu_choice;
    char player_choice;
    sf::Texture knight_txt, wizard_txt, archer_txt;
    sf::Sprite player_sprite, cpu_sprite;
    sf::Font font;
    sf::Text text;

    font.loadFromFile("/Font/ARIAL.TTF");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);

    knight_txt.loadFromFile("/textures/Knight.png");
    wizard_txt.loadFromFile("/textures/Wizard.png");
    archer_txt.loadFromFile("/textures/Archer.png");

    num = rand() % 100;

    if (num <= 33)
    {
        cpu_choice = 'w';
        cpu_sprite.setTexture(wizard_txt);
        cpu_sprite.setPosition(sf::Vector2f(500.f, 100.f));
    }
    else if (num >= 34 && num <= 66)
    {
        cpu_choice = 'k';
        cpu_sprite.setTexture(knight_txt);
        cpu_sprite.setPosition(sf::Vector2f(500.f, 100.f));
    }
    else if (num >= 67 && num <= 99 )
    {
        cpu_choice = 'a';
        cpu_sprite.setTexture(archer_txt);
        cpu_sprite.setPosition(sf::Vector2f(500.f, 100.f));
    }

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::KeyReleased(sf::Keyboard::W))
            {
                player_choice = 'w';
                player_sprite.setTexture(wizard_txt);
                player_sprite.setPosition(sf::Vector2f(100.f, 100.f));
                window.draw(cpu_sprite);
                window.draw(player_sprite);
                window.display();
            }
            else if (event.type == sf::Event::KeyReleased(sf::Keyboard::K))
            {
                player_choice = 'k';
                player_sprite.setTexture(knight_txt);
                player_sprite.setPosition(sf::Vector2f(100.f, 100.f));
                window.draw(cpu_sprite);
                window.draw(player_sprite);
                window.display();
            }
            else if (event.type == sf::Event::KeyReleased(sf::Keyboard::A))
            {
                player_choice = 'a';
                player_sprite.setTexture(archer_txt);
                player_sprite.setPosition(sf::Vector2f(100.f, 100.f));
                window.draw(cpu_sprite);
                window.draw(player_sprite);
                window.display();
            }
            if (event.type == sf::Event::KeyReleased(sf::Keyboard::Y))
                game_loop(sf::RenderWindow &window);
            else if (event.type == sf::Event::KeyReleased(sf::Keyboard::N))
                {
                    window.clear();
                    window.close();
                }
        }

        text.setString("Make Your Choice! Press W for Wizard, K for Knight, or A for archer!");
        window.draw(text);
        window.display();

        if (player_choice)
        {
            if (cpu_choice == 'w')
            {
                if (player_choice == 'w')
                    {
                        text.setString("Draw! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
                else if (player_choice == 'k')
                   {
                        text.setString("You Lose! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
                else if (player_choice =='a')
                    {
                        text.setString("You Win! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
            }
            if (cpu_choice == 'k')
            {
                if (player_choice == 'k')
                    {
                        text.setString("Draw! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
                else if (player_choice == 'a')
                    {
                        text.setString("You Lose! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
                else if (player_choice =='w')
                    {
                        text.setString("You Win! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
            }
            if (cpu_choice == 'a')
            {
                if (player_choice == 'a')
                    {
                        text.setString("Draw! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
                else if (player_choice == 'w')
                    {
                        text.setString("You Lose! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
                else if (player_choice =='k')
                    {
                        text.setString("You Win! Play Again? (Y/N)");
                        text.setPosition(sf::Vector2(0.f, 700.f));
                        window.draw(text);
                        window.display();
                    }
            }
        }
    }
}