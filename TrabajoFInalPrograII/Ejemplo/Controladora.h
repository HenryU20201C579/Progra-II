#pragma once
#include "ArrBaseMovimiento.h"
#include "Lider.h"
#include "Aliado.h"
#include "Agente.h"
#include "Habitante.h"
#include "Obstaculo.h"
#include "Pocion.h"
#include "Helicoptero.h"
#include "WokiToki.h"
#include <math.h>
#include <ctime>
using namespace std;

class Controladora
{
public:
	Controladora(Graphics^ grafico, Bitmap^ imagenLider, Bitmap^ imagenAliado,
				 Bitmap^ imagenAgente, Bitmap^ imagenHabitante, Bitmap^ imagenObstaculo, Bitmap^ imagenWokiToki,
				 int imagen, int CantHabitantes, int CantAgentes, int CantAliados, int CantTiempo, int nivel);
	~Controladora();

	void run(Graphics^ grafico, Bitmap^ imagenLider, Bitmap^ imagenAliado, 
		Bitmap^ imagenAgente, Bitmap^ imagenHabitante, Bitmap^ imagenObstaculo, 
		Bitmap^ imagenPocion, Bitmap^ imagenHelicoptero, Bitmap^ imagenWokiToki);
	void moverLider(Graphics^ grafico, char direccion, Bitmap^ imagenLider, Bitmap^ imagenAliado, 
				Bitmap^ imagenHabitante, Bitmap^ imagenPocion, Bitmap^ imagenHelicoptero);
	void generaAliado(Graphics^ grafico, Bitmap^ imagenAliado, int nivel);
	void generaAgente(Graphics^ grafico, Bitmap^ imagenAgente);
	void generaHabitante(Graphics^ grafico, Bitmap^ imagenHabitante, int nivel);
	void generaObstaculo(Graphics^ grafico, Bitmap^ imagenObstaculo);
	void generaHelicoptero(Graphics^ grafico, Bitmap^ imagenHelicoptero);
	void generaPocion(Graphics^ grafico, Bitmap^ imagenPocion);
	void generaWokiToki(Graphics^ grafico, Bitmap^ imagenWokiToki);
	bool colision(BaseMovimiento* uno, BaseMovimiento* dos);
	bool colision2(BaseMovimiento* uno, BaseMovimiento* dos);
	bool encuentraObstaculo(BaseMovimiento* uno, BaseMovimiento* dos);
	void rodeaObstaculo(BaseMovimiento* uno, BaseMovimiento* dos);
	void persecucion(BaseMovimiento* uno, BaseMovimiento* dos);
	void persecucion2(BaseMovimiento* uno, int x, int y);
	float formulaDistancia(int x1, int x2, int y1, int y2);
	float encuentraDistancia(BaseMovimiento* uno, BaseMovimiento* dos);
	void rompeRocas();
	void convierteAgentes(BaseMovimiento* uno, Bitmap^ imagenAliado);
	bool getGanar();
	bool getPerder();
	int getCantAliados();
	int getPuntaje();

private:
	ArrBaseMovimiento* objetos;
	Lider* lider;
	int destinox, destinoy;
	int distancia, indice;
	int auxX1, auxX2, auxY1, auxY2;
	bool ganar, perder;
	int puntaje, cantAliados, tiempo, cantHabitantes, cantAgentes, nivel, contPoder;
	time_t inicio;
};

