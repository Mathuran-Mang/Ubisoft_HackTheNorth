#include "PlayerMovementComponent.h"

#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace GameEngine;

PlayerMovementComponent::PlayerMovementComponent()
	: m_isPlayerOne(false)
	, m_isPlayerTwo(false)
{

}

PlayerMovementComponent::~PlayerMovementComponent()
{

}


void PlayerMovementComponent::Update() 
{
	Component::Update();
	
	//Grabs how much time has passed since last frame
	const float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//By default the displacement is 0,0
	sf::Vector2f displacement{ 0.0f, 0.0f };

	//The amount of speed that we will apply when input is recieved
	const float inputAmount = 300.0f;

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_isPlayerOne == true) 
		{
			displacement.y -= inputAmount * dt;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_isPlayerOne == true)
		{
			displacement.y += inputAmount * dt;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_isPlayerOne == false)
		{
			displacement.y -= inputAmount * dt;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_isPlayerOne == false)
		{
			displacement.y += inputAmount * dt;
		}


	


	GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void PlayerMovementComponent::OnAddToWorld() {}