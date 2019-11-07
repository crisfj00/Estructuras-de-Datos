/* 
 * File:   ingredientes.h
 * Author: cristian
 *
 * Created on 19 de octubre de 2019, 17:05
 */

/**
  * @file ingredientes.h
  * @brief Fichero cabecera del TDA ingredientes
  *
  */

#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include "ingrediente.h"
#include <vector>
#include <iostream>
#include <set>

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
  * @date Octubre 2019
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
    vector<ingrediente> datos; 
    vector<int> indices;
    
public:
    
    /**
     * @brief Constructor por defecto del vector ingredientes
     */
    ingredientes();

    /**
     *@brief Contructor de copia de un vector de ingredientes
     */
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

    
    
    /**
   * @brief Consultor del numero de elementos del vector
   * @return Devuelve el numero de elementos del vector
   */
    int size() const;
    
    /**
   * @brief Consultor del atributo de esa posicion
   * @param pos Posicion que queremos obtener
   * @return Devuelve el ingrediente que esta en la posicon pasada como parametro
   */
    const ingrediente& get(int pos) const;
    
    /**
     * @brief Consultor del atributo segun el nombre en el vector
     * @param n Nombre del ingredeinte 
     * @return Devuelve los valores del ingrediente que tenga el nombre pasado como argumento
     */
    
    const ingrediente& get(string n) const;

    /**
   * @brief Metodo para borrar el ingrediente de nombre n
   * @param n Nombre del ingrediente que queremos borrar del vector de ingredientes
   */
    void borrar(string n);

     /**
   * @brief Metodo para añadir un ingrediente en el orden pedido (por nombre o por tipo)
   * @param p ingrediente que queremos añadir al vector
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
    const ingrediente& operator[] (int i) const;

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
    friend std::ostream & operator<<(std::ostream &os , const ingredientes &p);
    
    /**
     * @brief Metodo que imprime el vector ordenado por el tipo del ingrediente
     * @param flujo stream del salida
     */
    
    void ImprimirPorTipo(ostream& flujo);
    
    /**
     * @brief Metodo que imprime el vector ordenado por el nombre del ingrediente
     * @param flujo stream del salida
     */
    
    void ImprimirPorNombre(ostream& flujo);
        
    /**
     * @brief Metodo que busca si esta el ingrediente pasado como parametro en el vector
     * @param p Ingrediente a  buscar 
     * @return Devuelve true si esta el ingrediente dentro del vector o false si no esta
     */
    
    bool incluidoIngrediente(const ingrediente &p)const;
    
    /**
     * @brief Sobrecarga del operador [] (Se puede modificar)
     * @param i Posicion del ingediente en el vector
     * @return Devuelve el ingrediente que esta en la posicion pasada como parametro
     */
    
    ingrediente & operator[](int i);
    
    /**
     * @brief Consultor de los tipos que hay en el vector de ingredientes
     * @return Devuelve todos los tios que estan denro del vector 
     */
    
    vector<string> getTipos();
    
    /**
     * @brief Metodo del vector filtrado por el tipo
     * @param tipo Tipo del ingrediente a comparar
     * @return Devuelve un vector de ingredientes con el mismo tipo (ordenado por nombre) 
     */
    
    ingredientes getIngredienteTipo(string tipo);
    
    
    /**
     * @brief Metodo que hace la Media de todos los ingredientes del mismo tipo sobre uno de los valores nutricionales
     * @param atributo Caracter que se refiere a un valor nutricional:
     *
     * 		-"C" Calorias
     * 		-"P" Proteinas
     * 		-"G" Grasas
     * 		-"F" Fibra
     * 		-"H" Hidratos de carbono
     * 
     * @param tipo Tipo del ingrediente 
     * @return Devuelve la Media de todos los ingredientes del mismo tipo sobre uno de los valores nutricionales
     */
    double getMedia(char atributo, string tipo);

     /**
     * @brief Metodo que hace la Desviacion Tipica de todos los ingredientes del mismo tipo sobre uno de los valores nutricionales
     * @param atributo Caracter que se refiere a un valor nutricional:
     *
     * 		-"C" Calorias
     * 		-"P" Proteinas
     * 		-"G" Grasas
     * 		-"F" Fibra
     * 		-"H" Hidratos de carbono
     *
     * @param tipo Tipo del ingrediente 
     * @return Devuelve la Desviacion Tipica de todos los ingredientes del mismo tipo sobre uno de los valores nutricionales
     */
    double getDesviacion(char atributo, string tipo);
    
     /**
     * @brief Metodo que Calcula el Maximo Ingrediente de todos los ingredientes del mismo tipo que tiene mas grande uno de los valores nutricionales
     * @param atributo Caracter que se refiere a un valor nutricional:
     *
     * 		-"C" Calorias
     * 		-"P" Proteinas
     * 		-"G" Grasas
     * 		-"F" Fibra
     * 		-"H" Hidratos de carbono
     *
     * @param tipo Tipo del ingrediente 
     * @return Devuelve el Maximo Ingrediente de todos los ingredientes del mismo tipo que tiene mas grande el valor nutricional pasado como parametro
     */
    ingrediente getMaximo(char atributo, string tipo);

     /**
     * @brief Metodo que Calcula el Minimo Ingrediente de todos los ingredientes del mismo tipo que tiene mas grande uno de los valores nutricionales
     * @param atributo Caracter que se refiere a un valor nutricional:
     *
     * 		-"C" Calorias
     * 		-"P" Proteinas
     * 		-"G" Grasas
     * 		-"F" Fibra
     * 		-"H" Hidratos de carbono
     *
     * @param tipo Tipo del ingrediente 
     * @return Devuelve el Minimo Ingrediente de todos los ingredientes del mismo tipo que tiene mas grande el valor nutricional pasado como parametro
     */
    ingrediente getMinimo(char atributo, string tipo);
    
    /*
    class iterador{
    private:
        vector<ingrediente>::iterator it;
    };
     
    
    class const_iterador{
    private:
        vector<ingrediente>::const_iterator it;
    };
     */
    
    typedef set<ingrediente>::iterator iterator;
    typedef set<ingrediente>::const_iterator const_iterator;
    
    ingredientes::iterator begin();   
    ingredientes::iterator end();
    
    ingredientes::const_iterator begin() const;
    ingredientes::const_iterator end() const;
    
    
};


#endif /* INGREDIENTES_H */
