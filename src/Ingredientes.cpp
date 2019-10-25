
#include "ingredientes.h"   
#include "vector_dinamico.cpp"
#include <iostream>
#include <string.h>

using namespace std;


ingredientes::ingredientes(){
    datos=vector_dinamico<ingrediente>(1);
    indices=vector_dinamico<int>(1);
    
}

    ingredientes::ingredientes(const ingredientes& original){
        datos=original.datos;
        indices=original.indices;
    }

    void ingredientes::operator=(const ingredientes &original){
        datos=original.datos;
        indices=original.indices;
    }
    
    int ingredientes::size(){
        return datos.getUtil();
    }
    
    
    ingredientes::~ingredientes(){
        datos.~vector_dinamico();
        indices.~vector_dinamico();
    }

    int ingredientes::getNumElementos() const{
        return datos.getUtil();
    }
    
    const ingrediente& ingredientes::get(int pos) const{
        return datos.get(pos);
    }

/*
    void Ingredientes::borrar(int pos){
        
        
        Pelota *vnuevo = new Pelota[getCapacidad()];
        
        for(int i=0,j=0; i<getCapacidad();j++){
            if(j!=pos){
             vnuevo[i] = v[j];
             i++;
            }
        }
        
        delete [] v;
        
        v=vnuevo;
        
        util--;
        
        
    }
*/
    int ingredientes::buscar(const ingrediente &p){
        
    int izda = 0;
    int dcha = datos.getUtil() - 1;
    bool encontrado = false;
    int centro;
    while (izda <= dcha && !encontrado){
        centro = (izda + dcha) / 2;
        if (datos.get(centro).getNombre() == p.getNombre())
            encontrado = true;
        else if (p.getNombre() > datos.get(centro).getNombre())
                izda = centro + 1;
            else
                dcha=centro;
    }
    
    if(encontrado)
        return -1;
    else     
    return izda;
    }
    
    int ingredientes::buscarTipo(const ingrediente &p){
        
    int izda = 0;
    int dcha = indices.getUtil() - 1;
    bool encontrado = false;
    int centro;
    while (izda <= dcha && !encontrado){
        centro = (izda + dcha) / 2;
        if(datos.get(indices.get(centro)).getNombre()==p.getNombre())
            encontrado=true;
        else if (p.getNombre() > datos.get(indices.get(centro)).getNombre())
                izda = centro + 1;
        else if (p.getNombre() == datos.get(indices.get(centro)).getNombre()){
            if(datos.get(indices.get(centro)).getTipo() < p.getTipo())
                izda=centro+1;
            else
                dcha=centro;
        }
                
    }
    
    if(encontrado)
        return -1;
    else
    return izda;
    }
    
    bool ingredientes::incluidoIngrediente(const ingrediente &p){
        
    int izda = 0;
    int dcha = datos.getUtil() - 1;
    bool encontrado = false;
    int centro;
    while (izda <= dcha && !encontrado){
        centro = (izda + dcha) / 2;
        if (datos.get(centro).getNombre() == p.getNombre())
            encontrado = true;
        else if (p.getNombre() < datos.get(centro).getNombre())
                dcha = centro - 1;
            else
                izda = centro + 1;
    }
    
    return encontrado;
    }
    



    void ingredientes::operator+=(const ingrediente &p){
        this->insertar(p);
    }
    
     
    const ingrediente &ingredientes::operator[] (int i) const{ //NO PERMITE MODIFICAR
       return datos[i];
    }
    
    ingrediente & ingredientes::operator[](int i){
        return datos[i];
    }
    
    

    std::ostream& operator<<(std::ostream& os, const ingredientes& p) {
        
        for (int i=0; i<p.getNumElementos();i++)
            os << p.get(i) << "\n" ;
            return os;
        }
    
/*
    std::istream & operator>>(std::istream & is, Ingredientes & p){
        Ingrediente pl("defecto", "defecto");
        for (int i=0; i<p.getNumElementos();i++){
            is >> pl;
            p.aniadir(pl);
        }
        return is;
    }
 */
    
    void ingredientes::ImprimirPorNombre(ostream& flujo){
        for(int i=0; i<size();i++)
            flujo << datos.get(i);
    }
    
    void ingredientes::ImprimirPorTipo(ostream& flujo){
        for(int i=0; i<size(); i++)
            flujo << datos.get(indices.get(i));
    }
    
    bool ingredientes::insertar(const ingrediente& otro){

        bool insertado=false;
        int pos_d, pos_i;
        string nombre=otro.getNombre(), tipo=otro.getTipo();
        
        for(int i=0; i<datos.getUtil() && !insertado;i++){
            if(nombre.compare(datos.get(i).getNombre())<0){
                pos_d=i;
                datos.insertar(pos_d,otro);
                insertado=true;
            }
        }
        
        if(!insertado){
            int i=datos.getUtil();
            datos.insertar(datos.getUtil(),otro);
            pos_d=i;
        }
 
        /*
        for(int i=0; i<indices.getUtil();i++){
            pos_i=indices.get(i);
            if(tipo.compare(datos.get(pos_i).getTipo())>0)
                indices.insertar(i,pos_d);
            else if(tipo.compare(datos.get(pos_i).getTipo()) == 0 && 
                    nombre.compare(datos.get(pos_i).getNombre()) >0){
                indices.insertar(i,pos_d);
                }
            else if(i==size())
                indices.insertar(i,pos_d);
        }
        
        */
        return insertado;
    }
    