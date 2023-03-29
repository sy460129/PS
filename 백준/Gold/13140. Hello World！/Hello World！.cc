#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int h, e, l, o, w, r, d, x;
	cin >> x;
	for(int i=1; i<=9; i++){
		h=i;
		for(int j=0; j<=9; j++){
			e=j;
			if(e==h){
				continue;
			}
			for(int k=0; k<=9; k++){
				l=k;
				if(l==e || l==h){
					continue;
				}
				for(int p=0; p<=9; p++){
					o=p;
					if(o==e || o==l || o==h){
						continue;
					}
					for(int q=0; q<=9; q++){
						r=q;
						if(r==e || r==h || r==l || r==o){
							continue;
						}
						for(int g=0; g<=9; g++){
							d=g;
							if(d==e || d==h || d==o || d==r || d==l){
								continue;
							}
							for(int u=1; u<=9; u++){
								w=u;
								if(w==e || w==h || w==r || w==o || w==l || w==d){
									continue;
								}
								else{
									if(10000*(h+w)+1000*(e+o)+o+100*(l+r)+20*l+d==x){
										cout << right << setw(3) << h << e << l << l << o << "\n";
										cout << "+ " << w << o << r << l << d << "\n";
										cout << "-------\n";
										cout << right << setw(7) << x;
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "No Answer";
}