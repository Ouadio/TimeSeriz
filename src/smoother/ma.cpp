#include <vector>
#include <string>
#include "smoother.h"
#include "ma.h"

template <typename T>
MA<T>::MA(int w, bool c) : Smoother<T>(), window{w}, centered{c}
{
}

template <typename T>
MA<T>::MA(int w) : MA{w, true}
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
    int isCentered = static_cast<int>(this->centered);

    int n = static_cast<int>(data.size());
    int win = (n < this->window) ? n : this->window;

    int halfWinSize = isCentered ? win / 2 - !(win & 1) : win - 1;

    int halfWinSizeRight = isCentered ? halfWinSize + 1 : 1;

    if (isCentered)
    {
        (*this->fittedValues).reserve(n - halfWinSize * 2 - !(win & 1));
    }
    else
    {
        (*this->fittedValues).reserve(n - win + 1);
    }

    T sum{0};
    for (auto i = halfWinSize; i < (n - (halfWinSize + !(win & 1)) * isCentered); i++)
    {
        sum = 0;
        for (int j = -halfWinSize; j < halfWinSizeRight; j++)
        {
            sum += data.at(i + j);
        }
        (*this->fittedValues).push_back(sum / (time.at(i + halfWinSize * isCentered) - time.at(i - halfWinSize) + 1));
    }
}

template <typename T>
void MA<T>::fit(std::vector<T> &&data, std::vector<long int> &&time)
{
    int isCentered = static_cast<int>(this->centered);

    int n = static_cast<int>(data.size());
    int win = (n < this->window) ? n : this->window;

    int halfWinSize = isCentered ? win / 2 - !(win & 1) : win - 1;

    int halfWinSizeRight = isCentered ? halfWinSize + 1 : 1;

    if (isCentered)
    {
        (*this->fittedValues).reserve(n - halfWinSize * 2 - !(win & 1));
    }
    else
    {
        (*this->fittedValues).reserve(n - win + 1);
    }

    T sum{0};
    for (auto i = halfWinSize; i < (n - (halfWinSize + !(win & 1)) * isCentered); i++)
    {
        sum = 0;
        for (int j = -halfWinSize; j < halfWinSizeRight; j++)
        {
            sum += data.at(i + j);
        }
        (*this->fittedValues).push_back(sum / (time.at(i + halfWinSize * isCentered) - time.at(i - halfWinSize) + 1));
    }
}

//Explicitly Instantiating Some Widely used type classes of MA<T> class template
template class MA<double>;
