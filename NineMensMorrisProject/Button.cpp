#include "Button.h"

Button::Button()
{
	rect.setSize(sf::Vector2f(32.0f, 32.0f));
}

Button::~Button()
{
}

void Button::Render(sf::RenderWindow * window)
{
	window->draw(rect);
}

void Button::SetPosition(sf::Vector2f position)
{
	this->position = position;
	rect.setPosition(position);
}

bool Button::IsMouseOver(sf::RenderWindow* window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	return rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat));
}

bool Button::IsMousePressed()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

sf::Vector2f Button::GetPosition()
{
	return this->position;
}
