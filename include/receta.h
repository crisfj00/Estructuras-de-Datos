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

 /**
  *  @brief T.D.A. Receta
  *
  * Representa una @c Receta de cocina que contiene:
  *
  * 	- Un código (único)
  *	- Un número entre 1-3 indicando si es un primer, segundo plato o postre.
  *	- El nombre de la receta. Por ejemplo “Salmorejo”
  *	- Una secuencia de pares de nombre de ingrediente y cantidad (en gramos).
  * 
  *	
  *	Además la receta mantiene el total de calorías, hidratos de carbono, grasas, proteínas y fibra que aporta.
  *	   
  *
  * Que se representa de la siguiente forma:
  *
  *  	Codigo; Numero de plato (1-3); Nombre de la receta; Ingrediente 1 y la cantidad del ingrediente; ..... ; Ingrediente n y la cantidad del ingrediente
  * 
  *
  * @author Fran Jimenez
  * @author Cristian Fernandez
  * @date Noviembre 2019 
  */
class receta{
    private:

	/**
  * @page repConjunto Rep del TDA Receta
  *
  * @section invConjunto Invariante de la representacion
  *
  * Un invariante es rep.codigo tiene que ser diferente a cualquier otro (unico)
  * Un invariante es rep.plato tiene que estar enre 1 y 3 
  *
  * @section faConjunto Funcion de abstraccion
  *
  * Un objeto valido @e rep del TDA Receta representa 
  *
  *    Codigo; Numero de plato (1-3); Nombre de la receta; Ingrediente 1 y la cantidad del ingrediente; ..... ; Ingrediente n y la cantidad del ingrediente
  *
  */
        string code;
        unsigned int plato;
        string nombre;
        list<pair<string,unsigned int> > ings;
        float calorias, hc, grasas, proteinas, fibra;
        
public:
    
    receta();
    
    receta(const receta& p);
    
    
    /**
     * @brief Consultor del codigo de la receta
     * @reutrn El codigo de la receta
     */
    string getCode() const;
    
    /**
     * @brief Consultor del numero del plato de la receta
     * @return Numero del plato
     */
    unsigned int getPlato() const;
    
    /**
     * @brief Consultor del nombre del plato
     * @return Nombre de la receta
     */
    string getNombre() const;
    
    /**
  * @brief Consultor de la cantidad de calorias de la receta
  * @return devuelve la cantidad de calorias de la receta
  */
  float getCalorias() const;
  
  /**
  * @brief Consultor de la cantidad de hidratos de carbono de la receta
  * @return devuelve la cantidad de hidratosd e carbono de la receta
  */
  float getHc() const;

  /**
  * @brief Consultor de la cantidad de proteinas de la receta
  * @return devuelve la cantidad de proteinas de la receta
  */
  float getProteinas() const;
  
  /**
  * @brief Consultor de la cantidad de grasas de la receta
  * @return devuelve la cantidad de grasas de la receta
  */
  float getGrasas() const;

  /**
  * @brief Consultor de la cantidad de fibra de la receta
  * @return devuelve la cantidad de fibra de la receta
  */
  float getFibra() const ;
    
    /**
     * @brief Consultor del numero de ingredientes de la receta
     * @return Devuelve el numero de ingredientes de la receta
     */
    long unsigned int ningredientes() const;
    
    /**
     * @brief Modificador del codigo de la receta
     * @param c Codigo nuevo
     */
    void setCode(string c);
    
    /**
     * @brief Modificador del número de plato de la receta (primero, segundo o tercero)
     * @param p Numero de plato nuevo
     */
    void setPlato(unsigned int p);
    
    /**
     * @brief Modificador del nombre de la receta
     * @param n Numero de plato nuevo
     */
    void setNombre(string n);
    
    
    /*
    void setCalorias(float cal);
    
    void setHc(float h);
    
    void setGrasas(float g);
    
    void setProteinas(float p);
    
    void setFibra(float f);
    */

    /**
     * @brief Consultor de un ingrediente de la receta (Nombre, Cantidad)
     * @param i Indice de la lista
     * @return Devuelve un par que representa un Ingrediente (Nombre y cantidad usada en la receta)
     */
    const pair<string,unsigned int> getIngrediente(int i) const;
    
    /**
     * @brief Consultor de un ingrediente de la receta y puede modicar (Nombre, Cantidad)
     * @param i Indice de la lista
     * @return Devuelve un par que representa un Ingrediente (Nombre y cantidad usada en la receta)
     */
    pair<string,unsigned int> &obtenerIngrediente(int i);
    
    /**
     * @brief Consultor de la lista de ingredientes
     * @return Devuelve la lista de pares Ingredientes (Nombre y cantidad usada en la receta)
     */
    list<pair<string,unsigned int>> getListaIngredientes() const;
    
   /**
    * @brief  Sobrecarga del operador [] (No permite modificar)
    * @param i Posicion en la lista a devolver
    * @return Devuelve un par Ingrediente (Nombre y cantidad usada en la receta) de la posicion pasada como parametro
    */
    const pair<string,unsigned int> &operator[](int i) const;
    
    /**
    * @brief  Sobrecarga del operador [] 
    * @param i Posicion en la lista a devolver
    * @return Devuelve un par Ingrediente (Nombre y cantidad usada en la receta) de la posicion pasada como parametro
    */
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
  * @brief Salida de una receta  a ostream
  * @param os stream de salida
  * @param p receta a escribir
  * @post Se obtiene en \a os la cadena de la receta con los valores
  *   de la receta de \a p
  */
  friend std::ostream & operator<<(std::ostream &os , const receta &p);
  
  void aniadirIngrediente(const pair<string,unsigned int> & p);
  
    
/*******************************ITERADORES***********************************/  
    
    /**
    * @brief Iterador que puede modificar y recorrer los elementos del contenedor
    * @return El iterador
    */ 
  typedef typename list<pair<string, unsigned int>>::iterator iterator;
    /**
    * @brief Iterador que puede recorrer los elementos del contenedor
    * @return El iterador
    */ 
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

