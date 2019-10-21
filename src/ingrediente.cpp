/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "ingrediente.h"

using namespace std;

//CONSTRUCTOR POR DEFECTO
    Ingrediente::Ingrediente(){
        nombre="";
        calorias=0;
        hidratos=0;
        proteinas=0;
        grasas=0;
        fibra=0;   
        tipo="DEFECTO";
    }

    Ingrediente::Ingrediente(string n, string t){
        Ingrediente();
        nombre=n;
        tipo=t;
    }

    Ingrediente::Ingrediente(string n, int c, int  h, int p, int g, int f,string t){
        Ingrediente(n,t);
        calorias=c;
        hidratos=h;
        proteinas=p;
        grasas=g;
        fibra=f;
    }
    

    string Ingrediente::getNombre() const{
        return nombre;
    }

    string Ingrediente::getTipo() const{
        return tipo;
    }

    int Ingrediente::getCalorias() const{
        return calorias;
    }

    int Ingrediente::getHc() const{
        return hidratos;
    }

    int Ingrediente::getGrasas() const{
        return grasas;
    }

    int Ingrediente::getFibra() const{
        return fibra;
    }

    int Ingrediente::getProteinas() const{
        return proteinas;
    }

    void Ingrediente::setIngrediente(string n, string t){
        nombre=n;
        tipo=t;
    }
    void Ingrediente::setIngrediente(string n, int c, int h, int p, int g, int f,string t){
        nombre=n;
        calorias=c;
        hidratos=h;
        proteinas=p;
        grasas=g;
        fibra=f;
        tipo=t;
    }
    void Ingrediente::setNombre(string n){
        nombre=n;
    }
    void Ingrediente::setCalorias(int c){
        calorias=c;
    }
    void Ingrediente::setHidratos(int h){
        hidratos=h;
    }
    void Ingrediente::setProteinas(int p){
        proteinas=p;
    }
    void Ingrediente::setGrasas(int g){
        grasas=g;
    }
    void Ingrediente::setFibra(int f){
        fibra=f;
    }
    void Ingrediente::setTipo(string t){
        tipo=t;
    }



    void Ingrediente::operator=(const Ingrediente &P){
        nombre=P.getNombre();
        calorias=P.getCalorias();
        hidratos=P.getHc();
        proteinas=P.getProteinas();
        fibra=P.getFibra();
        grasas=P.getGrasas();
        tipo=P.getTipo();
    }
    
    
    std::ostream& operator<<(std::ostream& os, const Ingrediente& p) {

        os << p.getNombre() << ";" << p.getCalorias() << ";" << p.getHc() << ";" << p.getProteinas() << ";" << p.getGrasas() << ";" << p.getFibra() << ";" << p.getTipo() << "\n";

        return os;
    }   
/*
    std::istream & operator>>(std::istream & is, Ingrediente & p){
        getline(p.nombre,';');
        is >> p.nombre;
        is >> p.calorias >> p.hidratos >> p.proteinas >> p.grasas >> p.fibra;
        is >> p.tipo;
        return is;

    }
    */

