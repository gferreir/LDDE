#ifndef NO_H
#define NO_H

template <typename T>
class No{
public:
    T valor;
    No<T>* proximo;
    No<T>* anterior;

    No(T valor): valor(valor), proximo(NULL), anterior(NULL){

    }
};

#endif