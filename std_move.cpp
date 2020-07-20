#include <iostream> 
#include <vector> 
 
int main ( ) 
{ 
    std :: string str =  "Hola" ; 
    std :: vector < std :: string > v ;
 
    // usa la sobrecarga push_back (const T &), lo que significa 
    // incurriremos en el costo de copiar str 
    v. push_back ( str ) ; 
    std :: cout  <<  "Después de la copia, str es \" "  << str <<  " \ " ;
 
    /* usa la sobrecarga de referencia de valor de retroceso (T &&) rvalue, 
    lo que significa que no se copiarán cadenas; en su lugar, el contenido 
    de str se moverá al vector. Esto es menos 
    costoso, pero también significa que str podría estar ahora vacío. */
    v. push_back ( std :: move ( str ) ) ; 
    std :: cout  <<  "Después de mover, str es \" "  << str <<  " \ "  ;
 
    std :: cout  <<  "El contenido del vector es \" "  << v [ 0 ] 
                                         <<  " \ " , " "  << v [ 1 ]  <<  " \ "  ; 
}
