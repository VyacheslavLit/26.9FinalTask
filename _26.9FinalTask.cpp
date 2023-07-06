#include "SumArr.h"

using namespace std::chrono;

void filling_the_vector(std::vector<int>&, int);
void menu();

//программа создает и заполняет 2 массива, на 100 000 и 10 000 000 значений
//далее запускается класс подсчета
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<int> one_hundred_thousand_values;
	std::vector<int> ten_million_values;
	filling_the_vector(one_hundred_thousand_values, 100000);
	filling_the_vector(ten_million_values, 10000000);
	menu();
	int thr = 1;
	SumArr sumArr;
//цикл подсчетов сто тысячного массива
	while (1)
	{
		auto t_start = system_clock::now();
		sumArr.calc(one_hundred_thousand_values, thr);
		auto t_end = system_clock::now();
		long diff = duration_cast<milliseconds>(t_end - t_start).count();
		std::cout << std::setw(8) << thr << std::setw(11) << one_hundred_thousand_values.size() << std::setw(12) << sumArr.getSum() << std::setw(11) << diff << std::endl;
		sumArr.clearSum();
		if (thr == 20)break;
		if (thr == 10) thr = 20;
		if (thr == 5) thr = 10;
		if (thr == 1)thr = 5;
	}
	thr = 1;
//цикл подсчета десяти миллионого массива
	while (1)
	{
		auto t_start = system_clock::now();
		sumArr.calc(ten_million_values, thr);
		auto t_end = system_clock::now();
		long diff = duration_cast<milliseconds>(t_end - t_start).count();
		std::cout << std::setw(8) << thr << std::setw(11) << ten_million_values.size() << std::setw(12) << sumArr.getSum() << std::setw(11) << diff << std::endl;
		sumArr.clearSum();
		if (thr == 20)break;
		if (thr == 10) thr = 20;
		if (thr == 5) thr = 10;
		if (thr == 1)thr = 5;
	}
	return 0;
}


void filling_the_vector(std::vector<int>& vec, int size)
{
	srand(std::time(0));
	for (int i = 0; i < size; i++) vec.push_back(rand() % 100);
}

void menu()
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	int numCPU = sysinfo.dwNumberOfProcessors;
	system("cls");
	std::cout << "В используемом компьютере " << sysinfo.dwNumberOfProcessors << " ядер.\n";
	std::cout << "Программа может использовать процессорную многозадачность по " << std::thread::hardware_concurrency() << " потокам.\n\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "| Кол-во|  Кол-во  |   Сумма   |Затраченное|\n";
	std::cout << "|потоков|  данных  |           |   время   |\n";
	std::cout << "--------------------------------------------\n";
}