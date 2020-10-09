#ifndef PARTICLESYSTEM
#define PARTICLESYSTEM

#include <SFML/Graphics.hpp>
#include "Particle.h"

class ParticleSystem : public sf::Drawable
{
private:
	std::Vector<Particles> m_particles;
	sf::VectorArray m_vertices;
	float m_duration;
	bool m_isRunning = false;

public:
	virtual void draw(sf::Rendertarget& t_target, sf::Renderstates t_states) const;
	void init(int t_count);
	void emitParticles(sf::Vector2f t_position);
	void update(float t_elapsed);
	bool running();

}
#endif //!PARTICLESYSTEM