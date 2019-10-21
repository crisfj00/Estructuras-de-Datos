/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector_dinamico.hxx
 * Author: cristian
 *
 * Created on 18 de octubre de 2019, 19:31
 */

#include <iostream>
#include "vector_dinamico.h"
#include "vector_dinamico.hpp"
#include <cassert>
template <typename T>

vector_dinamico<T>::vector_dinamico(int n){
    assert(n>=0);
    if(n>0)
        datos= new T[n];
    reservados=n;
    util=0;
}
template <typename T>

   vector_dinamico<T>::vector_dinamico(const vector_dinamico& original){
       datos= new T[original.size()];
       reservados=original.size();
       for(int i=0; i<original.getUtil(); i++)
           datos[i]=original.get(i);
       util=original.getUtil();
   }
template <typename T>

   vector_dinamico<T>::~vector_dinamico(){
       delete [] datos;
       reservados=0;
       util=0;
   }

template <typename T>

   int vector_dinamico<T>::size() const{
       return reservados;
   }
template <typename T>
        
   T vector_dinamico<T>::get(int i) const{
       return datos[i];
   }

template <typename T>

T& vector_dinamico<T>::obtener(int i){
    return datos[i];
}
template <typename T>
       
   void vector_dinamico<T>::set(int i, T v){
       datos[i]=v;
   }
template <typename T>
        
   void vector_dinamico<T>::resize(int n){
       vector_dinamico<T> vectoraux(n);
       for(int i=0; i<this->reservados;i++)
           vectoraux.set(i,datos[i]);
       this->~vector_dinamico();
       datos= new T[vectoraux.size()];
       reservados=vectoraux.size();
       for(int i=0; i<reservados; i++)
           datos[i]=vectoraux.get(i);
       
   }

template <typename T>
        
   vector_dinamico<T> & vector_dinamico<T>::operator=(const vector_dinamico& original){
       this->~vector_dinamico();
       datos= new T[original.getUtil()];
       reservados=original.getUtil();
       for(int i=0; i<reservados; i++)
           datos[i]=original.get(i);
       util=original.getUtil();
       return *this;
   }

template <typename T>

    int vector_dinamico<T>::getUtil() const{
        return util;
    }

template <typename T>

    void vector_dinamico<T>::aniadir(T otro){
    if(getUtil()==size()){
        resize(1);
        set(getUtil(),otro);
        util++;
    }
    else{
        set(getUtil(),otro);
        util++;
    }
        
    
}
 