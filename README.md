# Sorting Algorithms in C++

## Description
This C++ program provides implementations of various sorting algorithms, allowing users to compare their efficiency on different datasets. The included sorting algorithms are:

1. Recursive Merge Sort
2. Iterative Merge Sort
3. Bubble Sort
4. Insertion Sort
5. Quick Sort
6. Shell Sort

## File Structure

### sorts.h
Header file containing the declarations of sorting functions and helper functions.

#### Functions
- `Merge`: Merge two sorted halves of a vector.
- `MergeSort`: Recursive merge sort implementation.
- `merge`: Helper function for iterative merge sort.
- `IterativeMergeSort`: Iterative merge sort implementation.
- `BubbleSort`: Bubble sort implementation.
- `InsertionSort`: Insertion sort implementation.
- `QuickSort`: Quick sort implementation.
- `ShellSort`: Shell sort implementation.

### driver.cpp
Main program file that initializes a vector, sorts it using the specified algorithm, and measures the execution time.

#### Functions
- `InitVector`: Initializes a vector with random values.
- `PrintVector`: Prints the elements of a vector.
- `Elapsed`: Calculates the elapsed time in microseconds.

## Usage
Compile the program using a C++ compiler. The program takes command-line arguments as follows:

```bash


## Example
./Sorter QuickSort 1000 Print
