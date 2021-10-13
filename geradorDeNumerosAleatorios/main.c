#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

//declaracao de funcoes
void gerador();

//variaveis globais
char keyboard[BUFSIZ];


int main()
{
    setlocale(LC_ALL, "");

    int inicio, numIntervalo, numQuant;
    char i = 'C';

    printf("\t\t\tGerador de números aleatórios!\n\n");


    while(toupper(i) != 'S')
    {
        printf("Defina qual o primeiro número, onde deve iniciar o sorteio: \n");
        scanf("%d", &inicio);
        printf("Digite até qual número deve ser sorteado: \n");
        scanf("%d", &numIntervalo);
        printf("Digite quantos números devem ser sorteados\n");
        scanf("%d", &numQuant);

        if(inicio >= 1)
        {
            gerador(inicio, numIntervalo, numQuant);
        }else
        {
            printf("\nValor inicial inválido.\nDeve ser um valor maior que 0, não pode ser %d\n\n", inicio);
        }
        printf("Desejar Continuar sorteando?\n Digite qualquer tecla para continuar ou S para sair: \n");
        scanf("%c", &i);
        setbuf(stdin,keyboard);//limpa buffer do teclado

    }

    return 0;
}

void gerador(int ini, int intervalo, int quant)
{
    int i = 0, j, igual, contA, contB, aux;
    int vetNum[quant];
    char limpaTela = 'C';

    intervalo++;
    srand(time(NULL));

    //preenchendo o vetor
    if(quant < intervalo)
    {
        do
        {
            vetNum[i] = rand() % intervalo;
            igual = 0;
            if((vetNum[i] != 0) && (vetNum[i] >= ini))
            {
                for(j = 0; j < i; j++)
                {
                if(vetNum[j] == vetNum[i])
                    igual = 1;
                }
                if(igual == 0)
                    i++;

            }
        }
        while(i < quant);

        //ordenando números sorteados
        for(contA = 0; contA < quant ; contA++)
        {
            for(contB = contA + 1; contB < quant ; contB++)
            {
                if(vetNum[contA] > vetNum[contB])
                {
                    aux = vetNum[contB];
                    vetNum[contB] = vetNum[contA];
                    vetNum[contA] = aux;
                }
            }
        }

        //Escrevendo os numeros sorteados
        printf("\n%d números sorteados no intervalo de %d a %d: \n", quant,ini, intervalo - 1);

        for(i = 0; i < quant; i++)
        {
            printf("%d ", vetNum[i] );
        }

        //Limpa tela
        printf("\n\nDeseja limpar a Tela?\n S- Sim\n N- Não \n");
        setbuf(stdin, keyboard);//limpa buffer do teclado
        scanf("%c", &limpaTela);
        setbuf(stdin, keyboard);//limpa buffer do teclado

        switch(toupper(limpaTela))
        {
            case 'S':
                system("clear");
                break;
            default:
                break;
        }
    }else
    {
        printf("\nQuantidade digitada maior que o intervalo\n\n");
    }
}
