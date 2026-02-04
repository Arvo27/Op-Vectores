#include <iostream>
#include <iomanip> // Para dar formato a decimales si fuera necesario
#include "Vector.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

void imprimirSeparador() {
    cout << "\n------------------------------------------------\n";
}

int main() {
    try {
        short dim1, dim2;

        //datos
        cout << "Dimension del Vector 1: ";
        if (!(cin >> dim1)) throw "Entrada no valida para dimension";
        Vector v1(dim1);
        v1.capture();

        cout << "\nDimension del Vector 2: ";
        if (!(cin >> dim2)) throw "Entrada no valida para dimension";
        Vector v2(dim2);
        v2.capture();

        v2.setEnter(0, 10.0f);

        imprimirSeparador();

        // salidasds
        cout << "ESTADO INICIAL:\n";
        cout << "V1: " << v1 << "\n";
        cout << "V2: " << v2 << " (Modificado index 0 a 10.0)\n";

        imprimirSeparador();
        cout << "OPERACIONES ARITMETICAS:\n";

        // Suma
        Vector suma = v1 + v2;
        cout << "Suma (V1 + V2):      " << suma << "\n";

        // Resta
        Vector resta = v1 - v2;
        cout << "Resta (V1 - V2):     " << resta << "\n";

        // Producto Escalar
        float pEscalar = v1 * v2;
        cout << "Producto Escalar:    " << pEscalar << "\n";

        // Magnitud
        cout << "Magnitud de V1:      " << v1.obtenerMagnitud() << "\n";

        imprimirSeparador();
        cout << "OPERACIONES AVANZADAS:\n";

        // Escalado usando el producto escalar previo
        Vector escalado = pEscalar * v1;
        cout << "Escalado (V1 * " << pEscalar << "): " << escalado << "\n";

        // Demostracion de incremento
        cout << "Pre-incremento (++V1): ";
        cout << ++v1 << "\n";

        //Probando operador << y >>
        Vector v3;
        cout << "Ingrese los elementos para un nuevo vector V3 de dimension " << dim1 << ":\n";
        cin >> v3;
        cout << "Vector V3 ingresado: " << v3 << "\n";


        // Probando la funcion redimensionar
        short newDim;
        cout << "Ingrese la nueva dimension para redimensionar V3: ";
        if (!(cin >> newDim)) throw "Entrada no valida para dimension";
        Vector v3Redimensionado = v3.redimensionar(newDim);
        cout << "V3 redimensionado: " << v3Redimensionado << "\n";
    } catch (const char* msg) {
        cerr << "\n[ERROR DE LOGICA]: " << msg << endl;
    }/* catch (std::bad_alloc& e) {
        cerr << "\n[ERROR DE MEMORIA]: " << e.what() << endl;
    }*/catch (...) {
        cerr << "\n[ERROR]: Ocurrio una excepcion inesperada." << endl;
    }

    return 0;
}