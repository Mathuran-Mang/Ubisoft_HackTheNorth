#include "PlayerMovementComponent.h"

#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace GameEngine;

void PlayerMovementComponent::Update() 
{
	Component::Update();
	
	//Grabs how much time has passed since last frame
	const float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//By default the displacement is 0,0
	sf::Vector2f displacement{ 0.0f, 0.0f };

	//The amount of speed that we will apply when input is recieved
	const float inputAmount = 300.0f;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			displacement.y -= inputAmount * dt;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			displacement.y += inputAmount * dt;
		}
	

	GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void PlayerMovementComponent::OnAddToWorld() {}