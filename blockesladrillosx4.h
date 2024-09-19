#pragma once
#include<SFML/Graphics.hpp>
#include"colisionable.h"

class blockesladrillosx4 :public sf::Drawable, public colisionable
{
	sf::Sprite _sprite;
	sf::Texture _texture;
	//float _velocidad;
	sf::Vector2f _velocidad;//VECTOR PARA MOVIMIENTO DE REBOTE AUTOMATICO
	float _x;
	float _y;
	float _limitesuperior;

public:
	blockesladrillosx4();
	blockesladrillosx4(float x, float y);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds()const override;
	void setlimitesuperior(float limite);
	float getlimitesuperior();

};


