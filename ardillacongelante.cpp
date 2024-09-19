#include "ardillacongelante.h"
#include<SFML/Graphics.hpp>
#include<stdlib.h>


ardillacongelante::ardillacongelante() {

    _texture.loadFromFile("");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0,0,0,0 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = 0;
    _y = 0;
    _velocidad = { 0,0 };
    _frame = 0;
    _colisionando == false;

}
ardillacongelante::ardillacongelante(float x, float y, float escax, float escay, float vx, float vy) {

    _texture.loadFromFile("ardillacongelante.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 10,4,75,89 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(x, y);
    _x = x;
    _y = y;
    _vx = vx;
    _vy = vy;
    _frame = 0;
    _colisionando == false;
    _muerto = false;
    _framemuerte = 0;
    _siguemuerto = false;
    _escax = escax;
    _escay = escay;
    _velocidad = { _vx,_vy };
    _nacio = false;


}
void ardillacongelante::update() {
    if (_nacio == true) {
        _sprite.setScale(_escax, _escay);
        _frame += 0.2;
        if (_frame >= 4) {
            _frame = 0;
        }

        if (_velocidad.x == 0 || _colisionando == false) {
            _sprite.setTextureRect({ 10 + 100,4,75,89 });
        }
        else {
            _sprite.setTextureRect({ 10 + int(_frame) * 100,4,75,89 });
        }


        //movimiento:
       // _velocidad = { 2,3 };
        _sprite.move(_velocidad);


        if (_velocidad.x < 0) {
            _sprite.setScale(-_escax, _escay);
        }
        else if (_velocidad.x > 0) {
            _sprite.setScale(_escax, _escay);
        }
        if (_sprite.getPosition().x < 15 && _sprite.getPosition().y < 495) {
            _sprite.setPosition(810, _sprite.getPosition().y);
            //_velocidad.x = -_velocidad.x * 1.001;//logica para que rebote un objeto y elevacion de velocidad
        }

        if (_sprite.getPosition().x > 810 && _sprite.getPosition().y < 495) {
            _sprite.setPosition(15, _sprite.getPosition().y);
            //_velocidad.x = -_velocidad.x*1.001;//logica para que rebote un objeto
        }

        if (_sprite.getPosition().y > 495 && _sprite.getPosition().x > 800) {
            _sprite.setPosition(95, _y);
            //_velocidad.y = -_velocidad.y*1.001;//logica para que rebote un objeto
        }
        else if (_sprite.getPosition().y > 495 && _sprite.getPosition().x < 15) {
            _sprite.setPosition(700, _y);

        }




        /*if (_sprite.getPosition().y < 0) {
            _sprite.setPosition(_sprite.getPosition().x, 0);
            //_velocidad.y = -_velocidad.y*1.001;//logica para que rebote un objeto
        }*/
        if (_muerto == true) {
            _velocidad = { 0,3 };
            _sprite.setTextureRect({ 405,4,100,89 });

            _framemuerte += 0.2;
            if (_framemuerte >= 10) {
                _sprite.setTextureRect({ 505,4,100,89 });
                if (_framemuerte > 25) {
                    _sprite.setPosition(_x, _y);
                    _muerto = false;
                    _velocidad = { 4,6 };
                    _siguemuerto = false;
                }
            }
        }
    }


}
void ardillacongelante::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite, states);
}
void ardillacongelante::respawn() {

}

sf::FloatRect ardillacongelante::getBounds() const
{
    return _sprite.getGlobalBounds();

}
void ardillacongelante::limitedesuelo()
{
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > _limite) {
        _sprite.setPosition(_sprite.getPosition().x, _limite - 44);
    }

}
void ardillacongelante::setlimite(int y)
{
    _limite = y;
}

void ardillacongelante::encolision()
{
    _colisionando = true;
}

void ardillacongelante::dejodecolisionar()
{
    _colisionando = false;
}
void ardillacongelante::cambiodedireccion() {
    if (_velocidad.x == 4) {
        _velocidad = { -4,6 };
    }
    else if (_velocidad.x == -4) {
        _velocidad = { 4,6 };
    }
}
void ardillacongelante::muerto() {
    _muerto = true;
    _framemuerte = 0;
    _siguemuerto = true;
}
bool ardillacongelante::getsiguemuerto() {
    return _siguemuerto;
}
void ardillacongelante::nacio() {
    _nacio = true;
}
bool ardillacongelante::getnacio() {
    return _nacio;
}