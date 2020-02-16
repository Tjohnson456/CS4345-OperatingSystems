/*
CS-4345 Operating Systems
Spring-2020
Prof Chakraborty
Assignment 1

Steven Eiduk
Tamikal Johnson
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main() {

    int entry;

    printf("Enter a positive integer: ");
    scanf("%d", &entry);

    if (entry<0) {
        printf("Enter a valid positive integer: ");
        scanf("%d", &entry);
    }

    pid_t procid;
    procid = fork();

    if(procid>0){
        printf("Parent's id is = %d\n", getpid());
        printf("Parent will wait until child finishes.\n");
        wait(NULL); // The wait() system call will force parent to wait
        printf("\nParent resumes as child completed.\n");
        printf("Patent done!\n\n");
    }
    else if(procid==0){
        printf("Child process id = %d\n", getpid());
        printf("\nChild executing\n");
        
    }
    else{
       fprintf(stderr, "Forking failed.. code terminating");
       return 1; 
    }


    return 0;
}


//This is the code that does the computation.
//I am still working on configuring it into the main code.
/*
int collatz(unsigned int n) {
  int count = 0;
  while(n != 1) {
    if(n % 2 == 0) {
      n /= 2;
    } else {
      n = (3 * n) + 1;
    }
    count++;
  }
  return count;

} */