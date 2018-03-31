#include <stdio.h>
#include <string.h>

int main() {
    char palavra1[30];
    char palavra2[30];
    char palavra3[30];

    scanf("%s %s %s", palavra1, palavra2, palavra3);

    if (!strcmp(palavra1, "vertebrado")) {
        //printf("vertebrado ");

        if (!strcmp(palavra2, "ave")) {
            //printf("ave ");

            if (!strcmp(palavra3, "carnivoro")) {
                //printf("carnivoro\n ");
                printf("aguia\n");
            }

            else {
                //printf("onivoro\n");
                printf("pomba\n");
            }
        }

        else {
            //printf("mamifero ");

            if (!strcmp(palavra3, "onivoro")) {
                //printf("onivoro\n ");
                printf("homem\n");
            }

            else {
                //printf("herbivoro\n");
                printf("vaca\n");
            }
        }
    }

    else {
        //printf("um igual a um");

        if (!strcmp(palavra2, "inseto")) {
            //printf("inseto ");

            if (!strcmp(palavra3, "hematofago")) {
                //printf("carnivoro\n ");
                printf("pulga\n");
            }

            else {
                //printf("herbivoro\n");
                printf("lagarta\n");
            }
        }

        else {
            //printf("anelidio ");

            if (!strcmp(palavra3, "hematofago")) {
                //printf("hematofago\n ");
                printf("sanguessuga\n");
            }

            else {
                //printf("onivoro\n");
                printf("minhoca\n");
            }
        }
    }

    return 0;
}
