#include "stdafx.h"
#include "string"
#include "conio.h"
#include "iostream"
#include "fstream"
#include <io.h>


#define MAX 100;
using namespace std;


int _tmain()
{
	char a[100];
	char b[100];
	char s1[100];
	char s2[100];
	int m = 0;
	int d = 0;
	int ln = 0;
	cout << "> Nhap duong dan file: ";
	fflush(stdin);
	gets_s(a);
	string text;
	ifstream f;
	f.open(a, ios::in);
	ofstream file("C:\\Users\\ADMIN\\Desktop\\xxx\\doc\\ra.txt");
	file << "nhap vao: " << a << endl;
	if (_access(a, 0) != -1)
	{
		cout << "> File ton tai, moi ban chon: " << endl;
		while (true){
			cout << "-------------------------------" << endl;
			cout << "---       1. Tim kiem       ---" << endl;
			cout << "---       2. Sua            ---" << endl;
			cout << "---       3. Thoat          ---" << endl;
			cout << "------------------------------ " << endl;
			cout << "moi ban chon : ";
			cin >> m;
			switch (m){
			case 1:
				file << "Context 1: Tim kiem tu khoa " << endl;
				cout << " Nhap tu khoa: ";
				fflush(stdin);
				gets_s(s1);
				file << "\t Tu khoa: " << s1 << endl;
				while (f.getline(b, 255)) {
					fflush(stdin);
					char *p;
					p = strstr(b, s1); ln++;
					while (p){
						int i = p - b + 1;
						d++;
						p++;
						p = strstr(p, s1);
						cout << ">\t Ln " << ln << "," << " Col " << i << endl;
						file << ">\t Ln " << ln << "," << " Col " << i << endl;
					}
				}
				cout << "> So lan xuat hien: " << d << endl;
				file << "\t So lan xuat hien: " << d << endl;
				break;
			case 2:
				file << "Context 2: Thay the bang tu khoa moi" << endl;
				cout << " Nhap tu khoa can thay the: " << endl;
				fflush(stdin);
				gets_s(s1);
				file << "\t Tu khoa: " << s1 << endl;
				cout << " Nhap tu khoa moi: " << endl;
				fflush(stdin);
				gets_s(s2);
				file << "\t Tu khoa moi: " << s2 << endl;
				while (f.getline(b, 255)){
					char kq[100];
					int t = 0, i = 0, j = 0, k = 0;
					int ns1 = strlen(s1), ns2 = strlen(s2);
					strcat_s(b, "|");
					while (b[i] != '|'){
						k = i; j = 0;
						while (b[k] == s1[j]) {
							k++; j++;
						}
						if (j == ns1) {
							for (int m = 0; m<ns2; m++)
								kq[t++] = s2[m];
							i = ns1 + i;
						}
						else kq[t++] = b[i++];
					}
					cout << endl;
					for (int i = 0; i<t; i++) cout << kq[i];
					text = text + kq + "\n";
				}

				file << text;
				file.close();
				cout << "\n Thay the tu khoa thanh cong" << endl;
				break;
			case 3:
				exit(0);
				break;
			default:
				cout << "Khong hop le" << endl;
			}
		}
	}
	else
	{
		cout << "File khong hop le";
	}
	f.close();
	_getch();
	return 0;
}