#include "blockesolidox3.h"
#include<SFML/Graphics.hpp>

blockesolidox3::blockesolidox3() {

    _texture.loadFromFile("solidox3.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = 0;
    _y = 0;
}
blockesolidox3::blockesolidox3(float x, float y) {

    _texture.loadFromFile("solidox3.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _x = x;
    _y = y;
}
void blockesolidox3::update() {


    _sprite.setPosition(_x, _y);


}
void blockesolidox3::draw(sf::RenderTarget& target, sf::RenderStates states)const {

    target.draw(_sprite, states);
}
sf::FloatRect blockesolidox3::getBounds() const
{
    sf::FloatRect bounds = _sprite.getGlobalBounds();
    return sf::FloatRect(bounds.left, bounds.top, bounds.width, -1.0f);
}