# MPI Tasks Solutions Repository

This repository contains solved variants of tasks (variants 1 and 4) related to parallel programming using MPI in C++ and the `<mpi.h>` library. Additionally, it includes all types of variants (12 variants) for MPI tasks.

<details>
<summary>Task Descriptions</summary>

### Task 2
1. Each subordinate process has an integer. Send these numbers to the main process using `MPI_Send` and `MPI_Recv`, and print them in the main process. The received numbers should be printed in ascending order of the ranks of the processes that sent them.
2. The main process has a set of floating-point numbers, with the number of numbers equal to the number of subordinate processes. Using `MPI_Send`, send one number to each subordinate process (the first number to process 1, the second to process 2, etc.) and print the received numbers in the subordinate processes.

### Task 3
1. The main process has an integer. Using `MPI_Bcast`, send this number to all subordinate processes and print the received number in them.
2. Each process has an integer N, with one process having N equal to 1 and the others having N equal to 0. The process with N = 1 also has a set of K-1 numbers, where K is the number of processes. Send one of these numbers from this process to the other processes in ascending order of ranks and print the received number in each process.

### Task 4
1. Write a program to determine the approximate time t. The main process has a set of 5 numbers. Using `MPI_Bcast`, send these numbers to all subordinate processes. Each processor sums the received values and multiplies by its number, then sends the result back to the zero processor. Print the received values by the sending processor's number. Also, perform this task without using the `MPI_Bcast` function - use `MPI_Send` and `MPI_Recv` functions and determine the time using `MPI_Wtime`. Compare the results.
2. In the zero process, use a random number generator to form 10 floating-point numbers: `x[k] = cos(k*rand()), k=1,2,…10`. Using `MPI_Bcast`, send these values to other processes, multiply the elements in each process by its number, determine the maximum element in each processor, and send these values to the zero processor.

### Task 5
1. Each process has a set of K+5 integers, where K is the number of processes. Using `MPI_Reduce` for the `MPI_SUM` operation, sum the elements of these sets with the same ordinal number and print the sums in the main process.
2. The MPI process with number 0 inputs an array of 8 integers from the keyboard. Then, using `MPI_Bcast`, send this array to all processes. Each process prints the received data. Sum all elements of the array distributed across the processes using `MPI_REDUCE`, with the result obtained in process 2. Print the calculated value.

### Task 6
Functions `MPI_Isend` and `MPI_Irecv`:
1. Write a program that divides a number n into prime factors. Assign each process one prime number. Pass the number n around the ring of processes, checking its divisibility by the corresponding prime number and reducing (dividing) n if divisible without remainder. If n is not divisible by the prime number, pass the number n unchanged, otherwise pass the obtained new value.
2. Each process has an integer. Using `MPI_Isend` and `MPI_Irecv`, perform a cyclic shift of data with a step of 2 for all processes, sending the number from process 0 to process 2, from process 2 to process 4, etc., and from the last process to process 2. Print the received number in each process.

### Task 7
1. Each process has a floating-point number. Using `MPI_Gather`, send these numbers to the main process and print them in ascending order of the ranks of the processes that sent them (first print the number given in the main process). Find the maximum number and broadcast it to all processors.
2. The MPI process with number 0 inputs an array of 8 integers from the keyboard. Then, using `MPI_SCATTER`, distribute fragments of this array to 4 processes. Each process prints the received data. Sum all elements of the array distributed across the processes using `MPI_REDUCE`, with the result obtained in process 2. Print the calculated value.

</details>

---

# Решенные задачи MPI

Этот репозиторий содержит решенные варианты задач (1 и 4 вариант) по распараллеливанию с помощью MPI в C++ и библиотекой `<mpi.h>`. Дополнительно приложены все виды вариантов (12 вариантов) по задачам MPI.

<details>
<summary>Описание задач</summary>

