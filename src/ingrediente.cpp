/*
 * 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "ingrediente.h"

using namespace std;

//CONSTRUCTOR POR DEFECTO
    ingrediente::ingrediente(){
        nombre="";
        calorias=0;
        hidratos=0;
        proteinas=0;
        grasas=0;
        fibra=0;   
        tipo="DEFECTO";
    }

    ingrediente::ingrediente(string n, string t){
        nombre=n;
        tipo=t;
        calorias=0;
        hidratos=0;
        proteinas=0;
        grasas=0;
        fibra=0;   
    }

    ingrediente::ingrediente(string n, float c, float  h, float p, float g, float f,string t){
        nombre=n;
        tipo=t;
        calorias=c;
        hidratos=h;
        proteinas=p;
        grasas=g;
        fibra=f;
    }
    

    string ingrediente::getNombre() const{
        return nombre;
    }

    string ingrediente::getTipo() const{
        return tipo;
    }

    float ingrediente::getCalorias() const{
        return calorias;
    }

    float ingrediente::getHc() const{
        return hidratos;
    }

    float ingrediente::getGrasas() const{
        return grasas;
    }

    float ingrediente::getFibra() const{
        return fibra;
    }

    float ingrediente::getProteinas() const{
        return proteinas;
    }

    void ingrediente::setIngrediente(string n, string t){
        nombre=n;
        tipo=t;
    }
    void ingrediente::setIngrediente(string n, float c, float h, float p, float g, float f,string t){
        nombre=n;
        calorias=c;
        hidratos=h;
        proteinas=p;
        grasas=g;
        fibra=f;
        tipo=t;
    }
    void ingrediente::setNombre(string n){
        nombre=n;
    }
    void ingrediente::setCalorias(float c){
        calorias=c;
    }
    void ingrediente::setHidratos(float h){
        hidratos=h;
    }
    void ingrediente::setProteinas(float p){
        proteinas=p;
    }
    void ingrediente::setGrasas(float g){
        grasas=g;
    }
    void ingrediente::setFibra(float f){
        fibra=f;
    }
    void ingrediente::setTipo(string t){
        tipo=t;
    }



    void ingrediente::operator=(const ingrediente &P){
        nombre=P.getNombre();
        calorias=P.getCalorias();
        hidratos=P.getHc();
        proteinas=P.getProteinas();
        fibra=P.getFibra();
        grasas=P.getGrasas();
        tipo=P.getTipo();
    }
    
    
    std::ostream& operator<<(std::ostream& os, const ingrediente& p) {

        os << p.getNombre() << ";" << p.getCalorias() << ";" << p.getHc() << ";" << p.getProteinas() << ";" << p.getGrasas() << ";" << p.getFibra() << ";" << p.getTipo() << "\n";

        return os;
    }   

    std::istream & operator>>(std::istream & is, ingrediente & p){
        char nombre[256], tipo[256];
        char calorias[256], hidratos[256], grasas[256], proteinas[256], fibra[256];
        
        is.getline(nombre,256, ';');
        is.getline(calorias,256, ';');
        is.getline(hidratos,256, ';');
        is.getline(proteinas,256, ';');
        is.getline(grasas,256, ';');
        is.getline(fibra,256, ';');
        is.getline(tipo,256, '\n'); //cambiar ultimo elemento de ingredientes.txt, eliminar ';'
        
        p.setNombre(nombre);
        p.setCalorias(stof(calorias));
        p.setFibra(stof(fibra));
        p.setGrasas(stof(grasas));
        p.setHidratos(stof(hidratos));
        p.setProteinas(stof(proteinas));
        p.setTipo(tipo);
        
        return is;

    }
    
      bool ingrediente::operator==(const ingrediente &otro) const{
      bool iguales=false;
      if(nombre==otro.getNombre())
          iguales=true;
      return iguales;
  }
    

