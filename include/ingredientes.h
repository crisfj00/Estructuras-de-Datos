/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ingredientes.h
 * Author: cristian
 *
 * Created on 19 de octubre de 2019, 17:05
 */

#include "ingrediente.h"
#include <iostream>



#ifndef INGREDIENTES_H
#define INGREDIENTES_H
class Ingredientes{
private:
    vector_dinamico<Ingrediente> datos;
    vector_dinamico<int> indices;
    //OTRO VECTOR DE INDICES ORDENADO POR TIPO Y NOMBRE
    
public:
    Ingredientes(int util);
    
    Ingredientes(const Ingredientes& original);
    
    int buscar(const Ingrediente &p);
    
    void operator=(const Ingredientes &original);
    
    ~Ingredientes();

    int getNumElementos() const;
    
    Ingrediente get(int pos) const;

    void borrar(int pos);

    //SE AÑADE EN LA POSICION QUE TOQUE SEGUN EL ORDEN
    //BUSQUEDA BINARIA, VER SI ESTÁ EL ELEMENTO O CONSEGUIR LA POS
    //TODOS LOS ELEMENTOS DEL VECTOR INDICE QUE SE ENCUENTREN EN superior a pos normal se incrementan en 1
    void aniadir(const Ingrediente &p);

    void operator+=(const Ingrediente &p);
    
    Ingrediente& obtener(int pos);


    Ingrediente& operator[] (int i);
     
    Ingrediente operator[] (int i) const;

};


#endif /* INGREDIENTES_H */

