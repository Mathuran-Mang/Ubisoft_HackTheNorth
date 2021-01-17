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

	m_player->SetPos(sf::Vector2f(50.0f, 250.0f));  // <-- Move its initial position
	m_player->SetSize(sf::Vector2f(15.0f, 125.0f)); // <-- Make the square bigger

	GameEngine::RenderComponent* render = m_player->AddComponent<GameEngine::RenderComponent>(); // <-- Capturing the new component

	render->SetFillColor(sf::Color::Blue); // <-- Change the fill color to Red

	m_player->AddComponent<GameEngine::PlayerMovementComponent>();

	m_player->GetComponent<GameEngine::PlayerMovementComponent>()->m_isPlayerOne = true;


	m_player_two = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player_two);

	m_player_two->SetPos(sf::Vector2f(450.0f, 250.0f));  // <-- Move its initial position
	m_player_two->SetSize(sf::Vector2f(15.0f, 125.0f)); // <-- Make the square bigger

	GameEngine::RenderComponent* render_playertwo = m_player_two->AddComponent<GameEngine::RenderComponent>(); // <-- Capturing the new component

	render_playertwo->SetFillColor(sf::Color::Green); // <-- Change the fill color to Red

	m_player_two->AddComponent<GameEngine::PlayerMovementComponent>();

	m_player_two->GetComponent<GameEngine::PlayerMovementComponent>()->m_isPlayerOne = false;
}

void GameBoard::CreateObstacle()
{

}

GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}