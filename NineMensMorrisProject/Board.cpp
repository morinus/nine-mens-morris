#include "Board.h"

Board::Board()
{
	this->InitBackground();
	this->InitPoints();
	this->InitLines();
	this->InitPieces();
	this->InitTexts();
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

	// Forming point connects to other points
	this->points[0]->ConnectPoint(this->points[1]);
	this->points[0]->ConnectPoint(this->points[9]);

	this->points[1]->ConnectPoint(this->points[0]);
	this->points[1]->ConnectPoint(this->points[2]);
	this->points[1]->ConnectPoint(this->points[4]);

	this->points[2]->ConnectPoint(this->points[1]);
	this->points[2]->ConnectPoint(this->points[14]);

	this->points[3]->ConnectPoint(this->points[4]);
	this->points[3]->ConnectPoint(this->points[10]);

	this->points[4]->ConnectPoint(this->points[1]);
	this->points[4]->ConnectPoint(this->points[3]);
	this->points[4]->ConnectPoint(this->points[7]);
	this->points[4]->ConnectPoint(this->points[5]);

	this->points[5]->ConnectPoint(this->points[4]);
	this->points[5]->ConnectPoint(this->points[13]);

	this->points[6]->ConnectPoint(this->points[7]);
	this->points[6]->ConnectPoint(this->points[11]);

	this->points[7]->ConnectPoint(this->points[6]);
	this->points[7]->ConnectPoint(this->points[8]);
	this->points[7]->ConnectPoint(this->points[4]);

	this->points[8]->ConnectPoint(this->points[7]);
	this->points[8]->ConnectPoint(this->points[12]);

	this->points[9]->ConnectPoint(this->points[0]);
	this->points[9]->ConnectPoint(this->points[21]);
	this->points[9]->ConnectPoint(this->points[10]);

	this->points[10]->ConnectPoint(this->points[9]);
	this->points[10]->ConnectPoint(this->points[3]);
	this->points[10]->ConnectPoint(this->points[11]);
	this->points[10]->ConnectPoint(this->points[18]);

	this->points[11]->ConnectPoint(this->points[6]);
	this->points[11]->ConnectPoint(this->points[10]);
	this->points[11]->ConnectPoint(this->points[15]);

	this->points[12]->ConnectPoint(this->points[8]);
	this->points[12]->ConnectPoint(this->points[13]);
	this->points[12]->ConnectPoint(this->points[17]);

	this->points[13]->ConnectPoint(this->points[8]);
	this->points[13]->ConnectPoint(this->points[13]);
	this->points[13]->ConnectPoint(this->points[17]);

	this->points[14]->ConnectPoint(this->points[2]);
	this->points[14]->ConnectPoint(this->points[13]);
	this->points[14]->ConnectPoint(this->points[23]);

	this->points[15]->ConnectPoint(this->points[11]);
	this->points[15]->ConnectPoint(this->points[16]);

	this->points[16]->ConnectPoint(this->points[15]);
	this->points[16]->ConnectPoint(this->points[17]);
	this->points[16]->ConnectPoint(this->points[19]);

	this->points[17]->ConnectPoint(this->points[12]);
	this->points[17]->ConnectPoint(this->points[16]);

	this->points[18]->ConnectPoint(this->points[10]);
	this->points[18]->ConnectPoint(this->points[19]);

	this->points[19]->ConnectPoint(this->points[16]);
	this->points[19]->ConnectPoint(this->points[18]);
	this->points[19]->ConnectPoint(this->points[20]);
	this->points[19]->ConnectPoint(this->points[22]);

	this->points[20]->ConnectPoint(this->points[13]);
	this->points[20]->ConnectPoint(this->points[19]);

	this->points[21]->ConnectPoint(this->points[9]);
	this->points[21]->ConnectPoint(this->points[22]);

	this->points[22]->ConnectPoint(this->points[21]);
	this->points[22]->ConnectPoint(this->points[19]);
	this->points[22]->ConnectPoint(this->points[23]);

	this->points[23]->ConnectPoint(this->points[14]);
	this->points[23]->ConnectPoint(this->points[22]);
}

