#include "Matrix.h"
#include <memory>

Matrix::Matrix()
{
    size = 0;
    p = new DirectConnection **[0];
    // for (int i = 0; i < size; i++)
    // {
    //     p[i] = new DirectConnection *[0];
    // }
}

Matrix::Matrix(Matrix const&  matrix_to_copy)
{
    p = matrix_to_copy.p;
    size = matrix_to_copy.size;
    cites = matrix_to_copy.cites;
}

Matrix & Matrix::operator=(Matrix const& matrix_to_assign)
{
    p = matrix_to_assign.p;
    size = matrix_to_assign.size;
    cites = matrix_to_assign.cites;
    return *this;
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

    // for(int i = 0; i<size; i++)
    // {
    //     delete[] p[i];
    // }

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
    {
        int i_to_assign;
        int j_to_assign;

        for(int i = 0; i<cites.size(); i++)
        {
            if(cites[i]==cnt->get_PlaceA())
            i_to_assign = i;
            else if(cites[i]==cnt->get_PlaceB())
            j_to_assign = i;
        }
        p[i_to_assign][j_to_assign] = cnt;
        p[j_to_assign][i_to_assign] = cnt;

    }
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
    if(p[i][0]!=nullptr)
    {
    if(p[i][0]->get_PlaceA() == CityA || p[i][0]->get_PlaceB() == CityA)
    {
        for(int j = 0; j < size ; j++)
        {
            if(p[i][j]!=nullptr)
            {
            if(p[i][j]->get_PlaceA() == CityB || p[i][j]->get_PlaceB() == CityB)
            {return p[i][j];}
            }
        }
    }
    }
    }
    return nullptr;
    // throw DCNotFoundException("DirectConnection not found in matrix", CityA, CityB);
}

DirectConnection * Matrix::operator()(int i, int j){
    if(i>this->get_size() || j > this->get_size()){
        throw MyException("Matrix index out of range");
    }
    return p[i][j];
}

Matrix::~Matrix()
{
    if(p!=nullptr)
    p = nullptr;

    delete p;

}

std::string Matrix::description() const
{
    std::stringstream ss;
    for(int i = 0; i < size; i++)
    {
    for(int j = 0; j < size; j++)
    {
    if(p[i][j] != nullptr)
    {
        ss << p[i][j]->get_connection_id() << "\t";
    }
    else
    {
        ss << "NULL\t";
    }
    }
    ss << std:: endl;
    }
    return ss.str();
}

void Matrix::print_matrix()
{
    for(int i = 0; i < size; i++)
    {
    for(int j = 0; j < size; j++)
    {
    if(p[i][j] != nullptr)
    {
        std:: cout << p[i][j]->get_connection_id() << " ";
    }
    else
    {
        std::cout << "NULL\t";
    }
    }
    std::cout << std:: endl;
    }
}

void Matrix::clean()
{
    for(int i = 0; i < size; i++)
    {
    for(int j = 0; j < size; j++)
    {
        p[j][i] = nullptr;
    }
    }
}