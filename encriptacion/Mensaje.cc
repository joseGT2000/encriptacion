/** @file Mensaje.cc
@brief Codigo de la clase Mensaje
*/
#include "Mensaje.hh"

Mensaje::Mensaje()
{
}

Mensaje::Mensaje(string msg, string alf)
{
	this->msg.second = msg;
	this->msg.first = alf;
}

Mensaje::~Mensaje()
{
}

void Mensaje::imprimir()
{
	cout << msg.first << endl;
	cout << "\"" << msg.second << "\"" << endl;

}
string Mensaje::alfabetoPertenece() {
	return msg.first;
}

string Mensaje::mensajeTiene() {
	return msg.second;
}

void Mensaje::codDecod()
{
	codificado = not codificado;
}

bool Mensaje::codificacion()
{
	return codificado;
}
