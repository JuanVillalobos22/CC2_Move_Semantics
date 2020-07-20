#include <iostream>
using namespace std;

// Una clase que contiene un recurso de memoria.
class MemoryBlock
{
   // TODO: agregue recursos para la clase aqu�.
};

void f(const MemoryBlock&)
{
   cout << "En f (const MemoryBlock y). Esta versi�n no puede modificar el par�metro." << endl;
}

void f(MemoryBlock&&)
{
   cout << "En f (MemoryBlock &&). Esta versi�n puede modificar el par�metro." << endl;
}

int main()
{
   MemoryBlock block;
   f(block);
   f(MemoryBlock());
}
