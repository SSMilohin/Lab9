// Лабораторная работа №9 Вариант 8
//
// Создайте 3 прямоугольника разных цветов и размеров. 
// Перемещайте их из исходного положения вверх до конца экрана с разной скорость. 
// При достижении конца экрана остановите фигуры.
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 400), L"Первая программа");
    sf::RectangleShape rect1(sf::Vector2f(20.f, 40.f));
    sf::RectangleShape rect2(sf::Vector2f(40.f, 40.f));
    sf::RectangleShape rect3(sf::Vector2f(40.f, 20.f));
    rect1.setFillColor(sf::Color::Cyan);
    rect2.setFillColor(sf::Color::Red);
    rect3.setFillColor(sf::Color::Green);
    float x1 = 100, x2 = 200, x3 = 300,
          y1 = 250, y2 = 270, y3 = 320;
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if (y1 < 0) y1 = 0;
        if (y2 < 0) y2 = 0;
        if (y3 < 0) y3 = 0;
        rect1.setPosition(x1, y1);
        rect2.setPosition(x2, y2);
        rect3.setPosition(x3, y3);
        y1 -= 10.f;
        y2 -= 5.f;
        y3 -= 7.f;
        std::this_thread::sleep_for(40ms);

        window.draw(rect1);
        window.draw(rect2);
        window.draw(rect3);
        window.display();
    }

    return 0;
}