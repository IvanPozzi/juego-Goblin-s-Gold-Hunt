#include "buo.h"
#include<SFML/Graphics.hpp>
#include<stdlib.h>


buo::buo() {

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
buo::buo(float x, float y, float escax, float escay, float vx, float vy) {

    //_texture.loadFromFile("buoimagen.png");
    _texture.loadFromFile("buoimagen.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0,4,96,89 });
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
void buo::update() {
    if (_nacio == true) {
        _sprite.setScale(_escax, _escay);
        _frame += 0.2;
        if (_frame >= 3) {
            _frame = 0;
        }
        _sprite.setTextureRect({ 0 + int(_frame) * 96,4,96,89 });
        //_sprite.setScale(0.22,0.22 );
        //_sprite.setTextureRect({ 0+ int(_frame) * 600,0,600,393 });

        /* if (_velocidad.x == 0 || _colisionando == false) {
             _sprite.setTextureRect({ 0 + 100,4,75,89 });
         }*/
        _sprite.move(_velocidad);




        if (_sprite.getPosition().x < 15) {

            _velocidad.x = -_velocidad.x * 1.001;//logica para que rebote un objeto y elevacion de velocidad
        }

        if (_sprite.getPosition().x > 775) {

            _velocidad.x = -_velocidad.x * 1.001;//logica para que rebote un objeto
        }

        if (_sprite.getPosition().y > 495) {

            _velocidad.y = -_velocidad.y * 1.001;//logica para que rebote un objeto
        }
        else if (_sprite.getPosition().y < 25) {
            _velocidad.y = -_velocidad.y * 1.001;

        }




        /*if (_sprite.getPosition().y < 0) {
            _sprite.setPosition(_sprite.getPosition().x, 0);
            //_velocidad.y = -_velocidad.y*1.001;//logica para que rebote un objeto
        }*/
        if (_muerto == true) {
            _velocidad = { 0,0 };
            _sprite.setTextureRect({ 290,4,96,89 });
            //_sprite.setTextureRect({ 3600,0,600,393 });

            _framemuerte += 0.2;
            if (_framemuerte >= 10) {
                _sprite.setTextureRect({ 385,4,96,89 });
               // _sprite.setTextureRect({ 4200,0,600,393 });
                _velocidad = { 0,3 };
                if (_framemuerte > 25) {
                    _sprite.setPosition(_x, _y);
                    _muerto = false;
                    _velocidad = { 2,3 };
                    _siguemuerto = false;
                }
            }
        }
    }


}
void buo::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite, states);
}
void buo::respawn() {

}

sf::FloatRect buo::getBounds() const
{
    return _sprite.getGlobalBounds();

}
void buo::limitedesuelo()
{
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > _limite) {
        _sprite.setPosition(_sprite.getPosition().x, _limite - 44);
    }

}
void buo::setlimite(int y)
{
    _limite = y;
}

void buo::encolision()
{
    _colisionando = true;
}

void buo::dejodecolisionar()
{
    _colisionando = false;
}
void buo::cambiodedireccion() {
    if (_velocidad.x == 2) {
        _velocidad = { -2,3 };
    }
    else if (_velocidad.x == -2) {
        _velocidad = { 2,3 };
    }
}
void buo::muerto() {
    _muerto = true;
    _framemuerte = 0;
    _siguemuerto = true;
}
bool buo::getsiguemuerto() {
    return _siguemuerto;
}
void buo::nacio() {
    _nacio = true;
}
bool buo::getnacio() {
    return _nacio;
}
