
#include <stdio.h>
#include <math.h>
#include "complex.h"
#include <stdlib.h>

complex read_comp(char name,double real,double imaginary,complex comp) {
    switch (name) {
        case 'A':
            A.re = real;
            A.img = imaginary;
            comp = A;
            break;
        case 'B':
            B.re = real;
            B.img = imaginary;
            comp = B;
            break;
        case 'C':
            C.re = real;
            C.img = imaginary;
            comp = C;
            break;
        case 'D':
            D.re= real;
            D.img = imaginary;
            comp = D;
            break;
        case 'E':
            E.re = real;
            E.img = imaginary;
            comp = E;
            break;
        case 'F':
            F.re = real;
            F.img = imaginary;
            comp = F;
            break;
        default:
            return comp;
    }
    return comp;
}
void print_comp(char comp_name){
    complex comp = getComplex(comp_name);
    printf("The complex number is: %.2f + (%.2fi)\n",comp.re,comp.img);
}
void add_comp(char A, char B){
    complex comp1 = getComplex(A);
    complex comp2 = getComplex(B);
    double cRe;
    double cImg;
    cRe = comp1.re + comp2.re;
    cImg = comp1.img + comp2.img;
    printf("The sum of the two complex numbers %c = %f + %fi and %c = %f + %fi is:",A,comp1.re,comp1.img,B,comp2.re,comp2.img);
    printf("%.2f + (%.2fi)\n",cRe,cImg);
}
void sub_comp(char A, char B){
    complex comp1 = getComplex(A);
    complex comp2 = getComplex(B);
    double cRe;
    double cImg;
    cRe = comp1.re - comp2.re;
    cImg = comp1.img - comp2.img;
    printf("The subtraction of the two complex numbers %c = %f + %fi and %c = %f + %fi is:",A,comp1.re,comp1.img,B,comp2.re,comp2.img);
    printf("%.2f + (%.2fi)\n",cRe,cImg);
}
void mult_comp_real(char A, double realNum){
    complex comp1 = getComplex(A);
    double cRe;
    double cImg;
    cRe = realNum*comp1.re ;
    cImg = realNum*comp1.img;
    printf("The multiplication of the complex number %c = %f + %fi and the real number %f is:",A,comp1.re,comp1.img,realNum);
    printf("%.2f + (%.2fi)\n",cRe,cImg);
}
void mult_comp_img(char A, double imgNum){
    complex comp1 = getComplex(A);
    double cRe;
    double cImg;
    cRe = imgNum*comp1.img*(-1);
    cImg = imgNum*comp1.re;
    printf("The multiplication of the complex number %c = %f + %fi and the imaginary number %f is:",A,comp1.re,comp1.img,imgNum);
    printf("%.2f + (%.2fi)\n",cRe,cImg);
}
void mult_comp_comp(char A, char B){
    complex comp1 = getComplex(A);
    complex comp2 = getComplex(B);
    double cRe;
    double cImg;
    cRe = (comp1.re*comp2.re) - (comp1.img*comp2.img);
    cImg = (comp1.re*comp2.img) + (comp1.img*comp2.re);
    printf("The multiplication of the two complex numbers %c = %f + %fi and %c = %f + %fi is:",A,comp1.re,comp1.img,B,comp2.re,comp2.img);
    printf("%.2f + (%.2fi)\n",cRe,cImg);
}
void abs_comp(char A){
    complex comp = getComplex(A);
    double r;
    r = sqrt(pow(comp.re,2) + pow(comp.img,2));/*the abs value of a complex number*/
    printf("The absolute value of the complex number %c = %f + %fi is:",A,comp.re,comp.img);
    printf("%.2f\n",r);
}
void stop(){
    exit(0);
}
complex getComplex(char nameOfComplex){
    complex new;/*creating a default return value*/
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
}
