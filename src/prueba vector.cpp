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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector_dinamico<int> vectorint(7);
    vector_dinamico<double> vectordouble(5);
    vector_dinamico<int> vector;
    
    
    vectorint.aniadir(1);
    vectorint.aniadir(2);
    
    vectordouble.aniadir(3.4);
    
    
    for(int i=0; i<vectorint.size(); i++)
    
        cout << vectorint.get(i) << " ";
    cout << endl;
    
    for(int i=0; i<vectordouble.size();i++)
        cout << vectordouble.get(i) << " ";
    
    cout << endl;
    
    vector=vectorint;
    
        
    for(int i=0; i<vector.size();i++)
        cout << vector.get(i) << " ";
    
    cout<<"\n util es: " << vectorint.getUtil() << " " << vectordouble.getUtil() << " " << vector.getUtil()<< endl;

    return 0;
}

