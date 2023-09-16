#include "Players.h"

void Players::initShape()
{
	player1.setFillColor(sf::Color::White);
	player1.setSize(sf::Vector2f(30.f,100.f));
	player1.setPosition(sf::Vector2f(30.f, 200.f));

	player2.setFillColor(sf::Color::White);
	player2.setSize(sf::Vector2f(30.f, 100.f));
	player2.setPosition(sf::Vector2f(740.f, 200.f));
	
}

void Players::initVariables()
{
	speed1 = 1.f;
	speed2 = 1.f;
}

Players::Players()
{
	initShape();
	initVariables();

}

Players::~Players()
{
}

const sf::FloatRect Players::getBounds1() const
{
	return player1.getGlobalBounds();
}

const sf::FloatRect Players::getBounds2() const
{
	return player2.getGlobalBounds();
}

void Players::playerMove()
{
	speed1 = 1.f;
	speed2 = 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		speed1 += 0.1f;
		speed1 > 2.f ? speed1 = 2.0f : speed1 = speed1;
		player1.move(0.f, -3.f * speed1);
		direcao = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		speed1 += 0.1f;
		speed1 > 2.f ? speed1 = 2.0f : speed1 = speed1;
		player1.move(0.f, 3.f * speed1);
		direcao = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed2 += 0.1f;
		speed2 > 2.f ? speed2 = 2.0f : speed2 = speed2;
		player2.move(0.f, -3.f * speed2);
		direcao = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed2 += 0.1f;
		speed2 > 2.f ? speed2 = 2.0f : speed2 = speed2;
		player2.move(0.f, 3.f * speed2);
		direcao = 1;
	}

}

void Players::update()
{
	playerMove();
}

void Players::render(sf::RenderTarget& target)
{
	target.draw(player1);
	target.draw(player2);
}

void Players::restart()
{
	player1.setPosition(sf::Vector2f(30.f, 200.f));
	player2.setPosition(sf::Vector2f(740.f, 200.f));
}
