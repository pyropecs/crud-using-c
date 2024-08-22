#include <stdio.h>
#include <stdlib.h>
struct task{
    char task_name[100];
    int due_date;
    int task_number;
    

};

struct task tasks[100];
int current= 0;


void create_task(){
    if(current > 100){
        printf("you cant have task more than 100 tasks \n");
        exit(1);
    }
    printf("enter the task:");
    scanf("%s",tasks[current].task_name);
    
    printf("\nenter the number of days to complete:");
    scanf("%d",&tasks[current].due_date);
    
    tasks[current].task_number = current;
    current++;
    printf("task created successfully");
}


void read_task(){
 
   if(current ==0){
       printf("there is no task");
       exit(0);
   }

    for(int i=0;i<current;i++){
        printf("task number:%d \n",tasks[i].task_number);
        printf("task:%s \n",tasks[i].task_name);
        printf("due date:%d \n",tasks[i].due_date);
        printf("----- \n");
    }
    
}

void update_task(){
       int task_number;
           if(current == 0){
    printf("there is no task yet to be updated");
    exit(1);
}
            printf("enter the task number that should be updated:");
            scanf("%d",&task_number);
    if(task_number <0){
        printf("invalid task number");
        exit(1);
    }
    if(task_number > current){
        printf("given task number exceeds the number of tasks present in it ");
        exit(1);
    }
    printf("enter the task:");
    scanf("%s",tasks[task_number].task_name);
    printf("\nenter the number of days to complete:");
    scanf("%d",&tasks[task_number].due_date);
    printf("task number %d updated successfully",task_number);
    
}

void delete_task(){
    int task_number;
    if(current == 0){
    printf("there is no task yet to be deleted");
    exit(1);
}
    printf("enter the task number that should be deleted:");
    scanf("%d",&task_number);
    if(task_number < 0 ){
        printf("invalid task number");
    exit(1);
        
    }
     if(task_number > current){
        printf("given task number exceeds the number of tasks present in it ");
        exit(1);
    }

    for(int i=task_number;i<current;i++){
        tasks[i] = tasks[i+1];
        tasks[i].task_number = tasks[i].task_number -1;
    }
    current--;
    printf("task deleted successfully");
}

int main(){
    int choice;
   while(choice !=5){
           printf("\nCrud Choices\n");
    printf("1. Create Task\n");
    printf("2. Read Task\n");
    printf("3. Update Task\n");
    printf("4. Delete Task\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
       
       scanf("%d",&choice);
    switch(choice){
        case 1:
            create_task();
            break;
        case 2:
            read_task();
            break;
        case 3:
         
            update_task();
            break;
        case 4:
          
            delete_task();
            break;
        case 5:
        printf("program exited successffully");
        return 0;
        default:
                printf("Choice didnt exist \n");

    }
   }
}


