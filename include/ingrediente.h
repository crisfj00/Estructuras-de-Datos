/**
  * @file Ingrediente.h
  * @brief Fichero cabecera del TDA ingrediente
  *
  */


#ifndef INGREDIENTE
#define INGREDIENTE

#include<iostream>
#include <string.h>


using namespace std;


/**
  *  @brief T.D.A. ingrediente
  *
  * Representa un ingrediente alimenticio. Los atributos de un ingrediente
  * es el nombre (puede estar formado por varias palabras) y numero de calori­as que
  * aporta cada 100 gramos. Tambien se especifica para el alimento los porcentajes de los
  * nutrientes esenciales (hidratos de carbono, protei­nas, grasas y fibra) presentes en el
  * alimento. Finalmente se indica el tipo de alimento, por ejemplo: verdura, carne,
  * pescado, etc. Se representa:
  *
  * Alimento (100 gramos);Calorias (Kcal.);Hidratos de Carb.;Proteinas;Grasas;Fibra;Tipo
  *
  * 
  *
  * @author Fran Jimenez
  * @author Cristian Fernandez
  * @date Marzo 2008
  */

class ingrediente {

 private:
/**
  * @page repConjunto Rep del TDA ingrediente
  *
  * @section invConjunto Invariante de la representacion
  *
  * El invariante es rep.{calorias,hidratos,proteinas,grasas,fibra} >= 0
  *
  * @section faConjunto Funcion de abstraccion
  *
  * Un objeto valido @e rep del TDA ingrediente representa 
  *
  * Alimento ;Calorias ;Hidratos de Carb.;Proteinas;Grasas;Fibra;Tipo
  *
  */

  string nombre;
  float calorias;
  float hidratos;
  float proteinas;
  float grasas;
  float fibra;
  string tipo;

 public:

  /**
  * @brief Constructor por defecto de la clase. 
  * @return Inicializa el ingrediente a 0
  */
  ingrediente();
  
  /**
  * @brief Constructor de la clase. Inicializa el ingrediente a 0 y pone su nombre y su tipo
  * @param n nombre del ingrediente
  * @param t tipo del ingrediente
  * @return Inicializa el ingrediente a 0 y pone su nombre y su tipo
  */
  ingrediente(string n, string t );

  /**
  * @brief Constructor de la clase
  * @param n nombre del ingrediente
  * @param c cantidad de calorias del ingrediente
  * @param hc cantidad de hidratos de carbono del ingrediente
  * @param p cantidad de proteinas del ingrediente
  * @param g cantidad de grasas del ingrediente
  * @param f cantidad de fibras del ingrediente
  * @param t tipo del ingrediente
  * @return Crea el ingrediente
  * @pre calorias, hidratos, proteinas,grasas,fibras tiene que ser mayor o igual que 0
  */
  ingrediente(string n, float c, float hc, float p, float g, float f, string t);


  /**
  * @brief Consultor del nombre del ingrediente
  * @return devuelve el nombre del ingrediente
  */
  string getNombre() const ;

  /**
  * @brief Consultor de la cantidad de calorias del ingrediente
  * @return devuelve la cantidad de calorias del ingrediente
  */
  float getCalorias() const;
  
  /**
  * @brief Consultor de la cantidad de hidratos de carbono del ingrediente
  * @return devuelve la cantidad de hidratosd e carbono del ingrediente
  */
  float getHc() const;

  /**
  * @brief Consultor de la cantidad de proteinas del ingrediente
  * @return devuelve la cantidad de proteinas del ingrediente
  */
  float getProteinas() const;
  
  /**
  * @brief Consultor de la cantidad de grasas del ingrediente
  * @return devuelve la cantidad de grasas del ingrediente
  */
  float getGrasas() const;

  /**
  * @brief Consultor de la cantidad de fibra del ingrediente
  * @return devuelve la cantidad de fibra del ingrediente
  */
  float getFibra() const ;

  /**
  * @brief Consultor del tipo del ingrediente
  * @return devuelve el tipo del ingrediente
  */
  string getTipo() const;
  
  /**
  * @brief Modificador del nombre y tipo del ingrediente
  * @param n nombre del ingrediente 
  * @param t tipo del ingrediente
  */
  void setIngrediente(string n , string t);

  /**
  * @brief Modificador de un ingrediente
  * @param n nombre del ingrediente
  * @param c cantidad de calorias del ingrediente
  * @param hc cantidad de hidratos de carbono del ingrediente
  * @param p cantidad de proteinas del ingrediente
  * @param g cantidad de grasas del ingrediente
  * @param f cantidad de fibras del ingrediente
  * @param t tipo del ingrediente
  * @pre calorias, hidratos, proteinas,grasas,fibras tiene que ser mayor o igual que 0
  */
  void setIngrediente(string n, float c, float h, float p, float g, float f, string t);

  /**
   * @brief Modificador del nombre del ingrediente
   * @param n nombre del ingrediente
   */
  void setNombre(string n);

  /**
   * @brief Modificador de las calorias del ingrediente
   * @param c cantidad de calorias del ingrediente
   */
  void setCalorias(float c);

  /**
   * @brief Modificador de las hidratos de carbono del ingrediente
   * @param hc cantidad de hidratos de carbono del ingrediente
   */
  void setHidratos(float hc);

  /**
   * @brief Modificador de las proteinas del ingrediente
   * @param p cantidad de proteinas del ingrediente
   */
  void setProteinas(float p);

  /**
   * @brief Modificador de las grasas del ingrediente
   * @param g cantidad de grasas del ingrediente
   */
  void setGrasas(float g);

  /**
   * @brief Modificador de la fibra del ingrediente
   * @param f cantidad de fibra del ingrediente
   */
  void setFibra(float f);

  /**
   * @brief Modificador del tipo del ingrediente
   * @param t tipo del ingrediente
   */
  void setTipo(string t);

  /**
   * @brief Sobrecarga del operador =
   * @param P ingrediente
   * @return Asigna al objeto implícito el ingrediente
   */
  void operator=(const ingrediente &P);

 /**
  * @brief Entrada de un ingrediente desde istream
  * @param is stream de entrada
  * @param p ingrediente que recibe el valor
  * @retval El ingrediente leído en p
  */
  friend std::istream & operator>>(std::istream &is , ingrediente &p);

  /**
  * @brief Salida de un  a ostream
  * @param os stream de salida
  * @param p ingrediente a escribir
  * @post Se obtiene en \a os la cadena del ingrediente con los valores
  *   del ingredeiente de \a p
  */
  friend std::ostream & operator<<(std::ostream &os , const ingrediente &p);
  
  bool operator==(const ingrediente &otro) const;

};
#endif