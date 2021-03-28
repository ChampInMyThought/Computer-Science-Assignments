    //From SMHeeyGol, Thank you!

    #include<stdio.h>
    #include<string.h>
     
    int i,j;
     
    int main(){
     
        int nmem=0;
        FILE *fp;
        fp = fopen("contactbi.bin","w");
        fclose(fp);
        while(1){
     
            int ch;
            printf("1. Add new contact 2. Search contact 3. Exit\nWhat do you want to do : ");
            scanf("%d",&ch);
            if(ch==1){
                char x[100];
     
                fp = fopen("contactbi.bin","ab");
                printf("Enter name: ");
                scanf("%s",x);
                fwrite(x,sizeof(x),1,fp);
                printf("Enter phone number : ");
                scanf("%s",x);
                fwrite(x,sizeof(x),1,fp);
                fclose(fp);
                FILE *fo;
                fo = fopen("contactbi.bin","r");
                fread(x,sizeof(x),1,fo);
                printf("%s\n",x);
                fread(x,sizeof(x),1,fo);
                printf("%s\n",x);
                nmem++;
    //            for(i = 0 ; i < nmem*2 ; i++){
    //                fread(x,sizeof(x),1,fo);
    //            printf("%s\n",x);
    //            }
                fclose(fo);
            }
            else if(ch==2){
            int found=0,l[100];
            char x[100],r[100];
                FILE *fp;
                fp = fopen("contactbi.bin","r");
                printf("Enter name or phone number : ");
                scanf("%s",x);
                for(i = 0 ; i < 2*nmem ; i++){
                    fread(r,sizeof(r),1,fp);
                    //printf("%s vs %s = %d \n",r,x,strcmp(r,x));
                    if(!strcmp(r,x)){
                        l[found]=i;
                        found++;
                    }
                }
                fclose(fp);
     
                char n[100],nn[100];
                printf("Found %d contacts\n",found);
                for(i = 0 ; i < found ; i++){
                    fp = fopen("contactbi.bin","r");
                    for(j = 0 ; j < (l[i]/2)+1 ; j++){
                        fread(n,sizeof(n),1,fp);
                        fread(nn,sizeof(nn),1,fp);
                    }
                    printf("%s %s\n",n,nn);
                    fclose(fp);
                }
     
            }
            else{
                break;
            }
     
        }
     
    }
