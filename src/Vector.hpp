#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include <iostream>
#define MAX_DIM 100




class Vector {
    friend Vector operator*(float scalar, const Vector &v);
    friend std::ostream& operator<<(std::ostream &out, const Vector &v);
    friend std::istream& operator>>(std::istream &in, Vector &v);
public:
    // Un constructor que no recibe parametros es un constructor por Default
    Vector();
    explicit Vector(short dim);
    Vector(short dim, float valor);

    void setDim(short dim);
    int getDim() const;

    void setEnter(int i, float valor);
    float & operator[](int i);
    float getEnter(int i) const;
    float operator[](int i) const;

    void printDim() const;
    void capture();

    //Tarea Suma de dos vectores el & es para pasar por referencia y no por valor
    Vector sumVectors(const Vector &v2) const;
    // Sobrecarga del operador +
    Vector operator+(const Vector &v2) const;

    //Resta de dos vectores
    Vector restVectors(const Vector &b) const;
    // Sobrecarga del operador -
    Vector operator-(const Vector &b) const;

    // Producto escalar
    float scaleProduct(const Vector &b) const;
    // Sobrecarga del operador *
    float operator*(const Vector &b) const;
    Vector scaleProduct(float scalar);

    // Magnitud del vector
    float obtenerMagnitud() const;

    Vector & operator++();
    Vector operator++(int);


private:
    short dim;
    float *enter;

};

#endif 