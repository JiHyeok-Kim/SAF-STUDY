#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int map[9][9] = {0,};
int flag = 0;
int result = 1;

void input()
{
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            cin>>map[i][j];
        }
    }
}

void ZERO()
{
    //가로
    int row0[10] = {1,0,0,0,0,0,0,0,0,0};
    int i = 0;
    for(int j = 0; j<9; j++)
    {
        row0[map[i][j]]++;
        if(row0[map[i][j]]==2)
        {
            flag = 1;
            return;
        }
    }
    
    //세로
    int col0[10]= {1,0,0,0,0,0,0,0,0,0};
    int b = 0;
    for(int a = 0; a<9; a++)
    {
        col0[map[a][b]]++;
        if(row0[map[a][b]]==2)
        {
            flag = 1;
            return;
        }
    }
    
}

void GARO(int x)
{
    int row1[10] = {1,0,0,0,0,0,0,0,0,0};
    for(int j = 0; j<9; j++)
    {
        row1[map[x][j]]++;
        if(row1[map[x][j]]==2)
        {
            flag = 1;
            return;
        }
        
    }
}

void SQUAR(int x, int y)
{
    int squar[10] = {1,0,0,0,0,0,0,0,0,0};
    for(int i = x; i<3;i++)
    {
        for(int j = y; j<3; j++)
        {
            squar[map[i][j]]++;
            if(squar[map[i][j]]==2)
            {
                flag = 1;
                break;
            }
            
        }
    }
}


void SERO(int y)
{
    int col1[10]= {1,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i<9; i++)
    {
        col1[map[i][y]]++;
        if(col1[map[i][y]]==2)
        {
            flag = 1;
            return;
        }
        
    }
}
void Find()
{
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            // 0,0
            if (i ==0 && j ==0)
            {
                ZERO();
                if (flag ==1)
                {
                    result = 0;
                    return;
                }
            }
            //ㅁ
            if((i ==0 & j==0)||(i ==0 & j==3)||(i ==0 & j==6)||(i ==3 & j==0)||(i ==3 & j==3)
               ||(i ==3 & j==6)||(i ==6 & j==0)||(i ==6 & j==3)||(i ==6 & j==6))
            {
                SQUAR(i,j);
                if (flag ==1)
                {
                    result = 0;
                    return;
                }
            }
            //가로
            else if(j == 0)
            {
                GARO(i);
                if (flag ==1)
                {
                    result = 0;
                    return;
                }
            }
            //세로
            else if(i == 0)
            {
                SERO(j);
                if (flag ==1)
                {
                    result = 0;
                    return;
                }
                
            }
            
            
        }
    }
}

int main()
{
    cin>>T;
    for(int tc = 1; tc<T+1; tc++)
    {
        input();
        flag = 0;
        result = 1;
        Find();
        
        cout<<"#"<<tc<<" "<<result<<'\n';
    
    }
    return 0;
}
