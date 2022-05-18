#include "Matrix.h"

Matrix::Matrix()
{
    size = 0;
    p = new DirectConnection **[0];
    for (int i = 0; i < size; i++)
    {
        p[i] = new DirectConnection *[0];
    }
}

void Matrix::extend_matrix()
{
    DirectConnection ***temp_p = new DirectConnection **[size+1];
    for (int i = 0; i < size+1; i++)
    {
        temp_p[i] = new DirectConnection *[size+1];
        for (int j = 0; j < size+1 ; j++)
        {
                temp_p[i][j] = nullptr;
        }
    }

    for(int i = 0; i<size;i++)
    {
    for(int j=0; j<size;j++)
    {
        temp_p[i][j] = p[i][j];
    }
    }

    delete p;
    p = temp_p;
    size++;
}

bool Matrix::isCity(City const& city) const
{
    for(int i = 0; i<size; i++)
    {
        if(cites[i] == city)
        return true;
    }
    return false;
}

void Matrix::add_connection(DirectConnection *cnt)
{
    if(this->isCity(cnt->get_PlaceA()) && this->isCity(cnt->get_PlaceB()))
        throw "Matrix already has that connection";
    else if(this->isCity(cnt->get_PlaceA()))
    {
        this->extend_matrix();
        for( int i = 0; i < size; i++)
        {
            if(cites[i] == cnt->get_PlaceA())
            {
                p[i][size-1]=cnt;
                p[size-1][i]=cnt;
            }
        }
        cites.push_back(cnt->get_PlaceB());
    }
    else if(this->isCity(cnt->get_PlaceB()))
    {
        this->extend_matrix();
        for( int i = 0; i < size; i++)
        {
            if(cites[i] == cnt->get_PlaceB())
            {
                p[i][size-1]=cnt;
                p[size-1][i]=cnt;
            }
        }
        cites.push_back(cnt->get_PlaceA());
    }
    else
    {
        this->extend_matrix();
        this->extend_matrix();
        p[size-2][size-1] = cnt;
        p[size-1][size-2] = cnt;
        cites.push_back(cnt->get_PlaceA());
        cites.push_back(cnt->get_PlaceB());
    }
}

DirectConnection * Matrix::operator()(City const& CityA, City const& CityB)
{
    for(int i = 0 ; i < size ; i++)
    {
    if(p[i][0]!=nullptr && (p[i][0]->get_PlaceA() == CityA || p[i][0]->get_PlaceB() == CityA))
    {
        for(int j = 0; j < size ; j++)
        {
            if(p[i][j]!=nullptr && (p[i][j]->get_PlaceA() == CityB || p[i][j]->get_PlaceB() == CityB))
            {return p[i][j];}
        }
    }
    }
    return nullptr;
}

Matrix::~Matrix()
{
    delete p;
}

void Matrix::print() const
{
    for(int i = 0; i < size; i++)
    {
    for(int j = 0; j < size; j++)
    {
    if(p[i][j] != nullptr)
    {
        std::cout << p[i][j]->get_PlaceA().get_name() << "-" << p[i][j]->get_PlaceB().get_name() << "\t";
    }
    else
    {
        std::cout << "NULL\t";
    }
    }
    std::cout << std:: endl;
    }
}