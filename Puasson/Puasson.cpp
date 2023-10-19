#include <iostream>
#include "Puasson.h"
#include <fstream>

#define splitting 0.5

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
	
	double a = 3/splitting;
	double b = 5/ splitting;

	double bb = b * b;
	double aa = a * a;
	int size = b/ splitting+3;

	int offset = size / 2;
	double** data = new double* [size];
	for (int i = 0; i < size; i++)
		data[i] = new double[size];

	for (int i = -offset; i < size- offset; i++)
	{
		for (int j = -offset; j < size- offset; j++)
		{
			if (i * i + j * j <= bb && i * i + j * j >= aa)
				data[i + offset][j + offset] = 1;
			else
				data[i + offset][j + offset] = 0;
		}
	}
	double x, y;

	for (int e = 0; e < 1000000; e++)
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


	Print(size, data);
}