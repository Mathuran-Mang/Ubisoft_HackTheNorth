#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"

#include "GameEngine/EntitySystem/Components/PlayerMovementComponent.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.0f, 50.0f));  // <-- Move its initial position
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f)); // <-- Make the square bigger

	GameEngine::RenderComponent* render = m_player->AddComponent<GameEngine::RenderComponent>(); // <-- Capturing the new component

	render->SetFillColor(sf::Color::Blue); // <-- Change the fill color to Red

	m_player->AddComponent<GameEngine::PlayerMovementComponent>();
}

GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}