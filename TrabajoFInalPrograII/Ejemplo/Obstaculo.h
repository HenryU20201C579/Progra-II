#pragma once
#include "BaseMovimiento.h"

class Obstaculo : public BaseMovimiento
{
public:
	Obstaculo();
	~Obstaculo();
	void mover(Graphics^ grafico, char direccion);

};


Obstaculo::Obstaculo()
{
	eliminate = false;
	dx = dy = 0;
	idy = idx = 0;
	maxC = maxR = 1;
	clase = obstaculo;
	dzoom = 0.1;
}

Obstaculo::~Obstaculo()
{
}

inline void Obstaculo::mover(Graphics^ grafico, char direccion)
{
	idx++;
	if (idx >= maxC)
		idx = 0;
	x += dx;
	y += dy;
}