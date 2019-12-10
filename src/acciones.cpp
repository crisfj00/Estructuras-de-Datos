#include <iostream>
#include "acciones.h"

using namespace std;

   unsigned char acciones::getAriedad(string accion) const{
        return datos.at(accion);
    }
   
  long unsigned int acciones::size() const{
      return datos.size();
  }
  
  void acciones::aniadirAccion(string accion, unsigned char ariedad){
      datos.insert({accion,ariedad});
  }
  
  bool acciones::existeAccion(string accion){
      bool existe=true;
      if(datos.find(accion)==datos.end())
          existe=false;
      return existe;
  }

 
  istream & operator>>(std::istream &is , acciones &p){
          
        char ariedad;
        char accion[256];
        
        while(!is.eof()){
            is.getline(accion,256, ' ');
            ariedad=is.get();
            is.get(); //salto de linea

            p.aniadirAccion(accion,ariedad);
        }
        return is;
  }
  
  ostream & operator<<(std::ostream &os , const acciones &p){
      for(map<string,unsigned char>::const_iterator it=p.datos.cbegin();
               it!=p.datos.cend(); it++){
          os << it->first << " " << it->second << "\n";
      }
      return os;
  }
  