//Задача 1. Дано двовимірний масив з двадцяти двох рядків і двох стовпців. Знайти номера двох сусідніх рядків, сума елементів в яких максимальна. Відсортувати кожен рядок масиву за спаданням (функція).

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int rows = 22;
	const int columns = 2;
	const int random = 25;
	const int minValue = 0;
	const int maxValue = 100;

	cout << "Задача 1. Дано двовимірний масив з двадцяти двох рядків і двох стовпців. Знайти номера двох сусідніх рядків, сума елементів в яких максимальна. Відсортувати кожен рядок масиву за спаданням (функція)\n" << endl;

	// Генерування масиву
	srand(time(nullptr));
	int array[rows][columns];

	//Умови генерування двовимірного масиву
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (i > 0 && rand() % 100 < random) {
				array[i][j] = array[i - 1][j];
			}
			else {
				array[i][j] = rand() % (maxValue - minValue + 1) + minValue;
			}
		}
	}

	// Вивід згенерованого двовимірного масиву та суми кожного рядка
	cout << "Згенерований двовимірний масив зі значеннями від " << minValue << " до " << maxValue << ":" << endl;
	for (int i = 0; i < rows; ++i) {
		cout << "Рядок" << setw(2) << i + 1 << ": ";

		int rowsum = 0;
		for (int j = 0; j < columns; ++j) {
			cout << setw(4) << array[i][j] << " ";
			rowsum += array[i][j];
		}
		cout << " = " << rowsum;
		cout << endl;
	}

	// Знаходження номера пари сусідніх рядків, сума елементів в яких максимальна
	int maxSum = 0;
	int maxSumRow1, maxSumRow2;

	for (int i = 0; i < rows - 1; ++i) {
		int currentSum = 0;
		for (int j = 0; j < columns; ++j) {
			currentSum += array[i][j] + array[i + 1][j];
		}
		if (currentSum > maxSum) {
			maxSum = currentSum;
			maxSumRow1 = i + 1;
			maxSumRow2 = i + 2;
		}
	}
	cout << "Номери двох сусідніх рядків, сума елементів в яких максимальна: " << maxSumRow1 << " та " << maxSumRow2 << endl;

	// Обрахунок та вивід загальної суми двох сусідніх рядків
	int totalSum = 0;
	cout << "Сума рядків " << maxSumRow1 << " та " << maxSumRow2 << ": ";
	for (int j = 0; j < columns; ++j) {
		totalSum += array[maxSumRow1 - 1][j] + array[maxSumRow2 - 1][j];
	}
	cout << totalSum << endl;

	// Сортування кожного рядка масиву за спаданням
	for (int i = 0; i < rows; ++i) {
		sort(begin(array[i]), end(array[i]), greater<int>());
	}
	cout << "\nВідсортований масив за спаданням кожного рядка:" << endl;
	for (int i = 0; i < rows; ++i) {
		cout << "Рядок" << setw(2) << i + 1 << ": ";
		for (int j = 0; j < columns; ++j) {
			cout << setw(4) << array[i][j] << " ";
		}
		cout << endl;
	}

	cin.ignore(); //ігнорування авто введення
	return 0;
}