Controladora::Controladora(Graphics^ grafico, Bitmap^ imagenLider, Bitmap^ imagenAliado, 
						   Bitmap^ imagenAgente, Bitmap^ imagenHabitante, Bitmap^ imagenObstaculo, Bitmap^ imagenWokiToki,
						   int imagen, int CantHabitantes, int CantAgentes, int CantAliados, int CantTiempo, int nivel)
{
	contPoder = 0;
	this->cantHabitantes = 0;
	objetos = new ArrBaseMovimiento();
	lider = new Lider(imagen);
	lider->setX(grafico->VisibleClipBounds.Right / 2);
	lider->setY(10);
	lider->setWidth(imagenLider->Width / lider->getMaxColumn());
	lider->setHeight(imagenLider->Height / 4);
	for (int i = 0; i < CantAgentes; i++)
		generaAgente(grafico, imagenAgente);
	for (int i = 0; i < CantHabitantes; i++)
		generaHabitante(grafico, imagenHabitante, nivel);
	for (int i = 0; i < rand()% 5 + 1; i++)
		generaObstaculo(grafico, imagenObstaculo);
	if(nivel == 1)
		for (int i = 0; i < rand() % 3 + 1; i++)
			generaWokiToki(grafico, imagenWokiToki);


	puntaje = 0;
	ganar = perder = false;
	this->cantAliados = CantAliados;
	this->nivel = nivel;
	tiempo = CantTiempo;
	inicio = time(0);
}

Controladora::~Controladora()
{
}

