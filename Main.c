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
 in validarNome (char nome[]){
 if (strlen (nome) < 4 ){
    return 0;
}
if(nm[0] == ''){
    return 0;
}
    return 1;
}
