#include "Llanta.h"
#include "Bicicleta.h"
#include "BicicletaCarrera.h"
#include "BicicletaMontana.h"

#include <iostream>
using namespace std;

Bicicleta crearBicicleta();
int menu();

int main(){
	int tamanoMontanaN;
	int tamanoMontanaM;
	int tamanoCarreraN;
	int tamanoCarreraM;
	BicicletaMontana** camionMontana;
	BicicletaCarrera** camionCarrera;

	cout << "Usted ha iniciado sesión en Jitenhsha Motors" << endl
		<< "Bienvenido, Admin" << endl << "------------------------------"
		<< endl << "Por favor especifique el tamaño de los camiones" << endl << endl
		<< "Camión 1 (Bicicletas de Montaña): ";

	cin >> tamanoMontanaN;

	cout << "Camión 2 (Bicicletas de Carrera): ";
	cin >> tamanoCarreraN;

	if(tamanoMontanaN%4 == 0){
		tamanoMontanaM = (tamanoMontanaN) + (tamanoMonataN*0.75);
	}else if (tamanoMontanaN%2 == 0){
		tamanoMontanaM = tamanoMontanaN*1.5;
	}else{
		tamanoMontanaM = tamanoMontana*2;
	}

	if(tamanoCarreraN%4 == 0){
		tamanoCarreraM = (tamanoCarreraN) + (tamanoCarreraN*0.75);
	}else if (tamanoCarreraN%2 == 0){
		tamanoCarreraM = tamanoCarreraN*1.5;
	}else{
		tamanoCarreraM = tamanoCarrera*2;
	}

	cout << endl << "Los tamaños quedarán de la siguiente forma" << endl
		<< "Camión de Bicicletas de Montaña: (" << tamanoMontanaN << "x" 
		<< tamanoMontanaM << ")" << endl
		<< "Camión de Bicicletas de Carrera: (" << tamanoCarreraN << "x" 
		<< tamanoCarreraM << ")" << endl;

	bool salir = false;
	int contBicicletasM = 0;
	int contBicicletasC = 0;

	while(!salir){
		switch(menu()){
			case 1:
				bool continuar = false;
				int tipo = -1;

				do{
					cout << endl << "1. Bicicleta de Montaña" << endl << "2. Bicicleta de Carrera"
						<< endl << endl << "¿De que tipo será la nueva bicicleta? - ";
					cin >> tipo;

					switch(tipo){
						case 1:
							BicicletaMontana bm = crearBicicletaMontana();
							camionMontana[contBicicletasM] = bm;
							contBicicletasM++;
							continuar = true;
							break;
						case 2:
							BicicletaCarrera bc = crearBicicletaCarrera();
							camionCarrera[contBicicletasC] = bc;
							contBicicletasC++;
							continuar = true;
							break;
						default:
							cout << endl << "Tipo de bicicleta inválido" << endl << endl;
							break;
					}

				}while(!continuar);

				cout << endl << "Bicicleta agregada exitosamente." << endl;
				break;
			case 2:
				continuar = false;
				tipo = -1;

				do{
					cout << endl << "1. Bicicleta de Montaña" << endl << "2. Bicicleta de Carrera"
						<< endl << endl << "¿De que tipo serán las nuevas bicicletas? - ";
					cin >> tipo;

					switch(tipo){
						case 1:
							BicicletaMontana bm = crearBicicletaMontana();
							camionMontana[contBicicletasM] = bm;
							contBicicletasM++;
							continuar = true;
							break;
						case 2:
							BicicletaCarrera bc = crearBicicletaCarrera();
							camionCarrera[contBicicletasC] = bc;
							contBicicletasC++;
							continuar = true;
							break;
						default:
							cout << endl << "Tipo de bicicleta inválido" << endl << endl;
							break;
					}

				}while(!continuar);
				cout << "Camión llenado exitosamente." << endl;
				break;
			case 4:
				cout << "Saliendo..." << endl;
				salir = true;
				break;
			default:
				cout << "Opción inválida, por favor intente de nuevo." << endl;
				break;
		}

	}

	return 0;
}

int menu(){
	cout << "-----------------------------" << endl << "Menú Principal" << endl
		<< endl << "1. Agregar Bicicleta Individual" << endl
		<< "2. Llenar Espacios Restantes con Nueva Bicicleta" << endl
		<< "3. Calcular Valor Total de un Camión" << endl
		<< "4. Salir del Programa" << endl << endl;

	cout << "Ingrese el número de la opción que desea: ";

	int opcionMenu;
	cin >> opcionMenu;
	cout << "-----------------------------" << endl;
	return opcionMenu;
}

BicicletaMontana crearBicicletaMontana(){
	BicicletaMontana b;

	float precio;
	string color;
	float peso;

	cout << "Creando Nueva Bicicleta de Montaña" << endl << endl
		<< "Ingrese los datos requeridos" << endl
		<< "Precio: ";

	cin >> precio;

	cout << "Color: ";
	cin >> color;

	cout << "Peso: ";
	cin >> peso;

	b.setPrecio(precio);
	b.setColor(color);
	b.setPeso(peso);

	return b;
}

BicicletaCarrera crearBicicletaCarrera(){
	BicicletaCarrera b;

	float precio;
	string color;
	float peso;

	cout << "Creando Nueva Bicicleta de Carrera" << endl << endl
		<< "Ingrese los datos requeridos" << endl
		<< "Precio: ";

	cin >> precio;

	cout << "Color: ";
	cin >> color;

	cout << "Peso: ";
	cin >> peso;

	b.setPrecio(precio);
	b.setColor(color);
	b.setPeso(peso);

	return b;
}


