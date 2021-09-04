#include <stdio.h>
#include <locale.h>
#include "core/main.c"

int main () {
    setlocale(LC_ALL, "portuguese-brazilian");

    getDataAndOrder();
    showMenu(selectedOptionMenu);
   
    return 0;
}
