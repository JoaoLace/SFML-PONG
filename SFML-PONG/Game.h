#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include "Players.h"
#include "Ball.h"
#pragma once
class Game {
private:
	sf::RenderWindow* window;
	
	float moveX, moveY,moverX;

	sf::Text over1;
	sf::Text over2;
	sf::Font font;
	sf::Text pointsText1;
	sf::Text pointsText2;

	void initText();
	void updateText();
	void renderText();

	int points1;
	int points2;

	Ball* ball;
	Players* player;
	void initWindow();
	void initPlayer();
	void initBall();
	void initVariables();
public:
	Game();
	virtual ~Game();

	void pollEvents();
	
	void updateBall();

	void updateCollision();

	int direcao;

	void player1win();
	void player2win();
	void run();
	void update();
	void render();
	void renderWin1();
	void renderWin2();
};