### Задача 2
1. В каждом подчиненном процессе дано целое число. Переслать эти числа в главный процесс, используя функции `MPI_Send` и `MPI_Recv`, и вывести их в главном процессе. Полученные числа выводить в порядке возрастания рангов переславших их процессов.
2. В главном процессе дан набор вещественных чисел; количество чисел равно количеству подчиненных процессов. С помощью функции `MPI_Send` переслать по одному числу в каждый из подчиненных процессов (первое число в процесс 1, второе — в процесс 2, и т. д.) и вывести в подчиненных процессах полученные числа.

### Задача 3
1. В главном процессе дано целое число. Используя функцию `MPI_Bcast`, переслать это число во все подчиненные процессы и вывести в них полученное число.
2. В каждом процессе дано целое число N, причем для одного процесса значение N равно 1, а для остальных равно 0. В процессе с N = 1 дан также набор из K − 1 числа, где K — количество процессов. Переслать из этого процесса по одному из чисел данного набора в остальные процессы, перебирая ранги получателей в возрастающем порядке, и вывести в каждом из них полученное число.

### Задача 4
1. Написать программу для определения примерного времени t. В главном процессе дан набор из 5 чисел. Используя функцию `MPI_Bcast`, переслать эти числа во все подчиненные процессы. Каждый процессор суммирует полученные значения и умножает на свой номер, затем отправляет результат обратно в нулевой процессор. Вывести на экран полученные значения по номеру переславшего процессора. Также выполните данную задачу без использования функции `MPI_Bcast` — используйте функции `MPI_Send` и `MPI_Recv` и определите время через функцию `MPI_Wtime`. Сравните результаты.
2. На нулевом процессе с помощью датчика случайных чисел сформировать 10 вещественных чисел: `x[k] = cos(k*rand()), k=1,2,…10`. С помощью функции `MPI_Bcast` разослать эти значения остальным процессам, умножить на каждом процессе элементы на его номер, определить максимальный элемент на каждом процессоре и отправить эти значения в нулевой процессор.

### Задача 5
1. В каждом процессе дан набор из K + 5 целых чисел, где K — количество процессов. Используя функцию `MPI_Reduce` для операции `MPI_SUM`, просуммировать элементы данных наборов с одним и тем же порядковым номером и вывести полученные суммы в главном процессе.
2. MPI-процесс с номером 0 вводит с клавиатуры массив из 8 целых чисел. Затем с помощью функции `MPI_Bcast` рассылает этот массив всем процессам. Каждый процесс печатает полученные данные. Произвести сложение всех элементов массива, распределенных по процессам, с помощью функций `MPI_REDUCE` с получением результата на процессе с номером 2. Вычисленное значение распечатать.

### Задача 6
Функции `MPI_Isend` и `MPI_Irecv`:
1. Напишите программу, разбивающую число n на простые множители. Для этого сопоставьте каждому процессу по одному простому числу. Передавайте число n по кольцу процессов коммуникатора, проверяя его делимость на соответствующие простые числа и уменьшая (деля) n в случае делимости без остатка. В случае если n не делится на простое число, то передать число n без изменений, иначе передать полученное новое значение.
2. В каждом процессе дано целое число. С помощью функций `MPI_Isend`, `MPI_Irecv` осуществить для всех процессов циклический сдвиг данных с шагом 2, переслав число из процесса 0 в процесс 2, из процесса 2 в процесс 4, и так далее, и из последнего процесса в процесс 2. В каждом процессе вывести полученное число.

### Задача 7
1. В каждом процессе дано вещественное число. Используя функцию `MPI_Gather`, переслать эти числа в главный процесс и вывести их в порядке возрастания рангов переславших их процессов (первым вывести число, данное в главном процессе). Найти максимальное число и разослать всем процессорам.
2. MPI-процесс с номером 0 вводит с клавиатуры массив из 8 целых чисел. Затем с помощью функции `MPI_SCATTER` рассылает по 4 процессам фрагменты этого массива. Каждый процесс печатает полученные данные. Произвести сложение всех элементов массива, распределенных по процессам, с помощью функций MPI_REDUCE с получением результата на процессе с номером 2. Вычисленное значение распечатать
