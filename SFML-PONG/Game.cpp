#include "Game.h"

void Game::initText()
{
// "C:\Users\lacer\OneDrive\Área de Trabalho\repos\SFML-PONG\SFML-PONG\font.ttf"
	font.loadFromFile("font.ttf");
	
	pointsText1.setFont(font);
	pointsText1.setCharacterSize(40);
	pointsText1.setPosition(sf::Vector2f(30.f, 30.f));
	
	pointsText2.setFont(font);
	pointsText2.setPosition(sf::Vector2f(740.f, 30.f));
	pointsText2.setCharacterSize(40);

	pointsText1.setFillColor(sf::Color::White);
	pointsText2.setFillColor(sf::Color::White);

}

void Game::updateText()
{
	std::stringstream p1, p2;

	p1 <<  points1;
	p2 <<  points2;

	pointsText1.setString(p1.str());
	pointsText2.setString(p2.str());

}

void Game::renderText()
{
	window->draw(pointsText1);
	window->draw(pointsText2);
}

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Pong", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
}

void Game::initPlayer()
{
	player = new Players();
}

void Game::initBall()
{
	ball = new Ball();
}

void Game::initVariables()
{
	moveX = 4.f;
	moveY = 0.f;
	moverX = moveX;
	points1 = 0;
	points2 = 0;
}

Game::Game()
{
	initWindow();
	initVariables();
	initText();
	initPlayer();
	initBall();
	player1win();
	player2win();
	
}

Game::~Game()
{
	delete window;
}

void Game::pollEvents()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		switch (e.Event::type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (e.Event::key.code == sf::Keyboard::Escape)
			{
				window->close();
				break;
			}
		}
	}
}

void Game::updateBall()
{
	ball->setMove(moverX,moveY);
}

void Game::updateCollision()
{
	if (ball->getBounds().left + ball->getBounds().width >= player->getBounds2().left - 20
		&& ball->getBounds().top + ball->getBounds().height >= player->getBounds2().top
		&& ball->getBounds().top <= player->getBounds2().top + player->getBounds2().height)
	{
		moveX++;
		direcao = -1;
		if (moveX > 12)
			moveX = 12;
		moverX = moveX * direcao;  
		moveY = player->speed2 * player->direcao ; 
	}

	if (ball->getBounds().left <= player->getBounds1().left + 30
		&& ball->getBounds().top + ball->getBounds().height >= player->getBounds1().top
		&& ball->getBounds().top <= player->getBounds1().top + player->getBounds1().height)
	{
		moveX++;
		if (moveX > 12)
			moveX = 12;
		direcao = 1;
		moverX = moveX * direcao;
		moveY = player->speed1 * player->direcao;
	}

	if (ball->getBounds().top <= 0 || ball->getBounds().top >= 600)
	{
		moveY *= -1;
	}

	if (ball->getBounds().left <= 0)
	{
		ball->restart();
		player->restart();
		moveX = 4;
		moveY = 0;
		moverX = moveX;
		points2++;
	}
	if (ball->getBounds().left >= 800)
	{
		ball->restart();
		player->restart();
		moveX = 4;
		moveY = 0;
		moverX = moveX;
		points1++;
	}

}

void Game::player1win()
{
	std::stringstream p1;

	p1 << "PLAYER 1 WIN !!!";
	over1.setFont(font);
	over1.setPosition(150, 80);
	over1.setString(p1.str());
	over1.setCharacterSize(40);
	over1.setFillColor(sf::Color::White);
	
}
void Game::player2win()
{
	std::stringstream p1;

	p1 << "PLAYER 2 WIN !!!";

	over2.setFont(font);
	over2.setPosition(150, 80);
	over2.setString(p1.str());
	over2.setCharacterSize(40);
	over2.setFillColor(sf::Color::White);

}
void Game::run()
{
	while (window->isOpen())
	{
		pollEvents();

		if (points1 < 2 && points2 < 2)
		{
			update();
		}
		
		render();
	}
}

void Game::update()
{
	player->update();

	updateCollision();

	updateBall();

	updateText();
}

void Game::render()
{
	window->clear();

	player->render(*window);

	ball->render(*window);

	renderText();

	if (points1 == 2)
	{
		renderWin1();
	}
	if (points2 == 2)
	{
		renderWin2();
	}
	window->display();
}

void Game::renderWin1()
{
	window->draw(over1);
}
void Game::renderWin2()
{
	window->draw(over2);
}