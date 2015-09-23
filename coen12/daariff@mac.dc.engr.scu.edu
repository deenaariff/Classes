#include<stdio.h>
    
int main (int argc, char *argv[]) {
    FILE *fp;
    int count = 0;
    if (argc < 2) {
        printf("Please enter a text file to parse");
    }
    fp = fopen (argv[1], "r");
    while(!feof(fp)) {
       if(fgetc(fp) == ' ') 
           count++;
    }
    printf("Count is: %d", count);
}
