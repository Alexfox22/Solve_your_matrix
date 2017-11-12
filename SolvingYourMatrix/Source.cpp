#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
void show_me(double **matrix, int wid, int hei)
{
	bool lol = true;
	for (int i = 0; i < hei;i++)
	{
		for (int j = 0;j < wid;j++)
		{
			/*if (matrix[i][j] == 0) cout << "0.000";*/
			if (matrix[i][j] >= 0)
			{
				cout << " ";
				lol = true;
			}
			if (lol = false)
			{
			cout << " ";
			}
		//	cout << matrix[i][j] << " ";
			printf("%.3f", matrix[i][j]);//
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int FindMainElementSTR(double **matrix, int wid, int str)		//ищем ведущий элемент по строке (вернем номер в СТРОКЕ элемента)
{
	int n = NULL;
	for (int j = 0;j < wid; j++)			
	{
		if (matrix[str][j] != 0)
		{
			//cout << matrix[str][j] << endl;
			//n = matrix[str][j];
			n = j;
			break;
		}
	}
	return n;
}
int FindFirstRow(double **matrix, int wid, int hei)		//находим строку, где раньше всего ведущий элемент-не ноль
{
	int k = 0;
	int minfirst = 99999999;
	for (int i = 0;i < hei; i++)
	{
		if (FindMainElementSTR(matrix, wid, i) < minfirst)
		minfirst = FindMainElementSTR(matrix, wid, i);
	}
	for (int i = 0;i < hei;i++)
		if (matrix[i][minfirst] != 0)
		{
			k = i;
			//break;
		}
	return k;
}
void MakeMeBetter(double **matrix, int wid,int goodstr)	//занесем в первую строку хорошую строку
{
	double buf=0;
	for (int i=0;i<wid;i++)
	{
		buf=matrix[0][i];
		matrix[0][i] = matrix[goodstr][i];
		matrix[goodstr][i] = buf;
	}
}
void make_me_triangle(double **matrix, int wid, int hei)
{
	if (FindFirstRow(matrix, wid, hei) != 0)
	{
		cout << "azazaz" << FindFirstRow(matrix, wid, hei) << endl;
		int qqq = FindFirstRow(matrix, wid, hei);
		MakeMeBetter(matrix, wid, qqq);
		show_me(matrix, wid, hei);
	}
	for (int i = 0;i < hei;i++)
	{
		double coeff = 0;

		double MAINELEMENT = matrix[i][FindMainElementSTR(matrix, wid, i)];
		coeff = 1 / (MAINELEMENT);
		cout << coeff << endl;

		for (int j = 0; j < wid; j++)
		{
			matrix[i][j] = matrix[i][j] * coeff;
		}

		MAINELEMENT = matrix[i][FindMainElementSTR(matrix, wid, i)];
		show_me(matrix, wid, hei);
		for (int k = i + 1; k < hei; k++)
		{   
		coeff = matrix[k][i] / MAINELEMENT;
		cout << coeff << endl;
		for (int l = 0;l<wid;l++)
		{
			matrix[k][l] = matrix[k][l] - (matrix[i][l] * coeff);
		}
		}
	}
	
}
void transponir(double **matrix,double *res, int wid,int hei)
{
	show_me(matrix, wid, hei);
	cout << matrix[hei][wid] << endl;
//	res[hei] = matrix[hei][wid] / matrix[hei][wid - 1];
	//cout << res[hei] << endl;
	/*for (int i = 1;i < hei;i++)
	{
		
		for (int j = 1;j < FindMainElementSTR(matrix, wid, hei-i);j++)
		{
			matrix[hei-i][wid] = matrix[hei-i][wid] - matrix[hei-i][wid - j] * res[hei-i];
			
		}
		res[hei-i] = matrix[hei - 1][wid] / matrix[hei-i][FindMainElementSTR(matrix,wid,hei-i)];
	}
	show_me(matrix, wid, hei);*/
}
int main()
{
	double **matrix;
	double *result1, *result2, result3, result4, result5;
	
	int height,width;
	srand(time(0));
	cout << "Enter number of equations" << endl;
	cin >> height;
	cout << "Enter max width" << endl;
	cin >> width;
	width++;
	result1 = new double[height];
	matrix = new double*[height];
	for (int i = 0;i < height;i++)
	{
		matrix[i] = new double[width];
	}
	for (int i = 0;i < height;i++)
		for (int j = 0;j < width;j++)
			matrix[i][j] = rand() % 10;
	matrix[0][0] = 0;
	show_me(matrix, width, height);
	make_me_triangle(matrix, width, height);
	//transponir(matrix,result1, width, height);
	show_me(matrix,width,height);
	return 0;
}