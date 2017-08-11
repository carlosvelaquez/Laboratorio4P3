#ifndef LLANTA_H
#define LLANTA_H

#include <string>
using namespace std;

class Llanta{
	private:
		string material;
		float precio;
		string color;
	public:
		string getMaterial();
		void setMaterial(string);
		string getColor();
		void setColor(string);
		float getPrecio();
		void setPrecio(float);
};

#endif
