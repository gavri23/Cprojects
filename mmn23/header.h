struct myfile{
    FILE * file;
    char* fileName;

} ;
void standartInput(struct myfile file1,struct myfile file2,struct myfile file3);
void inputFile(struct myfile file1,struct myfile file2,struct myfile file3);
void IOFiles(struct myfile file1,struct myfile file2,struct myfile file3);
void getOnesDigits(int firstDigit,FILE *output,long num);
void getTensDigits(int secondDigit,int firstDigit,FILE* output,long num);
void getTeens(int digit,FILE* output);
