#include "Text.h"

Text::Text(sf::Vector2f position, sf::String text)
{
	this->Init();
	this->SetPosition(position);
	this->SetText(text);
	this->SetColor(sf::Color::Red);
}

void Text::Init()
{
	if (!this->font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << ERROR_LOADING_FONT << std::endl;
	}

	this->text.setFont(this->font);
	this->text.setCharacterSize(24);
}

void Text::Render(sf::RenderWindow * window)
{
	window->draw(text);
}

void Text::SetPosition(sf::Vector2f position)
{
	this->text.setPosition(position);
}

void Text::SetText(std::string string)
{
	this->text.setString(string);
}

void Text::SetColor(sf::Color color)
{
	this->text.setFillColor(color);
}
