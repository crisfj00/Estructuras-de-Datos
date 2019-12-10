/* 
 * File:   acciones.h
 * Author: cristian
 *
 * Created on 6 de diciembre de 2019, 11:42
 */

#ifndef ACCIONES_H
#define ACCIONES_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

class acciones{
private:
    map<string,unsigned char> datos;
public:
    
   unsigned char getAriedad(string accion) const;
    
 /**
  * @brief Entrada de acciones desde istream
  * @param is stream de entrada
  * @param p acciones que recibe el valor
  * @retval Las acciones leídas en p
  */
  friend std::istream & operator>>(std::istream &is , acciones &p);

  /**
  * @brief Salida de unas acciones a ostream
  * @param os stream de salida
  * @param p acciones a escribir
  * @post Se obtiene en \a os la secuencia de acciones con los valores de \a p
  */
  friend std::ostream & operator<<(std::ostream &os , const acciones &p);
  
  long unsigned int size() const;
  
  void aniadirAccion(string accion, unsigned char ariedad);
  
  bool existeAccion(string accion);
  
    
    
};


#endif /* ACCIONES_H */

