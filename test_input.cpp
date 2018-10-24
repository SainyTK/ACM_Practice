#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream testfile;
	testfile.open("fenwick_test_input.txt");
	
	int n;
	testfile >> n;
	cout << n << "\n";
	testfile >> n;
	cout << n << "\n";
	testfile >> n;
	cout << n << "\n";
	
	return 0;
}
