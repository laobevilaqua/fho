#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int A;
    int B;
    int C;
    int D;
} JOGADA;

int main()
{
    JOGADA jogada;
    JOGADA *jogadas;
    jogadas = (JOGADA *)malloc(sizeof(JOGADA));

    char resultados[sizeof(jogadas)];
    int indexResult = 0;

    int i;
    int ultimoHomemDefensor;
    int atacanteMaisPertoDoGol;

    do
    {
        scanf("%d %d", &jogada.A, &jogada.D);
        if(jogada.A == 0 && jogada.D == 0){
            break;
           
        } 
        for (i = 0; i < jogada.A; i++) {
            scanf("%d", &jogada.B);
            if(i == 0) {
                atacanteMaisPertoDoGol = jogada.B;
            } else if (atacanteMaisPertoDoGol > jogada.B) {
                atacanteMaisPertoDoGol = jogada.B;
            }
        }

        for (i = 0; i < jogada.D; i++) {
            scanf("%d", &jogada.C);
            if(i == 0) {
                ultimoHomemDefensor = jogada.B;
            } else if (ultimoHomemDefensor > jogada.C) {
                ultimoHomemDefensor = jogada.C;
            }
        }

        if(atacanteMaisPertoDoGol < ultimoHomemDefensor) {
            resultados[indexResult] = 'Y';
        } else {
            resultados[indexResult] = 'N';
        }
        indexResult++;
    } while (1);
    
    for (i = 0; i < indexResult; i++) {
       printf("%c\n", resultados[i]);
    }

    return 0;
}