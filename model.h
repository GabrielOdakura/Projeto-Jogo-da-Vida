//define valores para uso mais facil
#define MAX 60

//pre-definir funcoes
int carregarMatriz(int mesa[MAX][MAX]);
void colocarPadrao(int mesa[MAX][MAX], int, int);
void colocarSerVivo(int [MAX][MAX], int, int, int);
void delay(int velocidadeSimulacao);
void delayIndefinido();
void inicializarMapa(int [MAX][MAX], int [MAX][MAX], int);
int salvarMatriz(int mesa[MAX][MAX], int);
void simularCelulas(int mesa[MAX][MAX], int mesaaux[MAX][MAX], int);
