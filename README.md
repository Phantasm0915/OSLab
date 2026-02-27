# OSLab

A simple repository demonstrating a deadlock/safety check using the Banker's algorithm in C.

## Building and running (C)

Compile the C source with:

```sh
gcc -Wall -o deadlock deadlock.c
```

Execute the program:

```sh
./deadlock
```

It will prompt for the number of processes and resources, the claim (maximum) matrix, the allocation matrix, and the total resource vector. The program then determines if the system state is safe.

## Python version

A Python re‑implementation is available as `deadlock.py`. Run it with:

```sh
python3 deadlock.py
```

The input format and behaviour mirror the C program: enter process/resource counts, claim matrix, allocation matrix, and resource vector. A safety check is performed, and an optional additional request can be simulated.

