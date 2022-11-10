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
	getline(cin, nombre);
	getline(cin, nombre);
	for (int i = 0; i < n; ++i)
	{
		getline(cin, nombre);
		pos = nombre.find(" ");
		a = nombre.substr(pos + 1, nombre.length() - 1);
		nombre = nombre.substr(0, pos);
		getline(cin, msg);
		Mensaje aux(msg, a);
		mensajes.insert(make_pair(nombre, aux));
		alf.nuevoMsg(a);
		getline(cin, nombre);
	}
}

Cjt_Mensaje::~Cjt_Mensaje() {}

void Cjt_Mensaje::conjuntoInicial() {}

void Cjt_Mensaje::addMensaje(Cjt_Alfabeto& alf)
{
	int pos;
	string nombre, a, msg;
	getline(cin, nombre);
	cout << " " << nombre << endl;
	pos = nombre.find(" ");
	a = nombre.substr(pos + 1, nombre.length() - 1);
	nombre = nombre.substr(0, pos);
	map <string, Alfabeto>::const_iterator itA;
	map <string, Mensaje>::const_iterator itM;
	itA = alf.findAlfabeto(a);
	getline(cin, msg);
	if (itA == alf.ultimaPos()) {
		cout << "error: el alfabeto no existe" << endl;
	}
	else {
		itM = mensajes.find(nombre);
		if (itM != mensajes.end())
			cout << "error: ya existe un mensaje con ese identificador" << endl;
		else {
			Mensaje aux(msg, a);
			mensajes.insert(make_pair(nombre, aux));
			alf.nuevoMsg(a);
			cout << mensajes.size() << endl;
		}
	}
}

void Cjt_Mensaje::borrarMensaje(Cjt_Alfabeto& alf)
{
	string nombre, aux;
	cin >> nombre;
	getline(cin, aux);
	cout << " " << nombre << endl;
	map <string, Mensaje>::iterator it;
	it = mensajes.find(nombre);
	if (it != mensajes.end()) {
		alf.borrarMsg(it->second.alfabetoPertenece());
		mensajes.erase(it);
		cout << mensajes.size() << endl;
	}
	else
	cout << "error: el mensaje no existe" << endl;
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

void Cjt_Mensaje::codificaSustGuardado(Cjt_Alfabeto& alf)
{
	string ident, clave, mensaje, alfabeto;
	int x = 0, y = 0;
	cin >> ident;
	bool aux = true;
	getline(cin, clave);
	getline(cin, clave);
	cout << " " << ident << " \"" << clave << "\"" << endl;
	map<string, Mensaje>::iterator it = mensajes.find(ident);
	if (it == mensajes.end())
		cout << "error: el mensaje no existe" << endl;
	else {
		it->second.codDecod();
		mensaje = it->second.mensajeTiene();
		alfabeto = alf.devolverAlf(it->second.alfabetoPertenece());
		while (clave.size() != mensaje.size()) {
			if (clave.size() < mensaje.size())
				clave += clave;
			else if (clave.size() > mensaje.size())
				clave.pop_back();
		}
		for (int i = 0; i < mensaje.size(); ++i)
		{
			for (int z = 0; z < alfabeto.size() and aux; z++)
			{
				if (mensaje[i] == alfabeto[z])
					x = z;
				if (clave[i] == alfabeto[z])
					y = z;
				if (x != 0 and y != 0)
					aux = false;
			}
			x = (x + y) % alfabeto.size();
			mensaje[i] = alfabeto[x];
			x = 0;
			y = 0;
			aux = true;
		}
		cout <<  "\"" << mensaje << "\"" << endl;
	}
}

void Cjt_Mensaje::codificaSustNoGuardado(Cjt_Alfabeto& alf)
{
	string ident, clave, mensaje, alfabeto;
	int x = 0, y = 0;
	cin >> ident;
	bool aux = true;
	getline(cin, clave);
	getline(cin, clave);
	getline(cin, mensaje);
	cout << " " << ident << " \"" << clave << "\"" << endl;
	map<string, Alfabeto>::const_iterator it = alf.findAlfabeto(ident);
	if (it == alf.ultimaPos())
		cout << "error: el alfabeto no existe" << endl;
	else {
		alfabeto = alf.devolverAlf(ident);
		//alf.nuevoMsg(ident);
		while (clave.size() != mensaje.size()) {
			if (clave.size() < mensaje.size())
				clave += clave;
			else if (clave.size() > mensaje.size())
				clave.pop_back();
		}
		for (int i = 0; i < mensaje.size(); ++i)
		{
			for (int z = 0; z < alfabeto.size() and aux; z++)
			{
				if (mensaje[i] == alfabeto[z])
					x = z;
				if (clave[i] == alfabeto[z])
					y = z;
				if (x != 0 and y != 0)
					aux = false;
			}
			x = (x + y) % alfabeto.size();
			mensaje[i] = alfabeto[x];
			x = 0;
			y = 0;
			aux = true;
		}
		cout << "\"" << mensaje << "\"" << endl;
	}
}

void Cjt_Mensaje::decodificaSust(Cjt_Alfabeto& alf)
{
	string ident, clave, mensaje, alfabeto;
	int x = 0, y = 0;
	cin >> ident;
	bool aux = true;
	getline(cin, clave);
	getline(cin, clave);
	getline(cin, mensaje);
	cout << " " << ident << " \"" << clave << "\"" << endl;
	map<string, Alfabeto>::const_iterator it = alf.findAlfabeto(ident);
	if (it == alf.ultimaPos())
		cout << "error: el alfabeto no existe" << endl;
	else {
		map<string, Mensaje>::iterator itM = buscarCod(ident);
		//if (itM != mensajes.end()) {
			alfabeto = alf.devolverAlf(ident);
			//mensaje = itM->second.mensajeTiene();
			itM->second.codDecod();
			//alf.nuevoMsg(ident);
			while (clave.size() != mensaje.size()) {
				if (clave.size() < mensaje.size())
					clave += clave;
				else if (clave.size() > mensaje.size())
					clave.pop_back();
			}
			for (int i = 0; i < mensaje.size(); ++i)
			{
				for (int z = 0; z < alfabeto.size() and aux; z++)
				{
					if (mensaje[i] == alfabeto[z])
						x = z;
					if (clave[i] == alfabeto[z])
						y = z;
					if (x != 0 and y != 0)
						aux = false;
				}
				if ((x - y) < 0)
					x = (x - y + alfabeto.size()) % alfabeto.size();
				else
					x = (x - y) % alfabeto.size();
				mensaje[i] = alfabeto[x];
				x = 0;
				y = 0;
				aux = true;
			}
			cout << "\"" << mensaje << "\"" << endl;
		//}
	}
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

 map<string, Mensaje>::iterator Cjt_Mensaje::buscarCod(string alf)
{
	map<string, Mensaje>::iterator it = mensajes.begin();
	while (it != mensajes.end()) {
		if (it->second.alfabetoPertenece() == alf and it->second.codificacion())
			return it;
		++it;
	}
	return it;
}