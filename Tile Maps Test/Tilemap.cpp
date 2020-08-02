#include "Tilemap.h"

bool Tilemap::load(const std::string& t_tileset, sf::Vector2u t_tileSize, const int* t_tiles, unsigned int t_width, unsigned int t_height)
{
    if(!m_tileSet.loadFromFile("ASSETS\\IMAGES\\tilemap-tileset.png"))
    return false;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(t_width * t_height * 4);

    for (unsigned int i = 0; i < t_width; ++i)
        for (unsigned int j = 0; j < t_height; ++j)
        {
            int m_tileNumber = t_tiles[i + j * t_width];

            int m_tu = m_tileNumber % (m_tileSet.getSize().x / t_tileSize.x);
            int m_tv = m_tileNumber / (m_tileSet.getSize().x / t_tileSize.x);

            sf::Vertex* m_quad = &m_vertices[(i + j * t_width) * 4];

            m_quad[0].position = sf::Vector2f(i * t_tileSize.x, j * t_tileSize.y);
            m_quad[1].position = sf::Vector2f((i + 1) * t_tileSize.x, j * t_tileSize.y);
            m_quad[2].position = sf::Vector2f((i + 1) * t_tileSize.x, (j + 1) * t_tileSize.y);
            m_quad[3].position = sf::Vector2f(i * t_tileSize.x, (j + 1) * t_tileSize.y);

            m_quad[0].texCoords = sf::Vector2f(m_tu * t_tileSize.x, m_tv * t_tileSize.y);
            m_quad[1].texCoords = sf::Vector2f((m_tu + 1) * t_tileSize.x, m_tv * t_tileSize.y);
            m_quad[2].texCoords = sf::Vector2f((m_tu + 1) * t_tileSize.x, (m_tv + 1) * t_tileSize.y);
            m_quad[3].texCoords = sf::Vector2f(m_tu * t_tileSize.x, (m_tv + 1) * t_tileSize.y);
        }

    return true;

    
}

void Tilemap::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
    t_states.transform *= getTransform();

    t_states.texture = &m_tileSet;

    t_target.draw(m_vertices, t_states);
}
