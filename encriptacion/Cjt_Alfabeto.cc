/** @file Cjt_Alfabeto.cc
@brief Codigo de la clase Cjt_Alfabeto
*/
#include "Cjt_Alfabeto.hh"

Cjt_Alfabeto::Cjt_Alfabeto(){
	int n;
	string a, nombre;
	cin >> n;
	for (int i = 0; i < n;  ++i)
	{
		cin >> nombre;
		cin >> a;
		Alfabeto aux(a);
		alfabetos.insert(make_pair(nombre, aux));
	}
}

Cjt_Alfabeto::~Cjt_Alfabeto(){}

void Cjt_Alfabeto::conjuntoInicial(){}

void Cjt_Alfabeto::addAlfabeto()
{
	string a, nombre;
	map <string, Alfabeto>::const_iterator it;
	cin >> nombre;
	cin >> a;
	it = alfabetos.find(nombre);
	if(it != alfabetos.end())
		cout << "Alfabeto ya esistente";
	else {
		Alfabeto aux(a);
			alfabetos.insert(make_pair(nombre, aux));
	}
}

void Cjt_Alfabeto::borrarAlfabeto()
{
}

void Cjt_Alfabeto::listarAlfabeto()
{
	int i = 1;
	map<string, Alfabeto>::iterator it = alfabetos.begin();
	while (it != alfabetos.end()) {
		cout << i << ". " + it->first << endl;
		it->second.imprimir();
		++it;
		++i;
	}
}

void Cjt_Alfabeto::nuevoMsg(string alf)
{
	map <string, Alfabeto>::iterator it;
	it = alfabetos.find(alf);

	if(it != alfabetos.end()) 
		it->second.sumarMensaje();
	
}

map<string, Alfabeto>::const_iterator Cjt_Alfabeto::findAlfabeto(string nombre)
{
	map <string, Alfabeto>::const_iterator it;
	it = alfabetos.find(nombre);
	if (it != alfabetos.end())
		cout << "Alfabeto ya esistente";
	return it;
}

map<string, Alfabeto>::const_iterator Cjt_Alfabeto::ultimaPos()
{
	map <string, Alfabeto>::const_iterator it = alfabetos.end();
	return it;
}
