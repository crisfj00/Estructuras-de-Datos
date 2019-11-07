/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   recetas.h
 * Author: cristian
 *
 * Created on 7 de noviembre de 2019, 20:37
 */

#ifndef RECETAS_H
#define RECETAS_H

#include <map>


class recetas{
    private:
        map<string,receta> datos;
        
    public:
        
        class iterator{
            private:
                map<string,receta>::iterator it;
                
        };
        
        class const_iterator{
            private:
                map<string,receta>::const_iterator it;
        };
    
};

#endif /* RECETAS_H */