inline void Controladora::run(Graphics^ grafico, Bitmap^ imagenLider, Bitmap^ imagenAliado, 
						Bitmap^ imagenAgente, Bitmap^ imagenHabitante, Bitmap^ imagenObstaculo, 
						Bitmap^ imagenPocion, Bitmap^ imagenHelicoptero, Bitmap^ imagenWokiToki)
{
	time_t actual = time(0);
	if (difftime(actual, inicio) > tiempo)perder = true;

	cantHabitantes = cantAgentes = 0;
	for (int i = 0; i < objetos->size(); i++)
	{
		if (objetos->at(i)->getClase() == habitante)
			cantHabitantes++;	
		if (objetos->at(i)->getClase() == agente)
			cantAgentes++;
	}
	if (cantAgentes == 0)
	{
		for (int i = 0; i < objetos->size(); i++)
			if (objetos->at(i)->getClase() == pocion)
				objetos->at(i)->setEliminate(true);
	}

	if (cantHabitantes == 0)
		ganar = true;

	if(puntaje >= 100)
		ganar = true;

	//ordenamos cada subarreglo por clase
	for (int i = 0; i < 5; i++)
	{
		indice = 1;
		for (int j = 0; j < objetos->size(); j++)
		{
			if (objetos->at(j)->getClase() == i)
			{
				objetos->at(j)->setIndice(indice);
				indice++;
			}
			
		}
	}
	for (int j = 0; j < objetos->size(); j++)
	{
		if (colision(objetos->at(j), lider) && objetos->at(j)->getClase() == wokitoki)
		{
			objetos->at(j)->setEliminate(true);
			contPoder++;
		}
	}
	for (int i = 0; i < objetos->size(); i++)
	{
		for (int j = 0; j < objetos->size(); j++)
		{
			if (objetos->at(i)->getClase() == aliado && objetos->at(j)->getClase() == habitante)
			{
				if (objetos->at(j)->getIndice() == 1)
					objetos->at(i)->setDistancia(encuentraDistancia(objetos->at(i), objetos->at(j)));
				else
					if (encuentraDistancia(objetos->at(i), objetos->at(j)) < objetos->at(i)->getDistancia())
						objetos->at(i)->setDistancia(encuentraDistancia(objetos->at(i), objetos->at(j)));
			}
			if (objetos->at(i)->getClase() == pocion && objetos->at(j)->getClase() == agente)
			{
				if (objetos->at(j)->getIndice() == 1)
					objetos->at(i)->setDistancia(encuentraDistancia(objetos->at(i), objetos->at(j)));
				else
					if (encuentraDistancia(objetos->at(i), objetos->at(j)) < objetos->at(i)->getDistancia())
						objetos->at(i)->setDistancia(encuentraDistancia(objetos->at(i), objetos->at(j)));
			}

			if (objetos->at(i)->getClase() == agente && objetos->at(j)->getClase() == aliado)
			{
				if (objetos->at(j)->getIndice() == 1)
					objetos->at(i)->setDistancia(encuentraDistancia(objetos->at(i), objetos->at(j)));
				else
					if (encuentraDistancia(objetos->at(i), objetos->at(j)) < objetos->at(i)->getDistancia())
						objetos->at(i)->setDistancia(encuentraDistancia(objetos->at(i), objetos->at(j)));
			}
			
		}
	}
	//EMPEZAR LA PERSECUCION
	for (int i = 0; i < objetos->size(); i++)
		for (int j = 0; j < objetos->size(); j++)
		{
			if (objetos->at(i)->getClase() == helicoptero && objetos->at(j)->getClase() == agente
				&& colision(objetos->at(i), objetos->at(j)))
			{
				objetos->at(j)->setEliminate(true);
			}

			//ALIADO AL HABITANTE MAS CERCANO
			if (objetos->at(i)->getClase() == aliado && objetos->at(j)->getClase() == habitante &&
				encuentraDistancia(objetos->at(i), objetos->at(j)) == objetos->at(i)->getDistancia())
			{
				if (colision(objetos->at(i), objetos->at(j)))
				{
					puntaje += 10;
				}
				if (!encuentraObstaculo(objetos->at(i), objetos->at(j))) //SI NO ENCUENTRAS OBSTACULOS, PERSEGUIR DE FORMA NORMAL
					persecucion(objetos->at(i), objetos->at(j));
			}
			//AGENTE AL ALIADO MAS CERCANO
			if (objetos->at(i)->getClase() == agente && objetos->at(j)->getClase() == aliado &&
				encuentraDistancia(objetos->at(i), objetos->at(j)) == objetos->at(i)->getDistancia())
			{
				if (colision(objetos->at(i), objetos->at(j)))
				{
					if (puntaje - 5 > 0)
						puntaje -= 5;
				}
				if (!encuentraObstaculo(objetos->at(i), objetos->at(j))) //SI NO ENCUENTRAS OBSTACULOS, PERSEGUIR DE FORMA NORMAL
					persecucion(objetos->at(i), objetos->at(j));
			}
			//POCION AL AGENTE
			if (objetos->at(i)->getClase() == pocion && objetos->at(j)->getClase() == agente &&
				encuentraDistancia(objetos->at(i), objetos->at(j)) == objetos->at(i)->getDistancia())
			{
				if (colision(objetos->at(i), objetos->at(j)))
				{
					objetos->at(i)->setEliminate(true);
					convierteAgentes(objetos->at(j), imagenAliado);
				}
				else 
					persecucion(objetos->at(i), objetos->at(j));
			}
			
		}
	for (int i = 0; i < objetos->size(); i++)
	{
		if (objetos->at(i)->getClase() == agente && colision(objetos->at(i), lider))
		{
			objetos->at(i)->setX(objetos->at(i)->getX() + lider->getDx());
			objetos->at(i)->setY(objetos->at(i)->getY() + lider->getDy());
			break;
			break;
		}
	}

	objetos->erase();

	objetos->moverTodos(grafico, ' ');
	objetos->mostrarTodos(grafico, imagenLider, imagenAliado, imagenAgente, imagenHabitante, imagenObstaculo, imagenPocion, imagenHelicoptero, imagenWokiToki);
	lider->mover(grafico, ' ');
	lider->mostrar(grafico, imagenLider);
}

inline void Controladora::moverLider(Graphics^ grafico, char direccion, Bitmap^ imagenLider, Bitmap^ imagenAliado, 
	Bitmap^ imagenHabitante, Bitmap^ imagenPocion, Bitmap^ imagenHelicoptero)
{
	switch (direccion)
	{
	case 'A':
		lider->mover(grafico, 'A'); break;
	case 'S':
		lider->mover(grafico, 'S'); break;
	case 'D':
		lider->mover(grafico, 'D'); break;
	case 'W':
		lider->mover(grafico, 'W'); break;
	case 'J':
		if (cantAliados > 0)
		{
			cantAliados--;
			generaAliado(grafico, imagenAliado, nivel); break;
		}
	case 'Q':
		rompeRocas(); break;
	case 'E':
		generaPocion(grafico, imagenPocion); break;
	case 'R':
		if (contPoder > 0)
		{
			contPoder--;
			generaHelicoptero(grafico, imagenHelicoptero);
		}
		break;
	}
}

