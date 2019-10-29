
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
   cout << "________________________________________________________Estadistica___________________________________________________________\n\nTipo de Alimento: " << tipo << endl;
   cout << "Promedio +- Desviacion\n";
   cout << "Calorias        Hidratos de Carb        Proteinas       Grasas      Fibra"<<endl;
   cout << ingre_tipo.getMedia('C',tipo) << " +- " << ingre_tipo.getDesviacion('C',tipo) << "       ";
   cout << ingre_tipo.getMedia('H',tipo) << " +- " << ingre_tipo.getDesviacion('H',tipo) << "       ";
   cout << ingre_tipo.getMedia('P',tipo) << " +- " << ingre_tipo.getDesviacion('P',tipo) << "       ";
   cout << ingre_tipo.getMedia('G',tipo) << " +- " << ingre_tipo.getDesviacion('G',tipo) << "       ";
   cout << ingre_tipo.getMedia('F',tipo) << " +- " << ingre_tipo.getDesviacion('F',tipo) << "       \n"<<endl;
   cout << "Maximos Valores\n";
   cout << "Calorias (Alimento)       Hidratos de Carb (Alimento)        Proteinas (Alimento)       Grasas (Alimento)      Fibra (Alimento)"<<endl;
   cout << ingre_tipo.getMaximo('C',tipo).getCalorias() << " " << ingre_tipo.getMaximo('C',tipo).getNombre() << "       ";
   cout << ingre_tipo.getMaximo('H',tipo).getHc() << " " << ingre_tipo.getMaximo('H',tipo).getNombre() << "       ";
   cout << ingre_tipo.getMaximo('P',tipo).getProteinas() << " " << ingre_tipo.getMaximo('P',tipo).getNombre() << "       ";
   cout << ingre_tipo.getMaximo('G',tipo).getGrasas() << " " << ingre_tipo.getMaximo('G',tipo).getNombre() << "       ";
   cout << ingre_tipo.getMaximo('F',tipo).getFibra() << " " << ingre_tipo.getMaximo('F',tipo).getNombre() << "       "<<endl<<endl;
   cout << "Minimos Valores\n";
   cout << "Calorias (Alimento)       Hidratos de Carb (Alimento)        Proteinas (Alimento)       Grasas (Alimento)      Fibra (Alimento)"<<endl;
   cout << ingre_tipo.getMinimo('C',tipo).getCalorias() << " " << ingre_tipo.getMinimo('C',tipo).getNombre() << "       ";
   cout << ingre_tipo.getMinimo('H',tipo).getHc() << " " << ingre_tipo.getMinimo('H',tipo).getNombre() << "       ";
   cout << ingre_tipo.getMinimo('P',tipo).getProteinas() << " " << ingre_tipo.getMinimo('P',tipo).getNombre() << "       ";
   cout << ingre_tipo.getMinimo('G',tipo).getGrasas() << " " << ingre_tipo.getMinimo('G',tipo).getNombre() << "       ";
   cout << ingre_tipo.getMinimo('F',tipo).getFibra() << " " << ingre_tipo.getMinimo('F',tipo).getNombre() << "       "<<endl;


}
