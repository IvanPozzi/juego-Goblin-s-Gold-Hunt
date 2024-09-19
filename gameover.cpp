#include "gameover.h"
#include<SFML/Graphics.hpp>
#include<stdlib.h>


gameover::gameover() {

    _texture.loadFromFile("game over.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0,0,600,309 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(400, 300);

}
void gameover::update() {
    _sprite.setTextureRect({ 0,0,600,309 });
}
void gameover::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite, states);
}

sf::FloatRect gameover::getBounds() const
{
    return _sprite.getGlobalBounds();
}