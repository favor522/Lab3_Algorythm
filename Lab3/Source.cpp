#include <iostream>
#include <Windows.h>
using namespace std;

void gui();

int* WritePointer(int* Pointer) {
	int numb = rand() % 10 -2;
	*Pointer = numb;
	return Pointer;
}

void ReadPointer(int* Pointer) { 
	cout << *Pointer << " "; 
}

int* NewPointer(int n) {
	int* A = new int[n];
	return A;
}

void MassivPrinter(int* mas, int n) {
	for (int i = 0; i < n; i++) {
		ReadPointer(mas + i);
	}
	cout << '\n';
}

void FreePointer(int*& A) {
	if (A == nullptr) {
		cout << "Ошибка! Функция уже была вызвана \n";
	}
	else {
		delete[] A;
		A = nullptr;
	}
}

void Check(int* A) {
	if (A != nullptr) {
		cout << "Перезапись данных! Старые данные не будут сохранены" << '\n';
		FreePointer(A);
	}
}

int CountSum(int* mas, int n) {
	int Sum = 0;
	for (int i = 0; i < n; i++) {
		int el = *(mas + i);
		if (el > 3 || 8 < el) {
			Sum += el;
		}
	}
	return Sum;
}

int CountSumNechet(int* mas, int n) {
	int Sum = 0;
	for (int i = 0; i < n; i++) {
	int el = *(mas + i);
		if (el%2 != 0) {
			Sum += el;
		}
	}
	return Sum;
}

void Task1() {
	int n, i = 0;
	while (true) {
		cout << "Введите число элементов массива: ";
		cin >> n;
		if (cin.fail() || n <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Введено неверное значение, не соответствующее условиям! Попробуйте снова" << '\n';
		}
		else {
			break;
		}
	}
	int* A = nullptr;
	Check(A);
	A = NewPointer(n);
	for (int i = 0; i < n; i++) {
		WritePointer(A + i);
	}
	MassivPrinter(A, n);
	Check(A);
	A = NewPointer(n);
	for (int i = 0; i < n; i++) {
		WritePointer(A + i);
	}
	MassivPrinter(A, n);
	cout << "Сумма элементов больше 3 и меньше 8: " << CountSum(A, n) << '\n';
	FreePointer(A);
	gui();
}

void Task2() {
	int n, i = 0;
	while (true) {
		cout << "Введите число элементов массива: ";
		cin >> n;
		if (cin.fail() || n <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Введёное вами значение не число или <= 0. Повторите попытку" << '\n';
		}
		else {
			break;
		}
	}
	int* A = nullptr;
	Check(A);
	A = NewPointer(n);
	for (int i = 0; i < n; i++) {
		WritePointer(A + i);
	}
	MassivPrinter(A, n);
	Check(A);
	A = NewPointer(n);
	for (int i = 0; i < n; i++) {
		WritePointer(A + i);
	}
	MassivPrinter(A, n);
	cout << "Сумма нечётных элементов : " << CountSumNechet(A, n) << '\n';
	FreePointer(A);
	gui();
}

void gui() {
	string choose;
	cout << "Выберите действие: " << '\n';
	cout << "1. Задание на массив и сумму элементов 3 < n > 8" << '\n';
	cout << "2. Задание на массив и нечётные элементы" << '\n';
	cout << "3. Выйти" << '\n';
	cin >> choose;
	if (choose == "1") {
		cout << "Инициализация..." << '\n';
		Task1();
	}
	else if (choose == "2") {
		cout << "Инициализация..." << '\n';
		Task2();
	}
	else if (choose == "3") {
		exit;
	}
	else {
		cout << "Введено неверное действие, попробуйте ещё раз" << '\n';
		gui();
	}
}

int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	gui();
	return 0;
}