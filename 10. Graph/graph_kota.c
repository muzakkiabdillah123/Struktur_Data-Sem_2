#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct smp *alamat_simpul;
typedef struct edg *alamat_jalur;

typedef struct smp
{
    alamat_jalur jalur;
    alamat_simpul next;
    char id_simpul[30];
} simpul;

typedef struct edg
{
    alamat_jalur next_jalur;
    simpul *tujuan;
    int cost;
} edge;

typedef struct
{
    simpul *first;
} graph;

void create_graph(graph *g)
{
    (*g).first = NULL;
}

void add_simpul(char a[30], graph *g)
{
    simpul *baru = (simpul *)malloc(sizeof(simpul));
    strcpy(baru->id_simpul, a);
    baru->jalur = NULL;
    baru->next = NULL;

    if ((*g).first == NULL)
    {
        (*g).first = baru;
    }
    else
    {
        simpul *akhir = (*g).first;
        while (akhir->next != NULL)
        {
            akhir = akhir->next;
        }
        akhir->next = baru;
    }
}

void add_edge(simpul *awal, simpul *tujuan, int nilai_jalur)
{
    edge *baru = (edge *)malloc(sizeof(edge));
    //baru->cost = 1;
    baru->cost = nilai_jalur;
    baru->next_jalur = NULL;
    baru->tujuan = tujuan;

    if (awal->jalur == NULL)
    {
        awal->jalur = baru;
    }
    else
    {
        edge *jalur_akhir = awal->jalur;
        while (jalur_akhir->next_jalur != NULL)
        {
            jalur_akhir = jalur_akhir->next_jalur;
        }
        jalur_akhir->next_jalur = baru;
    }
}

void sambung_edge(simpul *begin, simpul *end, int cost)
{
    if ((begin != NULL) && (end != NULL))
    {
        add_edge(begin, end, cost);
    }
}

simpul *findsimpul(char a[30], graph g)
{
    simpul *hasil = NULL;
    simpul *bantu = g.first;

    int ketemu = 0;
    while ((bantu != NULL) && (ketemu == 0))
    {
        if (strcmp(bantu->id_simpul, a) == 0)
        {
            hasil = bantu;
            ketemu = 1;
        }
        else
        {
            bantu = bantu->next;
        }
    }
    return hasil;
}

void cetak_graph(graph g)
{
    simpul *temp_simpul = g.first;
    if (temp_simpul != NULL)
    {
        while (temp_simpul != NULL)
        {
            printf("Kota %s\n", temp_simpul->id_simpul);
            edge *temp_edge = temp_simpul->jalur;

            while (temp_edge != NULL)
            {
                printf("Kota %s terhubung dengan Kota %s, dengan jarak %d\n", temp_simpul->id_simpul, temp_edge->tujuan->id_simpul, temp_edge->cost);
                temp_edge = temp_edge->next_jalur;
            }

            temp_simpul = temp_simpul->next;
        }
    }
    else
    {
        printf("Graph Kosong\n");
    }
}

int main()
{
    graph g;

    create_graph(&g);

    add_simpul("Jakarta", &g);
    add_simpul("Surabaya", &g);
    add_simpul("Yogyakarta", &g);
    add_simpul("Bandung", &g);
    add_simpul("Solo", &g);

    //Titik awal Jakarta
    simpul *begin = findsimpul("Jakarta", g);
    simpul *end = findsimpul("Bandung", g); //Jakarta-Bandung
    sambung_edge(begin, end, 300);

    end = findsimpul("Solo", g); //Jakarta-Solo
    sambung_edge(begin, end, 1000);

    end = findsimpul("Surabaya", g); //Jakarta-Surabaya
    sambung_edge(begin, end, 1500);

    //Titik awal Surabaya
    begin = findsimpul("Surabaya", g);
    end = findsimpul("Bandung", g); //Surabaya-Bandung
    sambung_edge(begin, end, 1200);

    end = findsimpul("Yogyakarta", g); //Surabaya-Yogyakarta
    sambung_edge(begin, end, 300);

    //Titik Awal Yogyakarta
    begin = findsimpul("Yogyakarta", g);
    end = findsimpul("Bandung", g); //Yogyakarta-Bandung
    sambung_edge(begin, end, 1000);

    //Titik Awal Bandung
    begin = findsimpul("Bandung", g);
    end = findsimpul("Jakarta", g); //Bandung-Jakarta
    sambung_edge(begin, end, 400);

    //Titik Awal Solo
    begin = findsimpul("Solo", g);
    end = findsimpul("Bandung", g); //Solo-Bandung
    sambung_edge(begin, end, 700);

    cetak_graph(g);

    return 0;
}