/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   receta.h
 * Author: cristian
 *
 * Created on 7 de noviembre de 2019, 20:34
 */

#ifndef RECETA_H
#define RECETA_H

#include<string>
#include <list>
using namespace std;

class receta{
    private:
        string code;
        unsigned int plato;
        string nombre;
        list<pair<string,unsigned int> > ings;
        float calorias, hc, grasas, proteinas, fibra;
        
public:
    
    string getCode();
    
    unsigned int getPlato() const;
    
    string getNombre() const;
    
    float getCalorias() const;
    
    float getHc() const;
    
    float getGrasas() const;
    
    float getProteinas() const;
    
    float getFibra() const;
    
    long unsigned int ningredientes() const;
    
    void setCode(string c);
    
    void setPlato(unsigned int p);
    
    void setNombre(string n);
    
    void setCalorias(float cal);
    
    void setHc(float h);
    
    void setGrasas(float g);
    
    void setProteinas(float p);
    
    void setFibra(float f);
    
    const pair<string,unsigned int> getIngrediente(int i) const;
    
    pair<string,unsigned int> &obtenerIngrediente(int i);
    
    list<pair<string,unsigned int>> getListaIngredientes() const;
    
    const pair<string,unsigned int> &operator[](int i) const;
    
    pair<string,unsigned int> & operator[](int i); 
    
    
   /**
   * @brief Sobrecarga del operador =
   * @param P receta
   * @return Asigna al objeto implícito la receta
   */
  void operator=(const receta &P);

 /**
  * @brief Entrada de una receta desde istream
  * @param is stream de entrada
  * @param p receta que recibe el valor
  * @retval La receta leída en p
  */
  friend std::istream & operator>>(std::istream &is , receta &p);

  /**
  * @brief Salida de un  a ostream
  * @param os stream de salida
  * @param p receta a escribir
  * @post Se obtiene en \a os la cadena de la receta con los valores
  *   de la receta de \a p
  */
  friend std::ostream & operator<<(std::ostream &os , const receta &p);
  
    
    
    
/*******************************ITERADORES***********************************/  
    
    
  typedef typename list<pair<string, unsigned int>>::iterator iterator;
  typedef typename list<pair<string, unsigned int>>::const_iterator const_iterator;

  /**
   * @brief Primer elemento del list
   * @return Iterador señalando al primer elemento
   */
  iterator begin() { return ings.begin(); }

  /**
   * @brief Primer elemento del list
   * @return Iterador constante señalando al primer elemento
   */
  const_iterator cbegin() const { return ings.cbegin(); }

  /**
   * @brief Último elemento del list
   * @return Iterador señalando al último elemento
   */
  iterator end() { return ings.end(); }

  /**
   * @brief Último elemento del list
   * @return Iterador constante señalando al último elemento
   */
  const_iterator cend() const { return ings.cend(); }
        
};


#endif /* RECETA_H */

