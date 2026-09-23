/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Didac Barragan & Joan Surrell.
 *  Copyright (c) 2004-2021 IMAE-UdG.
 *
 */

#include <iostream>

#include "estructuraDinamica.h"

using namespace std;


estructuraDinamica::estructuraDinamica()
{
// aquest constructor es dona fet i no es pot canviar
	inici = final = NULL;
}

estructuraDinamica::~estructuraDinamica() {
    node *p = inici;

    while (p != nullptr) {
        node *aux = p;
        p = p->seguent;
        delete aux;
    }

    inici = nullptr;
    final = nullptr;
}

void estructuraDinamica::AfegirInici(int i){
	node *p = new node;
	p->dada = i;

	if(inici == nullptr && final == nullptr){
		inici = final = p;
		p->seguent = nullptr;
	}else{
		p->seguent = inici;
    	inici = p;

	}
}

void estructuraDinamica::Esborrar(int i){
	node *actual = inici;

	while(actual != nullptr){
		
		if(actual->dada != i){
			actual = actual ->seguent;
		}else{
			// El nodo esta al inici
			if(actual == inici){
				inici = inici->seguent;
				delete actual;
				return;
			}

			// Node al final
            if(actual == final){
                node *anterior = inici;

                while(anterior->seguent != final){
                    anterior = anterior->seguent;
                }

                anterior->seguent = nullptr;
                final = anterior;
                delete actual;
                return;
            }
		}
	}
}

void estructuraDinamica::Llistar() const
{
// aquest metode es dona fet i no es pot canviar
	node * p = inici;
	while (p != final) {
		cout << p->dada << " "; 
		p = p-> seguent; 
	}
	if (p != NULL) 
		cout << p->dada << endl; 
	else 
		cout << endl; 
}

