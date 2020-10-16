#include <iostream>
#include <vector>
#include <string>
#include "timeSerie.h"

using namespace std;

template<typename T> size_t TimeSerie<T>::nbTimeSeries = 0;

//Constructors
template<typename T> TimeSerie<T>::TimeSerie(vector<T> vals, vector<long int> timeStmp, string un) :values{ vals }, timeStamp{ timeStmp }, timeUnit{ un } {
	nbTimeSeries += 1;
}

template<typename T> TimeSerie<T>::TimeSerie(int l, string unit) : timeUnit{ unit }, length{ l } {
	vector<T> vals(l);
	vector<long int> timeStmp(l);
	for (int i = 0; i < l; i++) {
		timeStmp[i] = i;
	}
	this->values = vals;
	this->timeStamp = timeStmp;
	nbTimeSeries += 1;
}

template<typename T> TimeSerie<T>::TimeSerie(int l) :TimeSerie{ l,"s" } {}

template<typename T> TimeSerie<T>::TimeSerie() : TimeSerie(1, "s") {}

template<typename T> TimeSerie<T>::~TimeSerie() {
	nbTimeSeries -= 1;
}

//Getters

template<typename T> int TimeSerie<T>::getLength() const {
	return(this->length);
}

template<typename T> vector<T> TimeSerie<T>::getValues() const{
	return(this->values);
}

template<typename T> vector<long int> TimeSerie<T>::getTimeStamp() const{
	return(this->timeStamp);
}

template<typename T> string TimeSerie<T>::getTimeUnit() const{
	return(this->timeUnit);
}

template<typename T> size_t TimeSerie<T>::getNbTS() {
	return(nbTimeSeries);
}

//Setters

template<typename T> void TimeSerie<T>::setLength(int l) {
	this->length = l;
}

template<typename T> void TimeSerie<T>::setTimeStamp(vector<long int> timeStmp) {
	this->timeStamp = timeStmp;
}
template<typename T> void TimeSerie<T>::setValues(vector<T> vals) {
	this->values = vals;
}

template<typename T> void TimeSerie<T>::setUnit(string s) {
	this->timeUnit = s;
}

//Explicitly Instantiating Some Widely used type classes of TimeSerie class
template class TimeSerie<long double>;
template class TimeSerie<double>;
template class TimeSerie<float>;
template class TimeSerie<long>;
template class TimeSerie<int>;