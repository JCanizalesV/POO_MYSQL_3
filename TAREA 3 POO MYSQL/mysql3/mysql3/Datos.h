#pragma once

#include <iostream>
using namespace std;

class Datos{

protected: string proveedo, direccion;
		 int telefono = 0;

protected:
	Datos() {
	}
	Datos(string dor, int tel, string dir) {
		proveedo = dor;
		telefono = tel;
		direccion = dir;	}
};

