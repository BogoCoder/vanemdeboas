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

<img src="https://latex.codecogs.com/gif.latex?\texttt{proto\_vEB}" title="\texttt{proto\_vEB}" /> : 
	
  This is a brief summary of the operations implemented in the <img src="https://latex.codecogs.com/gif.latex?\texttt{proto\_vEB}" title="\texttt{proto\_vEB}" />  data structure, we will show the worst-case complexity too:

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{proto\_vEB(u)}" title="\texttt{proto\_vEB(u)}" /> : Constructor, it receives u argument which refers to the universe size.  <img src="https://latex.codecogs.com/gif.latex?O(u)" title="O(u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{min()}" title="\texttt{min()}" /> : Finds and returns the minimun element of the structure.  <img src="https://latex.codecogs.com/gif.latex?$\theta(\lg&space;u)" title="$\theta(\lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{max()}" title="\texttt{max()}" /> : Finds and returns the maximum element of the structure.  <img src="https://latex.codecogs.com/gif.latex?$\theta(\lg&space;u)" title="$\theta(\lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{succ(x)}" title="\texttt{succ(x)}" /> : Finds the successor of the element x.  <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u&space;\lg&space;\lg&space;u)$" title="$O(\lg u \lg \lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{pred(x)}" title="\texttt{pred(x)}" /> : Finds the predecessor of the element x.  <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u&space;\lg&space;\lg&space;u)$" title="$O(\lg u \lg \lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{size()}" title="\texttt{size()}" /> : Returns the number of elements of the structure.  <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{empty()}" title="\texttt{empty()}" /> : Returns 1 if the structure is empty, or 0 otherwise. <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{insert(x)}" title="\texttt{insert(x)}" /> : Inserts element x to the structure. <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u)$" title="$O(\lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{remove(x)}" title="\texttt{remove(x)}" /> : Removes element x of the structure. <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u)$" title="$O(\lg u)$" />

<img src="https://latex.codecogs.com/gif.latex?\texttt{vEB}" title="\texttt{vEB}" /> : 
	
  This is a brief summary of the operations implemented in the <img src="https://latex.codecogs.com/gif.latex?\texttt{vEB}" title="\texttt{proto\_vEB}" />  data structure, we will show the worst-case complexity too:

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{proto\_vEB(u)}" title="\texttt{proto\_vEB(u)}" /> : Constructor, it receives u argument which refers to the universe size.  <img src="https://latex.codecogs.com/gif.latex?O(u)" title="O(u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{min()}" title="\texttt{min()}" /> : Finds and returns the minimun element of the structure.  <img src="https://latex.codecogs.com/gif.latex?$\theta(\lg&space;u)" title="$\theta(\lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{max()}" title="\texttt{max()}" /> : Finds and returns the maximum element of the structure.  <img src="https://latex.codecogs.com/gif.latex?$\theta(\lg&space;u)" title="$\theta(\lg u)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{succ(x)}" title="\texttt{succ(x)}" /> : Finds the successor of the element x.  <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u&space;\lg&space;\lg&space;u)$" title="$O(\lg u \lg \lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{pred(x)}" title="\texttt{pred(x)}" /> : Finds the predecessor of the element x.  <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u&space;\lg&space;\lg&space;u)$" title="$O(\lg u \lg \lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{size()}" title="\texttt{size()}" /> : Returns the number of elements of the structure.  <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{empty()}" title="\texttt{empty()}" /> : Returns 1 if the structure is empty, or 0 otherwise. <img src="https://latex.codecogs.com/gif.latex?O(1)" title="O(1)" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{insert(x)}" title="\texttt{insert(x)}" /> : Inserts element x to the structure. <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u)$" title="$O(\lg u)$" />

  - <img src="https://latex.codecogs.com/gif.latex?\texttt{remove(x)}" title="\texttt{remove(x)}" /> : Removes element x of the structure. <img src="https://latex.codecogs.com/gif.latex?$O(\lg&space;u)$" title="$O(\lg u)$" />


### Prerequisites

You will need, obviously, C++ compiler. If you wanna use the data structure, you will need both hpp and cpp files of the respective data structure.

You will need to include the hpp file in your main to use the data structure: 
```
#include "vEB.hpp"
```
```
#include "proto\_vEB.hpp"
```

### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc

