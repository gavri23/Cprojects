#include <stdio.h>
#include "complex.h"
#include <stdlib.h>

int check_read_comp(char input[STRING_LEN],int iterator,int* ptr,char complex,double re,double img,struct complex comp){
    iterator = *ptr;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex = input[iterator];
    iterator++;
    *ptr = iterator;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    if(input[iterator] !=','){
        printf("no comma after the first parameter,please try again!\n");
        return -1;
    }
    iterator++;
    *ptr = iterator;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    re = scanDouble(input,iterator,ptr);
    if(*ptr==-1){
        printf("The second parameter is not a real number,please try again!\n");
        return -1;
    }
    iterator = *ptr;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    if(input[iterator] !=','){
        printf("no comma after the second parameter,please try again!\n");
        return -1;
    }
    iterator = *ptr;
    img = scanDouble(input,iterator+1,ptr);
    if(*ptr==-1) {
        printf("The third parameter is not a real number,please try again!\n");
        return -1;
    }
    iterator = *ptr;
    endOfInput(input,iterator+1,ptr);
    if(*ptr == -1){
        printf("extraneous text after end of command, please try again!\n");
        return -1;
    }
    /*Congratulation! the command is written correctly so we can call the function*/
    comp = read_comp(complex,re,img,comp);
    return 0;
}
int check_print_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1){
    iterator = *ptr;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
        complex1 = input[iterator];
        iterator++;
        *ptr = iterator;
        endOfInput(input,iterator,ptr);
    if(*ptr == -1){
        printf("extraneous text after end of command, please try again!\n");
        return -1;
    }
    /*Congratulation! the print command is valid*/
    print_comp(complex1);
    return 0;
}
int check_add_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1,char complex2){
    iterator = *ptr;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex1 = input[iterator];
    iterator++;
    *ptr = iterator;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    if(input[iterator] !=','){
        printf("no comma after the first parameter,please try again!\n");
        return -1;
    }
    iterator++;
    *ptr = iterator;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex2 = input[iterator];
    iterator = *ptr;
    endOfInput(input,iterator+1,ptr);
    if(*ptr == -1){
        printf("extraneous text after end of command, please try again!\n");
        return -1;
    }
    /*Congratulation! the command is written correctly so we can call the function*/
    add_comp(complex1,complex2);
    return 0;
}
int check_sub_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1,char complex2){
    iterator = *ptr;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex1 = input[iterator];
    iterator++;
    *ptr = iterator;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    if(input[iterator] !=','){
        printf("no comma after the first parameter,please try again!\n");
        return -1;
    }
    iterator++;
    *ptr = iterator;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex2 = input[iterator];
    iterator = *ptr;
    endOfInput(input,iterator+1,ptr);
    if(*ptr == -1){
        printf("extraneous text after end of command, please try again!\n");
        return -1;
    }
    /*Congratulation! the command is written correctly so we can call the function*/
    sub_comp(complex1,complex2);
    return 0;
}
int check_mult_comp_real(char input[STRING_LEN],int iterator,int* ptr,char complex1) {
    double num;
    iterator = *ptr;
    skipping_spaces(input, ptr, iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex1 = input[iterator];
    iterator++;
    *ptr = iterator;
    skipping_spaces(input, ptr, iterator);
    iterator = *ptr;
    if (input[iterator] != ',') {
        printf("no comma after the first parameter,please try again!\n");
        return -1;
    }
    iterator++;
    *ptr = iterator;
    skipping_spaces(input, ptr, iterator);
    iterator = *ptr;
    num = scanDouble(input, iterator, ptr);
    if (*ptr == -1) {
        printf("The second parameter is not a real number,please try again!\n");
        return -1;
    }
    iterator = *ptr;
    endOfInput(input, iterator + 1, ptr);
    if (*ptr == -1) {
        printf("extraneous text after end of command, please try again!\n");
        return -1;
    }
    /*Congratulation! the command is written correctly so we can call the function*/
    mult_comp_real(complex1, num);
    return 0;
}
int check_mult_comp_img(char input[STRING_LEN],int iterator,int* ptr,char complex1){
    double num;
    iterator = *ptr;
    skipping_spaces(input, ptr, iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex1 = input[iterator];
    iterator++;
    *ptr = iterator;
    skipping_spaces(input, ptr, iterator);
    iterator = *ptr;
    if (input[iterator] != ',') {
        printf("no comma after the first parameter,please try again!\n");
        return -1;
    }
    iterator++;
    *ptr = iterator;
    skipping_spaces(input, ptr, iterator);
    iterator = *ptr;
    num = scanDouble(input, iterator, ptr);
    if (*ptr == -1) {
        printf("The second parameter is not a real number,please try again!\n");
        return -1;
    }
    iterator = *ptr;
    endOfInput(input, iterator + 1, ptr);
    if (*ptr == -1) {
        printf("extraneous text after end of command, please try again!\n");
        return -1;
    }
    /*Congratulation! the command is written correctly so we can call the function*/
    mult_comp_img(complex1, num);
    return 0;

}
int check_mult_comp_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1,char complex2){
    iterator = *ptr;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex1 = input[iterator];
    iterator++;
    *ptr = iterator;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    if(input[iterator] !=','){
        printf("no comma after the first parameter,please try again!\n");
        return -1;
    }
    iterator++;
    *ptr = iterator;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex2 = input[iterator];
    iterator = *ptr;
    endOfInput(input,iterator+1,ptr);
    if(*ptr == -1){
        printf("extraneous text after end of command, please try again!\n");
        return -1;
    }
    /*Congratulation! the command is written correctly so we can call the function*/
    mult_comp_comp(complex1,complex2);
    return 0;
}
int check_abs_comp(char input[STRING_LEN],int iterator,int* ptr,char complex1){
    iterator = *ptr;
    skipping_spaces(input,ptr,iterator);
    iterator = *ptr;
    check_valid_char(input[iterator]);
    complex1 = input[iterator];
    iterator++;
    *ptr = iterator;
    endOfInput(input,iterator,ptr);
    if(*ptr == -1){
        printf("extraneous text after end of command, please try again!\n");
        return -1;
    }
    /*Congratulation! the command is valid*/
    abs_comp(complex1);
    return 0;
}
/*This function defines if a letter is a white space or a tab*/
int isWhitespace(char letter){
    if(letter == ' ' || letter =='\t')
        return 1;
    else
        return 0;
}
/*This function checks if a certain text is a real number or not, if the string is a number so it converts the text to a double, else it returns a default value*/
double scanDouble(char input[STRING_LEN],int iterator,int* tempIterator){
    char temp[STRING_LEN];
    resetString(temp);
    int j = 0;
    int countDots = 0;/*counting the points to handle the case of more than one consecutive dot.*/
    double number;
    /*Skips all spaces*/
    while(isWhitespace(input[iterator])){
        iterator++;
    }
    /*if the number is negative*/
    if(input[iterator] == '-'){
        temp[j] = '-';
        j++;
        iterator++;
    }
    /*making sure we only handle numbers and one/zero dots*/
    while((input[iterator] <= '9' && input[iterator] >= '0') || input[iterator] == '.'){
        if(input[iterator] == '.'){
            countDots++;
            /*Handling the case of more than one consecutive dot*/
            if(countDots <=1){
                temp[j] = input[iterator];
            }
            else{
                *tempIterator= -1;
                return 0;
            }
        }
        temp[j] = input[iterator];
        iterator++;
        j++;
    }
    /*If leaving from the loop because of one of this chars: '\0' or ',' or '\n', so it means that the text we got is a real number
     so we convert the string to a number */
    if(j > 0 && (input[iterator] == ',' || input[iterator] == '\0' || input[iterator] == '\n' || isWhitespace(input[iterator]))){
        /*Converting string to double number*/
        number = atof(temp);
    }
    else{
        *tempIterator = -1;
        return 0;
    }
    *tempIterator = iterator;
    return number;

}
/*This function checks that there is no characters after the command is finished*/
void endOfInput(char input[STRING_LEN],int iterator,int* tempIterator){
 while (isWhitespace(input[iterator]))
     iterator++;
 if(input[iterator]!='\0' && input[iterator]!='\n'){
     *tempIterator = -1;
     return;
 }
 *tempIterator = iterator;
}
/*This function copies from the string input to an empty string the name of the command itself without the parameters*/
int* getCommand(char input[STRING_LEN],char command[STRING_LEN],int* iterator,int indexOfCommand){
    /*getting the command*/
    int i;
    i = 0;
    while(input[i] != ' ' && input[i] !='\t'&& input[i] !='\0'&& input[i]!='\n'){
        command[indexOfCommand] = input[i];
        i++; indexOfCommand++;
    }
   *iterator = i;
    return iterator;
}
/*This function resets a string to a string that contains only \0 characters*/
void resetString(char str[STRING_LEN]){
    int i;
    for (i = 0; i <STRING_LEN; ++i)
        str[i]='\0';
}/*This function "skips" white spaces and tabs because it is valid to have a command with tabs and white spaces*/
void skipping_spaces(char input[STRING_LEN],int* ptr_iterator,int iterator){
    while(isWhitespace(input[iterator])){
        iterator++;
        *ptr_iterator = iterator;
    }
}/*This function receives a char, and returns the complex value.*//*
complex getComplex(char nameOfComplex){
    complex new;/*creating a default return value*//*
    switch (nameOfComplex){
        case 'A':
            return A;
        case 'B':
            return B;
        case 'C':
            return C;
        case 'D':
            return D;
        case 'E':
            return E;
        case 'F':
            return F;
        default:
            break;
    }
    return new;
}*/
/*This function checks if the name of the complex number is valid */
int check_valid_char(char letter){
    if (letter != 'A' &&
        letter != 'B' &&
        letter != 'C' &&
        letter!= 'D'  &&
        letter != 'E' &&
        letter != 'F'){
        printf("Undefined complex variable,please try again!\n");
        return -1;}
        return 0;
    }


