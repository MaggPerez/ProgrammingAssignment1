#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void userMemoryAllocation(int array[], int size){
    srand(time(0));

    int total_memory_available = 160 * 100;
    int starting_address = 2000;
    int process_number = 1;
    int pages_used = 0;

    //For loop using random num generator
    while(pages_used < size){
        //Generating random number between 1 to 30
        int randNum = (rand() % 30) + 1;
        int processSize = (randNum * 80);


        //Finding number of memory pages required to store the process in the memory
        int memory_pages = (processSize + 159) / 160;


        //Checking if there are enough pages left
        if(pages_used + memory_pages > size){
            printf("Not enough memory for process %d. Terminating.\n", process_number);
            break;
        }


        //Allocate pages to the process
        for(int i = 0; i < memory_pages; i++){
            array[pages_used + i] = process_number;
        }
        pages_used += memory_pages;

        

        //Total of memory allocated
        int allocated_memory = (memory_pages * 160);

        //Unused Memory
        int unused_memory = (allocated_memory - processSize);




        //Process details
        printf("Process Id %d\n:", process_number);
        printf("Starting Memory Address: %d\n", starting_address);
        printf("Size of the Process MB: %d\n", processSize);
        printf("Unused Memory Space MG: %d\n", unused_memory);

        //Updating starting address for the next process
        starting_address += allocated_memory;

        //Incrementing process number
        process_number++;




    }

    
}

int main(){
    int elements[100];
    int size = sizeof(elements) / sizeof(elements[0]);

    userMemoryAllocation(elements, size);


    return 0;
}