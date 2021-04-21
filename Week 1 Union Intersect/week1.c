//
//  .c
//  Classroom_week_1.c
//
//  Created by Theeradon Sakpetch on 14/12/2563 BE.
//

#include <stdio.h>

void findIntersection(int mem1[],int mem2[])
{
    int ans[20000]={0},cnt=0;
    for(int i=0;i<20000;i++)
    {
        if(mem1[i]>0&&mem2[i]>0)
        {
            ans[cnt]=i-10000;
            cnt++;
        }
    }
    if(cnt==0) printf("Empty");
    else{
        for(int i=0;i<cnt;i++)
        {
            printf("%d ",ans[i]);
        }
    }
}

void findUnion(int mem1[],int mem2[])
{
    int ans[20000]={0},cnt=0;
    for(int i=0;i<20000;i++)
    {
        if(mem1[i]>0||mem2[i]>0)
        {
            ans[cnt]=i-10000;
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
}


int main() {
    int len1,len2,num;
    int mem1[20010]={0},mem2[20010]={0};
    
    scanf("%d",&len1);
    for(int i=0;i<len1;i++)
    {
        scanf("%d",&num);
        mem1[num+10000]++;
    }
    scanf("%d",&len2);
    for(int i=0;i<len2;i++)
    {
        scanf("%d",&num);
        mem2[num+10000]++;
    }

    findIntersection(mem1,mem2);
    printf("\n");
    findUnion(mem1,mem2);
    
    return 0;
}

/*
 5
 -12 -3 0 11 13
 8
 -9 -3 8 11 12 14 20 23
 */
