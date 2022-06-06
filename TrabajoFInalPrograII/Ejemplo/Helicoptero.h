#pragma once 
#include "BaseMovimiento.h"


class Helicoptero : public BaseMovimiento
{
public:
	Helicoptero();
	~Helicoptero();
	void mover(Graphics^ grafico, char direccion);
};

Helicoptero::Helicoptero()
{
	dx = 10;
	eliminate = false;
	idx = 0;
	idy = 2;
	maxC = 3;
	dzoom = 1.0;
	clase = helicoptero;
}

Helicoptero::~Helicoptero()
{
}

inline void Helicoptero::mover(Graphics^ grafico, char direccion)
{	
	if (x + dx<0 || x + dx + width>grafico->VisibleClipBounds.Right) eliminate = true;
	x += dx;
	idx++;
	if (idx >= maxC)
		idx = 0;
}
