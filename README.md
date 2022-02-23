# КДЗ. Экспериментальное сравнение сортировок
### Туракулов Исломбек Улугбекови

### Отчётыч на эту ~~ссанину~~ 


# Sorting Algorithms

Использованы следующие сортировки:

- [Selection Sort](Sort-Algorithms/SelectionSort.cpp)
- [Bubble Sort](Sort-Algorithms/BubbleSort.cpp)
- [Bubble Sort Iverson 1](Sort-Algorithms/BubbleSort.cpp)
- [Bubble Sort Iverson 1 + 2](Sort-Algorithms/BubbleSort.cpp)
- [Insertion Sort](Sort-Algorithms/InsertionSort.cpp)
- [Binary Insertion sort](Sort-Algorithms/InsertionSort.cpp)
- [Counting Sort](Sort-Algorithms/CountingSort.cpp)
- [Radix Sort](Sort-Algorithms/CountingSort.cpp)
- [Merge Sort](Sort-Algorithms/MergeSort.cpp)
- [Quick sort Hoare partition](Sort-Algorithms/QuickSort.cpp)
- [Quick sort Lomuto partition](Sort-Algorithms/QuickSort.cpp)
- [heap sort](Sort-Algorithms/HeapSort.cpp)

## Table of contents

<!--ts-->
* [Алгоритмы сортировки](#sorting-algorithms)
* [Содержание](#table-of-contents)
* [Введение](#getting-started)
    * [Запуск программы](#running-the-program)
    * [Сохранение данных](#saving-data)
    * [Информация в консоле](#input-information)
* [Анализ времени выполнения](#time-complexity-analysis)
    * [O(k+n)](#okn)
    * [O(nlg(n))](#onlgn)
    * [O(n^2)](#on2)
    * [O(n)](#on)
* [Источники](#sources)
<!--te-->

## Getting Started

Инструкции описанные ниже немного помогут вам понять как устроен мой проект. Однако у меня расположены комментарии в коде, всё-таки нужно разнообразие :)
И да, подсказки в проекте написаны на английском, чтобы вдруг не слетела кодировка проверяющего ну или у меня.

### Running the program

1. Откройте проект

    ```
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
    ⣿⠟⠫⢻⣿⣿⣿⣿⢟⣩⡍⣙⠛⢛⣿⣿⣿⠛⠛⠛⠛⠻⣿⣿⣿⣿⣿⡿⢿⣿
    ⣿⠤⠄⠄⠙⢿⣿⣿⣿⡿⠿⠛⠛⢛⣧⣿⠇⠄⠂⠄⠄⠄⠘⣿⣿⣿⣿⠁⠄⢻
    ⣿⣿⣿⣿⣶⣄⣾⣿⢟⣼⠒⢲⡔⣺⣿⣧⠄⠄⣠⠤⢤⡀⠄⠟⠉⣠⣤⣤⣤⣾
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣀⣬⣵⣿⣿⣿⣶⡤⠙⠄⠘⠃⠄⣴⣾⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢻⠿⢿⣿⣿⠿⠋⠁⠄⠂⠉⠒⢘⣿⣿⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⡿⣡⣷⣶⣤⣤⣀⡀⠄⠄⠄⠄⠄⠄⠄⣾⣿⣿⣿⣿⣿⣿   <- Это Шрек
    ⣿⣿⣿⣿⣿⣿⣿⡿⣸⣿⣿⣿⣿⣿⣿⣿⣷⣦⣰⠄⠄⠄⠄⢾⠿⢿⣿⣿⣿⣿   <- красивый?
    ⣿⡿⠋⣡⣾⣿⣿⣿⡟⠉⠉⠈⠉⠉⠉⠉⠉⠄⠄⠄⠑⠄⠄⠐⡇⠄⠈⠙⠛⠋
    ⠋⠄⣾⣿⣿⣿⣿⡿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢠⡇⠄⠄⠄⠄⠄
    ⠄⢸⣿⣿⣿⣿⣿⣯⠄⢠⡀⠄⠄⠄⠄⠄⠄⠄⠄⣀⠄⠄⠄⠄⠁⠄⠄⠄⠄⠄
    ⠁⢸⣿⣿⣿⣿⣿⣯⣧⣬⣿⣤⣐⣂⣄⣀⣠⡴⠖⠈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
    ⠈⠈⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣽⣉⡉⠉⠈⠁⠄⠁⠄⠄⠄⠄⡂⠄⠄⠄⠄⠄
    ⠄⠄⠙⣿⣿⠿⣿⣿⣿⣿⣷⡤⠈⠉⠉⠁⠄⠄⠄⠄⠄⠄⠄⠠⠔⠄⠄⠄⠄⠄
    ⠄⠄⠄⡈⢿⣷⣿⣿⢿⣿⣿⣷⡦⢤⡀⠄⠄⠄⠄⠄⠄⢐⣠⡿⠁⠄⠄⠄⠄⠄
    ```

2. Создать сборку проекта.

3. Запустите программу.

    ```
    <input> -> typed [1] {Selection Sort}
    ```

   Это позволит отсортировать значения из разных режимов. Если все пойдет правильно, вы должны увидеть этот результат.

    ```
    Please wait...
    Progress: 20%
    Progress: 40%
    Progress: 60%
    Progress: 80%
    Progress: 100%
    Done! Files are located to the cmake-build-debug directory
    ```



### Saving data


1. После запуска сортировок(-ки) все данные записываются в  (`cmake-build-debug/...`) с названиями:

    ```
    First.csv
    input - 1.txt
    input - 2.txt
    Second.csv
    ```

   Например при выборе сортирвки пункта `[1]` то есть `Selection Sort` данные записываются в табличном виде в файлах `First` и `Second` с расширением `.csv`


### Input information

После запуска `main.cpp` пользователю отображаются доступные виды сортировок, которые описаны ниже.
Можно использовать как и одну или все сортировку сразу.

```
===== Available sort algorithms =====
[1] - Selection sort
[2] - Bubble sort
[3] - Bubble sort v 1
[4] - Bubble sort v 1 and 2
[5] - Insertion sort
[6] - Binary insertion sort
[7] - Counting sort
[8] - Radix sort
[9] - Merge sort
[10] - QuickSort (Hoare partition)
[11] - QuickSort (Lomuto partition)
[12] - HeapSort
[13] - Choose all sort algorithms
By default program choose - [13]
=================================
Type here: <input>
```

All the possible values for `<input>` is integer.

## Time complexity analysis

Измерение выполнения программы было произведено с следующими характеристиками ноутбука:

```
Процессор:	Intel(R) Core(TM) i5-10300H CPU @ 2.50GHz   2.50 GHz
ОЗУ:	        16,00 ГБ
Тип системы:	64-разрядная операционная система, процессор x64
```
#### Характеристики Windows

```
Выпуск:	        Windows 10 Pro
Версия:	        21H1
Сборка ОС:	19043.1526
Взаимодействие:	Windows Feature Experience Pack 120.2212.4170.0
```

### O(k+n)

Counting and Radix sort top the list when it comes to low execution times, but this comes at a price

Counting sort needs the maximum element beforehand (whose calculation hasn't been taken towards the time complexity, [see this](counting_sort/counting_sort.cpp#L7)) and its space complexity is O(k+n) and I had to limit the input in order to avoid segmentation faults.

Radix sort also has a space complexity of O(k+n) so the input had to be capped as well ([see this](radix_sort/radix_sort.cpp#L11)).

<img src="./figures/O(kn).svg">

### O(nlg(n))

Following the list are std:sort, merge and shell, among others, with a time complexity of O(nlg(n)).

std::sort is a special case since it uses three different sorting algorithms depending on the input data size and depth. For this study, std:sort was using quick sort, which is a special case again because it's time complexity is O(n^2) for the worst case, but its running times are much smaller because it's very easy to be optimized. Check out [this site](https://www.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/analysis-of-quicksort) for more info.


<img src="./figures/O(n lg(n)).svg">


### O(n^2)

At the end of the list we have bubble, insertion, cocktail shaker (double insertion), selection and gnome sorts. These are usually the easiest to implement but the least efficient as well.

For a small number of inputs, the performance difference between O(nlg(n)) and O(n^2) may not look too big as in the image below. For an input array of 250 elements, the difference between the best and the worst algorithms is only around 200 microseconds.

<img src="./figures/all_low_n.svg">

However, as the input size increases, so does the running time. For a 500.000 element input array, the running time goes from 62 milliseconds to 12 minutes...

<img src="./figures/all_high_n.svg">

Does this means we should ALWAYS use a sorting algorithm with a time complexity of O(nlg(n)) instead of O(n^2)? Well, for the majority of cases the answer is yes, but not always. The previous measurements were taken for a random input but in the best-case scenario, the roles are switched.

<img src="./figures/all_sorted_input.svg">

To sum up, what sorting algorithm should be used depends on many different aspects such as input size, input randomness, available RAM and number of CPU/GPU cores available. For example, bitonic is very popular in parallel structures but not so much in single CPU systems. If you are sorting totally random data, merge sort should be fine but if you are inserting a new entry into a sorted database, insertion sort might be the way to go...

And in embedded systems, never forget about the space complexity.


## Sources
 ```
 
 ```