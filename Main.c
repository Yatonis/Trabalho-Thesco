#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Variaveis gerais
int i = 0 , aux = 0, i2 = 0, totalagressivo = 3,  tamanhonomeanimal, tamanhonome, tamanhotelefone ,listarespecie, incremental = 0;
int temp2, temp3 ,tempdia, tempmes, tempano;
int menu = 0, quantpessoa = 3, quantanimal = 5, petsporcliente = 0;
char temp[50], continuar[20] , nomepet[50], nomecliente[50];
//Structs
struct Data{
    int dia;
    int mes;
    int ano;
};
struct Cliente{
    char nome[50];
    char telefone[15];
};
struct Animal{
    struct Cliente dono;
    char nomeanimal[50];
    int especie;
    struct Data dataanimal;
    char agressivo[4];
    
};
struct Serviço{
    int identificador;
    struct Data dataserviço;
    struct Animal pet;
    int tipodeserviço;
    char pagamento;
};

//Declaração das structs
struct Cliente individuo[100];
struct Animal animal[100];
struct Serviço serviço[100];

//Função para declarar clientes e animais já no programa:
void clientesjaCadastrados(void){
    strcpy(individuo[0].nome , "Gabriel\0");
    strcpy(individuo[1].nome , "Luiz Carlos\0");
    strcpy(individuo[2].nome , "Ana Beatriz\0");
    strcpy(individuo[0].telefone , "01234567891\0");
    strcpy(individuo[1].telefone , "04333470986\0");
    strcpy(individuo[2].telefone , "04399223344\0");
    strcpy(animal[0].dono.nome , "Gabriel\0");
    strcpy(animal[1].dono.nome , "Luiz Carlos\0");
    strcpy(animal[2].dono.nome , "Ana Beatriz\0");
    strcpy(animal[3].dono.nome , "Gabriel\0");
    strcpy(animal[4].dono.nome , "Luiz Carlos\0");
    strcpy(animal[0].dono.telefone , "01234567891\0");
    strcpy(animal[1].dono.telefone , "04333470986\0");
    strcpy(animal[2].dono.telefone , "04399223344\0");
    strcpy(animal[3].dono.telefone , "01234567891\0");
    strcpy(animal[4].dono.telefone , "04333470986\0");
    strcpy(animal[0].nomeanimal , "Momo\0");
    strcpy(animal[1].nomeanimal , "Rocky\0");
    strcpy(animal[2].nomeanimal , "Lipe\0");
    strcpy(animal[3].nomeanimal , "Louro jose\0");
    strcpy(animal[4].nomeanimal , "Montanha\0");
    animal[0].especie = 1;
    animal[1].especie = 1;
    animal[2].especie = 4;
    animal[3].especie = 3;
    animal[4].especie = 2;
    animal[0].dataanimal.dia = 1; animal[0].dataanimal.mes =  3; animal[0].dataanimal.ano = 2011;
    animal[1].dataanimal.dia = 20; animal[1].dataanimal.mes =  5; animal[1].dataanimal.ano = 2015;
    animal[2].dataanimal.dia = 19; animal[2].dataanimal.mes =  5; animal[2].dataanimal.ano = 1999;
    animal[3].dataanimal.dia = 29; animal[3].dataanimal.mes =  2; animal[3].dataanimal.ano = 2004;
    animal[4].dataanimal.dia = 31; animal[4].dataanimal.mes =  12; animal[4].dataanimal.ano = 2006;
    strcpy(animal[0].agressivo , "N\0");
    strcpy(animal[1].agressivo , "S\0");
    strcpy(animal[2].agressivo , "S\0");
    strcpy(animal[3].agressivo , "S\0");
    strcpy(animal[4].agressivo , "N\0");
}

