#include <string>
#include <iostream>
#include <utility>
 
struct A
{
    std::string s;
    A() : s("test") { }
    A(const A& o) : s(o.s) { std::cout << "movimiento fallido!\n"; }
    A(A&& o) : s(std::move(o.s)) { }
    A& operator=(const A& other)
    {
         s = other.s;
         std::cout << "copia asignada\n";
         return *this;
    }
    A& operator=(A&& other)
    {
         s = std::move(other.s);
         std::cout << "movimiento asignado\n";
         return *this;
    }
};
 
A f(A a) { return a; }
 
struct B : A
{
     std::string s2; 
     int n;
    /* operador de asignaci�n de movimiento impl�cito B & B :: operator = (B &&)
    llama al operador de asignaci�n de movimiento de A
    llama al operador de asignaci�n de movimiento de s2
    y hace una copia bit a bit de n*/
};
 
struct C : B
{
    ~C() { } // El destructor evita la asignaci�n de movimiento impl�cito
};
 
struct D : B
{
    D() { }
    ~D() { } // destructor evitar�a la asignaci�n de movimiento impl�cita
    D& operator=(D&&) = default; // forzar una asignaci�n de movimiento de todos modos
};
 
int main()
{
    A a1, a2;
    std::cout << "Intentando mover o asignar 'A' desde rvalue temporal\n";
    a1 = f(A()); // mover-asignaci�n de rvalue temporal
    std::cout << "Intentando mover o asignar 'A' desde xvalue\n";
    a2 = std::move(a1); // mover-asignaci�n de xvalue
 
    std::cout << "intentando movero o asignar B\n";
    B b1, b2;
    std::cout << "Antes de mover, b1.s = \"" << b1.s << "\"\n";
    b2 = std::move(b1); // llama a la asignaci�n de movimiento impl�cita
    std::cout << "Despu�s del movimiento, b1.s = \"" << b1.s << "\"\n";
 
    std::cout << "Intentando mover o asignar C\n";
    C c1, c2;
    c2 = std::move(c1); // llama al operador de asignaci�n de copias
 
    std::cout << "Intentando mover o asignar D\n";
    D d1, d2;
    d2 = std::move(d1);
}
