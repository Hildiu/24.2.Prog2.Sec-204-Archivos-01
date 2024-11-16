#include <iostream>
#include <fstream>
using namespace std;

int main()
{ int n;

    cout << "Cuantos numeros quieres grabar: ";
    cin >> n;

    srand(time(nullptr));
    fstream miArchivo("numeros.txt", ios::out);
    for(int i=0; i<n; i++)
        miArchivo << rand() % 100 << "\n";
    miArchivo.close();

    //----- ahora vamos a leer datos del archivo numeros.txt y luego
    //---- se van a genera dos nuevos archivos
    //---- pares.txt que va a contener solo los numeros pares del archivo numeros.txt
    //---- impares.txt que va a contener solo los numreos impares del archivo numeros.txt

    fstream  aFuente("numeros.txt", ios::in);   //-- se abre en el modo de lectura
    fstream  aDePares("pares.txt", ios::out);  //--- abre el archivo en el modo de escritura
    fstream  aDeImpares( "impares.txt", ios::out); //-- se abre el archivo en el modo de escritura
    int unNumero;
    while(aFuente >> unNumero)
        if(unNumero % 2 ==0)
            aDePares << unNumero << "\n";
        else
            aDeImpares << unNumero << "\n";

   aFuente.close();
   aDePares.close();
   aDeImpares.close();
    return 0;
}
