#pragma once
#include "BaseMovimiento.h"

class Lider : public BaseMovimiento
{
public:
	Lider(int imagen);
	~Lider();
	 
	void mover(Graphics^ grafico, char direccion);
};

Lider::Lider(int imagen)
{
	eliminate = false;
	idy = idx = 0;
	dx = dy = 10;
	maxC = 9;
	dzoom = 1.5;
	clase = lider;
	switch (imagen)
	{
	case 0: maxC = 9; dzoom = 1.5; break;
	case 1: maxC = 4; dzoom = 1.0; break;
	case 3: maxC = 4; dzoom = 1.1; break;
	case 4: maxC = 4; dzoom = 1.0; break;
	}
}

Lider::~Lider()
{
}

inline void Lider::mover(Graphics^ grafico, char direccion)
{
	switch (direccion)
	{
	case'A':
		if (x > grafico->VisibleClipBounds.Left) 
		{ 
			x -= dx; 
			idx++;
			idy = 1;
		}
		break;
	case'D':
		if (x + dx + width < grafico->VisibleClipBounds.Right) 
		{ 
			idx++;
			x += dx;
			idy = 2;
		}
		break;
	case'W':
		if (y > grafico->VisibleClipBounds.Top) 
		{ 
			y -= dy; 
			idx++;
			idy = 3;
		}
		break;
	case'S':
		if (y + dy + height < grafico->VisibleClipBounds.Bottom) 
		{ 
			y += dy; 
			idx++;
			idy = 0;
		}
	}
	if (idx >= maxC)
		idx = 0;
}
