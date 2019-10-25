/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector_dinamico.cpp
 * Author: cristian
 *
 * Created on 18 de octubre de 2019, 19:31
 */

#include "vector_dinamico.h"
#include <cassert>


template <class T>

vector_dinamico<T>::vector_dinamico(int n){
    assert(n>=0);
    if(n>0)
        datos= new T[n];
    reservados=n;
    util=0;
}
template <class T>

   vector_dinamico<T>::vector_dinamico(const vector_dinamico& original){
    reservados = original.getUtil()+1;
    util=original.getUtil();
    if(reservados>0){
        datos = new T[reservados];
        for(int i=0; i<util; i++)
        datos[i] = original[i];
    }
    else
        reservados = 0;
    }
template <class T>

   vector_dinamico<T>::~vector_dinamico(){
    if(reservados!=0){
        Liberar();
        reservados=0;
        util=0;
    }
   }

template <class T>

   int vector_dinamico<T>::size() const{
       return reservados;
   }
template <class T>
        
   const T& vector_dinamico<T>::get(int i)const{
    assert(i>=0 && i<size());
       return datos[i];
   }

template <class T>

T& vector_dinamico<T>::obtener(int i){
    assert(i>=0 && i<getUtil());
    return datos[i];
}
template <class T>
       
   void vector_dinamico<T>::set(int i, T v){
       datos[i]=v;
   }
template <class T>
        
   void vector_dinamico<T>::resize(int n){
       T *vectoraux=new T[n];
       for(int i=0; i<this->reservados;i++)
           vectoraux[i]=datos[i];
       reservados=n;
       delete [] datos;
       datos=vectoraux;
       
   }

template <class T>
        
   vector_dinamico<T> & vector_dinamico<T>::operator=(const vector_dinamico& original){
    
    if(reservados==original.size()){
        for(int i=0; i<original.getUtil();i++)
            set(i,original.get(i));
        util=original.getUtil();
    }
    else{
       this->~vector_dinamico();
       util=original.getUtil();
       datos= new T[util];
       reservados=original.getUtil();
       for(int i=0; i<reservados; i++)
           set(i,original.get(i));      
    }
    return *this;
   }

template <class T>

    int vector_dinamico<T>::getUtil() const{
        return util;
    }

template <class T>

    void vector_dinamico<T>::aniadir(T otro){
    if(getUtil()==size())
        resize(size()+1);

    set(getUtil(),otro);
    util++;
    }
        
   
template <class T>

void vector_dinamico<T>::insertar(int pos, T otro){
    if(getUtil()>=size())
        resize(size()+1);
    for(int i=getUtil();i>pos;i--)
        datos[i]=datos[i-1];
    datos[pos]=otro;
    util++;
    
}

template <class T>
void vector_dinamico<T>::Liberar(){
    delete [] datos;
}

template <class T>
T & vector_dinamico<T>::operator[](int i){
    assert(i>=0 && i<getUtil());
    return obtener(i);
}

template <class T>
const T &vector_dinamico<T>::operator[](int i)const{
    assert(i>=0 && i<getUtil());
    return get(i);
} 

template <class T>
void vector_dinamico<T>::borrar(int pos){
    for(int i=pos;i<getUtil()-1;i++)
        datos[i]=datos[i+1];
    util--;
    
    if(getUtil()<(reservados/2))
        resize(reservados/2);
}

 
