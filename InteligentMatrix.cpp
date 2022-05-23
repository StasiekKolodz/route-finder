#include "InteligentMatrix.h"

Inteligent_Matrix::Inteligent_Matrix()
{
    rows = std::make_unique<std::unique_ptr<std::shared_ptr<DirectConnection>[]>[]>(0);
    columns = std::make_unique<std::shared_ptr<DirectConnection>[]>(0);
    connections = std::make_shared<DirectConnection>(0);
}

void Inteligent_Matrix::extend_matrix()
{
    std::unique_ptr<std::unique_ptr<std::shared_ptr<DirectConnection>[]>[]> new_rows;
    new_rows = std::make_unique<std::unique_ptr<std::shared_ptr<DirectConnection>[]>[]>(size+1);
    std::unique_ptr<std::shared_ptr<DirectConnection>[]> new_columns;
    new_columns = std::make_unique<std::shared_ptr<DirectConnection>[]>(size+1);

    for (size_t i = 0; i < size; i++)
    {
        new_rows[i] = std::make_unique<std::shared_ptr<DirectConnection>[]>(size+1);
    for (size_t j = 0; j < size; j++)
    {
        new_rows[i][j] = nullptr;
    }
    }
    rows.swap(new_rows);
    size++;
}