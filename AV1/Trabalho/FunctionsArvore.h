typedef struct arv{
       int info;
       float nota1,nota2,nota3;
       char nome[100];
       struct arv* esq;
       struct arv* dir;
}Arv;

Arv *inicializa();
Arv *insere(Arv *a, int x, float n1, float n2,float n3, char n[]);
Arv* rotacaoDireita(Arv*raiz);
Arv* rotacaoEsquerda(Arv*raiz);
Arv* duplaEsquerda(Arv*raiz);
Arv* duplaDireita(Arv*raiz);
int contEsq(Arv*raiz);
int contDir(Arv*raiz);
void imprimeInOrdem(Arv *a);
void imprimePreOrdem(Arv *a);
void imprimePosOrdem(Arv *a);
Arv *busca(Arv *r, int x);
Arv *binaria(Arv *r);
int qtdNos(Arv*r);
int qtdFolha(Arv *r);
int somaNos(Arv *r);
int altura(Arv *r);
int vazia(Arv *a);
int NivelEscalar(Arv*a, int x);
int calculaEscalar(Arv *a, int x);
Arv *lerDoArquivo(char path[], Arv *a);


Arv *inicializa(){
   return NULL;
}
/*
Arv *insere(Arv *a, int x, int n1, int n2, char n)
{
   if (a==NULL) {
      a = (Arv*)malloc(sizeof(Arv));
      a->info = x;
      a->nota1= n1;
      a->nota2= n2;
      a->nome[50] = n;
      a->esq = a->dir = NULL;
      printf("Armazenou\n");
   }
   else if (x < a->info){
   //printf("ValorMenor");
      a->esq = insere(a->esq,x,n,n1,n2);

      if(contEsq(a)-contDir(a)==2)
      {
         // printf("RotacaoDireita");
          if(x < a->esq->info)
            a = rotacaoDireita(a);
          else
         // printf("RotacaDupla");
            a = duplaEsquerda(a);
       }
    }
   else if(x > a->info){
       // printf("\nValorMaior\n");
        a->dir = insere(a->dir,x,n,n1,n2);
        if(contDir(a)-contEsq(a)==2)
        {
          //  printf("rotacionando\n");
            if(x > a->dir->info)
                a = rotacaoEsquerda(a);
            else
               // printf("RotacaoDuplaDireita");
                a = duplaDireita(a);
         }
    }
   return a;
 }

 /// Funcao que realiza a rotacao para direita
Arv* rotacaoDireita(Arv*raiz)
{
  Arv* aux = raiz; ///variavel auxiliar
  Arv* A = aux; ///variavel auxiliar A recebe aux
  Arv* B = aux->esq; ///Variavel auxiliar B recebe aux->esq

   A->esq = B->dir; ///A->esq recebe B->dir
   B->dir = A; ///B->dir recebe A
   return B; ///retorno B
}

/// Funcao que realiza a rotacao para Esquerda
Arv* rotacaoEsquerda(Arv*raiz)
{
  Arv* aux = raiz; ///Variavel auxiliar
  Arv* A = aux; /// Variavel auxiliar A recebe aux
  Arv* B = aux->dir; / Variavel auxilar B recebe aux->dir

  A->dir = B->esq; ///A->dir recebe B->esq
  B->esq = A; ///B->eesq recebe A
  return B; ///retorna B
}
///Funcao que realiza a rotacao dupla  para esquerda
Arv* duplaEsquerda(Arv*raiz)
{
     Arv* aux = raiz; ///variavel auxiliar
     ///aux->esq recebe rotacaoEsquerda(aux)->esq
     aux->esq = rotacaoEsquerda(aux->esq);
     ///aux recebe rotacaoDireita(aux)
     aux = rotacaoDireita(aux);
     return aux; ///retorna aux
}
///Funcao que realiza a rotacao dupla para direita
Arv* duplaDireita(Arv*raiz)
{
  Arv* aux = raiz; ////variavel auxiliar
  ///aux->dir recebe rotacaoDireita(aux->dir)
  aux->dir = rotacaoDireita(aux->dir);
  ///aux recebe rotacaoEsquerda(aux)
  aux = rotacaoEsquerda(aux);
  return aux; ///retorna aux
}


/// Funcao que conta a altura da esquerda
int contEsq(Arv*raiz)
{
  Arv* aux = raiz; ///variavel auxiliar
  int cont = 0; /// variavel do tipo inteiro recebe 0

  if(aux->esq == NULL) /// se aux->esq == NULL
  {
    return 0; ///Retorna 0
  }else /// Senao
  {
    while(aux->esq != NULL) /// Enquanto aux->esq diferente de NULL
    {
      aux = aux->esq; ///aux recebe aux->esq
      cont = cont + 1; /// cont recebe cont + 1
      /// Se aux-<esq igual a NULL e aux->dir diferente de NULL
      if(aux->esq == NULL && aux->dir != NULL)
      {
        while(aux->dir != NULL) ///Enquanto aux->dir diferente de NULL
        {
         cont = cont + 1; /// cont recebe cont + 1
         aux = aux->dir; ///aux recebe aux->dir
        }
      }
    }
    return cont; ///retornar cont
  }
}

/// Funcao que conta a altura da direita
int contDir(Arv*raiz)
{
  Arv* aux = raiz; /// variavel auxiliar
  int cont = 0; ///variaavel to tipo inteiro recebe 0

  if(aux->dir == NULL) ///Se aux->dir for igual a 0
  {
    return 0; ///Retorna zero
  }else /// Senao
  {
    while(aux->dir != NULL) ///enquanto aux->dir for diferente de NULL
    {
      aux = aux->dir; ///aux recebe aux->dir
      cont = cont + 1; ///cont recebe cont + 1
      ///Se aux->dir == NULL e aux->esq diferente NULL
      if(aux->dir == NULL && aux->esq != NULL)
      {
        while(aux->esq != NULL) ///enquanto aux->esq diferente de NULL
        {
         cont = cont + 1; ///cont recebe cont + 1
         aux = aux->esq; ///aux recebe aux +1
        }
      }
    }
    return cont; ///retorna cont
  }
}
*/


