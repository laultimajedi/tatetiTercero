/*
 * pila.h
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */

#ifndef SRC_PILA_H_
#define SRC_PILA_H_
#include <iostream>

#include "Nodo.h"
#include "tablero.h"

template <class T> class Pila{
    private:
        Nodo<T>* tope;
        int tamanio;
    
    public:
        /*
        PRE: -
        POST: Crea una pila vacia preparada para ser usada */
        Pila();
        /*
        PRE: -
        POST: Destruye la pila */
        virtual ~Pila();
        /*
        PRE: -
        POST: Realiza el alta en la pila de un elemento pasado por argumento y devulve
        la pila modificada con la insercion del nuevo elemento en el tope */
        void push(T dato);
        /*
        PRE: la pila, ya creada, no debe estar vacia
        POST: Elimina el elemento del tope de la misma y devuelve
        una pila modificada por la eliminacion del elemento del tope*/
        T pop();
        /*
        PRE: la pila, ya creada, no debe estar vacia
        POST:  Retorna el valor del tope de la pila*/
        T top();
        /*
        * PRE: -
        * POST: Devuelve el valor logico true si la pila esta vacia, false en caso contrario
        */
        bool vacia();
        /*
        * PRE: -
        * POST: Setea como tope de la Pila al NodoPila que se pasa como parametro y
        * devuelve la pila modificada con un nuevo tope, y el tope anterior como siguiente del tope seteado */
        void setTope(Nodo<T>* ultimo);

};

template<class T> Pila<T>::Pila(){
	this->tamanio = 0;
	this->tope = NULL;
}

template<class T> Pila<T>::~Pila(){
	//Nodo<T>* aux = NULL;
	/*while(this->tope != NULL){
	    aux = this->tope;
	    this->tope = aux->getSiguiente();

	    delete(aux);
	 }*/
	while(this->tope != NULL){
		T dato = this->pop();
		delete(dato);
	}
}

template<class T> void Pila<T>::push(T dato){
	 Nodo<T>* aux = new Nodo<T>(dato);

	    aux->setSiguiente(this->tope);

	    this->setTope(aux);
	    this->tamanio += 1;
	}

template<class T> T Pila<T>::pop(){
	 Nodo<T> *aux = this->tope;
	 T dato = aux->getDato();

	 this->setTope(aux->getSiguiente());

	 this->tamanio -= 1;
	 delete aux;
	 return dato;
}

template<class T> T Pila<T>::top(){
	 Nodo<T>* aux = this->tope->getSiguiente();
	 return aux->getDato();
}

template<class T> bool Pila<T>::vacia(){
	 if(this->tamanio == 0){
		 return true;
	 }
	 else{
	     return false;
	 }
}

template<class T> void Pila<T>::setTope(Nodo<T>* ultimo){
	ultimo->setSiguiente(this->tope);
	this->tope = ultimo;
}
#endif /* SRC_PILA_H_ */
