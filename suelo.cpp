#include "suelo.h"
#include<SFML/Graphics.hpp>

suelo::suelo() {

    _texture.loadFromFile("suelo.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);

}
void suelo::update() {


    _sprite.setPosition(30, 580);


}
void suelo::draw(sf::RenderTarget& target, sf::RenderStates states)const {

    target.draw(_sprite, states);
}
sf::FloatRect suelo::getBounds() const
{
    return _sprite.getGlobalBounds();
}
