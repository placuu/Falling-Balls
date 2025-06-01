#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>


unsigned int width = 1300;
unsigned int height = 900;

std::mt19937 rng(std::random_device{}());
std::uniform_int_distribution<int> dist(0, 255);

sf::Color getRandomColor() {
	return sf::Color(dist(rng), dist(rng), dist(rng));
}

sf::CircleShape CreateCircle(const sf::Vector2f& position){
	sf::CircleShape circle(30.0f);
	circle.setFillColor(getRandomColor());
	circle.setOrigin(sf::Vector2f(circle.getRadius(),circle.getRadius()));
	circle.setPosition(position);
	return circle;
}

void coutUpdate(sf::Text& text, int count) {
	text.setString("Count: " + std::to_string(count));
}

int main() {


	sf::RenderWindow window(sf::VideoMode({ width, height }), "Falling balls",sf::Style::Close, sf::State::Windowed);
	window.setFramerateLimit(60);

	std::vector<sf::CircleShape> circles;

	sf::Font font;
	if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
		std::cout << "BŁĄD: Nie można załadować nawet systemowej czcionki Arial!" << std::endl;
		std::cout << "Problem może być z SFML lub systemem" << std::endl;
		return -1;
	}

	std::cout << "SUCCESS: Załadowano systemową czcionkę Arial!" << std::endl;

	sf::Text text(font,"", 30);
	text.setFillColor(sf::Color::White);
	text.setPosition({ 1150.0f,0.0f});
	

	while (window.isOpen()) {	
		while (const std::optional event = window.pollEvent()) {

			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			else if (const auto* keyPressed = event -> getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window.close();
				}
			}
			else if(const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()){
				if (mousePressed->button == sf::Mouse::Button::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					circles.push_back(CreateCircle(mousePosF));
					coutUpdate(text, circles.size());
				}
			}
		}

		
		window.clear(sf::Color::Black);
		float gravity = 3.f;
		for (auto& circle : circles) {
			circle.move(sf::Vector2f(0.f, gravity));
		}
		window.draw(text);

		
		for (const auto& circle : circles) {
			window.draw(circle);
		}
		
		window.display();

		



	}

	return 0;
}