#include<iostream>
#include<string>
using namespace std;
int main() {
	int count = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C') {
			count += 2;
		}
		else if (s[i] == 'D' || s[i] == 'E' || s[i] == 'F') {
			count += 3;
		}
		else if (s[i] == 'G' || s[i] == 'H' || s[i] == 'I') {
			count += 4;
		}
		else if (s[i] == 'J' || s[i] == 'K' || s[i] == 'L') {
			count += 5;
		}
		else if (s[i] == 'M' || s[i] == 'N' || s[i] == 'O') {
			count += 6;
		}
		else if (s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S') {
			count += 7;
		}
		else if (s[i] == 'T' || s[i] == 'U' || s[i] == 'V') {
			count += 8;
		}
		else if (s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'Z') {
			count += 9;
		}
		count++;
	}
	cout << count;
}