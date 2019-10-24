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
  * @brief Fichero cabecera del TDA ingredientes
  *
  */

#include "ingrediente.h"
#include "vector_dinamico.h"
#include <iostream>



#ifndef INGREDIENTES_H
#define INGREDIENTES_H

  /**
  *  @brief T.D.A. ingredientes
  *
  * Representa un vector dinamico de @e ingrediente(s). Tiene dos ordenaciones posibles:
  * 
  *  - Ordenacion por el nombre del ingrediente
  *  - Ordenacion por el tipo de alimento
  *
  *
  * @author Fran Jimenez
  * @author Cristian Fernandez
  * @date Marzo 2008
  */
class ingredientes{
private:

  /**
  * @page repConjunto Rep del TDA ingredientes
  *
  * @section invConjunto Invariante de la representacion
  *
  * El invariante es rep.datos.size >0
  *
  *
  * @section faConjunto Funcion de abstraccion
  *
  * Un objeto valido @e rep del TDA ingrediente se representa igual que @e Ingrediente ya que es un vector de estos:
  *
  * Alimento;Calorias;Hidratos de Carb;Proteinas;Grasas;Fibra;Tipo
  *
  */
    vector_dinamico<ingrediente> datos;
    
    vector_dinamico<int> indices;
    
public:
    
    ingredientes();

    ingredientes(const ingredientes& original);
    
    
    /**
   * @brief Sobrecarga del operador =
   * @param original vector de ingredientes
   * @return Asigna al objeto implícito el vector de ingredientes
   */
    void operator=(const ingredientes &original);
    
    /**
   * @brief Destructor del vector
   */
    ~ingredientes();
    
    int size();
    
    
    /**
   * @brief Consultor del numero de elementos del vector
   * @return Devuelve el numero de elementos del vector
   */
    int getNumElementos() const;
    
    /**
   * @brief Consultor del atributo de esa posicion
   * @param pos Posicion que queremos obtener
   * @return Devuelve el ingrediente que esta en la posicon pasada como parametro
   */
    ingrediente get(int pos) const;

    /**
   * @brief Metodo para borrar un ingrediente de la posicion pasada como parametro
   * @param pos Posicion que queremos borrar del vector
   */
    void borrar(int pos);

     /**
   * @brief Metodo para añadir un ingrediente en el orden pedido (por nombre o por tipo)
   * @param p ingrediente que queremos añadir 
   */
    bool insertar(const ingrediente &p);

   /**
   * @brief Sobrecarga del operador +=
   * @param p ingrediente a sumar con el objeto implícito
   */ 
    void operator+=(const ingrediente &p);
    
    /**
    * @brief  Sobrecarga del operador [] (No permite modificar)
    * @param i Posicion en el vector a devolver
    * @return Devuelve un ingrediente de la posicion pasada como parametro
    */
    ingrediente operator[] (int i) const;

    /**
    * @brief Entrada de un vector ingredientes desde istream
    * @param is stream de entrada
    * @param p Vector de Ingredientes que recibe el valor de ingredientes
    * @retval El vector de ingredientes leído en p
    */
    friend std::istream & operator>>(std::istream &is , ingredientes &p);

    /**
    * @brief Salida de un  a ostream
    * @param os stream de salida
    * @param p Ingrediente a escribir
    * @post Se obtiene en \a os la cadena de los diferentes ingredientes del vector con sus respetivos valores
    */
    friend std::ostream & operator<<(std::ostream &os , const ingrediente &p);
    
    int buscar(const ingrediente &p);
    
    void ImprimirPorTipo(ostream& flujo);
    
    void ImprimirPorNombre(ostream& flujo);
        

    
    bool incluidoIngrediente(const ingrediente &p);
    
    int buscarTipo(const ingrediente &p);
};


#endif /* INGREDIENTES_H */
