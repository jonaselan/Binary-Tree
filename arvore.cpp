#include <stdio.h>
#include <conio.h>

//Declaração da estrutura nó
typedef struct no {
    int info;
    struct no *dir, *esq;
};


//Função para criar um nó
no * cria_no(int x){
    no *p;
    p=new no;
    p->info = x;
    p->esq = p->dir =NULL;
    return(p);
}


//Função para inserir um nó na Árvore binária de busca (ABB)
void insere_ABB(no ** pos, int x){

    if (*pos ==NULL){
        *pos = cria_no(x);
        return;
    }

    if (x < (*pos)->info){
        insere_ABB(&((*pos)->esq), x);
    }else {
        if(x>(*pos)->info) {
            insere_ABB( &((*pos)->dir), x);
        }else{
            printf(“%d ja estava inserido na arvore \n”, x);
        }
    }
}

//Função de impressão em ordem
void inorder(no *p){

    if (p!=NULL) {
        inorder (p->esq);
        printf (” %d “, p->info);
        inorder (p->dir);
    }
}

// Função que verifica se um elemento está cadastrado ou não na árvore
int busca_ABB(no * pos, int x){

    if (pos ==NULL){
        return (0);
    }

    if (x== pos->info) {
        return(1);
    }

    if (x < pos->info){
        return(busca_ABB(pos->esq, x));
    }else{
        if(x> pos->info) {
            return(busca_ABB(pos->dir, x));
        }
    }
}

// Função que recebe um elemento de uma árvore e retorna o seu nível.
int nivel_ABB(no *pos, int x, int nivel){

    if (pos ==NULL){
        return (-1);
    }

    if (x== pos->info) {
        return(nivel);
    }

    if (x < pos->info){
        return(nivel_ABB(pos->esq, x, nivel+1));
    }else{
        if(x> pos->info) {
            return(nivel_ABB(pos->dir, x, nivel+1));
        }
    }
}

// Função que recebe a raiz de uma árvore binária e informa se ela é binária de busca.
int testa_ABB(no * pos){
    int arvesq=1, arvdir=1;

    if (pos ==NULL){
        return (1);
    }

    if ((pos->esq ==NULL) && (pos->dir ==NULL))
        return(1);

    if (pos->esq!=NULL){
        if(pos->info < pos->esq->info){
            return(0);
        }else{
            arvesq = testa_ABB(pos->esq);
        }
    }

    if (pos->dir != NULL){
        if(pos->info > pos->dir->info){
            return(0);
        }else{
            arvdir = testa_ABB(pos->dir);
        }
    }

    if ((arvdir==0) || (arvesq == 0))
       return(0);
    else
       return (1);

}

// Função que recebe a raiz de uma árvore binária e imprime todos os nós folha.
void imprime_folhas(no *pos){

    if (pos ==NULL){
        printf (“Arvore vazia”);
        return;
    }

    if ((pos->esq==NULL) && (pos->dir == NULL)) {
        printf(” %d “, pos->info);
    }else{
        if (pos->esq!=NULL){
            imprime_folhas(pos->esq);
        }
        if (pos->dir!=NULL){
            imprime_folhas(pos->dir);
        }
    }
}

// Função que recebe a raiz de uma árvore binária e imprime todos os nós não folha.
void imprime_nao_folhas(no *pos){

    if (pos ==NULL){
        printf (“Arvore vazia”);
        return;
    }

    if ((pos->esq!=NULL) || (pos->dir != NULL)) {
        printf(” %d “, pos->info);
    }

    if (pos->esq!=NULL){
        imprime_nao_folhas(pos->esq);
    }

    if(pos->dir!=NULL) {
        imprime_nao_folhas(pos->dir);
    }
}

// Função que recebe a raiz de uma árvore binária e imprime todos os nós com o respectivo nível
void imprime_nivel(no *pos, int nivel){

    if (pos ==NULL){
        printf(“arvore vazia\n”);
        return ;
    }

    printf(“%d nivel %d \n”, pos->info, nivel);

    if (pos->esq !=NULL)
        imprime_nivel (pos->esq, nivel+1);

    if (pos->dir !=NULL)
        imprime_nivel (pos->dir, nivel+1);

}
