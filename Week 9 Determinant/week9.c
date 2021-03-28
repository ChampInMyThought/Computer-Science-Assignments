// ChampInMyThought 15/Feb/2021

#include <stdio.h>
#include <stdlib.h>

float determinant(int size,float *matrix)
{
    float ans = 0;
    float *new_matrix;
    if(size == 1) ans = matrix[0];
    else
    {
        for(int i=0;i<size;i++)
        {
            int counter = 0,power = 1;
            new_matrix = calloc((size-1)*(size-1),sizeof(float));
            for(int a=1;a<size;a++)
            {
                for(int b=0;b<size;b++)
                {
                    if(b != i){
                        new_matrix[counter++] = matrix[a*size+b];
                    }
                }
            }
            float cofac = determinant(size-1,new_matrix);
            if(i%2 == 1) power = -1;
            ans += power * matrix[i] * cofac;
            free(new_matrix);
        }
    }
    return ans;
}

int main()
{
    int n;
    float *matrix;
    scanf("%d",&n);
    matrix  = calloc(n*n,sizeof(float));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%f",&matrix[i*n+j]);
        }
    }
    printf("%.2f",determinant(n,matrix));
    free(matrix);
    return 0;
}
