#include "DataTable.h"


info * initDT(ptr *p){

    *p = NULL;
    info * pt;      /* set to start of list   */

    pt = (info*) malloc(sizeof(info));
    return pt;
}


void deinitDT(ptr *p){

    while (*p != NULL) {

        free(*p);           /* free current node         */
        p++;        /* advance to next node      */
    }
}

int exportDT(ptr *p){

    info * pexp = *p;       /* set to start of list   */

    FILE* f;

    f = fopen("test.csv", "w");

    if (f == NULL) {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }

    fprintf(f,"label1,label2,label3,label4,label5,label6\n");

    while(pexp != NULL){

        fprintf(f,"%f,%f,%f,%s,%s,%s\n", pexp[maxrows]->label1, pexp[maxrows]->label2, pexp[maxrows]->label3, pexp[maxrows]->label4, pexp[maxrows]->label5, pexp[maxrows]->label6);
        pexp++;     /* advance to next item   */
    }

    fclose(f);
    return 0;
}


int loadDT(ptr *p) {

    info * pload = *p;   /* set to start of list   */

    FILE *fp;

    fp = fopen("DataTable_t.csv", "r");

    if (fp == NULL) {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }

    while (fscanf(fp,"%f,%f,%f,%[^,],%[^,],%[^\n]", &pload[maxrows]->label1, &pload[maxrows]->label2, &pload[maxrows]->label3, pload[maxrows]->label4, pload[maxrows]->label5, pload[maxrows]->label6) == 6) {
        pload++;        /* advance to next item   */
    }

    fclose(fp);

    return 0;
}

void showDT(ptr *p){

    info * pshow = *p;    /* set to start of list   */

    int i;
    int count =0;

    while(pshow != NULL){
        pshow++;
        count++;
    }

    FILE *file = fopen("DataTable_t.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file!\n"); // error
        exit(1);
    }

    fprintf(file,"  label1      label2      label3      label4      label5      label6\n");
    for (i = 0; i < count-1; i++)
    {
        fprintf(file,"%10f  %10f  %10f  %10.10s  %10.10s  %10.10s\n",pshow[maxrows]->label1, pshow[maxrows]->label2, pshow[maxrows]->label3, pshow[maxrows]->label4, pshow[maxrows]->label5, pshow[maxrows]->label6);
        pshow++;
    }

    fprintf(file,"  \n  .\n  .\n  .\n\n%10f  %10f  %10f  %10.10s  %10.10s  %10.10s\n", pshow[maxrows]->label1 , pshow[maxrows]->label2, pshow[maxrows]->label3 , pshow[maxrows]->label4, pshow[maxrows]->label5, pshow[maxrows]->label6);

    fclose(file);
}

info * projectDT(ptr *p){

    struct DataTable_t *data = malloc(sizeof(struct DataTable_t) * maxrows);

    info * pproj1 = *p;   /* set to start of list   */

    int i = 0;
    int x = 5;
    int y = 13;

    while(pproj1 != NULL){

        if(i>=x && i<=y){

            data[i].label1 = pproj1[maxrows]->label1;
            data[i].label2 = pproj1[maxrows]->label2;
            data[i].label3 = pproj1[maxrows]->label3;
            strcpy(data[i].label4, pproj1[maxrows]->label4 );
            strcpy(data[i].label5, pproj1[maxrows]->label5 );
            strcpy(data[i].label6, pproj1[maxrows]->label6 );
        }

        pproj1++;       /* advance to next item in info   */
        i++;        /* advance to next item in data  */
    }

    return data;
}


void mutateDT(ptr * p, void (* pfun)()){

    info * pmut = *p;    /* set to start of list   */

    while (pmut != NULL){

        (*pfun)(pmut[maxrows]->label1);
        (*pfun)(pmut[maxrows]->label2);
        (*pfun)(pmut[maxrows]->label3);
        (*pfun)(pmut[maxrows]->label4);
        (*pfun)(pmut[maxrows]->label5);
        (*pfun)(pmut[maxrows]->label6);
        pmut++;  /* advance to next item   */
    }
}

