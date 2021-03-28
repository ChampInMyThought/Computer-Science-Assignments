

int createBoard(int tab[][110],int mine[][2],int num,int length,int width)
{
    FILE *OP;
    OP = fopen("initializedBoard.txt", "w");
    for(int i=0;i<num;i++)
    {
        int r=mine[i][0],c=mine[i][1];
        tab[r][c]=-1;
        for(int a=-1;a<2;a++)
        {
            for(int b=-1;b<2;b++)
            {
                if(tab[r+a][c+b] != -1) tab[r+a][c+b]++;
            }
        }
    }
    for(int a=1;a<=length;a++)
    {
        for(int b=1;b<=width;b++)
        {
            if(tab[a][b] == -1) fprintf(OP, "* ");
            else{
                fprintf(OP, "%d ",tab[a][b]);
            }
        }
        fprintf(OP, "\n");
    }
    fclose(OP);
}
