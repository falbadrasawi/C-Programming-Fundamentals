/*
A memory leak occurs when a program that allocates memory 
loses the ability to access the allocated memory, typically
due to failure to properly destroy/free dynamically allocated
memory.
A program's leaking memory becomes unusable,
much like a water pipe might have water leaking out and
become unusable. 
A memory leak may cause a program to occupy more and more memory
as the program runs, which slows program runtime.
Even worse, a memory leak can cause the program to fail if
memory becomes completely full and the program is unable to allocate
additional memory. 

A common error is failing to free allocated memory that is no longer used
resulting in a memory leak. Many programs that are commmonly
left running for long periods, like web browsers, suffer
from known memory leaks
A web seatch for <your-favorite-browser> memory leak will likely result in 
numerous hits
*/

/*
Garbage Collection

Some programming languages, such as Java, use a mechanism called
garbage collection wherein a program's executable includes
automatic behavior that at various intervals finds all unreachable 
allocated memory locations 
(e.g, by comparing all reachable memory with all previously-allocated memory),
and automatically frees such unreachable memory. Some non-standard C implementations also 
include garbage collection. Garbage collection can reduce the impact
of memory leaks at the expense of runtime overhead.
Computer scientists debate whether new programmers should learn 
to explicitly free memory versus letting garbage collection do the work.
*/