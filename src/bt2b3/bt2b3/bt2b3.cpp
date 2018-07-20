#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "conio.h"

#define MAX 1000

using namespace std;
int  A = 1,  B= 0;
int queue[MAX];
int back[MAX] = { -1 };
bool Free[MAX];
int a[MAX][MAX] = { 0 };
int n, m, u, v;
int Max;
const char *fn("C:\\Users\\ADMIN\\Desktop\\xxx\\doc\\xuat.txt");
ofstream fo(fn);
void push(int i){
	queue[++B] = i;
}
int pop(){
	return queue[A++];
}
bool isEmpty(){
	return A > B;
}
void Ghi(int u, int v, int back[]){

	if (u == v){
		cout << v << "  ";
		fo << v << "  ";
	}
	else if (back[v] == -1){
		cout << "khong thay duong";
		fo << "khong tim thay duong";
	}
	else {
		Ghi(u, back[v], back);
		cout << v << "  ";
		fflush(stdin);
		fo << v << "  ";
	}
}
void BFS(int k){
	push(k);
	Free[k] = false;
	while (!isEmpty()){
		int j = pop();
		for (int i = 1; i <= Max; i++)
		if (Free[i] && a[j][i] == 1){
			Free[i] = false;
			back[i] = j;
			if (i == v) break;
			push(i);
		}
	}
	Ghi(u, v, back);
}
int max(int a, int b){
	if (a > b) return a;
	else return b;
}
int _tmain(){
	int i, j;
	int l[MAX], r[MAX];
	const char *fn("C:\\Users\\ADMIN\\Desktop\\xxx\\doc\\nhap.txt");
	ifstream f(fn);
	if (!f){
		cout << "khong thay file";
	}
	else{
		f >> n >> m >> u >> v;
		for (i = 0; i< m; i++){
			f >> l[i] >> r[i];
			Max = max(Max, max(l[i], r[i]));
			a[l[i]][r[i]] = 1;
		}
	}
	cout << "So tuyen pho di qua: " << n << endl;
	cout << "So tuyen duong con co the di duoc: " << m << endl;
	cout << "Mat ma: " << u << endl;
	cout << "Sbox: " << v << endl;
	cout << "duong di: " << endl;
	for (i = 0; i< m; i++){
		cout << l[i] << "   " << r[i] << endl;
	}
	for (i = 0; i< Max; i++)
		Free[i + 1] = true;
	BFS(u);
	_getch();
	return 0;
	
}
