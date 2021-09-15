//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//
//int map[9][9] = {
//    {2,2,2,2,2,2,2,2,2},
//    {2,0,0,0,0,0,0,0,2},
//    {2,0,2,2,0,2,2,0,2},
//    {2,0,2,0,0,2,0,0,2},
//    {2,0,2,0,2,0,2,0,2},
//    {2,0,0,0,0,0,2,0,2},
//    {2,2,0,2,2,0,2,2,2},
//    {2,0,0,0,0,0,0,0,2},
//    {2,2,2,2,2,2,2,2,2}
//};
//
//int facing = 0;
//const COORD end = { 7,7 };
//COORD back = { 1,1 };
//COORD player = { 1,1 };
//
//void gotoxy(int x, int y) {
//    COORD pos = { x * 2,y };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//int main_ㄹ() {
//    printf("딜레이를 입력해주세요 (밀리초) : ");
//    int speed;
//    scanf("%d", &speed);
//    system("cls");
//    gotoxy(0, 0);
//    for (int i = 0; i < 9; i++) {
//        for (int j = 0; j < 9; j++)
//            printf("%s", map[i][j] ? "■" : "□");
//        putchar(10);
//    }
//    gotoxy(player.X, player.Y);
//    printf("★");
//    while (end.X != player.X || end.Y != player.Y) {
//        Sleep(speed);
//        facing += 3;
//        facing %= 4;
//        while (player.X == back.X && player.Y == back.Y) {
//            switch (facing) {
//                case 0:
//                    if (map[player.Y - 1][player.X]) {
//                        facing++;
//                    }
//                    else {
//                        player.Y--;
//                    }
//                    break;
//                case 1:
//                    if (map[player.Y][player.X + 1]) {
//                        facing++;
//                    }
//                    else {
//                        player.X++;
//                    }
//                    break;
//                case 2:
//                    if (map[player.Y + 1][player.X]) {
//                        facing++;
//                    }
//                    else {
//                        player.Y++;
//                    }
//                    break;
//                case 3:
//                    if (map[player.Y][player.X - 1]) {
//                        facing = 0;
//                    }
//                    else {
//                        player.X--;
//                    }
//                    break;
//            }
//        }
//        gotoxy(player.X, player.Y);
//        printf("★");
//        gotoxy(back.X, back.Y);
//        printf("□");
//        gotoxy(0, 10);
//        printf("goal : %d %d\n", end.X, end.Y);
//        printf("player : %d %d\n", player.X, player.Y);
//        printf("last pos : %d %d\n", back.X, back.Y);
//        printf("facing : %s", facing == 0 ? "up   " : facing == 1 ? "right" : facing == 2 ? "down " : "left ");
//        back.X = player.X;
//        back.Y = player.Y;
//    }
//}
