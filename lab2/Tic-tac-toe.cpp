#include <iostream>
#define a ' '

char matrix[3][3] = { {a, a, a},{a, a, a},{a, a, a}}; // Матрица для игрового поля

void computer_move(void); // Ход компьютера
void player_move(void); // Ход игрока
void game_board(void); // Игровое поле
char сheck_for_victory(void); // Проверка на победу
int main()
{
	setlocale(LC_ALL, "ru");
	char done;
	printf("Игра в крестики-нолики против компьютера.\n");
	done = a;
	do {
		game_board(); // Вывод игрового поля
		player_move(); // Ход игрока
		done = сheck_for_victory(); // Проверка на победу
		if (done != a) break; 
		computer_move(); // Ход компьютера
		done = сheck_for_victory(); // Проверка на победу
	} while (done == a);
	game_board();
	if (done == 'X') printf("Вы выйграли.\n");
	else printf("Выйграл комьютер.\n");
	return 0;
}
/* Ход игрока */
void player_move(void)
{
	int x, y;
	printf("\nВведите координаты X.\n");
	printf("Номер строки: ");
	scanf("%d", &x);
	printf("Номер столбца: ");
	scanf("%d", &y);
	x--; y--;
	if (x < 0 || y < 0 || x>2 || y>2 || matrix[x][y] != a)
	{
		printf("\nБыли введины не вверные координаты. Повторите ввод координат.\n");
		player_move();
	}
	else matrix[x][y] = 'X';
}
/* Ход компьютера */
void computer_move(void)
{
	register int t;
	char* p;
	p = (char*)matrix;
	for (t = 0; *p != a && t < 9; ++t) p++;
	if (t == 9)
	{
		printf("draw\n");
		exit(0); 
	}
	else *p = 'O';
}
/* Игровое поле */
void game_board(void)
{
	int t;
	printf("\n");
	for (t = 0; t < 3; t++)
	{
		printf(" %c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);
		if (t != 2) printf("\n---|---|---\n");
	}
	printf("\n");
}
/* Проверка на победу */
char сheck_for_victory(void)
{
	system("cls"); // Очистка консоли
	int t;
	char* p;
	for (t = 0; t < 3; t++) { // Проверка строк 
		p = &matrix[t][0];
		if (*p == *(p + 1) && *(p + 1) == *(p + 2)) return *p;
	}
	for (t = 0; t < 3; t++) { // Проверка столбцов 
		p = &matrix[0][t];
		if (*p == *(p + 3) && *(p + 3) == *(p + 6)) return *p;
	}
	// Проверка диагоналей 
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		return matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		return matrix[0][2];
	return a;
}