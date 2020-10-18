#include <vector>
#include <string>
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

template <typename T>
MA<T>::MA(int w, bool c) : Smoother<T>(), window{w}, centered{c}
{
}

template <typename T>
MA<T>::MA() : MA{1, true}
{
}

template <typename T>
MA<T>::~MA()
{
}

template <typename T>
void MA<T>::setWindow(int w)
{
    this->window = w;
}
template <typename T>
int MA<T>::getWindow()
{
    return (this->window);
}

template <typename T>
void MA<T>::fit(std::vector<T> &data, std::vector<long int> &time)
{
    int n = static_cast<int>(data.size());
    int halfWinSize =  (this->window) / 2 ;
    int halfWinSizeRight = this->centered ? halfWinSize + 1 : 1;
    (*this->fittedValues).reserve(n-halfWinSize*(1+this->centered));
    T sum{0};
    for (auto i = halfWinSize; i < (n - halfWinSize * this->centered); i++)
    {
        sum = 0;
        for (int j = -halfWinSize; j < halfWinSizeRight; j++)
        {
            sum += data.at(i+j);
        }
        (*this->fittedValues).push_back(sum / (time.at(i + halfWinSize * this->centered) - time.at(i - halfWinSize) + 1));
    }
}

template <typename T>
void MA<T>::fit(std::vector<T> &&data, std::vector<long int> &&time)
{
    int n = static_cast<int>(data.size());
    int halfWinSize =  (this->window) / 2 ;
    int halfWinSizeRight = this->centered ? halfWinSize + 1 : 1;
    (*this->fittedValues).reserve(n-halfWinSize*(1+this->centered));
    T sum{0};
    for (auto i = halfWinSize; i < (n - halfWinSize * this->centered); i++)
    {
        sum = 0;
        for (int j = -halfWinSize; j < halfWinSizeRight; j++)
        {
            sum += data.at(i+j);
        }
        (*this->fittedValues).push_back(sum / (time.at(i + halfWinSize * this->centered) - time.at(i - halfWinSize) + 1));
    }
}

//Explicit Instantiation of Some Widely used type classes of MA<T> class template
template class Smoother<double>;
template class MA<double>;
