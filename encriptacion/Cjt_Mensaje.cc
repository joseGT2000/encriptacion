/** @file Cjt_Mensaje.cc
@brief Codigo de la clase Cjt_Mensaje
*/
#include "Cjt_Mensaje.hh"

Cjt_Mensaje::Cjt_Mensaje()
{
}

Cjt_Mensaje::Cjt_Mensaje(Cjt_Alfabeto& alf) {
	int n;
	string a, nombre, msg;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> nombre;
		cin >> a;
		getline(cin, msg);
		while (msg == "") {
			cin.clear();
			getline(cin, msg);
		}

		map <string, Alfabeto>::const_iterator itA;
		itA = alf.findAlfabeto(a);
		if (itA != alf.ultimaPos()) {
			Mensaje aux(msg, a);
			mensajes.insert(make_pair(nombre, aux));
			alf.nuevoMsg(a);
		}
	}
}

Cjt_Mensaje::~Cjt_Mensaje() {}

void Cjt_Mensaje::addMensaje(Cjt_Alfabeto& alf)
{
	string nombre, a, msg;
	cin >> nombre;
	cin >> a;
	cout << " " << nombre << " " << a << endl;

	map <string, Alfabeto>::const_iterator itA;
	map <string, Mensaje>::const_iterator itM;
	itA = alf.findAlfabeto(a);
	getline(cin, msg);
	while (msg == "") {
		cin.clear();
		getline(cin, msg);
	}
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
	string nombre;
	cin >> nombre;
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
		cout << i << ". " << it->first << endl;
		it->second.imprimir();
		++it;
		++i;
	}
}

void Cjt_Mensaje::codificaSustGuardado(Cjt_Alfabeto& alf)
{
	string ident, clave, mensaje, alfabeto;
	cin >> ident;
	getline(cin, clave);
	while (clave == "") {
		cin.clear();
		getline(cin, clave);
	}
	cout << " " << ident << " \"" << clave << "\"" << endl;
	map<string, Mensaje>::iterator it = mensajes.find(ident);
	if (it == mensajes.end())
		cout << "error: el mensaje no existe" << endl;
	else {
		mensaje = it->second.mensajeTiene();
		alfabeto = alf.devolverAlf(it->second.alfabetoPertenece());
		if (alfabeto != "0" and alfabeto.size() > 1) {
			if (alf.devolverSpecial(it->second.alfabetoPertenece()))
				ecuacionEncriptarEspecial(mensaje, alfabeto, clave);
			else
				ecuacionEncriptar(mensaje, alfabeto, clave);
		}
		cout << "\"" << mensaje << "\"" << endl;
	}
}

void Cjt_Mensaje::codificaSustNoGuardado(Cjt_Alfabeto& alf)
{
	string ident, clave, mensaje, alfabeto;
	cin >> ident;
	getline(cin, clave);
	while (clave == "") {
		cin.clear();
		getline(cin, clave);
	}
	getline(cin, mensaje);
	while (mensaje == "") {
		cin.clear();
		getline(cin, mensaje);
	}
	cout << " " << ident << " \"" << clave << "\"" << endl;
	map<string, Alfabeto>::iterator it = alf.findAlfabeto(ident);
	if (it == alf.ultimaPos())
		cout << "error: el alfabeto no existe" << endl;
	else {
		alfabeto = it->second.returnAlf();
		if (alfabeto != "0" and alfabeto.size() > 1) {
			if (it->second.returnSpecial())
				ecuacionEncriptarEspecial(mensaje, alfabeto, clave);
			else
				ecuacionEncriptar(mensaje, alfabeto, clave);
		}
		cout << "\"" << mensaje << "\"" << endl;
	}
}

