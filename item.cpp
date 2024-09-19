#include "item.h"
#include<SFML/Graphics.hpp>
#include<stdlib.h>


item::item() {

    _texture.loadFromFile("moneda.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0,0,50,50 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(400, 360);
}
void item::update() {

}
void item::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite, states);
}
void item::respawn() {
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
}

sf::FloatRect item::getBounds() const
{
    return _sprite.getGlobalBounds();
}