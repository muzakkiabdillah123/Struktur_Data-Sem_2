#include <stdio.h>
#include <stdlib.h>

#define max 7

typedef struct {
    int head;
    int tail;
    int data[max];
} queue;

void createQueue (queue * q)
{
    q->head=-1;
    q->tail=-1;
}

int isFull (queue * q)
{
    if (q->head==0 && q->tail==(max-1))
        return 1;
    else if ((q->head)-(q->tail)==1)
        return 1;
    else return 0;
}

int isEmpty(queue*q)
{
    if (q->head==-1 && q->tail==-1)
        return 1;
    else return 0;
}

void enQueue (queue * q, int x)
{
    if (isFull (q) == 0)
    {
        if (q->head==-1)
        {
            q->head = q->head + 1;
        }
        q->tail = (q->tail + 1) % max;
        q->data [q->tail] = x;

    } else {
        printf("Antrian penuh\n");
    }
}

void deQueue (queue*q)
{
    int dataHapus;
    if (isEmpty(q)==0)
    {
        dataHapus = q->data [q->head];
        printf("Data yang dihapus = %d\n",dataHapus);
        q->data [q->head] = q->data[(q->head)+1];
        //q->data [q->head] = NULL;

        if (q->head==q->tail)
        {
            q->head = -1;
            q->tail = -1;

        } else {
            q->head = (q->head +1) % max;
        }

    } else {
        printf("Antrian kosong\n");
    }
}

void printQ (queue*q)
{
    if (q->head!=-1 && q->tail!=-1)
    {
        int i;
        for (i=q->head;i<=q->tail;i++)
        {
            printf("Nomor antrian = %d\n",q->data[i]);
        }
    } else {
        printf("Antrian kosong\n");
    }
}

int main(){
    queue antrian;
    createQueue(&antrian);

    printf("- Antrian bioskop -\n");

    //masuk 1-7
    enQueue(&antrian,1);
    enQueue(&antrian,2);
    enQueue(&antrian,3);
    enQueue(&antrian,4);
    enQueue(&antrian,5);
    enQueue(&antrian,6);
    enQueue(&antrian,7);

    printf("\nPrint antrian bioskop : \n");
    printQ(&antrian);

    //hapus 1-3
    printf("\n");
    deQueue(&antrian);
    deQueue(&antrian);
    deQueue(&antrian);
    
    printf("\nPrint antrian bioskop : \n");
    printQ(&antrian);

    //hapus 4
    printf("\n");
    deQueue(&antrian);

    printf("\nPrint antrian bioskop : \n");
    printQ(&antrian);  

    return 0;
}