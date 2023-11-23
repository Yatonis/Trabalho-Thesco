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
int validarNome (char nome[]){
if (strlen (nome) < 4 ){
    return 0;
}
if(nome[0] == ' '){
    return 0;
}
for (i = 0; i < 50; i++){
    if(nome[i] < 65 || nome[i] > 122 || nome[i] > 90  && nome[i] < 97 ){
        return 0;
        }
        
    }
return 1;
}
