#pragma once


#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int solve(char arr[], int left, int right);  //�ж�ϵͳ
int filterBracket(char* arr, int& size);//���ˣ���
void pri(char arr[], int left, int right);  //��ӡ����
int myfind(char arr[], int left, int right, int& sig);  //���ҵ�һ�����Ӵ�λ��,sig���Ӵ�λ���±�
char getT(); //�����ȡ����Ԫ
void randAtext(char* arr, int seed); //���������������
void randBtext(char* formula);  //�����������
void generateSpecified(char* ops, int size, int num, char* formula);  //ָ�������������
void generateErrorSubject(char* fars); //ָ�����ɴ�������

