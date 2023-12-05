#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i = 0 , aux = 0, i2 = 0, totalagressivo = 3,  tamanhonomeanimal,tamanhonome,tamanhotelefone;
int menu = 0, quantpessoa = 3, quantanimal = 5, petsporcliente = 0;
char temp[50], continuar[4] , nomepet[50], nomecliente[50];
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
struct serviço{
    int identificador;
    struct Data dataserviço;
    struct Animal pet;
    int serviço;
    char pagamento;
};
//Declaração das structs
struct Cliente individuo[100];
struct Animal animal[100];
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
//Função para cadastrar clientes. Para teste por enquanto apenas utilizando indivduo[0]
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
    printf("\nO seu animal é agressivo?\n");
    printf("Digite:\n S - Para Sim\n N - Para Não\n");
    for (;1;){
        setbuf(stdin , NULL);
        fgets(animal[quantanimal].agressivo, 4 , stdin);
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
                if(animal[i].agressivo[0] == 'S' || animal[i].agressivo[0] == 's' ){
                    printf("Animal agressivo: Sim\n");
                }
                if ( animal[i].agressivo[0] == 'N' || animal[i].agressivo[0] == 'n' ){
                printf("Animal agressivo: Não\n");
                }
            }
        }
        printf ("Digite '0' para deixar de procurar:\n");
        fgets(continuar, 4 , stdin);
        
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
            printf ("6: Quantidade de animais agressivos\n");
            printf ("Escolha uma opcao: \n");
            scanf ("%d", &menu);
        }while(menu < 1 || menu > 6);
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
                printf("-----------Quantidade de animais agressivos-----------\n");
                printf("Existem %d animais agressivos em nosso banco de dados\n",totalagressivo);
                menu = 0;
                break;
            }
        }
    }while(menu == 0);
    return 0;
}


