#include<stdio.h>
#include<stdbool.h>
int time = 0 ;
typedef struct process{

    int pid ;
    int arrivalTime ;
    int burstTime ;
    int timeLeft ;
    int waitingTime ;
    int turnAroundTime ;
    int gntVal ;
    int completed ;

}process ;

void nonPremptive(process ps[], int numberOfProcesses){

    for(int i = 0 ; i < numberOfProcesses - 1; i++){

        for (int j = 0; j < numberOfProcesses - i - 1 ; j++){
            
            if(ps[j].arrivalTime > ps[j + 1].arrivalTime){

                process temp = ps[j] ;
                ps[j] = ps[j + 1] ;
                ps[j + 1] = temp ;                

            }

        }

    }
    int totalTime = ps[0].burstTime ;
    ps[0].gntVal = ps[0].burstTime ;
    int i = 0 ;
    int j = 0 ;
    while(i < numberOfProcesses){

        if(i >= numberOfProcesses){

            break ;

        }
        j = i + 1 ;
        while(ps[j].arrivalTime <= totalTime){

            j++ ;

        }
        i++ ;
        for(int k = i ; k < j - 1 ; k++){

            for(int l = i ; l < j - k ; l++){

                if(ps[l].burstTime > ps[l + 1].burstTime){

                    process temp = ps[l] ;
                    ps[l] = ps[l + 1] ;
                    ps[l + 1] = temp ;                

                }

            }

        }
        totalTime += ps[i].burstTime ;

    }
    int wtSum = 0 ;
    int tatSum = 0 ;
    totalTime = ps[0].arrivalTime ;
    for(int i = 0; i < numberOfProcesses; i++){
        
        ps[i].waitingTime = totalTime - ps[i].arrivalTime ;
        wtSum += ps[i].waitingTime ;
        ps[i].turnAroundTime = totalTime + ps[i].burstTime ;
        tatSum += ps[i].turnAroundTime ;
        totalTime += ps[i].burstTime ;
        ps[i].gntVal = totalTime ;

    }
    printf("\nProcess\tWaiting Time\tTurn Around Time\n") ;
    for(int i = 0; i < numberOfProcesses; i++){

        printf("P%d\t", ps[i].pid) ;
        printf("%d\t\t", ps[i].waitingTime) ;
        printf("%d\n", ps[i].turnAroundTime) ;

    }
    printf("Gantt Chart :- \n") ;
    for (int i = 0; i < numberOfProcesses; i++){
        
        printf("|   P%d\t", ps[i].pid) ;

    }    
    printf("|\n%d\t", ps[0].arrivalTime) ;
    for (int i = 0; i < numberOfProcesses; i++){
        
        printf("%d\t", ps[i].gntVal) ;

    }
    float tp = (float) numberOfProcesses / totalTime ;
    printf("\nAverage Waiting time is :- %.2f \n", (float) wtSum / numberOfProcesses ) ;
    printf("Average turn around time is :- %.2f \n", (float) tatSum / numberOfProcesses ) ;
    printf("Throughput :-  %.2f \n", tp) ;

}

void main(){

    int numberOfProcesses ;
    printf("Enter The number of Processes :- ") ;
    scanf("%d", &numberOfProcesses) ;
    process prcs[100] ;
    for(int i = 0 ; i < numberOfProcesses; i++){

        prcs[i].pid = i + 1 ;
        printf("Input Arrival time of Process %d :- ", i + 1) ;
        scanf("%d", &(prcs[i].arrivalTime)) ;
        printf("Input Burst time of Process %d :- ", i + 1) ;
        scanf("%d", &(prcs[i].burstTime)) ;
        time += prcs[i].burstTime ;

    }
    nonPremptive(prcs, numberOfProcesses) ;

}