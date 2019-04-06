#ifndef A_H_INCLUDED
#define A_H_INCLUDED

using namespace std;

// Forward declaration clase B y C
class ClaseB;
class ClaseC;

class ClaseA{
    private:
      int numA;
      ClaseB * clase_b;
      ClaseC * clase_c;

    public:
      ClaseA();// Constructor
      void SetA(int); //Set
      int getA(); //Get
      ~ClaseA(); //Destructor
};
#endif // A_H_INCLUDED

