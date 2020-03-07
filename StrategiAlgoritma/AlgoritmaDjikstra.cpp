#include <iostream>
#include <stdlib.h>
#define INF 999
using namespace std;

int main(){
    int js, i, j, awal;
    cout << "ALGORITMA DIJKSTRA (Shortest Path Problem)" << endl << endl;
    cout << "Masukkan jumlah simpul yang ada: ";
    cin  >> js;
    int Graf[js][js], GrafSem[js][js], jarak[js], come[js], temp[js], hitung;
    cout << "Masukkan jarak antar simpul: " << endl;
    for(i = 1 ; i <= js ; i++){
        for (j=1 ; j<= js ; j++){
        	cout << "[" << i << "]" << "[" << j << "] : "; 
            cin >> Graf[i][j]; 
        }
    }
    cout << "Masukkan simpul awal: ";
    cin  >> awal;

    for(i=1;i<=js;i++){
        for (j=1;j<=js;j++){
            if (Graf[i][j]==0){
                GrafSem[i][j]=INF;
            }
            else{
                GrafSem[i][j]=Graf[i][j];
            }
        }
    }
    for (i=0;i<js;i++){
        jarak[i] = GrafSem[awal][i];
        temp[i] = awal;
        come[i] = 0;
    }
    
    jarak[awal] = 0;
    come[awal] = 1;

    hitung = 1; //dimulai dari 1 karena kita tidak akan menghitung vertex asal lagi

    //proses untuk menghitung vertex yang dikunjungi
    int minPath, nextvertex;
    while (hitung < js-1){
        minPath = INF;
        for (i=1;i<=js;i++){
            //jika jarak lebih kecil dari jarak minimum dan vertex belum dikunjungi
            // maka jarak minimum adalah jarak yang sudah dibandingkan sebelumnya dengan jarakmin
                if(jarak[i]<minPath&&come[i]!=1){
                    minPath = jarak[i];
                    nextvertex = i; //untuk memberikan vertex pada jarak minimum
                }
        }

        // untuk mengecek vertex selanjutnya yang terhubung dengan vertex lain yang memiliki jarak minimum
        come[nextvertex] = 1;
        for(i=0;i<=js;i++){
            if(come[i]!=1){
                if(minPath+GrafSem[nextvertex][i]<jarak[i]){
                    jarak[i] = minPath+GrafSem[nextvertex][i];
                    temp[i] = nextvertex;
                }
            }
        }
    hitung++;
    }
    //nenampilkan jalur dan jarak untuk setiap vertex
    int a[js+1],k;
    for (i = 0; i < js ;i++){
        if(i!=awal){
            cout << endl << endl << "Jarak untuk simpul ke" << i << " adalah: " << jarak[i] << endl << endl;
            if(j=i){
            cout << " <- " << i;
            }
            while(j!=awal){
                j=temp[j];
                cout << j;
                if(j!=awal){
                    cout << "<-";
                }
            }
        }
    }
    cout << "\nTotal Jaraknya adalah: " << jarak[js - 1] << endl;
    return 0;
}
