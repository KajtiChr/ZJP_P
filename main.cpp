#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;


const int N = 12;
int maze_Values[N][N];
char maze_Char[N][N];
char movement;
bool check;
int player_x;
int player_y;
int maze_exit_x;
int maze_exit_y;

char Maze_set_uper(int Switcher)
{
    char result;
    switch(Switcher)
    {
    case 0:
        result = '?';
        break;
    case 1:
        result = 'x';
        break;
    case 2:
        result = 'P';
        break;
    case 3:
        result = 'E';
        break;
    case 4:
        result = ' ';
        break;
    case 5:
        result = '?';
        break;
    }
    return result;
}

void Maze_Generator_Empty_Fields(int limit, int Values[N][N])
{
    for(int i = 0; i < limit; i++)
    {
        for(int j = 0; j < limit; j++)
        {
            Values[i][j] = 0;
        }
    }
}


void Maze_Translation(int limit, int Values[N][N])
{
    for(int i = 0; i < limit; i++)
    {
        for(int j = 0; j < limit; j++)
        {
            maze_Char[i][j] = Maze_set_uper(Values[i][j]);
        }
    }
}



void Show_Maze(int limit)
{
    for(int i = 0; i < limit; i++)
    {
        for(int j = 0; j < limit; j++)
        {
            cout<< maze_Char[i][j];
            cout<< ' ';
            if(j == limit-1) cout<<endl;
        }
    }

}

void Set_Player_Exit_Position(int limit, int Values[N][N])
{
    player_x = limit/2;
    player_y = 1;
    maze_Values[player_x][player_y] = 2;
    maze_exit_x = rand()%(limit-2)+1;
    maze_exit_y = limit-2;
    maze_Values[maze_exit_x][maze_exit_y] = 5;

}


void Wall_Builder(int limit, int Values[N][N])
{
    for (int i = 0; i < limit; i++)
    {
        for(int j = 0; j < limit; j++)
        {
            if(i==0  || j ==0 || i == limit-1 || j == limit-1) Values[i][j] = 1;
        }
    }
}

void Orient(int Values[N][N], int p_x, int p_y )
{
    if(Values[p_x-1][p_y] != 1 && Values[p_x-1][p_y] != 5)
    {
        Values[p_x-1][p_y] = 4;
    }
    if(Values[p_x+1][p_y] != 1 && Values[p_x+1][p_y] != 5)
    {
        Values[p_x + 1][p_y] = 4;
    }
    if(Values[p_x][p_y - 1] != 1 && Values[p_x][p_y - 1] != 5)
    {
        Values[p_x][p_y - 1] = 4;
    }
    if(Values[p_x][p_y + 1] != 1 && Values[p_x][p_y + 1] != 5)
    {
        Values[p_x][p_y + 1] = 4;
    }
}

void Exit_view(int Values[N][N], int p_x, int p_y )
{
    if(Values[p_x - 1][p_y] == 5)
    {
        Values[p_x - 1][p_y] = 3;
    }
    if(Values[p_x + 1][p_y] == 5)
    {
        Values[p_x + 1][p_y] = 3;
    }
    if(Values[p_x][p_y - 1] == 5)
    {
        Values[p_x][p_y - 1] = 3;
    }
    if(Values[p_x][p_y + 1] == 5)
    {
        Values[p_x][p_y + 1] = 3;
    }
}

void First_Setup()
{
    srand(time(0));
    Maze_Generator_Empty_Fields(N,maze_Values);
    Wall_Builder(N, maze_Values);
    Set_Player_Exit_Position(N, maze_Values);
    Orient(maze_Values, player_x, player_y);
    Maze_Translation(N, maze_Values);
    Show_Maze(N);

}



void Movement(char where_to_move, int Values[N][N], int p_x, int p_y)
{

    if(where_to_move == 'w' && Values[p_x-1][p_y]!= 1)
    {
        Values[p_x-1][p_y] = 2;
        Values[p_x][p_y] = 0;
        player_x = p_x -1;
    }
    if(where_to_move == 'a' && Values[p_x][p_y-1]!= 1)
    {
        Values[p_x][p_y-1] = 2;
        Values[p_x][p_y] = 0;
        player_y = p_y -1;
    }
    if(where_to_move == 's' && Values[p_x+1][p_y]!= 1)
    {
        Values[p_x+1][p_y] = 2;
        Values[p_x][p_y] = 0;
        player_x = p_x + 1;
    }
    if(where_to_move == 'd' && Values[p_x][p_y+1]!= 1)
    {
        Values[p_x][p_y+1] = 2;
        Values[p_x][p_y] = 0;
        player_y = p_y +1;
    }
    else
    {

    }

}

void ChooseMovement(int Values[N][N], int px, int py)
{
        cout << "Wybierz strone w ktora chcesz sie udac, uzywajac WSADu: ";
        cin >> movement;
        Movement(movement, maze_Values, px, py);
}

bool Wynik(int x, int y)
{
    if(x == maze_exit_x && y == maze_exit_y)
        {
            cout<< "Gratuluje przeszedles labirynt.";
            cout<<endl;
        return false;
        }

    else
        return true;

}




int main()
{
    First_Setup();
    while(Wynik(player_x,player_y))
    {
        ChooseMovement(maze_Values, player_x, player_y);
        Orient(maze_Values, player_x, player_y);
        Exit_view(maze_Values, player_x, player_y);
        Maze_Translation(N, maze_Values);
        system("CLS");
        Show_Maze(N);

    }
    return 0;
}




