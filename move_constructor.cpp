#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
 
struct A
{
    std::string s;
    int k;
    A() : s("test"), k(-1) { }
    A(const A& o) : s(o.s), k(o.k) { std::cout << "movimiento fallido! \n"; }
    A(A&& o) noexcept :
           s(std::move(o.s)),      // movimiento explícito de un miembro de tipo de clase
           k(std::exchange(o.k, 0)) // movimiento explícito de un miembro de tipo no clase
    { }
};
 
A f(A a)
{
    return a;
}
 
struct B : A
{
    std::string s2;
    int n;
    /* constructor de movimiento implícito B: :( B &&)
    llama al constructor de movimientos de A
    llama al constructor de movimiento de s2
    y hace una copia bit a bit de n*/
};
 
struct C : B
{
    ~C() { } // destructor evita el movimiento implícito del constructor C: :( C &&)
};
 
struct D : B
{
    D() { }
    ~D() { }          // destructor evitaría el movimiento implícito del constructor D: :( D &&)
    D(D&&) = default; // obliga a un constructor de movimiento de todos modos
};
 
int main()
{
    std::cout << "Intentando mover A\n";
    A a1 = f(A()); // retorno por valor move-constructs el objetivo del parámetro de función
    std::cout << "Antes de mover, a1.s = " << std::quoted(a1.s) << " a1.k = " << a1.k << '\n';
    A a2 = std::move(a1);// move-constructs desde xvalue
    std::cout << "Despues de mover, b1.s =" << std::quoted(a1.s) << " a1.k = " << a1.k << '\n';
 
    std::cout << "Intentando mover B \n";
    B b1;
    std::cout << "Antes de mover, b1.s =" << std::quoted(b1.s) << "\n";
    B b2 = std::move(b1);// llama al constructor de movimiento implícito
    std::cout << "Despues de mover, b1.s =" << std::quoted(b1.s) << "\n";
 
    std::cout << "Intentando mover C\n";
    C c1;
    C c2 = std::move(c1); // llama al constructor de copia
 
    std::cout << "Intentando mover D\n";
    D d1;
    D d2 = std::move(d1);
}
