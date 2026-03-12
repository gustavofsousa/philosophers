<h1 align="center">philosophers</h1>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/42-School-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-complete-brightgreen.svg" alt="Status">
</p>

<p align="center">
  A solution to Dijkstra's classic Dining Philosophers problem — exploring concurrent programming with threads and mutexes.
</p>

<p align="center">
  <a href="README.pt-br.md">🇧🇷 Leia em Português</a>
</p>

---

## Why this project matters

> "This project taught me how operating systems handle concurrency — what race conditions are, how mutexes prevent them, and why the order in which threads acquire locks determines whether a program deadlocks or runs correctly. These are the exact concepts behind every multi-threaded backend, every database transaction system, and every concurrent data structure in production software."

Concurrency bugs are among the hardest to find and reproduce in production. Understanding threads, mutexes, and deadlock prevention at this level gives you the foundation to write safe, performant concurrent code in any language — Go goroutines, Java threads, Python asyncio, or Rust's ownership model all build on these same principles.

---

## The problem

Proposed by Dijkstra in 1965, the Dining Philosophers is a classic synchronization problem:

- `N` philosophers sit at a round table
- Each philosopher alternates between **thinking** and **eating**
- There is one fork between each pair of adjacent philosophers
- To eat, a philosopher needs **both** adjacent forks
- The challenge: design a solution where no philosopher starves and no deadlock occurs

![Philosophers diagram](https://github.com/PedroArnaldo/philosophers/blob/main/img/philo.png)

---

## What was built

A simulation where each philosopher runs as an independent **thread**, with forks represented as **mutexes**:

- Each philosopher thread loops: think → take forks → eat → release forks → sleep
- A monitoring thread continuously checks if any philosopher has exceeded `time_to_die` without eating
- Mutexes ensure only one philosopher can hold a fork at a time
- The simulation ends when a philosopher dies or all philosophers have eaten at least `n` times

---

## A standout technical detail

The solution avoids deadlock by using an **even/odd fork acquisition order**: even-numbered philosophers pick up the right fork first, while odd-numbered ones pick up the left fork first. This asymmetry breaks the circular wait condition — the root cause of the classic deadlock scenario — without requiring a centralized arbiter or additional synchronization primitives. It's a clean, minimal, production-grade solution to a fundamental concurrency problem.

---

## Getting Started

```bash
git clone https://github.com/gustavofsousa/philosophers.git
cd philosophers
make
```

### Running

```bash
./philo num_of_philos time_to_die time_to_eat time_to_sleep [num_times_must_eat]
```

| Argument | Description | Unit |
|---|---|---|
| `num_of_philos` | Number of philosophers (and forks) | — |
| `time_to_die` | Max time a philosopher can go without eating | ms |
| `time_to_eat` | Time it takes to eat | ms |
| `time_to_sleep` | Time a philosopher spends sleeping | ms |
| `num_times_must_eat` | (Optional) Stop when all have eaten this many times | — |

### Examples

```bash
# No one should die
./philo 5 900 200 200

# One philosopher dies
./philo 4 310 200 200

# Stop when all philosophers have eaten at least 7 times
./philo 5 900 200 200 7
```

---

## References

- [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [O Jantar dos Filósofos — Pantuza Blog](https://blog.pantuza.com/artigos/o-jantar-dos-filosofos-problema-de-sincronizacao-em-sistemas-operacionais)
- [How Threads Work — Pantuza Blog](https://blog.pantuza.com/artigos/o-que-sao-e-como-funcionam-as-threads)

---

## Skills demonstrated

- POSIX threads (`pthread_create`, `pthread_join`, `pthread_detach`)
- Mutex locks (`pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`)
- Race condition identification and prevention
- Deadlock avoidance strategies
- Precise timing with `usleep` and `gettimeofday`
- Concurrent state management

---

## License

This project was developed as part of the [42 School](https://42.fr) curriculum.

---

<p align="center">Made with ☕ at 42 Rio de Janeiro</p>
