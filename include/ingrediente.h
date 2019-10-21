/**
  * @file Ingrediente.h
  * @brief Fichero cabecera del TDA Ingrediente
  *
  */

#ifndef INGREDIENTE
#define INGREDIENTE

#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. Ingrediente
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

class Ingrediente {

 private:
/**
  * @page repConjunto Rep del TDA Ingrediente
  *
  * @section invConjunto Invariante de la representacion
  *
  * El invariante es rep.{calorias,hidratos,proteinas,grasas,fibra} >= 0
  *
  * @section faConjunto Funcion de abstraccion
  *
  * Un objeto valido @e rep del TDA Ingrediente representa 
  *
  * Alimento ;Calorias ;Hidratos de Carb.;Proteinas;Grasas;Fibra;Tipo
  *
  */

  string nombre;
  int calorias;
  int hidratos;
  int proteinas;
  int grasas;
  int fibra;
  string tipo;

 public:

  /**
  * @brief Constructor por defecto de la clase. 
  * @return Inicializa el ingrediente a 0
  */
  Ingrediente();
  
  /**
  * @brief Constructor de la clase. Inicializa el ingrediente a 0 y pone su nombre y su tipo
  * @param n nombre del ingrediente
  * @param t tipo del ingrediente
  * @return Inicializa el ingrediente a 0 y pone su nombre y su tipo
  */
  Ingrediente(string n, string t );

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
  Ingrediente(string n, int c, int hc, int p, int g, int f, string t);


  /**
  * @brief Consultor del nombre del ingrediente
  * @return devuelve el nombre del ingrediente
  */
  string getNombre() const ;

  /**
  * @brief Consultor de la cantidad de calorias del ingrediente
  * @return devuelve la cantidad de calorias del ingrediente
  */
  int getCalorias() const;
  
  /**
  * @brief Consultor de la cantidad de hidratos de carbono del ingrediente
  * @return devuelve la cantidad de hidratosd e carbono del ingrediente
  */
  int getHc() const;

  /**
  * @brief Consultor de la cantidad de proteinas del ingrediente
  * @return devuelve la cantidad de proteinas del ingrediente
  */
  int getProteinas() const;
  
  /**
  * @brief Consultor de la cantidad de grasas del ingrediente
  * @return devuelve la cantidad de grasas del ingrediente
  */
  int getGrasas() const;

  /**
  * @brief Consultor de la cantidad de fibra del ingrediente
  * @return devuelve la cantidad de fibra del ingrediente
  */
  int getFibra() const ;

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
  void setIngrediente(string n, int c, int h, int p, int g, int f, string t);

  /**
   * @brief Modificador del nombre del ingrediente
   * @param n nombre del ingrediente
   */
  void setNombre(string n);

  /**
   * @brief Modificador de las calorias del ingrediente
   * @param c cantidad de calorias del ingrediente
   */
  void setCalorias(int c);

  /**
   * @brief Modificador de las hidratos de carbono del ingrediente
   * @param hc cantidad de hidratos de carbono del ingrediente
   */
  void setHidratos(int hc);

  /**
   * @brief Modificador de las proteinas del ingrediente
   * @param p cantidad de proteinas del ingrediente
   */
  void setProteinas(int p);

  /**
   * @brief Modificador de las grasas del ingrediente
   * @param g cantidad de grasas del ingrediente
   */
  void setGrasas(int g);

  /**
   * @brief Modificador de la fibra del ingrediente
   * @param f cantidad de fibra del ingrediente
   */
  void setFibra(int f);

  /**
   * @brief Modificador del tipo del ingrediente
   * @param t tipo del ingrediente
   */
  void setTipo(string t);

  /**
   * @brief Sobrecarga del operador =
   * @param P Ingrediente
   * @return Asigna al objeto implícito el ingrediente
   */
  void operator=(const Ingrediente &P);

 /**
  * @brief Entrada de un ingrediente desde istream
  * @param is stream de entrada
  * @param p Ingrediente que recibe el valor
  * @retval El ingrediente leído en p
  */
  friend std::istream & operator>>(std::istream &is , Ingrediente &p);

  /**
  * @brief Salida de un  a ostream
  * @param os stream de salida
  * @param p Ingrediente a escribir
  * @post Se obtiene en \a os la cadena del ingrediente con los valores
  *   del ingredeiente de \a p
  */
  friend std::ostream & operator<<(std::ostream &os , const Ingrediente &p);
