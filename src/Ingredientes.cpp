/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */








    void Ingredientes::operator=(const Ingrediente &original){
        capacidad=original.getCapacidad();
        delete [] v;
        v = new Pelota [capacidad];
        for(int i=0; i<original.getUtil();i++)
            aniadir(original[i]);
    }
   
    
    Ingredientes::~Ingredientes(){
        delete [] v;
    }

    int Ingredientes::getUtil() const{
        return util;
    }
    
    Ingrediente& Ingredientes::get(int pos) const{
        return v[pos];
    }


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


    void Ingredientes::aniadir(const Ingrediente &p){
        
        if (getUtil()>=getCapacidad())
        {
            Ingrediente *v_ampliado = new Ingrediente[getCapacidad()+1];
            
            for(int i=0; i<getCapacidad();i++)
                v_ampliado[i] = v[i];
            
            delete [] v;
            
            v = v_ampliado;
            
            capacidad++;
        }
        
        v[getUtil()]=p;
        util++;
           
    }

    void Ingredientes::operator+=(const Ingrediente &p){
        aniadir(p);
    }
    
    Pelota& Pelotas::obtener(int pos){
        return v[pos];
    }


    Ingrediente& Ingredientes::operator[] (int i){
        obtener(i);
    }

     
    Ingrediente& Ingredientes::operator[] (int i) const{
        get(i);
    }




    std::ostream& operator<<(std::ostream& os, const Ingredientes& p) {
        
        for (int i=0; i<p.getUtil();i++)
            os << p.get(i);
            return os;
        }

    std::istream & operator>>(std::istream & is, Ingredientes & p){
        Ingrediente pl;
        for (int i=0; i<p.capacidad;i++){
            is >> pl;
            p.aniadir(pl);
        }
        return is;
    }