Arv *insere(Arv *a, int x, float n1, float n2, float n3, char n[])
{
   if (vazia(a)) {
      a = (Arv*)malloc(sizeof(Arv));
      a->info = x;
      a->nota1= n1;
      a->nota2= n2;
      a->nota3= n3;
      strcpy(a->nome,n);
      a->esq = a->dir = NULL;
   }
   else if (x < a->info)
      a->esq = insere(a->esq,x,n1,n2,n3,n);
   else
      a->dir = insere(a->dir,x,n1,n2,n3,n);
   return a;
}

void imprimeInOrdem(Arv *a)
{
   if (!vazia(a)) {
      imprimeInOrdem(a->esq);
      printf("Matricula:[ %d ]\n",a->info);
      printf("Nome: %s\n",a->nome);
      printf("Nota1: %.2f\n",a->nota1);
      printf("Nota2: %.2f\n",a->nota2);
      printf("Nota3: %.2f\n",a->nota3);
      printf("Media: %.2f\n", (a->nota1+a->nota2+a->nota3)/3);
      printf("\n\n");
      imprimeInOrdem(a->dir);
    }
}

void imprimePreOrdem(Arv *a)
{
   if (!vazia(a)) {
      printf("Matricula:[ %d ]\n",a->info);
      printf("Nome: %s\n",a->nome);
      printf("Nota1: %.2f\n",a->nota1);
      printf("Nota2: %.2f\n",a->nota2);
      printf("Nota3: %.2f\n",a->nota3);
      printf("Media: %.2f\n", (a->nota1+a->nota2+a->nota3)/3);
      printf("\n\n");
      imprimePreOrdem(a->esq);
      imprimePreOrdem(a->dir);
    }
}

void imprimePosOrdem(Arv *a)
{
   if (!vazia(a)) {
      imprimePosOrdem(a->esq);
      imprimePosOrdem(a->dir);
      printf("Matricula:[ %d ]\n",a->info);
      printf("Nome: %s\n",a->nome);
      printf("Nota1: %.2f\n",a->nota1);
      printf("Nota2: %.2f\n",a->nota2);
      printf("Nota3: %.2f\n",a->nota3);
      printf("Media: %.2f\n", (a->nota1+a->nota2+a->nota3)/3);
      printf("\n\n");
    }
}

