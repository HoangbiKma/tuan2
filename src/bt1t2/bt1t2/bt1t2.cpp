#include "stdafx.h"
#include "string"
#include "conio.h"
#include "iostream"
#include "stdlib.h"
#include "stack"
#include "fstream"
#include "iostream"

#define MAX 50;
using namespace std;
void Fix(string s){
	const char *p(" C:\\Users\\ADMIN\\Desktop\\xxx\\doc\\output.txt");

	ofstream f(p);
	int i;
	stack<char> a, b;//stack khai luu ngoac duoc xet và con lai
	stack<int> c, d;//vi tri dau ngoac
	int dem = 0;
	for (i = 0; i < s.length(); i++){
		//day cac dau mo ngoac vao stack va vi tri cua no

	

		if (s[i] == '(' || s[i] == '{'){
			a.push(s[i]);
			d.push(i);
		}
		//gap dau dong ngoac thi xoa dinh
		else if ((s[i] == ')'&&a.top() == '(') || (s[i] == '}'&&a.top() == '{')){
			a.top();
			a.pop();
			d.top();
			d.pop();
		}
		//gap dau dong ngoac va dinh stack a.empty or khac loai dau
		else if (s[i] == ')' && (a.top() != '(' || a.empty())){
			b.push('(');
			c.push(i);
			dem++;
		}
		else if (s[i] == '}' && (a.top() != '{' || a.empty())){
			b.push('{');
			c.push(i);
			dem++;
		}
	}
	cout << "so loi la: " << dem + a.size() << endl;
	f << "so loi la: " << dem + a.size() << endl;
	cout << "sua loi: " << endl;
	f << "sua loi: " << endl;
	//dau ngoac con lai trong stack b
	while (!b.empty()){
		if (b.top() == '(' || b.top() == '{'){
			cout << c.top() + 1 << " " << b.top() << endl;
			f << c.top() + 1 << " " << b.top() << endl;
			c.pop(); b.pop();
		}
		else if (b.top() == ')' || b.top() == '}'){
			cout << c.top() - 1 << " " << b.top() << endl;
			f << c.top() - 1 << " " << b.top() << endl;
			c.pop(); b.pop();
		}
	}
	//dau ngoac con lai trong stack a
	while (!a.empty()){
		if (a.top() == '('){
			cout << d.top() + 1 << " " << ")" << endl;
			f << d.top() + 1 << " " << ")" << endl;
			a.pop(); d.pop();
		}
		else if (a.top() == '{'){
			cout << d.top() + 1 << " " << "}" << endl;
			f << d.top() + 1 << " " << "}" << endl;
			a.pop(); d.pop();
		}
	}
}
int _tmain(){

	const char *t(" C:\\Users\\ADMIN\\Desktop\\xxx\\doc\\input.txt ");
	string s;
	fstream f(t);
	if (!f) cout << "khong tim thay file" << endl;
	else
	{
		f >>  s;
	}
	Fix(s);
	f.close();
	
	_getch();
}