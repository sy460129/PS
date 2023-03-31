#include <iostream>
#include <deque>
using namespace std;
deque<int>d, d2;
int main(){
	d.push_back(1);
	int n, t; cin >> n;
	t=(n+1)/2;
	d2.push_back(t);
	for(int i=2; i<=n; i++){
		i%2 ? d.push_front(i) : d.push_back(i);
		i%2 ? d2.push_back(t-i/2) : d2.push_back(t+i/2);
	}
	cout << "YES\n";
	while(!d.empty()){
		cout << d.front() << " ";
		d.pop_front();
	}
	cout << "\n";
	while(!d2.empty()){
		cout << d2.front() << " ";
		d2.pop_front();
	}
}