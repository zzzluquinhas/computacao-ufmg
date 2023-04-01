#include <iostream>

template<typename T>
class Lista{
protected:
	int tamanho;
public:
	T *head, *tail;
	Lista() : head(nullptr), tail(nullptr), tamanho(0){}
	int getTamanho() { return tamanho; }
	virtual void limpa()=0;/*{
		for(T* i = head; i; i=i->prox) delete i;
		tamanho=0;
	}*/
};