#include <iostream>
#include <math.h>
using namespace std;

int main(){
	float a;
	bool prima = true, bulat = true;
	
	input:
	cin>>a;
	
	int b = a;
	
	if(b!=a){
		bulat = false;
		cout << "Masukkan bilangan bulat "<<endl;
		goto input;
	} else if(bulat){
		int akar=sqrt(b);
		for (int i=2;i<=akar;i++){ //mencari bilangan pria dari 2 hingga akar n
				if(b%i == 0){ //menguji n apakah habis dibagi bilangan prima tersebut
				//jika n habis dibagi bilangan prima, maka n adalah bilangan komposit
					prima = false;
					break;
				}	
			}
		}
		if(prima) {
			cout << b << " adalah bilangan prima";
		} else { 
			cout << b << " adalah bilangan komposit";			
		}
}
