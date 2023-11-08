#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[31];
    char posicao;
    int forca;
} Jogador;

typedef struct
{
    char nome[31];
    Jogador jogadores[11];
    double forca_ponderada;
} Time;

double calcular_forca_ponderada(Time time)
{
    double F = 0;
    int G = 0, L1 = 0, L2 = 0, Z1 = 0, Z2 = 0, V1 = 0, V2 = 0, M1 = 0, M2 = 0, A1 = 0, A2 = 0;
    for (int i = 0; i < 11; i++)
    {
        switch (time.jogadores[i].posicao)
        {
            case 'G':
                G = time.jogadores[i].forca;
                break;
            case 'L':
                if (L1 == 0)
                {
                    L1 = time.jogadores[i].forca;
                } else
                {
                    L2 = time.jogadores[i].forca;
                }
                break;
            case 'Z':
                if (Z1 == 0)
                {
                    Z1 = time.jogadores[i].forca;
                } else
                {
                    Z2 = time.jogadores[i].forca;
                }
                break;
            case 'V':
                if (V1 == 0)
                {
                    V1 = time.jogadores[i].forca;
                } else
                {
                    V2 = time.jogadores[i].forca;
                }
                break;
            case 'M':
                if (M1 == 0)
                {
                    M1 = time.jogadores[i].forca;
                } else
                {
                    M2 = time.jogadores[i].forca;
                }
                break;
            case 'A':
                if (A1 == 0)
                {
                    A1 = time.jogadores[i].forca;
                } else
                {
                    A2 = time.jogadores[i].forca;
                }
                break;
        }
    }
    F = (8.0 * G + 10.0 * (L1 + L2) + 5.0 * (Z1 + Z2) + 8.0 * (V1 + V2) + 11.0 * (M1 + M2) + 12.0 * (A1 + A2)) / 100.0;
    return F;
}

void ler_time(Time *time)
{
    scanf("%[^\n]%*c", time->nome);
    for (int i = 0; i < 11; i++)
    {
        scanf("%[^;];%c;%d%*c", time->jogadores[i].nome, &time->jogadores[i].posicao, &time->jogadores[i].forca);
    }
    time->forca_ponderada = calcular_forca_ponderada(*time);
}

void comparar_times(Time time1, Time time2)
{
    printf("%s: %.2lf de forca\n", time1.nome, time1.forca_ponderada);
    printf("%s: %.2lf de forca\n", time2.nome, time2.forca_ponderada);
    if (time1.forca_ponderada > time2.forca_ponderada)
    {
        printf("%s eh mais forte\n", time1.nome);
    } else if (time1.forca_ponderada < time2.forca_ponderada)
    {
        printf("%s eh mais forte\n", time2.nome);
    } else
    {
        printf("Os times tem a mesma forca\n");
    }
}

int main()
{
    Time time1, time2;
    ler_time(&time1);
    ler_time(&time2);
    comparar_times(time1, time2);
    return 0;
}