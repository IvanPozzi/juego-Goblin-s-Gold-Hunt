#pragma once
#include<SFML/Graphics.hpp>
#include<stdlib.h>
#include"colisionable.h"

	class ardillacongelante :public sf::Drawable, public colisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	//float _velocidad;
	sf::Vector2f _velocidad;//VECTOR PARA MOVIMIENTO DE REBOTE AUTOMATICO
	float _x = 0;
	float _y = 0;
	bool _colisionando = false;
	int _limite;
	float _frame;
	bool _muerto;
	float _framemuerte;
	bool _siguemuerto;
	float _escax;
	float _escay;
	float _vx;
	float _vy;
	bool _nacio;
public:
	ardillacongelante();
	ardillacongelante(float x, float y, float escax, float escy, float vx, float vy);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn();
	sf::FloatRect getBounds()const override;
	void limitedesuelo();
	void setlimiteinferior();
	void encolision();
	void dejodecolisionar();
	void setlimite(int _y);
	void cambiodedireccion();
	void muerto();
	bool getsiguemuerto();
	void nacio();
	bool getnacio();
};

