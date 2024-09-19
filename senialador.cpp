#include "senialador.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<stdlib.h>

senialador::senialador() {
    _texture.loadFromFile("senialador.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0,0,80,80 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(250, 300);
    _Y = 300;
    _comenzarjuego = false;
    _salir = false;
    _creditos = false;
    _score = false;

}
void senialador::update() {
    sf::Joystick::isConnected(0);
    float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    //SONIDO DE PUNTERO:
    sf::SoundBuffer bufferpuntero;
    bufferpuntero.loadFromFile("pop.wav");
    sf::Sound soundpuntero;
    soundpuntero.setBuffer(bufferpuntero);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || y < -30)
    {
        soundpuntero.play();

        if (_Y > 300) {
            _sprite.setPosition(250, _Y -= 70);
        }
        else {
            _sprite.setPosition(250, 300);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || y > 30)
    {
        soundpuntero.play();

        if (_Y < 510) {
            _sprite.setPosition(250, _Y += 70);
        }
        else if (_Y > 580) {
            _sprite.setPosition(250, 580);
        }

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _Y == 300 || sf::Joystick::isButtonPressed(0, 0) && _Y == 300) {

        _comenzarjuego = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _Y == 370 || sf::Joystick::isButtonPressed(0, 0) && _Y == 370) {
        _creditos = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _Y == 440 || sf::Joystick::isButtonPressed(0, 0) && _Y == 440) {

        _score = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && _Y == 510 || sf::Joystick::isButtonPressed(0, 0) && _Y == 440) {

        _salir = true;
    }
}


void senialador::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite, states);
}
sf::FloatRect senialador::getBounds() const
{
    return _sprite.getGlobalBounds();

}
void senialador::setcomenzarjuego() {
    _comenzarjuego = false;
}
void senialador::setcreditos() {
    _creditos = false;
}
void senialador::setscore() {
    _score = false;
}
bool senialador::getcomenzarjuego() {
    return _comenzarjuego;
}
bool senialador::getsalir() {
    return _salir;
}
bool senialador::getcreditos() {
    return _creditos;
}
bool senialador::getscore() {
    return _score;
}