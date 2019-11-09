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


class recetas{
    private:
        map<string,receta> datos;
        
    public:
        
        
        
/*******************************ITERADORES***********************************/  
        
  typedef typename map<string, receta>::iterator iterator;
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
  const_iterator cbegin() const { return datos.cbegin(); }

  /**
   * @brief Último elemento del map
   * @return Iterador señalando al último elemento
   */
  iterator end() { return datos.end(); }

  /**
   * @brief Último elemento del map
   * @return Iterador constante señalando al último elemento
   */
  const_iterator cend() const { return datos.cend(); }
    
};

#endif /* RECETAS_H */

