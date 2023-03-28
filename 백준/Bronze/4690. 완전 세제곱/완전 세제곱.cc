#include <iostream>
#define rep_(i, a, b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
	rep_(i, 6, 100){
		rep_(j, 2, 100){
			rep_(k, j+1, 100){
				rep_(l, k+1, 100){
					if(i*i*i==j*j*j+k*k*k+l*l*l){
						cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << l << ")\n";
					}
				}
			}
		}
	}
}