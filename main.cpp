#include <iostream>
#include "LDDE.h"
#include <string>

using namespace std;

int main(){
    LDDE<string> l;
    l.insere("abc");
    l.insere("def");
    l.insere("ghi");
    l.insere("jkl");
    l.imprime();
    l.remove("ghi");
    l.imprime();

}