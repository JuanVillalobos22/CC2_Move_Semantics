#include <iostream>
using namespace std;

// Una clase que contiene un recurso de memoria.
class MemoryBlock
{
   // TODO: agregue recursos para la clase aquí.
};

void f(const MemoryBlock&)
{
   cout << "En f (const MemoryBlock y). Esta versión no puede modificar el parámetro." << endl;
}

void f(MemoryBlock&&)
{
   cout << "En f (MemoryBlock &&). Esta versión puede modificar el parámetro." << endl;
}

int main()
{
   MemoryBlock block;
   f(block);
   f(MemoryBlock());
}
