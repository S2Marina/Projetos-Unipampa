#include <stdio.h>
#include <stdlib.h>

float calculaCPI2Caches(float freq, int latMP, int latCD2, int latCI2, float CPI, float taxCD1, float taxCI1, float taxCD2, float taxCI2, float perDados);
float calculaCPI1Cache(float freq, int latMP, float CPI, float taxCD1, float taxCI1, float perDados);

int main() {
    float freq, CPI, final, taxCD1, taxCI1, taxCD2, taxCI2, perDados;
    int latMP, latCD2, latCI2;
    int opc;
    do {
        printf("\n==MENU==\n");
        printf("1- Calcular CPI 2 Caches: \n2- Calcular CPI 1 Cache \n3- Sair\n>>OPCAO:");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                printf("\nInforme a frequencia de operacao do processador (GHz): ");
                scanf("%f", &freq);
                printf("\nInforme a latencia para acesso a memoria principal (ns): ");
                scanf("%d", &latMP);
                printf("\nInforme a latencia para acesso a cache de dados nivel 2 (ns): ");
                scanf("%d", &latCD2);
                printf("\nInforme a latencia para acesso a cache de instrucoes nivel 2 (ns): ");
                scanf("%d", &latCI2);
                printf("\nInforme o CPI basico do processador (sem falhas): ");
                scanf("%f", &CPI);
                printf("\nInforme o percentual de falhas na cache nivel 1 de dados : ");
                scanf("%f", &taxCD1);
                printf("\nInforme o percentual de falhas na cache nivel 1 de instrucoes: ");
                scanf("%f", &taxCI1);
                printf("\nInforme o percentual de falhas na cache nivel 2 de dados : ");
                scanf("%f", &taxCD2);
                printf("\nInforme o percentual de falhas na cache nivel 2 de instrucoes : ");
                scanf("%f", &taxCI2);
                printf("\nInforme o percentual de instrucoes do tipo load/store: ");
                scanf("%f", &perDados);

                final = calculaCPI2Caches(freq,latMP,latCD2,latCI2,CPI,taxCD1,taxCI1,taxCD2,taxCI2,perDados);
                printf("\n\n<<Resultados>>");
                printf("\nFrequencia de operacao do processador (GHz): %.2f ", freq);
                printf("\nLatencia para acesso a memoria principal (ns): %d", latMP);
                printf("\nLatencia para acesso a cache de dados nivel 2 (ns): %d ", latCD2);
                printf("\nLatencia para acesso a cache de instrucoes nivel 2 (ns): %d ", latCI2);
                printf("\nCPI basico do processador (sem falhas): %.2f", CPI);
                printf("\nPercentual de falhas na cache nivel 1 de dados : %.2f", taxCD1);
                printf("\nPercentual de falhas na cache nivel 1 de instrucoes: %.2f ", taxCI1);
                printf("\nPercentual de falhas na cache nivel 2 de dados : %.2f ", taxCD2);
                printf("\nPercentual de falhas na cache nivel 2 de instrucoes : %.2f", taxCI2);
                printf("\nPercentual de instrucoes do tipo load/store: %.2f", perDados);
                printf("\n\nCPI final: %.2f \n", final);

                break;
            case 2:
                printf("\nInforme a frequencia de operacao do processador (GHz): ");
                scanf("%f", &freq);
                printf("\nInforme a latencia para acesso a memoria principal (ns): ");
                scanf("%d", &latMP);
                printf("\nInforme o CPI basico do processador (sem falhas): ");
                scanf("%f", &CPI);
                printf("\nInforme o percentual de falhas na cache nivel 1 de dados : ");
                scanf("%f", &taxCD1);
                printf("\nInforme o percentual de falhas na cache nivel 1 de instrucoes: ");
                scanf("%f", &taxCI1);
                printf("\nInforme o percentual de instrucoes do tipo load/store: ");
                scanf("%f", &perDados);

                final = calculaCPI1Cache(freq,latMP,CPI,taxCD1,taxCI1,perDados);

                printf("\n\n<<Resultados>>");
                printf("\nFrequencia de operacao do processador (GHz): %.2f ", freq);
                printf("\nLatencia para acesso a memoria principal (ns): %d", latMP);
                printf("\nCPI basico do processador (sem falhas): %.2f", CPI);
                printf("\nPercentual de falhas na cache nivel 1 de dados : %.2f", taxCD1);
                printf("\nPercentual de falhas na cache nivel 1 de instrucoes: %.2f ", taxCI1);
                printf("\nPercentual de instrucoes do tipo load/store: %.2f", perDados);
                printf("\n\nCPI final: %.2f \n", final);

               break;
            case 3:
                exit(0);
            default:
                printf("Opcao errada!\n");
                break;
        }
    }while (opc!=3);
}

float calculaCPI2Caches(float freq, int latMP, int latCD2, int latCI2, float CPI, float taxCD1, float taxCI1, float taxCD2, float taxCI2, float perDados){
    float tempciclo = 1/freq;
    float ram = latMP/tempciclo, cacheD2 = latCD2/tempciclo, cacheI2 = latCI2/tempciclo;

    float ciclosL1I = (taxCI1/100) * cacheI2; //ciclos extras para falhas lvl 1 de instrucoes
    printf("\nCiclos L1 I = %.2f\n", ciclosL1I);

    float ciclosL2I = (taxCI1/100)*(taxCI2/100) * ram; //ciclos extras para falhas lvl 2 de instrucoes
    printf("Ciclos L2 I = %.2f\n", ciclosL2I);

    float ciclosL1D = (perDados/100)*(taxCD1/100)*cacheD2; //ciclos extras para falhas lvl 1 de dados
    printf("Ciclos L1 D = %.2f\n", ciclosL1D);

    float ciclosL2D = (perDados/100)*(taxCD1/100)*(taxCD2/100)*ram; //ciclos extras para falhas lvl 2 de dados
    printf("Ciclos L2 D = %.2f\n", ciclosL2D);

    float final = CPI + ciclosL1I + ciclosL2I + ciclosL1D + ciclosL2D;
    return final;
}


float calculaCPI1Cache(float freq, int latMP, float CPI, float taxCD1, float taxCI1, float perDados){
    float tempciclo = 1/freq;
    float ram = latMP/tempciclo;

    float ciclosI = (taxCI1/100) * ram;
    printf("\nCiclos L1 I = %.2f\n", ciclosI);

    float ciclosD = (perDados/100)*(taxCD1/100)*ram;
    printf("Ciclos L1 D = %.2f\n", ciclosD);


    float final = CPI + ciclosI + ciclosD;
    return final;
}