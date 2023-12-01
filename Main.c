#include <stdio.h>
#include <string.h>
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
    struct Cliente cliente;
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
