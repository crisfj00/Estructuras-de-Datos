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
  *  @brief T.D.A. Recetas
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
    
    /**
     * @page repConjunto Rep del TDA Recetas
     *
     * @section invConjunto Invariante de la representacion
     *
     * Un invariante es rep.datos.size>0                      //ESTO SE LO TENGO QUE PREGUNTAR  
     * 
     *
     * @section faConjunto Funcion de abstraccion
     *
     * Un objeto valido @e rep del TDA Recetas representa 
     *
     *    Codigo; Numero de plato (1-3); Nombre de la receta; Ingrediente 1 y la cantidad del ingrediente; ..... ; Ingrediente n y la cantidad del ingrediente
     *
     */

        map<string,receta> datos;
        
    public:
        
      /**
       * @brief Metodo para saber el numero total de recetas 
       * @return Numero total de las recetas que contiene 
       */  
     long unsigned int size() const;

      /**
       * @brief Metodo para borrar una receta segun el codigo
       * @param codigo Codigo unico de la receta a borrar
       */
     void borrar(string codigo);
  
   /**
    * @brief  Sobrecarga del operador [] (No permite modificar)
    * @param i Código de la receta en el diccionario a devolver
    * @return Devuelve una receta con el código pasado como parametro
    */
    const receta &operator[](string i) const;
    
    /**
    * @brief  Sobrecarga del operador [] 
    * @param i Código de la receta en el diccionario a devolver
    * @return Devuelve una receta con el código pasado como parametro
    */
    receta & operator[](string i); 
    
    
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
  
   /**
    * @brief Salida de un elemento del map 
    * @param os stream de salida
    * @param its un elemeto del map de recetas
    * @post Se obtiene en \a os el elemento de recetas con sus valores de \a p
    */
    friend std::ostream & operator<<(std::ostream &os , const pair< string, receta> &its);
  
   /**
    * @brief Metodo para añadir una receta al map
    * @param p Receta a añadir
    */
    void aniadir(const receta & p);
  
              
/*******************************ITERADORES***********************************/  
  /**
  * @brief Iterador que puede modificar y recorrer los elementos del contenedor
  * @return El iterador
  */      
  //typedef typename map<string, receta>::iterator iterator;

  /**
  * @brief Iterador que puede modificar y recorrer los elementos del contenedor
  * @return El iterador
  */ 
  //typedef typename map<string, receta>::const_iterator const_iterator;

  /**
   * @brief Primer elemento del map
   * @return Iterador señalando al primer elemento
   */
  //iterator begin() { return datos.begin(); }

  /**
   * @brief Primer elemento del map
   * @return Iterador constante señalando al primer elemento
   */
  //const_iterator cbegin() const { return datos.begin(); }

  /**
   * @brief Último elemento del map
   * @return Iterador señalando al último elemento
   */
  //iterator end() { return datos.end(); }

  /**
   * @brief Último elemento del map
   * @return Iterador constante señalando al último elemento
   */
  //const_iterator cend() const { return datos.end(); }
  
class iterator{
    private:
        map<string,receta>::iterator puntero;

    public:

    iterator() : puntero(0) {};

    iterator(const iterator & v) : puntero(v.puntero) {};

    ~iterator(){}


    iterator & operator=(const iterator & orig){
        puntero = orig.puntero;
        return *this;
    }


    receta &operator*()const{
         return puntero->second;
    }

    iterator & operator++(){
         puntero++;
         return *this;
    }


    iterator &operator--(){
        puntero--;
        return *this;
    }


    bool operator !=(const iterator& v)const{
        return puntero != v.puntero;
    }


    bool operator ==(const iterator& v)const{
        return puntero == v.puntero;
    }

    friend class recetas;

};

    iterator begin(){
        iterator i;
        i.puntero= datos.begin();
        return i;
    }



    iterator end(){
        iterator i;
        i.puntero=datos.end();
        return i;
    }

class const_iterator{
    private:
        map<string,receta>::const_iterator puntero;
    public:

    const_iterator() : puntero(0) {};

   
    const_iterator(const const_iterator &v) : puntero(v.puntero){};

    const_iterator(const iterator &v) : puntero(v.puntero){};

    ~const_iterator(){};

    const_iterator& operator=(const iterator &orig){
        puntero = orig.puntero;
        return *this;
    }

    const receta& operator*()const{
        return puntero->second;
    }

    const_iterator operator++(){
        puntero++;
        return *this;
    }
    
    const_iterator operator--(){
        puntero--;
        return *this;
    }  
      
    bool operator!=(const const_iterator & v)const{
        return puntero != v.puntero;
    }

 
    bool operator==(const const_iterator & v)const{
         return puntero == v.puntero;
    } 

friend class recetas;

};

        const_iterator cbegin() const{
            const_iterator i;
            i.puntero=datos.cbegin();
            return i;
        }
        
        const_iterator cend() const{
            const_iterator i;
            i.puntero=datos.cend();
            return i;
        }
    
};

#endif /* RECETAS_H */

