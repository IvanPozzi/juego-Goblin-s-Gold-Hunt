#pragma once
#include<SFML/Graphics.hpp>
#include<stdlib.h>
#include"colisionable.h"
class item :public sf::Drawable, public colisionable
{
	sf::Sprite _sprite;
	sf::Texture _texture;
	//float _velocidad;
	sf::Vector2f _velocidad;//VECTOR PARA MOVIMIENTO DE REBOTE AUTOMATICO

public:
	item();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn();
	sf::FloatRect getBounds()const override;



};