void Board::InitLines()
{
	Line* line0 = new Line();
	Line* line1 = new Line();
	Line* line2 = new Line();
	Line* line3 = new Line();
	Line* line4 = new Line();
	Line* line5 = new Line();
	Line* line6 = new Line();
	Line* line7 = new Line();
	Line* line8 = new Line();
	Line* line9 = new Line();
	Line* line10 = new Line();
	Line* line11 = new Line();
	Line* line12 = new Line();
	Line* line13 = new Line();
	Line* line14 = new Line();
	Line* line15 = new Line();

	// Add horizontal lines
	line0->ConnectPoint(points[0]);
	line0->ConnectPoint(points[1]);
	line0->ConnectPoint(points[2]);

	line1->ConnectPoint(points[3]);
	line1->ConnectPoint(points[4]);
	line1->ConnectPoint(points[5]);

	line2->ConnectPoint(points[6]);
	line2->ConnectPoint(points[7]);
	line2->ConnectPoint(points[8]);

	line3->ConnectPoint(points[9]);
	line3->ConnectPoint(points[10]);
	line3->ConnectPoint(points[11]);

	line4->ConnectPoint(points[12]);
	line4->ConnectPoint(points[13]);
	line4->ConnectPoint(points[14]);

	line5->ConnectPoint(points[15]);
	line5->ConnectPoint(points[16]);
	line5->ConnectPoint(points[17]);

	line6->ConnectPoint(points[18]);
	line6->ConnectPoint(points[19]);
	line6->ConnectPoint(points[20]);

	line7->ConnectPoint(points[21]);
	line7->ConnectPoint(points[22]);
	line7->ConnectPoint(points[23]);

	// Vertical lines
	line8->ConnectPoint(points[0]);
	line8->ConnectPoint(points[9]);
	line8->ConnectPoint(points[21]);

	line9->ConnectPoint(points[3]);
	line9->ConnectPoint(points[10]);
	line9->ConnectPoint(points[18]);

	line10->ConnectPoint(points[6]);
	line10->ConnectPoint(points[11]);
	line10->ConnectPoint(points[15]);

	line11->ConnectPoint(points[1]);
	line11->ConnectPoint(points[4]);
	line11->ConnectPoint(points[7]);

	line12->ConnectPoint(points[16]);
	line12->ConnectPoint(points[19]);
	line12->ConnectPoint(points[22]);

	line13->ConnectPoint(points[8]);
	line13->ConnectPoint(points[12]);
	line13->ConnectPoint(points[17]);

	line14->ConnectPoint(points[5]);
	line14->ConnectPoint(points[13]);
	line14->ConnectPoint(points[20]);

	line15->ConnectPoint(points[2]);
	line15->ConnectPoint(points[14]);
	line15->ConnectPoint(points[23]);

	// Add lines to vector
	this->lines.push_back(line0);
	this->lines.push_back(line1);
	this->lines.push_back(line2);
	this->lines.push_back(line3);
	this->lines.push_back(line4);
	this->lines.push_back(line5);
	this->lines.push_back(line6);
	this->lines.push_back(line7);
	this->lines.push_back(line8);
	this->lines.push_back(line9);
	this->lines.push_back(line10);
	this->lines.push_back(line11);
	this->lines.push_back(line12);
	this->lines.push_back(line13);
	this->lines.push_back(line14);
	this->lines.push_back(line15);
}

void Board::InitPieces()
{
	for (int i = 0; i < PIECES_PER_PLAYER; i++)
	{
		this->pieces.push_back(new Piece(OwnershipType::PLAYERONE, sf::Vector2f(500.0f, 65.0f + (15.0f * i))));
		this->pieces.push_back(new Piece(OwnershipType::PLAYERTWO, sf::Vector2f(650.0f, 65.0f + (15.0f * i))));
	}
}

void Board::InitTexts()
{
	this->playerOneTitleText = new Text(sf::Vector2f(450.0f, 10.0f), "-Player 1-");
	this->playerTwoTitleText = new Text(sf::Vector2f(600.0f, 10.0f), "-Player 2-");

	this->currentPlayerText = new Text(sf::Vector2f(480.0f, 250.0f), "CURRENT_PLAYER");
	this->currentActionText = new Text(sf::Vector2f(480.0f, 300.0f), "CURRENT_ACTION");
	this->currentActionText->SetColor(sf::Color::Blue);
	this->currentActionText->SetCharacterSize(16);
}

void Board::Render(sf::RenderWindow* window, int deltaTime)
{
	window->draw(background);
	playerOneTitleText->Render(window);
	playerTwoTitleText->Render(window);
	currentPlayerText->Render(window);
	currentActionText->Render(window);

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

void Board::DeselectEverything()
{
	this->currentlySelectedPiece = nullptr;
	this->currentlySelectedPoint = nullptr;
	this->currentTargetPoint = nullptr;
}

void Board::SetCurrentlySelectedPiece(Piece * piece)
{
	this->currentlySelectedPiece = piece;
}

void Board::SetCurrentlySelectedPoint(Point * point)
{
	this->currentlySelectedPoint = point;
}

void Board::SetCurrentPlayerText(std::string string)
{
	this->currentPlayerText->SetText(string);
}

void Board::SetCurrentActionText(std::string string)
{
	this->currentActionText->SetText(string);
}

void Board::DisableAllLines()
{
	for (auto line : lines)
	{
		line->Disable();
	}
}

bool Board::CheckIfCurrentPlayerWon(int currentPlayer)
{
	std::vector<Piece* > removedPieces;

	for (auto piece : this->pieces)
	{
		if (piece->GetOwnershipType() != currentPlayer)
		{
			if (piece->GetPieceState() == PieceState::REMOVED)
			{
				removedPieces.push_back(piece);
			}
		}
	}

	return removedPieces.size() >= PIECES_PER_PLAYER - 2;
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

bool Board::CheckIfLineIsCompletedForCurrentPlayer(int currentPlayerIndex)
{
	for (auto line : lines)
	{
		if (line->IsMillCompleted())
		{
			if (line->connectedPoints[0]->GetPiece()->GetOwnershipType() == currentPlayerIndex)
			{
				return true;
			}
		}
	}

	return false;
}

Piece * Board::GetCurrentlySelectedPiece()
{
	return this->currentlySelectedPiece;
}

Point * Board::GetCurrentlySelectedPoint()
{
	return this->currentlySelectedPoint;
}

Point * Board::GetCurrentTargetPoint()
{
	return this->currentTargetPoint;
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
