#include "02-Cola.h"

void manejaError();

COLA crearCola(){
    COLA C;
    C = (COLA)malloc(sizeof(Cola));
    if (C == NULL){
        manejaError(0);
        exit(0);
    }
    C->primero = 0;
    C->ultimo = 0;
    C->tam = 0;
    return C;

}

int es_vaciaCola(COLA C){
    if (C->tam == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

//Calcula la posicion en la cola
int sig(int i){
    int p;
    p = (i+1) % TAMCOLA;
    return p;
}

void encolar(COLA C, int x){
    if (C->tam == TAMCOLA){
        manejaError(4);//cola llena
        exit(0);
    }
    C->cola[C->ultimo] = x;
    C->ultimo = sig(C->ultimo);
    C->tam = C->tam+1;
}

int desencolar(COLA C){
    int v;
    if (es_vaciaCola(C) == TRUE){
        manejaError(5);
        exit(0);
    }
    v = C->cola[C->primero];
    C->primero = sig(C->primero);
    C->tam = C->tam-1;
    return v;
    
}

int copiaCola(COLA C1, COLA C2){
    int x;
    while (es_vaciaCola(C1) == FALSE){
        x = desencolar(C1);
        encolar(C2, x);
    }
    
}

// CONSULTAR EL PRIMER ELEMENTO DE LA ESTRUCTURA COLA
int primero(COLA C){
    int v;
    if (es_vaciaCola(C) == TRUE){
        manejaError(5);
        exit(0);
    }
    v = C->cola[C->primero];
    return v;
}
