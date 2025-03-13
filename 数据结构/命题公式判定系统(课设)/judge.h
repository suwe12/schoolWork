#pragma once


#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int solve(char arr[], int left, int right);  //判定系统
int filterBracket(char* arr, int& size);//过滤（）
void pri(char arr[], int left, int right);  //打印函数
int myfind(char arr[], int left, int right, int& sig);  //查找第一个连接词位置,sig连接词位置下标
char getT(); //随机获取单变元
void randAtext(char* arr, int seed); //辅助生成随机命题
void randBtext(char* formula);  //生成随机命题
void generateSpecified(char* ops, int size, int num, char* formula);  //指定生成随机命题
void generateErrorSubject(char* fars); //指定生成错误命题

