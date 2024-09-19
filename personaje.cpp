#include "personaje.h"
#include<SFML/Graphics.hpp>
#include<stdlib.h>


Personaje::Personaje() {
    _frame = 0;
    _frame2 = 0;
    _velocidad = { 3.5,3.5 };
    _texture.loadFromFile("duende.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 49,19,75,115 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2.8, _sprite.getGlobalBounds().height);
    _framemuerte = 0;
    _framerespawn = 0;
    _sprite.setPosition(400, 500);
    _b = 0;
    _b2 = 0;
    _muerto = false;
    _ataque = false;
    _gameover = false;
    _revivido = true;
    


}

void Personaje::update() {
    sf::Joystick::isConnected(0);
    float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    
        _ataque = false;

        _framerespawn += 0.2;
        _framemuerte += 0.2;

        if (_framemuerte >= 2) {

            _framemuerte = 0;
        }



        //CMD _ ejecucion de comandos(joy)
        //MUERTE DE PERSONAJE:



        _up = false;

        _velocidad = { 0,3 };

        _frame += 0.2;
        if (_frame >= 4) {
            _frame = 0;
        }
        if (_velocidad.x == 0) {
            _sprite.setTextureRect({ 49,18,75,115 });
        }
        //ATAQUE:

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && _revivido == true && _congelado == false|| sf::Joystick::isButtonPressed(0, 0) && _revivido == true && _congelado == false)
        {
            _frame += 0.2;
            if (_frame >= 3) {
                _frame = 0;
            }


            _sprite.setTextureRect({ 1249 + int(_frame) * 150,18,75,115 });
            _ataque = true;


        }





        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && spacePresionada == false && _colisionando == true && _congelado == false && _revivido == true|| sf::Joystick::isButtonPressed(0, 1) && spacePresionada == false && _colisionando == true && _congelado == false && _revivido == true) {
            _sprite.setTextureRect({ 49 + 600,18,75,115 });
            //_up = true;
            //temporizador.restart();
            //while (_sprite.getGlobalBounds().top  > _limite-90) {
         //if(_sprite.getGlobalBounds().top > _limite - 90){
            _frame2 += 0.2;
            _velocidad.y = -6.5;
            if (_frame2 > 4.4) {
                _velocidad.y = 3.0;
                _frame2 = 0;
                _colisionando = false;
                spacePresionada = true;
            }
            //_colisionando = false;
            //spacePresionada = true;
            //}

       // if (temporizador.getElapsedTime().asSeconds() >=10.0) {
         //   _velocidad.y = 3.5;
        //}
            if (_b2 == 1) {
                _velocidad = { 0,0 };
            }
        }
        else {
            spacePresionada = false;

        }




        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _congelado == false && _revivido == true || x<-30 && _congelado == false && _revivido == true) {
            //_sprite.move(-_velocidad,0);
            _velocidad.x = -3.5;
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                _sprite.setTextureRect({ 49 + int(_frame) * 150,18,75,115 });
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && _revivido == true|| sf::Joystick::isButtonPressed(0, 0) && _revivido == true)
            {
                _ataque = true;
                _frame += 0.2;
                if (_frame >= 3) {
                    _frame = 0;
                }


                _sprite.setTextureRect({ 1249 + int(_frame) * 150,18,75,115 });

            }
            if (_b2 == 1) {
                _velocidad = { 0,0 };
            }
            else if (_b2 == 0) { _velocidad.x = -3.5; }

            //_up = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _congelado == false && _revivido == true|| x >30 && _congelado == false && _revivido == true) {
            //_sprite.move(_velocidad,0);
            _velocidad.x = 3.5;
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                _sprite.setTextureRect({ 49 + int(_frame) * 150,18,75,115 });
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && _revivido == true || sf::Joystick::isButtonPressed(0, 0) && _revivido == true)
            {
                _ataque = true;
                _frame += 0.2;
                if (_frame >= 3) {
                    _frame = 0;
                }


                _sprite.setTextureRect({ 1249 + int(_frame) * 150,18,75,115 });

            }
            if (_b2 == 1) {
                _velocidad = { 0,0 };
            }
            else if (_b2 == 0) { _velocidad.x = 3.5; }


            //_up = true;
        }
        /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
              //_sprite.move(_velocidad);
              _velocidad.y = 3.5;


          }*/

          //limites de pantalla:
          //_sprite.move(_velocidad);


        _sprite.move(_velocidad);

        if (_velocidad.x < 0) {
            _sprite.setScale(-1, 1);
        }
        else if (_velocidad.x > 0) {
            _sprite.setScale(1, 1);
        }
        //FORMA NUEVA UTILIZANDO LA FUNCION getGlobalBounds():

        if (_sprite.getGlobalBounds().left < -25) {
            _sprite.setPosition(_sprite.getOrigin().x - 10, _sprite.getPosition().y);
        }
        if (_sprite.getGlobalBounds().top < 0) {
            _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
        }
        if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 830) {
            _sprite.setPosition(830 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
        }
        if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) {
            _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
        }

        //FORMA BIEJA DE PONER LIMITES PARA QUE EL OBJETO NO SALGA DE LA VENTANA:

      /* if (_sprite.getPosition().x < 20) {
            _sprite.setPosition(20, _sprite.getPosition().y);
           // _velocidad.x = -_velocidad.x * 1.001;//logica para que rebote un objeto y elevacion de velocidad
        }

        if (_sprite.getPosition().x > 780) {
            _sprite.setPosition(780, _sprite.getPosition().y);
           // _velocidad.x = -_velocidad.x*1.001;//logica para que rebote un objeto
        }

        if (_sprite.getPosition().y < 0) {
            _sprite.setPosition(_sprite.getPosition().x, 0);
            //_velocidad.y = -_velocidad.y*1.001;//logica para que rebote un objeto
        }*/

        //if (_sprite.getPosition().y > 480) {
          //_sprite.setPosition(_sprite.getPosition().x,480);
           // _velocidad.y = -_velocidad.y*1.001;//logica para que rebote un objeto
       // }
        if (_congelado == true) {
            _framecongelado += 0.2;
            if (_framecongelado < 30) {
                _sprite.setTextureRect({ 799 ,18,75,115 });
            }
            else if (_framecongelado >= 10) {
                _congelado = false;
                _framecongelado = 0;
            }
        }

        if (_muerto == true) {



            _sprite.setTextureRect({ 894 + int(_framemuerte) * 150 ,18,137,115 });


            if (_b == 0 && _sprite.getScale().x == -1) {
                _b2 = 1;

                _sprite.setPosition(_sprite.getPosition().x + 100, _sprite.getPosition().y);
                _b = 1;
            }
            else {
                if (_b == 0 && _sprite.getScale().x == 1) {
                    _b2 = 1;

                    _sprite.setPosition(_sprite.getPosition().x - 100, _sprite.getPosition().y);
                    _b = 1;
                }
            }
            if (_muerto == true && _gameover == false) {
                if (_framerespawn > 24) {
                    _revivido = true;
                    _b2 = 0;
                    _sprite.setPosition(400, 540);
                    _frame += 0.2;
                    if (_frame >= 2) {
                        _frame = 0;
                    }
                    _sprite.setTextureRect({ -32 + int(_frame) * 81,18,75,115 });
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Joystick::isButtonPressed(0, 0)|| sf::Joystick::isButtonPressed(0, 1)|| x < -30||x>30) {
                        _muerto = false;
                        _b = 0;
                    }
                }
            }

        }





    }


void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect Personaje::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Personaje::setlimite(int _y)
{
    _limite = _y;
}




void Personaje::limitedesuelo()
{
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > _limite) {
        _sprite.setPosition(_sprite.getPosition().x, _limite);
    }

}

void Personaje::encolision()
{
    _colisionando = true;
}

void Personaje::dejodecolisionar()
{
    _colisionando = false;
}

void Personaje::murio()
{
    _muerto = true;
    _revivido = false;
}
void Personaje::susto() {
    _susto = true;
}

void Personaje::respawn()
{
    _framerespawn = 0;
}

bool Personaje::getmuerto()
{
    return _muerto;
}



bool Personaje::getatacando()
{
    return _ataque;
}

void Personaje::congelado() {
    _framecongelado = 0;
    _congelado = true;

}
bool Personaje::getcongelado() {
    return _congelado;
}
void Personaje::gameover() {
    _gameover = true;
}

const float Personaje::getescale()
{
    return _sprite.getScale().x;
}







