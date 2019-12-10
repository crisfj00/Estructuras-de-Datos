/* 
 * File:   instrucciones.h
 * Author: cristian
 *
 * Created on 6 de diciembre de 2019, 12:18
 */

#include "arbolbinario.h"
#include <iostream>
#include <string>
#include "acciones.h"

#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

class instrucciones{
private:
    ArbolBinario<string> datos;
    acciones acc;
public:
    
  instrucciones();
  
  instrucciones(const acciones &acc);
    
  void setArbol(const ArbolBinario<string> & arbol);

  friend std::istream & operator>>(std::istream &is , instrucciones &p);
  
  ArbolBinario<string> getArbol() const;

  friend std::ostream & operator<<(std::ostream &os , const instrucciones &p);   
};

#endif /* INSTRUCCIONES_H */

