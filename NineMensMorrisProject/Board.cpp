#include "Board.h";

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
	this->points[0].Init(0, sf::Vector2f(30.0f, 30.0f));
	this->points[1].Init(1, sf::Vector2f(220.0f, 30.0f));
	this->points[2].Init(2, sf::Vector2f(410.0f, 30.0f));
	this->points[3].Init(3, sf::Vector2f(93.0f, 93.0f));
	this->points[4].Init(4, sf::Vector2f(219.0f, 93.0f));
	this->points[5].Init(5, sf::Vector2f(345.0f, 93.0f));
	this->points[6].Init(6, sf::Vector2f(156.0f, 156.0f));
	this->points[7].Init(7, sf::Vector2f(219.0f, 156.0f));
	this->points[8].Init(8, sf::Vector2f(282.0f, 156.0f));
	this->points[9].Init(9, sf::Vector2f(30.0f, 220.0f));
	this->points[10].Init(10, sf::Vector2f(93.0f, 220.0f));
	this->points[11].Init(11, sf::Vector2f(156.0f, 220.0f));
	this->points[12].Init(12, sf::Vector2f(282.0f, 220.0f));
	this->points[13].Init(13, sf::Vector2f(345.0f, 220.0f));
	this->points[14].Init(14, sf::Vector2f(410.0f, 220.0f));
	this->points[15].Init(15, sf::Vector2f(156.0f, 282.0f));
	this->points[16].Init(16, sf::Vector2f(219.0f, 282.0f));
	this->points[17].Init(17, sf::Vector2f(282.0f, 282.0f));
	this->points[18].Init(18, sf::Vector2f(93.0f, 345.0f));
	this->points[19].Init(19, sf::Vector2f(219.0f, 345.0f));
	this->points[20].Init(20, sf::Vector2f(345.0f, 345.0f));
	this->points[21].Init(21, sf::Vector2f(30.0f, 407.0f));
	this->points[22].Init(22, sf::Vector2f(219.0f, 407.0f));
	this->points[23].Init(23, sf::Vector2f(410.0f, 407.0f));
}

void Board::InitPieces()
{
	for (int i = 0; i < PIECES_PER_PLAYER; i++)
	{
		this->pieces.push_back(new Piece(Ownership::PlayerOne, sf::Vector2f(500.0f, 35.0f + (15.0f * i))));
		this->pieces.push_back(new Piece(Ownership::PlayerTwo, sf::Vector2f(650.0f, 35.0f + (15.0f * i))));
	}
}

Board::Board()
{
	this->InitBackground();
	this->InitPoints();
	this->InitPieces();
}

Board::~Board()
{

}

void Board::Render(sf::RenderWindow* window)
{
	window->draw(background);

	for (auto piece : this->pieces)
	{
		piece->Render(window);
	}
}
