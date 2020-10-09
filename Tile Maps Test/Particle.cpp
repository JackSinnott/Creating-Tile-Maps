#include "Particle.h"

Particle::Particle(sf::Vector2f t_direction)
{
	// Determine direction

	m_velocity.x = t_direction.x;
	m_velocity.y = t_direction.y;
}

void Particle::update(float t_dt)
{
	// Move the particle
	m_position += m_velocity * t_dt;
}

void Particle::setPosition(sf::Vector2f t_position)
{
	m_position = t_position;
}

sf::Vector2f Particle::getPosition()
{
	return m_position;
}