inline void Controladora::generaAliado(Graphics^ grafico, Bitmap^ imagenAliado, int nivel)
{
	Aliado* nuevo = new Aliado(nivel);
	nuevo->setHeight(imagenAliado->Height / 4.0);
	nuevo->setWidth((imagenAliado->Width / 4.0));
	nuevo->setX(lider->getX());
	nuevo->setY(lider->getY());
	objetos->pushback(nuevo);
}

inline void Controladora::generaAgente(Graphics^ grafico, Bitmap^ imagenAgente)
{
	Agente* nuevo = new Agente();
	nuevo->setHeight(imagenAgente->Height / 4.0);
	nuevo->setWidth(imagenAgente->Height / 4.0);
	nuevo->setX(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Right - nuevo->getWidth()) - 1);
	nuevo->setY(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Bottom - nuevo->getHeight()) - 1);
	for (int i = 0; i < objetos->size(); i++)
	{
		while (colision(objetos->at(i), nuevo))
		{
			nuevo->setX(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Right - nuevo->getWidth()) - 1);
			nuevo->setY(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Bottom - nuevo->getHeight()) - 1);
		}
	}
	objetos->pushback(nuevo);
}

inline void Controladora::generaHabitante(Graphics^ grafico, Bitmap^ imagenHabitante, int nivel)
{
	Habitante* nuevo = new Habitante(nivel);
	nuevo->setHeight(imagenHabitante->Height / 4.0);
	nuevo->setWidth(imagenHabitante->Width / nuevo->getMaxColumn());
	nuevo->setX(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Right - nuevo->getWidth()) - 1);
	nuevo->setY(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Bottom - nuevo->getHeight()) - 1);
	for (int i = 0; i < objetos->size(); i++)
	{
		while (colision(objetos->at(i), nuevo))
		{
			nuevo->setX(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Right - nuevo->getWidth()) - 1);
			nuevo->setY(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Bottom - nuevo->getHeight()) - 1);
		}
	}
	objetos->pushback(nuevo);
}

inline void Controladora::generaObstaculo(Graphics^ grafico, Bitmap^ imagenObstaculo)
{
	Obstaculo* nuevo = new Obstaculo();
	nuevo->setHeight(imagenObstaculo->Height);
	nuevo->setWidth(imagenObstaculo->Width);
	nuevo->setX(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Right - nuevo->getWidth()) - 1);
	nuevo->setY(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Bottom - nuevo->getHeight()) - 1);
	for (int i = 0; i < objetos->size(); i++)
	{
		while (colision(objetos->at(i), nuevo))
		{
			nuevo->setX(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Right - nuevo->getWidth()) - 1);
			nuevo->setY(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Bottom - nuevo->getHeight()) - 1);
		}
	}
	objetos->pushback(nuevo);
}

inline void Controladora::generaHelicoptero(Graphics^ grafico, Bitmap^ imagenHelicoptero)
{
	Random r;
	Helicoptero* nuevo = new Helicoptero(); 
	nuevo->setHeight(imagenHelicoptero->Height / 4.0);
	nuevo->setWidth((imagenHelicoptero->Width / 3.0));
	nuevo->setX(0);
	nuevo->setY(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Bottom - nuevo->getHeight()) - 1);
	objetos->pushback(nuevo);
}

inline void Controladora::generaPocion(Graphics^ grafico, Bitmap^ imagenPocion)
{
	Pocion* nuevo = new Pocion();
	nuevo->setHeight(imagenPocion->Height / 1.0);
	nuevo->setWidth(imagenPocion->Width / 1.0);
	nuevo->setX(lider->getX());
	nuevo->setY(lider->getY());
	objetos->pushback(nuevo);
}

