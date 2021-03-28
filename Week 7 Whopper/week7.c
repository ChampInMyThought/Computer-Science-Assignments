#include <stdio.h>
#include <string.h>


struct ingredient
{
    char name[100];
    float price;
    int cal,num;
};

int compare(){
    char want[4];
    scanf("%s",want);
    if(strcmp(want,"Yes") == 0) return 1;
    else return 0;
}

float calculatedPrice(struct ingredient A[])
{
    float Price = 0;
    for(int i=0;i<11;i++){
        Price += A[i].num*A[i].price;
    }
    return Price;
}

int calculatedCalories(struct ingredient A[])
{
    int Calories = 0;
    for(int i=0;i<11;i++){
        Calories += A[i].num*A[i].cal;
    }
    return Calories;
}

int main()
{
    struct ingredient A[100];
    char dummy[100];
    int count = 0;

    FILE *OP;
    OP = fopen("ingredientList.txt","r");
    while( fscanf(OP, "%[^\n]", A[count].name) != EOF)
    {
        fscanf(OP,"%f",&A[count].price);
        fscanf(OP,"%d",&A[count].cal);
        fgets(dummy, 100, OP);
        count++;
    }
    /*
        DEBUG
        printf("%d\n",count);
        for(int i=0;i<10;i++){
            printf("%s = %.2f %d\n",A[i].name, A[i].price, A[i].cal);
        }
        printf("\n");
    */
    
    fclose(OP);

    printf("How many flamed-grilled beef patties?: "); scanf("%d",&A[0].num);
    A[1].num = 1;
    printf("Mayonnaise?: "); A[2].num = compare();   
    printf("Lettuce?: "); A[3].num = compare();
    printf("Tomato?: "); A[4].num = compare();
    printf("Pickles?: "); A[5].num = compare();
    printf("Ketchup?: "); A[6].num = compare();
    printf("Slicedonion?: "); A[7].num = compare();
    printf("How many American cheese slices?: "); scanf("%d",&A[8].num);
    printf("How many bacon strips?: "); scanf("%d",&A[9].num);
    printf("Mustard?: "); A[10].num = compare();

    float sum_price = calculatedPrice(A);
    int sum_cal = calculatedCalories(A);
    printf("Price = %.2f THB\n",sum_price);
    printf("Calories = %d kcal",sum_cal);

    return 0;
}

/*
    INPUT
    Howmanyflamed-grilledbeefpatties?:3
    Mayonnaise?:Yes
    Lettuce?:Yes
    Tomato?:Yes
    Pickles?:Yes
    Ketchup?:No
    Slicedonion?:Yes
    HowmanyAmericancheeseslices?:4
    Howmanybaconstrips?:6
    Mustard?:Yes

    flame-grilled beef patty
    90.00
    410
    sesame-seed bun
    40.00
    160
    mayonnaise
    0.00
    20
    lettuce
    0.00
    10
    tomato
    0.00
    10
    pickles
    0.00
    20
    ketchup
    0.00
    20
    sliced onion
    0.00
    10
    American cheese slice
    40.00
    150
    bacon strip
    30.00
    60
    mustard
    0.00
    10
*/
