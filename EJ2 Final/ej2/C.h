#ifndef C_H_INCLUDED
#define C_H_INCLUDED

using namespace std;

// Forward declaration clase a y B
class ClaseA;
class ClaseB;

class ClaseC{
   private:
        int numC;
        ClaseA * clase_a;
        ClaseB * clase_b;
   public:
        ClaseC();
        void setC(int);
        int getC();
        ~ClaseC();
};

#endif // C_H_INCLUDED

