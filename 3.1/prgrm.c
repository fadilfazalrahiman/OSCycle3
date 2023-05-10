#include<stdio.h>

typedef struct process{

    int pid ;
    int burstTime ;
    int waitingTime ;
    int turnAroundTime ;
    int gntVal ;

}process ;

void FCFS(process ps[], int numberOfProcess){

    int totalTime = 0 ;
    int wtSum = 0 ;
    int tatSum = 0 ;
    for(int i = 0; i < numberOfProcess; i++){
        
        ps[i].waitingTime = totalTime ;
        wtSum += ps[i].waitingTime ;
        ps[i].turnAroundTime = totalTime + ps[i].burstTime ;
        tatSum += ps[i].turnAroundTime ;
        totalTime += ps[i].burstTime ;
        ps[i].gntVal = totalTime ;

    }
    printf("\nProcess\tWaiting Time\tTurn Around Time\n") ;
    for(int i = 0; i < numberOfProcess; i++){

        printf("P%d\t", ps[i].pid) ;
        printf("%d\t\t", ps[i].waitingTime) ;
        printf("%d\n", ps[i].turnAroundTime) ;

    }
    printf("Gantt Chart :- \n") ;
    for (int i = 0; i < numberOfProcess; i++){
        
        printf("|   P%d\t", ps[i].pid) ;

    }    
    printf("|\n0\t") ;
    for (int i = 0; i < numberOfProcess; i++){
        
        printf("%d\t", ps[i].gntVal) ;

    }
    float tp = (float) numberOfProcess / totalTime ;
    printf("\nAverage Waiting time is :- %d \n", wtSum / numberOfProcess ) ;
    printf("Average turn around time is :- %d \n", tatSum / numberOfProcess) ;
    printf("Throughput :-  %.2f \n", tp) ;

}

void SJF(process ps[], int numberOfProcess){

    process  ps1[100] ;
    for(int i = 0 ; i < numberOfProcess ; i++){

        ps1[i] = ps[i] ;

    }
    for(int i = 0 ; i < numberOfProcess - 1; i++){

        for (int j = 0; j < numberOfProcess - i - 1 ; j++){
            
            if(ps1[j].burstTime > ps1[j + 1].burstTime){

                process temp = ps1[j] ;
                ps1[j] = ps1[j + 1] ;
                ps1[j + 1] = temp ;
 
            }

        }
        
    }
    FCFS(ps1, numberOfProcess) ;

}

void main(){

    int numberOfProcesses ;
    printf("Enter The number of Processes :- ") ;
    scanf("%d", &numberOfProcesses) ;
    process prcs[100] ;
    for(int i = 0 ; i < numberOfProcesses; i++){

        prcs[i].pid = i + 1 ;
        printf("Input Burst time of Process %d :- ", i + 1) ;
        scanf("%d", &(prcs[i].burstTime)) ;

    }
    int choice ;
    do{

        printf("Menu\n") ;
        printf("1)FCFS\n2)SJF\n3)Exit\n") ;
        printf("Enter Choice :- ") ;
        scanf("%d", &choice) ;
        switch(choice){

            case 1 :{

                printf("\nFCFS Algorithm :- ") ;
                FCFS(prcs, numberOfProcesses) ;
                break ;
            
            }
            case 2 :{

                printf("\nSJF Algorithm :- ") ;
                SJF(prcs, numberOfProcesses) ;
                break ;

            }
            case 3 :{

                printf("Exit Point\n") ;
                break ;

            }
            default:{

                printf("Enter valid Option\n") ;

            }

        }

    }while(choice != 3) ;

}