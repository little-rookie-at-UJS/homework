#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10000000
int r1[Maxsize] = { 0 };
int r2[Maxsize] = { 0 };
int r3[Maxsize] = { 0 };
// 冒泡算法统计
void BubbleSort(int r[],int n) {
	int j = 0;
	int temp = 0;
	// 比较次数
	long long count1 = 0;
	// 移动次数
	long long count2 = 0;

	int bound = 0;
	// 问题规模
	int exchange = n - 1;

	while (exchange != 0) {
		bound = exchange;
		exchange = 0;

		for (j = 0; j < bound; j++) {
			if (++count1 && r[j] > r[j + 1]) {
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				count2 = count2 + 3;
				exchange = j;
			}
		}
	}
	printf("计较次数：%lld\n", count1);
	printf("移动次数：%lld\n", count2);
}

// 快速排序
long qcount1 = 0;
long qcount2 = 0;
void quicksort(int s[], int l, int r) {
	if (l < r) {
		int i = l, j = r, x = s[l];

		while (i < j) {
			while (i < j && s[j] >= x) {
				j--;
				qcount1++;
			}
			if (i < j) {
				s[i++] = s[j];
				qcount2++;
			}
			while (i < j && s[i] < x) {
				i++;
				qcount1++;
			}
			if (i < j) {
				s[j--] = s[i];
				qcount2++;
			}
		}
		s[i] = x;
		quicksort(s, l, i - 1);
		quicksort(s, i+1, r);
	}
}


// 非递归快速排序
//void exch(int i, int j) {
//	int temp = 0;
//
//	temp = i;
//	i = j;
//	j = temp;
//}

//int Partition(int a[], int i, int r) {
//	// 左起下标
//	int i = 0;
//	// 右起下标
//	int j = r;
//	int v = a[r];
//
//	while (1) {
//		// 在a数组中查找值大于等于v的下标
//		while (a[i] < v) {
//			i++;
//		}
//		// 在a数组中查找值小于等于v的下标
//		while (a[i] >= v && j >= i) {
//			j--;
//		}
//		if (i >= j) {
//			break;
//		}
//		exch(a[i], a[j]);
//	}
//	exch(a[i], a[j]);
//	return i;
//}
//
//typedef struct StrackList {
//	int data[Maxsize];
//	int top;
//}StackNode, * SqList;
//
//
//SqList InitStack() {
//	SqList list = (SqList)malloc(sizeof(StackNode));
//	list->top = -1;
//	return list;
//}
//
//void Push(SqList list, int a) {
//	/*if (list->top == 19) {
//		return 0;
//	}*/
//
//	list->top++;
//	list->data[list->top] = a;
//}

//int Pop(SqList list) {
//	//if (list->top == -1) {
//	//	return 0;
//	//}
//
//	int b = list->data[list->top];
//	list->top--;
//	return b;
//}
//
//int StackEmpty(SqList s) {
//	if (s->top == -1) {
//		return 1;
//	}
//	return 0;
//}
//
//void quicksort2(int a[], int l, int r) {
//	int i = 0;
//	SqList list = InitStack();
//
//}

int main() {

	int number = 0;
	printf("请输入总个数：");
	scanf("%d", &number);
	// 正序
	/*while (number!=-1) {
		for (int i = 0; i < number; i++) {
			r1[i] = i;
			r2[i] = number - i;
			r3[i] = rand();
		}
		BubbleSort(r1, number);
		BubbleSort(r2, number);
		BubbleSort(r3, number);
		printf("请输入总个数：");
		scanf("%d", &number);
	}*/

	while (number != -1) {
		for (int i = 0; i < number; i++) {
			r1[i] = i;
			r2[i] = number - i;
			r3[i] = rand();
		}

//		quicksort(r1, 0, number);
//		printf("计较次数：%lld\n", qcount1);
//		printf("移动次数：%lld\n", qcount2);
		qcount1 = 0;
		qcount2 = 0;
//		quicksort(r2, 0, number);
//		printf("计较次数：%lld\n", qcount1);
//		printf("移动次数：%lld\n", qcount2);
		qcount1 = 0;
		qcount2 = 0;
		quicksort(r3, 0, number);
		printf("计较次数：%lld\n", qcount1);
		printf("移动次数：%lld\n", qcount2);
		printf("请输入总个数：");
		scanf("%d", &number);
	}
}