inline void Controladora::generaWokiToki(Graphics^ grafico, Bitmap^ imagenWokiToki)
{
	WokiToki* nuevo = new WokiToki();
	nuevo->setHeight(imagenWokiToki->Height);
	nuevo->setWidth(imagenWokiToki->Width);
	nuevo->setX(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Right - nuevo->getWidth()) - 1);
	nuevo->setY(rand() % Convert::ToInt32(grafico->VisibleClipBounds.Bottom - nuevo->getHeight()) - 1);
	objetos->pushback(nuevo);
}

inline bool Controladora::colision(BaseMovimiento* uno, BaseMovimiento* dos)
{
	Rectangle rectangulo;
	rectangulo.X = uno->getX();
	rectangulo.Y = uno->getY();
	rectangulo.Width = uno->getWidth() * uno->getDzoom();
	rectangulo.Height = uno->getHeight() * uno->getDzoom();

	Rectangle rectangulo2;
	rectangulo2.X = dos->getX();
	rectangulo2.Y = dos->getY();
	rectangulo2.Width = dos->getWidth() * dos->getDzoom();
	rectangulo2.Height = dos->getHeight() * dos->getDzoom();

	return rectangulo.IntersectsWith(rectangulo2);
}

inline bool Controladora::colision2(BaseMovimiento* uno, BaseMovimiento* dos)
{
	Rectangle rectangulo;
	rectangulo.X = uno->getX() - 5;
	rectangulo.Y = uno->getY() - 5;
	rectangulo.Width = uno->getWidth() * uno->getDzoom() + 10;
	rectangulo.Height = uno->getHeight() * uno->getDzoom() + 10;

	Rectangle rectangulo2;
	rectangulo2.X = dos->getX() - 5;
	rectangulo2.Y = dos->getY() - 5;
	rectangulo2.Width = dos->getWidth() * dos->getDzoom() + 10;
	rectangulo2.Height = dos->getHeight() * dos->getDzoom() + 10;

	return rectangulo.IntersectsWith(rectangulo2);
}

