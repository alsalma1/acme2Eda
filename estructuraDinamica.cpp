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

