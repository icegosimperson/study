#include <stdio.h>

int number = 10;
int data[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void Quick_Sort(int* data, int start, int end) {
	if (start >= end) //���Ұ� 1���� ��� 
		return;

	int key = start; // Ű�� �κ� ������ ù��° ���� 
	int i = start + 1; //���� ��� ����
	int j = end; //������ ��� ����
	int temp; //�ӽ� ����

	while (i <= j) { // ������ ������ �ݺ�
		while (data[i] < data[key]) { //Ű ������ ū ���� ������ ������ ���������� �̵�
			i++;
		}
		while (data[j] >= data[key] && j>start) { //Ű ������ ���� ���� ���� ������ ���������� �̵�
			j--;
		}
		if (i > j) { //���� ������ ���¸� Ű ���� ��ü
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else { // �������� �ʾ��� �� 
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