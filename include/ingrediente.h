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
    float hidratos;
    float proteinas;
    float grasas;
    float fibra;
    string tipo;
public:
    Ingrediente();
    Ingrediente(string n, string t);
    Ingrediente(string n, int c, float h, float p, float g, float f,string t);
    string getNombre() const;
    string getTipo() const;
    int getCalorias() const;
    float getHidratos() const;
    float getGrasas() const;
    float getFibra() const;
    float getProteinas() const;
    void setIngrediente(string n, string t);
    void setIngrediente(string n, int c, float h, float p, float g, float f,string t);
    void setNombre(string n);
    void setCalorias(int c);
    void setHidratos(float h);
    void setProteinas(float p);
    void setGrasas(float g);
    void setFibra(float f);
    void setTipo(string t);
    void operator=(const Ingrediente &P);
    friend std::istream & operator>>(std::istream & is, Ingrediente & p);
    friend std::ostream& operator<<(std::ostream& os, const Ingrediente& p);
    
    
    
    
    
    
};


#endif /* INGREDIENTE_H */
