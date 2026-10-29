#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <math.h>
typedef struct point {
	float x;
	float y;
	char name;
} Point;
void put_point(Point z) {
	printf("point %c (%.1f, %.1f)\n", z.name, z.x, z.y);
}
float dist(Point z, Point w) {
	return (float)sqrt((w.x - z.x) * (w.x - z.x) + (w.y - z.y) * (w.y - z.y));
}
void task_1() {
	printf("\n=== ЗАДАНИЕ 1: Работа с точками на плоскости ===\n");
	Point a = { 1.0f, 2.0f, 'A' };
	Point b;
	b.name = 'B';
	b.x = 5.0f;
	b.y = -3.0f;
	printf("Точка a: ");
	put_point(a);
	printf("Точка b: ");
	put_point(b);
}
void task_2() {
	printf("\n=== ЗАДАНИЕ 2: Текущее время и форматирование ===\n");
	time_t t;
	struct tm* mxtime;
	t = time(NULL);
	mxtime = localtime(&t);
	printf("Текущее время: %02d:%02d:%02d\n", mxtime->tm_hour, mxtime->tm_min, mxtime->tm_sec);
	char message[100];
	sprintf(message, "Moscow Time: %02d:%02d:%02d", mxtime->tm_hour, mxtime->tm_min, mxtime->tm_sec);
	int total_width = 80;
	int msg_len = (int)strlen(message);
	int padding = (total_width - msg_len) / 2;
	printf("\nОформление по Заданию 2.3 (в рамке):\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < total_width; j++) printf("*");
		printf("\n");
	}
	for (int i = 0; i < padding; i++) printf("*");
	printf("%s", message);
	for (int i = 0; i < (total_width - padding - msg_len); i++) printf("*");
	printf("\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < total_width; j++) printf("*");
		printf("\n");
	}
}
int main() {
	setlocale(LC_ALL, "Russian");

	int choice;

	do {
		printf("\n================ МЕНЮ ЛАБ. 18 ================\n");
		printf("1. Задание 1 (Работа с точками)\n");
		printf("2. Задание 2 (Текущее время и оформление 2.3)\n");
		printf("0. Выход\n");
		printf("Выберите номер задания: ");

		if (scanf("%d", &choice) != 1) {
			printf("Ошибка ввода! Пожалуйста, введите число.\n");
			while (getchar() != '\n');
			continue;
		}

		switch (choice) {
		case 1:
			task_1();
			break;
		case 2:
			task_2();
			break;
		case 0:
			printf("Выход из программы.\n");
			break;
		default:
			printf("Неверный выбор! Попробуйте снова.\n");
		}
	} while (choice != 0);

	return 0;
}