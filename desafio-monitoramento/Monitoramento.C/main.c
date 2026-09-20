// Monitoramento de Temperatura - Helio Junior Vieira Caires - Profa. Karla Sartin
#include <stdio.h>

int main()
{
    float limite, t, soma = 0, maior = -50, menor = 150;
    int qtd = 0, acima = 0, seguidas = 0;

    // do...while: o limite e pedido pelo menos uma vez e depois validado
    do
    {
        printf("Limite de temperatura (-50 a 150): ");
        scanf("%f", &limite);
        if (limite < -50 || limite > 150)
            printf("Limite invalido!\n");
    } while (limite < -50 || limite > 150);

    // while: le temperaturas ate ter 3 seguidas acima do limite (ou digitar 999)
    while (seguidas < 3)
    {
        printf("Temperatura (999 encerra): ");
        scanf("%f", &t);
        if (t == 999)
            break;
        if (t < -50 || t > 150)  // invalida: nao entra nos calculos
        {
            printf("Temperatura invalida!\n");
            continue;
        }
        qtd++;
        soma += t;
        if (t > maior) maior = t;
        if (t < menor) menor = t;
        if (t > limite)  // mais uma acima do limite
        {
            acima++;
            seguidas++;
            printf("Acima do limite! (%d seguida(s))\n", seguidas);
        }
        else
            seguidas = 0;  // sequencia quebrou: zera
    }

    printf("\n=== RELATORIO FINAL ===\n");
    if (seguidas == 3)
        printf("Encerrado: 3 temperaturas consecutivas acima do limite!\n");
    if (qtd > 0)
    {
        printf("Leituras validas: %d\nMedia: %.2f\n", qtd, soma / qtd);
        printf("Maior: %.1f\nMenor: %.1f\n", maior, menor);
        printf("Acima do limite: %d (%.1f%%)\n", acima, acima * 100.0 / qtd);
    }
    else
        printf("Nenhuma leitura valida.\n");
    return 0;
}