//Validação de nome
int validarNome (char nome[]){
    if (nome[0] >= 'a' && nome[0] <= 'z'){
        nome[0] = nome[0] - 32;
    }
    if (strlen (nome) < 4 ){
        printf("\nO nome foi digitado incorretamente. O motivo é que você digitou menos de 4 caracteres\n");
        return 0;
    }
    if(nome[0] == ' '){
        printf("\nO nome foi digitado incorretamente. O motivo é um espaço ocupando o primeiro caracter\n");
        return 0;
    }
    for (i = 0; i < 50; i++){
        if(nome[i] < 'a' && nome[i] != '\0' && nome[i] != ' ' || nome[i] > 'z' && nome[i] != '\0' && nome[i] != ' ' ){
            if(nome[i] < 'A' && nome[i] != '\0' && nome[i] != ' ' || nome[i] > 'Z' && nome[i] != '\0' && nome[i] != ' '){
                printf("\nO nome foi digitado incorretamente, sendo a provavel causa deste erro a utilização de algum caracter que não esteja no alfabeto\n");
                return 0;  
            }
        }
            
    }
    return 1;
}

// Validação do número de telefone
int validarNumero (char numero[]){
    if (numero[0] != '0'){
        printf ("\nSeu telefone foi digitado incorretamente, com seu primeiro caracter sendo diferente de um 'zero'\n");
        return 0;
    }
if (strlen (numero) < 11 || strlen (numero) > 12 ){
        printf ("\nSeu telefone foi digitado incorretamente, contendo menos que 11 ou mais que 12 caracteres\n");
    return 0;
}
for (i = 0; i < 20; i++){
    if (numero[i] < '0' && numero[i] != '\0' && numero[i] != '\n' || numero[i] > '9' && numero[i] != '\0' && numero[i] != '\n'){
        printf ("\nSeu telefone foi digitado incorretamente, contendo caracteres diferentes dos numeros árabicos, ou seja diferentes dos números de '0' a '9'\n");
        return 0;
    }
}
return 1;
}

