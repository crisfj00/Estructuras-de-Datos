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
#include "ingredientes.h"
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
    
    /**
     * @brief Constructor por defecto
     */ 
    receta();
    
    /**
     * @brief Constructor de copia 
     */
    receta(const receta& p);
    
    /**
     * @brief Destructor del vector de recetas
     */
    ~receta();
    
    /**
     * @brief Consultor del codigo de la receta
     * @return El codigo de la receta
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
    
    
    /**
     * @brief Modificador de las calorias de la receta
     * @param cal Cantidad de calorias nuevas 
     */
    void setCalorias(float cal);
    
    /**
     * @brief Modificador de los hidratos de carbono de la receta
     * @param h Cantidad de hidratos de carbono nuevos 
     */
    void setHc(float h);
    
    /**
     * @brief Modificador de las grasas de la receta
     * @param g Cantidad de grasas nuevas 
     */
    void setGrasas(float g);
    
    /**
     * @brief Modificador de las proteinas de la receta
     * @param p Cantidad de proteinas nuevas 
     */
    void setProteinas(float p);
    
    /**
     * @brief Modificador de las fibras de la receta
     * @param f Cantidad de fibras nuevas 
     */
    void setFibra(float f);
    
    /**
     * @brief Modificador de todos los nutrientes de una receta
     * @param ingre Ingredientes sobre los cuales buscará la información
     */
    void actualizarNutrientes(const ingredientes & ingre);

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
    
    
  //typedef typename list<pair<string, unsigned int>>::iterator iterator;
    
  //typedef typename list<pair<string, unsigned int>>::const_iterator const_iterator;

  
  //iterator begin() { return ings.begin(); }

  
  //const_iterator cbegin() const { return ings.cbegin(); }

  
  //iterator end() { return ings.end(); }

  /**
   * @brief Último elemento del list
   * @return Iterador constante señalando al último elemento
   */
  //const_iterator cend() const { return ings.cend(); }
  
  class iterator{
    private:
        /**
    * @brief Iterador que puede modificar y recorrer los elementos del contenedor
    * @return El iterador
    */ 
        list<pair<string,unsigned int>>::iterator puntero;

    public:
    /**
     * @brief Constructor por defecto
     */
    iterator() : puntero(0){};
    /**
     * @brief Constructor de copia
     * @param v Iterador 
     */
    iterator(const iterator & v) : puntero(v.puntero){};

    /**
    * @brief Destructor (liberar memoria)
    */
    ~iterator(){}

    /**
     * @brief Sobrecarga del operador =
     * @param orig iterador 
     * @return Devuelve un iterador con la posicion del iterador de la otra receta
     */
    iterator & operator=(const iterator & orig){
        puntero = orig.puntero;
        return *this;
    }

    /**
         * @brief Sobrecarga del operador *
         * @return Devuelve un pair del elemento de la lista al que esta apuntando
         */
    pair<string ,unsigned int> &operator*()const{
         return *puntero;
    }

    /**
     * @brief Sobrecarga del operador ++
     * @return Devuelve el iterador de la siguiente posicion
     */
    iterator & operator++(){
         puntero++;
         return *this;
    }


    /**
     * @brief Sobrecarga del operador --
     * @return Devuelve el iterador de la anterior posicion
     */
    iterator &operator--(){
        puntero--;
        return *this;
    }

    /**
     * @brief Sobrecarga del operador !=
     * @param v iterador 
     * @return Devuelve true si la posicion de los iteradores son distintos y false si son iguales 
     */
    bool operator !=(const iterator& v)const{
        return puntero != v.puntero;
    }
    /**
     * @brief Sobrecarga del operador ==
     * @param v Iterador
     * @return Devuelve true si la posicion de los iteradores son iguales y false si no lo son 
     */
    bool operator ==(const iterator& v)const{
        return puntero == v.puntero;
    }

    friend class receta;

};

    /**
   * @brief Primer elemento del list
   * @return Iterador señalando al primer elemento
   */
    iterator begin(){
    iterator i;
    i.puntero=ings.begin();
    return i;
}
    
    /**
   * @brief Último elemento del list
   * @return Iterador señalando al último elemento
   */
    iterator end(){
    iterator i;
    i.puntero=ings.end();
    return i;
}

  class const_iterator{
    private:
        /**
    * @brief Iterador que puede recorrer los elementos del contenedor
    * @return El iterador constante
    */ 
        list<pair<string,unsigned int>>::const_iterator puntero;
    public:
    /**
    * @brief Constructor por defecto
    */
    const_iterator(): puntero(0){};
    /**
    * @brief Constructor de copia
    * @param v Iterador constante 
    */
    const_iterator(const const_iterator &v): puntero(v.puntero){};
    /**
    * @brief Constructor de copia
    * @param v Iterador  
    */
    const_iterator(const iterator &v): puntero(v.puntero){};
    /**
    * @brief Destructor (liberar memoria)
    */
    ~const_iterator(){};
    /**
     * @brief Sobrecarga del operador =
     * @param orig iterador 
     * @return Devuelve un iterador constante con la posicion del iterador de la otra receta
     */
    const_iterator& operator=(const iterator &orig){
        puntero = orig.puntero;
        return *this;
    }

    /**
    * @brief Sobrecarga del operador *
    * @return Devuelve la receta constante del elemento de la lista al que esta apuntando
    */
    const pair<string ,unsigned int>& operator*()const{
        return *puntero;
    }
    /**
         * @brief Sobrecarga del operador ++
         * @return Devuelve el iterador constante de la siguiente posicion
         */
    const_iterator operator++(){
        puntero++;
        return *this;
    }
    /**
     * @brief Sobrecarga del operador --
     * @return Devuelve el iterador constante de la anterior posicion
     */
    const_iterator operator--(){
        puntero--;
        return *this;
    }  

     /**
     * @brief Sobrecarga del operador !=
     * @param v iterador constante
     * @return Devuelve true si la posicion de los iteradores constantes son distintos y false si son iguales 
     */
    bool operator!=(const const_iterator & v)const{
        return puntero != v.puntero;
    }

    /**
     * @brief Sobrecarga del operador ==
     * @param v Iterador constante
     * @return Devuelve true si la posicion de los iteradores son iguales y false si no lo son 
     */
    bool operator==(const const_iterator & v)const{
         return puntero == v.puntero;
    } 

friend class receta;

};   
    /**
   * @brief Primer elemento del list
   * @return Iterador constante señalando al primer elemento
   */
    const_iterator cbegin(){
        const_iterator i;
        i.puntero=ings.cbegin();
        return i;
    }
    /**
   * @brief Último elemento del list
   * @return Iterador constante señalando al último elemento
   */
    const_iterator cend(){
        const_iterator i;
        i.puntero=ings.cend();
        return i;
    }
        
};


#endif /* RECETA_H */

