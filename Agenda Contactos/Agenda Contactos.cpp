#include<iostream>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<string> 
using namespace std;
void pantalla_principal_inicio(string nombres[]);//accede a los datos personales
void upper(string& cadena);//convierte de minusculas a mayusculas
void lower(string& cadena);//convierte de mayusculas a minusculas
void menu();//menú de la agenda
void cargar(string contactos[20][4], int x, int y);//accede a la matriz de contactos para agregar nuevos
void datos_personales(string personal[]);
bool validar_numero(string cadena);  //valida solo númericos
bool validar_nombre(string cadena);//valida solo caracteres alfabéticos 
bool validar_apellido(string cadena); //valida solo caracteres alfabéticos 
bool validar_correo(string cadena);//valida el correo electronico debe contener "@"
int codigo();//generados de números aleatorios
int main() {
	int opc, x = 0, y = 0, z = 0, cod;
	string nombre, apellido, celular, correo;
	string nombres[4];
	string personal[7];
	int codigo_id[20];
	int buscar;
	pantalla_principal_inicio(nombres);
	system("cls");
	datos_personales(personal);
	string contactos[40][4];
	do {
		menu();
		cin >> opc;
		if (opc == 1) {//muestra los datos personales de la agenda
			string datos[7] = { "Universidad :    ","Facultad :       ","Direccion:       ","Ciudad :         ","Telefono :       ","Celular :        ","E-mail :         " };
			cout << "\t\n\tDatos Informativos\n\nNombre completo :" << nombres[0] << " " << nombres[1] << " " << nombres[2] << " " << nombres[3] << endl;
			for (int i = 0; i < 7; i++) {
				cout << datos[i] << personal[i] << endl;
			}
			system("pause");
			system("cls");
		}
		else if (opc == 2) {//agrega nuevos contactos a la agenda
			cout << "Crear contactos " << endl;
			cargar(contactos, x, y);
			codigo_id[x] = codigo();
			z++;
			y++;
			system("pause");
			system("cls");
		}
		else if (opc == 3) {//podemos visualizar los contactos en la matriz
			cout << "\tVer contactos " << endl << "\tCodigo     Nombre    Apellido Numero     E - mail			" << endl;
			for (int i = 0; i < y; i++) {
				cout << i + 1 << ".-     " << codigo_id[i] << "  ";
				for (int j = 0; j < 4; j++) {
					cout << "\t" << contactos[i][j] << " ";
				}
				cout << endl;
			}
			system("pause");
			system("cls");
		}
		else if (opc == 4) {//buscador de la agendo por medio del código aleatorio
			bool valid = false;
			int pos;
			cout << "Buscar contactos ";
			cin >> buscar;
			for (int i = 0; i < z; i++) {
				if (buscar == codigo_id[i]) {
					valid = true;
					pos = i;
				}
			}
			if (valid == true) {
				cout << "Codigo     Nombre    Apellido Numero     E - mail			" << endl;
				for (int i = 0; i < 4; i++) {

					cout << contactos[pos][i] << "  ";
				}
			}
			else {
				cout << "no se encontro";
			}
			system("pause");
			system("cls");
		}
	} while (opc != 5);
	system("pause");
	return 0;
}
void pantalla_principal_inicio(string nombres[]) {
	printf("\n\t\t\t\t\t\t\tAgenda\t\t\t\t\t\t\t\t\n");
	int i = 0;
	while (i < 2) {
		cout << "\t\t\tIngrese nombre " << i + 1 << " : ";
		cin >> nombres[i]; i++;
	}
	while (i < 4) {
		cout << "\t\t\tIngrese apellido " << i - 1 << " : "; cin >> nombres[i]; upper(nombres[i]);
		i++;
	}
	system("cls");
	cout << "\n\n\t\t\t\t\tEsta libreta pertenece a\n\n\t\t\t\t\t     " << nombres[0] << " " << nombres[2] << "\n" << "\n\t\t\t\t\t\tContinuar";
	system("pause");
}
void lower(string& cadena) {
	int i = 0;
	for (int i = 0; i < cadena.length(); i++) {
		cadena[i] = tolower(cadena[i]);
	}
}
void upper(string& cadena) {
	int i = 0;
	for (int i = 0; i < cadena.length(); i++) {
		cadena[i] = toupper(cadena[i]);
	}
}
void menu() {
	cout << "1.- Datos personales\n2.- Cargar contactos a la agenda\n3.- Ver contactos\n4.- Buscar contactos\n\tselecione :  ";
}
void datos_personales(string personal[]) {
	int op;
	string dir;
	string facultades[14] = { "Arquitectura","Diseño y Artes","Ciencias Administrativas y Contables","Ciencias de la Educación","Ciencias Humanas","Enfermería","Comunicación","Lingüística y Literatura","Economía","Ingeniería","Jurisprudencia","Medicina","Psicología","Campo vacio" };
	printf("\n Datos Personales\n\n Universidad : ");
	cin >> personal[0];
	upper(personal[0]);
	printf(" Seleccione Facultad\n 1.- Arquitectura\n 2.- Diseño y Artes\n 3.- Ciencias Administrativas y Contables\n 4.- Ciencias de la Educación\n 5.- Ciencias Humanas\n 6.- Enfermería\n 7.- Comunicación\n 8.- Lingüística y Literatura\n 9.- Economía\n 10.- Ingeniería\n 11.- Jurisprudencia\n 12.- Medicina\n 13.- Psicología\nSeleccione :  ");
	cin >> op;
	switch (op) {
	case 1:personal[1] = facultades[0];
		break;
	case 2:personal[1] = facultades[1];
		break;
	case 3:personal[1] = facultades[2];
		break;
	case 4:personal[1] = facultades[3];
		break;
	case 5:personal[1] = facultades[4];
		break;
	case 6:personal[1] = facultades[5];
		break;
	case 7:personal[1] = facultades[6];
		break;
	case 8:personal[1] = facultades[7];
		break;
	case 9:personal[1] = facultades[8];
		break;
	case 10:personal[1] = facultades[9];
		break;
	case 11:personal[1] = facultades[10];
		break;
	case 12:personal[1] = facultades[11];
		break;
	case 13:personal[1] = facultades[12];
		break;
	default:
		personal[1] = facultades[13];
	}
	cout << "Ingrese dirección : ";
	cin >> dir;
	personal[2] = dir;
	system("cls");
	string ciudad = "";
	bool band = false, band1 = false, band2 = false, band3 = false;
	while (band == false) {
		cout << "ingrese ciudad : ";
		cin >> ciudad;
		lower(ciudad);
		if (validar_nombre(ciudad) == true) band = true;
	}
	upper(ciudad);
	personal[3] = ciudad;
	if (band == true) {
		string telefono_fijo = "";
		while (band1 == false) {
			cout << "ingrese telefono fijo (numerico) : ";
			cin >> telefono_fijo;
			lower(telefono_fijo);
			if (validar_numero(telefono_fijo) == true) band1 = true;
		}
		personal[4] = telefono_fijo;
	}
	if (band1 == true) {
		string telefono_celular = "";
		while (band2 == false) {
			cout << "ingrese celular fijo (numerico) : ";
			cin >> telefono_celular;
			lower(telefono_celular);
			if (validar_numero(telefono_celular) == true) band2 = true;
		}
		personal[5] = telefono_celular;
		if (band2 == true) {
			string correo = "";
			while (band3 == false) {
				cout << "ingrese correo debe contener @ : ";
				cin >> correo;
				lower(correo);
				if (validar_correo(correo) == true) band3 = true;
			}
			personal[6] = correo;
		}
	}
}
bool validar_numero(string cadena) {
	char val[] = "0123456789";
	int c = 0;
	bool band = false;
	for (int i = 0; i < cadena.length(); i++) {
		for (int j = 0; j < 10; j++) {
			if (cadena[i] == val[j]) {
				c++;
				break;
			}
		}
	}
	if (c == cadena.length())return true;
	return band;
}
bool validar_nombre(string cadena) {
	char val[] = " abcdefghijklmnosqprstuvwxyzáéíóú";
	int c = 0;
	bool band = false;
	for (int i = 0; i < cadena.length(); i++) {
		for (int j = 0; j < strlen(val); j++) {
			if (cadena[i] == val[j]) {
				c++;
				break;
			}
		}
	}
	if (c == cadena.length())return true;
	return band;
}
bool validar_apellido(string cadena) {
	char val[] = "abcdefghijklmnñosprstuvwxyzáéíóú";
	int c = 0;
	bool band = false;
	for (int i = 0; i < cadena.length(); i++) {
		for (int j = 0; j < strlen(val); j++) {
			if (cadena[i] == val[j]) {
				c++;
				break;
			}
		}
	}
	if (c == cadena.length())return true;
	return band;
}
bool validar_correo(string cadena) {
	char val = '@';
	int i = 0;
	bool band = false;
	while (i < cadena.length()) {
		if (cadena[i] == val) {
			band = true;
			break;
		}
		i++;
	}
	return band;
}
void cargar(string contactos[20][4], int x, int y) {
	string nombre, apellido, numero, email, cod1;
	x = 0;
	bool band = false, band1 = false, band2 = false, band3 = false;
	while (band == false) {
		cout << "Ingrese nombre: "; cin >> nombre;
		lower(nombre);
		if (validar_nombre(nombre) == true)band = true;
	}
	upper(nombre);
	contactos[y][x] = nombre; x++;
	if (band == true) {
		while (band1 == false) {
			cout << "Ingrese apellido: "; cin >> apellido;
			lower(apellido);
			if (validar_apellido(apellido) == true)band1 = true;
		}
	}
	upper(apellido);
	contactos[y][x] = apellido; x++;
	if (band1 == true) {
		while (band2 == false) {
			cout << "Ingrese numero: "; cin >> numero;
			if (validar_numero(numero) == true)band2 = true;
		}
	}
	contactos[y][x] = numero; x++;
	if (band2 == true) {
		while (band3 == false) {
			cout << "Ingrese E-mail: "; cin >> email;
			lower(email);
			if (validar_correo(email) == true)band3 = true;
		}

	}
	lower(email);
	contactos[y][x] = email;
}
int codigo() {
	srand(time(NULL));
	int cod;
	cod = (rand() % (9999)) + 1000;
	return cod;
}