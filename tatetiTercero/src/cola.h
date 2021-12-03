/*
 * cola.h
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */

#ifndef SRC_COLA_H_
#define SRC_COLA_H_
#include <iostream>
#include "jugador.h"
#include "Nodo.h"

template<class T> class Cola{

    private:
        int tamanio;
        Nodo<T>* front;
        Nodo<T>* end;

    public:
        /*
        PRE: -
        POST: crea una cola vacia preparada para ser usada y con tamanio 0*/
        Cola();
        /*
        PRE: -
        POST: Destruye la cola */
        virtual ~Cola();
        /*
        PRE: la cola, ya creada, no debe estar vacia
        POST: Retorna el primer elemento de la cola*/
        T frente();
        /*
        PRE: -
        POST: Da de alta en la cola a un elemento pasado por argumento,
        devuelve la cola modificada con la inserciòn del nuevo elemento al fondo*/
        void acolar(T dato);
        /*
        PRE: la cola, ya creada, no debe estar vacia
        POST: Elimina el elemento del frente de la cola y
        devuelve cola modificada por la eliminacion del elemento del frente*/
        T desacolar();
        /*
        PRE: -
        POST: Devuelve un true si la cola esta vacia y false en caso contrario */
        bool vacia();
        /*PRE:-
        * POST: Devuelve el elemento siguiente al elemento que se encuentra en el frente de la cola
        */
        T siguiente();
        /*PRE:-
        * POST: Devuelve el tamaño de la cola
        */
        int getTamanio();
};

template<class T> Cola<T>::Cola(){
	    this->tamanio = 0;
	    this->front = NULL;
	    this->end = NULL;
}

template<class T> Cola<T>::~Cola(){
	 Nodo<T>* aux = NULL;
	 while(this->front != NULL){
	    aux = this->front;
	    this->front = aux->getSiguiente();
	    delete(aux);

	 }
}

template<class T> T Cola<T>::frente(){
	return this->front->getDato();
}

template<class T> void Cola<T>::acolar(T dato){
	Nodo<T> *elemento = new Nodo<T>(dato);
    if(this->tamanio == 0 && this->front == NULL && this->end == NULL) {
    	this->front = elemento;
        this->end = elemento;
    } else if (this->tamanio == 1){
    	this->front->setSiguiente(elemento);
    	this->end = this->front->getSiguiente();
    }
    else {
    	this->end->setSiguiente(elemento);
    	this->end = this->end->getSiguiente();
    }
    this->tamanio += 1;
}

template<class T> T Cola <T>::desacolar(){
	Nodo<T>* aux = this->front;
	T dato = aux->getDato();

	    this->front = this->front->getSiguiente();
	    this->tamanio -= 1;

	    delete aux;
	    return dato;
}

template<class T> bool Cola<T>::vacia(){
	 if (this->tamanio == 0 && this->front == NULL && this->end == NULL){
		return true;
	 }

	 else{
       return false;
	 }
}

template<class T> T Cola<T>::siguiente(){
	return this->front->getSiguiente()->getDato();
}

template<class T> int Cola<T>::getTamanio(){
	return this->tamanio;
}

#endif /*SRC_COLA_H_*/
