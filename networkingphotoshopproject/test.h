#include<stdio.h>
#include<conio.h>
#include <string.h>

int fetch(char oldt[200],char newt[200]) {
    char ch, fileName1[20], fileName2[20];
    FILE *fs, *fn;
    fs = fopen("temp.txt", "r");
    if(fs == NULL)
    {
        printf("\nError in Opening the first file, %s", fileName1);
        getch();
        return 0;
    }
    fn = fopen("./imageencoded.txt", "w");
    if(fn == NULL)
    {
        printf("\nError in Opening the second file, %s", fileName2);
        getch();
        return 0;
    }
    char c;
    char cf[200];
    int flag = 0;
    int i=0,count=0;
    while(1){
        if(feof(fs)){
            break;
        }
        c = fgetc(fs);
        if (c != '\n') {
            cf[i++] = c;
        } else {
            cf[i++] = c;
            i = 0;
            char *found_string = strstr(cf, "Content-Type: ");
            if (found_string == NULL) {
                continue;
            } else {
                flag = 1;
                break;
            }
        }
    }

    while(1){
        if(feof(fs)){
            break;
        }
        while((c=fgetc(fs) )!='\n');
        c= getc(fs);
        break;
    }
    while(1){
        if(feof(fs)){
            break;
        }
        c= fgetc(fs);
        fputc(c,fn);
    }


    fclose(fs);
    fclose(fn);
    printf("done!\n");
    return 0;
}