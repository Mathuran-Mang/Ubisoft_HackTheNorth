#pragma once

namespace Game
{
	class Ball : public GameEngine::CollidableComponent
	{
	public:
		Ball();
		~Ball();

		virtual void Update() override;
		void SetLifetTime(float lifetime) { m_lifeTime = lifetime; }

	private:
		float m_lifeTime;
		sf::Vector2f m_velocity;
	};
}