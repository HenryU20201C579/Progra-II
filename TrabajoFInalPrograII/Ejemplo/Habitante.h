#pragma once
#include "BaseMovimiento.h"

class Habitante : public BaseMovimiento
{
public:
	Habitante(int numero);
	~Habitante();
};

Habitante::Habitante(int numero)
{
	eliminate = false;
	dx = dy = 0;
	idx = 0;
	idy = rand() % 4;
	if (numero == 1)
	{
		maxC = 4;
		dzoom = 1.0;
	}
	if (numero == 2)
	{
		maxC = 3;
		dzoom = 1.5;
	}
	clase = habitante;
}

Habitante::~Habitante()
{
}

