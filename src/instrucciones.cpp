#include <iostream>
#include "instrucciones.h"
#include "arbolbinario.h"
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

  instrucciones::instrucciones(){}

  instrucciones::instrucciones(const acciones &acci){
      acc=acci;
  }
  
  void instrucciones::setArbol(const ArbolBinario<string> & arbol){
      
      datos=arbol;
  }
  
  ArbolBinario<string> instrucciones::getArbol() const{
      return datos;
  }
    
  istream & operator>>(std::istream &is , instrucciones &p){
      char cadena[256];
      char accion[256];
      char ingrediente[256];
      
      stack<ArbolBinario<string>> pila;
      
      
      while(!is.eof()){ //no detecta eof
        is.getline(cadena,256,'\n');
        if(p.acc.existeAccion(cadena)){ //solo hemos leido la accion (sacar pila)
            if(p.acc.getAriedad(cadena)=='1'){
                //crear arbol de padre cadena e hijo izq el arbol de la pila
                ArbolBinario<string> arbol(cadena);
                arbol.Insertar_Hi(arbol.getRaiz(),pila.top());
                pila.pop();
                pila.push(arbol);
            }
            else if(p.acc.getAriedad(cadena)=='2'){
                //crear arbol de padre cadena e hijos arboles de la pila(mirar practica)
                ArbolBinario<string> arbol(cadena);
                arbol.Insertar_Hd(arbol.getRaiz(),pila.top());
                pila.pop();
                arbol.Insertar_Hi(arbol.getRaiz(),pila.top());
                pila.pop();
                pila.push(arbol);
            }
        }
        else{ //hemos leido varios ingredientes
            istringstream istr(cadena);
            istr.getline(accion,256,' '); //metemos en accion el verbo
            if(!p.acc.existeAccion(accion))
                break; //SI NO EXISTE LA ACCIÓN, SALIMOS DEL WHILE
            istr.getline(ingrediente,256,istr.eofbit);

            if(p.acc.getAriedad(accion)=='1'){
                //crear arbol de raiz accion y de hijo ingrediente
                ArbolBinario<string> arbol(accion);
                arbol.Insertar_Hi(arbol.getRaiz(),ingrediente);
                pila.push(arbol);
            }
            else if(p.acc.getAriedad(accion)=='2'){
                //crear arbol de hijo izquierda la pila, raiz accion e hijo derecha ingrediente
                ArbolBinario<string> arbol(accion);
                arbol.Insertar_Hi(arbol.getRaiz(),pila.top());
                pila.pop();
                arbol.Insertar_Hd(arbol.getRaiz(),ingrediente);
                pila.push(arbol);
                
            }
        }
      }
      
      p.setArbol(pila.top());
      
      pila.pop();
      
      return is;
  }
  
  ostream & operator<<(std::ostream &os , const instrucciones &p){   

    string ingrediente1="", ingrediente2="";
    for(ArbolBinario<string>::postorden_iterador it=p.getArbol().beginpostorden(); it!=p.getArbol().endpostorden(); ++it){
        if(it.hd().nulo() && it.hi().nulo()){
            if(ingrediente1=="")
                ingrediente1=*it;
            else
                ingrediente2=*it;
        }
        else{
            os << *it;
            if(ingrediente1!=""){
                os << " " <<ingrediente1;
                ingrediente1="";
            }
            if(ingrediente2!=""){
                os << " " << ingrediente2;
                ingrediente2="";
            }
            os << endl;
        
        }
    }
      
      return os;
  }