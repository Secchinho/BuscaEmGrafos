typedef struct nofila
{
    int info;
    struct nofila *prox;
}NoFila;

typedef struct fila{
    NoFila* ini;
    NoFila* fim;
}Fila;

Fila* criarFila();
int estaVazia(Fila *f);
int removerDaFila(Fila* f);
void inserirFila(Fila* f, int v);
void liberarFila(Fila* f);
void imprimeFila(Fila* f);
