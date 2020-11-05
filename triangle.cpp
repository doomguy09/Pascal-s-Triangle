// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int numberOfSpaces(int num) {
	int count = 0;
	do {
		++count;
		num /= 10;
	} while(num > 0);
	count = 6 - count;
	//std::cout << "Count = " << count;
	return count;
}

void print(int n, int **arr) {
	int count = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			count = numberOfSpaces(arr[i][j]);
			for (int k = 0; k < count; ++k) {
				std::cout << ' ';
			}
			std::cout << arr[i][j];
		}		
		std::cout << std::endl;
	}
}

void PascalsTriangle(int n) {
	int **arr;
		arr = new int*[n];
	for (int i = 0; i <= n; ++i) {
		arr[i] = new int[i+1];
	}
	for (int i = 0; i <= n; ++i) {
		arr[i][0] = 1; 
		arr[i][i-1] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i-1; ++j) {
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	}
	print(n, arr);
}


int main()
{
	int n;
	do {
		std::cout << "Put the number of cols u need(from 1 to 20): ";
		std::cin >> n;
	} while (n > 20 || n <= 0);
	PascalsTriangle(n);
}

