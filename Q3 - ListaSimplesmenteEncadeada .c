#include <stdio.h>
#include <stdlib.h>

struct no{
	int num;
	struct no *prox;
};

typedef struct no No;

No *criar_no(){
	No *novo = malloc(sizeof(No));
	return novo;
}

//Função para inserir no inicio
No *inserirInicio(No *Lista, int dado){
	No *novo_no = criar_no();
	novo_no->num = dado;
	
	if(Lista == NULL){
		Lista = novo_no;
		novo_no->prox = NULL;
	} else {
		novo_no->prox = Lista;
		Lista = novo_no;
	}
	return Lista;
}

void imprimir(No *Lista){
	No *aux = Lista;
	
	while(aux!=NULL){
		printf("%d ", aux->num);
		aux = aux->prox;
	}
}

int main(){
	No *Lista = NULL;
	
	Lista = inserirInicio (Lista, 10);
	Lista = inserirInicio (Lista, 20);
	Lista = inserirInicio (Lista, 30);
	Lista = inserirInicio (Lista, 40);
	Lista = inserirInicio (Lista, 50);
	imprimir(Lista);
	
	return 0;
}
