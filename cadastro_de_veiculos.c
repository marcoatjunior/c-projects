#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
    Programa de cadastro de ve�culos com vetores, estrutura e passagem por refer�ncia.
*/

typedef struct s_vehicle{
    char licensePlate[8];
    char mark[20];
    char model[20];
    int  year;
    int  gas;
}s_vehicle;

int createVehicle(s_vehicle vehicles[], int aux){
    if(aux < 50){
        fflush(stdin);
        printf(" Digite a placa: ");
        gets(vehicles[aux].licensePlate);

        printf(" Digite a marca: ");
        gets(vehicles[aux].mark);

        printf(" Digite o modelo: ");
        gets(vehicles[aux].model);

        printf(" Digite o ano: ");
        scanf("%d", &vehicles[aux].year);

        printf(" Digite a capacidade de combust�vel: ");
        scanf("%d", &vehicles[aux].gas);

        aux++;
    }
    showMenu();
    return aux;
}

void searchVehicleByLicensePlate(s_vehicle vehicles[], int aux){
    char vehiclePlate[20];
    int  contVehicles, hasVehicle = 0;

    if(aux > 0){
        fflush(stdin);
        printf(" Digite a placa do ve�culo cadastrado: ");
        gets(vehiclePlate);

        for(contVehicles = 0; contVehicles < aux; contVehicles++){
            if(strcmp(vehiclePlate, vehicles[contVehicles].licensePlate) == 0){
                print_vehicle(vehicles, contVehicles);
                hasVehicle++;
                break;
            }
        }
        if(hasVehicle == 0){
            printf(" N�o existem ve�culos cadastrados com a placa informada. \n");
        }
    } else {
        printf(" N�o existem ve�culos a serem pesquisados. \n");
    }
    showMenu();
}

void listVehicle(s_vehicle vehicles[], int aux){
    int contVehicles;
    if(aux > 0){
        for(contVehicles = 0; contVehicles < aux; contVehicles++){
            print_vehicle(vehicles, contVehicles);
        }
    } else {
        printf(" N�o h� ve�culos cadastrados. \n");
    }
    showMenu();
}

void consultGas(s_vehicle vehicles[], int aux, float *gasMedium){
    char vehicleMark[20];
    int  contVehicles, hasVehicle = 0, element = 0, gas = 0;

    if(aux > 0){
        fflush(stdin);
        printf(" Digite a marca do ve�culo cadastrado: ");
        gets(vehicleMark);

        for(contVehicles = 0; contVehicles < aux; contVehicles++){
            if(strcmp(vehicleMark, vehicles[contVehicles].mark) == 0){
                for(contVehicles = contVehicles; contVehicles < aux; contVehicles++){
                    gas = vehicles[contVehicles].gas + gas;
                    element++;
                }
                hasVehicle++;
                break;
            }
        }

        *gasMedium = gas / element;
        printf(" Capacidade m�dia de combust�vel: %.2f litros", *gasMedium);

        if(hasVehicle == 0){
            printf(" N�o existem ve�culos cadastrados com a placa informada. \n");
        }
    } else {
        printf(" N�o h� ve�culos cadastrados. \n");
    }
    showMenu();
}

void print_vehicle(s_vehicle vehicles[], int contVehicles){
    printf(" Placa      : %s \n"  , vehicles[contVehicles].licensePlate);
    printf(" Marca      : %s \n"  , vehicles[contVehicles].mark);
    printf(" Modelo     : %s \n"  , vehicles[contVehicles].model);
    printf(" Ano        : %d \n"  , vehicles[contVehicles].year);
    printf(" Combust�vel: %d \n\n", vehicles[contVehicles].gas);
}

void showMenu(){
    printf("\n");
    system("pause");
    system("cls");
    fflush(stdin);
    menuApplication();
}

void menuApplication(){
    printf("\n _________ Cadastro de Ve�culos _________ \n");
    printf("| \t1 - Cadastrar Ve�culos \t         |\n");
    printf("| \t2 - Buscar Ve�culos \t         |\n");
    printf("| \t3 - Listar Ve�culos \t         |\n");
    printf("| \t4 - Consultar Combust�vel M�dio  |\n");
    printf("| \t5 - Sair da Aplica��o \t         |\n");
    printf("------------------------------------------");
    printf("\n\n");
}

int main(int argc, char * argv[]){
    int getAux = 0, option = 0, i, cont = 0;
    float gasMedium = 0;
    struct s_vehicle vehicles[50];

    setlocale(LC_ALL,"");
    menuApplication();

    if(argc > 1){
        for(i = 1; i < argc; i){
            strcpy(vehicles[cont].licensePlate, argv[i]);
            i++;
            strcpy(vehicles[cont].mark, argv[i]);
            i++;
            strcpy(vehicles[cont].model, argv[i]);
            i++;
            vehicles[cont].year = atoi(argv[i]);
            i++;
            vehicles[cont].gas = atoi(argv[i]);
            i++;
            cont++;
            if(cont == 50){
                break;
            }
        }
        getAux = cont;
    }

    do{
        printf(" Escolha uma das op��es acima: ");
        scanf("%d", &option);

        system("cls");
        menuApplication();

        switch(option){
            case 1:
                getAux = createVehicle(vehicles, getAux);
            break;

            case 2:
                searchVehicleByLicensePlate(vehicles, getAux);
            break;

            case 3:
                listVehicle(vehicles, getAux);
            break;

            case 4:
                consultGas(vehicles, getAux, &gasMedium);
            break;

            case 5:
                exit(EXIT_SUCCESS);
            break;

            default:
                printf("Digite um valor v�lido! \n");
                showMenu();
        }
    } while(option);
}
