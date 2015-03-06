char *lerDoArquivo(FILE *arq)
{
    char str[100];
    fgets(str,100,arq);
    return str;
}