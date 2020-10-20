#include <vector>
#include "smoother.h"

using namespace std;

template <typename T>
Smoother<T>::Smoother()
{
    fittedValues = new vector<T>();
}

template <typename T>
Smoother<T>::~Smoother()
{
    delete fittedValues;
}

template <typename T>
std::vector<T> Smoother<T>::getFittedValues()
{
    return (*(this->fittedValues));
}

//Explicitly Instantiating Some Widely used type classes of Smoother<T> class template
template class Smoother<double>;
