struct jogada {
	int linha, coluna;
};

typedef struct jogada JOGADA;

void lemapa();
void imprimemapa();
void jogadores(char j1[10], char j2[10]);
void inicio();
JOGADA jogada(char j1[10], char j2[10]);
void atualiza(int x, int y);
int acabou();
int vazia(int x, int y);
int valida(int x, int y);
JOGADA adapta();
int fechoucoluna();
int fechoulinha();
int fechoudiagonal();
JOGADA invalida(int x, int y, char jogador1[10], char jogador2[10]);
int querjogardenovo();
void imprimeparte(char desenho[6][10], int parte);