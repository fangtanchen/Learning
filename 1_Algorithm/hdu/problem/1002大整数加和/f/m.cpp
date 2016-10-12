//经过VC++6.0测试
//左上角为当前路灯的状态，绿灯10秒，黄灯3秒
//运行后务必将窗口最大化
#include <windows.h>

#include <iostream>
using namespace std;
#include <ctime>
#include <cmath>

const int L = 70;
const int W = 50;

// Declarations:
int inter=2; // a factor used in function random()
char light[30] = "LeftAndRightGreen";

void InitRoad(char road[][L], char car[][L]);
void ShowRoad(char road[][L], char car[][L]);
void Run(char car[][L], int dir[][L]);
void Newcomer(char car[][L], int dir[][L]);
void Move(int, int, int, int, char car[][L], int dir[][L]);
bool CannotPass(int, int, int, int, int dir[][L]);
void NextLight(int &bjtime);

int main()
{
 char road[W][L];
 char car[W][L];
 int dir[W][L];
 int bjtime = 1;
 InitRoad(road, car);
 for (; bjtime < 1000 ;bjtime++)
 {
  if (bjtime > 20)
   NextLight(bjtime);
  Run(car, dir);
  Sleep(500);
  ShowRoad(road, car);
 }

return 0;
}

int random()
{
 int pos,x;
 inter++;
 srand()(unsigned(time(0)));
 double seed=sqrt(double(fabs(rand()()*time(0)*inter*sqrt(1.0*inter))));
 for(;seed > 10; seed /= 10);
 pos=(rand()()+inter-1)%5 + 1;
 for(int p=0;p<pos;p++)seed*=10;
 x=int(fabs(double(int(seed+inter)%10)));
 return x;
}

void InitRoad(char road[][L], char car[][L])
{
 int i, j;
 for (i = 0; i < W; i ++)
  for(j = 0; j < L; j ++)
  {
   road[i][j] = '\0';
   car[i][j] = '\0';
  }
 for (i = 0; i < W; i ++)
 {
  if (i >= W/4 && i <= W*3/4)
   continue;
  road[i][L/4] = '|';
  road[i][L*3/4] = '|';
 }
 for (j = 0; j < L; j ++)
 {
  if (j >= L/4 && j <= L*3/4)
   continue;
  road[W/4][j] = '-';
  road[W*3/4][j] = '-';
 }

}
void ShowRoad(char road[][L], char car[][L])
{
 system("cls");
 char world[W][L];
 int i, j;
 for (i = 0; i < W; i ++)
  for (j = 0; j < L; j ++)
  {
   world[i][j] = road[i][j];
   if (car[i][j] != '\0')
    world[i][j] = car[i][j];
  }
 strcpy(world[1], light);
 for (i = 0; i < W; i ++)
 {
  for (j = 0; j < L; j ++)
  {
   cout<<world[i][j];
  }
  cout<<endl;
 }
}
void Run(char car[][L], int dir[][L])
{
 int i, j;
 for (j = 0; j < L; j ++)
 {
  for (i = 0; i < W; i ++)
  {
   if (car[i][j] == '\0')
    continue;
   if (dir[i][j] == 1)
    Move(i, j, i - 3, j, car, dir);
  }
  for (i = W-1; i >= 0; i --)
  {
   if (car[i][j] == '\0')
    continue;
   if (dir[i][j] == 2)
    Move(i, j, i + 3, j, car, dir);
  }
 }
 for (i = 0; i < W; i ++)
 {
  for (j = 0; j < L; j ++)
  {
   if (car[i][j] == '\0')
    continue;
   if (dir[i][j] == 3)
    Move(i, j, i, j-4, car, dir);
  }
  for (j = L - 1; j >= 0; j --)
  {
   if (car[i][j] == '\0')
    continue;
   if (dir[i][j] == 4)
    Move(i, j, i, j + 4, car, dir);
  }
 }
 Newcomer(car, dir);
}
char RandomName()
{
 int i = random()()*10 + random();
 i = i%26;
 i += int('A');
 return char(i);
}
void Newcomer(char car[][L], int dir[][L])
{
 int i, j;
 for (i = W/4 + 1; i < W*3/4 - 1; i ++)
 {
  if (car[i][0] == '\0')
   if (i > W/2 + 2)
    if (random()%4 == 0)
    {
     car[i][0] = RandomName();
     dir[i][0] = 4;
    }
  if (car[i][L-1] == '\0')
   if (i < W/2 - 2)
    if (random()%4 == 0)
    {
     car[i][L-1] = RandomName();
     dir[i][L-1] = 3;
    }
 }
 for (j = L/4 + 1; j < L*3/4 - 1; j ++)
 {
  if (car[0][j] == '\0')
   if (j < L/2 - 2)
    if (random()%4 == 0)
    {
     car[0][j] = RandomName();
     dir[0][j] = 2;
    }
  if (car[W-1][j] == '\0')
   if (j > L/2 + 2)
    if (random()%4 == 0)
    {
     car[W-1][j] = RandomName();
     dir[W-1][j] = 1;
    }
 }
}
void Move(int x1, int y1, int x2, int y2, char car[][L], int dir[][L])
{
 if (x2 < 0 || x2 >= W || y2 < 0 || y2 >= L);
 else if (car[x2][y2] != '\0')
  return;
 else
 {
  if (CannotPass(x1, y1, x2, y2, dir))
   return;
  car[x2][y2] = car[x1][y1];
  dir[x2][y2] = dir[x1][y1];
 }
 car[x1][y1] = '\0';
 dir[x1][y1] = 0;
}

bool CannotPass(int x1, int y1, int x2, int y2, int dir[][L])
{
 int d = dir[x1][y1];
 switch(d)
 {
 case 1:if (x1 > W*3/4 && x2 <= W*3/4 && strcmp(light, "UpAndDownGreen")!=0)return true;break;
 case 2:if (x1 < W/4 && x2 >= W/4 && strcmp(light, "UpAndDownGreen")!=0)return true;break;
 case 3:if (y1 > L*3/4 && y2 <= L*3/4&&strcmp(light, "LeftAndRightGreen")!=0)return true;break;
 case 4:if (y1 < L/4&&y2>=L/4&&strcmp(light, "LeftAndRightGreen")!=0)return true;break;
 }
 return false;
}

void NextLight(int &bjtime)
{
 if (strcmp(light, "LeftAndRightGreen") == 0)
 {
  bjtime = 13;
  strcpy(light, "LeftAndRightYellow");
 }
 else if (strcmp(light, "LeftAndRightYellow") == 0)
 {
  bjtime = 1;
  strcpy(light, "UpAndDownGreen");
 }
 else if (strcmp(light, "UpAndDownGreen") == 0)
 {
  bjtime = 12;
  strcpy(light, "UpAndDownYellow");
 }
 else if (strcmp(light, "UpAndDownYellow") == 0)
 {
  bjtime = 1;
  strcpy(light, "LeftAndRightGreen");
 }
}