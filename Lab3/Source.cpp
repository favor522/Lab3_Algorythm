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
		cout << "������! ������� ��� ���� ������� \n";
	}
	else {
		delete[] A;
		A = nullptr;
	}
}

void Check(int* A) {
	if (A != nullptr) {
		cout << "���������� ������! ������ ������ �� ����� ���������" << '\n';
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
		cout << "������� ����� ��������� �������: ";
		cin >> n;
		if (cin.fail() || n <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "������� �������� ��������, �� ��������������� ��������! ���������� �����" << '\n';
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
	cout << "����� ��������� ������ 3 � ������ 8: " << CountSum(A, n) << '\n';
	FreePointer(A);
	gui();
}

void Task2() {
	int n, i = 0;
	while (true) {
		cout << "������� ����� ��������� �������: ";
		cin >> n;
		if (cin.fail() || n <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "������� ���� �������� �� ����� ��� <= 0. ��������� �������" << '\n';
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
	cout << "����� �������� ��������� : " << CountSumNechet(A, n) << '\n';
	FreePointer(A);
	gui();
}

void gui() {
	string choose;
	cout << "�������� ��������: " << '\n';
	cout << "1. ������� �� ������ � ����� ��������� 3 < n > 8" << '\n';
	cout << "2. ������� �� ������ � �������� ��������" << '\n';
	cout << "3. �����" << '\n';
	cin >> choose;
	if (choose == "1") {
		cout << "�������������..." << '\n';
		Task1();
	}
	else if (choose == "2") {
		cout << "�������������..." << '\n';
		Task2();
	}
	else if (choose == "3") {
		exit;
	}
	else {
		cout << "������� �������� ��������, ���������� ��� ���" << '\n';
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