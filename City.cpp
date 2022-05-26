#include "City.h"

std::ostream& operator<<(std::ostream& os, City const& ct)
{
    os << ct.get_name();
    return os;
}