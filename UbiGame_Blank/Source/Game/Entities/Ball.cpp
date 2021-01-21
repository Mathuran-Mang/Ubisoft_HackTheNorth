#include "Ball.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/Util/CollisionManager.h"


using namespace Game;

Ball::Ball()
	: m_velocity(sf::Vector2f(0.f, 0.f))
	, m_lifeTime(10.f)

{

}

Ball::~Ball()
{

}

void Ball::Update()
{
	__super::Update();

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	m_lifeTime -= dt;
}