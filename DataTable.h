#ifndef TASK2A_DATATABLE_H
#define TASK2A_DATATABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


#define maxchar 63
#define maxrows 1000  // max num of rows

typedef struct DataTable_t{

    float label1;
    float label2;
    float label3;

    char label4[maxchar];
    char label5[maxchar];
    char label6[maxchar];

    char* columnNames[6];
    int rowcount;
    struct DataTable_t * next;

}info[maxrows];

typedef info *ptr;

/* function prototypes */


/* operation:        returns a pointer to an initialized DataTable_t structure                                  */
/* preconditions:    p points to an initialized DataTable_t structure                                           */
/* postconditions:   function returns a pointer to an initialized DataTable_t structure                         */
info * initDT(ptr *p);


/* operation:        relinquishes all resources associated with a DataTable_t structure                         */
/* preconditions:    p points to an initialized DataTable_t structure                                           */
/* postconditions:   any memory allocated for the structure is freed and the structure is set to empty          */
void deinitDT(ptr *p);

/* operation:        load the content of a csv file into an initialized DataTable_t structure                   */
/* preconditions:    p points to an initialized DataTable_t structure                                           */
/* postconditions:   the contents of a csv file named test.csv are loaded into a DataTable_t structure          */
int exportDT(ptr *p);

/* operation:        exports the content of an initialized DataTable_t structure to a csv file                  */
/* preconditions:    p points to an initialized DataTable_t structure                                           */
/* postconditions:   a csv file named DataTable_t.csv is created in the working directory with the content
 *                   of a DataTable_t structure                                                                 */
int loadDT(ptr *p);

/* operation:        prints a DataTable_t structure to screen                                                   */
/* preconditions:    p points to an initialized DataTable_t structure                                           */
/* postconditions:   the contents of a DataTable_t structure are printed in a file named DataTable_t.txt in
 *                   the working directory                                                                      */
void showDT(ptr *p);

/* operation:        returns a copy of a DataTable_t structure containing only contents from row x to row y     */
/* preconditions:    p points to an initialized DataTable_t structure                                           */
/* postconditions:   the function returns a copy of a DataTable_t structure containing only contents from
 *                   row x to row y                                                                             */
info * projectDT(ptr *p);

/* operation:        transforms each floating-point or string value of a specified DataTable_t column           */
/* preconditions:    p points to an initialized DataTable_t structure                                           */
/* postconditions:   the function pointed to by pfun is executed once for a specified DataTable_t column        */
void mutateDT(ptr * p, void (* pfun)());

#endif //TASK2A_DATATABLE_H
