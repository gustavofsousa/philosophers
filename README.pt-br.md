<h1 align="center">philosophers</h1>

<p align="center">
  <img src="https://img.shields.io/badge/linguagem-C-blue.svg" alt="Linguagem">
  <img src="https://img.shields.io/badge/42-School-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-completo-brightgreen.svg" alt="Status">
</p>

<p align="center">
  Uma solução para o clássico problema do Jantar dos Filósofos de Dijkstra — explorando programação concorrente com threads e mutexes.
</p>

<p align="center">
  <a href="README.md">🇺🇸 Read in English</a>
</p>

---

## Por que este projeto importa

> "Este projeto me ensinou como sistemas operacionais lidam com concorrência — o que são race conditions, como mutexes as previnem, e por que a ordem em que threads adquirem locks determina se um programa entra em deadlock ou executa corretamente. São exatamente os conceitos por trás de todo backend multi-threaded, todo sistema de transações de banco de dados e toda estrutura de dados concorrente em software de produção."

Bugs de concorrência estão entre os mais difíceis de encontrar e reproduzir em produção. Entender threads, mutexes e prevenção de deadlock nesse nível dá a base para escrever código concorrente seguro e eficiente em qualquer linguagem — goroutines do Go, threads do Java, asyncio do Python ou o modelo de ownership do Rust, todos se baseiam nesses mesmos princípios.

---

## O problema

Proposto por Dijkstra em 1965, o Jantar dos Filósofos é um problema clássico de sincronização:

- `N` filósofos sentam em uma mesa redonda
- Cada filósofo alterna entre **pensar** e **comer**
- Há um garfo entre cada par de filósofos adjacentes
- Para comer, um filósofo precisa dos **dois** garfos adjacentes
- O desafio: projetar uma solução onde nenhum filósofo morre de fome e nenhum deadlock ocorre

![Diagrama dos filósofos](https://github.com/PedroArnaldo/philosophers/blob/main/img/philo.png)

---

## O que foi construído

Uma simulação onde cada filósofo executa como uma **thread** independente, com garfos representados como **mutexes**:

- Cada thread de filósofo faz um loop: pensar → pegar garfos → comer → soltar garfos → dormir
- Uma thread de monitoramento verifica continuamente se algum filósofo excedeu `time_to_die` sem comer
- Mutexes garantem que apenas um filósofo pode segurar um garfo por vez
- A simulação termina quando um filósofo morre ou todos comeram pelo menos `n` vezes

---

## Um detalhe técnico que se destaca

A solução evita deadlock usando uma **ordem de aquisição par/ímpar de garfos**: filósofos de número par pegam o garfo da direita primeiro, enquanto os de número ímpar pegam o da esquerda primeiro. Essa assimetria quebra a condição de espera circular — a causa raiz do cenário clássico de deadlock — sem precisar de um árbitro centralizado ou primitivas de sincronização adicionais. É uma solução limpa, mínima e de nível de produção para um problema fundamental de concorrência.

---

## Como usar

```bash
git clone https://github.com/gustavofsousa/philosophers.git
cd philosophers
make
```

### Executando

```bash
./philo num_de_filosofos tempo_para_morrer tempo_para_comer tempo_para_dormir [num_vezes_deve_comer]
```

| Argumento | Descrição | Unidade |
|---|---|---|
| `num_de_filosofos` | Número de filósofos (e garfos) | — |
| `tempo_para_morrer` | Tempo máximo sem comer antes de morrer | ms |
| `tempo_para_comer` | Tempo que leva para comer | ms |
| `tempo_para_dormir` | Tempo que um filósofo passa dormindo | ms |
| `num_vezes_deve_comer` | (Opcional) Para quando todos comeram essa quantidade | — |

### Exemplos

```bash
# Ninguém deve morrer
./philo 5 900 200 200

# Um filósofo morre
./philo 4 310 200 200

# Para quando todos os filósofos comeram pelo menos 7 vezes
./philo 5 900 200 200 7
```

---

## Referências

- [Problema do Jantar dos Filósofos — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [O Jantar dos Filósofos — Blog Pantuza](https://blog.pantuza.com/artigos/o-jantar-dos-filosofos-problema-de-sincronizacao-em-sistemas-operacionais)
- [Como Threads Funcionam — Blog Pantuza](https://blog.pantuza.com/artigos/o-que-sao-e-como-funcionam-as-threads)

---

## Habilidades demonstradas

- Threads POSIX (`pthread_create`, `pthread_join`, `pthread_detach`)
- Locks de mutex (`pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`)
- Identificação e prevenção de race conditions
- Estratégias de prevenção de deadlock
- Temporização precisa com `usleep` e `gettimeofday`
- Gerenciamento de estado concorrente

---

## Licença

Este projeto foi desenvolvido como parte do currículo da [42 School](https://42.fr).

---

<p align="center">Feito com ☕ na 42 Rio de Janeiro</p>
