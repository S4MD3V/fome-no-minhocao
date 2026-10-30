# Fome no Minhocão

Projeto desenvolvido em **C** para resolver o problema de navegação e busca pelo menor caminho no campus (Minhocão) até o Restaurante Universitário (RU) usando **Busca em Largura (BFS)**.

---

## Sobre o Projeto

São 11h40, a aula de Estrutura de Dados acabou e o objetivo é chegar ao RU antes que a fila cresça. O campus é representado por um grid contendo obstáculos, caminhos livres, o ponto de partida do aluno e o destino final.

O programa processa o mapa, verifica a existência de um trajeto válido e calcula a **rota mínima** necessária para o aluno chegar até a refeição sem se perder.

---

## Funcionalidades e Algoritmo

- **Algoritmo BFS (Breadth-First Search):** Garante a descoberta do caminho mais curto em grafos/grids não ponderados.
- **Mapeamento de Movimentos:** Reconstrói e exibe os passos no formato:
  - `C` — Cima
  - `B` — Baixo
  - `D` — Direita
  - `E` — Esquerda
- **Tratamento de Obstáculos:** Contorna bloqueios no mapa (`@`) e valida os limites da matriz.
- **Respostas de Status:**
  - Imprime `AMEM`, a sequência de passos e a quantidade de movimentos se houver caminho.
  - Imprime `VOU MORRER DE FOME` caso o RU esteja inacessível.

---

## Simbologia do Mapa

| Caractere | Significado |
| :---: | :--- |
| `A` | Ponto de Partida (Aluno) |
| `R` | Destino (Porta do RU) |
| `.` | Caminho livre |
| `@` | Obstáculo / Parede |

---

## Como Executar

### Pré-requisitos
Possuir um compilador C instalado (como `gcc`).

### Compilação e Execução

1. Compile o arquivo:
   ```bash
   gcc fameNoMinhocao.c -o fomeNoMinhocao