inline bool Controladora::encuentraObstaculo(BaseMovimiento* uno, BaseMovimiento* dos)
{
	//backup de las coordenadas actuales
	auxX1 = uno->getX();
	auxX2 = dos->getX();
	auxY1 = uno->getY();
	auxY2 = dos->getY();

	int vector[4];
	int aux;
	do {
		if (uno->getX() > dos->getX()) { //uno esta a la derecha de dos
			uno->setX(uno->getX() - uno->getDx());
		}
		else if (uno->getX() < dos->getX()) { //uno esta a la izquierda de dos
			uno->setX(uno->getX() + uno->getDx());
		}
		if (uno->getY() > dos->getY()) { //uno esta abajo de dos
			uno->setY(uno->getY() - uno->getDy());
		}
		else if (uno->getY() < dos->getY()) { //uno esta arriba de dos
			uno->setY(uno->getY() + uno->getDy());
		}
		for (int i = 0; i < objetos->size(); i++)
			if (colision(uno, objetos->at(i)) && objetos->at(i)->getClase() == obstaculo)
			{
				//regresa valores
				uno->setX(auxX1);
				dos->setX(auxX2);
				uno->setY(auxY1);
				dos->setY(auxY2);


				//(x,y)
				vector[0] = formulaDistancia(dos->getX(), objetos->at(i)->getX(), dos->getY(), objetos->at(i)->getY());
				//(x+w,y)
				vector[1] = formulaDistancia(dos->getX(), objetos->at(i)->getX() + objetos->at(i)->getWidth(), dos->getY(), objetos->at(i)->getY());
				//(x,y+h)
				vector[2] = formulaDistancia(dos->getX(), objetos->at(i)->getX(), dos->getY(), objetos->at(i)->getY() + objetos->at(i)->getHeight());
				//(x+w,y+h)
				vector[3] = formulaDistancia(dos->getX(), objetos->at(i)->getX() + objetos->at(i)->getWidth(), dos->getY(), objetos->at(i)->getY() + objetos->at(i)->getHeight());

				for (int i = 0; i < 4; i++)
				{
					for (int j = i + 1; j < 4; j++)
					{
						if (vector[i] < vector[j])
						{
							aux = vector[i];
							vector[i] = vector[j];
							vector[j] = aux;
						}
					}
				}

				if (vector[3] == formulaDistancia(dos->getX(), objetos->at(i)->getX(), dos->getY(), objetos->at(i)->getY()))
				{
					destinox = objetos->at(i)->getX() - uno->getWidth();
					destinoy = objetos->at(i)->getY() - uno->getHeight();
				}
				else if (vector[3] == formulaDistancia(dos->getX(), objetos->at(i)->getX() + objetos->at(i)->getWidth(), dos->getY(), objetos->at(i)->getY()))
				{
					destinox = objetos->at(i)->getX() - uno->getWidth();
					destinoy = objetos->at(i)->getY() - uno->getHeight();
				}
				else if (vector[3] == formulaDistancia(dos->getX(), objetos->at(i)->getX(), dos->getY(), objetos->at(i)->getY() + objetos->at(i)->getHeight()))
				{
					destinox = objetos->at(i)->getX() - uno->getWidth();
					destinoy = objetos->at(i)->getY() + objetos->at(i)->getHeight();
				}
				else if (vector[3] == formulaDistancia(dos->getX(), objetos->at(i)->getX() + objetos->at(i)->getWidth(), dos->getY(), objetos->at(i)->getY() + objetos->at(i)->getHeight()))
				{
					destinox = objetos->at(i)->getX() + objetos->at(i)->getWidth();
					destinoy = objetos->at(i)->getY() + objetos->at(i)->getHeight();
				}


				if (colision2(uno, objetos->at(i)) && objetos->at(i)->getClase() == obstaculo)
				{
					rodeaObstaculo(uno, dos);
					return true;
				}
				else
				{
					persecucion2(uno, destinox, destinoy);
					return true;
				}
			}
	} while (!colision(uno, dos));

	//regresa valores
	uno->setX(auxX1);
	dos->setX(auxX2);
	uno->setY(auxY1);
	dos->setY(auxY2);
	return false;
}

inline void Controladora::rodeaObstaculo(BaseMovimiento* uno, BaseMovimiento* dos)
{

	int vector[4];
	int aux;

	for (int i = 0; i < objetos->size(); i++)
		if (colision2(uno, objetos->at(i)) && objetos->at(i)->getClase() == obstaculo)
		{

			//(x,y)
			vector[0] = formulaDistancia(dos->getX(), objetos->at(i)->getX(), dos->getY(), objetos->at(i)->getY());
			//(x+w,y)
			vector[1] = formulaDistancia(dos->getX(), objetos->at(i)->getX() + objetos->at(i)->getWidth(), dos->getY(), objetos->at(i)->getY());
			//(x,y+h)
			vector[2] = formulaDistancia(dos->getX(), objetos->at(i)->getX(), dos->getY(), objetos->at(i)->getY() + objetos->at(i)->getHeight());
			//(x+w,y+h)
			vector[3] = formulaDistancia(dos->getX(), objetos->at(i)->getX() + objetos->at(i)->getWidth(), dos->getY(), objetos->at(i)->getY() + objetos->at(i)->getHeight());

			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					if (vector[i] < vector[j])
					{
						aux = vector[i];
						vector[i] = vector[j];
						vector[j] = aux;
					}
				}
			}

			if (vector[1] == formulaDistancia(dos->getX(), objetos->at(i)->getX(), dos->getY(), objetos->at(i)->getY()))
			{
				destinox = objetos->at(i)->getX() - uno->getWidth();
				destinoy = objetos->at(i)->getY() - uno->getHeight();
			}
			else if (vector[1] == formulaDistancia(dos->getX(), objetos->at(i)->getX() + objetos->at(i)->getWidth(), dos->getY(), objetos->at(i)->getY()))
			{
				destinox = objetos->at(i)->getX() - uno->getWidth();
				destinoy = objetos->at(i)->getY() - uno->getHeight();
			}
			else if (vector[1] == formulaDistancia(dos->getX(), objetos->at(i)->getX(), dos->getY(), objetos->at(i)->getY() + objetos->at(i)->getHeight()))
			{
				destinox = objetos->at(i)->getX() - uno->getWidth();
				destinoy = objetos->at(i)->getY() + objetos->at(i)->getHeight();
			}
			else if (vector[1] == formulaDistancia(dos->getX(), objetos->at(i)->getX() + objetos->at(i)->getWidth(), dos->getY(), objetos->at(i)->getY() + objetos->at(i)->getHeight()))
			{
				destinox = objetos->at(i)->getX() + objetos->at(i)->getWidth();
				destinoy = objetos->at(i)->getY() + objetos->at(i)->getHeight();
			}
		}
}

