#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <Windows.h>

using namespace std;

void searchWord(const string& archivo, const string& palabra) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo " << archivo << endl;
        return;
    }

    // Obtener el color predeterminado de la consola
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    WORD defaultColor = csbi.wAttributes;

    // Buscar la palabra en el archivo
    int countlineconcidencias = 0;
    int count = 0;
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(palabra);
        if (pos != string::npos) {
            countlineconcidencias++;
            while (pos != string::npos) {
                cout << line.substr(0, pos);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << line.substr(pos, palabra.length());
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultColor);
                line = line.substr(pos + palabra.length());
                pos = line.find(palabra);
                count++;
            }
            cout << line << endl;
        }
    }

    if (count == 0) {
        cout << "No se encontraron coincidencias" << endl;
    } else {
        cout << "Se encontraron " << count << " coincidencias" << endl;
        cout << "Se encontraron " << countlineconcidencias << " lineas con coincidencias" << endl;
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Uso: Minigrep <archivo> <palabra>" << endl;
        return 1;
    }

    string archivo = argv[1];
    string palabra = argv[2];

    searchWord(archivo, palabra);

    return 0;
}