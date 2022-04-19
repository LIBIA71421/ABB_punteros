#pragma once
#include "Node.h"

template <class T>
class ArbolVL
{
private:
	Node<T>* raiz;
public:
	ArbolVL();
	~ArbolVL();

	void RotarDERSimple(Node<T>*& Raiz);
	void RotarIZQSimple(Node<T>*& Raiz);

	void RotarDERCompuesto(Node<T>*& Raiz);
	void RotarIZQCompuesto(Node<T>*& Raiz);

	void insertar(T elem, Node<T>*& Raiz, bool& continuar);
	void insertar(T elem);

	void mostrarInOrder();
	void mostrarInOrder(Node<T>* Raiz);
};

	template<class T>
	ArbolVL<T>::ArbolVL()
	{
		raiz = NULL;
	}

	template<class T>
	ArbolVL<T>::~ArbolVL(){
	}

	template<class T>
	void ArbolVL<T>::RotarDERSimple(Node<T>*& Raiz){
		Node<T>* NewRoot = Raiz->getIzquierda();
		Node<T>* flotante;
		if (NewRoot->getDerecha() != NULL){
			flotante = NewRoot->getDerecha();
		}
		else{
			flotante = NULL;
		}
		NewRoot->setDerecha(Raiz);
		Raiz->setIzquierda(flotante);
		Raiz = NewRoot;
		Raiz->setFactor(0);
		Raiz->getDerecha()->setFactor(0);
	}

	template<class T>
	void ArbolVL<T>::RotarIZQSimple(Node<T>*& Raiz){
		Node<T>* NewRoot = Raiz->getDerecha();
		Node<T>* flotante;
		if (NewRoot->getIzquierda() != NULL){
			flotante = NewRoot->getIzquierda();
		}
		else{
			flotante = NULL;
		}
		NewRoot->setIzquierda(Raiz);
		Raiz->setDerecha(flotante);
		Raiz = NewRoot;
		Raiz->setFactor(0);
		Raiz->getIzquierda()->setFactor(0);
	}

	template<class T>
	void ArbolVL<T>::RotarDERCompuesto(Node<T>*& Raiz)
	{
		Node<T>* NewRoot = Raiz->getIzquierda()->getDerecha();
		Node<T>* HijoIZQ = NewRoot->getIzquierda();
		Node<T>* HijoDER = NewRoot->getDerecha();
		
		NewRoot->setIzquierda(Raiz->getIzquierda());
		NewRoot->setDerecha(Raiz);
		Raiz = NewRoot;
		
		if (Raiz->getFactor() == 0){ // 1er CASO
			Raiz->getIzquierda()->setFactor(0);
			Raiz->getDerecha()->setFactor(0);
		}
		else if (Raiz->getFactor() == 1){ //2do CASO
			Raiz->setFactor(0);
			Raiz->getIzquierda()->setFactor(0);
			Raiz->getDerecha()->setFactor(-1);
		}
		else if(Raiz->getFactor() == -1){ // 3er CASO
			Raiz->setFactor(0);
			Raiz->getIzquierda()->setFactor(1);
			Raiz->getDerecha()->setFactor(0);
		}
		NewRoot->getDerecha()->setIzquierda(HijoDER);
		NewRoot->getIzquierda()->setDerecha(HijoIZQ);
	}

	template<class T>
	void ArbolVL<T>::RotarIZQCompuesto(Node<T>*& Raiz)
	{
		Node<T>* NewRoot = Raiz->getDerecha()->getIzquierda();
		Node<T>* HijoIZQ = NewRoot->getIzquierda();
		Node<T>* HijoDER = NewRoot->getDerecha();
	
		NewRoot->setDerecha(Raiz->getDerecha());
		NewRoot->setIzquierda(Raiz);
		Raiz = NewRoot;
		
		if (Raiz->getFactor() == 0){ // 1er CASO
			Raiz->getIzquierda()->setFactor(0);
			Raiz->getDerecha()->setFactor(0);
		}
		else if(Raiz->getFactor() == 1){ // 2do CASO
			Raiz->setFactor(0);
			Raiz->getIzquierda()->setFactor(0);
			Raiz->getDerecha()->setFactor(-1);
		}
		else if(Raiz->getFactor() == -1){ // 3er CASO
			Raiz->setFactor(0);
			Raiz->getIzquierda()->setFactor(1);
			Raiz->getDerecha()->setFactor(0);
		}
		NewRoot->getIzquierda()->setDerecha(HijoIZQ);
		NewRoot->getDerecha()->setIzquierda(HijoDER);
	}

	template<class T>
	void ArbolVL<T>::insertar(T elem, Node<T>*& Raiz, bool& continuar){
		if (Raiz == NULL){
			Raiz = new Node<T>(elem);
			continuar = true;
		}
		else{
			if (elem < Raiz->getDato()){
				insertar(elem, Raiz->getIzquierda(), continuar);
				if (continuar == true){
					Raiz->setFactor(Raiz->getFactor() + 1);
					if (Raiz->getFactor() == 0){
						continuar = false;
					}
					else{
						if (Raiz->getFactor() == 2){
							continuar = false;
							if (Raiz->getIzquierda()->getFactor() == 1){
								RotarDERSimple(Raiz);
							}
							else{
								RotarDERCompuesto(Raiz);
							}
						}
					}
				}
			}
			if (elem > Raiz->getDato()){
				insertar(elem, Raiz->getDerecha(), continuar);
				if (continuar == true){
					Raiz->setFactor(Raiz->getFactor() - 1);
					if (Raiz->getFactor() == 0){
						continuar = false;
					}
					else{
						if (Raiz->getFactor() == -2){
							continuar = false;
							if (Raiz->getDerecha()->getFactor() == -1){
								RotarIZQSimple(Raiz);
							}
							else{
								RotarIZQCompuesto(Raiz);
							}
						}
					}
				}
			}
		}
	}

	template<class T>
	void ArbolVL<T>::insertar(T elem){
		bool continuar = true;
		insertar(elem, raiz, continuar);
	}

	template<class T>
	void ArbolVL<T>::mostrarInOrder(){
		mostrarInOrder(raiz);
		cout << endl;
	}

	template<class T>
	void ArbolVL<T>::mostrarInOrder(Node<T>* Raiz){
		if (Raiz == NULL){
			return;
		}
		else{
			mostrarInOrder(Raiz->getIzquierda());
			cout << Raiz->getDato() << ", " << Raiz->getFactor() << endl;
			mostrarInOrder(Raiz->getDerecha());
		}
	}

