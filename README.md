<h1 align=”center”> Philosophers </h1>
<p>
The philosophers' dinner was proposed by Dijkstra in 1965 as a synchronization problem. The project aims to solve the philosophers' dinner problem and learn about concurrent programming using threads and mutex.</p>

## Install

```sh
git clone git@github.com:PedroArnaldo/philosophers.git
```


## Usage

1. `cd philosophers && make`
2. `Run the program passing the params`

```js
./philo num_of_philo time_to_die time_to_eat time_to_sleep num_times_must_eat
```

### Examples

```js
./philo 5 900 200 200 7 // Stop when all the philosopher has eaten of least 7 times each
./philo 4 310 200 200   // One philosopher dies
./philo 5 900 200 200 // No one should die
```
![](https://github.com/PedroArnaldo/philosophers/blob/main/img/philo.png)

## References
- [The dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Explanation of philosophers solution](https://blog.pantuza.com/artigos/o-jantar-dos-filosofos-problema-de-sincronizacao-em-sistemas-operacionais)
- [Explanation of how thread works](https://blog.pantuza.com/artigos/o-que-sao-e-como-funcionam-as-threads)
