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
  float caloriasMAX=atof(argv[3]);
  
  if (!f){
	  cout<<"No existe el fichero "<<endl;
  }

  recetas rall;
  f>>rall;
  
  
  ingredientes iall;
  d>>iall;
  
  float calorias, hc, grasas, proteinas, fibra;

  vector<pair<string,float>> razones; 
  
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
      
      razones.push_back({it->first,it->second.getProteinas()/it->second.getHc()});
      
      cout << "Valores Nutricionales de la receta " << it->first << endl;
      cout << it->second;
      cout << "Calorias " << it->second.getCalorias();
      cout << "     Hidratos de Carb " << it->second.getHc();
      cout << "     Proteinas " << it->second.getProteinas();
      cout << "     Grasas " << it->second.getGrasas();
      cout << "     Fibra " << it->second.getFibra();
      cout << endl << endl;

  }
  
  
  bool cambio=true;
  vector<pair<string,float>>::iterator it;
  vector<pair<string,float>>::iterator it2;
  pair<string,float> aux;

  for(long unsigned int izda=0; izda < razones.size() && cambio; izda++){
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
  for(vector<pair<string,float>>::const_iterator it=razones.cbegin(); it!=razones.cend(); it++){
      if((caloriasT+rall[it->first].getCalorias())<= caloriasMAX){
          subconjunto.aniadir(rall[it->first]);
          caloriasT+=rall[it->first].getCalorias();
          proteinasT+=rall[it->first].getProteinas();
      }
  }
  cout << endl;
  cout << "Las recetas escogidas son: \n\n";
    for(recetas::iterator it=subconjunto.begin(); it!=subconjunto.end(); it++){
        cout << it->second;
    }
  cout << endl << "Calorias Totales " << caloriasT << "\tProteinas Totales " << proteinasT << endl;


}