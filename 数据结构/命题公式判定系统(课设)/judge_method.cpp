#define _CRT_SECURE_NO_WARNINGS

#include "judge.h";

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <stack>
#include <stdlib.h>

using namespace std;

//￢   ∧  ∨  →  ↔
// !    *    +  ->  <->


int solve(char arr[], int left, int right);  //判定系统
int filterBracket(char* arr, int& size);//过滤（）
void pri(char arr[], int left, int right);  //打印函数
int myfind(char arr[], int left, int right, int& sig);  //查找第一个连接词位置
char getT(); //随机获取单变元
void randAtext(char* arr, int seed); //辅助生成随机命题
void randBtext(char* formula);  //生成随机命题
void generateSpecified(char* ops, int size, int num, char* formula);  //指定生成随机命题
void generateErrorSubject(char* fars); //指定生成错误命题




int filterBracket(char* arr, int& size) { //命题公式的左右括号过滤掉
	int sig = 1;
	stack<char> a;
	for (int i = 1; i <= size; i++) {
		if (arr[i] == '(') {
			a.push(arr[i]);
		}
		else if (arr[i] == ')') {
			if (a.empty()) { return 0; }
			a.pop();
		}
		else {
			arr[sig++] = arr[i];
		}
	}
	arr[sig] = '\0';
	size = sig - 1;
	if (a.empty())
	{
		return 1;
	}
	return 0;
}
int myfind(char arr[], int left, int right, int& sig) {
	//查找第一次出现的连接词
	sig = 0;
	for (int i = left; i <= right; i++) {

		if (i != right) {
			if (arr[i] == '*' || arr[i] == '+')return i;
			if (i + 1 <= right && arr[i] == '-' && arr[i + 1] == '>') { sig = 1; return i; }
			if (i + 2 <= right && arr[i] == '<' && arr[i + 1] == '-' && arr[i + 2] == '>') { sig = 2; return i; }
		}
	}
	return 0;
}


//错误返回0
int solve(char arr[], int left, int right) {

	if (arr[left] == '!') { left++; }

	if (left == right && arr[left] >= 97 && arr[left] <= 122) {
		return 1;
	}
	else if (left + 1 == right && arr[left] == '!' && arr[left + 1] >= 97 && arr[left + 1] <= 122) {
		return 1;
	}
	int sig = 0;
	int n = myfind(arr, left, right, sig);
	if (n == 0) {
		return 0;
	}
	/*cout << "递归：";
	pri(arr, left, n - 1);
	cout << "  ";
	pri(arr, n + sig + 1, right);
	cout << endl << "---------------" << endl;*/
	return solve(arr, left, n - 1) & solve(arr, n + sig + 1, right);

}

void pri(char arr[], int left, int right) {
	for (int i = left; i <= right; i++) {
		cout << arr[i];
	}
}


// 生成单个变元
char getT() {
	return 'c' + rand() % 10;  // 随机生成p,q,r,s,t
}
//随机
void randAtext(char* arr, int seed) {
	srand((unsigned)time(NULL));
	// 0:单变元, 1:带非, 2:二元运算
	int a = (rand() + seed) % 3;
	//cout << "---" << a << endl;
	switch (a)
	{
	case 0:
		arr[0] = getT() + seed % 4;
		arr[1] = '\0';
		break;
	case 1:
		arr[0] = '!';
		arr[1] = getT() + seed % 4;
		arr[2] = '\0';
		break;
	case 2:
		char ops[] = { '*', '+', '-', '<' };
		char op = ops[rand() % 4];
		if (op == '-') {
			sprintf(arr, "(%c->%c)", getT(), getT() + 2);
			arr[6] = '\0';
		}
		else if (op == '<') {
			sprintf(arr, "(%c<->%c)", getT(), getT() + 2);
			arr[7] = '\0';
		}
		else {
			sprintf(arr, "(%c%c%c)", getT(), op, getT() + 2);
			arr[5] = '\0';
		}
		break;
	}
}
//
void randBtext(char* formula) {

	srand((unsigned)time(NULL));
	int type = rand() % 4;  // 0:简单公式, 1:带括号, 2:多重运算, 3:复杂公式
	char temp1[10], temp2[10];
	char ops[] = { '*', '+', '-', '<' };
	char op = ops[rand() % 4];
	//cout << type;

	switch (2) {
	case 0:
		randAtext(formula, 0);
		break;

	case 1:
		randAtext(temp1, 0);
		sprintf(formula, "(%s)", temp1);
		break;

	case 2:
		randAtext(temp1, 0);
		randAtext(temp2, 15);

		if (op == '-') {
			sprintf(formula, "(%s->%s)", temp1, temp2);
		}
		else if (op == '<') {
			sprintf(formula, "(%s<->%s)", temp1, temp2);
		}
		else {
			sprintf(formula, "(%s%c%s)", temp1, op, temp2);
		}
		break;
	case 3:
		char a[5];
		char b[5];
		randAtext(temp1, 0);
		randAtext(a, rand() % 2);
		randAtext(b, rand() % 5);
		sprintf(formula, "((%s)%c(%s)%c(%s))", temp1, op, a, op, b);
		break;
	}
}
//ops连接词 size数组大小 num数量变元
void generateSpecified(char* ops, int size, int num, char* formula) {
	srand((unsigned)time(NULL));
	int ra = rand() % size;
	char op = ops[ra];
	char a = 'a';

	char temp[100];
	if (op == '-') {
		sprintf(formula, "%c->%c", a, a + 1);
	}
	else if (op == '<') {
		sprintf(formula, "%c<->%c", a, a + 1);
	}
	else {
		sprintf(formula, "%c%c%c", a, op, a + 1);
	}

	for (int i = 2; i < num; i++) {
		strcpy(temp, formula);  // 保存当前formula的内容
		if (op == '-') {
			sprintf(formula, "(%s)->%c", temp, a + i);
		}
		else if (op == '<') {
			sprintf(formula, "(%s)<->%c", temp, a + i);
		}
		else {
			sprintf(formula, "(%s)%c%c", temp, op, a + i);
		}
		op = ops[(ra + i) % size];

	}
	return;
}

void generateErrorSubject(char* fars) {
	srand((unsigned)time(NULL));
	int type = rand() % 3;
	char arr[] = { '-','<','+','*' };
	int a = rand() % 8;
	generateSpecified(arr, 4, a, fars);
	switch (type) {
	case 0:
		sprintf(fars, "%s)", fars);
		break;
	case 1:
		sprintf(fars, "%sa", fars);
		break;
	case 2:
		sprintf(fars, "(%s", fars);
		break;
	}

}


