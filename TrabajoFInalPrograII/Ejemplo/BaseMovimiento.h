#pragma once
#include <iostream>
using namespace System;
using namespace System::Drawing;
using namespace std;
//CLASE PADRE

enum Clases { lider = 0, aliado = 1, agente = 2, habitante = 3, obstaculo = 4, pocion = 5, helicoptero = 6, wokitoki = 7};

class BaseMovimiento
{
public:
	BaseMovimiento();
	~BaseMovimiento();
	//GETTERS 
	int getX();
	int getY();
	int getDx();
	int getDy();
	int getHeight();
	int getWidth();
	int getMaxRow();
	int getMaxColumn();
	bool getEliminate();
	int getIdx();
	int getIdy();
	float getDzoom();
	Clases getClase();
	float getDistancia();
	int getIndice();

	//SETTERS
	void setX(int nuevo);
	void setY(int nuevo);
	void setDx(int nuevo);
	void setDy(int nuevo);
	void setHeight(int nuevo);
	void setWidth(int nuevo);
	void setEliminate(bool nuevo);
	void setMaxRow(int maxR);
	void setMaxColumn(int maxC);
	void setIdx(int idx);
	void setIdy(int idy);
	void setDzoom(float dzoom);
	void setClase(Clases clase);
	void setDistancia(float distancia);
	void setIndice(int indice);

	//OTROS
	void mostrar(Graphics^ grafico, Bitmap^ imagen);
	virtual void mover(Graphics^ grafico, char direccion);

protected:
	int x, y, dx, dy, height, width, maxR, maxC, idx, idy, indice;
	float dzoom, distancia;
	bool eliminate;
	Clases clase;
};

BaseMovimiento::BaseMovimiento()
{
	dzoom = 1.0;
	dx = dy = 5;
}
BaseMovimiento::~BaseMovimiento(){}

inline int BaseMovimiento::getX() { return this->x; }
inline int BaseMovimiento::getY() { return this->y; }
inline int BaseMovimiento::getDx() { return this->dx; }
inline int BaseMovimiento::getDy() { return this->dy; }
inline int BaseMovimiento::getHeight() { return this->height; }
inline int BaseMovimiento::getWidth() { return this->width; }
inline bool BaseMovimiento::getEliminate() { return this->eliminate; }
inline int BaseMovimiento::getIdx() { return this->idx; }
inline int BaseMovimiento::getIdy() { return this->idy; }
inline float BaseMovimiento::getDzoom() { return this->dzoom; }
inline Clases BaseMovimiento::getClase() { return this->clase; }
inline float BaseMovimiento::getDistancia() { return distancia; }
inline int BaseMovimiento::getIndice() { return this->indice; }
inline int BaseMovimiento::getMaxRow(){	return this->maxR;}
inline int BaseMovimiento::getMaxColumn() { return this->maxC; }

inline void BaseMovimiento::setX(int nuevo) { this->x = nuevo; }
inline void BaseMovimiento::setY(int nuevo) { this->y = nuevo; }
inline void BaseMovimiento::setDx(int nuevo) { this->dx = nuevo; }
inline void BaseMovimiento::setDy(int nuevo) { this->dy = nuevo; }
inline void BaseMovimiento::setHeight(int nuevo) { this->height = nuevo; }
inline void BaseMovimiento::setWidth(int nuevo) { this->width = nuevo; }
inline void BaseMovimiento::setEliminate(bool nuevo) { this->eliminate = nuevo; }
inline void BaseMovimiento::setMaxRow(int maxR) { this->maxR = maxR; }
inline void BaseMovimiento::setMaxColumn(int maxC) { this->maxC = maxC; }
inline void BaseMovimiento::setIdx(int idx) { this->idx = idx; }
inline void BaseMovimiento::setIdy(int idy) { this->idy = idy; }
inline void BaseMovimiento::setDzoom(float dzoom) { this->dzoom = dzoom; }
inline void BaseMovimiento::setClase(Clases clase) { this->clase = clase; }
inline void BaseMovimiento::setDistancia(float distancia) { this->distancia = distancia; }
inline void BaseMovimiento::setIndice(int indice) { this->indice = indice; }

inline void BaseMovimiento::mostrar(Graphics^ grafico, Bitmap^ imagen) 
{
	Rectangle porcion = Rectangle(idx * width, idy * height, width, height);
	Rectangle zoom = Rectangle(x, y, width * dzoom, height * dzoom);
	grafico->DrawImage(imagen, zoom, porcion, GraphicsUnit::Pixel);
}
inline void BaseMovimiento::mover(Graphics^ grafico, char direccion) {}
