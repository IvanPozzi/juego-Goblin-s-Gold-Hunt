#pragma once
#include<SFML/Graphics.hpp>
#include<stdlib.h>
#include"colisionable.h"
class gameover :public sf::Drawable, public colisionable
{
	sf::Sprite _sprite;
	sf::Texture _texture;
public:
	gameover();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds()const override;




};
