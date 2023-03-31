#include <stdio.h>

int number = 10;
int data[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void Quick_Sort(int* data, int start, int end) {
	if (start >= end) //원소가 1개인 경우 
		return;

	int key = start; // 키는 부분 집합의 첫번째 원소 
	int i = start + 1; //왼쪽 출발 지점
	int j = end; //오른쪽 출발 지점
	int temp; //임시 변수

	while (i <= j) { // 엇갈릴 때까지 반복
		while (data[i] < data[key]) { //키 값보다 큰 값으 ㄹ만날 때까지 오른쪽으로 이동
			i++;
		}
		while (data[j] >= data[key] && j>start) { //키 값보다 작은 값을 만날 때까지 오른쪽으로 이동
			j--;
		}
		if (i > j) { //현재 엇갈린 상태면 키 값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else { // 엇갈리지 않았을 때 
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	Quick_Sort(data, start, j - 1);
	Quick_Sort(data, j + 1, end);
}

int main(void) {
	Quick_Sort(data, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d", data[i]);
	}
}