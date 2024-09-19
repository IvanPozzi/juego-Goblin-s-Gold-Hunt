#include "colisionable.h"
#include"personaje.h"
#include<SFML/Graphics.hpp>

bool colisionable::colisiono(colisionable& obj)const {
	return getBounds().intersects(obj.getBounds());
}