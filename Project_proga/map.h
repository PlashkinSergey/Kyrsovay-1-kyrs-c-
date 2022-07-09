#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

class Map: public sf::Drawable, public sf::Transformable
{
public:
	explicit Map(std::string);
	int clickChecked(int, int, int, int);
	void checkGarden(float);
	bool checkCarrot(int, int, float, float);
private:
	void genTitle();
	static const int HEIGHT_MAP = 20;
	static const int WIDHT_MAP = 20;
	std::string File;
	std::map<int, float> veg;
	std::vector<std::pair<std::vector<int>, int>> clicked;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	int title[HEIGHT_MAP * WIDHT_MAP];
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};
