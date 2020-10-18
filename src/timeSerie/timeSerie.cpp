#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "timeSerie.h"

using namespace std;

template <typename T>
size_t TimeSerie<T>::nbTimeSeries = 0;

//Constructors
template <typename T>
TimeSerie<T>::TimeSerie(vector<T> vals, vector<long int> timeStmp, string un) : values{vals}, timeStamp{timeStmp}, timeUnit{un},length{(int)timeStmp.size()}
{
	nbTimeSeries += 1;
}

template <typename T>
TimeSerie<T>::TimeSerie(vector<T> vals, string un) : values{vals}, timeUnit{un}, length{static_cast<int>(vals.size())}
{
	vector<long int> timeStmp(vals.size());
	iota(timeStmp.begin(), timeStmp.end(), 0);
	this->timeStamp.reserve(vals.size());
	this->timeStamp = timeStmp;
	nbTimeSeries += 1;
}

template <typename T>
TimeSerie<T>::TimeSerie(vector<T> vals) : TimeSerie{vals, "s"} {}

template <typename T>
TimeSerie<T>::TimeSerie(int l, string unit) : timeUnit{unit}, length{l}
{
	vector<T> vals(l);
	vector<long int> timeStmp(l);
	iota(timeStmp.begin(), timeStmp.end(), 0);
	this->timeStamp.reserve(l);
	this->timeStamp = timeStmp;
	this->values = vals;
	nbTimeSeries += 1;
}

template <typename T>
TimeSerie<T>::TimeSerie(int l) : TimeSerie{l, "s"} {}

template <typename T>
TimeSerie<T>::TimeSerie() : TimeSerie(1, "s") {}

template <typename T>
TimeSerie<T>::~TimeSerie()
{
	nbTimeSeries -= 1;
}

//Getters

template <typename T>
int TimeSerie<T>::getLength() const
{
	return (this->length);
}

template <typename T>
vector<T> TimeSerie<T>::getValues() const
{
	return (this->values);
}

template <typename T>
vector<long int> TimeSerie<T>::getTimeStamp() const
{
	return (this->timeStamp);
}

template <typename T>
string TimeSerie<T>::getTimeUnit() const
{
	return (this->timeUnit);
}

template <typename T>
size_t TimeSerie<T>::getNbTS()
{
	return (nbTimeSeries);
}

//Setters

template <typename T>
void TimeSerie<T>::setLength(int l)
{
	this->length = l;
}

template <typename T>
void TimeSerie<T>::setTimeStamp(vector<long int> timeStmp)
{
	this->timeStamp = timeStmp;
}
template <typename T>
void TimeSerie<T>::setValues(vector<T> vals)
{
	this->values = vals;
}

template <typename T>
void TimeSerie<T>::setUnit(string s)
{
	this->timeUnit = s;
}

//Explicitly Instantiating Some Widely used type classes of TimeSerie class
template class TimeSerie<long double>;
template class TimeSerie<double>;
template class TimeSerie<float>;
template class TimeSerie<long>;
template class TimeSerie<int>;