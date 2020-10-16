#pragma once
#include <iostream>
#include <vector>
#include <string>

template<typename T> class TimeSerie {
private:
	std::vector<T> values;
	std::vector<long int> timeStamp;
	int length;
	std::string timeUnit;
	//Static attribute
	static size_t nbTimeSeries;

public:
	//Constructors
	TimeSerie();
	TimeSerie(std::vector<T>, std::vector<long int>, std::string);
	TimeSerie(int, std::string);
	TimeSerie(int);

	//Getters
	int getLength() const;
	std::vector<T> getValues() const;
	std::vector<long int> getTimeStamp() const;
	std::string getTimeUnit() const;
	//static method
	static size_t getNbTS();

	//Setters
	void setLength(int);
	void setValues(std::vector<T>);
	void setTimeStamp(std::vector<long int>);
	void setUnit(std::string);

	~TimeSerie();

};

