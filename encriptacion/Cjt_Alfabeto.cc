/** @file Cjt_Alfabeto.cc
@brief Codigo de la clase Cjt_Alfabeto
*/
#include "Cjt_Alfabeto.hh"

Cjt_Alfabeto::Cjt_Alfabeto(){
	int n;
	string a, nombre;
	cin >> n;
	getline(cin, nombre);
	getline(cin, nombre);
	for (int i = 0; i < n;  ++i)
	{
		getline(cin, nombre);
		getline(cin, a);
		Alfabeto aux(a);
		alfabetos.insert(make_pair(nombre, aux));
		getline(cin, nombre);
	}
}

Cjt_Alfabeto::~Cjt_Alfabeto(){}

void Cjt_Alfabeto::conjuntoInicial(){}

void Cjt_Alfabeto::addAlfabeto()
{
	string nombre, aux, alf;
	map <string, Alfabeto>::const_iterator it;
	cin >> nombre;
	getline(cin, aux);
	cin >> alf;
	getline(cin, aux);
	cout << " " << nombre << endl;
	it = alfabetos.find(nombre);
	if(it != alfabetos.end())
		cout << "error: el alfabeto ya existe" << endl;
	else {
		Alfabeto aux(alf);
		alfabetos.insert(make_pair(nombre, aux));
		cout << alfabetos.size() << endl;
	}
}

void Cjt_Alfabeto::borrarAlfabeto()
{
	string nombre, aux;
	map <string, Alfabeto>::const_iterator it;
	cin >> nombre;
	getline(cin, aux);
	cout << " " << nombre << endl;
	it = alfabetos.find(nombre);
	if (it == alfabetos.end())
		cout << "error: el alfabeto no existe" << endl;
	else {
		if (alfabetos.find(nombre)->second.numMensaje() > 0)
			cout << "error: hay mensajes guardados con el alfabeto" << endl;
		else {
			alfabetos.erase(it);
			cout << alfabetos.size() << endl; 
		}
	}
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

void Cjt_Alfabeto::borrarMsg(string alf)
{
	map <string, Alfabeto>::iterator it;
	it = alfabetos.find(alf);

	if (it != alfabetos.end()) {
		it->second.restarMensaje();
	}

}

string Cjt_Alfabeto::devolverAlf(string id)
{
	map <string, Alfabeto>::iterator it;
	it = alfabetos.find(id);
	return it->second.returnAlf();

}

map<string, Alfabeto>::const_iterator Cjt_Alfabeto::findAlfabeto(string nombre)
{
	map <string, Alfabeto>::const_iterator it;
	it = alfabetos.find(nombre);
	return it;
}

map<string, Alfabeto>::const_iterator Cjt_Alfabeto::ultimaPos()
{
	map <string, Alfabeto>::const_iterator it = alfabetos.end();
	return it;
}

