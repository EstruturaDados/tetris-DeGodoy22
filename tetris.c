#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 10
#define PECAS_INICIAIS 5

typedef struct {
    char nome;
    int id;
} Peca;

Peca fila[TAM_FILA];
int inicio = 0;
int fim = 0;
int quantidade = 0;
int contadorID = 0;

Peca gerarPeca() {
    Peca p;
    char tipos[4] = {'I', 'O', 'T', 'L'};
    p.nome = tipos[rand() % 4];
    p.id = contadorID++;
    return p;
}

void enqueue() {
    if (quantidade == TAM_FILA) {
        printf("\nA fila está cheia!\n");
        return;
    }
    Peca nova = gerarPeca();
    fila[fim] = nova;
    fim = (fim + 1) % TAM_FILA;
    quantidade++;
    printf("\nPeça [%c %d] inserida!\n", nova.nome, nova.id);
}

void dequeue() {
    if (quantidade == 0) {
        printf("\nA fila está vazia!\n");
        return;
    }
    Peca jogada = fila[inicio];
    inicio = (inicio + 1) % TAM_FILA;
    quantidade--;
    printf("\nPeça jogada: [%c %d]\n", jogada.nome, jogada.id);
}

void mostrarFila() {
    printf("\n===== FILA DE PEÇAS =====\n");
    if (quantidade == 0) {
        printf("(vazia)\n");
        return;
    }
    int idx = inicio;
    for (int i = 0; i < quantidade; i++) {
        printf("[%c %d] ", fila[idx].nome, fila[idx].id);
        idx = (idx + 1) % TAM_FILA;
    }
    printf("\n==========================\n");
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < PECAS_INICIAIS; i++) {
        enqueue();
    }

    int opc;

    do {
        mostrarFila();

        printf("\n1 - Jogar peça\n");
        printf("2 - Inserir nova peça\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1: dequeue(); break;
            case 2: enqueue(); break;
            case 0: printf("\nSaindo...\n"); break;
            default: printf("\nOpção inválida!\n");
        }

    } while (opc != 0);

    return 0;
}
