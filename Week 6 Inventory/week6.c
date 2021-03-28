#include <stdio.h>
#include <string.h>

struct item
{
    long long barcode;
    char name[100];
    float price;
    int num_left;
};

int main()
{
    int num=0;
    struct item A[10010];
    char dummy[500];
    FILE *inv;
    inv = fopen("inventory.txt","r");
    while ( fscanf(inv," %lld",&A[num].barcode) != EOF)
    {
        //fscanf(inv," %s",&A[num].name);
        fgets(dummy, 500, inv);
        fgets(A[num].name, 500, inv);
        fscanf(inv," %f",&A[num].price);
        fscanf(inv," %d",&A[num].num_left);

        //printf("%d ; %lld %s %.2f %d\n",num,A[num].barcode,A[num].name,A[num].price,A[num].num_left);
        num++;
    }
    fclose(inv);

    int count=0;
    float all;
    long long input;
    scanf(" %lld",&input);
    do
    {
        int count = 0;
        while(A[count].barcode != input && count < num){
            count++;
        }
        A[count].num_left--;
        for(int i=0;i<strlen(A[count].name)-1;i++){
            printf("%c",A[count].name[i]);
        }
        all += A[count].price;
        printf(" = %.2f THB\n",A[count].price);
        scanf(" %lld",&input);
    } while (input != 0000000000000);
    printf("Total = %.2f THB",all);

    FILE *UP;
    UP = fopen("inventory.txt","w");
    for(int i=0;i<num;i++)
    {
        fprintf(UP, "%lld\n",A[i].barcode);
        fprintf(UP, "%s%.2f\n",A[i].name,A[count].price);
        fprintf(UP, "%d\n\n",A[i].num_left);
    }
    fclose(UP);
}

/*
8851932295796
Walls Ice Cream Magnum Classic
40.00
10

8851932295789
Walls Ice Cream Magnum Almond
40.00
20

8851932406574
Walls Ice Cream Paddle Pop Topten Double
20.00
25

8851932115919
Walls Cornetto Royal Chocolove
25.00
17

8850329183616
Meiji Pasteurized Milk Strawberry
46.50
3

4547691712905O
kamoto Condom 003 
Size 52 mm 2 pcs
69.00
9999

8851932295796
8850329183616
8851932295789
8851932406574
8851932295789
8851932115919
0000000000000
*/
