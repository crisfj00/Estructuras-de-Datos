#include <iostream>
#include "receta.h"
#include <cmath>
#include <cassert>
#include <string.h>
#include <string>

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
    
    receta::receta(const receta & p){
        this=p;
    }

    string receta::getCode(){
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
    
    /*
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
    */
    const pair<string,unsigned int> receta::getIngrediente(int i) const{
        return *(ings.begin()+i);
    }
    
    pair<string,unsigned int> & receta::obtenerIngrediente(int i){
        return *(ings.begin()+i);
    }
    
    const pair<string,unsigned int> &receta::operator[] (int i) const{ 
        
       return getIngrediente(i);
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
    
    std::ostream& operator<<(std::ostream& os, const receta& p) {

        os << p.getCode() << ";" << p.getPlato() << ";" << p.getNombre();
        
        for(long unsigned int i=0; i<size();i++){
            os << ";" << p[i].first << " "<< p[i].second;
        }
        
        os << "\n";

        return os;
    }   

    std::istream & operator>>(std::istream & is, receta & p){
        
        char cadena[256];
        
        is.getline(cadena,256, ';'); //CODE
        p.setCode(cadena);
        is.getline(cadena,256, ';'); //PLATO
        p.setPlato(stoi(cadena));
        is.getline(cadena,256, ';'); //NOMBRE
        p.setNombre(cadena);
        
        
        int posANTES = is.tellg();
        is.getline(cadena,256,'\n');
        bool encontrado=false;
        for(int i=0; i<strlen(cadena);i++){
            if(!encontrado && cadena[i]==';'){
                encontrado=true;
                cadena.erase(i);
            }
            if(encontrado)
        }
        
        //LEER CADENA, CAMBIAR OFFSET Ó BORRAR A PARTIR DEL PUNTO Y COMA DETECTADO
        
        
        

        
        return is;

    }