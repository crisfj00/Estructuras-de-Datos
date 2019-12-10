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
#include "receta.h"

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
class recetas
{
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

    map<string, receta> datos;

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
    receta &operator[](string i);

    /**
    * @brief Entrada de un conjunto de recetas desde istream
    * @param is stream de entrada
    * @param p recetas que recibe el valor
    * @retval Las recetas leída en p
    */
    friend std::istream &operator>>(std::istream &is, recetas &p);

    /**
    * @brief Salida de recetas a ostream
    * @param os stream de salida
    * @param p recetas a escribir
    * @post Se obtiene en \a os el conjunto de recetas con sus valores de \a p
    */
    friend std::ostream &operator<<(std::ostream &os, const recetas &p);

    /**
    * @brief Salida de un elemento del map 
    * @param os stream de salida
    * @param its un elemeto del map de recetas
    * @post Se obtiene en \a os el elemento de recetas con sus valores de \a p
    */
    friend std::ostream &operator<<(std::ostream &os, const pair<string, receta> &its);

    /**
    * @brief Metodo para añadir una receta al map
    * @param p Receta a añadir
    */
    void aniadir(const receta &p);
    

    /*******************************ITERADORES***********************************/
    
    //typedef typename map<string, receta>::iterator iterator;

    
    //typedef typename map<string, receta>::const_iterator const_iterator;

  
    //iterator begin() { return datos.begin(); }

   
    //const_iterator cbegin() const { return datos.begin(); }

    
    //iterator end() { return datos.end(); }


    //const_iterator cend() const { return datos.end(); }

    class iterator
    {
    private:
        /**
         * @brief Iterador que puede modificar y recorrer los elementos del contenedor
         * @return El iterador
         */
        map<string, receta>::iterator puntero;

    public:

        /**
         * @brief Constructor por defecto
         */
        iterator() : puntero(0){};
        /**
         * @brief Constructor de copia
         * @param v Iterador 
         */
        iterator(const iterator &v) : puntero(v.puntero){};
        /**
         * @brief Destructor (liberar memoria)
         */
        ~iterator() {}
        /**
         * @brief Sobrecarga del operador =
         * @param orig iterador 
         * @return Devuelve un iterador con la posicion del iterador de la otra receta
         */
        iterator &operator=(const iterator &orig)
        {
            puntero = orig.puntero;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador *
         * @return Devuelve la receta del elemento del map al que esta apuntando
         */
        receta &operator*() const
        {
            return puntero->second;
        }
        /**
         * @brief Sobrecarga del operador ++
         * @return Devuelve el iterador de la siguiente posicion
         */
        iterator &operator++()
        {
            puntero++;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador --
         * @return Devuelve el iterador de la anterior posicion
         */
        iterator &operator--()
        {
            puntero--;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador !=
         * @param v iterador 
         * @return Devuelve true si la posicion de los iteradores son distintos y false si son iguales 
         */
        bool operator!=(const iterator &v) const
        {
            return puntero != v.puntero;
        }
        /**
         * @brief Sobrecarga del operador ==
         * @param v Iterador
         * @return Devuelve true si la posicion de los iteradores son iguales y false si no lo son 
         */
        bool operator==(const iterator &v) const
        {
            return puntero == v.puntero;
        }

        friend class recetas;
    };
    /**
    * @brief Primer elemento del map
    * @return Iterador señalando al primer elemento
    */
    iterator begin()
    {
        iterator i;
        i.puntero = datos.begin();
        return i;
    }
    /**
   * @brief Último elemento del map
   * @return Iterador señalando al último elemento
   */
    iterator end()
    {
        iterator i;
        i.puntero = datos.end();
        return i;
    }




    class const_iterator
    {
    private:
        /**
         * @brief Iterador que puede modificar y recorrer los elementos del contenedor
         * @return El iterador
         */
        map<string, receta>::const_iterator puntero;

    public:
        /**
         * @brief Constructor por defecto
         */
        const_iterator() : puntero(0){};
        /**
         * @brief Constructor de copia
         * @param v Iterador constante
         */
        const_iterator(const const_iterator &v) : puntero(v.puntero){};
        /**
         * @brief Constructor de copia
         * @param v Iterador 
         */
        const_iterator(const iterator &v) : puntero(v.puntero){};
        /**
         * @brief Destructor (liberar memoria)
         */
        ~const_iterator(){};
        /**
         * @brief Sobrecarga del operador =
         * @param orig iterador 
         * @return Devuelve un iterador constante con la posicion del iterador de la otra receta
         */
        const_iterator &operator=(const iterator &orig)
        {
            puntero = orig.puntero;
            return *this;
        }
         /**
         * @brief Sobrecarga del operador *
         * @return Devuelve la receta constante del elemento del map al que esta apuntando
         */
        const receta &operator*() const
        {
            return puntero->second;
        }
        /**
         * @brief Sobrecarga del operador ++
         * @return Devuelve el iterador constante de la siguiente posicion
         */
        const_iterator operator++()
        {
            puntero++;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador --
         * @return Devuelve el iterador constante de la anterior posicion
         */
        const_iterator operator--()
        {
            puntero--;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador !=
         * @param v iterador constante
         * @return Devuelve true si la posicion de los iteradores constantes son distintos y false si son iguales 
         */
        bool operator!=(const const_iterator &v) const
        {
            return puntero != v.puntero;
        }
        /**
         * @brief Sobrecarga del operador ==
         * @param v Iterador constante
         * @return Devuelve true si la posicion de los iteradores son iguales y false si no lo son 
         */
        bool operator==(const const_iterator &v) const
        {
            return puntero == v.puntero;
        }

        friend class recetas;
    };
    /**
   * @brief Primer elemento del map
   * @return Iterador constante señalando al primer elemento
   */
    const_iterator cbegin() const
    {
        const_iterator i;
        i.puntero = datos.cbegin();
        return i;
    }
    /**
   * @brief Último elemento del map
   * @return Iterador constante señalando al último elemento
   */
    const_iterator cend() const
    {
        const_iterator i;
        i.puntero = datos.cend();
        return i;
    }
};

    receta fusionarRecetas(recetas &allrecet, string code1, string code2);


#endif /* RECETAS_H */
