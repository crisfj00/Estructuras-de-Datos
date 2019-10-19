/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prueba vector.cpp
 * Author: cristian
 *
 * Created on 15 de octubre de 2019, 12:15
 */

#include <cstdlib>
#include <iostream>
#include "vector_dinamico.hpp"
#include "vector_dinamico.hxx"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector_dinamico<int> vectorint(3);
    vector_dinamico<double> vectordouble(3);
    vector_dinamico<int> vector;
    
    
    vectorint.set(0,2);
    vectorint.set(1,3);
    vectorint.set(2,5);
    
    vectordouble.set(0,2.54);
    vectordouble.set(1,3.12);
    vectordouble.set(2,-1.45);
    
    
    for(int i=0; i<vectorint.size(); i++)
    
        cout << vectorint.get(i) << " ";
    cout << endl;
    
    for(int i=0; i<vectordouble.size();i++)
        cout << vectordouble.get(i) << " ";
    
    cout << endl;
    
    vector=vectorint;
    
        
    for(int i=0; i<vector.size();i++)
        cout << vector.get(i) << " ";

    return 0;
}

