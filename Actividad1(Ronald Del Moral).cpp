#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

    //Declaracion de funciones a usar
bool EsNum(const string& str) {
    stringstream ss(str);
    double num;
    return (ss >> num) && ss.eof();
}

double CadenaANumero(const string& str) {
    stringstream ss(str);
    double num;
    ss >> num;
    return num;
}

int main() {

    //introducir la direccion del archivo
    ifstream archivo("c:/Users/PC/OneDrive/Documentos/P2 codes/actividad 1/datos.txt");

    // Comprobacion de apertura de archivos
    if (!archivo) {
        cout << "No se encontro el archivo solicitado" << endl;
        return -1;
    }

    string linea;
    double suma = 0.0;
    int contador = 0;

    while (getline(archivo, linea)) {
        if (EsNum(linea)) {
            suma += CadenaANumero(linea);
            cout << "linea: " << linea << endl;
            contador++;
        } else {
            cerr << "Error: \"" << linea << "\" caracter(es) no valido(s)." << endl;
        }
    }

    archivo.close();

    // Función para sacar la media:
    if (contador > 0) {
        double media = suma / contador;
        cout << "La media de los números es: " << media << endl;
    } else {
        cout << "No hay números validos en el archivo." << endl;
    }

    return 0;
}