void Cjt_Mensaje::decodificaSust(Cjt_Alfabeto& alf)
{
	string ident, clave, mensaje, alfabeto;
	cin >> ident;
	getline(cin, clave);
	while (clave == "") {
		cin.clear();
		getline(cin, clave);
	}
	getline(cin, mensaje);
	while (mensaje == "") {
		cin.clear();
		getline(cin, mensaje);
	}
	cout << " " << ident << " \"" << clave << "\"" << endl;
	map<string, Alfabeto>::const_iterator it = alf.findAlfabeto(ident);
	if (it == alf.ultimaPos())
		cout << "error: el alfabeto no existe" << endl;
	else {
		alfabeto = alf.devolverAlf(ident);
		if (alfabeto != "0" and alfabeto.size() > 1) {
			if (alf.devolverSpecial(ident))
				ecuacionDesEncriptarEspecial(mensaje, alfabeto, clave);
			else
				ecuacionDesEncriptar(mensaje, alfabeto, clave);
		}
		cout << "\"" << mensaje << "\"" << endl;
	}
}

void Cjt_Mensaje::codificaPermGuardado()
{
	int bloque;
	string id, mensaje;

	cin >> id;
	cin >> bloque;
	cout << " " << id << " " << bloque << endl;
	map<string, Mensaje>::iterator it = mensajes.find(id);
	if (it == mensajes.end())
		cout << "error: el mensaje no existe" << endl;
	else {
		cout << "\"";
		mensaje = it->second.mensajeTiene();
		if (mensaje.size() < bloque)
			permutar(mensaje);
		else {
			vector<string> words;
			while (bloque < mensaje.size()) {
				words.push_back(mensaje.substr(0, bloque));
				mensaje.erase(0, bloque);
			}
			words.push_back(mensaje.substr(0, mensaje.size()));
			mensaje.erase(0, mensaje.size());
			for (int i = 0; i < words.size(); ++i) {
				permutar(words[i]);
			}
		}
		cout << "\"" << endl;
	}
}

void Cjt_Mensaje::codificaPermNoGuardado()
{
	int bloque;
	string mensaje, aux;

	cin >> bloque;
	cout << " " << bloque << endl;
	while (mensaje == "") {
		cin.clear();
		getline(cin, mensaje);
	}
	cout << "\"";
	if (mensaje.size() < bloque)
		permutar(mensaje);
	else {
		vector<string> words;
		while (bloque < mensaje.size()) {
			words.push_back(mensaje.substr(0, bloque));
			mensaje.erase(0, bloque);
		}
		words.push_back(mensaje.substr(0, mensaje.size()));
		mensaje.erase(0, mensaje.size());
		for (int i = 0; i < words.size(); ++i) {
			permutar(words[i]);
		}
	}
	cout << "\"" << endl;
}

void Cjt_Mensaje::decodificaPerm()
{
	int bloque;
	string mensaje, aux;

	cin >> bloque;
	cout << " " << bloque << endl;
	while (mensaje == "") {
		cin.clear();
		getline(cin, mensaje);
	}
	cout << "\"";
	if (mensaje.size() < bloque)
		permutar(mensaje);
	else {
		vector<string> words;
		while (bloque < mensaje.size()) {
			words.push_back(mensaje.substr(0, bloque));
			mensaje.erase(0, bloque);
		}
		words.push_back(mensaje.substr(0, mensaje.size()));
		mensaje.erase(0, mensaje.size());
		for (int i = 0; i < words.size(); ++i) {
			permutar(words[i]);
		}
	}
	cout << "\"" << endl;
}

void Cjt_Mensaje::ecuacionEncriptar(string& mensaje, string& alfabeto, string& clave)
{
	int i = 0;
	int x = -1, y = -1;
	for (int z = 0; i < mensaje.size(); z++)
	{
		if (mensaje[i] == alfabeto[z])
			x = z;
		if (clave[i%clave.size()] == alfabeto[z])
			y = z;
		if (x != -1 and y != -1) {
			x = (x + y) % alfabeto.size();
			mensaje[i] = alfabeto[x];
			x = -1;
			y = -1;
			z = -1;
			++i;
		}
	}
}

