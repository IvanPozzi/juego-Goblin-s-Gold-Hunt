#include "vida.h"
#include<SFML/Graphics.hpp>
#include<stdlib.h>


vida::vida() {

    _texture.loadFromFile("vida.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0,4,100,90 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(60, 570);
    _vida = 0;
}
void vida::update() {
    _sprite.setTextureRect({ 0 + _vida * 100,4,100,90 });
}
void vida::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite, states);
}
void vida::descontadordevida() {
    _vida += 1;
}
int vida::getvida() {
    return _vida;
}

sf::FloatRect vida::getBounds() const
{
    return _sprite.getGlobalBounds();
}