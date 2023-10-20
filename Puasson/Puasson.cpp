#include <iostream>
#include "Puasson.h"
#include <fstream>
#include <time.h>

using namespace std;

void Print(int size, double** data)
{
	ofstream ofs("output.txt");
	ofs.clear();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ofs << data[i][j] << " ";
		}
		ofs << endl;
	}
	ofs.close();
}

int main()
{
	double splitting = 0.2;
	double a = 2;
	double b = 5;

	double bb = b * b;
	double aa = a * a;
	int size = ((2*b)/splitting)+3;
	double x, y;
	int offset = size / 2;
	double** data = new double* [size];
	for (int i = 0; i < size; i++)
		data[i] = new double[size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			x = (i-offset) * splitting;
			y = (j-offset) * splitting;
			if (x * x + y * y <= bb && x * x + y * y >= aa)
				data[i][j] = 1;
			else
				data[i][j] = 0;
		}
	}
	
	clock_t tStart = clock();
	for (int e = 0; e < 10000; e++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (data[i][j] == 1)
				{
					x = (i - offset) * splitting;
					y = (j - offset) * splitting;
					data[i][j] = 0.25 * (data[i-1][j] + data[i+1][j] + data[i][j-1]
						+ data[i][j+1] - 12 * (x * x - y * y) * splitting * splitting);
				}
			}
		}
	}
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	Print(size, data);

	return 0;
}