/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   recetas.h
 * Author: cristian
 *
 * Created on 7 de noviembre de 2019, 20:37
 */

#ifndef RECETAS_H
#define RECETAS_H

#include <map>
#include <string>

using namespace std;

/**
  *  @brief T.D.A. Receta
  *
  * Representa un objeto del TDA @c Recetas representa un conjunto no repetido de objetos de tipo Receta.
  *	   
  * 
  * Que se representa como un objeto de receta:
  *
  *  	Codigo; Numero de plato (1-3); Nombre de la receta; Ingrediente 1 y la cantidad del ingrediente; ..... ; Ingrediente n y la cantidad del ingrediente
  * 
  *
  * @author Fran Jimenez
  * @author Cristian Fernandez
  * @date Noviembre 2019 
  */
class recetas{
    private:

        map<string,receta> datos;
        
    public:
        
  long unsigned int size() const;
  
  void borrar(string codigo);
  
   /**
    * @brief  Sobrecarga del operador [] (No permite modificar)
    * @param i Posicion en el diccionario a devolver
    * @return Devuelve una receta de la posicion pasada como parametro
    */
    const receta &operator[](int i) const;
    
    /**
    * @brief  Sobrecarga del operador [] 
    * @param i Posicion en el diccionario a devolver
    * @return Devuelve una receta de la posicion pasada como parametro
    */
    receta & operator[](int i); 
    
    
     /**
  * @brief Entrada de un conjunto de recetas desde istream
  * @param is stream de entrada
  * @param p recetas que recibe el valor
  * @retval Las recetas leída en p
  */
  friend std::istream & operator>>(std::istream &is , recetas &p);

  /**
  * @brief Salida de recetas a ostream
  * @param os stream de salida
  * @param p recetas a escribir
  * @post Se obtiene en \a os el conjunto de recetas con sus valores de \a p
  */
  friend std::ostream & operator<<(std::ostream &os , const recetas &p);
  
  
  void aniadir(const receta & p);
  
              
/*******************************ITERADORES***********************************/  
  /**
  * @brief Iterador que puede modificar y recorrer los elementos del contenedor
  * @return El iterador
  */      
  typedef typename map<string, receta>::iterator iterator;

  /**
  * @brief Iterador que puede modificar y recorrer los elementos del contenedor
  * @return El iterador
  */ 
  typedef typename map<string, receta>::const_iterator const_iterator;

  /**
   * @brief Primer elemento del map
   * @return Iterador señalando al primer elemento
   */
  iterator begin() { return datos.begin(); }

  /**
   * @brief Primer elemento del map
   * @return Iterador constante señalando al primer elemento
   */
  const_iterator cbegin() const { return datos.begin(); }

  /**
   * @brief Último elemento del map
   * @return Iterador señalando al último elemento
   */
  iterator end() { return datos.end(); }

  /**
   * @brief Último elemento del map
   * @return Iterador constante señalando al último elemento
   */
  const_iterator cend() const { return datos.end(); }
  
    
};

#endif /* RECETAS_H */

