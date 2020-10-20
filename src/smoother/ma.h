#pragma once
#include "smoother.h"

template <typename T>
class MA : public Smoother<T>
{
private:
    int window;
    bool centered; //Whether the Moving Average is centered or Trailing (to the left)

public:
    //Constructors
    MA(int, bool);
    MA(int);
    MA();
    virtual ~MA();
    //Getters & Setters
    void setWindow(int w);
    int getWindow();
    //Fitting
    virtual void fit(std::vector<T> &data, std::vector<long int> &time) override;
    virtual void fit(std::vector<T> &&data, std::vector<long int> &&time) override;
};