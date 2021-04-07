// Created by ChampInMyThought
// Date: 6/1/2020
// Time: 22.54

#include <stdio.h>
#include "headerA.h"
#include "headerB.h"

int main()
{
    int length,width,left,num,mine[10010][2],tab[110][110];
    char board[110][110];
    for(int i=0;i<110;i++) for(int j=0;j<110;j++) board[i][j]='*';
    scanf(" %d %d",&length,&width);
    left = length*width;
    scanf(" %d",&num);
    for(int i=0;i<num;i++)
    {
        scanf(" %d %d",&mine[i][0],&mine[i][1]);
    }
    createBoard(tab,mine,num,length,width);
    int r,c;
    int status = 0;
    while(status != -1)
    {
        int left = 0;
        for(int a=1;a<=length;a++)
        {
            for(int b=1;b<=width;b++)
            {
                if(board[a][b] == '*') left++;
            }
        }
        printf("%d\n",left);  // DEBUG

        if(left==num){
             printf("--VICTORY--");
             break;
        }
        int r,c;
        scanf(" %d %d",&r,&c);
        status = revealSquare(tab,board,r,c,length,width,left);
        if(left == -1) break;
        for(int a=1;a<=length;a++)
        {
            for(int b=1;b<=width;b++)
            {
                printf("%c ",board[a][b]);
            }
            printf("\n");
        }
    }
}

/*
6 10
12
3 4
5 2
1 8
4 9
6 1
6 2
1 10
2 8
6 7
3 5
3 6
4 6
*/
