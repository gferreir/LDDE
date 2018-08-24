#ifndef LDDE_H
#define LDDE_H
#include <iostream>
#include "no.h"

using namespace std;

template <typename T>
class LDDE{
private:
    No<T>* primeiro;
    No<T>* ultimo;
    int n;
public:
    LDDE(): primeiro(NULL), ultimo(NULL), n(0){

    }

    bool insere(T valor){
        No<T>* novo = new No<T>(valor);
        if(!novo)
            return false;

        No<T>* ptrAnterior = NULL;
        No<T>* ptrAtual = primeiro;

        while(ptrAtual && ptrAtual -> valor < valor){
            ptrAnterior = ptrAtual;
            ptrAtual = ptrAtual -> proximo;

        }

        novo -> anterior = ptrAnterior;
        if(ptrAnterior){
            ptrAnterior -> proximo = novo;
        }
        else{
            primeiro = novo;
        }

        novo -> proximo = ptrAtual;
        if(ptrAtual){
            ptrAtual -> anterior = novo;
        }
        else{
            ultimo = novo;
        }

        n++;
        return true;

    }

    T busca(T valor){

        No<T>* atual = primeiro;
        while(atual && atual->valor < valor){
            atual = atual->proximo;
        }

        if(atual && atual->valor == valor){
            return atual->valor;
        } else{
            return nullptr;
        }
    }


    void imprime(){
        No<T>* ptr = primeiro;
        while(ptr){
            cout << ptr -> valor << " ";
            ptr = ptr -> proximo;
        }
        cout << endl;
    }

    bool remove(T valor){
        No<T>* ptrAtual = primeiro;

        while(ptrAtual && ptrAtual-> valor < valor){
            ptrAtual = ptrAtual -> proximo;
        }

        if(!ptrAtual || ptrAtual -> valor != valor){
            return false;
        }

        No<T>* ptrAnterior = ptrAtual -> anterior;
        No<T>* ptrProximo = ptrAtual -> proximo;

        if(ptrAnterior)
            ptrAnterior -> proximo = ptrProximo;
        else
            primeiro = ptrProximo;

        if(ptrProximo)
            ptrProximo -> anterior = ptrAnterior;
        else
            ultimo = ptrAnterior;

        delete ptrAtual;
        n--;
        return true;

    }
};

#endif