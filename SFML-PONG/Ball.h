#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Ball
{
private:
	sf::CircleShape ball;
	float veloX, veloY;


	sf::Vector2f movements;
	void initShape();
	void initVaribles();
public:
	Ball();

	const sf::FloatRect getBounds() const;
	void setMove(float speed_x, float speed_y);
	void update();
	void render(sf::RenderTarget& target);
	void restart();
};

