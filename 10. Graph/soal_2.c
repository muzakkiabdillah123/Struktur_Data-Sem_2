#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct simpul { //beda
    struct edge * jalur;
    struct simpul * next;
    char id_simpul;
};

struct edge {
    struct edge * next_jalur;
    struct simpul * tujuan;
    int cost;
};

struct graph {
    struct simpul * first; //beda
};

void create_graph (struct graph*g)
{
    g->first = NULL;
}

struct simpul * create_simpul (struct graph*g, char a)  //beda
{
    struct simpul * simpul_baru = (struct simpul*) malloc (sizeof(struct simpul));
    simpul_baru->id_simpul = a;
    simpul_baru->jalur = NULL;
    simpul_baru->next = NULL;
    if (g->first == NULL) {
        g->first = simpul_baru;
    } else {
        struct simpul * akhir = g->first;
        while (akhir->next != NULL) {
            akhir = akhir->next;
        }
        akhir->next = simpul_baru;
    }
}

void add_edge (struct simpul * awal, struct simpul * akhir, int nilai_jalur)
{
    struct edge * new_edge = (struct edge *) malloc(sizeof(struct edge));
    new_edge->cost = nilai_jalur;
    new_edge->next_jalur = NULL;
    new_edge->tujuan = akhir;

    if (awal->jalur==NULL) 
    {
        awal->jalur = new_edge;
    } 
    else {
        struct edge * jalur_akhir = awal->jalur;
        while (jalur_akhir->next_jalur != NULL) {
            jalur_akhir = jalur_akhir->next_jalur;
        }
        jalur_akhir->next_jalur=new_edge;
    }
}

void cetak_graph (struct graph * g)
{
    struct simpul * temp_simpul = g->first;
    if (temp_simpul != NULL)    //beda
    {
        while (temp_simpul != NULL)
        {
            printf ("Simpul %c\n", &temp_simpul->id_simpul);
            struct edge * temp_edge = temp_simpul->jalur;
            while (temp_edge->next_jalur != NULL)   //beda
            {
                printf("Terhubung dengan simpul %c, dengan cost %d", &temp_edge->tujuan, &temp_edge->cost);
                temp_edge = temp_edge->next_jalur;
            }
            temp_simpul = temp_simpul->next;
        }
    }
    else {
        printf("Graph Kosong\n");
    }
}

int main()
{
    struct simpul * gr = NULL;
    gr = create_simpul(&gr,"A");
}