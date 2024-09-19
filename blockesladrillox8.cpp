#include "blockesladrillox8.h"
#include<SFML/Graphics.hpp>

blockesladrillosx8::blockesladrillosx8() {

    _texture.loadFromFile("ladrillosx8.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = 250;
    _y = 300;
}
blockesladrillosx8::blockesladrillosx8(float x, float y) {

    _texture.loadFromFile("ladrillosx8.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = x;
    _y = y;
}
void blockesladrillosx8::update() {


    _sprite.setPosition(_x, _y);


}
void blockesladrillosx8::draw(sf::RenderTarget& target, sf::RenderStates states)const {

    target.draw(_sprite, states);
}
sf::FloatRect blockesladrillosx8::getBounds() const
{
    return _sprite.getGlobalBounds();
}
