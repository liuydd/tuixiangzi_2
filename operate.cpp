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
            case 0://�յ�
                cout<<("  "); 
                break;
            case 1://ǽ��
                cout<<("��"); 
                break;
            case 3://Ŀ�ĵ�
                cout<<("��"); 
                break;
            case 4://����
                cout<<("��"); 
                break;
            case 5://��
                cout<<("��"); 
                break;
            case 7://���ӵ���Ŀ�ĵ�
                cout<<("��"); 
                break;
            case 8://�˵���Ŀ�ĵ�
                cout<<("��"); 
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
        if (map[r - 1][c] == 0 || map[r - 1][c] == 3)//�˵�ǰ���ǿյػ�Ŀ�ĵ� 
        {
            map[r - 1][c] += 5; //����+5
            map[r][c] -= 5;//����-5 
            step++;
        }
        else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)//��ǰ�������ӻ����Ӽ�Ŀ�ĵ�
        {
            if (map[r - 2][c] == 0 || map[r - 2][c] == 3)//��ǰ���ǰ���ǿյػ�Ŀ�ĵ� 
            {
                map[r - 2][c] += 4;
                map[r - 1][c] += 1;
                map[r][c] -= 5;
                step++;
            }
        }

        break;
    case 's':
        if (map[r + 1][c] == 0 || map[r + 1][c] == 3)//�˵ĺ����ǿյػ�Ŀ�ĵ� 
        {
            map[r + 1][c] += 5; //����+5
            map[r][c] -= 5;//����-5 
            step++;
        }
        else if (map[r + 1][c] == 4 || map[r + 1][c] == 7)//�˺��������ӻ����Ӽ�Ŀ�ĵ�
        {
            if (map[r + 2][c] == 0 || map[r + 2][c] == 3)//�˺����ǰ���ǿյػ�Ŀ�ĵ� 
            {
                map[r + 2][c] += 4;
                map[r + 1][c] += 1;
                map[r][c] -= 5;
                step++;
            }
        }
        break;
    case 'a':
        if (map[r][c - 1] == 0 || map[r][c - 1] == 3)//�˵������ǿյػ�Ŀ�ĵ� 
        {
            map[r][c - 1] += 5; //����+5
            map[r][c] -= 5;//����-5 
            step++;
        }
        else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)//�����������ӻ����Ӽ�Ŀ�ĵ�
        {
            if (map[r][c - 2] == 0 || map[r][c - 2] == 3)//������������ǿյػ�Ŀ�ĵ� 
            {
                map[r][c - 2] += 4;
                map[r][c - 1] += 1;
                map[r][c] -= 5;
                step++;
            }
        }
        break;

    case 'd':
        if (map[r][c + 1] == 0 || map[r][c + 1] == 3)//�˵������ǿյػ�Ŀ�ĵ� 
        {
            map[r][c + 1] += 5; //����+5
            map[r][c] -= 5;//����-5 
            step++;
        }
        else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)//�����������ӻ����Ӽ�Ŀ�ĵ�
        {
            if (map[r][c + 2] == 0 || map[r][c + 2] == 3)//������������ǿյػ�Ŀ�ĵ� 
            {
                map[r][c + 2] += 4;
                map[r][c + 1] += 1;
                map[r][c] -= 5;
                step++;
            }
        }
        break;
    case 'r':
               //�����е����⣬�˳�Ӧ����ָ�˳���ǰ���棬�����˳���Ϸ
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
    cout << "�˵��±�:" << r << " " << c;
    cout << endl;
}
