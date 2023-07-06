#include "SumArr.h"

//выбор, если запускается 1 поток активируется метод one_thread,
//если более одного, метод several_thread
void SumArr::calc(std::vector<int>& data, int thread_)
{
	if (thread_ == 1) one_thread(data); else several_thread(data, thread_);
}


SumArr::~SumArr(){}

void SumArr::one_thread(std::vector<int>& data)
{
	for (int i = 0; i < data.size(); ++i) sum += data[i];
}

void SumArr::several_thread(std::vector<int>& data, int thread_)
{
	std::vector <std::thread> threads;
    int l = 0;
    int quantity = data.size() / thread_;
    int r = 0;
    for (int i = 0; i < thread_; i++)
    {
        if (i == thread_ - 1) r = data.size(); else r += quantity;    
        threads.push_back(std::move(std::thread(&SumArr::counting_thread, this, std::ref(data), l, r)));
        l = r + 1;    
    }
    for (auto& t : threads) if (t.joinable()) t.join();
}

//метод подсчета массива изходя из левого и правого краев часит массива
void SumArr::counting_thread(std::vector<int>& data, int l, int r)
{
    int res=0;
    while (l <r) res += data[l++];
    sum += res;
}