//Validação de data
int validarData(int dia, int mes, int ano){
    if (ano > 2023 || ano > 2023 && mes == 12 && dia > 6) {
        printf("\nVocê digitou a data incorretamente. Foi digitado uma data futura\n");
        return 0;
    }
    if (ano < 1950) {
        printf("\nVocê digitou a data incorretamente. Foi digitado um ano muito velho\n");
        return 0;
    }
    if ( mes > 12 || mes < 1){
        printf("\nVocê digitou a data incorretamente. Foi digitado um mês que não existe\n");
        return 0;
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 ){
        if (dia < 1 || dia > 31){
            printf("\nVocê digitou a data incorretamente. Foi digitado um dia que não existe\n");
            return 0;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11 ){
        if (dia < 1 || dia > 30){
            printf("\nVocê digitou a data incorretamente. Foi digitado um dia que não existe\n");
            return 0;
        }
    }
    if (mes == 2){
        if (ano % 4 == 0){
            if (dia < 1 || dia > 29){
                printf("\nVocê digitou a data incorretamente. Foi digitado um dia que não existe\n");
                return 0;
            }
        }
        else {
            if (dia < 1 || dia > 28){
                printf("\nVocê digitou a data incorretamente. Foi digitado um dia que não existe\n");
                return 0;
            }
        }
    }
    return 1;
}

//Função para cadastrar clientes. 
void cadastrarCliente(struct Cliente indiviuo[100]){
    do{
        printf("\nDigite o seu nome: \n");
        setbuf(stdin,NULL);
        fgets (individuo[quantpessoa].nome, 50 , stdin);
        individuo[quantpessoa].nome[strlen(individuo[quantpessoa].nome) - 1] = '\0';
        aux = validarNome (individuo[quantpessoa].nome);
        setbuf(stdin,NULL);
        printf("\n(obs: Caso você tenha cadastrado o nome iniciando com uma letra minúscula, essa letra será automaticamente convertida para maiúsculo)\n");
    }while (aux == 0);
    do{
        printf("\nDigite o seu número de telefone: \n");
        setbuf(stdin,NULL);
        fgets (individuo[quantpessoa].telefone, 15, stdin);
        individuo[quantpessoa].telefone[strlen(individuo[quantpessoa].telefone) - 1] = '\0';
        aux = validarNumero (individuo[quantpessoa].telefone);
        setbuf(stdin,NULL);
    }while (aux == 0);
}

//Função para cadastrar animais
void cadastrarAnimal (struct Animal animal[quantanimal]){
    printf("\nDigite o nome do proprietário do animal que fez o cadastro no site: \n");
    for (i = 0; i < 100; i++){
        do{
            setbuf(stdin,NULL);
            fgets (animal[quantanimal].dono.nome, 50 , stdin);
            animal[quantanimal].dono.nome[strlen(animal[quantanimal].dono.nome) - 1] = '\0';
            setbuf(stdin,NULL);
            aux = validarNome (animal[quantanimal].dono.nome);
        }while (aux == 0);
        for (i2 = 0; i2 < 100; i2++){
            if (strcmp (animal[quantanimal].dono.nome , individuo[i2].nome) == 0){
                strcpy(animal[quantanimal].dono.nome , individuo[i2].nome);
                strcpy(animal[quantanimal].dono.telefone , individuo[i2].telefone);
                i2 = 1;
                break;
            }
        }
        if (i2 == 1){
            break;
        }
        printf ("\nVocê digitou um nome que não está cadastrado, digite novamente:\n");
    }
    printf ("\nDigite o nome do seu animal de estimação:\n");
    do{
        setbuf(stdin,NULL);
        fgets (animal[quantanimal].nomeanimal, 50 , stdin);
        animal[quantanimal].nomeanimal[strlen(animal[quantanimal].nomeanimal) - 1] = '\0';
        aux = validarNome (animal[quantanimal].nomeanimal);
        setbuf(stdin,NULL);
    }while (aux == 0);
    printf("\nQual é a espécie de seu animal de estimação?\n");
    printf("Digite: \n1 - Para cachorro \n2 - Para gato \n3 - Para pássaro \n4 - Para outros\n");
    for (;1;){
        scanf ("%d", &animal[quantanimal].especie);
        if (animal[quantanimal].especie == 1 || animal[quantanimal].especie == 2 || animal[quantanimal].especie == 3 || animal[quantanimal].especie == 4 ){
            break;
        }
        printf ("\nVocê digitou um caracter não correspondente. Digite novamente o número que corresponde a espécie de seu animal\n");
    }
    printf ("\nDigite a data em que seu animal nasceu. Digite o dia, seguido pelo mês e por último o ano.\n");
    do{
        printf ("Dia: ");
        scanf ("%d",&animal[quantanimal].dataanimal.dia);
        printf ("\nMês: ");
        scanf ("%d", &animal[quantanimal].dataanimal.mes);
        printf ("\nAno: ");
        scanf ("%d", &animal[quantanimal].dataanimal.ano);
        aux = validarData(animal[quantanimal].dataanimal.dia, animal[quantanimal].dataanimal.mes, animal[quantanimal].dataanimal.ano);
    }while(aux == 0);

    printf("\nO seu animal é agressivo?\n");
    printf("Digite:\n S - Para Sim\n N - Para Não\n");
    for (;1;){
        setbuf(stdin , NULL);
        fgets(animal[quantanimal].agressivo, 3 , stdin);
        animal[quantanimal].agressivo[strlen(animal[quantanimal].agressivo) - 1] = '\0';
        setbuf(stdin , NULL);
        if (animal[quantanimal].agressivo[0] == 'S' || animal[quantanimal].agressivo[0] == 's' ){
            totalagressivo = totalagressivo + 1;
            break;
        }
        if ( animal[quantanimal].agressivo[0] == 'N' || animal[quantanimal].agressivo[0] == 'n' ){
            break;
        }
        printf ("\nVocê digitou um caracter não correspondente. Digite novamente: 'S' para Sim ou 'N' para Não\n");
    }
}

//Função para procurar o animal de estimação
void buscarPet(void){
    do{
        printf ("\nDigite o nome do animal de estimação: \n");
        setbuf(stdin,NULL);
        fgets (nomepet, 50, stdin);
        nomepet[strlen(nomepet) - 1] = '\0';
        printf("%s", nomepet);
        aux = validarNome (nomepet);
        setbuf(stdin,NULL);
        for (i = 0; i < 100 ; i++){
            if (strcmp (nomepet, animal[i].nomeanimal) == 0){
                printf("\nNome de seu dono: %s\nNúmero de telefone: %s\n",animal[i].dono.nome, animal[i].dono.telefone);
                if(animal[i].especie == 1){
                printf("Espécie cadastrada: Cachorro\n");
                }
                if(animal[i].especie == 2){
                printf("Espécie cadastrada: Gato\n");
                }
                if(animal[i].especie == 3){
                printf("Espécie cadastrada: Pássaro\n");
                }
                if(animal[i].especie == 4){
                printf("Espécie cadastrada: Outro\n");
                }
                printf ("Data de nascimento: %d/%d/%d\n",animal[i].dataanimal.dia ,animal[i].dataanimal.mes ,animal[i].dataanimal.ano);
                if(animal[i].agressivo[0] == 'S' || animal[i].agressivo[0] == 's' ){
                    printf("Animal agressivo: Sim\n");
                }
                if ( animal[i].agressivo[0] == 'N' || animal[i].agressivo[0] == 'n' ){
                printf("Animal agressivo: Não\n");
                }
            }
        }
        printf ("Digite '0' para deixar de procurar:\n");
        fgets(continuar, 20 , stdin);
        
        setbuf(stdin,NULL);
    }while(continuar[0] != '0');
}

//Função para buscar cliente
void buscarCliente(void){
    do{
        printf ("\nDigite o nome do cliente: \n");
        setbuf(stdin,NULL);
        fgets (nomecliente, 50, stdin);
        nomecliente[strlen(nomecliente) - 1] = '\0';
        setbuf(stdin,NULL);
        aux = validarNome (nomecliente);
        for (i = 0; i < 100 ; i++){
            if (strcmp (nomecliente, individuo[i].nome) == 0){
                printf("\nNome: %s\nNúmero de telefone: %s\nNome de seu pet(s): ",individuo[i].nome, individuo[i].telefone);
            }
            if (strcmp (nomecliente, animal[i].dono.nome) == 0){
                printf ("%s ; ", animal[i].nomeanimal);
            }
        }
        printf ("\nDigite '0' para deixar de procurar:\n");
        fgets(continuar, 4 , stdin);
        setbuf(stdin,NULL);
    }while(continuar[0] != '0');
}

//Função para listar em ordem alfabética
void listarPet(void){
    printf ("                               (Lembre-se, a primeira letra de qualquer nome está em maiúsculo)\n\n");
    for(i = 0; i < quantanimal; i++){
        for(i2 = i + 1; i2 < quantanimal; i2++){
            if (animal[i].nomeanimal[0] > animal[i2].nomeanimal[0] ){
                temp2 = animal[i].especie;
                animal[i].especie = animal[i2].especie;
                animal[i2].especie = temp2;

                tempdia = animal[i].dataanimal.dia;
                animal[i].dataanimal.dia = animal[i2].dataanimal.dia;
                animal[i2].dataanimal.dia = tempdia;
                tempmes = animal[i].dataanimal.mes;
                animal[i].dataanimal.mes = animal[i2].dataanimal.mes;
                animal[i2].dataanimal.mes = tempmes;
                tempano = animal[i].dataanimal.ano;
                animal[i].dataanimal.ano = animal[i2].dataanimal.ano;
                animal[i2].dataanimal.ano = tempano;

                strcpy (temp, animal[i].agressivo);
                strcpy (animal[i].agressivo, animal[i2].agressivo);
                strcpy (animal[i2].agressivo, temp);
                
                strcpy (temp, animal[i].nomeanimal);
                strcpy (animal[i].nomeanimal, animal[i2].nomeanimal);
                strcpy (animal[i2].nomeanimal, temp);
            }
        }
    }
    printf("|               Nome do animal               |                Nome do dono                |             Número de telefone             |\n");
    for(i = 0; i < 100; i++){
        tamanhonomeanimal = strlen(animal[i].nomeanimal);
        tamanhonome = strlen(animal[i].dono.nome);
        tamanhotelefone = strlen(animal[i].dono.telefone);
        printf("|");
        for(i2 = 0; i2 < (44 - tamanhonomeanimal) / 2; i2++){
            printf(" ");
        }
        printf ("%s",animal[i].nomeanimal);
        for(i2 = 0; i2 < (45 - tamanhonomeanimal) / 2; i2++){
            printf(" ");
        }
        printf("|");
        for(i2 = 0; i2 < (44 - tamanhonome) / 2; i2++){
            printf(" ");
        }
        printf ("%s",animal[i].dono.nome);
        for(i2 = 0; i2 < (45 - tamanhonome) / 2; i2++){
        printf(" ");
        }
        printf("|");
        for(i2 = 0; i2 < (44 - tamanhotelefone) / 2; i2++){
            printf(" ");
        }
        printf("%s", animal[i].dono.telefone);
        for(i2 = 0; i2 < (45 - tamanhotelefone) / 2; i2++){
            printf(" ");
        }
        printf("|\n");
    }
}
//Função para listar em ordem de espécie
void listarEspecie(void){
    for(i = 0; i < quantanimal; i++){
        for(i2 = i + 1; i2 < quantanimal; i2++){
            if (animal[i].nomeanimal[0] > animal[i2].nomeanimal[0] ){
                temp2 = animal[i].especie;
                animal[i].especie = animal[i2].especie;
                animal[i2].especie = temp2;

                tempdia = animal[i].dataanimal.dia;
                animal[i].dataanimal.dia = animal[i2].dataanimal.dia;
                animal[i2].dataanimal.dia = tempdia;
                tempmes = animal[i].dataanimal.mes;
                animal[i].dataanimal.mes = animal[i2].dataanimal.mes;
                animal[i2].dataanimal.mes = tempmes;
                tempano = animal[i].dataanimal.ano;
                animal[i].dataanimal.ano = animal[i2].dataanimal.ano;
                animal[i2].dataanimal.ano = tempano;

                strcpy (temp, animal[i].agressivo);
                strcpy (animal[i].agressivo, animal[i2].agressivo);
                strcpy (animal[i2].agressivo, temp);
                
                strcpy (temp, animal[i].nomeanimal);
                strcpy (animal[i].nomeanimal, animal[i2].nomeanimal);
                strcpy (animal[i2].nomeanimal, temp);
            }
        }
    }
    
    printf("Digite: 1 - Para listar cachorros | 2 - Para listar gatos | 3 - Para listar pássaros | 4 - Para listar outros animais\n");
    scanf ("%d",&listarespecie);
     
    printf ("                               (Lembre-se, a primeira letra de qualquer nome está em maiúsculo)\n\n");
    printf("|               Nome do animal               |             Data de nascimento             |               Agressividade                |\n");
    for(i = 0; i < 100; i++){
        if (listarespecie == animal[i].especie){
            tamanhonomeanimal = strlen(animal[i].nomeanimal);
            
            printf("|");
            for(i2 = 0; i2 < (44 - tamanhonomeanimal) / 2; i2++){
                printf(" ");
            }
            printf ("%s",animal[i].nomeanimal);
            for(i2 = 0; i2 < (45 - tamanhonomeanimal) / 2; i2++){
                printf(" ");
            }
            printf("|");
            if(animal[i].dataanimal.dia < 10){
                for(i2 = 0; i2 < (44 - 10) / 2; i2++){
                    printf(" ");
                }
                printf("0");
                printf ("%d",animal[i].dataanimal.dia);
            }
            else{
                for(i2 = 0; i2 < (44 - 10) / 2; i2++){
                    printf(" ");
                }
                printf ("%d",animal[i].dataanimal.dia);
            }
            printf("/");
            if(animal[i].dataanimal.mes < 10){
                printf("0");
                printf ("%d",animal[i].dataanimal.mes);
            }
            else{
                printf ("%d",animal[i].dataanimal.mes);
            }
            printf("/");
            printf ("%d",animal[i].dataanimal.ano);
            for(i2 = 0; i2 < (44 - 10) / 2; i2++){
                printf(" ");
            }
            printf("|");
            for(i2 = 0; i2 < (44 - 1) / 2; i2++){
                printf(" ");
            }
            printf("%s", animal[i].agressivo);
            for(i2 = 0; i2 < (45 - 1) / 2; i2++){
                printf(" ");
            }
            printf("|\n");
        }
    }
}

//Função para promoção de aniversário
void Aniversario (int tempdia, int tempmes){
    printf ("\nDigite o dia e depois o mês. Em seguida irei mostrar todos os animais cadastrados num intervalo de 7 dias desta data\n");
    
    for (i = 0; i < 100; i++){
        if (tempmes == animal[i].dataanimal.mes){
            if (tempmes == 1 || tempmes == 3 || tempmes == 5 || tempmes == 7 || tempmes == 8 || tempmes == 10 || tempmes == 12){
                for(i2 = 0; i2 < 8 ; i2++){
                    tempdia = tempdia + i2;
                    if (tempdia > 31){
                        tempdia = tempdia - 31;
                        tempmes = tempmes + 1;
                        if (tempmes == 13){
                            tempmes = 1;
                        }
                    }
                    if (tempmes == animal[i].dataanimal.mes ){
                        if (tempdia == animal[i].dataanimal.dia){
                            printf("Dono: %s\nTelefone: %s\nNome do pet: %s\nEspécie:",animal[i].dono.nome, animal[i].dono.telefone, animal[i].nomeanimal);
                            if (animal[i].especie == 1){
                                printf("Cachorro\n");
                            }
                            if (animal[i].especie == 2){
                                printf("Gato\n");
                            }
                            if (animal[i].especie == 3){
                                printf("Pássaro\n");
                            }
                            if (animal[i].especie == 4){
                                printf("Outro\n");
                            }
                            printf ("Data de nascimento do pet: %d/%d/%d\nAgressivo: ",animal[i].dataanimal.dia ,animal[i].dataanimal.mes ,animal[i].dataanimal.ano);
                            printf ("%s\n\n",animal[i].agressivo);
                        }
                    }
                    tempdia = temp2;
                    tempmes = temp3;
                }
                tempdia = temp2;
                tempmes = temp3;
            }
            if (tempmes == 4 || tempmes == 6 || tempmes == 9 || tempmes == 11){
                for(i2 = 0; i2 < 8 ; i2++){
                    tempdia = tempdia + i2;
                    if (tempdia > 30){
                        tempdia = tempdia - 30;
                        tempmes = tempmes + 1;
                        if (tempmes == 13){
                            tempmes = 1;
                        }
                    }
                    if (tempmes == animal[i].dataanimal.mes ){
                        if (tempdia == animal[i].dataanimal.dia){
                            printf("Dono: %s\nTelefone: %s\nNome do pet: %s\nEspécie:",animal[i].dono.nome, animal[i].dono.telefone, animal[i].nomeanimal);
                            if (animal[i].especie == 1){
                                printf("Cachorro\n");
                            }
                            if (animal[i].especie == 2){
                                printf("Gato\n");
                            }
                            if (animal[i].especie == 3){
                                printf("Pássaro\n");
                            }
                            if (animal[i].especie == 4){
                                printf("Outro\n");
                            }
                            printf ("Data de nascimento do pet: %d/%d/%d\nAgressivo: ",animal[i].dataanimal.dia ,animal[i].dataanimal.mes ,animal[i].dataanimal.ano);
                            printf ("%s\n\n",animal[i].agressivo);
                        }
                        
                    }
                    tempdia = temp2;
                    tempmes = temp3;
                }
                tempdia = temp2;
                tempmes = temp3;
            }
            if (tempmes == 2 && animal[i].dataanimal.ano % 4 == 0){
                for(i2 = 0; i2 < 8 ; i2++){
                    tempdia = tempdia + i2;
                    if (tempdia > 29){
                        tempdia = tempdia - 29;
                        tempmes = tempmes + 1;
                        if (tempmes == 13){
                            tempmes = 1;
                        }
                    }
                    if (tempmes == animal[i].dataanimal.mes ){
                        if (tempdia == animal[i].dataanimal.dia){
                            printf("Dono: %s\nTelefone: %s\nNome do pet: %s\nEspécie:",animal[i].dono.nome, animal[i].dono.telefone, animal[i].nomeanimal);
                            if (animal[i].especie == 1){
                                printf("Cachorro\n");
                            }
                            if (animal[i].especie == 2){
                                printf("Gato\n");
                            }
                            if (animal[i].especie == 3){
                                printf("Pássaro\n");
                            }
                            if (animal[i].especie == 4){
                                printf("Outro\n");
                            }
                            printf ("Data de nascimento do pet: %d/%d/%d\nAgressivo: ",animal[i].dataanimal.dia ,animal[i].dataanimal.mes ,animal[i].dataanimal.ano);
                            printf ("%s\n\n",animal[i].agressivo);
                        }
                    }
                    tempdia = temp2;
                    tempmes = temp3;
                }
                tempdia = temp2;
                tempmes = temp3;
            }
            if (tempmes == 2){
                for(i2 = 0; i2 < 8 ; i2++){
                    tempdia = tempdia + i2;
                    if (tempdia > 28){
                        tempdia = tempdia - 28;
                        tempmes = tempmes + 1;
                        if (tempmes == 13){
                            tempmes = 1;
                        }
                    }
                    if (tempmes == animal[i].dataanimal.mes ){
                        if (tempdia == animal[i].dataanimal.dia){
                            printf("Dono: %s\nTelefone: %s\nNome do pet: %s\nEspécie:",animal[i].dono.nome, animal[i].dono.telefone, animal[i].nomeanimal);
                            if (animal[i].especie == 1){
                                printf("Cachorro\n");
                            }
                            if (animal[i].especie == 2){
                                printf("Gato\n");
                            }
                            if (animal[i].especie == 3){
                                printf("Pássaro\n");
                            }
                            if (animal[i].especie == 4){
                                printf("Outro\n");
                            }
                            printf ("Data de nascimento do pet: %d/%d/%d\nAgressivo: ",animal[i].dataanimal.dia ,animal[i].dataanimal.mes ,animal[i].dataanimal.ano);
                            printf ("%s\n\n",animal[i].agressivo);
                        }
                    }
                    tempdia = temp2;
                    tempmes = temp3;
                }
                tempdia = temp2;
                tempmes = temp3;
            }
            
        }
    }
    
}
//Função para os serviços do petshop
void serviçosPetshop(void){
    do{
    scanf("%d", &serviço[incremental].tipodeserviço);
    if (serviço[incremental].tipodeserviço != 1 || serviço[incremental].tipodeserviço != 2 ||serviço[incremental].tipodeserviço != 3){
        printf("\nVocê digitou um serviço que não existe. Digite: 1 - Banho | 2 - Tosa | 3 - Vacina\n");
    }
    }while(serviço[incremental].tipodeserviço != 1 || serviço[incremental].tipodeserviço != 2 ||serviço[incremental].tipodeserviço != 3 );
    printf("Agora digite o nome do animal de estimação já cadastrado que receberá o serviço\n");
    setbuf(stdin,NULL);
    fgets (nomepet, 50, stdin);
    nomepet[strlen(nomepet) - 1] = '\0';
    printf("%s", nomepet);
    aux = validarNome (nomepet);
    setbuf(stdin,NULL);
    for (i = 0; i < 100 ; i++){
        if (strcmp (nomepet, animal[i].nomeanimal) == 0){
            printf("\nNome de seu dono: %s\nNúmero de telefone: %s\n",animal[i].dono.nome, animal[i].dono.telefone);
            if(animal[i].especie == 1){
            printf("Espécie cadastrada: Cachorro\n");
            }
            if(animal[i].especie == 2){
            printf("Espécie cadastrada: Gato\n");
            }
            if(animal[i].especie == 3){
            printf("Espécie cadastrada: Pássaro\n");
            }
            if(animal[i].especie == 4){
            printf("Espécie cadastrada: Outro\n");
            }
            printf ("Data de nascimento: %d/%d/%d\n",animal[i].dataanimal.dia ,animal[i].dataanimal.mes ,animal[i].dataanimal.ano);
            if(animal[i].agressivo[0] == 'S' || animal[i].agressivo[0] == 's' ){
                printf("Animal agressivo: Sim\n");
            }
            if ( animal[i].agressivo[0] == 'N' || animal[i].agressivo[0] == 'n' ){
            printf("Animal agressivo: Não\n");
            }
            strcpy (serviço[incremental].pet.dono.nome, animal[i].dono.nome);
            strcpy (serviço[incremental].pet.dono.telefone, animal[i].dono.telefone);
            serviço[incremental].pet.especie = animal[i].especie;
            serviço[incremental].pet.dataanimal.dia = animal[i].dataanimal.dia;
            serviço[incremental].pet.dataanimal.mes = animal[i].dataanimal.mes;
            serviço[incremental].pet.dataanimal.ano = animal[i].dataanimal.ano;
            strcpy (serviço[incremental].pet.agressivo, animal[i].agressivo);
        }
    }
    serviço[incremental].dataserviço;
    
}

int main()
{
    clientesjaCadastrados();
    do{
        do{
            printf ("\n--------------MENU--------------\n");
            printf ("1: Cadastrar cliente\n");
            printf ("2: Cadastrar animal de estimação\n");
            printf ("3: Buscar cliente por nome\n");
            printf ("4: Buscar animal de estimação por nome\n");
            printf ("5: Listagem em ordem alfabética dos animais de estimação\n");
            printf ("6: Listagem por escolha de espécie\n");
            printf ("7: Quantidade de animais agressivos\n");
            printf ("8: Promoção de aniversário\n");
            printf ("9: Serviços do petshop\n");
            printf ("Escolha uma opcao: \n");
            scanf ("%d", &menu);
        }while(menu < 1 || menu > 9);
        switch(menu) {
            case 1:
            {
                printf ("----------Cadastro de cliente----------\n");
                cadastrarCliente(individuo);
                quantpessoa++;
                menu = 0;
                break;
            }
            case 2: 
            {
                printf ("-------Cadastro de animal de estimação-------\n");
                cadastrarAnimal (animal);
                quantanimal++;
                menu = 0;
                break;
            }
            case 3: 
            {
                printf("--------Busca de informção de cliente--------\n");
                buscarCliente();
                menu = 0;
                break;
            }
            case 4:
            {
                printf("--------Busca de informações do pet--------\n");
                buscarPet();
                menu = 0;
                break;
            }
            case 5:
            {
                printf("------------------------------------------------------Listagem em ordem alfabética-----------------------------------------------------\n");
                listarPet();
                menu = 0;
                break;
            }
            case 6:
            {
                printf("------------------------------------------------------Listagem em ordem de espécie-----------------------------------------------------\n");
                listarEspecie();
                menu = 0;
                break;
            }
            case 7:
            {
                printf("-----------Quantidade de animais agressivos-----------\n");
                printf("Existem %d animais agressivos em nosso banco de dados\n",totalagressivo);
                menu = 0;
                break;
            }
            case 8:
            {
                printf("---------------------Aniversário---------------------\n");
                printf("Esta opção de menu tem como objetivo ver se um animal de estimação está elegível à promoção de aniversário\n");
                do{
                    printf ("\nDia: ");
                    scanf ("%d", &tempdia);
                    printf ("\n");
                    printf ("Mês: ");
                    scanf ("%d", &tempmes);
                    printf ("\n");
                    temp2 = tempdia;
                    temp3 = tempmes;
                    if (tempdia < 1 || tempdia > 31 || tempmes < 1 || tempmes > 12){
                        printf ("Você digitou uma data que não existe, digite novamente:\n");
                    }
                    }while(tempdia < 1 || tempdia > 31 || tempmes < 1 || tempmes > 12);
                Aniversario(tempdia ,tempmes);
                menu = 0;
                break;
            }
            case 9:
            {
                printf("---------------------------------Serviços---------------------------------\n");
                printf("Os serviços dispnoníveis em nosso petshop são o banho, a tosa e a vacina\n\n");
                printf("|     Tipo     |     Deascrição     |     Valor     |\n");
                printf("|       1      |        Banho       |    R$ 40,00   |\n");
                printf("|       2      |        Tosa        |    R$ 65,00   |\n");
                printf("|       3      |       Vacina       |    R$ 120,00  |\n\n");
                printf("Para escolher o serviço, digite o tipo dele\n");
                
            }
        }
    }while(menu == 0);
    return 0;
}
