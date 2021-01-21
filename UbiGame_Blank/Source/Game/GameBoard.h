#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();		
		bool IsGameOver() { return false; }

	private:
		void CreateObstacle();
		void CreatePlayer();
		void CreateBall();
		int a;
		GameEngine::Entity* m_player;
		GameEngine::Entity* m_player_two;
		GameEngine::Entity* ball;
		GameEngine::Entity* border;
		GameEngine::Entity* border2;
	};
}

