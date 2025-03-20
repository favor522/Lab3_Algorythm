#include <iostream>
#include <Windows.h>
using namespace std;

int* WritePointer(int* a, int r) {
	*a = r;
	return a;
}

void initArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		WritePointer(arr + i, 2 + rand() % 8); 
	}
}

void ReadPointer(int* a) { 
	cout << *a << " "; 
}

int* NewPointer(int n) {

	int* A = new int[n];
	return A;
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		ReadPointer(arr + i);
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

void Check(int* a, int* b, int* c) {
	if (a != nullptr || b != nullptr || c != nullptr){ 
		cout << "���������� ��������� ��������� ������: ������ ������ �� �����������" <<  '\n';
	}

}

void Task1() {
	int n;
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
}

void Task2() {

}

void gui() {
	string choose;
	cout << "�������� ��������: " << '\n';
	cout << "1. ������� �� �������� ���� ���������" << '\n';
	cout << "2. ������� �� ���� ��������� �������" << '\n';
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	gui();
	return 0;
}