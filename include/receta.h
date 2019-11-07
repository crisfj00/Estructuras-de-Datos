/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   receta.h
 * Author: cristian
 *
 * Created on 7 de noviembre de 2019, 20:34
 */

#ifndef RECETA_H
#define RECETA_H

class receta{
    private:
        string code;
        unsigned int plato;
        string nombre;
        list<pair<string,unsigned int> > ings;
        float calorias, hc, grasas, proteinas, fibra;
        
public:
    
    class iterator{
        private:
            list<pair<string,unsigned int> >::iterator it;
        
    };
    
    class const_iterator{
        private:
            list<pair<string,unsigned int> >::const_iterator it;
    };
        
};


#endif /* RECETA_H */

