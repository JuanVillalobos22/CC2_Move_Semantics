#include <iostream>
int main()
{
    int i, j, *p;
	// Uso correcto: la variable i es un lvalue y el literal 7 es un prvalue.
    i = 7;
	
	// Uso incorrecto: el operando izquierdo debe ser un lvalue (C2106) .`j * 4` es un prvalue.
    7 = i; // C2106
    j * 4 = 7; // C2106

    // Uso correcto: el puntero desreferenciado es un lvalue.
    *p = i;

	// Uso correcto: el operador condicional devuelve un lvalue.
    ((i < 3) ? i : j) = 7;

	// Uso incorrecto: la constante ci es un lvalue no modificable (C3892).
    const int ci = 7;
    ci = 9; // C3892
}
