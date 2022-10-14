#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//ostream& operator << (ostream& os, istream& is)
//{
//	string s;
//	is >> s;
//	return os << s << " ";
//}
//
//
//int main()
//{
//	string file1, file2;
//
//	cout << "Enter name of first file: ";
//	cin >> file1;
//	ifstream in1{ file1 };
//	
//	cout << "Enter name of second file: ";
//	cin >> file2;
//	ifstream in2{ file2 };
//
//	ofstream out{ "out.txt" };
//
//	
//
//	
//
//	out << in1 << in2;
//
//
//}

void push_back(int*& arr, int& size, const int value)
{
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	newArr[size] = value;
	delete[] arr;
	arr = newArr;
	size++;
}

void pop_back(int*& arr, int& size)
{
	int* newArr = new int[--size];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
}

void push_begin(int*& arr, int& size, const int value)
{
	int* newArr = new int[++size];
	newArr[0] = value;
	for (int i = 0; i < size; i++) {
		newArr[i + 1] = arr[i];
	}
	delete[] arr;
	arr = newArr;
}

void pop_begin(int*& arr, int& size)
{
	int* newArr = new int[--size];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i + 1];
	}
	delete[] arr;
	arr = newArr;
}

void push_inpos(int*& arr, int& size, const int value, const int pos)
{
	bool is_push = false;
	int* newArr = new int[++size];
	for (int i = 0; i < size; i++) {
		if (i == pos) {
			newArr[i] = value;
			is_push = true;
			continue;
		}
		newArr[i] = arr[i - is_push];
	}
	delete[] arr;
	arr = newArr;
}

void pop_inpos(int*& arr, int& size, const int pos)
{
	bool is_pop = false;
	int* newArr = new int[--size];
	for (int i = 0; i < size; i++) {
		if (i == pos) {
			is_pop = true;
		}
		newArr[i] = arr[i + is_pop];
	}
	delete[] arr;
	arr = newArr;
}

 
int main()
{
	


	

}