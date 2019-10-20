/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector_dinamico.hpp
 * Author: cristian
 *
 * Created on 18 de octubre de 2019, 19:30
 */

#ifndef VECTOR_DINAMICO_HPP
#define VECTOR_DINAMICO_HPP

template <typename T>
class vector_dinamico {
    private:
        T *datos;
        int reservados=0;
        
    public:
        
        vector_dinamico(int n=100);
        vector_dinamico(const vector_dinamico& original);
        ~vector_dinamico();
        int size() const;
        T get(int i) const;
        void set(int i, T v);
        void resize(int n);
        vector_dinamico & operator=(const vector_dinamico& original);
        T& obtener(int i);
};



#endif /* VECTOR_DINAMICO_HPP */

