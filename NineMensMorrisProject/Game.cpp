#include "Game.h"

void Game::InitVariables()
{
	this->currentGameState = GameState::PLACING;
	this->board = new Board();
	this->currentPlayerIndex = rand() % 2;
	this->piecesPerPlayer = 9;
	this->window = nullptr;
}

void Game::InitWindow()
{
	this->videoMode.height = 440;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Nine Men's Morris", sf::Style::Close);
}

Game::Game()
{
	this->InitVariables();
	this->InitWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::GetWindowIsOpen() const
{
	return this->window->isOpen();
}

void Game::UpdatePollEvents()
{
	// Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (this->ev.key.code == sf::Mouse::Left)
			{
				sf::Vector2i currentMousePosition = sf::Mouse::getPosition(*this->window);

				std::cout << currentMousePosition.x << ' ' << currentMousePosition.y << std::endl;
			}

			break;
		}
	}
}

void Game::Update()
{
	this->UpdatePollEvents();
}

void Game::Render()
{
	this->window->clear(sf::Color::White);

	board->Render(this->window);

	this->window->display();
}

void Game::ChangeGameState(GameState newGameState)
{
	this->currentGameState = newGameState;
}
