#include <iostream>
using namespace std;

int main(){

    char temp, checker;

    char player[3][3], comp[3][3]; // comp buat kucing. player buat tikus

    cout<<"====== SELAMAT DATANG DI PROGRAM PERMAINAN KEJAR TIKUS ======"<<endl;
    cout<<"Di sini peran Anda sebagai tikus yang harus lolos dari kejaran kucing dan komputer sebagai kucing!"<<endl;
    cout << "RULES : " << endl << "\t" << "1. Tikus hanya bisa menuju ke 2 simpul terdekat dari simpul sekarang secara vertikal maupun horizontal" << endl;
    cout << "\t" << "2. Poin no 1 berlaku juga untuk kucing walaupun kucing dijalankan oleh komputer" << endl;
    cout << "\t" << "3. Tikus dan kucing hanya dapat melakukan satu kali backtrack untuk simpul yang sama" << endl;
    cout << "\t" << "4. Permainan akan selesai apabila tikus dan kucing berada di satu simpul yang sama" << endl << endl;
	//cout << "\t" << "5. "

    char p1[3][3], p2[3][3], p3[3][3];
    bool t[3][3]={0,0,0,0,0,0,0,0,0};
    bool k[3][3]={0,0,0,0,0,0,0,0,0};
    p1[0][0]='A'; //untuk jalan tikus
    p1[0][1]='C';
    p1[1][0]='H';

    p2[2][2]='B'; //untuk jalan kucing
    p2[2][1]='E';
    p2[1][2]='D';

	p3[2][0]='G'; //untuk perpindahan yang memungkinkan antara kucing dan tikus
	p3[1][1]='F';
	p3[0][2]='I';

    for (int i=0; i<1; i++){
        for (int j=0; j<1; j++){
        	cout << "Tikus mau pergi ke mana? ";
        	cin>>player[0][0];
        	if (player[0][0] == p1[0][0]){
           		cout<<"Inputan yang Anda masukkan salah, tikus tidak bergerak" << endl;
        	} else if (player[0][0] == p1[0][1]){
            	temp=p1[0][1];
            	p1[0][1]=player[0][0];
            	player[0][0]=temp;
            	cout << "Tikus sekarang berada di " << p1[0][1] << endl;
            	t[0][1]=true;
            	//break;
        	} else if (player[0][0] == p1[1][0]){
       			temp=p1[1][0];
        		p1[1][0]=player[0][0];
        		player[0][0]=temp;
        		cout << "Tikus sekarang berada di " << p1[1][0] << endl;;
        		t[1][0]=true;
        	} else {
            	cout<<"Tikus tidak bisa pindah ke simpul ini" << endl;
        	}
 
        }
        checker = player[0][0] ;
    }


        	if (checker==p1[0][1]){
        		temp=p2[2][1];
        		p2[2][1]=p2[2][2];
        		p2[2][2]=temp;
        		cout << "Kucing sekarang ada di " << p2[2][2] << endl;
        		k[0][1]=true;
			} else if (checker==p1[1][0]){
				temp=p2[1][2];
        		p2[1][2]=p2[2][2];
        		p2[2][2]=temp;
        		cout << "Kucing sekarang ada di " << p2[2][2] << endl;
        		k[1][0]=true;
			} else {
				cout << "Kucing tidak bisa pindah ke simpul ini" << endl;
			}

    for (int i=0;i<2;i++){
    	for (int j=0;j<2;j++){
    		if (k[i][j]==true && t[i][j]==true){
    			cout << "Tikus mau pindah ke mana? ";
    			cin >> player[0][0];
    			if (player[0][0]=='I'){
    				temp=p2[2][2];
    				p2[2][2]=p2[2][1];
    				p2[2][1]=temp;
    				cout << "Sekarang tikus ada di titik I dan kucing ada di titik B (kucing backtracking)" << endl;
				} else if (player[0][0]=='A'){
					temp=p3[2][0];
					p3[2][0]=p2[2][1];
					p2[2][1]=temp;
					cout << "Sekarang tikus ada di titik A lagi (backtracking) dan kucing ada di titik G";
				} else if (player[0][0]=='F'){
					temp=p3[1][1];
					p3[1][1]=p2[2][1];
					p2[2][1]=temp;

					cout << "Permainan selesai karena posisi tikus berada di titik F"<<endl;
					cout << "lalu kucing tidak bisa backtrack lagi sehingga kucing harus maju ke titik F"<<endl;
					cout << "dan mereka bertemu.";
				} else {
					cout << "tikus tidak bisa menuju simpul yang Anda inputkan" << endl;
				}
			} else if (t[1][0]==true && k[1][2]==true){
				cout << "Tikus mau pindah ke mana? ";
				cin >> player[0][0];
				if(player[0][0]=='A'){
					temp=p3[0][2];
					p3[0][2]=p2[1][2];
					p2[1][2]=temp;
					cout << "Sekarang tikus ada di simpul A (backtrack) dan kucing berada di simpul I";
				} else if (player[0][0]=='G'){
					temp=p2[2][2];
					p2[2][2]=p2[1][2];
					p2[1][2]=temp;
					cout << "Sekarang tikus ada di simpul G dan kucing ada di titik B (backtrack)";
				} else if (player[0][0]=='F'){
					temp=p3[1][1];
					p3[1][1]=p2[1][2];
					p2[1][2]=temp;
					cout << "Permainan selesai karena posisi tikus berada di titik F"<<endl;
					cout << "lalu kucing tidak bisa backtrack lagi sehingga kucing harus maju ke titik F"<<endl;
					cout << "dan mereka bertemu.";
				} else {
					cout << "tikus tidak bisa menuju simpul yang Anda inputkan";
				}
			}
		}
	}

	for (int i=0;i<2;i++){
    	for (int j=0;j<2;j++){
    		if (k[i][j]==true && t[i][j]==true){
    			cout << "Tikus mau pindah ke mana? ";
    			cin >> player[0][0];
    			if (player[0][0]=='C'){
    				temp=p1[0][1];
    				p1[0][1]=p3[0][2];
    				p3[0][2]=temp;
    				cout << "Sekarang tikus ada di titik C (tikus backtrack) dan kucing ada di titik D (kucing backtracking)";
				} else if (player[0][0]=='D'){
					temp=p3[0][2];
					p3[0][2]=p2[1][2];
					p2[1][2]=temp;
					cout << "Sekarang tikus ada di titik D dan kucing ada di titik D. Permainan selesai";
				} else {
					cout << "tikus tidak bisa menuju simpul yang Anda inputkan" << endl;
				}
			}
		}
	}

	for (int i=0;i<2;i++){
    	for (int j=0;j<2;j++){
    		if (k[i][j]==true && t[1][0]==true){
    			cout << "Tikus mau pindah ke mana? ";
    			cin >> player[0][0];
    			if (player[0][0]=='C'){
    				temp=p1[0][1];
    				p1[0][1]=p3[0][2];
    				p3[0][2]=temp;
    				cout << "Sekarang tikus ada di titik C dan kucing ada di titik D (kucing backtracking)" << endl;
				} else if (player[0][0]=='D'){
					temp=p3[0][2];
					p3[0][2]=p2[1][2];
					p2[1][2]=temp;
					cout << "Sekarang tikus ada di titik D dan kucing ada di titik D. Permainan selesai" << endl;
				} else {
					cout << "tikus tidak bisa menuju simpul yang Anda inputkan" << endl;
				}
            }
        }
    }
}
