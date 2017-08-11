#ifndef BICICLETA_H
#define BICICLETA_H

#include "Llanta.h"

class Bicicleta{
	private:
		float precio;
		float peso;
		Llanta tipoLlantas;
	public:
		void setPrecio(float);
		void setPeso(float);
		void setTipoLlantas(Llanta);
		float getPrecio();
		float getPeso();
		Llanta getTipoLlantas();
};

#endif
