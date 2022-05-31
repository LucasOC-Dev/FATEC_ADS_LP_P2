//Definindo Structs
struct atividade{
    int codigo;
    int prior;
    char tarefa[34];
    int diasEsti;
    char dataFim[11];
    char status[17];
};
typedef struct atividade Ativ;

void inicializar(Ativ *p[], int tamanho);

void cadastrar(Ativ *p[], int posicao);

void buscar(Ativ *p[],int tamanho);

void alterar(Ativ* p[], int tamanho);

int menuAlt(void);

void listar(Ativ *p[], int tamanho);

void listarOrdem(Ativ* p[], int tamanho);

void imprimir(Ativ *p);

void excluir(Ativ* p[], int tamanho);
