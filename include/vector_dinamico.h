/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector_dinamico.h
 * Author: cristian
 *
 * Created on 18 de octubre de 2019, 19:30
 */

#ifndef VECTOR_DINAMICO_H
#define VECTOR_DINAMICO_H

template <class T>
class vector_dinamico {
    private:
        T *datos;
        int reservados=0;
        int util=0;
        
    public:
        vector_dinamico(int n=10);
        vector_dinamico(const vector_dinamico& original);
        ~vector_dinamico();
        int size() const;
        int getUtil() const;
        const T& get(int i)const;
        void set(int i, T v);
        void resize(int n);
        T &operator[](int i);
        const T &operator[](int i) const;        
        vector_dinamico & operator=(const vector_dinamico& original);
        void aniadir(T otro);
        T& obtener(int i);
        void insertar(int i, T otro);
        void Liberar();
        void borrar(int pos);
};
//#include "vector_dinamico.cpp"

#endif /* VECTOR_DINAMICO_H */


