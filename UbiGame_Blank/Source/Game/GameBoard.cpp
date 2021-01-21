#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"

#include "GameEngine/EntitySystem/Components/PlayerMovementComponent.h"

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreateBall();
	CreateObstacle();
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

	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
	m_player_two->AddComponent<GameEngine::CollidablePhysicsComponent>();
}

void GameBoard::CreateObstacle()
{
	border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(border);

	border->SetPos(sf::Vector2f(500.0f, 0.0f));  // <-- Move its initial position
	border->SetSize(sf::Vector2f(1000.0f, 20.0f)); // <-- Make the square bigger

	GameEngine::RenderComponent* renderborder = border->AddComponent<GameEngine::RenderComponent>();

	renderborder->SetFillColor(sf::Color::Yellow);

	border->AddComponent<GameEngine::CollidablePhysicsComponent>();

	border2 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(border2);

	border2->SetPos(sf::Vector2f(500.0f, 500.0f));  // <-- Move its initial position
	border2->SetSize(sf::Vector2f(1000.0f, 20.0f)); // <-- Make the square bigger

	GameEngine::RenderComponent* renderborder1 = border2->AddComponent<GameEngine::RenderComponent>();

	renderborder1->SetFillColor(sf::Color::Yellow);

	border2->AddComponent<GameEngine::CollidablePhysicsComponent>();

}
void GameBoard::CreateBall()
{
	
	ball = new GameEngine::Entity();
	
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ball);
	ball->SetPos(sf::Vector2f(250.0f, a));  // <-- Move its initial position
	ball->SetSize(sf::Vector2f(30.0f, 30.0f));

	GameEngine::RenderComponent* render_ball = ball->AddComponent<GameEngine::RenderComponent>(); // <-- Capturing the new component

	render_ball->SetFillColor(sf::Color::Green); // <-- Change the fill color to Red


}
GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{
	
	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	a = (double)rand() / (290 + 1) /dt;
}