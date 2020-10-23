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

void Game::ChangeMovingStateSelection(MovingStateSelection newMovingStateSelection)
{
	this->currentMovingStateSelection = newMovingStateSelection;
}

void Game::ProcessCurrentGameState()
{
	Point* currentlySelectedPoint = nullptr;
	Point* currentTargetPoint = nullptr;

	switch (this->currentGameState)
	{
	case GameState::PLACING:
		currentlySelectedPoint = this->board->GetCurrentlySelectedPoint();
		if (currentlySelectedPoint != nullptr)
		{
			bool isOccupied = currentlySelectedPoint->IsOccupied();

			if (!isOccupied)
			{
				auto piece = this->board->GetNextAvailablePiece(this->currentPlayerIndex);
				piece->SetPosition(currentlySelectedPoint->GetPosition());
				piece->ConnectPoint(currentlySelectedPoint);

				currentlySelectedPoint->PlacePiece(piece);
				currentlySelectedPoint = nullptr;

				this->board->DeselectEverything();

				if (this->board->CheckIfLineIsCompletedForCurrentPlayer(this->currentPlayerIndex))
				{
					this->ChangeGameState(GameState::REMOVING);
					break;
				}

				this->ChangeTurn();

				if (!this->board->HasUnplacedPieces())
				{
					this->ChangeGameState(GameState::MOVING);
					break;
				}
			}
		}

		break;

	case GameState::REMOVING:
		currentlySelectedPoint = this->board->GetCurrentlySelectedPoint();
		if (currentlySelectedPoint != nullptr)
		{
			auto pointPiece = currentlySelectedPoint->GetPiece();
			if (pointPiece == nullptr)
			{
				break;
			}

			if (pointPiece->GetOwnershipType() == this->currentPlayerIndex)
			{
				break;
			}

			pointPiece->Remove();
			currentlySelectedPoint->Deselect();
			this->board->DeselectEverything();

			this->ChangeTurn();

			if (!this->board->HasUnplacedPieces())
			{
				this->ChangeGameState(GameState::MOVING);
				break;
			}
			else
			{
				this->ChangeGameState(GameState::PLACING);
				break;
			}
		}

		break;

	case GameState::MOVING:
		currentlySelectedPoint = this->board->GetCurrentlySelectedPoint();
		if (currentlySelectedPoint != nullptr)
		{
			if (currentMovingStateSelection == MovingStateSelection::SELECTING_PIECE)
			{
				// Check if piece belowing to current player
				if (currentlySelectedPoint->GetPiece() != nullptr)
				{
					if (currentlySelectedPoint->GetPiece()->GetOwnershipType() == currentPlayerIndex)
					{
						// Check if piece can be moved
						if (currentlySelectedPoint->HasFreeConnectedPoints())
						{
							// Set currently selected piece
							this->board->SetCurrentlySelectedPiece(currentlySelectedPoint->GetPiece());
							this->ChangeMovingStateSelection(MovingStateSelection::SELECTING_POINT);
							this->board->SetCurrentlySelectedPoint(nullptr);
							currentlySelectedPoint = nullptr;

							break;
						}

						this->board->DeselectEverything();
					}
				}
			}
			else {
				// If currentlySelectedPoint as target point is connected to currently selected piece
				if (this->board->GetCurrentlySelectedPiece() != nullptr)
				{
					if (this->board->GetCurrentlySelectedPiece()->GetConnectedPoint()->IsConnectedTo(currentlySelectedPoint))
					{
						// If currentlySelectedPoint is free
						if (currentlySelectedPoint->GetPiece() == nullptr)
						{
							this->board->GetCurrentlySelectedPiece()->Move(currentlySelectedPoint);
							this->ChangeMovingStateSelection(MovingStateSelection::SELECTING_PIECE);

							if (this->board->CheckIfLineIsCompletedForCurrentPlayer(this->currentPlayerIndex))
							{
								this->ChangeGameState(GameState::REMOVING);
								break;
							}

							this->ChangeTurn();

							break;
						}
					}
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
