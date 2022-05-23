#include <memory>
#include "DirectConnection.h"

class Inteligent_Matrix
{
    private:
    std::unique_ptr<std::unique_ptr<std::shared_ptr<DirectConnection>[]>[]> rows;
    std::unique_ptr<std::shared_ptr<DirectConnection>[]> columns;
    std::shared_ptr<DirectConnection> connections;
    unsigned int size = 0;

    public:
    Inteligent_Matrix();
    void extend_matrix();
    void add_connection(std::shared_ptr<DirectConnection>);
    std::shared_ptr<DirectConnection> operator()(City const& CityA, City const& CityB) const;




};