#include <iostream>
#include "receta.h"
#include <cmath>
#include <cassert>
#include <string.h>
#include <string>
#include <cctype>

using namespace std;

    receta::receta(){
        code="00";
        plato=-1;
        nombre="DEFAULT";
        calorias=0;
        hc=0;
        proteinas=0;
        fibra=0;
        grasas=0;
    }
    
    receta::receta(const receta& p){
        code=p.getCode();
        plato=p.getPlato();
        nombre=p.getNombre();
        ings=p.getListaIngredientes();
        calorias=p.getCalorias();
        hc=p.getHc();
        grasas=p.getGrasas();
        proteinas=p.getProteinas();
        fibra=p.getFibra();
    }
    
    receta::~receta(){}

    string receta::getCode()const{
        return code;
    }
    
    unsigned int receta::getPlato() const{
        return plato;
    }
    
    string receta::getNombre() const{
        return nombre;
    }
    
    float receta::getCalorias() const{
        return calorias;
    }
    
    float receta::getHc() const{
        return hc;
    }
    
    float receta::getGrasas() const{
        return grasas;
    }
    
    float receta::getProteinas() const{
        return proteinas;
    }
    
    float receta::getFibra() const{
        return fibra;
    }
    
    long unsigned int receta::ningredientes() const{
        return ings.size();
    }    
    
    void receta::setCode(string c){
        code=c;
    }
    
    void receta::setPlato(unsigned int p){
        plato=p;
    }
    
    void receta::setNombre(string n) {
        nombre=n;
    }
    
    
    void receta::setCalorias(float cal) {
        calorias=cal;
    }
    
    void receta::setHc(float h) {
        hc=h;
    }
    
    void receta::setGrasas(float g) {
        grasas=g;
    }
    
    void receta::setProteinas(float p) {
        proteinas=p;
    }
    
    void receta::setFibra(float f) {
        fibra=f;
    }
    
    void receta::actualizarNutrientes(const ingredientes & ingre){
        float calorias, hc, grasas, proteinas, fibra;
        calorias=0;
        hc=0;
        grasas=0;
        proteinas=0;
        fibra=0;
        for(receta::iterator its=begin(); its!=end(); ++its){ //OBTENEMOS DE ingredientes SUS VALORES Y LOS ASIGNAMOS A LAS RECETAS
            ingrediente i=ingre.get((*its).first);
            calorias+=i.getCalorias()*(*its).second/100;
            hc+=i.getHc()*(*its).second/100;
            grasas+=i.getGrasas()*(*its).second/100;
            proteinas+=i.getProteinas()*(*its).second/100;
            fibra+=i.getFibra()*(*its).second/100;
        }

        setCalorias(calorias);
        setHc(hc);
        setGrasas(grasas);
        setProteinas(proteinas);
        setFibra(fibra);        
    }

    
    const pair<string,unsigned int> receta::getIngrediente(int i) const{
        list<pair<string,unsigned int>>::const_iterator it=ings.begin();
        advance(it,i);
        return *it;
    }
    
    pair<string,unsigned int> & receta::obtenerIngrediente(int i){
        list<pair<string,unsigned int>>::iterator it=ings.begin();
        advance(it,i);
        return *it;
    }
    
    const pair<string,unsigned int> &receta::operator[] (int i) const{ 
        list<pair<string,unsigned int>>::const_iterator it=ings.begin();
        advance(it,i);
        return *it;
    }
    
    pair<string,unsigned int> & receta::operator[](int i){
        
        return obtenerIngrediente(i);
    }
    
    list<pair<string,unsigned int>> receta::getListaIngredientes() const{
        return ings;
    }


    void receta::operator=(const receta &P){
        
        code=P.getCode();
        plato=P.getPlato();
        nombre=P.getNombre();
        ings=P.getListaIngredientes();
        calorias=P.getCalorias();
        hc=P.getHc();
        grasas=P.getGrasas();
        proteinas=P.getProteinas();
        fibra=P.getFibra();
    }
    
    
    void receta::aniadirIngrediente(const pair<string,unsigned int> & p){
        ings.push_back(p);
    }

    
    std::ostream& operator<<(std::ostream& os, const receta& p) {

        os << p.getCode() << ";" << p.getPlato() << ";" << p.getNombre();
        
        for(long unsigned int i=0; i<p.ningredientes();i++){
            os << ";" << p[i].first << " "<< p[i].second;
        }
        
        os << "\n";

        return os;
    }   

    std::istream & operator>>(std::istream & is, receta & p){
        if(!p.ings.empty())
            p.ings.clear();
        
        char cadena[256];
        char numero[256];
        is.getline(cadena,256, ';'); //CODE
        p.setCode(cadena);
        is.getline(cadena,256, ';'); //PLATO
        p.setPlato(stoi(cadena));
        is.getline(cadena,256, ';'); //NOMBRE
        p.setNombre(cadena);
        
        bool encontrado=false;
        
        while(!encontrado){
        int posANTES = is.tellg();
        int poscoma;
        is.getline(cadena,256,'\n');
        for(size_t i=0; !encontrado &&i<strlen(cadena);i++){     //BORRAR CADENAS DESPUÉS DEL ';'
            if(!encontrado && cadena[i]==';'){
                encontrado=true;
                poscoma=i;
            }
            
        }
        if(!encontrado)
            poscoma=strlen(cadena);
        string cadena2=cadena;
        cadena2=cadena2.substr(0,poscoma);
        int posEntero=cadena2.size()-1;
        for(int i=cadena2.size()-1; i>0;i--){
            if(isdigit(cadena2[i]))
                posEntero=i;   
        }
        cadena2=cadena2.substr(0,posEntero-1);  //BORRAR EL NUMERO
        is.seekg(posANTES+cadena2.size());      //CAMBIAR EL OFFSET JUSTO DESPUÉS DEL NOMBRE DEL INGREDIENTE
        
        
        if(encontrado){
            is.getline(numero,256,';');
            encontrado=false;
        }
        else{
            is.getline(numero,256,'\n');    
            encontrado=true;
        }
        //LEER EL NUMERO
        pair<string,unsigned int> nuevo;
        
        nuevo.first=cadena2;
        nuevo.second=stoul(numero);
        
        p.aniadirIngrediente(nuevo);
        

        //LEER CADENA, CAMBIAR OFFSET Ó BORRAR A PARTIR DEL PUNTO Y COMA DETECTADO
        
        }
        
        

        
        return is;

    }