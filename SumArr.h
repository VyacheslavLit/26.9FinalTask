#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <ctime>
#include <chrono>
#include <functional>
#include <Windows.h>


//класс подсчета массивов
class SumArr
{
	long sum = 0;
public:
	SumArr() {};
	~SumArr();
	void calc(std::vector<int>&, int count_);
	int getSum() { return sum; }
	void clearSum() { sum = 0; }
private:
	void one_thread(std::vector<int>&);
	void several_thread(std::vector<int>&, int);
	void counting_thread(std::vector<int>&, int, int);
};