Arv *busca(Arv *r, int x)
{
   if (r == NULL) return NULL;
   else if (r->info > x) return busca (r->esq, x);
   else if (r->info < x) return busca (r->dir, x);
   else return r;
}
/* Se a árvore for vazia ela é estritamente binária,
se a esquerda for NULL e a direita não ou se a direita
for NULL e a esquerda não, logo a árvore não é estritamente
binária, caso contrátio é.*/

Arv *binaria(Arv *r)
{
    if (r)
    {
       // printf("entrou par verificar filhos\n ");
        if(((!r ->dir)&&(r ->esq)) || (r ->dir)&&(!r ->esq))
	    return 0;
	else
        // printf("entrou para percorrer de novo\n");
	    return binaria(r ->dir) && binaria(r ->esq);
    }
   // printf("terminou aqui");
    return 1;
}
///Soma quantidade de nos
int qtdNos(Arv *r)
{
    if (r)
        return 1 + qtdNos(r->esq) + qtdNos(r->dir);
    else
        return 0;
}
///Soma quantidade de nos folhas
int qtdFolha(Arv *r)
{
    if (r)
    {
        if((!r->esq) && (!r->dir))
	    return 1 + qtdFolha(r->dir) + qtdFolha(r->esq);
	else
	    return 0 + qtdFolha(r->dir) + qtdFolha(r->esq);
    }
    else
        return 0;
}
///Soma valores contidos em cada no
int somaNos(Arv *r)
{
    if (r)
        return r->info + somaNos(r->esq) + somaNos(r->dir);
    else
        return 0;
}
///Soma o no atual com o maior da esquerda ou direita
int altura(Arv *r)
{
    if(r)
    {
        if(altura(r->esq) > altura(r->dir))
            return 1 + altura(r->esq);
	else
            return 1 + altura(r->dir);
    }
    else
       return 0;
}


int vazia(Arv *a)
{
   return a==NULL;
}

int NivelEscalar(Arv*a, int x)
{
    int cont=0;

    if(a== x){
        return cont;
    }
    else if(x > a->info){
        return 1+NivelEscalar(a->dir,x);
        cont = 1+cont;
    }else if(x < a->info){
        return 1+NivelEscalar(a->esq,x);
        cont = 1+cont;
    }
}

int CalculaEscalar(Arv *a, int x)
{
    int nivel;
    if ((busca(a,x))==NULL){
            return NULL;
    }else if(nivel == NivelEscalar(a,x)){
         return pow(2,nivel);
       }
}


Arv *retira (Arv *r, int v)
{
   if (vazia(r))
      return NULL;
   else if (r->info > v)
      r->esq = retira(r->esq, v);
   else if (r->info < v)
      r->dir = retira(r->dir, v);
   else {          ///achou o elemento
      if (r->esq == NULL && r->dir == NULL) { ///elemento sem filhos
         free (r);
         r = NULL;
      }
      else if (r->esq == NULL) {        ///só tem filho à direita
         Arv* t = r;
         r = r->dir;
         free (t);
      }
      else if (r->dir == NULL) {        /// só tem filho à esquerda
         Arv* t = r;
         r = r->esq;
         free (t);
      }
      else {                            /// tem os dois filhos
         Arv* pai = r;
         Arv* f = r->esq;
         while (f->dir != NULL) {  /// encontra o elemento que é o antecessor
            pai = f;
            f = f->dir;
         }
         r->info = f->info;            /// troca as informações
         f->info = v;

         r->esq = retira(r->esq,v); ///retiramos o nó encontrado
      }
   }
   return r;
}

Arv *lerDoArquivo(char path[], Arv *a)
{
    char buf[BUFSIZ];
    Arv aux;
    FILE *arq;
    arq = fopen(path,"r");
    if (arq == NULL)
    {
        return;
    }else{
        while(fgets(buf,BUFSIZ,arq) != NULL)
        {
            fscanf(arq,"%d;%[^;];%f;%f;%f;",&aux.info,aux.nome,&aux.nota1,&aux.nota2,&aux.nota3);
            a = insere(a,aux.info,aux.nota1,aux.nota2,aux.nota3,aux.nome);
        }
        fclose(arq);
    }
    return a;
}
