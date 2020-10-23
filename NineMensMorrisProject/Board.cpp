#include "Board.h"

Board::Board()
{
	this->InitBackground();
	this->InitPoints();
	this->InitLines();
	this->InitPieces();
}

Board::~Board()
{

}

void Board::InitBackground()
{
	if (!this->backgroundTexture.loadFromFile("Textures/Nine_Men's_Morris_board.png"))
	{
		std::cout << ERROR_LOADING_TEXTURE << std::endl;
	}

	background = sf::Sprite(this->backgroundTexture);
}

void Board::InitPoints()
{
	this->points.push_back(new Point(0, sf::Vector2f(30.0f, 30.0f)));
	this->points.push_back(new Point(1, sf::Vector2f(220.0f, 30.0f)));
	this->points.push_back(new Point(2, sf::Vector2f(410.0f, 30.0f)));
	this->points.push_back(new Point(3, sf::Vector2f(93.0f, 93.0f)));
	this->points.push_back(new Point(4, sf::Vector2f(219.0f, 93.0f)));
	this->points.push_back(new Point(5, sf::Vector2f(345.0f, 93.0f)));
	this->points.push_back(new Point(6, sf::Vector2f(156.0f, 156.0f)));
	this->points.push_back(new Point(7, sf::Vector2f(219.0f, 156.0f)));
	this->points.push_back(new Point(8, sf::Vector2f(282.0f, 156.0f)));
	this->points.push_back(new Point(9, sf::Vector2f(30.0f, 220.0f)));
	this->points.push_back(new Point(10, sf::Vector2f(93.0f, 220.0f)));
	this->points.push_back(new Point(11, sf::Vector2f(156.0f, 220.0f)));
	this->points.push_back(new Point(12, sf::Vector2f(282.0f, 220.0f)));
	this->points.push_back(new Point(13, sf::Vector2f(345.0f, 220.0f)));
	this->points.push_back(new Point(14, sf::Vector2f(410.0f, 220.0f)));
	this->points.push_back(new Point(15, sf::Vector2f(156.0f, 282.0f)));
	this->points.push_back(new Point(16, sf::Vector2f(219.0f, 282.0f)));
	this->points.push_back(new Point(17, sf::Vector2f(282.0f, 282.0f)));
	this->points.push_back(new Point(18, sf::Vector2f(93.0f, 345.0f)));
	this->points.push_back(new Point(19, sf::Vector2f(219.0f, 345.0f)));
	this->points.push_back(new Point(20, sf::Vector2f(345.0f, 345.0f)));
	this->points.push_back(new Point(21, sf::Vector2f(30.0f, 407.0f)));
	this->points.push_back(new Point(22, sf::Vector2f(219.0f, 407.0f)));
	this->points.push_back(new Point(23, sf::Vector2f(410.0f, 407.0f)));
}

void Board::InitLines()
{

}

void Board::InitPieces()
{
	for (int i = 0; i < PIECES_PER_PLAYER; i++)
	{
		this->pieces.push_back(new Piece(OwnershipType::PLAYERONE, sf::Vector2f(500.0f, 35.0f + (15.0f * i))));
		this->pieces.push_back(new Piece(OwnershipType::PLAYERTWO, sf::Vector2f(650.0f, 35.0f + (15.0f * i))));
	}
}

void Board::Render(sf::RenderWindow* window, int deltaTime)
{
	window->draw(background);

	for (auto point : this->points)
	{
		point->Render(window);
	}

	for (auto piece : this->pieces)
	{
		piece->Render(window, deltaTime);
	}
}

void Board::Update(sf::RenderWindow* window)
{
	for (auto point : points)
	{
		point->Update(window);

		if (point->IsSelected())
		{
			this->currentlySelectedPoint = point;
			point->Deselect();
		}
	}
}

Piece* Board::GetNextAvailablePiece(int currentPlayerIndex)
{
	for (auto piece : pieces)
	{
		if (piece->GetOwnershipType() == currentPlayerIndex
			&& piece->GetPieceState() == PieceState::UNPLACED)
		{
			return piece;
		}
	}

	return nullptr;
}

Piece * Board::GetCurrentlySelectedPiece()
{
	return this->currentlySelectedPiece;
}

Point * Board::GetCurrentlySelectedPoint()
{
	return this->currentlySelectedPoint;
}

bool Board::HasUnplacedPieces()
{
	for (auto piece : pieces)
	{
		if (piece->GetPieceState() == PieceState::UNPLACED)
		{
			return true;
		}
	}

	return false;
}
