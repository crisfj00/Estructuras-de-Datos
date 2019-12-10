#include <iostream>
#include "instrucciones.h"
#include "recetas.h"
#include "ingredientes.h"
#include "color.h"
#include <fstream>
using namespace std;

void MuestraParametros(){
	
	cout<<"1.- Dime el nombre del fichero con las acciones\n2.- Dime el nombre del fichero con las recetas"<<endl;
        cout << "3.- Dime el nombre del fichero con los ingredientes \n4.- Dime el nombre de la carpeta con las instrucciones (../carpeta/)" << endl;
}

int main(int argc,char *argv[]){
    
  if (argc!=5){
	  MuestraParametros();
	  return 0;
 }
    
  ifstream acc(argv[1]);
  ifstream rec(argv[2]);
  ifstream ingre(argv[3]);
  
  acciones accion;
  acc>>accion;
  
  ingredientes allingre;
  ingre >> allingre;
  
  instrucciones instr(accion);
  
  recetas todasrec;
  rec>>todasrec;
  
  
  for(recetas::iterator it=todasrec.begin(); it!=todasrec.end(); ++it){
      cout << BOLD("CODE: ") << (*it).getCode() << BOLD(" NOMBRE: ") << (*it).getNombre() << "\t" << BOLD("PLATO: ") << (*it).getPlato() << endl;
    string receta=argv[4] + (*it).getCode() + "m.txt";

    ifstream in(receta);
    in>>instr;
    
    (*it).actualizarNutrientes(allingre);  
    (*it).setArbol(instr.getArbol());
  }
  
  string recet;
  
  cout << "\n\nIntroduzca un código de receta: ";
  cin >> recet;
  
  todasrec[recet].imprimirRecetaCompleta(cout);
  
  string code1, code2;
  
  cout << "\nIntroduzca el código de una receta: ";
  cin >> code1;
  
  cout << endl;
  
  cout << "Introduzca otro código: ";
  cin >> code2;
  
  receta fusion=fusionarRecetas(todasrec,code1,code2);
  fusion.actualizarNutrientes(allingre);

  fusion.imprimirRecetaCompleta(cout);
 

}
