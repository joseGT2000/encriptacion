/** @file Cjt_Mensaje.cc
@brief Codigo de la clase Cjt_Mensaje
*/
#include "Cjt_Mensaje.hh"

Cjt_Mensaje::Cjt_Mensaje()
{
}

Cjt_Mensaje::Cjt_Mensaje(Cjt_Alfabeto& alf) {
	int n, pos;
	string a, nombre, msg;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> nombre;
		cin >> a;
		//pos = nombre.find(" ");
		//a = nombre.substr(pos + 1, nombre.length() - 1);
		cin >> msg;
		Mensaje aux(msg, a);
		mensajes.insert(make_pair(nombre, aux));
		alf.nuevoMsg(a);
	}
}

Cjt_Mensaje::~Cjt_Mensaje() {}

void Cjt_Mensaje::conjuntoInicial() {}

void Cjt_Mensaje::addMensaje(Cjt_Alfabeto& alf)
{
	string nombre, a, msg;
	cin >> nombre;
	cin >> a;
	//pos = nombre.find(" ");
	//a = nombre.substr(pos + 1, nombre.length() - 1);
	map <string, Alfabeto>::const_iterator itA;
	map <string, Mensaje>::const_iterator itM;
	itA = alf.findAlfabeto(nombre);
	if (itA != alf.ultimaPos())
		cout << "Alfabeto ya esistente";
	else {
		itM = mensajes.find(nombre);
		if (itM != mensajes.end())
			cout << "Mensaje ya esistente";
		else {
			cin >> msg;
			Mensaje aux(msg, a);
			mensajes.insert(make_pair(nombre, aux));
			alf.nuevoMsg(a);
		}
	}
}

void Cjt_Mensaje::borrarMensaje(Cjt_Alfabeto& alf)
{
}

void Cjt_Mensaje::listarMensajes()
{
	int i = 1;
	map<string, Mensaje>::iterator it = mensajes.begin();
	while (it != mensajes.end()) {
		cout << i << ". " + it->first << endl;
		it->second.imprimir();
		++it;
		++i;
	}
}

void Cjt_Mensaje::codificaSustGuardado()
{
}

void Cjt_Mensaje::codificaSustNoGuardado()
{
}

void Cjt_Mensaje::decodificaSust()
{
}

void Cjt_Mensaje::codificaPermGuardado()
{
}

void Cjt_Mensaje::codificaPermNoGuardado()
{
}

void Cjt_Mensaje::decodificaPerm()
{
}
