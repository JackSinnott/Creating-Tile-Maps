#ifndef PARTICLE
#define PARTICLE

#include <SFML/Graphics.hpp>

class Particle
{
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

public:
	Particle(sf::Vector2f t_direction);
	void update(float t_dt);
	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition();
};

#endif //!PARTICLE