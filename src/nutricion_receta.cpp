#include <iostream>
#include "receta.h"
#include "recetas.h"
#include "ingredientes.h"
#include <fstream>
using namespace std;
int main(int argc,char *argv[]){
  if (argc!=4){
    cout<<"Dime el fichero con las recetas, el de los ingredientes y un número de calorias máximas"<<endl;
    return 0;
  
  }
    
  ifstream f(argv[1]);
  ifstream d(argv[2]);
  
  if (!f){
	  cout<<"No existe el fichero "<<endl;
  }

  recetas rall;
  f>>rall;
  
  ingredientes iall;
  d>>iall;
  
  float calorias, hc, grasas, proteinas, fibra;

  
  for(recetas::iterator it=rall.begin(); it!=rall.end(); it++){
      calorias=0;
      hc=0;
      grasas=0;
      proteinas=0;
      fibra=0;
      for(receta::iterator its=it->second.begin(); its!=it->second.end(); its++){
          ingrediente i= iall.get(its->first);
          calorias+=i.getCalorias()*its->second/100;
          hc+=i.getHc()*its->second/100;
          grasas+=i.getGrasas()*its->second/100;
          proteinas+=i.getProteinas()*its->second/100;
          fibra+=i.getFibra()*its->second/100;
      }
      
      it->second.setCalorias(calorias);
      it->second.setHc(hc);
      it->second.setGrasas(grasas);
      it->second.setProteinas(proteinas);
      it->second.setFibra(fibra);
      
      cout << "Valores Nutricionales de la receta " << it->first << endl;
      cout << it->second;
      cout << "Calorias " << it->second.getCalorias();
      cout << "     Hidratos de Carb " << it->second.getHc();
      cout << "     Proteinas " << it->second.getProteinas();
      cout << "     Grasas " << it->second.getGrasas();
      cout << "     Fibra " << it->second.getFibra();
      cout << endl << endl;

  }
  
  
  //OBTENER SUBCONJUNTO (2 RECETAS??)
  
  


}