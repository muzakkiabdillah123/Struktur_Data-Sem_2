void hapusTengah (element *list, int idHapus)
{
    element *hapus;
    element *prev;
    hapus=List;
    prev =List;
    while(hapus->data!=idHapus) {
        prev = hapus;
        hapus = hapus->nextAlamat;
    }
    prev->next = hapus->next;
    hapus->next = NULL;
    free(hapus);
}