inline void Controladora::persecucion(BaseMovimiento* uno, BaseMovimiento* dos)
{
	if (colision(uno, dos)) {
		dos->setEliminate(true);
	}
	if (uno->getX() > dos->getX()) { //uno esta a la derecha de dos
		uno->setX(uno->getX() - uno->getDx());
		uno->setIdy(1);
	}
	else if (uno->getX() < dos->getX()) { //uno esta a la izquierda de dos
		uno->setX(uno->getX() + uno->getDx());
		uno->setIdy(2);
	}
	if (uno->getY() > dos->getY()) { //uno esta abajo de dos
		uno->setY(uno->getY() - uno->getDy());
		uno->setIdy(3);
	}
	else if (uno->getY() < dos->getY()) { //uno esta arriba de dos
		uno->setY(uno->getY() + uno->getDy());
		uno->setIdy(0);
	}	
}

inline void Controladora::persecucion2(BaseMovimiento* uno, int x, int y)
{
	if (uno->getX() > x) { //uno esta a la derecha de dos
		uno->setX(uno->getX() - uno->getDx());
		uno->setIdy(1);
	}
	else if (uno->getX() < x) { //uno esta a la izquierda de dos
		uno->setX(uno->getX() + uno->getDx());
		uno->setIdy(2);
	}
	if (uno->getY() > y) { //uno esta abajo de dos
		uno->setY(uno->getY() - uno->getDy());
		uno->setIdy(3);
	}
	else if (uno->getY() < y) { //uno esta arriba de dos
		uno->setY(uno->getY() + uno->getDy());
		uno->setIdy(0);
	}
}

inline float Controladora::formulaDistancia(int x1, int x2, int y1, int y2)
{
	return abs(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}
inline float Controladora::encuentraDistancia(BaseMovimiento* uno, BaseMovimiento* dos)
{
	return formulaDistancia(uno->getX(), dos->getX(), uno->getY(), dos->getY());
}

inline void Controladora::rompeRocas()
{
	for (int i = 0; i < objetos->size(); i++)
	{
		if (colision2(lider, objetos->at(i)) && objetos->at(i)->getClase() == obstaculo)
		{
			objetos->at(i)->setEliminate(true);
		}
	}
}

inline void Controladora::convierteAgentes(BaseMovimiento* uno, Bitmap^ imagenAliado)
{
	int auxX, auxY;
	auxX = uno->getX();
	auxY = uno->getY();
	uno->setEliminate(true);
	Aliado* nuevo = new Aliado(nivel);
	nuevo->setX(auxX);
	nuevo->setY(auxY);
	nuevo->setHeight(imagenAliado->Height / 4.0);
	nuevo->setWidth(imagenAliado->Width / 4.0);
	objetos->pushback(nuevo);
}

inline bool Controladora::getGanar() { return this->ganar; }
inline bool Controladora::getPerder() { return this->perder; }

inline int Controladora::getCantAliados() { return this->cantAliados; }
inline int Controladora::getPuntaje() { return this->puntaje; }

