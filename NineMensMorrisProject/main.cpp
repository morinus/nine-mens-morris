#include "Game.h"

int main()
{
	// Init game engine
	Game game;
	sf::Clock clock;

	// Game loop
	while (game.GetWindowIsOpen())
	{
		// Update
		game.Update();

		// Render
		game.Render(clock.restart().asMilliseconds());
	}

	return 0;
}