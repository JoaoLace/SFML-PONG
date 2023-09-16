#include "Ball.h"

void Ball::initShape()
{
	ball.setRadius(6.f);
	ball.setPosition(sf::Vector2f(394.f, 294.f));
	ball.setFillColor(sf::Color::White);
}

void Ball::initVaribles()
{
	veloX = 1.f;
	veloY = 1.f;
}

Ball::Ball()
{
	initShape();
}

const sf::FloatRect Ball::getBounds() const
{
	return ball.getGlobalBounds();
}

void Ball::setMove(float speed_x, float speed_y)
{
	ball.move(speed_x, speed_y);
}

void Ball::update()
{
	
}

void Ball::render(sf::RenderTarget& target)
{
	target.draw(ball);
}

void Ball::restart()
{
	ball.setPosition(sf::Vector2f(394.f, 294.f));
}
