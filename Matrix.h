#include "DirectConnection.h"

class Matrix
{
private:
    DirectConnection ***p;
    unsigned int size;


public:
    Matrix(unsigned int N);
    void add_connection(DirectConnection *cnt);
    DirectConnection operator()(unsigned int j, unsigned int i);

    ~Matrix();
};


