#include "blockesladrillosx4.h"
#include<SFML/Graphics.hpp>

blockesladrillosx4::blockesladrillosx4() {

    _texture.loadFromFile("ladrillosx4.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = 0;
    _y = 0;
}
blockesladrillosx4::blockesladrillosx4(float x, float y) {

    _texture.loadFromFile("ladrillosx4.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = x;
    _y = y;
}
void blockesladrillosx4::update() {


    _sprite.setPosition(_x, _y);


}
void blockesladrillosx4::draw(sf::RenderTarget& target, sf::RenderStates states)const {

    target.draw(_sprite, states);
}
sf::FloatRect blockesladrillosx4::getBounds() const
{

    return _sprite.getGlobalBounds();
}


void blockesladrillosx4::setlimitesuperior(float limite)
{
    _limitesuperior = _sprite.getGlobalBounds().top;
}

float blockesladrillosx4::getlimitesuperior()
{
    return  _limitesuperior;
}
