/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ingredientes.h
 * Author: cristian
 *
 * Created on 19 de octubre de 2019, 17:05
 */

/**
  * @file Ingredientes.h
  * @brief Fichero cabecera del TDA Ingredientes
  *
  */

#include "ingrediente.h"
#include <iostream>



#ifndef INGREDIENTES_H
#define INGREDIENTES_H

  /**
  *  @brief T.D.A. Ingredientes
  *
  * Representa un vector dinamico de @e Ingrediente(s). Tiene dos ordenaciones posibles:
  * 
  *  - Ordenacion por el nombre del ingrediente
  *  - Ordenacion por el tipo de alimento
  *
  *
  * @author Fran Jimenez
  * @author Cristian Fernandez
  * @date Marzo 2008
  */
class Ingredientes{
private:

  /**
  * @page repConjunto Rep del TDA Ingredientes
  *
  * @section invConjunto Invariante de la representacion
  *
  * El invariante es rep.datos.size >0
  *
  *
  * @section faConjunto Funcion de abstraccion
  *
  * Un objeto valido @e rep del TDA Ingrediente se representa igual que @e Ingrediente ya que es un vector de estos:
  *
  * Alimento;Calorias;Hidratos de Carb;Proteinas;Grasas;Fibra;Tipo
  *
  */
    vector_dinamico<Ingrediente> datos;
    
public:
    /**
   * @brief Sobrecarga del operador =
   * @param original vector de ingredientes
   * @return Asigna al objeto implícito el vector de ingredientes
   */
    void operator=(const Ingredientes &original);
    
    /**
   * @brief Destructor del vector
   */
    ~Ingredientes();

    /**
   * @brief Consultor del numero de elementos del vector
   * @return Devuelve el numero de elementos del vector
   */
    int getNumElementos() const;
    
    /**
   * @brief Consultor del atributo de esa posicion
   * @param pos Posicion que queremos obtener
   * @return Devuelve el Ingrediente que esta en la posicon pasada como parametro
   */
    Ingrediente& get(int pos) const;

    /**
   * @brief Metodo para borrar un Ingrediente de la posicion pasada como parametro
   * @param pos Posicion que queremos borrar del vector
   */
    void borrar(int pos);

     /**
   * @brief Metodo para añadir un Ingrediente en el orden pedido (por nombre o por tipo)
   * @param p Ingrediente que queremos añadir 
   */
    void aniadir(const Ingrediente &p);

   /**
   * @brief Sobrecarga del operador +=
   * @param p Ingrediente a sumar con el objeto implícito
   */ 
    void operator+=(const Ingrediente &p);
    
    /**
    * @brief Metodo para obtener el contenido de una posicion del vector (Permite modificar el elemento)
    * @param pos Posicion en el vector a devolver
    * @return Devuelve un ingrediente de la posicion pasada como parametro
    */
    Ingrediente& obtener(int pos);

    /**
    * @brief  Sobrecarga del operador [] (Permite modificar el elemento)
    * @param i Posicion en el vector a devolver
    * @return Devuelve un ingrediente de la posicion pasada como parametro
    */
    Ingrediente& operator[] (int i);
     
    /**
    * @brief  Sobrecarga del operador [] (No permite modificar)
    * @param i Posicion en el vector a devolver
    * @return Devuelve un ingrediente de la posicion pasada como parametro
    */
    Ingrediente& operator[] (int i) const;

    /**
    * @brief Entrada de un vector ingredientes desde istream
    * @param is stream de entrada
    * @param p Vector de Ingredientes que recibe el valor de ingredientes
    * @retval El vector de ingredientes leído en p
    */
    friend std::istream & operator>>(std::istream &is , Ingredientes &p);

    /**
    * @brief Salida de un  a ostream
    * @param os stream de salida
    * @param p Ingrediente a escribir
    * @post Se obtiene en \a os la cadena de los diferentes ingredientes del vector con sus respetivos valores
    */
    friend std::ostream & operator<<(std::ostream &os , const Ingrediente &p);

};


#endif /* INGREDIENTES_H */
