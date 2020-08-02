#ifndef TILEMAP
#define TILEMAP

#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& t_tileset, sf::Vector2u tileSize, const int* t_tiles,
		unsigned int t_width, unsigned int t_height);

private:
	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileSet;
};

#endif // !TILEMAP