#include <stdio.h>
#include "header.h"
#include <stdlib.h>
int main(int argc, char *argv[] ) {
    struct myfile file1,file2,file3;
    file1.fileName = "input";
    file2.fileName = "output";
    file3.file = stderr;
    file3.fileName = "Errors";
    switch (argc)
    {
        case 1:/*zero arguments files*/
            file1.file = stdin;
            file2.file = stdout;
            standartInput(file1,file2,file3);
            break;
        case 2:/*one argument file */
            file1.fileName = argv[1];
            inputFile(file1,file2,file3);
            break;
        case 3:/*two arguments files*/
            file1.fileName = argv[1];
            file2.fileName = argv[2];
            IOFiles(file1,file2,file3);
            break;
        default:/*more than two names of file - return an error */
            fopen(file3.fileName,"w");
            fprintf(file3.file,"too many arguments, goodbye!");
            fclose(file3.file);
            break;
    }
    return 0;
}
void standartInput(struct myfile file1,struct myfile file2,struct myfile file3){
    char *strNum;
    char* ptr;
    long num;
    fopen(file1.fileName,"r");
    fopen(file2.fileName,"w");
    while(fscanf(file1.file,"%s",strNum)!=EOF){
            int secondDigit;
            int firstDigit;
           num =  strtol(strNum,&ptr,10);
           if(num<10){/*the number is between 0-9 */
               getOnesDigits((int)num,file2.file,num);
               continue;
           }
           firstDigit = (int)num%10;
           secondDigit = (int)num/10;
           getTensDigits(secondDigit,firstDigit,file2.file,num);
           if(firstDigit != 0 && secondDigit != 1)/*the number is not 10,20,30 exc... or the number is not between 11-19*/
           {
               getOnesDigits(firstDigit,file2.file,num);
           }
    }
    fclose(file1.file);
    fclose(file2.file);

}
void inputFile(struct myfile file1,struct myfile file2,struct myfile file3){
    char *strNum;
    char* ptr;
    long num;
    if(!(file1.file = fopen(file1.fileName,"r"))
    ){
        fprintf(file3.file,"The file could not be open, goodbye!\n");
        fclose(file3.file);
        exit(0);
    }
    printf("trb00");
    fopen(file2.fileName,"w");

    while(fscanf(file1.file,"%s",strNum)!=EOF){

        int secondDigit;
        int firstDigit;
        num =  strtol(strNum,&ptr,10);
        if(num<10){/*the number is between 0-9 */
            getOnesDigits((int)num,file2.file,num);
            continue;
        }
        firstDigit = (int)num%10;
        secondDigit = (int)num/10;
        getTensDigits(secondDigit,firstDigit,file2.file,num);
        if(firstDigit != 0 && secondDigit != 1)/*the number is not 10,20,30 exc... or the number is not between 11-19*/
        {
            getOnesDigits(firstDigit,file2.file,num);
        }
    }
    fclose(file1.file);
    fclose(file2.file);
}

void IOFiles(struct myfile file1,struct myfile file2,struct myfile file3){
    char *strNum;
    char* ptr;
    long num;
    if(!(file1.file = fopen(file1.fileName,"r"))
            ){
        fprintf(file3.file,"The file could not be open, goodbye!\n");
        exit(0);
    }

    fopen(file2.fileName,"w");
    if(!(file2.file = fopen(file2.fileName,"r"))
            ){
        fprintf(file3.file,"The file could not be open, goodbye!\n");
        exit(0);
    }
    while(fscanf(file1.file,"%s",strNum)!=EOF){
        int secondDigit;
        int firstDigit;
        num =  strtol(strNum,&ptr,10);
        if(num<10){/*the number is between 0-9 */
            getOnesDigits((int)num,file2.file,num);
            continue;
        }
        firstDigit = (int)num%10;
        secondDigit = (int)num/10;
        getTensDigits(secondDigit,firstDigit,file2.file,num);
        if(firstDigit != 0 && secondDigit != 1)/*the number is not 10,20,30 exc... or the number is not between 11-19*/
        {
            getOnesDigits(firstDigit,file2.file,num);
        }
    }
    fclose(file1.file);
    fclose(file2.file);
}
void getOnesDigits(int firstDigit, FILE* output, long num){
    switch (firstDigit)
    {
        case 0:
            if(num<10)
                fprintf(output,"zero\n");/* a condition if the number has two digits so will not print zero*/
            break;
        case 1:
            fprintf(output,"one\n");
            break;
        case 2:
            fprintf(output,"two\n");
            break;
        case 3:
            fprintf(output,"three\n");
            break;
        case 4:
            fprintf(output,"four\n");
            break;
        case 5:
            fprintf(output,"five\n");
            break;
        case 6:
            fprintf(output,"six\n");
            break;
        case 7:
            fprintf(output,"seven\n");
            break;
        case 8:
            fprintf(output,"eight\n");
            break;
        case 9:
            fprintf(output,"nine\n");
            break;
        default:
            break;
    }
}
void getTensDigits(int secondDigit,int firstDigit, FILE* output,long num){

    switch (secondDigit)
    {
        case 1:
            getTeens(firstDigit,output);/*special function for numbers 10-19 */
            break;
        case 2:
            fprintf(output,"twenty ");/**/
            getOnesDigits(firstDigit,output+sizeof(int),num);
            break;
        case 3:
            fprintf(output,"thirty ");
            getOnesDigits(firstDigit,output+sizeof(int),num);
            break;
        case 4:
            fprintf(output,"forty ");
            getOnesDigits(firstDigit,output+sizeof(int),num);
            break;
        case 5:
            fprintf(output,"fifty ");
            getOnesDigits(firstDigit,output+sizeof(int),num);
            break;
        case 6:
            fprintf(output,"sixty ");
            getOnesDigits(firstDigit,output+sizeof(int),num);
            break;
        case 7:
            fprintf(output,"seventy ");
            getOnesDigits(firstDigit,output+sizeof(int),num);
            break;
        case 8:
            fprintf(output,"eighty ");
            getOnesDigits(firstDigit,output+sizeof(int),num);
            break;
        case 9:
            fprintf(output,"ninety ");
            getOnesDigits(firstDigit,output+sizeof(int),num);
            break;
        default:
            break;
    }
}
void getTeens(int digit,FILE* output){
    switch (digit)
    {
        case 0:
            fprintf(output,"ten\n");
            break;
        case 1:
            fprintf(output,"eleven\n");
            break;
        case 2:
            fprintf(output,"twelve\n");
            break;
        case 3:
            fprintf(output,"thirteen\n");
            break;
        case 4:
            fprintf(output,"fourteen\n");
            break;
        case 5:
            fprintf(output,"fifteen\n");
            break;
        case 6:
            fprintf(output,"sixteen\n");
            break;
        case 7:
            fprintf(output,"seventeen\n");
            break;
        case 8:
            fprintf(output,"eighteen\n");
            break;
        case 9:
            fprintf(output,"nineteen\n");
            break;
        default:
            break;
    }
}
