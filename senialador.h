#pragma once
#include<SFML/Graphics.hpp>
#include"colisionable.h"

class senialador :public sf::Drawable, public colisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	int _Y;
	bool _comenzarjuego;
	bool _salir;
	bool _creditos;
	bool _score;
public:
	senialador();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds()const override;
	void setcreditos();
	void setscore();
	void setcomenzarjuego();
	bool getcomenzarjuego();
	bool getsalir();
	bool getcreditos();
    bool getscore();

};
