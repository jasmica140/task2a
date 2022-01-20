#include "DataTable.h"

int initPerson(info *p, float l1, float l2, float l3, char l4[maxchar], char l5[maxchar], char l6[maxchar])
{
    if (p == NULL)
        return -1;

    p[maxrows]->label1 = l1;
    p[maxrows]->label2 = l2;
    p[maxrows]->label3 = l3;
    memmove(&p[maxrows]->label4, l4, strlen(l4)+1);
    memmove(&p[maxrows]->label4, l5, strlen(l5)+1);
    memmove(&p[maxrows]->label4, l5, strlen(l5)+1);

    return 0;
}

int main(){

      info info[] = {

            {0.100000,0.200000,0.300000,"aaa","bbb","ccc"},
            {1.100000,1.200000,1.300000,"aaa","bbb","ccc"},
            {2.100000,2.200000,2.300000,"aaa","bbb","ccc"},
            {3.100000,3.200000,3.300000,"aaa","bbb","ccc"},
            {4.100000,4.200000,4.300000,"aaa","bbb","ccc"},
            {5.100000,5.200000,5.300000,"aaa","bbb","ccc"},
            {6.100000,6.200000,6.300000,"aaa","bbb","ccc"},
            {7.100000,7.200000,7.300000,"aaa","bbb","ccc"},
            {8.100000,8.200000,8.300000,"aaa","bbb","ccc"},
            {9.100000,9.200000,9.300000,"aaa","bbb","ccc"},
            {10.100000,10.200000,10.300000,"aaa","bbb","ccc"},
            {11.100000,11.200000,11.300000,"aaa","bbb","ccc"},
            {12.100000,12.200000,12.300000,"aaa","bbb","ccc"},
            {13.100000,13.200000,13.300000,"aaa","bbb","ccc"},
            {14.100000,14.200000,14.300000,"aaa","bbb","ccc"},
            {15.100000,15.200000,15.300000,"aaa","bbb","ccc"},
            {16.100000,16.200001,16.299999,"aaa","bbb","ccc"},
            {17.100000,17.200001,17.299999,"aaa","bbb","ccc"},
            {18.100000,18.200001,18.299999,"aaa","bbb","ccc"},
            {19.100000,19.200001,19.299999,"aaa","bbb","ccc"},
            {20.100000,20.200001,20.299999,"aaa","bbb","ccc"}

    };


    initDT((ptr *) &info[21]);
    deinitDT((ptr *) &info[21]);
    exportDT((ptr *) &info[21]);
    loadDT((ptr *) &info[21]);
    showDT((ptr *) &info[21]);
    projectDT((ptr *) &info[21]);
    mutateDT((ptr *) &info[21], projectDT((ptr *) &info[21]));

}
