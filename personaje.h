#pragma once
#include<SFML/Graphics.hpp>
#include"personaje.h"
#include"colisionable.h"


class Personaje :public sf::Drawable, public colisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    //float _velocidad;
    sf::Vector2f _velocidad;//VECTOR PARA MOVIMIENTO DE REBOTE AUTOMATICO
    int _limite;
    bool _colisionando = false;
    bool _up;
    float _limiteinferior;
    bool spacePresionada = false;
    float _frame;
    float _frame2;
    bool _muerto;
    bool _susto;
    float _framemuerte;
    float _framerespawn;
    int _b;
    int _b2;
    bool _ataque;
    float _framecongelado = 0;
    bool _congelado = false;
    bool _gameover = false;
    bool _revivido;
  
public:
    Personaje();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds()const override;
    void setlimite(int _y);
    void limitedesuelo();
    void setlimiteinferior();
    void encolision();
    void dejodecolisionar();
    void murio();
    void susto();
    void respawn();
    bool getmuerto();
    bool getatacando();
    void congelado();
    bool getcongelado();
    void gameover();
    const float getescale();
   
    
   
    





};

/*Personaje::Personaje{
    _textura.loadFromFile("duendecaminando1.png");
    _sprite.setTexture(_textura);
}
Personaje::update{

    //CMD _ ejecucion de comandos(joy)

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _sprite.move(0,-_velocidad);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _sprite.move(-_velocidad,0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _sprite.move(0, _velocidad);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _sprite.move(_velocidad,0);
    }
    //limites de pantalla:
    if (_sprite.getPosition().x < 0) {
        _sprite.setPosition(0, _sprite.getPosition().y);
    }

    if (_sprite.getPosition().x > 730) {
        _sprite.setPosition(730, _sprite.getPosition().y);
    }

    if (_sprite.getPosition().y < 0) {
        _sprite.setPosition(_sprite.getPosition().x, 0);
    }

    if (_sprite.getPosition().y > 480) {
        _sprite.setPosition(_sprite.getPosition().x,480);
    }

}*/

