#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 3


//动态规划，拿最大牌问题


//暴力递归
// 
//int f(int arr[3], int L, int R);
//int g(int arr[3], int L, int R);
//int fun1(int arr[3], int L, int R);
//
//int g(int arr[3], int L, int R)
//{//后手获得最好分数
//	if (L == R)
//		return 0;
//	int p1 = f(arr, L+1, R);
//	int p2 = f(arr, L, R-1);
//	return p1 > p2 ? p2 : p1;
//}
//
//int f(int arr[3],int L,int R)
//{//先手拿牌获得最好分数
//	if (L == R)
//	{
//		return arr[R];
//	}
//	int p1 = arr[L] + g(arr, L+1, R);
//	int p2 = arr[R] + g(arr, L, R-1);
//	return p1 > p2 ? p1 : p2;
//}
//
//int fun1(int arr[3], int L,int R)
//{
//	int first = f(arr, L, R);
//	int Last = g(arr, L, R);
//	return first > Last ? first : Last;
//}
//
//
//int main()
//{
//	int L = 0;
//	int R = 2;
//	int arr[3] = { 1,2,3 };
//	cout<<fun1(arr,L,R);
//}

//---------------------------------------------------------------------------------

//缓存法

//int f(int arr[3], int L, int R, int**& farr, int**& garr);
//int g(int arr[3], int L, int R,int**& farr, int**& garr);
//
//int g(int arr[3], int L, int R, int**& farr, int**& garr)
//{//后手获得最好分数
//	if (garr[L][R] != -1)
//	{
//		return garr[L][R];
//	}
//	int num = 0;
//	if (L == R)
//		return 0;
//	else {
//		int p1 = f(arr, L + 1, R, farr, garr);
//		int p2 = f(arr, L, R - 1, farr, garr);
//		num = p1 > p2 ? p2 : p1;
//	}
//	garr[L][R] = num;
//	return num;
//}
//
//int f(int arr[3],int L,int R, int**& farr, int**& garr)
//{//先手拿牌获得最好分数
//	if (farr[L][R] != -1)
//	{
//		return farr[L][R];
//	}
//	int num = 0;
//	if (L == R)
//		num = arr[R];
//	else {
//		int p1 = arr[L] + g(arr, L + 1, R, farr, garr);
//		int p2 = arr[R] + g(arr, L, R - 1, farr, garr);
//		num = p1 > p2 ? p1 : p2;
//	}
//	farr[L][R] = num;
//	return num;
//}
//
//int fun2(int arr[3], int L,int R,int**& farr, int**& garr)
//{
//	int first = f(arr, L, R,farr,garr);
//	int Last = g(arr, L, R,farr,garr);
//	return first > Last ? first : Last;
//}
//
//
//int main()
//{
//	int L = 0, R = 2;
//	int arr[MAXSIZE] = { 1,2,3 };
//	int** farr = (int**)malloc(sizeof(int*) * MAXSIZE);
//	int** garr = (int**)malloc(sizeof(int*) * MAXSIZE);
//	for (int i = 0; i <= MAXSIZE; i++)
//	{
//		farr[i] = (int*)malloc(MAXSIZE * sizeof(int));
//		garr[i] = (int*)malloc(MAXSIZE * sizeof(int));
//	}
//	for (int i = 0; i <= MAXSIZE; i++)
//	{
//		for (int j = 0; j <= MAXSIZE; j++)
//		{
//			farr[i][j] = -1;
//			garr[i][j] = -1;
//		}
//	}
//
//	cout << fun2(arr,L,R,farr,garr);
//
//}

//动态规划法 
//------------------------------------------------------------------------------------------

int main()
{
	int L = 0, R = 2;
	int arr[MAXSIZE] = { 1,2,3 };
	int** farr = (int**)malloc(sizeof(int*) * MAXSIZE);
	int** garr = (int**)malloc(sizeof(int*) * MAXSIZE);
	for (int i = 0; i <= MAXSIZE; i++)
	{
		farr[i] = (int*)malloc(MAXSIZE * sizeof(int));
		garr[i] = (int*)malloc(MAXSIZE * sizeof(int));
	}
	for (int i = 0; i < MAXSIZE; i++)
	{//初始化图标
		farr[i][i] = arr[i];
		garr[i][i] = 0;
	}
	//      f									g
	//  0  1  2  R                         0  1  2  R
    //0 1								   0 0
	//1 x  2							   1 x  0
	//2 x  x  3						       2 x  x  0
	//L								       L 
	for (int col = 1; col < MAXSIZE; col++)
	{
		for (int l = 0, r = col; r < MAXSIZE; l++, r++)
		{//f
			int p1 = arr[l] + garr[l + 1][r];
			int p2 = arr[r] + garr[l][r - 1];
			farr[l][r] = p1 > p2 ? p1 : p2;
		//g
			p1 =farr[l + 1][r];
			p2 =farr[l][r - 1];
			garr[l][r] = p1 > p2 ? p2 : p1;
		}
	}
	int num = farr[L][R] > garr[L][R] ? farr[L][R] : garr[L][R];
	cout << num;
}