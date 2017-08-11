#include "Llanta.h"
#include "Bicicleta.h"
#include "BicicletaCarrera.h"
#include "BicicletaMontana.h"

#include <iostream>
using namespace std;

BicicletaCarrera crearBicicletaCarrera();
BicicletaMontana crearBicicletaMontana();
void llenarCamionMontana(BicicletaMontana**, int ,int, BicicletaMontana, int, int);
void llenarCamionCarrera(BicicletaCarrera**, int ,int, BicicletaCarrera, int, int);
float calcularValorMontana(BicicletaMontana**, int, int);
float calcularValorCarrera(BicicletaCarrera**, int, int);

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
		tamanoMontanaM = (tamanoMontanaN) + (tamanoMontanaN*0.75);
	}else if (tamanoMontanaN%2 == 0){
		tamanoMontanaM = tamanoMontanaN*1.5;
	}else{
		tamanoMontanaM = tamanoMontanaN*2;
	}

	if(tamanoCarreraN%4 == 0){
		tamanoCarreraM = (tamanoCarreraN) + (tamanoCarreraN*0.75);
	}else if (tamanoCarreraN%2 == 0){
		tamanoCarreraM = tamanoCarreraN*1.5;
	}else{
		tamanoCarreraM = tamanoCarreraN*2;
	}

	camionMontana = new BicicletaMontana*[tamanoMontanaN];
	for(int i = 0; i < tamanoMontanaN; i++){
		camionMontana[i] = new BicicletaMontana[tamanoMontanaM];
	}

	camionCarrera = new BicicletaCarrera*[tamanoCarreraN];
	for(int i = 0; i < tamanoMontanaN; i++){
		camionCarrera[i] = new BicicletaCarrera[tamanoCarreraM];
	}


	cout << endl << "Los tamaños quedarán de la siguiente forma" << endl
		<< "Camión de Bicicletas de Montaña: (" << tamanoMontanaN << "x" 
		<< tamanoMontanaM << ")" << endl
		<< "Camión de Bicicletas de Carrera: (" << tamanoCarreraN << "x" 
		<< tamanoCarreraM << ")" << endl;

	bool salir = false;
	bool montanaLleno = false;
	bool carreraLleno = false;
	int contBicicletasMontM = 0;
	int contBicicletasMontN = 0;
	int contBicicletasCarrM = 0;
	int contBicicletasCarrN = 0;

	while(!salir){
		switch(menu()){
			bool continuar;
			int tipo;

			case 1:{
					   continuar = false;
					   tipo = -1;

					   do{
						   cout << "1. Bicicleta de Montaña" << endl << "2. Bicicleta de Carrera"
							   << endl << endl << "¿De que tipo será la nueva bicicleta? - ";
						   cin >> tipo;

						   switch(tipo){
							   case 1:{
										  if(montanaLleno){
											  cout << endl << "[ERROR] El camión seleccionado ya está lleno." << endl << endl;
											  break;
										  }

										  BicicletaMontana bm = crearBicicletaMontana();
										  camionMontana[contBicicletasMontN][contBicicletasMontM] = bm;
										  contBicicletasMontN++;

										  if(contBicicletasMontN == tamanoMontanaN){
											  contBicicletasMontN = 0;
											  contBicicletasMontM ++;
										  }

										  if(contBicicletasMontM == tamanoMontanaM){
											  montanaLleno = true;
										  }
										  continuar = true;}
									  break;
							   case 2:{
										  if(carreraLleno){
											  cout << endl << "[ERROR] El camión seleccionado ya está lleno." << endl;
										  }
										  BicicletaCarrera bc = crearBicicletaCarrera();
										  camionCarrera[contBicicletasCarrN][contBicicletasCarrM] = bc;
										  contBicicletasCarrN++;

										  if(contBicicletasMontN == tamanoMontanaN){
											  contBicicletasCarrN = 0;
											  contBicicletasCarrM ++;
										  }

										  if(contBicicletasCarrM == tamanoCarreraM){
											  carreraLleno = true;
										  }

										  continuar = true;}
									  break;
							   default:{
										   cout << endl << "Tipo de bicicleta inválido" << endl << endl;}
									   break;
						   }

					   }while(!continuar);

					   cout << endl << "Bicicleta agregada exitosamente." << endl;}
				   break;
			case 2:{
					   continuar = false;
					   tipo = -1;

					   do{
						   cout << endl << "1. Bicicleta de Montaña" << endl << "2. Bicicleta de Carrera"
							   << endl << endl << "¿De que tipo serán las nuevas bicicletas? - ";
						   cin >> tipo;

						   switch(tipo){
							   case 1:{
										  if(montanaLleno){
											  cout << endl << "[ERROR] El camión seleccionado ya está lleno." << endl << endl;
											  break;
										  }else{

										  BicicletaMontana bm = crearBicicletaMontana();
										  llenarCamionMontana(camionMontana, contBicicletasMontN, contBicicletasMontM, bm, tamanoMontanaN, tamanoMontanaM);
										  montanaLleno = true;
										  continuar = true;}
									  }
									  break;
							   case 2:{
										  if(carreraLleno){
											  cout << endl << "[ERROR] El camión seleccionado ya está lleno." << endl;
											  break;
										  }
										  BicicletaCarrera bc = crearBicicletaCarrera();

										  llenarCamionCarrera(camionCarrera, contBicicletasCarrN, contBicicletasCarrM, bc, tamanoCarreraN, tamanoCarreraM);
										  carreraLleno = true;
										  continuar = true;}
									  break;
							   default:{
										   cout << endl << "Tipo de bicicleta inválido" << endl << endl;}
									   break;
						   }

					   }while(!continuar);
					   cout << endl << "Camión llenado exitosamente." << endl;}
				   break;
			case 3:{
					   continuar = false;
					   tipo = -1;
					   float valorTotal = 0;

					   do{
						   cout << "1. Camión de Bicicletas de Montaña" << endl << "2. Camión de Bicicletas de Carrera"
							   << endl << endl << "¿De que camión desea calcular el valor? - ";
						   cin >> tipo;

						   switch(tipo){
							   case 1:{
										  valorTotal = calcularValorMontana(camionMontana, tamanoMontanaN, tamanoMontanaM);
										  continuar = true;}
									  break;
							   case 2:{
										  valorTotal = calcularValorCarrera(camionCarrera, tamanoCarreraN, tamanoCarreraM);
										  continuar = true;}
									  break;
							   default:
									  cout << "Opción inválida, por favor intente de nuevo." << endl;
									  break;
						   }

					   }while(!continuar);
					   if(valorTotal == 0){
							cout << "El camión seleccionado está vacío." << endl;
							break;
					   }
					   cout << "El valor total del camión seleccionado es de: " << valorTotal << endl;
				   }
				   break;
			case 4:{
					   cout << "Saliendo..." << endl;
					   salir = true;}
				   break;
			default:{
						cout << "Opción inválida, por favor intente de nuevo." << endl;}
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
	float peso;

	cout << endl << "------------------------------" << endl << "Creando Nueva Bicicleta de Montaña" << endl << endl
		<< "Ingrese los datos requeridos" << endl
		<< "Precio: ";

	cin >> precio;

	cout << "Peso: ";
	cin >> peso;

	b.setPrecio(precio);
	b.setPeso(peso);

	cout << endl << "Tipo de Llanta: " << endl << endl;

	Llanta l;

	string material;
	string color;
	float precioL;

	cout << "Material: ";
	cin >> material;

	cout << "Color: ";
	cin >> color;

	cout << "Precio: ";
	cin >> precioL;

	l.setMaterial(material);
	l.setColor(color);
	l.setPrecio(precioL);

	b.setTipoLlantas(l);
	return b;
}

BicicletaCarrera crearBicicletaCarrera(){
	BicicletaCarrera b;

	float precio;
	float peso;

	cout << endl << "------------------------------" << endl << "Creando Nueva Bicicleta de Carrera" << endl << endl
		<< "Ingrese los datos requeridos" << endl
		<< "Precio: ";

	cin >> precio;

	cout << "Peso: ";
	cin >> peso;

	b.setPrecio(precio);
	b.setPeso(peso);

	cout << endl << "Tipo de Llanta: " << endl << endl;

	Llanta l;

	string material;
	string color;

	float precioL;

	cout << "Material: ";
	cin >> material;

	cout << "Color: ";
	cin >> color;

	cout << "Precio: ";
	cin >> precioL;

	l.setMaterial(material);
	l.setColor(color);
	l.setPrecio(precioL);

	b.setTipoLlantas(l);
	return b;
}

void llenarCamionMontana(BicicletaMontana** camionCarrera, int contBicicletasCarrN, int contBicicletasCarrM, BicicletaMontana bc, int tamanoMontanaN, int tamanoMontanaM){
	bool lleno = false;

	while(!lleno){
		camionCarrera[contBicicletasCarrN][contBicicletasCarrM] = bc;
		contBicicletasCarrN++;


		if(contBicicletasCarrN == tamanoMontanaN){
			contBicicletasCarrN = 0;
			contBicicletasCarrM ++;
		}

		if(contBicicletasCarrM == tamanoMontanaM){
			lleno = true;
		}
	}

}

void llenarCamionCarrera(BicicletaCarrera** camionCarrera, int contBicicletasCarrN, int contBicicletasCarrM, BicicletaCarrera bc, int tamanoMontanaN, int tamanoMontanaM){
	bool lleno = false;

	while(!lleno){
		camionCarrera[contBicicletasCarrN][contBicicletasCarrM] = bc;
		contBicicletasCarrN++;


		if(contBicicletasCarrN == tamanoMontanaN){
			contBicicletasCarrN = 0;
			contBicicletasCarrM ++;
		}

		if(contBicicletasCarrM == tamanoMontanaM){
			lleno = true;
		}
	}

}

float calcularValorMontana(BicicletaMontana** b, int n, int m){
	float valor = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			valor += b[i][j].getPrecio();
			valor += b[i][j].getTipoLlantas().getPrecio();
		}
	}

	return valor;
}

float calcularValorCarrera(BicicletaCarrera** b, int n, int m){
	float valor = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			valor += b[i][j].getPrecio();
			valor += b[i][j].getTipoLlantas().getPrecio();
		}
	}

	return valor;
}


