#pragma once
#include "BaseMovimiento.h"

class Agente : public BaseMovimiento
{
public:
	Agente();
	~Agente();

	void mover(Graphics^ grafico, char direccion);

};	


Agente::Agente()
{
	eliminate = false;
	idy = idx = 0;
	maxC = 4;
	dzoom = 1.0;
	clase = agente;
}

Agente::~Agente()
{
}

inline void Agente::mover(Graphics^ grafico, char direccion)
{
	idx++;
	if (idx >= maxC)
		idx = 0;
}
