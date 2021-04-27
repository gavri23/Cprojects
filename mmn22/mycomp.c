#include <stdio.h>
#include "complex.h"
#include <string.h>
#include <stdlib.h>


/*The way we approach this task is to scan the the input from the user and then we check each letter with an iterator index that we increment
  him and a pointer that points to him because we sending the iterator to different functions and to make sure we get the most updated iterator we use that pointer
  the object complex is made from two real numbers, the first real number represents a number from the realm of the real numbers (R),
  the second real number represents a number from the imaginary realm (C).  */

void main()
{
    /*declaration of variables we will use for the task*/
    complex comp;
    char input[STRING_LEN];
    char command[STRING_LEN];
    int iterator;/*the index we use to check if the input is correct or incorrect*/
    int indexOfCommand;/*the index of the command in order to copy the name of the command*/
    double re;/*represents the real part of the complex number*/
    double img;/*represents the imaginary part of the complex number*/
    char complex1;/*name of the first complex variable*/
    char complex2;/*name of the second complex variable*/
    int* ptr;/*the iterator pointer*/
    ptr = &iterator;

    /*making all the 6 complex numbers of the program to be zero*/
    comp.re = 0;
    comp.img = 0;
    comp = A = B = C = D = E = F;

    /*starting the program, in order to terminate the infinite loop we need to enter "stop"*/
    while(TRUE){
    /*resetting the iterators to zero and the strings to empty values*/
    iterator = indexOfCommand = 0;
    resetString(input);
    resetString(command);

    /*starting the program*/
    printf("Hello user! please enter a command\n");
    printf("if you want to stop the program please enter stop\n");
    fgets(input,STRING_LEN,stdin);/*scanning the input from the user*/
    skipping_spaces(input,ptr,iterator);/*Skipping the whitespaces at the start*/
    getCommand(input,command,ptr,indexOfCommand);/*getting the command*/

    /*Handling empty input*/
    if(*command == EOF){
        printf("You must enter stop in order to stop the program");
    }
        if(iterator == 0){
            printf("No command have been entered, please try again!\n");
            continue;/*Entering the next command*/
        }
    /*the user entered a non-empty command so we need to check if its a correct command*/
    if(strcmp(command,"read_comp") == 0) {
        check_read_comp(input,iterator,ptr,complex1,re,img,comp);/*helper function to check the rest of the command*/
    }
    else if(strcmp(command,"print_comp") == 0){
        check_print_comp(input,iterator,ptr,complex1);/*helper function to check the rest of the command*/
    }
    else if(strcmp(command,"add_comp") == 0){
        check_add_comp(input, iterator, ptr, complex1, complex2);/*helper function to check the rest of the command*/
    }
    else if(strcmp(command,"sub_comp") == 0){
        check_sub_comp(input,iterator,ptr,complex1,complex2);/*helper function to check the rest of the command*/
    }
    else if(strcmp(command,"mult_comp_real") == 0){
        check_mult_comp_real(input, iterator, ptr,complex1);/*helper function to check the rest of the command*/
    }
    else if(strcmp(command,"mult_comp_img") == 0){
        check_mult_comp_img(input, iterator, ptr,complex1);/*helper function to check the rest of the command*/
    }
    else if(strcmp(command,"mult_comp_comp") == 0){
        check_mult_comp_comp(input, iterator, ptr,complex1,complex2);/*helper function to check the rest of the command*/
    }
    else if(strcmp(command,"abs_comp") == 0){
        check_abs_comp(input, iterator, ptr,complex1);/*helper function to check the rest of the command*/
    }
    else if(strcmp(command,"stop") == 0){
       stop();
       exit(0);
    }
    else
        printf("The command does not exist, please try again!\n");
    }

}

