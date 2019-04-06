#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;

int main(){

    ClaseA msg_a;
    msg_a = ClaseA();

    ClaseB msg_b;
    msg_b = ClaseB();

    ClaseC msg_c;
    msg_c = ClaseC();

    cout<<"Valor de la clase A: " << msg_a.getA()<<endl;
    cout<<"Valor de la clase B: " <<msg_b.getB()<<endl;
    cout<<"Valor de la clase C: " <<msg_c.getC()<<endl;

    return 0;
}
