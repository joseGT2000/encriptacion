/** @file Alfabeto.cc
@brief Codigo de la clase Alfabeto
*/
#include "Alfabeto.hh"

Alfabeto::Alfabeto()
{
}

Alfabeto::Alfabeto(string alf)
{
	alfabeto = alf;
	esSpecial();
}

Alfabeto::~Alfabeto()
{
}

void Alfabeto::sumarMensaje()
{
	++numMensajes;
}

void Alfabeto::restarMensaje()
{
	--numMensajes;
}

int Alfabeto::numMensaje()
{
	return numMensajes;
}

string Alfabeto::returnAlf()
{
	return alfabeto;
}

void Alfabeto::imprimir()
{
	if (special) 
		cout << "especial [" << alfabeto[0] << ".." << alfabeto[alfabeto.size() - 1] << "] " << numMensajes << " mensajes" << endl;
	else
		cout << "normal \"" << alfabeto << "\" " << numMensajes << " mensajes" << endl;
	
}

void Alfabeto::esSpecial()
{
	for (int i = 1; i < alfabeto.size() and special; ++i)
	{
		if (alfabeto[i] < alfabeto[i - 1])
			special = false;
		else if(alfabeto[i] > alfabeto[i - 1] and (alfabeto[i] - alfabeto[i - 1]) != 1)
			special = false;
	}
}
