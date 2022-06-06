#pragma once
#include "BaseMovimiento.h"

class ArrBaseMovimiento : public BaseMovimiento
{
public:
	ArrBaseMovimiento();
	~ArrBaseMovimiento();

	//FUNCIONES VECTOR
	BaseMovimiento* at(int indice);
	int size();
	void pushback(BaseMovimiento* nuevo);
	void erase();

	//OTROS
	void moverTodos(Graphics^ grafico, char direccion);
	void mostrarTodos(Graphics^ grafico, Bitmap^ imagenLider, Bitmap^ imagenAliado,
		Bitmap^ imagenAgente, Bitmap^ imagenHabitante, Bitmap^ imagenObstaculo, 
		Bitmap^ imagenPocion, Bitmap^ imagenHelicoptero, Bitmap^ imagenWokiToki);
private:
	int nele;
	BaseMovimiento** arreglo;
};

ArrBaseMovimiento::ArrBaseMovimiento()
{
	nele = 0;
}

ArrBaseMovimiento::~ArrBaseMovimiento()
{
	for (int i = 0; i < nele; i++)
		delete arreglo[i];
	delete arreglo;
}

inline BaseMovimiento* ArrBaseMovimiento::at(int indice) { return arreglo[indice]; }
inline int ArrBaseMovimiento::size() { return nele; }

inline void ArrBaseMovimiento::pushback(BaseMovimiento* nuevo)
{
	//CREAR UN BACKUP
	BaseMovimiento** aux = new BaseMovimiento * [nele];
	for (int i = 0; i < nele; i++)
		aux[i] = arreglo[i];
	//SE INCREMENTA EL ARREGLO
	arreglo = new BaseMovimiento * [nele + 1];
	//SE DEVUELVEN LOS VALORES 
	for (int i = 0; i < nele; i++)
		arreglo[i] = aux[i];
	//SE AGREGA EL NUEVO ELEMENTO
	arreglo[nele] = nuevo;
	//SE DA ESPACIO PARA LA SIGUIENTE OCASION
	nele += 1;
}

inline void ArrBaseMovimiento::erase()
{
	int cont = 0;
	//CONTAMOS CUANTOS SE HAN ELIMINADO
	for (int i = 0; i < nele; i++)
		if (arreglo[i]->getEliminate()) cont++;
	//GENERAMOS EL AUXILIAR
	BaseMovimiento** aux = new BaseMovimiento * [nele - cont];
	int j = 0;
	for (int i = 0; i < nele; i++)
		if (arreglo[i]->getEliminate() == false) { aux[j] = arreglo[i]; j++; }
	//AHORA EL ARREGLO APUNTE AL AUX
	arreglo = aux;
	nele -= cont;
}

inline void ArrBaseMovimiento::moverTodos(Graphics^ grafico, char direccion)
{
	for (int i = 0; i < nele; i++)
		arreglo[i]->mover(grafico, direccion);
}

inline void ArrBaseMovimiento::mostrarTodos(Graphics^ grafico, Bitmap^ imagenLider, Bitmap^ imagenAliado, 
								Bitmap^ imagenAgente, Bitmap^ imagenHabitante, Bitmap^ imagenObstaculo, 
								Bitmap^ imagenPocion, Bitmap^ imagenHelicoptero, Bitmap^ imagenWokiToki)
{
	for (int i = 0; i < nele; i++)
	{
		if (arreglo[i]->getClase() == lider)
			arreglo[i]->mostrar(grafico, imagenLider);
		if (arreglo[i]->getClase() == aliado)
			arreglo[i]->mostrar(grafico, imagenAliado);
		if (arreglo[i]->getClase() == agente)
			arreglo[i]->mostrar(grafico, imagenAgente);
		if (arreglo[i]->getClase() == habitante)
			arreglo[i]->mostrar(grafico, imagenHabitante);
		if (arreglo[i]->getClase() == obstaculo)
			arreglo[i]->mostrar(grafico, imagenObstaculo);
		if (arreglo[i]->getClase() == pocion)
			arreglo[i]->mostrar(grafico, imagenPocion);
		if (arreglo[i]->getClase() == helicoptero)
			arreglo[i]->mostrar(grafico, imagenHelicoptero);
		if (arreglo[i]->getClase() == wokitoki)
			arreglo[i]->mostrar(grafico, imagenWokiToki);
	}
}
