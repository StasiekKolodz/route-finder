
#include "Matrix.h"

Matrix::Matrix(unsigned int N): size(N)
{
    p = new DirectConnection **[size];
    for (int i = 0; i < size; i++)
    {
        p[i] = new DirectConnection *[size];
    }

    for(int i = 0; i < size; i++)
    {
    for(int j = 0; j < size; j++)
    {
        p[j][i] = nullptr;
    }
    }
}

void Matrix::add_connection(DirectConnection *cnt)
{
    for(int i = 0; i < size; i++)
    {
    for(int j = 0; j < size; j++)
    {
        if(p[j][i] == nullptr)
        {
            p[j][i] = cnt;
        }
    }
    }
}

DirectConnection Matrix::operator()(unsigned int j, unsigned int i)
{
    return *p[j][i];
}

Matrix::~Matrix()
{
    delete p;
}