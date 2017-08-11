#include "Bicicleta.h"

void Bicicleta::setPrecio(float nPrecio){
	precio = nPrecio;
}

void Bicicleta::setPeso(float nPeso){
	peso = nPeso;
}

void Bicicleta::setTipoLlantas(Llanta nLlanta){
	tipoLlantas = nLlanta;
}

float Bicicleta::getPrecio(){
	return precio;
}

float Bicicleta::getPeso(){
	return peso;
}

Llanta Bicicleta::getTipoLlantas(){
	return tipoLlantas;
}
