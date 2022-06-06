#pragma once 
#include "BaseMovimiento.h"

class Pocion : public BaseMovimiento
{
public:
	Pocion();
	~Pocion();

};

Pocion::Pocion()
{
	eliminate = false;
	idy = idx = 0;
	dx = dy = 10;
	dzoom = 0.5;
	clase = pocion;
}

Pocion::~Pocion()
{
}

