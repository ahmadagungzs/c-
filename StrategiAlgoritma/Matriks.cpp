#include <iostream>
using namespace std;

int main(){
	int a, b, c, d, sum=0;
	cout << "Masukkan ukuran matriks pertama : ";
	cin >> a >> b;
	cout << "Masukkan ukuran matriks kedua : ";
	cin >> c >> d;
	cout << endl << "Matriks pertama berukuran " << a << " x "<< b << " dengan ";
	cout << "matriks kedua berukuran " << c << " x " << d;
	
	if (b!=c){
		cout << endl << "WARNING! Matriks tidak bisa dikalikan karena perbedaan antara" << endl;
		cout << "baris matriks pertama dan kolom matriks kedua";
	} else {
		int A[a][b];
		cout << endl << endl << "Masukkan angka untuk mengisi matriks pertama" << endl;
		for (int i=0;i<a;i++){
			for (int j=0;j<b;j++){
				cin >> A[i][j];
			}
		}	
		cout << endl;
		
		int B[c][d];
		cout << endl << "Masukkan angka untuk mengisi matriks kedua" << endl;
		for (int i=0;i<c;i++){
			for (int j=0;j<d;j++){
				cin >> B[i][j];
			}
		}
		cout << endl;
		
		int C[a][d];
		for (int i=0;i<a;i++){
			for (int j=0;j<d;j++){
				for (int k=0;k<c;k++){
					sum=sum+A[i][k]*B[k][j];
				}
				C[i][j]=sum;
				sum=0;
			}
		}
		
		cout << "Maka hasil perkalian kedua matriks adalah "<< endl;
		for (int i=0;i<a;i++){
			for (int j=0;j<d;j++){
				cout << C[i][j] << " ";
			}
			cout << endl;
		}
	}
}
