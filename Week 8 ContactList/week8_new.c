#include <stdio.h>
#include <string.h>

struct contact{
    char name[20];
    char tel[20];
};

// DEBUG
void read_contact(){
    struct contact debug;

    int count = 0;
    FILE *FP;
    FP = fopen("contactbi.bin","rb");
    while (fread(&debug, sizeof(debug), 1, FP) != 0) {
        printf("%s %s\n", debug.name, debug.tel);
        count += 1;
    }
    fclose(FP);
}

void addContact(){
    struct contact input;

    printf("Enter name: "); scanf("%s",input.name);
    printf("Enter phone number : "); scanf("%s",input.tel);

    FILE *FP;
    FP = fopen("contactbi.bin","ab");
    fwrite(&input, sizeof(input), 1, FP);
    fclose(FP);
}

void findContact(int n){
    char search_for[20];
    int count = 0;
    struct contact searcher, find[n];
    printf("Enter name or phone number : ");
    scanf("%s", search_for);

    FILE *FP;
    FP = fopen("contactbi.bin","rb");
    while(fread(&searcher, sizeof(searcher), 1, FP) != 0)
    {
        if (!strcmp(search_for, searcher.tel)){
            strcpy(find[count].name, searcher.name);
            strcpy(find[count].tel, searcher.tel);
            count += 1;
        }
        if (!strcmp(search_for, searcher.name)){
            strcpy(find[count].name, searcher.name);
            strcpy(find[count].tel, searcher.tel);
            count += 1;
        }
    }
    fclose(FP);

    printf("Found %d contacts\n", count);
    for (int i = 0; i < count; i++){
        printf("%s %s\n", find[i].name, find[i].tel);
    }
}

int main() {
    int opp, num = 0;
    while(1) {
        printf("1. Add new contact 2. Search contact 3. Exit \nWhat do you want to do : ");
        scanf("%d",&opp);
        if (opp == 1){
            addContact();
            num++;
        }
        else if (opp == 2){
            findContact(num);
        }
        else if(opp == 4){
            read_contact();
        }
        else if (opp == 3){
            break;
        }
    }
    return 0;
}
