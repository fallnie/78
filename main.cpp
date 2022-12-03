#include <SFML/Graphics.hpp>

using namespace sf;


const float w_w = 800;
const float w_h = 600;
const float r_w = 20;
const float r_h = 80;
const float t = 50;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(w_w, w_h), "SFML Works!");
	window.setFramerateLimit(60.f);

	CircleShape c(10.f);
	c.setOrigin(10, 10);
	c.setFillColor(Color{ 220, 20, 60 });
	c.setPosition(w_w/2, w_h/2);

	RectangleShape rect(Vector2f(r_w, r_h));
	RectangleShape rect1(Vector2f(r_w, r_h));
	rect.setFillColor(Color{ 205, 92, 92 });
	rect1.setFillColor(Color{ 70, 130, 180 });
	rect.setOrigin(Vector2f(r_w/2, r_h/2));
	rect1.setOrigin(Vector2f(r_w/2, r_h/2));
	rect.setPosition(t+ r_w, w_h/2);
	rect1.setPosition((w_w-(t+r_w*2)), w_h / 2);
	
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// Отрисовка окна 
		
		c.move(2, 2);
		
		window.clear(Color{ 102, 205, 170 });
		window.draw(rect);
		window.draw(rect1);
		window.draw(c);
		window.display();
	}

	return 0;
}
