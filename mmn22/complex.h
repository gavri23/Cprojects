typedef struct complex{
    double re;
    double img;
} complex;
#define TRUE 1
#define STRING_LEN 100
complex A,B,C,D,E,F;
complex read_comp(char name,double real,double imaginary,complex comp);
void print_comp(char A);
void add_comp(char A, char B);
void sub_comp(char A, char B);
void mult_comp_real(char A, double realNum);
void mult_comp_img(char A, double imgNum);
void mult_comp_comp(char A, char B);
void abs_comp(char A);
void stop();
/*helping functions*/
int isWhitespace(char letter);
double scanDouble(char input[STRING_LEN],int iterator,int* tempIterator);
void endOfInput(char input[STRING_LEN],int iterator,int* tempIterator);
int* getCommand(char input[STRING_LEN],char command[STRING_LEN],int* iterator,int indexOfCommand);
void resetString(char str[STRING_LEN]);
void skipping_spaces(char input[STRING_LEN],int* ptr_iterator,int iterator);
int check_read_comp(char input[STRING_LEN],int iterator,int* ptr,char complex,double real,double imaginary,struct complex comp);
int check_print_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1);
complex getComplex(char nameOfComplex);
int check_add_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1,char complex2);
int check_sub_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1,char complex2);
int check_mult_comp_real(char input[STRING_LEN],int iterator,int* ptr,char complex1);
int check_mult_comp_img(char input[STRING_LEN],int iterator,int* ptr,char complex1);
int check_mult_comp_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1,char complex2);
int check_abs_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1);
int check_valid_char(char letter);