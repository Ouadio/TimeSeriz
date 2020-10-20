#pragma once

#include <string>
#include <vector>

template <typename T>
class Smoother
{
protected:
    std::vector<T> *fittedValues;
public:
    //Constructor
    Smoother();
    virtual ~Smoother();
    //Smoothing Methods
    virtual void fit(std::vector<T> &data, std::vector<long int> &time) = 0;
    virtual void fit(std::vector<T> &&data, std::vector<long int> &&time) = 0;
    //Fitted Values
    std::vector<T> getFittedValues();
};
