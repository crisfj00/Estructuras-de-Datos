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
        map<string,receta>::const_iterator it=datos.find(i);
        assert (it!=datos.end());
          return it->second;

  }
  
  receta & recetas::operator[](string i){
        map<string,receta>::iterator it=datos.find(i);
        assert (it!=datos.end());
           return it->second;
  }
  
  
   std::istream & operator>>(std::istream &is , recetas &p){
        receta pl;
        
        for (int i=0;!is.eof();i++){
            is >> pl;
            p.aniadir(pl);
            
        }
        
        return is;
  }

   std::ostream & operator<<(std::ostream &os , const recetas &p){
        for(recetas::const_iterator it=p.cbegin(); it!=p.cend();++it)
            os << *it;
        
        return os;
  }
  
   std::ostream & operator<<(std::ostream &os , std::pair<const std::__cxx11::basic_string<char>, receta> its){
      os << its.second; //NO LO DETECTA 
        return os;
  }

  
  void recetas::aniadir(const receta & p){
      pair<string,receta>nuevo;
      nuevo.first=p.getCode();
      nuevo.second=p;
      datos.insert(nuevo);
  }
  
    receta fusionarRecetas(recetas &allrecet, string code1, string code2){
        receta fusion;
        fusion.setNombre("Fusión " + allrecet[code1].getNombre() + " y " + allrecet[code2].getNombre());
        fusion.setCode("F_"+code1+"_"+code2);
        if(allrecet[code1].getPlato()==2 && allrecet[code2].getPlato()==2)
            fusion.setPlato(2);
        else
            fusion.setPlato(1);

        for(receta::const_iterator it=allrecet[code1].cbegin(); it!=allrecet[code1].cend(); ++it)
            fusion.aniadirIngrediente({(*it).first,(*it).second});


        for(receta::const_iterator it=allrecet[code2].cbegin(); it!=allrecet[code2].cend(); ++it){
            bool encontrado=false;

            for(receta::iterator it2=fusion.begin(); it2!=fusion.end(); ++it2){
                if((*it).first==(*it2).first){
                    (*it2).second+=(*it).second;
                    encontrado=true;
                }
            }

            if(!encontrado)
                fusion.aniadirIngrediente({(*it).first,(*it).second});
        }

        fusion.setCalorias(allrecet[code1].getCalorias()+allrecet[code2].getCalorias());
        fusion.setHc(allrecet[code1].getHc()+allrecet[code2].getHc());
        fusion.setGrasas(allrecet[code1].getGrasas()+allrecet[code2].getGrasas());
        fusion.setProteinas(allrecet[code1].getProteinas()+allrecet[code2].getProteinas());
        fusion.setFibra(allrecet[code1].getFibra()+allrecet[code2].getFibra());

        allrecet.aniadir(fusion);

        ArbolBinario<string> uno=allrecet[code1].getPasos().getArbol();
        ArbolBinario<string> dos=allrecet[code2].getPasos().getArbol();
        ArbolBinario<string> arbol("Acompañar");
        arbol.Insertar_Hi(arbol.getRaiz(),uno);
        arbol.Insertar_Hd(arbol.getRaiz(),dos);
        fusion.setArbol(arbol);
        arbol.~ArbolBinario();
        uno.~ArbolBinario();
        dos.~ArbolBinario();

        return fusion;
    }
