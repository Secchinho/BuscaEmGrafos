typedef struct nofila
{
    float info;
    struct nofila *prox;
}NoFila;

typedef struct fila{
    NoFila* ini;
    NoFila* fim;
}Fila;

Fila* criarFila();
int estaVazia(Fila *f);
float remover(Fila* f);
void inserirFila(Fila* f, float v);
void liberarFila(Fila* f);
void imprimeFila(Fila* f);
