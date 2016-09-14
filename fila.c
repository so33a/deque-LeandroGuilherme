#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next, link prev) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  t->prev = prev;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->fim = f->inicio = NULL;
  return f;
}

void inseriresq(FILA f,int e) {
    link t;
  if(f->inicio == NULL) {
    f->inicio = f->fim  = novoNo(e, NULL, NULL);
  } else {
    f->inicio->prev = t = novoNo(e, NULL, NULL);
    t->next = f->inicio;
    f->inicio = t;
  }
}


void inserir(FILA f, int e) {
  if(f->fim == NULL) {
    f->inicio = f->fim = novoNo(e, NULL,NULL);
  } else {
    f->fim->next = novoNo(e, NULL,f->fim);
    f->fim = f->fim->next;
  }
}

int removerdir(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }

  x = f->inicio->item;
  t = f->inicio;
  f->inicio = f->inicio->prev;

  if(f->inicio == NULL)
    f->fim = NULL;

  free(t);
  return x;
}


int remover(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }

  x = f->fim->item;
  t = f->fim;
  f->fim = f->fim->next;

  if(f->fim == NULL)
    f->inicio = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->inicio == NULL) || (f->fim == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->inicio; t != NULL; t = t->next)
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}

