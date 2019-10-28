/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector_dinamico.h
 * Author: cristian
 *
 * Created on 18 de octubre de 2019, 19:30
 */

#ifndef VECTOR_DINAMICO_H
#define VECTOR_DINAMICO_H
/**
  * @file vector_dinamico.h
  * @brief Fichero cabecera del TDA vector_dinamico
  *
  */

  /**
  *  @brief T.D.A. Vector_Dinamico
  *
  * Representa un vector dinamico de cualquier tipo de dato y sus diferentes metodos
  *
  *
  * @author Fran Jimenez
  * @author Cristian Fernandez
  * @date Octubre 2019
  */
template <class T>
class vector_dinamico {
    private:
  /**
  * @page repConjunto Rep del TDA Vector_Dinamico
  *
  * @section invConjunto Invariante de la representacion
  *
  * Los invariantes son rep.reservados>0 y rep.util
  * 
  *
  *
  *
  */
        T *datos;
        int reservados=0;
        int util=0;
        
    public:
	/**
	* @brief Constructor del vector dinamico por defecto
	* @param n Espacio reservado
	*/
        vector_dinamico(int n=10);

	/**
	* @brief Constructor de copia de un vector dinamico
	* @param original vector dinamico que se va a copiar
	*/
        vector_dinamico(const vector_dinamico& original);
	/**
	* @brief Destructor del vector dinamico
	*/
        ~vector_dinamico();

	/**
	* @brief Consultor del tamaño del vector(No permite modificar)
	* @return Devuelve el espacio reservado para el vector
	*/
        int size() const;

	/**
	* @brief Consultor del espacio ocupado en el vector 
	* @return Devuelve el espacio ocupado en el vector
	*/
        int getUtil() const;

	/**
	* @brief Consultor de una posicion en el vector
	* @param i Posicion a consultar
	* retrun Devuelve el valor de la posicion (cualquier tipo de dato)
	*/
        const T& get(int i)const;

	/**
	* @brief Modificador del valor de una posicion del vector
	* @param i indice del vector(Posicion)
	* @param v dato a insertar en la posicion pasada como parametro
	*/
        void set(int i, T v);
	
	/**
	* @brief Metodo para reubicar el vector en un espacio de memoria mas grande
	* @brief n nuevo tamaño de memoria reservada
	*/
        void resize(int n);

	/**
	* @brief Sobrecarga del operador [] (Permite modificar)
	* @param i posicion en el vector
	* @return Devuelve el valor que hay en el vector de la posicion pasada como parametro
	*/
        T &operator[](int i);

	/**
	* @brief Sobrecarga del operador [] (No Permite modificar)
	* @param i posicion en el vector
	* @return Devuelve el valor que hay en el vector de la posicion pasada como parametro
	*/
        const T &operator[](int i) const;   
    
	/**
  	 * @brief Sobrecarga del operador =
  	 * @param original Vector dinamico
  	 * @return Asigna al objeto implícito el vector
  	 */
        vector_dinamico & operator=(const vector_dinamico& original);

	/**
   	* @brief Metodo para añadir un elemeto al final del vector
 	* @param otro Dato que queremos añadir al vector
 	*/
        void aniadir(T otro);
	
	/**
	* @brief Metodo para consultar el valor de una posicion en el vector (Permite modificar)
	* @param i Posicion a consultar
	* @retrun Devuelve el valor de la posicion (cualquier tipo de dato)
	*/
        T& obtener(int i);

	/**
  	* @brief Metodo para añadir un elemento
  	* @param i Posicion en el vector
	* @param otro Dato que queremos añadir
  	*/
        void insertar(int i, T otro);
	/**
	* @brief Metodo para liberar el vector
	*/
        void Liberar();
	/**
	* @brief Metodo para borrar una posicion en el vector
	* @param pos Posicion a borrar
	*/
        void borrar(int pos);
};
//#include "vector_dinamico.cpp"

#endif /* VECTOR_DINAMICO_H */


