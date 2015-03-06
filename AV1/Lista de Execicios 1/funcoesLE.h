typedef struct No{
	int chave;
	int valor;
	struct No* prox;
}TNo;

//Protótipo das funções
TNo *inicializaLista();
TNo *add(TNo *l,int chave, int valor);
TNo *addFinal(TNo *l,int chave, int valor);
void printLE(TNo *l);
int buscaValor(TNo *l, int chave);
TNo *removeNo(TNo *l, int chave);
TNo *criaLE(int chave[], int valor[], int TAM);
int somaLE(TNo *l);


TNo *inicializaLista()
{
    return NULL;
}

//Ex3
TNo *add(TNo* l,int chave, int valor)
{
	TNo *novoNo;
	novoNo = (TNo*)malloc(sizeof(TNo));
	if (!novoNo)
	{
		printf("Nao foi possivel alocar memoria");
		exit;
	}else{
		novoNo->chave = chave;
		novoNo->valor = valor;
		if (l == NULL)
		{
			novoNo->prox = NULL;
		}else{
			novoNo->prox = l;
		}
	}
	return novoNo;
}

//Ex4
TNo *addFinal(TNo *l,int chave, int valor)
{
	TNo *novoNo;
	TNo *aux = l;
	novoNo = (TNo*)malloc(sizeof(TNo));
	novoNo->chave = chave;
	novoNo->valor = valor;
	novoNo->prox = NULL;
	if (!l)
	{
		return NULL;
	}else{
		while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novoNo;
	}
	return l;
}

//Ex5
void printLE(TNo *l)
{
	if (!l)
	{
		printf("\nFim da lista\n\n");
		return;
	}
	else{
		printf("Chave : %d\n",l->chave);
		printf("Valor : %d\n",l->valor);
		printf("-----------\n");
		printLE(l->prox);
	}
}

//Ex6
int buscaValor(TNo *l, int chave)
{
	if(!l)
	{
		printf("Chave nao encontrada\n");
		return -1;
	}else{
		if (l->chave == chave)
		{
			return l->valor;
		}else{
			buscaValor(l->prox,chave);
		}
	}
}

//Ex7
TNo *removeNo(TNo *l, int chave)
{
	TNo *noAnterior, *noAtual;
    noAnterior = noAtual = l;
	if(!l)
	{
		printf("Chave nao encontrada\n");
		return l;
	}else{
		while(noAtual != NULL != noAtual->chave == chave)
        {
            noAnterior = noAtual;
            noAtual = noAtual->prox;
        }
        if (noAtual == NULL)
        {
            return l;
        }else if (noAtual == l)
        {
            l = l->prox;
            free(noAtual);
        }else{
            noAnterior->prox = noAtual->prox;
            free(noAtual);
        }
    return l;
	}
}

//Ex8
TNo *criaLE(int chave[], int valor[], int TAM)
{
	TNo *l = inicializaLista();
	int i;
	for(i=0; i<TAM; i++)
	{
		l = add(l,chave[i],valor[i]);
	}
	return l;
}

//Ex9
int somaLE(TNo *l)
{
	int soma=0;
	if(!l)
	{
		printf("Lista vazia");
		return 0;
	}else{
		while(l != NULL)
		{
			soma += l->valor;
			l = l->prox;
		}
		return soma;
	}
}
