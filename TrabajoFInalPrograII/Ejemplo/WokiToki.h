#pragma once
#include "BaseMovimiento.h"

class WokiToki : public BaseMovimiento
{
public:
	WokiToki();
	~WokiToki();

};

WokiToki::WokiToki()
{
	eliminate = false;
	dx = dy = 0;
	idx = idy = 0;
	clase = wokitoki;
	dzoom = 0.1;
}

WokiToki::~WokiToki()
{
}