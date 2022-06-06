#include "map.h"

Map::Map(std::string F) : File(F)
{
    m_tileset.loadFromFile("images/" + File);
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(WIDHT_MAP * HEIGHT_MAP* 4.0);
    for (int i = 0; i < HEIGHT_MAP; ++i)
    {
        for (int j = 0; j < WIDHT_MAP; ++j)
        {
            if (i == 0 || i == 1 || i == HEIGHT_MAP - 1 || i == HEIGHT_MAP - 2)
                title[j + i * WIDHT_MAP] = 1;
            else if (j == 0 || j == 1 || j == WIDHT_MAP - 1 || j == WIDHT_MAP - 2)
                title[j + i * WIDHT_MAP] = 1;
            else
                title[j + i * WIDHT_MAP] = 0;
        }
    }
    for (int j = 0; j < HEIGHT_MAP; ++j)
    {
        for (int i = 0; i < WIDHT_MAP; ++i)
        {
            int tileNumber = title[i + j * WIDHT_MAP];
            int tu = tileNumber;
            int tv = 0;
            clicked.push_back({ { i * 89, j * 89, 89, 89}, i + j * WIDHT_MAP });
            sf::Vertex* quad = &m_vertices[(i + j * WIDHT_MAP) * 4];
            quad[0].position = sf::Vector2f(i * 89, j * 89);
            quad[1].position = sf::Vector2f((i + 1) * 89, j * 89);
            quad[2].position = sf::Vector2f((i + 1) * 89, (j + 1) * 89);
            quad[3].position = sf::Vector2f(i * 89, (j + 1) * 89);
            quad[0].texCoords = sf::Vector2f(tu * 89, 0);
            quad[1].texCoords = sf::Vector2f((tu + 1) * 89, 0);
            quad[2].texCoords = sf::Vector2f((tu + 1) * 89, 1 * 89);
            quad[3].texCoords = sf::Vector2f(tu * 89, 1 * 89);
        }
    }
}

int Map::clickChecked(int x, int y, int fx, int fy) 
{
    sf::CircleShape center;
    center.setRadius(140);
    center.setPosition(fx + 26 - 140, fy + 60 - 140);
    for (int i = 0; i < clicked.size();i++) 
    {
        if (sf::IntRect(clicked[i].first[0], clicked[i].first[1], clicked[i].first[2], clicked[i].first[3]).contains(sf::Vector2i(x, y)) && center.getGlobalBounds().contains(sf::Vector2f(x,y))) 
        {
            if (title[clicked[i].second] == 0)
            {
                title[clicked[i].second] = 4;
                genTitle();
                return 0;
            }
            else if (title[clicked[i].second] == 4)
            {
                title[clicked[i].second] = 2;
                if (!veg.count(clicked[i].second))veg.insert({ clicked[i].second, 0 });
                else veg.find(clicked[i].second)->second = 0;
                genTitle();
                return clicked[i].second;
            }
        }
    }
    return 0;
}

void Map::checkGarden(float time)
{
    for (auto&x : veg)
    {
        x.second = x.second == -1 ? -1 : x.second + time;
        int i = x.first;
        if (x.second >= 60000)
        {
            int i = x.first;
            title[clicked[i].second] = 3;
            if (!veg.count(clicked[i].second))veg.insert({ clicked[i].second, 0 });
            else veg.find(clicked[i].second)->second = 0;
            genTitle();
        }
    }
}

void Map::genTitle()
{
    for (int j = 0; j < HEIGHT_MAP; ++j)
    {
        for (int i = 0; i < WIDHT_MAP; ++i)
        {
            int tileNumber = title[i + j * WIDHT_MAP];
            int tu = tileNumber;
            sf::Vertex* quad = &m_vertices[(i + j * WIDHT_MAP) * 4];
            quad[0].position = sf::Vector2f(i * 89, j * 89);
            quad[1].position = sf::Vector2f((i + 1) * 89, j * 89);
            quad[2].position = sf::Vector2f((i + 1) * 89, (j + 1) * 89);
            quad[3].position = sf::Vector2f(i * 89, (j + 1) * 89);
            quad[0].texCoords = sf::Vector2f(tu * 89, 0);
            quad[1].texCoords = sf::Vector2f((tu + 1) * 89, 0);
            quad[2].texCoords = sf::Vector2f((tu + 1) * 89, 1 * 89);
            quad[3].texCoords = sf::Vector2f(tu * 89, 1 * 89);
        }
    }
}

bool Map::checkCarrot(int x, int y, float fx, float fy)
{
    sf::CircleShape center;
    center.setRadius(40);
    center.setPosition(fx + 26 - 40, fy + 60 - 40);
    center.setFillColor(sf::Color::Red);
    for (int i = 0; i < clicked.size(); i++)
    {
        if (sf::IntRect(clicked[i].first[0], clicked[i].first[1], clicked[i].first[2], clicked[i].first[3]).contains(sf::Vector2i(x, y))  && center.getGlobalBounds().contains(sf::Vector2f(x, y)))
        {
            if (title[clicked[i].second] == 3)
            {
                title[clicked[i].second] = 0;
                veg.erase(clicked[i].second);
                genTitle();
                return true;
            }
            if (title[clicked[i].second] == 4)
            {
                title[clicked[i].second] = 0;
                genTitle();
                return false;
            }
        }
    }
    return false;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_tileset;
    target.draw(m_vertices, states);
}
