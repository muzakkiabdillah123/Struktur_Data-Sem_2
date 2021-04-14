void DelFirst(element** node) {
    if(*node != NULL) {
        element* del = *node;
        *node = del->next;
        del->next = NULL;
        free(del);
    } else {
        printf("Tidak ada data !");
    }        
}