FILE * abreArquivo(path char[])
{
	FILE *arq;
	arq = fopen(path,"a");
	if (arq != NULL)
		return arq;
	else
		return NULL;
}