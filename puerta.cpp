#include "puerta.h"
#include<SFML/Graphics.hpp>

puerta::puerta() {

    _texture.loadFromFile("puerta.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = 0;
    _y = 0;
}
puerta::puerta(float x, float y) {

    _texture.loadFromFile("puerta.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = x;
    _y = y;
}
void puerta::update() {


    _sprite.setPosition(_x, _y);


}
void puerta::draw(sf::RenderTarget& target, sf::RenderStates states)const {

    target.draw(_sprite, states);
}
sf::FloatRect puerta::getBounds() const
{
    sf::FloatRect bounds = _sprite.getGlobalBounds();
    return sf::FloatRect(bounds.left, bounds.top, bounds.width, -1.0f);
}
