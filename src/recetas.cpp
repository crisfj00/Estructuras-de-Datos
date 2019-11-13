#include <iostream>
#include "receta.h"
#include "recetas.h"
#include <cmath>
#include <cassert>
#include <string>
#include <map>

using namespace std;


  long unsigned int recetas::size() const{
      return datos.size();
      
  }
  
  void recetas::borrar(string codigo){
      datos.erase(codigo);
  }
  
  const receta & recetas::operator[](string i) const{
      return datos.at(i);
  }
  
  receta & recetas::operator[](string i){
      return datos.at(i);
  }
  
  
   std::istream & operator>>(std::istream &is , recetas &p){
        receta pl;
        
        for (int i=0; !is.eof();i++){
            is >> pl;
            p.aniadir(pl);
        }
        
        return is;
  }

   std::ostream & operator<<(std::ostream &os , const recetas &p){
        for(recetas::const_iterator it=p.cbegin(); it!=p.cend();it++)
            os << (*it).second;
        
        return os;
  }
  
   std::ostream & operator<<(std::ostream &os , const pair<const string, receta> its){
      os << its.second;
        return os;
  }
  
  void recetas::aniadir(const receta & p){
      pair<string,receta>nuevo;
      nuevo.first=p.getCode();
      nuevo.second=p;
      datos.insert(nuevo);
  }
  