void Cjt_Mensaje::ecuacionEncriptarEspecial(string& mensaje, string& alfabeto, string& clave)
{
	int max = 0, min = 0, suma = 0;
	max = alfabeto[alfabeto.size() - 1];
	min = alfabeto[0];
	max -= min;
	for (int i = 0; i < mensaje.length(); i++)
	{
		suma = (mensaje[i] - min) + (clave[i % clave.size()] - min);
		if (suma > max)
			suma = (suma % max) - 1;
		else
			suma %= max;
		mensaje[i] = alfabeto[suma];
	}
}

void Cjt_Mensaje::ecuacionDesEncriptar(string& mensaje, string& alfabeto, string& clave)
{
	int i = 0;
	int x = -1, y = -1;
	for (int z = 0; i < mensaje.size(); z++)
	{
		if (mensaje[i] == alfabeto[z])
			x = z;
		if (clave[i % clave.size()] == alfabeto[z])
			y = z;
		if (x != -1 and y != -1) {
			if ((x - y) < 0)
				x = (x - y + alfabeto.size()) % alfabeto.size();
			else
				x = (x - y) % alfabeto.size();
			mensaje[i] = alfabeto[x];
			x = -1;
			y = -1;
			z = -1;
			++i;
		}
	}
}

void Cjt_Mensaje::ecuacionDesEncriptarEspecial(string& mensaje, string& alfabeto, string& clave)
{
	int max = 0, min = 0, suma = 0;
	max = alfabeto[alfabeto.size() - 1];
	min = alfabeto[0];
	max -= min;
	for (int i = 0; i < mensaje.length(); i++)
	{
		suma = (mensaje[i] - min) - (clave[i % clave.size()] - min);
		if (suma < 0)
			suma += alfabeto.size();
		if (suma > max)
			suma = (suma % max) - 1;
		else
			suma %= max;
		mensaje[i] = alfabeto[suma];
	}
}

void Cjt_Mensaje::permutar(string& mensaje) {
	BinTree<char> arbol;
	int i = (mensaje.size()-1) / 2 ;
	//if (mensaje.size() % 2 == 0)
		//--i;
	arbol = crear(mensaje, 0, mensaje.size()-1);
	arbol = cambiar(arbol, mensaje[i]);
	leer(arbol);
}

BinTree<char> Cjt_Mensaje::crear(string mensaje, int inferior, int superior) {
	BinTree<char> a;
	int i;
	if (inferior == superior)
		i = inferior;
	else
		i = inferior + (((superior) - inferior) / 2);
	if ((i >= inferior and i <= superior)/* and ((i != inferior or i == 0) and (i != superior or i == mensaje.size() - 1)) or superior == inferior*/) {
		BinTree<char> aLeft;
		BinTree<char> aRight;
		aLeft = BinTree<char>(crear(mensaje, inferior, i-1));
		aRight = BinTree<char>(crear(mensaje, i+1, superior));

		a  = BinTree<char>(mensaje[i], aLeft, aRight);
	}
	return a;
}

BinTree<char> Cjt_Mensaje::cambiar(BinTree<char> a, char hermano) {
	BinTree<char> aux, hijoI, hijoD;
	if (a.empty() or (a.left().empty() and a.right().empty()))
		return aux = BinTree<char>(hermano);
	else {
		if (a.left().empty() or a.right().empty()) {
			if (a.left().empty() and not a.right().empty()) {
				hijoD = BinTree<char>(a.right().value());

			}
			else if (a.right().empty() and not a.left().empty()) {
				hijoI = BinTree<char>(a.left().value());
			}
		}
		else {
			hijoI = cambiar(a.left(), a.right().value());
			hijoD = cambiar(a.right(), a.left().value());
		}
		aux = BinTree<char>(hermano, hijoI, hijoD);
	}
	return aux;
}


void Cjt_Mensaje::leer(BinTree<char> a) {
	if (not a.empty()){
		leer(a.left());
		cout << a.value();
		leer(a.right());
	}
}