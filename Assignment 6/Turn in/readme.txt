I did quite a bit of extensive reading on threads and multithreading using the TA slides, various websites, and even a few Youtube videos before attempting the homework.
Furthermore, I did a couple mini programs, as advised by my TA, Nandan, to get a better feel of how threads in C work. I wrote the outline of what needs to happen on paper, and followed that outline throughout the entire coding process.

I decided to make scene and nthread variables global in order to allow different threads to have access. I moved the section of my main function that could be divided into different threads into a new function I defined 
and with it moved the variable declarations that were used. In main, I implemented pthread_create in a loop and allowed the user to pass in an argument that is the number of threads to divide the program into and used pthread_join 
for these threads to "wait" for one another. Moreover, I commented out a couple lines from the original main.c file, namely how it printed and error checking for anything other than 1 argument, which both no longer made sense when 
using multithreading. I added a different way of printing using a 3D global array and made it print in the same output format as before.

The issues I ran into were initially neglecting the fact that I needed to include all the other supporting files in when compiling my modified main.c program and later faced issues with the printing of the pixel values. 
I had to change the way the program printed and that required me to create a global array to hold the pixel color values and print them in the same format as before. In my main, I realized that I needed an array to hold the thread ID's
that constantly needed to be updated every time I created a new thread (an iteration of the loop). I would, in turn, pass this value into the 4th argument of my pthread_create function. I learned this when I went back and reviewed
my TA's lecture slides. With the exception of these smaller errors, I did not run into any major issues. 

Using multiple threads, my real-time increased as I added more threads. However, my user-time was either constant (with 1, 2, 4 threads) or actually increased when I implemented 8 threads.
Since the CPU time (use+sys) is across all CPU's, it makes sense that the user-time increases as there is now parallelism happening. It even exceeds the real-time when I use 2 or more threads!

Nonetheless, the real-time always decreased, meaning the program could run faster when it was using parallelism with more threads, meaning it is more efficient than using a single thread.