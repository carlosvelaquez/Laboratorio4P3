#include "Bicicleta.h"

Bicicleta::setPrecio(float nPrecio){
	precio = nPrecio;
}

Bicicleta::setPeso(float nPeso){
	peso = nPeso;
}

Bicicleta::setTipoLlantas(Llanta nLlanta){
	tipoLlantas = nLlanta;
}

Bicicleta::getPrecio(){
	return precio;
}

Bicicleta::getPeso(){
	return peso;
}

Bicicleta::getTipoLlantas(){
	return tipoLlantas;
}
