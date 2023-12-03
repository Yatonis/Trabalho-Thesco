#include <stdio.h>
#include <string.h>
int i = 0 , aux = 0, i2 = 0, totalagressivo = 0;
char temp[50];
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
if (strlen (nome) < 4 ){
    printf("\nO nome foi digitado incorretamente. O motivo é que você digitou menos de 4 caracteres\n");
    return 0;
}
if(nome[0] == ' '){
    printf("\nO nome foi digitado incorretamente. O motivo é um espaço ocupando o primeiro caracter\n");
    return 0;
}
for (i = 0; i < 50; i++){
    if(nome[i] < 'a' && nome[i] != '\0' || nome[i] > 'z' && nome[i] != '\0' ){
        if(nome[i] < 'A' && nome[i] != '\0' && nome[i] != ' ' || nome[i] > 'Z' && nome[i] != '\0' && nome[i] != ' '){
            printf("\nO nome foi digitado incorretamente, sendo a provavel causa deste erro a utilização de algum caracter que não esteja no alfabeto\n");
            return 0;  
        }
        }
        
    }
return 1;
}
// Validação do número de telefone, obs: tirar os printf depois
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
        fgets (individuo[0].nome, 50 , stdin);
        individuo[0].nome[strlen(individuo[0].nome) - 1] = '\0';
        aux = validarNome (individuo[0].nome);
        setbuf(stdin,NULL);
    }while (aux == 0);
    do{
        printf("\nDigite o seu número de telefone: \n");
        fgets (individuo[0].telefone, 15, stdin);
        individuo[0].telefone[strlen(individuo[0].telefone) - 1] = '\0';
        aux = validarNumero (individuo[0].telefone);
        setbuf(stdin,NULL);
    }while (aux == 0);
}
//Função para cadastrar animais
void cadastrarAnimal (struct Animal animal){
    printf("\nDigite o nome do proprietário do animal que fez o cadastro no site: \n");
    for (i = 0; i < 100; i++){
        do{
            fgets (animal.dono.nome, 50 , stdin);
            animal.dono.nome[strlen(animal.dono.nome) - 1] = '\0';
            setbuf(stdin,NULL);
            aux = validarNome (animal.dono.nome);
        }while (aux == 0);
        for (i2 = 0; i2 < 100; i2++){
            if (strcmp (animal.dono.nome , individuo[i2].nome) == 0){
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
        fgets (animal.nomeanimal, 50 , stdin);
        animal.nomeanimal[strlen(animal.nomeanimal) - 1] = '\0';
        aux = validarNome (animal.nomeanimal);
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
int main()
{
    // dps colocar if para escolher o indivíduo. Por enquanto para teste só utilizando individuo[0] e animal[0]
    cadastrarCliente(individuo[0]) ;
    cadastrarAnimal (animal[0]);
