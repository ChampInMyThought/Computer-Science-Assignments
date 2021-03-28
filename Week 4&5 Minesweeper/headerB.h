
int revealSquare(int tab[][110],char board[][110],int row,int column,int length,int width,int left)
{
    if(row>0 && row<=length && column>0 && column<=width)
    {
        if (tab[row][column] == 0)
        {
            tab[row][column] = -2;
            board[row][column] = '0';
            left--;
            for(int a=-1;a<2;a++)
            {
                for(int b=-1;b<2;b++)
                {
                    if(tab[row+a][column+b] != -1 && tab[row+a][column+b] != -2) revealSquare(tab,board,row+a,column+b,length,width,left);
                }
            }
        }
        else if(tab[row][column] == -1)
        {

            for(int a=1;a<=length;a++)
            {
                for(int b=1;b<=width;b++)
                {
                    if(tab[a][b] == -1) {
                        if(a==row && b==column) printf("B ");
                        else printf("* ");
                    }
                    else if(tab[a][b] == -2) printf("0 ");
                    else{
                    printf("%d ",tab[a][b]);
                    }
                }
                printf("\n");
            }
            printf("-- DEFEAT --");
            return 0;
        }
        else
        {
            board[row][column]=tab[row][column]+'0';
            left--;
        }
        return 1;
    }
}
