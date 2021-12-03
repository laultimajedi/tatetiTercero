/*
 * Nodo.h
 *
 *  Created on: 2 dic. 2021
 *      Author: catalina
 */

#ifndef SRC_NODO_H_
#define SRC_NODO_H_

template<class T> class Nodo {
private:
	T dato;
	Nodo<T>* siguiente;

public:
	/*
	 * PRE:-
	 * POST: el Nodo resulta inicializado con el dato pasado por parametro*/
	Nodo(T dato){
		this->dato = dato;
		this->siguiente = NULL;
	}

	/*
	 * PRE:
	 * POST: devuelve el valor del dato*/
	T getDato(){
		return this->dato;
	}

	/*
	 * PRE:
	 * POST: devuelve el siguiente Nodo*/
	Nodo<T>* getSiguiente(){
		return this->siguiente;
	}
	/*
	 * PRE:-
	 * POST: cambia el siguiente Nodo por el nuevoSiguiente pasado por parametro*/
	void setSiguiente(Nodo<T>* nuevoSiguiente){
		this->siguiente = nuevoSiguiente;
	}

	/*
	 * PRE: -
	 * POST: destruye el Nodo*/
	virtual ~Nodo(){

	}
};

#endif /* SRC_NODO_H_ */
