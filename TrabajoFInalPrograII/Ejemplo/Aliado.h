#pragma once
#include "BaseMovimiento.h"

class Aliado : public BaseMovimiento
{
public:
	Aliado(int numero);
	~Aliado();

	void mover(Graphics^ grafico, char direccion);

};
		
Aliado::Aliado(int numero)
{
	eliminate = false;
	idy = idx = 0;
	maxC = 4;
	if (numero == 1) dzoom = 0.6;
	if (numero == 2) dzoom = 1.0;
	clase = aliado;
}

Aliado::~Aliado()
{
}

inline void Aliado::mover(Graphics^ grafico, char direccion)
{
	idx++;
	if (idx >= maxC)
		idx = 0;
}
