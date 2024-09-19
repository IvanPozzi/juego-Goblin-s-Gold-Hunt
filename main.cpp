#include<SFML/Graphics.hpp>

#include<SFML/Audio.hpp>

#include<stdlib.h>

#include<time.h>

#include<iostream>

#include "blockesladrillosx4.h"

#include"personaje.h"

#include "suelo.h"

#include"enemigo1.h"

#include "blockesladrillox8.h"

#include "blockesolidox2.h"

#include "blockesolidox4.h"

#include "puerta.h"

#include "blockesolidox3.h"

#include "ardillacongelante.h"

#include "buo.h"

#include "vida.h"

#include "gameover.h"

#include"item.h"

#include "senialador.h"

#include <iostream>

#include <fstream>

#include <deque>

#include <fstream>








float frame = 0;
float frameingresarpuntaje = 0;
int puntos = 0;

void menu();
void jugar();
void creditoss();
void ingresepuntaje();
void verscore();

bool musica=true;
void musicamenuapagada();
void musicamenuprendida(); 
bool getmusica();
float frame3=0;

int main()
{
    //verscore();
   // ingresepuntaje();
    menu();


    return 0;
}
void menu() {

    //MUSICA DE MENU:
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Goliath's Foe.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    std::srand((unsigned)std::time(0));

   

   sf::RenderWindow window(sf::VideoMode(800, 600), "ventana1");


    window.setFramerateLimit(60);//fps
    
    
    //SONIDO DE ENTER:
    sf::SoundBuffer bufferenter;
    bufferenter.loadFromFile("dcoin.wav");
    sf::Sound soundenter;
    soundenter.setBuffer(bufferenter);

    //REPRODUCCION ,MUSICA DE MENU:
    sound.setVolume(25);
    senialador puntero;

    sound.play();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        sf::Sprite Fondo;
        sf::Texture textura;
        textura.loadFromFile("fondomenu.png");

        Fondo.setTexture(textura);
        Fondo.setScale(1.25, 1.60);
        sf::Font font;

        font.loadFromFile("SuperMario256.ttf");

        sf::Text text;
        sf::Text textstart;
        sf::Text creditos;
        sf::Text salir;
        sf::Text score;

        text.setFont(font);
        textstart.setFont(font);
        creditos.setFont(font);
        salir.setFont(font);
        score.setFont(font);

        //Titulo:
        text.setString("Goblin's Gold Hunt");
        text.setFillColor(sf::Color::Yellow);
        text.setOutlineColor(sf::Color::Red);
        text.setOutlineThickness(4);
        text.setScale(2, 3);
        text.setPosition(60, 120);

        //Start:
        textstart.setString("start");
        textstart.setFillColor(sf::Color::Yellow);
        textstart.setOutlineColor(sf::Color::Red);
        textstart.setOutlineThickness(4);
        textstart.setScale(1.5, 1.5);
        textstart.setPosition(325, 270);

        //Creditos:

        creditos.setString("creditos");
        creditos.setFillColor(sf::Color::Yellow);
        creditos.setOutlineColor(sf::Color::Red);
        creditos.setOutlineThickness(4);
        creditos.setScale(1.5, 1.5);
        creditos.setPosition(325, 340);

        //Score:

        score.setString("score");
        score.setFillColor(sf::Color::Yellow);
        score.setOutlineColor(sf::Color::Red);
        score.setOutlineThickness(4);
        score.setScale(1.5, 1.5);
        score.setPosition(325,410);



        //Salir:

        salir.setString("salir");
        salir.setFillColor(sf::Color::Yellow);
        salir.setOutlineColor(sf::Color::Red);
        salir.setOutlineThickness(4);
        salir.setScale(1.5, 1.5);
        salir.setPosition(325, 480);


        window.draw(Fondo);


        puntero.update();

        window.draw(puntero);



        window.draw(text);
        window.draw(textstart);
        window.draw(creditos);
        window.draw(score);
        window.draw(salir);

        if (puntero.getcomenzarjuego() == true) {
            
            soundenter.play();
            sound.stop();
            window.close();
            jugar();
            puntero.setcomenzarjuego();
        }

        if (puntero.getcreditos() == true) {
            soundenter.play();
            creditoss();
            puntero.setcreditos();
    
        }
        if (puntero.getscore() == true) {
            soundenter.play();
            verscore();
            puntero.setscore();

        }
        if (puntero.getsalir() == true) {
            soundenter.play();
            window.close();
           
        }

        

        window.display();

    }

}
void jugar() {
    //MUSICA DE JUEGO:
    sf::SoundBuffer buffer;
    buffer.loadFromFile("JUEGO.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    //SONIDO MONEDA:
    sf::SoundBuffer buffercoin;
    buffercoin.loadFromFile("moneda.wav");
    sf::Sound soundcoin;
    soundcoin.setBuffer(buffercoin);

    //SONIDO GAME OVER:
    sf::SoundBuffer buffergameover;
    buffergameover.loadFromFile("gameover.wav");
    sf::Sound soundgameover;
    soundgameover.setBuffer(buffergameover);

    //SONIDO DE ESPADA:
    sf::SoundBuffer bufferespada;
    bufferespada.loadFromFile("espada.wav");
    sf::Sound soundespada;
    soundespada.setBuffer(bufferespada);

    //MUERTE DEL JUGADOR:
    sf::SoundBuffer buffermuerto;
    buffermuerto.loadFromFile("gritodemuerte.wav");
    sf::Sound soundmuerto;
    soundmuerto.setBuffer(buffermuerto);

    
    //VOZ DE ARDILLA:
    sf::SoundBuffer bufferardilla;
    bufferardilla.loadFromFile("ardilla.wav");
    sf::Sound soundardilla;
    soundardilla.setBuffer(bufferardilla);

    //VOZ DE ARDILLA:
    sf::SoundBuffer buffercuervo;
    buffercuervo.loadFromFile("cuervo.wav");
    sf::Sound soundcuervo;
    soundcuervo.setBuffer(buffercuervo);

    //VOLUMEN DE LOS SONIDO:
    sound.setVolume(10);
    soundcoin.setVolume(50);
    soundgameover.setVolume(50);
    soundmuerto.setVolume(50);

    
    
    

    //semilla de tiempo aleatoria:

    std::srand((unsigned)std::time(0));

    //inicializacion de la ventana


    sf::RenderWindow window(sf::VideoMode(800, 600), "ventana2");
    window.setFramerateLimit(60);//fps


   
    sound.play();

    

    sf::Font font;
    font.loadFromFile("bitBold.ttf");

    sf::Text text;
    sf::Text text2;
    text.setFont(font);
    text2.setFont(font);



    puerta puerta_1(70, 90);
    puerta puerta_2(728, 90);
    puerta puerta_3(400, 90);
    blockesolidox3 solidox3_1(55, 315);
    blockesolidox3 solidox3_2(743, 315);


    blockesolidox2 solidox2_3(320, 315);
    blockesolidox2 solidox2_4(481, 315);
    blockesolidox4 solidox4_1(70, 150);
    blockesolidox4 solidox4_2(730, 150);
    blockesolidox4 solidox4_3(400, 150);
    blockesladrillosx8 ladrillosx8_1(397, 400);
    blockesladrillosx4 ladrillosx4_1(195, 230);
    blockesladrillosx4 ladrillosx4_2(80, 468);
    blockesladrillosx4 ladrillosx4_3(720, 468);
    blockesladrillosx4 ladrillosx4_4(604, 230);
    item moneda;
    Personaje jugador;
    suelo piso;
    vida vidas;

    enemigo1 esbirro(95, 90, 1, 1, 2, 3);
    enemigo1 esbirro2(750, 90, 1, 1, -2, 3);
    enemigo1 esbirro3(400, 90, 1, 1, -2, 3);
    ardillacongelante esbirrofrio(750, 90, 1, 1, -4, 6);
    buo buo2(95, 90, 1, 1, 2, 2);
    buo buo(750, 90, 1, 1, -2, 2);

    

    gameover findeljuego;

  


    //FONDO DEL JUEGO:
    sf::Sprite Fondo;
    sf::Texture textura;
    textura.loadFromFile("fondoclaro.png");

    Fondo.setTexture(textura);



    //sf::Sprite personaje;
    //sf::Texture personaje_text;
    //float velocidad = 2.5;

    //personaje_text.loadFromFile("duendecaminando1.png");

    //personaje.setTexture(personaje_text);

    
    //gamrloop(update del juego)
    while (window.isOpen())
    {

        //read imput actualiza los estados de los perifericos de entrada
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                frame = 0;
                window.close();
            }
        }

        //CMD _ ejecucion de comandos(joy)

       /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            personaje.move(0,-velocidad);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            personaje.move(-velocidad,0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            personaje.move(0, velocidad);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            personaje.move(velocidad,0);
        }
        //limites de pantalla:
        if (personaje.getPosition().x < 0) {
            personaje.setPosition( 0,  personaje.getPosition().y);
        }

        if (personaje.getPosition().x > 730) {
            personaje.setPosition(730, personaje.getPosition().y);
        }

        if (personaje.getPosition().y < 0) {
            personaje.setPosition(personaje.getPosition().x, 0);
        }

        if (personaje.getPosition().y > 480) {
            personaje.setPosition(personaje.getPosition().x,480);
        }*/


        //update _ actualiza los estados de los personajes del juego
        
       
         

        //UPDATE DEL JUGADOR:

        jugador.update();

        if (vidas.getvida() <= 5 && vidas.getvida() > 4) {
            soundgameover.play();
        }
        
      
        //UPDATE ENEMIGOS:

        frame += 0.2;
        if (frame > 10) {
            esbirro.update();
            esbirro.nacio();
        }
        if (frame > 150) {
            esbirro2.update();
            esbirro2.nacio();
        }
        if (frame > 400) {
            esbirro3.update();
            esbirro3.nacio();
        }
        if (frame > 1500) {
            esbirrofrio.update();
            esbirrofrio.nacio();
        }
        if (frame > 3000) {
            buo.update();
            buo.nacio();
        }
        if (frame > 4000) {
            buo2.update();
            buo2.nacio();
        }
     


        //COLISIONAMIENTO DE JUGADOR:

        if (jugador.colisiono(piso)) {
            jugador.encolision();
            jugador.setlimite(piso.getBounds().top);
            jugador.limitedesuelo();
        }

        /* if (jugador.colisiono(esbirro)) {
             esbirro.respawn();
         }*/

        if (jugador.colisiono(ladrillosx4_1)) {
            if (jugador.getBounds().top + jugador.getBounds().height > ladrillosx4_1.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(ladrillosx4_1.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(ladrillosx4_2)) {
            if (jugador.getBounds().top + jugador.getBounds().height > ladrillosx4_2.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < ladrillosx4_2.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(ladrillosx4_2.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(ladrillosx4_3)) {
            if (jugador.getBounds().top + jugador.getBounds().height > ladrillosx4_3.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < ladrillosx4_3.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(ladrillosx4_3.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        /*if (jugador.colisiono(solidox2_1)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox2_1.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox2_1.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(solidox2_1.getBounds().top);
                jugador.limitedesuelo();
            }
            else{}
        }

        if (jugador.colisiono(solidox2_2)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox2_2.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox2_2.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(solidox2_2.getBounds().top);
                jugador.limitedesuelo();
            }
            else{}
        }*/

        if (jugador.colisiono(solidox2_3)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox2_3.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox2_3.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(solidox2_3.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(solidox2_4)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox2_4.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox2_4.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(solidox2_4.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(ladrillosx8_1)) {
            if (jugador.getBounds().top + jugador.getBounds().height > ladrillosx8_1.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < ladrillosx8_1.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(ladrillosx8_1.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(solidox3_1)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox3_1.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox3_1.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(solidox3_1.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(solidox3_2)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox3_2.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox3_2.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(solidox3_2.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(ladrillosx4_4)) {
            if (jugador.getBounds().top + jugador.getBounds().height > ladrillosx4_4.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < ladrillosx4_4.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(ladrillosx4_4.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(ladrillosx4_1)) {
            if (jugador.getBounds().top + jugador.getBounds().height > ladrillosx4_1.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(ladrillosx4_1.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }




        if (jugador.colisiono(solidox4_1)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox4_1.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox4_1.getBounds().top + 10) {
                jugador.encolision();
                jugador.setlimite(solidox4_1.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }






        if (jugador.colisiono(solidox4_2)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox4_2.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox4_2.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(solidox4_2.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }

        if (jugador.colisiono(solidox4_3)) {
            if (jugador.getBounds().top + jugador.getBounds().height > solidox4_3.getBounds().top && jugador.getBounds().top + jugador.getBounds().height < solidox4_3.getBounds().top + 10)
            {
                jugador.encolision();
                jugador.setlimite(solidox4_3.getBounds().top);
                jugador.limitedesuelo();
            }
            else {}
        }
        //COLISIONES ENTRE JUGADOR E ITEM:
        if (jugador.colisiono(moneda)) {
            soundcoin.play();
            moneda.respawn();
            puntos += 100;
        }
        if (moneda.colisiono(piso)) {
            moneda.respawn();
        }
        if (moneda.colisiono(ladrillosx4_1)) {
            moneda.respawn();
        }
        if (moneda.colisiono(ladrillosx4_2)) {
            moneda.respawn();
        }
        if (moneda.colisiono(ladrillosx4_3)) {
            moneda.respawn();
        }

        if (moneda.colisiono(solidox2_3)) {
            moneda.respawn();
        }

        if (moneda.colisiono(solidox2_4)) {
            moneda.respawn();
        }

        if (moneda.colisiono(ladrillosx8_1)) {
            moneda.respawn();
        }

        if (moneda.colisiono(solidox3_1)) {
            moneda.respawn();
        }

        if (moneda.colisiono(solidox3_2)) {
            moneda.respawn();
        }

        if (moneda.colisiono(ladrillosx4_4)) {
            moneda.respawn();
        }

        if (moneda.colisiono(ladrillosx4_1)) {
            moneda.respawn();
        }
        if (moneda.colisiono(solidox4_1)) {
            moneda.respawn();
        }
        if (moneda.colisiono(solidox4_2)) {
            moneda.respawn();
        }

        if (moneda.colisiono(solidox4_3)) {
            moneda.respawn();
        }

                    
        //COLISIONES ENTRE EL JUGADOR Y LOS ESBIRROS:
        //COLISION CON ESBIRRO 1:
        if (esbirro.colisiono(jugador)) {
            if (jugador.getatacando() == true) {
                if (esbirro.getsiguemuerto() == false) {
                    soundardilla.play();
                    esbirro.muerto();
                   


                }


            }
            else if (jugador.getmuerto() == false && jugador.getatacando() == false) {
                if (esbirro.getsiguemuerto() == false && esbirro.getnacio() == true) {
                    
                    jugador.murio();
                    soundmuerto.play();
                    vidas.descontadordevida();
                    jugador.respawn();
                    esbirro.cambiodedireccion();
                }

            }
        }
        //COLISION CON ESBIRRO2:
        if (esbirro2.colisiono(jugador)) {
            if (jugador.getatacando() == true) {
                if (esbirro2.getsiguemuerto() == false) {
                    soundardilla.play();
                    esbirro2.muerto();


                }


            }
            else if (jugador.getmuerto() == false && jugador.getatacando() == false) {
                if (esbirro2.getsiguemuerto() == false && esbirro2.getnacio() == true) {
                   
                    jugador.murio();
                    soundmuerto.play();
                    vidas.descontadordevida();
                    jugador.respawn();
                    esbirro2.cambiodedireccion();
                }

            }
        }
        //COLISION CON ESBIRRO3:
        if (esbirro3.colisiono(jugador)) {
            if (jugador.getatacando() == true) {
                if (esbirro3.getsiguemuerto() == false) {
                    soundardilla.play();
                    esbirro3.muerto();


                }


            }
            else if (jugador.getmuerto() == false && jugador.getatacando() == false) {
                if (esbirro3.getsiguemuerto() == false && esbirro3.getnacio() == true) {
                    jugador.murio();
                    soundardilla.play();
                    soundmuerto.play();
                    vidas.descontadordevida();
                    jugador.respawn();
                    esbirro3.cambiodedireccion();
                }

            }
        }
        //COLISION CON ESBIRROFRIO:
        if (jugador.getcongelado() == false) {
            if (esbirrofrio.colisiono(jugador)) {
                if (jugador.getatacando() == true) {
                    if (esbirrofrio.getsiguemuerto() == false) {
                        soundardilla.play();
                        esbirrofrio.muerto();


                    }


                }
                else if (jugador.getmuerto() == false && jugador.getatacando() == false) {
                    if (esbirrofrio.getsiguemuerto() == false && esbirrofrio.getnacio() == true) {
                        
                        jugador.congelado();
                        esbirrofrio.cambiodedireccion();
                    }

                }
            }
        }
        //COLISION CON BUO:
        if (buo.colisiono(jugador)) {
            if (jugador.getatacando() == true) {
                if (buo.getsiguemuerto() == false) {
                    buo.muerto();
                    soundcuervo.play();
                }


            }
            else if (jugador.getmuerto() == false && jugador.getatacando() == false) {
                if (buo.getsiguemuerto() == false && buo.getnacio() == true) {
                    soundcuervo.play();
                    jugador.murio();
                    soundmuerto.play();
                    vidas.descontadordevida();
                    jugador.respawn();
                    buo.cambiodedireccion();
                }

            }
        }
        //COLISION CON BUO2:
        if (buo2.colisiono(jugador)) {
            if (jugador.getatacando() == true) {
                if (buo2.getsiguemuerto() == false) {
                    buo2.muerto();
                    soundcuervo.play();

                }


            }
            else if (jugador.getmuerto() == false && jugador.getatacando() == false) {
                if (buo2.getsiguemuerto() == false && buo2.getnacio() == true) {
                    soundcuervo.play();
                    jugador.murio();
                    soundmuerto.play();
                    vidas.descontadordevida();
                    jugador.respawn();
                    buo2.cambiodedireccion();
                }

            }
        }
        //COLIDIONES ENTRE ESBIRROS:
        if (esbirro.colisiono(esbirro2)) {
            frame3 += 0.2;
            if (frame3 > 6) {
                esbirro.cambiodedireccion();
                esbirro2.cambiodedireccion();
                frame3 = 0;
            }
            
        }

        else if (esbirro.colisiono(esbirro3)) {
            frame3 += 0.2;
            if (frame3 > 6) {
                esbirro.cambiodedireccion();
                esbirro3.cambiodedireccion();
                frame3 = 0;
            }

        }


       else if (esbirro2.colisiono(esbirro3)) {
            frame3 += 0.2;
            if (frame3 > 6) {

                esbirro2.cambiodedireccion();
                esbirro3.cambiodedireccion();
                frame3 = 0;
            }
        }
       
      
        
       if (esbirrofrio.colisiono(esbirro)) {
            frame3 += 0.2;
            if (frame3 > 6) {
                
                esbirrofrio.cambiodedireccion();
                frame3 = 0;
            }
        }
        if (esbirrofrio.colisiono(esbirro2)) {
            frame3 += 0.2;
            if (frame3 >6 ) {
               
                esbirrofrio.cambiodedireccion();
                frame3 = 0;
            }
        }
        if (esbirrofrio.colisiono(esbirro3)) {
            frame3 += 0.2;
            if (frame3 > 6) {
               
                esbirrofrio.cambiodedireccion();
                frame3 = 0;
            }
        }


        //COLISIONAMIENTO DEL ESBIRRO1:

        if (esbirro.colisiono(piso)) {

            esbirro.encolision();
            esbirro.setlimite(piso.getBounds().top);
            esbirro.limitedesuelo();

        }
        else {
            esbirro.dejodecolisionar();
        }

        /* if (jugador.colisiono(moneda)) {
             moneda.respawn();
         }*/

        if (esbirro.colisiono(ladrillosx4_1)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > ladrillosx4_1.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(ladrillosx4_1.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }


        if (esbirro.colisiono(ladrillosx4_2)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > ladrillosx4_2.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < ladrillosx4_2.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(ladrillosx4_2.getBounds().top);
                esbirro.limitedesuelo();
            }
            else {}
        }


        if (esbirro.colisiono(ladrillosx4_3)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > ladrillosx4_3.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < ladrillosx4_3.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(ladrillosx4_3.getBounds().top);
                esbirro.limitedesuelo();
            }
            else {}
        }




        if (esbirro.colisiono(solidox2_3)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > solidox2_3.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < solidox2_3.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(solidox2_3.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }


        if (esbirro.colisiono(solidox2_4)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > solidox2_4.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < solidox2_4.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(solidox2_4.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }


        if (esbirro.colisiono(ladrillosx8_1)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > ladrillosx8_1.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < ladrillosx8_1.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(ladrillosx8_1.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }


        if (esbirro.colisiono(solidox3_1)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > solidox3_1.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < solidox3_1.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(solidox3_1.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }


        if (esbirro.colisiono(solidox3_2)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > solidox3_2.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < solidox3_2.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(solidox3_2.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }


        if (esbirro.colisiono(ladrillosx4_4)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > ladrillosx4_4.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < ladrillosx4_4.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(ladrillosx4_4.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }


        if (esbirro.colisiono(ladrillosx4_1)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > ladrillosx4_1.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(ladrillosx4_1.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }





        if (esbirro.colisiono(solidox4_1)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > solidox4_1.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < solidox4_1.getBounds().top + 10) {
                esbirro.encolision();
                esbirro.setlimite(solidox4_1.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }







        if (esbirro.colisiono(solidox4_2)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > solidox4_2.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < solidox4_2.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(solidox4_2.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }


        if (esbirro.colisiono(solidox4_3)) {
            if (esbirro.getBounds().top + esbirro.getBounds().height > solidox4_3.getBounds().top && esbirro.getBounds().top + esbirro.getBounds().height < solidox4_3.getBounds().top + 10)
            {
                esbirro.encolision();
                esbirro.setlimite(solidox4_3.getBounds().top);
                esbirro.limitedesuelo();
            }
            else { esbirro.dejodecolisionar(); }
        }

        //COLISIONES DEL ESBIRRO2:

        if (esbirro2.colisiono(piso)) {

            esbirro2.encolision();
            esbirro2.setlimite(piso.getBounds().top);
            esbirro2.limitedesuelo();

        }
        else {
            esbirro2.dejodecolisionar();
        }

        /* if (jugador.colisiono(esbirro)) {
             esbirro.respawn();
         }*/

        if (esbirro2.colisiono(ladrillosx4_1)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > ladrillosx4_1.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(ladrillosx4_1.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }


        if (esbirro2.colisiono(ladrillosx4_2)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > ladrillosx4_2.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < ladrillosx4_2.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(ladrillosx4_2.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else {}
        }


        if (esbirro2.colisiono(ladrillosx4_3)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > ladrillosx4_3.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < ladrillosx4_3.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(ladrillosx4_3.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else {}
        }




        if (esbirro2.colisiono(solidox2_3)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > solidox2_3.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < solidox2_3.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(solidox2_3.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }


        if (esbirro2.colisiono(solidox2_4)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > solidox2_4.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < solidox2_4.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(solidox2_4.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }


        if (esbirro2.colisiono(ladrillosx8_1)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > ladrillosx8_1.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < ladrillosx8_1.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(ladrillosx8_1.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }


        if (esbirro2.colisiono(solidox3_1)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > solidox3_1.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < solidox3_1.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(solidox3_1.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }


        if (esbirro2.colisiono(solidox3_2)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > solidox3_2.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < solidox3_2.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(solidox3_2.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }


        if (esbirro2.colisiono(ladrillosx4_4)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > ladrillosx4_4.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < ladrillosx4_4.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(ladrillosx4_4.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }


        if (esbirro2.colisiono(ladrillosx4_1)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > ladrillosx4_1.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(ladrillosx4_1.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }





        if (esbirro2.colisiono(solidox4_1)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > solidox4_1.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < solidox4_1.getBounds().top + 10) {
                esbirro2.encolision();
                esbirro2.setlimite(solidox4_1.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }







        if (esbirro2.colisiono(solidox4_2)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > solidox4_2.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < solidox4_2.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(solidox4_2.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }


        if (esbirro2.colisiono(solidox4_3)) {
            if (esbirro2.getBounds().top + esbirro2.getBounds().height > solidox4_3.getBounds().top && esbirro2.getBounds().top + esbirro2.getBounds().height < solidox4_3.getBounds().top + 10)
            {
                esbirro2.encolision();
                esbirro2.setlimite(solidox4_3.getBounds().top);
                esbirro2.limitedesuelo();
            }
            else { esbirro2.dejodecolisionar(); }
        }
        //COLISIONAMIENTO DEL ESBIRRO3:

        if (esbirro3.colisiono(piso)) {

            esbirro3.encolision();
            esbirro3.setlimite(piso.getBounds().top);
            esbirro3.limitedesuelo();

        }
        else {
            esbirro3.dejodecolisionar();
        }

        /* if (jugador.colisiono(esbirro)) {
             esbirro.respawn();
         }*/

        if (esbirro3.colisiono(ladrillosx4_1)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > ladrillosx4_1.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(ladrillosx4_1.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }


        if (esbirro3.colisiono(ladrillosx4_2)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > ladrillosx4_2.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < ladrillosx4_2.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(ladrillosx4_2.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else {}
        }


        if (esbirro3.colisiono(ladrillosx4_3)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > ladrillosx4_3.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < ladrillosx4_3.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(ladrillosx4_3.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else {}
        }




        if (esbirro3.colisiono(solidox2_3)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > solidox2_3.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < solidox2_3.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(solidox2_3.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }


        if (esbirro3.colisiono(solidox2_4)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > solidox2_4.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < solidox2_4.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(solidox2_4.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }


        if (esbirro3.colisiono(ladrillosx8_1)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > ladrillosx8_1.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < ladrillosx8_1.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(ladrillosx8_1.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }


        if (esbirro3.colisiono(solidox3_1)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > solidox3_1.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < solidox3_1.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(solidox3_1.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }


        if (esbirro3.colisiono(solidox3_2)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > solidox3_2.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < solidox3_2.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(solidox3_2.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }


        if (esbirro3.colisiono(ladrillosx4_4)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > ladrillosx4_4.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < ladrillosx4_4.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(ladrillosx4_4.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }


        if (esbirro3.colisiono(ladrillosx4_1)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > ladrillosx4_1.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(ladrillosx4_1.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }





        if (esbirro3.colisiono(solidox4_1)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > solidox4_1.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < solidox4_1.getBounds().top + 10) {
                esbirro3.encolision();
                esbirro3.setlimite(solidox4_1.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }







        if (esbirro3.colisiono(solidox4_2)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > solidox4_2.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < solidox4_2.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(solidox4_2.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }


        if (esbirro3.colisiono(solidox4_3)) {
            if (esbirro3.getBounds().top + esbirro3.getBounds().height > solidox4_3.getBounds().top && esbirro3.getBounds().top + esbirro3.getBounds().height < solidox4_3.getBounds().top + 10)
            {
                esbirro3.encolision();
                esbirro3.setlimite(solidox4_3.getBounds().top);
                esbirro3.limitedesuelo();
            }
            else { esbirro3.dejodecolisionar(); }
        }
        //COLISIONAMIENTO DEL ESBIRROFRIO:

        if (esbirrofrio.colisiono(piso)) {

            esbirrofrio.encolision();
            esbirrofrio.setlimite(piso.getBounds().top);
            esbirrofrio.limitedesuelo();

        }
        else {
            esbirrofrio.dejodecolisionar();
        }

        /* if (jugador.colisiono(esbirro)) {
             esbirro.respawn();
         }*/

        if (esbirrofrio.colisiono(ladrillosx4_1)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > ladrillosx4_1.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(ladrillosx4_1.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }


        if (esbirrofrio.colisiono(ladrillosx4_2)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > ladrillosx4_2.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < ladrillosx4_2.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(ladrillosx4_2.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else {}
        }


        if (esbirrofrio.colisiono(ladrillosx4_3)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > ladrillosx4_3.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < ladrillosx4_3.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(ladrillosx4_3.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else {}
        }




        if (esbirrofrio.colisiono(solidox2_3)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > solidox2_3.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < solidox2_3.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(solidox2_3.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }


        if (esbirrofrio.colisiono(solidox2_4)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > solidox2_4.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < solidox2_4.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(solidox2_4.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }


        if (esbirrofrio.colisiono(ladrillosx8_1)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > ladrillosx8_1.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < ladrillosx8_1.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(ladrillosx8_1.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }


        if (esbirrofrio.colisiono(solidox3_1)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > solidox3_1.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < solidox3_1.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(solidox3_1.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }


        if (esbirrofrio.colisiono(solidox3_2)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > solidox3_2.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < solidox3_2.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(solidox3_2.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }


        if (esbirrofrio.colisiono(ladrillosx4_4)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > ladrillosx4_4.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < ladrillosx4_4.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(ladrillosx4_4.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }


        if (esbirrofrio.colisiono(ladrillosx4_1)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > ladrillosx4_1.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < ladrillosx4_1.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(ladrillosx4_1.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }





        if (esbirrofrio.colisiono(solidox4_1)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > solidox4_1.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < solidox4_1.getBounds().top + 10) {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(solidox4_1.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }







        if (esbirrofrio.colisiono(solidox4_2)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > solidox4_2.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < solidox4_2.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(solidox4_2.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }


        if (esbirrofrio.colisiono(solidox4_3)) {
            if (esbirrofrio.getBounds().top + esbirrofrio.getBounds().height > solidox4_3.getBounds().top && esbirrofrio.getBounds().top + esbirrofrio.getBounds().height < solidox4_3.getBounds().top + 10)
            {
                esbirrofrio.encolision();
                esbirrofrio.setlimite(solidox4_3.getBounds().top);
                esbirrofrio.limitedesuelo();
            }
            else { esbirrofrio.dejodecolisionar(); }
        }



        window.clear();

        //Draw _ dibuja los graficos en pantalla
        moneda.update();

        piso.update();

        ladrillosx4_1.update();

        ladrillosx4_2.update();

        ladrillosx4_3.update();

        ladrillosx4_4.update();

        ladrillosx8_1.update();

        // solidox2_1.update();

         //solidox2_2.update();

        solidox2_3.update();

        solidox2_4.update();

        solidox4_1.update();

        solidox4_2.update();

        puerta_1.update();

        puerta_2.update();

        puerta_3.update();

        solidox3_1.update();

        solidox3_2.update();

        solidox4_3.update();

        vidas.update();


        text2.setString("P1:");
        text2.setPosition(10, 0);
        text.setPosition(60, 0);
        text.setString(std::to_string(puntos));

        //window.draw(ladrillosx4);


        window.draw(Fondo);


        // window.draw(menu);

        window.draw(puerta_1);

        window.draw(puerta_2);

        window.draw(puerta_3);

        //window.draw(solidox2_1);

        //window.draw(solidox2_2);

        window.draw(solidox2_3);

        window.draw(solidox2_4);

        window.draw(ladrillosx4_1);

        window.draw(ladrillosx4_2);

        window.draw(ladrillosx4_3);

        window.draw(ladrillosx4_4);

        //window.draw(solidox2_1);

        window.draw(ladrillosx8_1);

        window.draw(piso);


        window.draw(solidox4_1);

        window.draw(solidox4_2);

        window.draw(solidox3_1);

        window.draw(solidox3_2);

        window.draw(solidox4_3);

        window.draw(moneda);

       

        window.draw(vidas);

        window.draw(text);

        window.draw(text2);


        /*frame += 0.2;
        if (frame > 10) {

            esbirro.update();
            esbirro.nacio();
        }
        if (frame > 150) {
            esbirro2.update();
            esbirro2.nacio();
        }
        if (frame > 400) {
            esbirro3.update();
            esbirro3.nacio();
        }
        if (frame > 1500) {
            esbirrofrio.update();
            esbirrofrio.nacio();
        }
        if (frame > 3000) {
            buo.update();
            buo.nacio();
        }
        if (frame > 6000) {
            buo2.update();
            buo2.nacio();
        }*/
        frame += 0.2;
        if (frame > 11) {
            window.draw(esbirro);
            
        }
        if (frame > 151) {
            window.draw(esbirro2);
            
        }
        if (frame > 401) {
            window.draw(esbirro3);
            
        }
        if (frame > 1501) {
            window.draw(esbirrofrio);
            
        }
        if (frame > 3001) {
            window.draw(buo);
        }
        if (frame > 4001) {
            window.draw(buo2);
        }
        window.draw(jugador);
        
        findeljuego.update();
        if (vidas.getvida() >= 6) {
            
            window.draw(findeljuego);
            jugador.gameover();
            frameingresarpuntaje+=0.2;
            if (frameingresarpuntaje > 50) {
                sound.stop();
                window.close();
                ingresepuntaje();
            }
            
           
            

        }
        //REPRODUCCION DE SONIDO DE ATAQUE:
        

        if (jugador.getatacando() == true) {
            soundespada.play();
        }
     






        //Display _ flip
      

        window.display();


    }
}


void creditoss() {
    std::srand((unsigned)std::time(0));

    sf::RenderWindow window(sf::VideoMode(800, 600), "ventana3");


    window.setFramerateLimit(60);//fps

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.text.unicode == 27) {
            window.close();
        }
        sf::Sprite Fondo;
        sf::Texture textura;
        textura.loadFromFile("fondocreditos.png");

        Fondo.setTexture(textura);

        Fondo.setScale(1.10, 1.10);

        window.draw(Fondo);

       

        window.display();
    }
}


void ingresepuntaje() {
    std::string enteredText;
    std::srand((unsigned)std::time(0));

    sf::RenderWindow window(sf::VideoMode(800, 600), "ventana3");

    sf::Event event;
    window.setFramerateLimit(60); // fps

    sf::Font font;
    font.loadFromFile("SuperMario256.ttf");

    sf::Text textscore;
    textscore.setFont(font);
    textscore.setString("score :");
    textscore.setFillColor(sf::Color::Green);
    textscore.setOutlineColor(sf::Color::Magenta);
    textscore.setOutlineThickness(2);
    textscore.setScale(2, 2);
    textscore.setPosition(70, 200);

    sf::Text textpuntos;
    textpuntos.setFont(font);
    textpuntos.setString(std::to_string(puntos));
    textpuntos.setFillColor(sf::Color::Green);
    textpuntos.setOutlineColor(sf::Color::Magenta);
    textpuntos.setOutlineThickness(2);
    textpuntos.setScale(2, 2);
    textpuntos.setPosition(340, 200);

    sf::Text textnombre;
    textnombre.setFont(font);
    textnombre.setString("enter your names");
    textnombre.setFillColor(sf::Color::Green);
    textnombre.setOutlineColor(sf::Color::Magenta);
    textnombre.setOutlineThickness(2);
    textnombre.setScale(2, 2);
    textnombre.setPosition(70, 120);

    sf::Text alias;
    alias.setFont(font);
    alias.setCharacterSize(24);
    alias.setFillColor(sf::Color::Green);
    alias.setOutlineColor(sf::Color::Magenta);
    alias.setOutlineThickness(2);
    alias.setScale(2, 2);
    alias.setPosition(70, 400);

    std::ofstream outputFile("score.dat", std::ios::app);  //abrir archivo

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                menu();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8 && !enteredText.empty()) {
                    enteredText.pop_back();
                }
                else if (event.text.unicode == 13) { //CON CODIGO ASKI USO ENTER PARA CERRAR
                    // Guardar datos
                    outputFile << "Puntos: " << puntos << "\n";
                    outputFile << "Alias: " << enteredText << "\n";
                    window.close();
                    menu(); 
                }
                else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    enteredText += static_cast<char>(event.text.unicode);
                }
            }

            window.clear(sf::Color::Black);

            window.draw(textscore);
            window.draw(textpuntos);
            window.draw(textnombre);

            alias.setString(enteredText);
            window.draw(alias);

            window.display();
        }
    }

    outputFile.close();  //CIERRO ARCHIVO DESPUES DE BUCLE
}

/*void verscore() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "VERARCHIVO");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("SuperMario256.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    std::ifstream inputFile("datos.txt");
    std::string line, content;

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            content += line + "\n";
        }
        inputFile.close();
    }

    text.setString(content);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
}*/

void verscore() {
    sf::RenderWindow window(sf::VideoMode(800, 600), " SCORE");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("SuperMario256.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Yellow);
    text.setOutlineColor(sf::Color::Red);
    text.setOutlineThickness(1);
    text.setPosition(10, 10);

    std::ifstream inputFile("score.dat");
    std::deque<std::string> registros;
    std::string line, content;

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            registros.push_front(line);
            if (registros.size() > 10) {
                registros.pop_back();
            }
        }
        inputFile.close();
    }

    for (const auto& registro : registros) {
        content += registro + "\n";
    }

    text.setString(content);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (event.text.unicode == 27) {
            window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
}
void musicamenuapagada() {
    musica = false;
}
void musicamenuprendida() {
    musica = true;
}
bool getmusica() {
    return musica;
}