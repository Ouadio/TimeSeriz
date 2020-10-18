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

template <typename T>
class MA : public Smoother<T>
{
private:
    int window;
    bool centered; //Whether the Moving Average is centered or Trailing (to the left)

public:
    //Constructors
    MA(int, bool);
    MA();
    virtual ~MA();
    //Getters & Setters
    void setWindow(int w);
    int getWindow();
    //Fitting
    virtual void fit(std::vector<T> &data, std::vector<long int> &time) override;
    virtual void fit(std::vector<T> &&data, std::vector<long int> &&time) override;
};