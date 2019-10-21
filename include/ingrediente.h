/* 
 * File:   ingrediente.h
 * Author: cristian
 * Author: fran
 *
 * Created on 7 de octubre de 2019, 11:22
 */
#include <string>
#include <iostream>

using namespace std;

#ifndef INGREDIENTE_H
#define INGREDIENTE_H

class Ingrediente{
private:
    string nombre;
    int calorias;
    int hidratos;
    int proteinas;
    int grasas;
    int fibra;
    string tipo;
public:
    Ingrediente();
    Ingrediente(string n, string t);
    Ingrediente(string n, int c, int h, int p, int g, int f,string t);
    string getNombre() const;
    string getTipo() const;
    int getCalorias() const;
    int getHc() const;
    int getGrasas() const;
    int getFibra() const;
    int getProteinas() const;
    void setIngrediente(string n, string t);
    void setIngrediente(string n, int c, int h, int p, int g, int f,string t);
    void setNombre(string n);
    void setCalorias(int c);
    void setHidratos(int h);
    void setProteinas(int p);
    void setGrasas(int g);
    void setFibra(int f);
    void setTipo(string t);
    void operator=(const Ingrediente &P);
    friend std::istream & operator>>(std::istream & is, Ingrediente & p);
    friend std::ostream& operator<<(std::ostream& os, const Ingrediente& p);
    
    
    
    
    
    
};


#endif /* INGREDIENTE_H */

