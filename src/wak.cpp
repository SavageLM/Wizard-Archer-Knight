#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <iostream>

void game_loop(sf::RenderWindow& window);

int main()
{
    auto window = sf::RenderWindow{ { 1100u, 800u }, "W.A.K" };
    window.setFramerateLimit(144);
    sf::Texture title_txt;
    sf::Sprite title;
    sf::Font font;
    sf::Text menu;

    title_txt.loadFromFile("/mnt/c/Users/nagol/lab-hacksprint_1/src/textures/Title.png");
    title.setTexture(title_txt);
    title.setPosition(sf::Vector2f(200.f, 0.f));
    font.loadFromFile("/mnt/c/Users/nagol/lab-hacksprint_1/src/Font/ARIAL.TTF");
    menu.setFont(font);
    menu.setString("Press 'P' to play or 'Q' to quit");
    menu.setCharacterSize(30);
    menu.setFillColor(sf::Color::White);
    menu.setPosition(sf::Vector2(350.f, 700.f));


    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased)
            {  
                if (event.key.code == sf::Keyboard::P)
                    game_loop(window);
                if (event.key.code == sf::Keyboard::Q)
                {
                    window.clear();
                    window.close();
                }
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
    sf::Text start, result;

    font.loadFromFile("/mnt/c/Users/nagol/lab-hacksprint_1/src/Font/ARIAL.TTF");
    start.setFont(font);
    start.setCharacterSize(30);
    start.setFillColor(sf::Color::White);

    result.setFont(font);
    result.setCharacterSize(30);
    result.setFillColor(sf::Color::White);

    knight_txt.loadFromFile("/mnt/c/Users/nagol/lab-hacksprint_1/src/textures/Knight.png");
    wizard_txt.loadFromFile("/mnt/c/Users/nagol/lab-hacksprint_1/src/textures/Wizard.png");
    archer_txt.loadFromFile("/mnt/c/Users/nagol/lab-hacksprint_1/src/textures/Archer.png");

    window.clear();
    srand((unsigned) time(NULL));
    num = rand() % 100;

    if (num <= 33)
    {
        cpu_choice = 'w';
        cpu_sprite.setTexture(wizard_txt);
        cpu_sprite.setPosition(sf::Vector2f(600.f, 40.f));
    }
    else if (num >= 34 && num <= 66)
    {
        cpu_choice = 'k';
        cpu_sprite.setTexture(knight_txt);
        cpu_sprite.setPosition(sf::Vector2f(600.f, 40.f));
    }
    else if (num >= 67 && num <= 99 )
    {
        cpu_choice = 'a';
        cpu_sprite.setTexture(archer_txt);
        cpu_sprite.setPosition(sf::Vector2f(600.f, 40.f));
    }

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::W)
                {
                    player_choice = 'w';
                    player_sprite.setTexture(wizard_txt);
                    player_sprite.setPosition(sf::Vector2f(50.f, 40.f));
                    window.draw(cpu_sprite);
                    window.draw(player_sprite);
                    window.display();
                }
                if (event.key.code == sf::Keyboard::K)
                {
                    player_choice = 'k';
                    player_sprite.setTexture(knight_txt);
                    player_sprite.setPosition(sf::Vector2f(50.f, 40.f));
                    window.draw(cpu_sprite);
                    window.draw(player_sprite);
                    window.display();
                }
                if (event.key.code == sf::Keyboard::A)
                {
                    player_choice = 'a';
                    player_sprite.setTexture(archer_txt);
                    player_sprite.setPosition(sf::Vector2f(50.f, 40.f));
                    window.draw(cpu_sprite);
                    window.draw(player_sprite);
                    window.display(); 
                }
                if (event.key.code == sf::Keyboard::Y)
                    game_loop(window);
                if (event.key.code == sf::Keyboard::N)
                {
                    window.clear();
                    window.close();
                }
            }
        }

        start.setString("Make Your Choice! Press W for Wizard, K for Knight, or A for archer!");
        start.setPosition(sf::Vector2f(50.f, 0.f));
        window.draw(start);
        window.display();

        if (player_choice)
        {
            if (cpu_choice == 'w')
            {
                if (player_choice == 'w')
                    {
                        result.setString("Draw! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
                else if (player_choice == 'k')
                   {
                        result.setString("You Lose! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
                else if (player_choice =='a')
                    {
                        result.setString("You Win! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
            }
            if (cpu_choice == 'k')
            {
                if (player_choice == 'k')
                    {
                        result.setString("Draw! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
                else if (player_choice == 'a')
                    {
                        result.setString("You Lose! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
                else if (player_choice =='w')
                    {
                        result.setString("You Win! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
            }
            if (cpu_choice == 'a')
            {
                if (player_choice == 'a')
                    {
                        result.setString("Draw! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
                else if (player_choice == 'w')
                    {
                        result.setString("You Lose! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
                else if (player_choice =='k')
                    {
                        result.setString("You Win! Play Again? (Y/N)");
                        result.setPosition(sf::Vector2f(50.f, 700.f));
                        window.draw(result);
                        window.display();
                    }
            }
        }
    }
}
