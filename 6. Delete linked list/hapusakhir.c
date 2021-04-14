/*
butuh hapus dan prev (seperti del tengah)
hapus berhenti ketika next->alamat = NULL
PREV->NEXTALAMAT = NULL
free(hapus)
*/

void delAkhir (element * list)
{
    element *hapus;
    element *prev;
    hapus = list;
    prev = list;
    while(hapus->nextAlamat!=NULL) {
        prev = hapus;
        hapus = hapus->nextAlamat;
    }
    prev->nextAlamat = NULL;
    free(hapus);
}