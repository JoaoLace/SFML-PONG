#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Players
{
private:
	
	

	sf::RectangleShape player1;
	sf::RectangleShape player2;

	void initShape();
	void initVariables();
public:
	Players();
	virtual ~Players();

	const sf::FloatRect getBounds1() const;
	const sf::FloatRect getBounds2() const;
	void playerMove();
	void update();
	void render(sf::RenderTarget& target);
	void restart();

	int direcao;
	float speed1,speed2;
};

