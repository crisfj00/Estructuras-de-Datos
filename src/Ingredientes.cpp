    Ingredientes::Ingredientes(int util){
        vector_dinamico<Ingrediente> otro(util);
        datos=otro;
        otro.~vector_dinamico();
    }    

    Ingredientes::Ingredientes(const Ingredientes& original){
        datos=original.datos;
        indices=original.indices;
    }

    void Ingredientes::operator=(const Ingredientes &original){
        datos=original.datos;
        indices=original.indices;
    }
    
    
    Ingredientes::~Ingredientes(){
        datos.~vector_dinamico();
        indices.~vector_dinamico();
    }

    int Ingredientes::getNumElementos() const{
        return datos.getUtil();
    }
    
    Ingrediente Ingredientes::get(int pos) const{
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
    int Ingredientes::buscar(const Ingrediente &p){
        
    int pos_encontrado;
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
    
    if (encontrado)
        pos_encontrado = centro;
    else
        pos_encontrado = -1;
    
    return pos_encontrado;
    }

    void Ingredientes::aniadir(const Ingrediente &p){
    

           
    }

    void Ingredientes::operator+=(const Ingrediente &p){
        aniadir(p);
    }
    
    Ingrediente& Ingredientes::obtener(int pos){ //PERMITE MODIFICACION
        return datos.obtener(pos);
    }


    Ingrediente& Ingredientes::operator[] (int i){ //PERMITE MODIFICACIÓN
        return obtener(i);
    }

     
    Ingrediente Ingredientes::operator[] (int i) const{ //NO PERMITE MODIFICAR
       return get(i);
    }




    std::ostream& operator<<(std::ostream& os, const Ingredientes& p) {
        
        for (int i=0; i<p.getNumElementos();i++)
            os << p.get(i);
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