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

template<typename T>
void swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}
 
int main()
{
	int a = 4;
	int* p = &a;
	int& r = *p;

	cout << r;




}