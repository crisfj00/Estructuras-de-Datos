/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "ingrediente.h"

using namespace std;

//CONSTRUCTOR POR DEFECTO
Ingrediente::Ingrediente(){}
    





    void Ingrediente::operator=(const Ingrediente &P){
        x = P.getPosX();
        y = P.getPosY();
        dx = P.getDx();
        dy = P.getDy();
        color = P.getColor();
        radio = P.getRadio();
    }
std::ostream& operator<<(std::ostream& os, const Ingrediente& p) {
        
    os << p.getPosX() << " " << p.getPosY() << " " << p.getDx() << " " << p.getDy() << " " << p.getRadio() << " " << pcolorStr(p.getColor()) << "\n";
             
    return os;
}   
  
std::istream & operator>>(std::istream & is, Ingrediente & p){
    std::string c;
    is >> p.x;
    is >> p.y;
    is >> p.dx >> p.dy >> p.radio;
    is >> c;
    p.color=strPColor(c);

    return is;
    
}
    

