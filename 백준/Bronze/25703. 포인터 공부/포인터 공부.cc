#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << "int a;\n";
	for (int i = 0; i < n; i++) {
		cout << "int ";
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		if (i != 0) cout << "ptr" << i+1 << " = ";
		else cout << "ptr" << " = ";
		if (i == 0) cout << "&a;";
		else {
			if (i == 1) cout << "&ptr;";
			else cout << "&ptr" << i << ";";
		}
		cout << "\n";
	}
}