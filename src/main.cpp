#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
    try {
        short dim;

        Vector v;
        Vector v2;

        v.printDim();

        cout << "Set dimension of the vector 1: ";
        cin >> dim;
        v.setDim(dim);
        cout << endl;
        cout << "Set dimension of the vector 2: ";
        cin >> dim;
        v2.setDim(dim);
        cout << endl;

        cout << "Please enter the elements of the first vector:" << endl;
        v.capture();

        cout << "Please enter the elements of the second vector:" << endl;
        v2.capture();

        v2.setEnter(0, 10.0f);  // Example of using setEnter
        // cout << "The sum of the vectors is: ";
        // v.sumVectors(v2).printDim();
        // cout << endl;

        // cout << "The rest of the vectors is: ";
        // v.restVectors(v2).printDim();
        // cout << endl;

        // cout << "And the scalar product is: ";
        // cout << v.scaleProduct(v2);
        // cout << endl;

        cout << "The magnitude of the first vector is: ";
        cout << v.obtenerMagnitud() << endl;

        Vector s;

        s = v + v2;
        cout << "The sum using operator overloading is: ";
        s.printDim();
        cout << endl;

        s = v - v2;
        cout << "The rest using operator overloading is: ";
        s.printDim();
        cout << endl;

        float scalarProduct = v * v2;
        cout << "The scalar product using operator overloading is: ";
        cout << scalarProduct << endl;

        // Multiplication by a scalar using friend function using variable scalarProduct
        Vector scaledVector = scalarProduct * v;
        cout << "The first vector multiplied by scalar " << scalarProduct << " is: ";
        scaledVector.printDim();
        cout << endl;
        
        cout << "Try the increment operator on the first vector: " << endl;
        ++v = s;
        v.printDim();
        cout << endl;


    }catch(const char* msg) {
        cerr << "Error: " << msg << endl;
    }catch(...) {
        cerr << "Unknown error" << endl;
    }


    return 0;
}
