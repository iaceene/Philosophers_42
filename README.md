# Philosophers

![iaceene](https://github.com/user-attachments/assets/0f928ba7-46a3-45e6-86bb-d48311a15775)

**Philosophers** : This project is part of the **42 the network**, a unique coding school that focuses on peer-to-peer learning and real-world coding practices. The goal of the Philosophers 42 project is to develop a program that simulates philosophers thinking and eating in a shared environment, inspired by the classical synchronization problem known as the **Dining Philosophers Problem**.

## Project Overview

The Dining Philosophers Problem was formulated by **Edsger Dijkstra** in 1965 and is often used to illustrate synchronization issues in concurrent programming. The problem consists of a set of philosophers sitting around a table. Each philosopher thinks and, when hungry, picks up two forks to eat. Philosophers must not starve, and they should not block each other indefinitely, ensuring a solution that avoids deadlocks and resource starvation.

In this project, you are tasked with writing a program that simulates the philosophers' behavior using threads, mutexes, and semaphores, ensuring synchronization and avoiding deadlock and resource starvation.

## Objective

The main goal is to implement a solution that allows philosophers to:

1. **Think**: Philosophers can think for an arbitrary amount of time.
2. **Eat**: Philosophers can eat for an arbitrary amount of time.
3. **Acquire forks**: Each philosopher needs two forks (mutexes) to eat.
4. **Avoid deadlock**: Philosophers should never be in a state where they are all waiting for a fork (deadlock).
5. **Avoid starvation**: Philosophers should not be prevented from eating for an indefinite period (starvation).

## Requirements

- Use **pthread** (POSIX threads) to implement concurrency in C.
- Use **mutexes** or **semaphores** to protect shared resources.
- The program should simulate philosophers in a circular arrangement where each philosopher can either think or eat.
- The system should properly handle concurrency to ensure philosophers eat, think, and take turns eating without deadlocks or starvation.
- Handle edge cases like when there are very few philosophers or when no philosophers are hungry.
- Ensure all resources are properly cleaned up (e.g., destroying mutexes/semaphores before program termination).

## How It Works

### Structure of the Program:

1. **Philosopher Structure**: Each philosopher is represented by a structure that includes:
   - A unique identifier (e.g., `id`).
   - A state (thinking, eating, waiting).
   - Mutexes for the two forks they need to pick up and eat.
   
2. **Forks**: Each fork is shared between two philosophers and is represented by a mutex to avoid simultaneous access.

3. **Simulation Loop**: Each philosopher operates within a loop that alternates between thinking and eating, with pauses for each action to simulate real-time behavior. Philosophers must pick up forks in a controlled manner, ensuring no deadlocks.

4. **Synchronization**: Using mutexes and semaphores, philosophers must avoid blocking each other indefinitely while ensuring that only two philosophers can eat simultaneously without interference.

### Key Components:

- **pthread_create**: Used to create threads for each philosopher.
- **pthread_mutex_t**: Mutexes are used to protect shared resources (the forks).
- **pthread_join**: Used to wait for threads to finish execution before the program terminates.

## How to Run

1. Clone the repository:

    ```bash
    git clone https://github.com/iaceene/Philosophers_42.git
    cd Philosophers_42
    ```

2. Compile the program:

    ```bash
    make
    ```

3. Run the program:

    ```bash
    ./philosophers <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>
    ```

    Replace `<number_of_philosophers>`, `<time_to_die>`, `<time_to_eat>`, and `<time_to_sleep>` with appropriate values.

    Example:

    ```bash
    ./philosophers 5 800 200 200
    ```

    In this example, there are 5 philosophers, each philosopher must die after 800 milliseconds of not eating, and philosophers will eat and sleep for 200 milliseconds each.

## Requirements for Completion

- The program must ensure that the simulation terminates after a specified amount of time or when all philosophers are able to eat.
- The program should handle edge cases where philosophers do not get a chance to eat due to starvation.
- Proper synchronization techniques should be used to avoid race conditions and ensure the system runs efficiently.

## Resources

For additional information on synchronization and concurrency, you may want to review the following concepts:

- **POSIX Threads (pthreads)**: [https://man7.org/linux/man-pages/man3/pthread_create.3.html](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- **Mutexes and Semaphores**: [https://en.wikipedia.org/wiki/Mutex](https://en.wikipedia.org/wiki/Mutex), [https://en.wikipedia.org/wiki/Semaphore_(programming)](https://en.wikipedia.org/wiki/Semaphore_(programming))
- **Dining Philosophers Problem**: [https://en.wikipedia.org/wiki/Dining_philosophers_problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

## Contributing

If you would like to contribute to this project, feel free to submit pull requests or open issues with suggestions. All contributions are welcome!
