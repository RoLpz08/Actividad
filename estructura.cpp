#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Dot {
    float x;
    float y;
    float z;

    Dot(float x, float y, float z) : x(x), y(y), z(z) {}
};

float calcularDistancia(Dot p1, Dot p2) { 
    float x1 = p1.x;
    float y1 = p1.y;
    float z1 = p1.z;
    float x2 = p2.x;
    float y2 = p2.y;  
    float z2 = p2.z;
    
    float dx = x2 - x1;
    float dy = y2 - y1;
    float dz = z2 - z1;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

Dot calcularSumaVectores(Dot v1, Dot v2) {
    return Dot(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Dot calcularVectorResultante(vector<Dot> vectores) {
    Dot resultado(0.0, 0.0, 0.0);
    for (const auto& vector : vectores) {
        resultado.x += vector.x;
        resultado.y += vector.y;
        resultado.z += vector.z;
    }
    return resultado;
}

float productoEscalar(Dot v1, Dot v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Dot productoCruz(Dot v1, Dot v2) {
    return Dot(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

void imprimirVector(Dot vector) {
    cout << "Vector: " << vector.x << "i + " << vector.y << "j + " << vector.z << "k";
    
    if (vector.x == 0 && vector.y == 0) {
        cout << " (plano XZ)" << endl;
    } else if (vector.x == 0 && vector.z == 0) {
        cout << " (plano XY)" << endl;
    } else if (vector.y == 0 && vector.z == 0) {
        cout << " (plano YZ)" << endl;
    } else if (vector.x == 0) {
        cout << " (en el eje X)" << endl;
    } else if (vector.y == 0) {
        cout << " (en el eje Y)" << endl;
    } else if (vector.z == 0) {
        cout << " (en el eje Z)" << endl;
    } else if (vector.x != 0 && vector.y != 0 && vector.z != 0) {
        cout << " (en el plano XY)" << endl;
    } else if (vector.x != 0 && vector.y != 0) {
        cout << " (en el plano XZ)" << endl;
    } else if (vector.x != 0 && vector.z != 0) {
        cout << " (en el plano YZ)" << endl;
    } else {
        cout << " (no se encuentra en un plano específico)" << endl;
    }
}

void resolverSistemaFuerzas(vector<Dot> fuerzas) {
    Dot resultado = calcularVectorResultante(fuerzas);
    cout << "El vector resultante del sistema de fuerzas es: ";
    imprimirVector(resultado);
}
int main() {

    cout << "Con cuantas dimensiones se hara el sistema de fuerzas?" << endl;
    int dimensiones;
    cin >> dimensiones;

    if (dimensiones != 3 && dimensiones != 2) {
        cout << "La dimención no es valida" << endl;
        return 0;
    }

    if (dimensiones == 3) {
        cout << "Ingresa el valor de x1: ";
        float x1;
        cin >> x1;

        cout << "Ingresa el valor de y1: ";
        float y1;
        cin >> y1;

        cout << "Ingresa el valor de z1: ";
        float z1;
        cin >> z1;

        cout << "Ingresa el valor de x2: ";
        float x2;
        cin >> x2;

        cout << "Ingresa el valor de y2: ";
        float y2;
        cin >> y2;

        cout << "Ingresa el valor de z2: ";
        float z2;
        cin >> z2;

        Dot punto1(x1, y1, z1);
        Dot punto2(x2, y2, z2);

        float distancia = calcularDistancia(punto1, punto2);
        cout << "La distancia entre los puntos es: " << distancia << endl;

        Dot sumaVectores = calcularSumaVectores(punto1, punto2);
        cout << "El vector resultante de la suma de los dos vectores es: ";
        imprimirVector(sumaVectores);

        vector<Dot> vectores = {Dot(x1, y1, z1), Dot(x2, y2, z2)};
        Dot vectorResultante = calcularVectorResultante(vectores);
        cout << "El vector resultante del arreglo de vectores es: ";
        imprimirVector(vectorResultante);

        Dot v1(x1, y1, z1);
        Dot v2(x2, y2, z2);
        float escalar = productoEscalar(v1, v2);
        cout << "El producto escalar de los vectores es: " << escalar << endl;

        Dot cruz = productoCruz(v1, v2);
        cout << "El producto cruz de los vectores es: ";
        imprimirVector(cruz);

        vector<Dot> fuerzas = {Dot(x1, y1, z1), Dot(x2, y2, z2), };
        resolverSistemaFuerzas(fuerzas);
        cout << "\n El sistema de fuerzas se resolvio correctamente" << endl;

    }

    if (dimensiones == 2) {
        cout << "Ingresa el valor de x1: ";
        float x1;
        cin >> x1;

        cout << "Ingresa el valor de y1: ";
        float y1;
        cin >> y1;

        cout << "Ingresa el valor de x2: ";
        float x2;        
        cin >> x2;  

        cout << "Ingresa el valor de y2: ";
        float y2;        
        cin >> y2;

        Dot punto1(x1, y1, 0.0f);
        Dot punto2(x2, y2, 0.0f);

        float distancia = calcularDistancia(punto1, punto2);
        cout << "La distancia entre los puntos es: " << distancia << endl;

        Dot sumaVectores = calcularSumaVectores(punto1, punto2);
        cout << "El vector resultante de la suma de los dos vectores es: ";
        imprimirVector(sumaVectores);

        vector<Dot> vectores = {Dot(x1, y1, 0.0f), Dot(x2, y2, 0.0f)};
        Dot vectorResultante = calcularVectorResultante(vectores);
        cout << "El vector resultante del matriz de vectores es: ";
        imprimirVector(vectorResultante);

        Dot v1(x1, y1 , 0.0f);
        Dot v2(x2, y2 , 0.0f);
        float escalar = productoEscalar(v1, v2);
        cout << "El producto escalar de los vectores es: " << escalar << endl;

        vector<Dot> fuerzas = {Dot(x1, y1, 0.0f), Dot(x2, y2, 0.0f)};
        resolverSistemaFuerzas(fuerzas);
        cout << "\n El sistema de fuerzas se resolvio correctamente" << endl; 
    }
    return 0;
}