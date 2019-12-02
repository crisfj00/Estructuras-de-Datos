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
  const float caloriasMAX=atof(argv[3]);
  
  if (!f){
	  cout<<"No existe el fichero "<<endl;
  }

  recetas rall;
  f>>rall;
  
  
  ingredientes iall;
  d>>iall;
  

  vector<pair<string,float>> razones; 
  
  for(recetas::iterator it=rall.begin(); it!=rall.end(); ++it){
      (*it).actualizarNutrientes(iall);      
      razones.push_back({(*it).getCode(),(*it).getProteinas()/(*it).getHc()}); //AÑADIMOS A UN VECTOR EL PAR codigo, proteinas/Hc
      
      cout << "Valores Nutricionales de la receta " << (*it).getCode() << endl;
      cout << (*it);
      cout << "Calorias " << (*it).getCalorias();
      cout << "     Hidratos de Carb " << (*it).getHc();
      cout << "     Proteinas " << (*it).getProteinas();
      cout << "     Grasas " << (*it).getGrasas();
      cout << "     Fibra " << (*it).getFibra();
      cout << endl << endl;

  }
  
  
  bool cambio=true;
  vector<pair<string,float>>::iterator it;
  vector<pair<string,float>>::iterator it2;
  pair<string,float> aux;

  for(long unsigned int izda=0; izda < razones.size() && cambio; izda++){ //ORDENAMOS EL VECTOR DE MAYOR A MENOR
      cambio=false;
      
      for(long unsigned int i=razones.size()-1; i>izda;i--){
          it=razones.begin();
          it2=razones.begin();
          advance(it,i);
          advance(it2,i-1);
          
          if(it->second > it2->second){
              cambio=true;
              aux=*it;
              *it=*it2;
              *it2=aux;
          }
      }
  }
  
  recetas subconjunto;
  
  float caloriasT=0;
  float proteinasT=0;
  for(vector<pair<string,float>>::const_iterator it=razones.cbegin(); it!=razones.cend(); it++){ //SELECCIONAMOS HASTA COMPLETAR LAS CALORIAS PEDIDAS
      if((caloriasT+rall[it->first].getCalorias())<= caloriasMAX){
          subconjunto.aniadir(rall[it->first]);
          caloriasT+=rall[it->first].getCalorias();
          proteinasT+=rall[it->first].getProteinas();
      }
  }
  cout << endl;
  cout << "Las recetas escogidas son: \n\n";
    for(recetas::iterator it=subconjunto.begin(); it!=subconjunto.end(); ++it){
        cout << (*it);
    }
  cout << endl << "Calorias Totales " << caloriasT << "\tProteinas Totales " << proteinasT << endl;


}
