#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int num;
	struct Lista *ant;
	struct Lista *prox;
}Lista;

int criaNo(Lista **root, int num);
void imprime(Lista **root);
Lista *rotacaoNode(Lista **root);

int main (void){
	Lista *root;
	int tamanho;
	int num;
	int rotacao;
	int i;
	
	root = NULL;
	printf("\nDigite o tamanho e quantidade da rotacao: ");
	scanf("%d %d", &tamanho, &rotacao);
	
	for(i =0; i < tamanho; i++){
		scanf("%d ", &num);
		if (criaNo(&root, num) == 1){
			return (1);
		}	
	}
	printf("Antes da Rotacao\n");
	imprime(&root);
	for(i = 0; i < rotacao; i++)
	{
		rotacaoNode(&root);
		printf("Antes da Rotacao\n");
		imprime(&root);
		printf("\n");
	}
return 0;
}
//Criando novo no
int criaNo(Lista **root, int num){
	Lista *node;
	Lista *antNode;
	
	antNode = *root;
	node = malloc(sizeof(Lista));
	if(node == NULL){
		return (1);
	}
	//Inicializando o Node
	node->num = num;
	node->ant = NULL;
	node->prox = NULL;
	
	if(*root == NULL){
		*root = node;
	}
	else{
		node->prox = *root;
		(*root)->ant = node;
		
		if(antNode->prox == NULL)
		{
			antNode->prox = node;
		}
		else{
			while(antNode->prox != *root)
			{
				antNode = antNode->prox;
			}
			antNode->prox = node;
		}
		node->ant = antNode;
	}
	return 0;
}

//Imprime node
void imprime(Lista **root){
	Lista *AtualNode;
	AtualNode = *root;
	
	while(AtualNode->prox != *root)
	{
		printf("%d\n", AtualNode->num);
		AtualNode = AtualNode->prox;
	}
	
}

//Rotacao node
Lista *rotacaoNode(Lista **root){
	Lista *antNode;
	
	antNode = (*root)->ant;
	*root = antNode;
	
	return (*root);
}




