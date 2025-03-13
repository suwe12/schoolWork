#define _CRT_SECURE_NO_WARNINGS

#include "judge.h";

/*

				 / $$$$$$$ / $$  / $$  /$$  / $$ / $$   / $$$$$$
				/ $$_____/ | $$  | $$ | $$ | $$ | $$  / $$__  $$
			   |   $$$$$$  | $$  | $$ | $$ | $$ | $$ | $$$$$$$$
				\____  $$  | $$  | $$ | $$ | $$ | $$ | $$_____/
				/$$$$$$$/  |  $$$$$$/ |  $$$$$/$$$$/ |  $$$$$$$
			   |_______/   \______/    \_____/\___/   \_______/

*/ 


//￢   ∧  ∨  →  ↔
// !    *    +  ->  <->
int main() {

	int option = 1;
	do {
		printf("------------------------------------\n");
		printf("1.输入任意字符串，判断命题公式\n");
		printf("2.随机生成正确命题公式\n");
		printf("3.指定生成正确命题公式\n");
		printf("4.错误生成命题公式\n");
		printf("5.退出\n");
		printf("------------------------------------\n");
		char arr[100];
		char ops[5];

		scanf("%d", &option);
		getchar();
		switch (option) {
		case 1:
			int right;
			cout << "请输入命题(小写字母)(蕴含请输入:-> ,等价:<-> ,析取:+ , 合取:*)：";
			cin.getline(arr + 1, 100);
			/*cin >> arr+1;*/
			right = strlen(arr + 1);
			if (filterBracket(arr, right) == 0) { cout << "命题错误--\n"; break; }
			if (solve(arr, 1, right) == 1) { cout << "命题正确\n" << endl; }
			else cout << "命题错误\n";
			break;
		case 2:
			cout << "随机生成命题公式为：";
			randBtext(arr);
			cout << arr << endl;
			break;
		case 3:
			int num, size;
			cout << "请输入连接词的数量" << endl;
			cin >> size;
			cout << "请输入连接词(相邻不需要空格) 蕴含请输入:- ,等价:< ,析取:+ , 合取:* " << endl;
			cin >> ops;
			cout << "请指定生成变元数量" << endl;
			cin >> num;
			generateSpecified(ops, size, num, arr);
			cout << arr << endl;
			break;
		case 4:
			generateErrorSubject(arr);
			cout << arr << endl;
			break;
		case 5:
			return 0;
		default:
			cout << "输入错误" << endl;
			break;
		}

	} while (option != 5);

	return 0;

}


//命题公式测试用例
/*
(a*b)+(a*c)
a->(b+c)
((a*b)*c
(a,->)
a<-b*c
a*b*c
a+b(a)
a*b+c
((a*b)*b)(
(a*b)+(a*c)
((a*b)*b))
(

p++q+r
(p*)*q
(p+)+q
p-q
p>q
p=q
p&q
p|q
p^q
((p->q)*(!q->r))
((!p+q)*(p+!q))
(!p<->q)*(p<->!q)
((p*q)+(r*s))->t
(p->q)->(!q->!p)
(p<->q)<->(!q<->!p)
!((p*q)+(r*s))
!(p->q)*!(q->r)
(!p<->!q)*(!q<->!r)
((p+q)*(!r+s))->t
(p->q->(r->s))
(p<->q<->(r<->s))
(p*q*)*r
(p+q+)+r
p->q->r->s
p<->q<->r<->s
(*p*q)
(+p+q)
(->p->q)
(<->p<->q)


!(p*q)
!(p+q)
(p*q)+(r*s)
(!p+q)*(!q+r)
!(p*q)*!(q*r)
p q
p q r
!(p->q)*(q->r)
(p*!q)+(!p*q)


*/


