#include <iostream>
using namespace std;
int main(){
	int n;
	cout << "Masukkan ordo matriks yang akan dikalikan (n x n) : ";
	cin >> n;
  	int A[n][n],B[n][n],C[n][n],i,j;
	int mat1,mat2,mat3,mat4,mat5,mat6,mat7;

  	cout<<"Masukkan isi matriks pada matriks A: ";
  	for(i=0;i<n;i++){
  		for(j=0;j<n;j++){
  			cin>>A[i][j];
		  }
  		}

  	cout<<"Masukkan isi matriks pada matriks B : ";
  	for(i=0;i<n;i++){
  		for(j=0;j<n;j++){
  			cin>>B[i][j];
	  	}
 	}
  
  	cout<<"Berikut adalah matriks pertama : ";
  	for(i=0;i<n;i++){
    	cout<<endl;
      	for(j=0;j<n;j++){
      		cout<<" "<<A[i][j];
	  	}
  	}cout<<endl;

  	cout<<"dan ini adalah matriks yang kedua : ";
  	for(i=0;i<n;i++){
      	cout<<endl;
      	for(j=0;j<n;j++){
      		cout<<" "<<B[i][j];
	  	}
  	}

  	mat1 = (A[0][0] + A[1][1])*(B[0][0]+B[1][1]);
  	mat2 = (A[1][0]+A[1][1])*B[0][0]);
  	mat3 = A[0][0]*(B[0][1]-B[1][1]);
  	mat4 = A[1][1]*(B[1][0]-B[0][0]);
  	mat5 = (A[0][0]+A[0][1])*B[1][1];
  	mat6 = (A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
  	mat7 = (A[0][1]-A[1][1])*(B[1][0]+B[1][1]);

  	C[0][0]=mat1+mat4-mat5+mat7;
  	C[0][1]=mat3+mat5;
  	C[1][0]=mat2+mat4;
  	C[1][1]=mat1-mat2+mat3+mat6;

   	cout<<"\nSetelah perkalian menggunakan Algoritma Strassen :";
   	for(i=0;i<n;i++){
      	cout<<endl;
      	for(j=0;j<n;j++){
      		cout<<"\t"<<C[i][j];
	  	}
   	}
}

