#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <ctime>

using namespace std;

void InsertSort(double a[], const int size)
{
	int i, j, count = 0, step;
	double temp;

	for (step = size / 2; step > 0; step /= 2) {
		for (i = step; i < size; ++i) {
			temp = a[i];
			for (j = i - step; (j >= 0) && (temp < a[j]); j -= step) {
				a[j + step] = a[j];
				count++;
			}
			a[j + step] = temp;
			count++;
		}
	}
	cout << "Количество операций присваивания при сортировке массива раземером " << size << ":  " << count << endl;
}

void OfFile(int count, string const& file)
{
	ofstream files(file);
	for (int i = 0; i < count; i++)
	{
		double digit = (double)(rand()) / RAND_MAX + rand();;
		files << digit;
		files << " ";
	}
	files.close();
}

void IfFile(double a[], string const& file, int size)
{
	ifstream files(file);
	double value;

	if (!files.is_open())
	{
		cout << "Can't open the file!";
	}
	else
	{
		for (int i=0;i<size;i++)
		{
			files >> value;
			a[i] = value;
		}
	}
	files.close();
}

void InFile(double a[], string const& file, int size)
{
	ofstream files(file);

	if (!files.is_open())
	{
		cout << "Can't open the file!";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			files << a[i] << " ";
		}
	}
	files.close();
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	double a1[100];
	double a2[1000];
	double a3[10000];
	string file1("100.txt"); OfFile(100, file1); IfFile(a1, file1, 100);
	string file2("1000.txt"); OfFile(1000, file2); IfFile(a2, file2, 1000);
	string file3("10000.txt"); OfFile(10000, file3); IfFile(a3, file3, 10000);
	InsertSort(a1, 100);
	InsertSort(a2, 1000);
	InsertSort(a3, 10000);
	InFile(a1, "result100.txt", 100);
	InFile(a2, "result1000.txt", 1000);
	InFile(a3, "result10000.txt", 10000);
	return 0;
}

