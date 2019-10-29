
#include <iostream>
#include "ingrediente.h"
#include "ingredientes.h"
#include "vector_dinamico.cpp"
#include <fstream>
using namespace std;
void MuestraParametros(){
	
	cout<<"1.- Dime el nombre del fichero con los ingredientes 2.- Dime el tipo de ingrediente"<<endl;
}

int main(int argc, char *argv[])
{
  if (argc!=3){
	  MuestraParametros();
	  return 0;
 }	
 /******************************************************************************************/	

 string nf =argv[1];
 ifstream f(nf);
 if (!f){
    cout<<"No puedo abrir "<<nf<<endl;
    return 0;
 }
 
 cout<<"\n Pulsa una tecla para continuar...."<<endl;
 cin.get();
 /******************************************************************************************/

 f.seekg(0);
 ingredientes all_ingre;
 cout<<"Lectura de todos los ingredientes"<<endl;
 f>>all_ingre;

  /******************************************************************************************/

   vector_dinamico<string> tipos=all_ingre.getTipos();
   cout<<"Los tipos de alimentos son:"<<endl;
   for (int i=0;i<tipos.size(); ++i){
      cout<<tipos[i]<<endl;
   }
   cout<<"Pulse una tecla para continuar "<<endl;
   cin.get();
  
   string tipo=argv[2]; //ingredientes.txt ha sido creado en windows e incluye el /r tras cada final de linea
   ingredientes ingre_tipo=all_ingre.getIngredienteTipo(tipo);
   cout<<"Los ingredientes de tipo "<<tipo<<" son: "<<endl<<ingre_tipo<<endl;
   
   /******************************************************************************************/
   
   cout << "MEDIA: " << ingre_tipo.getMedia('H',tipo) << endl;
   cout << "\nDESVIACION: " << ingre_tipo.getDesviacion('H',tipo) << endl << endl;
   cout << ingre_tipo.getMaximo('H',tipo) << endl;
   cout << ingre_tipo.getMinimo('H',tipo) << endl;
   

}
