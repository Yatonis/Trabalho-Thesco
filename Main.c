#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i = 0 , aux = 0, i2 = 0, totalagressivo = 0,  tamanhonomeanimal,tamanhonome,tamanhotelefone;
int menu = 0, quantpessoa = 0, quantanimal = 0;
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
    char agressivo;
    
};
struct serviço{
    int identificador;
    struct Data dataserviço;
    struct Animal pet;
    int serviço;
    char pagamento;
};
struct Cliente individuo[100];
struct Animal animal[100];
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
void cadastrarCliente(struct Cliente indiviuo){
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
void cadastrarAnimal (struct Animal animal){
    printf("\nDigite o nome do proprietário do animal que fez o cadastro no site: \n");
    for (i = 0; i < 100; i++){
        do{
            setbuf(stdin,NULL);
            fgets (animal.dono.nome, 50 , stdin);
            animal.dono.nome[strlen(animal.dono.nome) - 1] = '\0';
            setbuf(stdin,NULL);
            aux = validarNome (animal.dono.nome);
        }while (aux == 0);
        for (i2 = 0; i2 < 100; i2++){
            if (strcmp (animal.dono.nome , individuo[i2].nome) == 0){
                strcpy(animal.dono.nome , individuo[i2].nome);
                strcpy(animal.dono.telefone , individuo[i2].telefone);
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
        fgets (animal.nomeanimal, 50 , stdin);
        animal.nomeanimal[strlen(animal.nomeanimal) - 1] = '\0';
        aux = validarNome (animal.nomeanimal);
        setbuf(stdin,NULL);
    }while (aux == 0);
    printf("\nQual é a espécie de seu animal de estimação?\n");
    printf("Digite: \n1 - Para cachorro \n2 - Para gato \n3 - Para pássaro \n4 - Para outros\n");
    for (;1;){
        scanf ("%d", &animal.especie);
        if (animal.especie == 1 || animal.especie == 2 || animal.especie == 3 || animal.especie == 4 ){
            break;
        }
        printf ("\nVocê digitou um caracter não correspondente. Digite novamente o número que corresponde a espécie de seu animal\n");
    }
    printf("\nO seu animal é agressivo?\n");
    printf("Digite:\n S - Para Sim\n N - Para Não\n");
    for (;1;){
        scanf (" %c",&animal.agressivo);
        if (animal.agressivo == 'S' || animal.agressivo == 's' ){
            totalagressivo = totalagressivo + 1;
            break;
        }
        if ( animal.agressivo == 'N' || animal.agressivo == 'n' ){
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
                if(animal[i].agressivo == 'S' || animal[i].agressivo == 's' ){
                    printf("Animal agressivo: Sim\n");
                }
                if ( animal[i].agressivo == 'N' || animal[i].agressivo == 'n' ){
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
                printf("\nNome: %s\nNúmero de telefone: %s\nNome de seu pet: %s\n",individuo[i].nome, individuo[i].telefone, animal[i].nomeanimal);
                
            }
        }
        printf ("Digite '0' para deixar de procurar:\n");
        fgets(continuar, 4 , stdin);
        setbuf(stdin,NULL);
    }while(continuar[0] != '0');
}
//Função para listar em ordem alfabética
void listarPet(void){
    printf ("\nLembre-se, a primeira letra de qualquer nome está em maiúsculo\n");
    for(i = 0; i < quantanimal; i++){
        for(i2 = i + 1; i2 < quantanimal; i2++){
            if (animal[i].nomeanimal[0] < animal[i2].nomeanimal[0] ){
                strcpy (temp, animal[i].nomeanimal);
                strcpy (animal[i].nomeanimal, animal[i2].nomeanimal);
                strcpy (animal[i2].nomeanimal, temp);
            }
        }
    }
    printf("|               Nome do animal               |                Nome do dono                |            Número de telefone            |\n");
    tamanhonomeanimal = strlen(animal[i].nomeanimal);
    tamanhonome = strlen(animal[i].dono.nome);
    tamanhotelefone = strlen(animal[i].dono.telefone);
    for(i = 0; i < 100; i++){
        printf("|");
        for(i2 = 0; i2 < (44 - tamanhonomeanimal) / 2; i2++){
            printf(" ");
        }
        printf ("%s",animal[i].nomeanimal);
        for(i2 = 0; i2 < (44 - tamanhonomeanimal) / 2; i2++){
            printf(" ");
        }
        printf("|");
        for(i2 = 0; i2 < (44 - tamanhonome) / 2; i2++){
            printf(" ");
        }
        printf ("%s",animal[i].dono.nome);
        for(i2 = 0; i2 < (44 - tamanhonome) / 2; i2++){
        printf(" ");
        }
        printf("|");
        for(i2 = 0; i2 < (44 - tamanhotelefone) / 2; i2++){
            printf(" ");
        }
        printf("%s", animal[i].dono.telefone);
        for(i2 = 0; i2 < (43 - tamanhotelefone) / 2; i2++){
            printf(" ");
        }
        printf("|\n");
    }
}
int main()
{
    // dps colocar if para escolher o indivíduo. Por enquanto para teste só utilizando individuo[0] e animal[0]
    do{
        do{
            printf ("\n--------------MENU--------------\n");
            printf("%s\n",animal[0].dono.nome);
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
                cadastrarCliente(individuo[quantpessoa]);
                quantpessoa++;
                menu = 0;
                break;
            }
            case 2: 
            {
                printf ("-------Cadastro de animal de estimação-------\n");
                cadastrarAnimal (animal[quantanimal]);
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
