#pragma once
#include<SFML/Graphics.hpp>
#include"colisionable.h"

class blockesolidox4 :public sf::Drawable, public colisionable
{
	sf::Sprite _sprite;
	sf::Texture _texture;
	//float _velocidad;
	sf::Vector2f _velocidad;//VECTOR PARA MOVIMIENTO DE REBOTE AUTOMATICO
	float _x;
	float _y;

public:
	blockesolidox4();
	blockesolidox4(float x, float y);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds()const override;
};

