#ifndef B_H_INCLUDED
#define B_H_INCLUDED

using namespace std;

// Forward declaration clase A y C
class ClaseA;
class ClaseC;

class ClaseB{
    private:
       int numB;
       ClaseA * clase_a;
       ClaseC * clase_c;

    public:
       ClaseB();
       void setB(int);
       int getB();
       ~ClaseB();
};

#endif // B_H_INCLUDED

