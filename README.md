# van Emde Boas Trees

Bogotá D.C. - Colombia
November 2018

Project for Algorithms and Data Structures course of Applied Mathematics and Computer Science Major at Universidad del Rosario.

The van Emde Boas Tree is an advanced data structure which supports each of the dynamic set operations - <img src="https://latex.codecogs.com/gif.latex?\texttt{INSERT}" title="\texttt{INSERT}" />, <img src="https://latex.codecogs.com/gif.latex?\texttt{REMOVE}" title="\texttt{REMOVE}" />, <img src="https://latex.codecogs.com/gif.latex?\texttt{MEMBER}" title="\texttt{MEMBER}" />, <img src="https://latex.codecogs.com/gif.latex?\texttt{MINIMUM}" title="\texttt{MINIMUM}" />, <img src="https://latex.codecogs.com/gif.latex?\texttt{MAXIMUM}" title="\texttt{MAXIMUM}" />, <img src="https://latex.codecogs.com/gif.latex?\texttt{SUCCESSOR}" title="\texttt{SUCCESSOR}" />, <img src="https://latex.codecogs.com/gif.latex?\texttt{PREDECESSOR}" title="\texttt{PREDECESSOR}" /> -, in <img src="https://latex.codecogs.com/gif.latex?O(\lg&space;\lg&space;u)" title="O(\lg \lg u)" /> time.

## How to use the data structure

### Preliminaries

The data structures implemented here are: 

- <img src="https://latex.codecogs.com/gif.latex?\texttt{proto\_vEB}" title="\texttt{proto\_vEB}" /> : A prototype for the van Emde Boas Tree.
- <img src="https://latex.codecogs.com/gif.latex?\texttt{vEB}" title="\texttt{vEB}" /> : The real van Emde Boas Tree.

You can find the implementations in the respectives folders, the <img src="https://latex.codecogs.com/gif.latex?\texttt{BST}" title="\texttt{BST}" /> (Binary Search Tree) implementations are only used for time testing.

### Doc

## <img src="https://latex.codecogs.com/gif.latex?\texttt{proto\_vEB}" title="\texttt{proto\_vEB}" /> : 
	
  This is a brief summary of the operations implemented in the <img src="https://latex.codecogs.com/gif.latex?\texttt{proto\_vEB}" title="\texttt{proto\_vEB}" />  data structure, we will show the worst-case complexity too:

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{proto\_vEB(u)}" title="\texttt{proto\_vEB(u)}" /> : Constructor, it receives u argument which refers to the universe size.  <img src="https://latex.codecogs.com/gif.latex?O(u)" title="O(u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{min()}" title="\texttt{min()}" /> : Finds and returns the minimum element of the structure.  <img src="https://latex.codecogs.com/gif.latex?$\theta(\lg&space;u)" title="$\theta(\lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{max()}" title="\texttt{max()}" /> : Finds and returns the maximum element of the structure.  <img src="https://latex.codecogs.com/gif.latex?$\theta(\lg&space;u)" title="$\theta(\lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{succ(x)}" title="\texttt{succ(x)}" /> : Finds the successor of the element x.  <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u&space;\lg&space;\lg&space;u)$" title="$O(\lg u \lg \lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{pred(x)}" title="\texttt{pred(x)}" /> : Finds the predecessor of the element x.  <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u&space;\lg&space;\lg&space;u)$" title="$O(\lg u \lg \lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{size()}" title="\texttt{size()}" /> : Returns the number of elements of the structure.  <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{empty()}" title="\texttt{empty()}" /> : Returns 1 if the structure is empty, or 0 otherwise. <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{insert(x)}" title="\texttt{insert(x)}" /> : Inserts element x to the structure. <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u)$" title="$O(\lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{remove(x)}" title="\texttt{remove(x)}" /> : Removes element x of the structure. <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u)$" title="$O(\lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{clear()}" title="\texttt{clear()}" /> : Clears the structure. <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u)$" title="$O(\lg u)$" />

## <img src="https://latex.codecogs.com/gif.latex?\texttt{vEB}" title="\texttt{vEB}" /> : 
	
  This is a brief summary of the operations implemented in the <img src="https://latex.codecogs.com/gif.latex?\texttt{vEB}" title="\texttt{proto\_vEB}" />  data structure, we will show the worst-case complexity too:

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{vEB(u)}" title="\texttt{vEB(u)}" /> : Constructor, it receives u argument which refers to the universe size.  <img src="https://latex.codecogs.com/gif.latex?O(u)" title="O(u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{min()}" title="\texttt{min()}" /> : Finds and returns the minimum element of the structure.  <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{max()}" title="\texttt{max()}" /> : Finds and returns the maximum element of the structure.  <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{succ(x)}" title="\texttt{succ(x)}" /> : Finds the successor of the element x.  <img src="https://latex.codecogs.com/gif.latex?O(\lg&space;\lg&space;u)" title="O(\lg \lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{pred(x)}" title="\texttt{pred(x)}" /> : Finds the predecessor of the element x.  <img src="https://latex.codecogs.com/gif.latex?O(\lg&space;\lg&space;u)" title="O(\lg \lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{size()}" title="\texttt{size()}" /> : Returns the number of elements of the structure.  <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{empty()}" title="\texttt{empty()}" /> : Returns TRUE if the structure is empty, or FALSE otherwise. <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{insert(x)}" title="\texttt{insert(x)}" /> : Inserts element x to the structure. <img src="https://latex.codecogs.com/gif.latex?O(\lg&space;\lg&space;u)" title="O(\lg \lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{remove(x)}" title="\texttt{remove(x)}" /> : Removes element x of the structure. <img src="https://latex.codecogs.com/gif.latex?O(\lg&space;\lg&space;u)" title="O(\lg \lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{clear()}" title="\texttt{clear()}" /> : Clears the structure. <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u)$" title="$O(\lg u)$" />


### Prerequisites

You will need, obviously, C++ compiler. If you wanna use the data structure, you will need both hpp and cpp files of the respective data structure.

You will need to include the hpp file in your main to use the data structure: 
```
#include "vEB.hpp"
```
```
#include "proto_vEB.hpp"
```

### Running the tests

There are a few number of tests, programmed in the respectives main.cpp, this tests compares BST usual data structure and (proto)van Emde Boas Trees.

Linux:

```
g++ -std=c++14 main.cpp
```

```
./a.out
```
This will show you a comparison between the time of the BST operations and (proto)vEB operations.

## How to start

To initialize a new structure of type proto_vEB or vEB you just need to:

```
proto_vEB proto(x); 
```
or

```
vEB proto(x); 
```
## Tools

* C++
* Cormen, Thomas H., Leiserson, Charles E., Rivest, Ronald L. and Stein, Clif-
ford. (2009). Introduction to Algorithms. Tercera edición. MIT Press.

## Authors

* **Samuel Pérez** - *Student* - [BogoCoder](https://github.com/BogoCoder)
* **Nicolás Duque** - *Student* - [nicolasduque-10](https://github.com/nicolasduque-10)

Supervisor: **Prof. Julián Rincón**


## Acknowledgments

* A cool data structure to learn!

