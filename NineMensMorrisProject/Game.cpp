#include "Game.h"

Game::Game()
{
	this->InitVariables();
	this->InitWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::InitVariables()
{
	this->currentGameState = GameState::PLACING;
	this->board = new Board();
	this->currentPlayerIndex = rand() % 2;
	this->window = nullptr;
}

void Game::InitWindow()
{
	this->videoMode.height = 440;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Nine Men's Morris", sf::Style::Close);
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
		}
	}
}

void Game::Update()
{
	this->UpdatePollEvents();
	this->board->Update(this->window);
	this->ProcessCurrentGameState();
}

void Game::Render(int deltaTime)
{
	this->window->clear(sf::Color::White);

	board->Render(this->window, deltaTime);

	this->window->display();
}

void Game::ChangeGameState(GameState newGameState)
{
	this->currentGameState = newGameState;
}

void Game::ProcessCurrentGameState()
{
	switch (this->currentGameState)
	{
	case GameState::PLACING:
		Point* currentlySelectedPoint = this->board->GetCurrentlySelectedPoint();
		if (currentlySelectedPoint != nullptr)
		{
			bool isOccupied = currentlySelectedPoint->IsOccupied();

			if (!isOccupied)
			{
				auto piece = this->board->GetNextAvailablePiece(this->currentPlayerIndex);
				piece->SetPosition(currentlySelectedPoint->GetPosition());

				currentlySelectedPoint->PlacePiece(piece);
				currentlySelectedPoint = nullptr;

				this->ChangeTurn();

				if (!this->board->HasUnplacedPieces())
				{
					this->ChangeGameState(GameState::MOVING);
					break;
				}
			}
		}

		break;
	}
}

void Game::ChangeTurn()
{
	this->currentPlayerIndex = this->currentPlayerIndex == 0 ? 1 : 0;
}
