
#include "ingredientes.h"   
#include "vector_dinamico.cpp"
#include <cmath>
#include <cassert>
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
    

    
    
    ingredientes::~ingredientes(){
        datos.~vector_dinamico();
        indices.~vector_dinamico();
    }

    int ingredientes::size() const{
        return datos.getUtil();
    }
    
    const ingrediente& ingredientes::get(int pos) const{
        return datos[pos];
    }


    void ingredientes::borrar(string n){
        bool borrado1=false, borrado2=false;
        for(int i=0; i<indices.getUtil() && !borrado1;i++){
              if(datos[indices[i]].getNombre()==n){
              int indice=indices[i];
              indices.borrar(i);
              borrado1=true;
              for(int j=indices.getUtil()-1;j>=0;j--){
                  if(indices[j]>indice)
                  indices[j]--;
              }
          }
        }
      for(int i=0; i<datos.getUtil() &&!borrado2; i++){
          if(datos[i].getNombre()==n){
              datos.borrar(i);
              borrado2=true;
          }

      }
    }

    
    bool ingredientes::incluidoIngrediente(const ingrediente &p) const{
        
    int izda = 0;
    int dcha = datos.getUtil() - 1;
    bool encontrado = false;
    int centro;
    while (izda <= dcha && !encontrado){
        centro = (izda + dcha) / 2;
        if (datos.get(centro) == p)
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
    
    

    ostream& operator<<(std::ostream& os, const ingredientes &p) {
        os << "Alimento (100 gramos);Calorias (Kcal.);Hidratos de Carb.;Proteinas;Grasas;Fibra;Tipo\n";
        for(int i=0; i<p.size();i++)
            os << p[i];
        
        return os;
        }
    

    istream & operator>>(std::istream & is, ingredientes & p){
        char primera[256];
        is.getline(primera,256, '\n' );
        
        ingrediente pl("defecto", "defecto");
        for (int i=0; !is.eof();i++){
            is >> pl;
            p.insertar(pl);
        }
        return is;
    }
 
    
    void ingredientes::ImprimirPorNombre(ostream& flujo){
        for(int i=0; i<size();i++)
            flujo << datos.get(i);
    }
    
    void ingredientes::ImprimirPorTipo(ostream& flujo){
        for(int i=0; i<indices.getUtil(); i++)
            flujo << datos.get(indices.get(i));
    }
    
    bool ingredientes::insertar(const ingrediente& otro){
        
        bool insertado=false;
        if(!incluidoIngrediente(otro)){
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
        
        for(int i=0; i<indices.getUtil();i++)
            if(indices[i]>=pos_d)
                indices[i]++;
        
        insertado=false;
        for(int i=0; i<indices.getUtil() && !insertado;i++){
            if(tipo.compare(datos[indices[i]].getTipo())<0){
                pos_i=i;
                indices.insertar(pos_i,pos_d);
                insertado=true;
            }
            else if(tipo.compare(datos[indices[i]].getTipo())==0){
                if(nombre.compare(datos[indices[i]].getNombre())<0){
                pos_i=i;
                indices.insertar(pos_i,pos_d);
                insertado=true;
                }
            }
        }
        
        if(!insertado){
            int i=indices.getUtil();
            indices.insertar(i,pos_d);
            insertado=true;
        }
 
        }
        
        return insertado;
    }
    
    vector_dinamico<string> ingredientes::getTipos(){
        vector_dinamico<string> tipos;
        assert(indices.getUtil()>=1);
        tipos.aniadir(datos[indices[0]].getTipo());
        for(int i=1; i<indices.getUtil();i++)
            if(datos[indices[i]].getTipo().compare(datos[indices[i-1]].getTipo())!=0)
                tipos.aniadir(datos[indices[i]].getTipo());
        
        return tipos;
    }
    
    ingredientes ingredientes::getIngredienteTipo(string tipo){
        ingredientes porTipo;
        bool salir=false;
        for(int i=0; i<indices.getUtil() && !salir;i++)
            if(datos[indices[i]].getTipo()==tipo){
                porTipo.insertar(datos[indices[i]]);
                if(i+1>=indices.getUtil()){
                    salir=true;
                    continue;
                }
                if(datos[indices[i+1]].getTipo()!=tipo) 
                    salir=true;
            }
        return porTipo;
            
        
    }
    
    const ingrediente& ingredientes::get(string n) const{
        ingrediente aux(n,"defecto");
        
        assert(incluidoIngrediente(aux));

        bool encontrado=false;
        int indice=-1;
        for (int i=0; i<size() && !encontrado;i++){
            if (datos[i]==aux){
                encontrado=true;
                indice=i;
            }
        }
        return datos[indice];
    }
    
    
    double ingredientes::getMedia(char atributo, string tipo){
        double media;
        ingredientes porTipo=getIngredienteTipo(tipo);
        
        switch(atributo){
            case 'C':

                for(int i=0; i<porTipo.size();i++)
                    media+=porTipo[i].getCalorias();
                break;
                
            case 'P':

                for(int i=0; i<porTipo.size();i++)
                    media+=porTipo[i].getProteinas();
                break;
                
            case 'G':

                for(int i=0; i<porTipo.size();i++)
                    media+=porTipo[i].getGrasas();
                break;
                
                
            case 'F':

                for(int i=0; i<porTipo.size();i++)
                    media+=porTipo[i].getFibra();
                break;
                
            case 'H':

                for(int i=0; i<porTipo.size();i++)
                    media+=porTipo[i].getHc();
                break;       
        }
        
        media/=porTipo.size();
        
        return media;
        
    }
    
    double ingredientes::getDesviacion(char atributo, string tipo) {
        double media=getMedia(atributo,tipo);
        double varianza=0;
        ingredientes porTipo=getIngredienteTipo(tipo);
        
        switch(atributo){
            case 'C':

                for(int i=0; i<porTipo.size();i++)
                    varianza+=pow((porTipo[i].getCalorias() - media),2.0);
                break;
                
            case 'P':

                for(int i=0; i<porTipo.size();i++)
                    varianza+=pow((porTipo[i].getProteinas() - media),2.0);  
                break;
                
            case 'G':

                for(int i=0; i<porTipo.size();i++)
                    varianza+=pow((porTipo[i].getGrasas() - media),2.0);  
                break;
                
                
            case 'F':

                for(int i=0; i<porTipo.size();i++)
                    varianza+=pow((porTipo[i].getFibra() - media),2.0); 
                break;
                
            case 'H':

                for(int i=0; i<porTipo.size();i++)
                    varianza+=pow((porTipo[i].getHc() - media),2.0); 
                break;       
        }
        
        varianza=varianza/porTipo.size();
        return sqrt(varianza);
        
    }
    
    
    ingrediente ingredientes::getMaximo(char atributo, string tipo){
        ingredientes porTipo=getIngredienteTipo(tipo);
        int pos_maximo;
        assert(porTipo.size()>0);
            pos_maximo=0;
   
        switch(atributo){
            case 'C':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getCalorias()>porTipo[pos_maximo].getCalorias())
                        pos_maximo=i;
                break;
                
            case 'P':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getProteinas()>porTipo[pos_maximo].getProteinas())
                        pos_maximo=i; 
                break;
                
            case 'G':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getGrasas()>porTipo[pos_maximo].getGrasas())
                        pos_maximo=i;
                break;
                
                
            case 'F':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getFibra()>porTipo[pos_maximo].getFibra())
                        pos_maximo=i;
                break;
                
            case 'H':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getHc()>porTipo[pos_maximo].getHc())
                        pos_maximo=i;
                break;       
        }
        

        
        return porTipo[pos_maximo];
    }
    
    
    ingrediente ingredientes::getMinimo(char atributo, string tipo){
        ingredientes porTipo=getIngredienteTipo(tipo);
        int pos_minimo;
        assert(porTipo.size()>0);
            pos_minimo=0;
   
        switch(atributo){
            case 'C':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getCalorias()<porTipo[pos_minimo].getCalorias())
                        pos_minimo=i;
                break;
                
            case 'P':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getProteinas()<porTipo[pos_minimo].getProteinas())
                        pos_minimo=i; 
                break;
                
            case 'G':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getGrasas()<porTipo[pos_minimo].getGrasas())
                        pos_minimo=i;
                break;
                
                
            case 'F':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getFibra()<porTipo[pos_minimo].getFibra())
                        pos_minimo=i;
                break;
                
            case 'H':
                for(int i=0; i<porTipo.size();i++)
                    if(porTipo[i].getHc()<porTipo[pos_minimo].getHc())
                        pos_minimo=i;
                break;       
        }
        

        
        return porTipo[pos_minimo];
    }
    

        
    
    