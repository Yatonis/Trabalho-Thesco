#include <stdio.h>
#include <string.h>
int i = 0 , aux = 0;
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
struct Cliente individuo;
//Validação de nome
int validarNome (char nome[]){
if (strlen (nome) < 4 ){
    return 0;
}
if(nome[0] == ' '){
    return 0;
}
for (i = 0; i < 50; i++){
    if(nome[i] < 'a' && nome[i] != '\0' || nome[i] > 'z' && nome[i] != '\0' ){
        if(nome[i] < 'A' && nome[i] != '\0' || nome[i] > 'Z' && nome[i] != '\0'){
            return 0;  
        }
        }
        
    }
return 1;
}
// Validação do número de telefone, obs: tirar os printf depois
int validarNumero (char numero[]){
    if (numero[0] != '0'){
        printf ("errado1");
        return 0;
    }
if (strlen (numero) < 11 || strlen (numero) > 12 ){
        printf ("errado2");
    return 0;
}
for (i = 0; i < 20; i++){
    if (numero[i] < '0' && numero[i] != '\0' && numero[i] != '\n' || numero[i] > '9' && numero[i] != '\0' && numero[i] != '\n'){
        printf ("errado3");
        return 0;
    }
}
return 1;
}
//Função para cadastrar clientes
void cadastrarCliente(struct Cliente indiviuo){
    do{
        printf("\nDigite o seu nome: \n");
        fgets (individuo.nome, 50 , stdin);
        individuo.nome[strlen(individuo.nome) - 1] = '\0';
        aux = validarNome (individuo.nome);
        setbuf(stdin,NULL);
    }while (aux == 0);
    do{
        printf("\nDigite o seu número de telefone: \n");
        fgets (individuo.telefone, 15, stdin);
        individuo.telefone[strlen(individuo.telefone) - 1] = '\0';
        aux = validarNumero (individuo.telefone);
        setbuf(stdin,NULL);
    }while (aux == 0);
}
