#include<bits/stdc++.h>
#include<conio.h>
#include "menu.h"
#include "operate.h"
using namespace std;
void Operate::Print(int map[8][8]) {
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            switch (map[i][j])
            {
            case 0://空地
                cout<<("  "); 
                break;
            case 1://墙壁
                cout<<("■"); 
                break;
            case 3://目的地
                cout<<("☆"); 
                break;
            case 4://箱子
                cout<<("□"); 
                break;
            case 5://人
                cout<<("♀"); 
                break;
            case 7://箱子到达目的地
                cout<<("★"); 
                break;
            case 8://人到达目的地
                cout<<("♀"); 
                break;
            }
        }
        cout << endl;
    }
    Position(map);
    cout <<"The number of step is "<< step << endl;
}

void Operate::Move(int map[8][8],char ch) {
    //ch = _getch();
    switch (ch)
    {
    case 'w':
        if (map[r - 1][c] == 0 || map[r - 1][c] == 3)//人的前面是空地或目的地 
        {
            map[r - 1][c] += 5; //人来+5
            map[r][c] -= 5;//人走-5 
            step++;
        }
        else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)//人前面是箱子或箱子加目的地
        {
            if (map[r - 2][c] == 0 || map[r - 2][c] == 3)//人前面的前面是空地或目的地 
            {
                map[r - 2][c] += 4;
                map[r - 1][c] += 1;
                map[r][c] -= 5;
                step++;
            }
        }

        break;
    case 's':
        if (map[r + 1][c] == 0 || map[r + 1][c] == 3)//人的后面是空地或目的地 
        {
            map[r + 1][c] += 5; //人来+5
            map[r][c] -= 5;//人走-5 
            step++;
        }
        else if (map[r + 1][c] == 4 || map[r + 1][c] == 7)//人后面是箱子或箱子加目的地
        {
            if (map[r + 2][c] == 0 || map[r + 2][c] == 3)//人后面的前面是空地或目的地 
            {
                map[r + 2][c] += 4;
                map[r + 1][c] += 1;
                map[r][c] -= 5;
                step++;
            }
        }
        break;
    case 'a':
        if (map[r][c - 1] == 0 || map[r][c - 1] == 3)//人的左面是空地或目的地 
        {
            map[r][c - 1] += 5; //人来+5
            map[r][c] -= 5;//人走-5 
            step++;
        }
        else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)//人左面是箱子或箱子加目的地
        {
            if (map[r][c - 2] == 0 || map[r][c - 2] == 3)//人左面的左面是空地或目的地 
            {
                map[r][c - 2] += 4;
                map[r][c - 1] += 1;
                map[r][c] -= 5;
                step++;
            }
        }
        break;

    case 'd':
        if (map[r][c + 1] == 0 || map[r][c + 1] == 3)//人的右面是空地或目的地 
        {
            map[r][c + 1] += 5; //人来+5
            map[r][c] -= 5;//人走-5 
            step++;
        }
        else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)//人右面是箱子或箱子加目的地
        {
            if (map[r][c + 2] == 0 || map[r][c + 2] == 3)//人右面的右面是空地或目的地 
            {
                map[r][c + 2] += 4;
                map[r][c + 1] += 1;
                map[r][c] -= 5;
                step++;
            }
        }
        break;
    case 'r':
               //这里有点问题，退出应该是指退出当前界面，而非退出游戏
        Menu menu;
        menu.ShowChosemap();
        break;
    }
}

bool Operate::Judge(int map[8][8]) {
    int t = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j] == 4)
                t = 1;
        }
    }
    if (t == 1)
        return 1;
    return 0;
}
void Operate::Position(int map[8][8]) {
    int flag = 0;
    for (r = 0; r < 8; r++)
    {
        for (c = 0; c < 8; c++)
        {
            if (map[r][c] == 5 || map[r][c] == 8)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    cout << "人的下标:" << r << " " << c;
    cout << endl;
}
