#include <stdio.h>
#include <string.h>

int main()
{
    FILE *input,*output;
    char name[200][10]={0},elem[10]={0};
    int atomic[200]={0},num=0,now;
    input=fopen("elements.txt","r");
    output=fopen("arrangedElements","w");
    //fscanf(input,"%s",elem);
    //printf("%s",elem);
    while(fscanf(input,"%s",elem)!=EOF)
    {
        int length=strlen(elem);
        fscanf(input," %d",&now);
        for(int l=0;l<length;l++){
            name[now][l]=elem[l];
        }
        atomic[now]=1;
        num++;
    }
    printf("%d\n",num);
    
    for(int i=1;i<=200;i++)
    {
        if(atomic[i]==1){
            fprintf(output,"%s ",name[i]);
        }
    }
    
    fclose(input); fclose(output);
}

/*
int main()
{
    FILE *fp;
    fp=fopen("hello.txt","w");
    fprintf(fp,"Hello");
    fclose(fp);
    return 0;
}
*/