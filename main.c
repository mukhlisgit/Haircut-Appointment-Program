#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//  main.c

//
//  Created by mukhlis bashir hassan on 3.06.2020.
//  Copyright © 2020 mukhlis bashir hassan. All rights reserved.

struct queue //queue struct to record number of people on the queue
{
char person_name[15];             //string character to keep record of people's names
char hairstyle[12];
char hairstyle_cost[10];
int price;
char id[11];                   //unique id number given to each customer
struct queue *next_node;      //struct to be used as next node inside the queue node
}*front, *rear;

//prototypes:
void enqueue(void); // Function used to insert the element into the queue
void dequeue(void); // Function used to delete the elememt from the queue
void display(void); // Function used to display all the elements in the queue according to FIFO(first in first out) rule


int main(int argc, char *argv[]) {
    int choice;
    
    do //all these will be carried out as long as four is not chosen, you will see at the end.
    {
         printf("\nPlease select the following options to continue");
    printf("\n1. Enter 1 to Add a customer to queue \n2. Enter 2 to Remove a customer from  queue\n3. Enter 3 to Display/Save queue \n4. Enter 4 to Exit program \n\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
        
    switch(choice)
    {
    case 1:
    enqueue(); // if the user chooses 1, it will enqueue(ask for people to be added to the queue)
    break;
            
    case 2:
    dequeue(); // if the user chooses 2, it will dequeue(remove the first person to be added from the line)
    break;
            
    case 3:
    display(); // this will display the customers on the queue
    break;
            
    case 4:
    exit(0);  // if the user chooses 4, the program will safely and calmly exit in peace :)
    break;
    default:
    printf("Sorry, invalid choice!\n"); // any other choice chosen will not be accepted!
    break;
    }
    }                      // the program will do all these tasks....
        while(choice!=4); //as long as the choice isn't four.
    
  return 0;
}






void enqueue()
{
    int hairstyle_choice;
    int i,j,k;
    
    struct queue *temp; // this will be used as our  pointer to a single node
   
    
    temp = (struct queue*)malloc(sizeof(struct queue)); // allocating memory according to its own size
    
    printf("Enter the name of the customer: \n");
    scanf("%s",temp->person_name);  // getting input by scanf putting into the node as a string(person_name)

        
    printf("\nchoose the hairstyle of the person:\n1. bald\n2. adam cut\n3. normal\n4.keko cut\n5. custom haircut\n");
    scanf("%d",&hairstyle_choice);  //taking user's choice and inserting it to hairstyele_choice
 
        
        switch (hairstyle_choice)
        {
                
           case 1:
                strcpy(temp->hairstyle, "bald"); //defining bald hairstyle and its price
                temp->price=25;
                break;
           case 2:
                strcpy(temp->hairstyle, "adam cut"); //defining another hairstyle
                temp->price=30;
                break;
           case 3:
                strcpy(temp->hairstyle, "normal cut"); //defining another hairstyle
                temp->price=20;
                break;
           case 4:
                strcpy(temp->hairstyle, "keko cut"); //defining another hairstyle
                temp->price=5;
                break;
            case 5:
             printf("\nEnter the hairstyle for the person:\n"); // letting the user input a custom hairstyle
             scanf("%s",temp->hairstyle);
    
            printf("\nEnter the cost of this hairstyle:\n"); // getting the price for this custom hairstyle
            scanf("%s/n",temp->hairstyle_cost);
                
            temp->price=atoi(temp->hairstyle_cost); //decided to convert the string to an int in case the user adds any string with the number like in "245tl" tl is a string
              break;
              default:
            printf("you did not select the correct option\n");
                break;
                
     }
    
temp->next_node = NULL;            //making the next node NULL
    
if (rear == NULL)                 //if the rear node is empty then:
{
front = rear = temp;            //move the new node which is temp to the rear and eventually to the front
}
    
else                          //if it's not empty then:
{
rear->next_node = temp;     //shifting the node in the rear to the next node to in order create space for our new node temp
rear = temp;               // and simply put temp into the rear
}
    
    srand((unsigned)time(0));
    for(i=0; i<2 ;i++) //generating just one line of random block of numbers (for each customer)
    {
        for(j=0;j<8;j++) //generating 8 digits of random binary numbers
        {
            k=rand()%9;
            temp->id[j]=k+48;
        }
        temp->id[10]='\0';
    }
    
}                         //queue process for enquing new node is done.

void dequeue()
{
struct queue *temp;      // making temp a node, again :)
temp = front;           // making temp the node that is at the front of all other nodes
    
if (front == NULL)     //if there's nothing there then of course the queue is empty
{
printf("Sorry, there's no one on the line sir.\n"); //printing apologies to the user for not having customers.
front = rear = NULL;                               //making sure the node and rear are NULL
}
else                                             //if there is a node present in the front
{
printf("%s has been removed from the line \n", front->person_name);//tell the user the name of the person that was dequeued
front = front->next_node;                                         //moving the next node to the front
free(temp);                                                      //freeing the temp node and thereby deleting it.
}
}

void display()
{
  FILE *file; //creating a file
   file=fopen("/Users/mukhlis/Downloads/SimpleMovieTicketBooking_C Programming/SimpleMovieTicketBookingSystem/mytextfile.txt", "w"); //writing on this file
       
       if (file==NULL) {
           printf("file not found"); //print this if the file is not found
       }
    
 time_t now; // time_t is a time arithmetic type
time(&now);  // time() returns the current time of the system as a time_t value. so we obtain current time
struct tm *local = localtime(&now); //localtime converts a time_t value to calendar time and also returns a pointer to a                                     tm structure with its members filled with the corresponding values
     
struct queue *temp;    //my node.
temp = front;         //front node
int count = 0;
    
if (front == NULL)   //if front node is empty then all the nodes are empty
{
printf("sir, the queue is empty\n");
    fprintf(file, "sir, the queue is empty\n");
}
else
{
printf("These are the customers in line: \n\n");  //if it is not empty then print the following
fprintf(file, "This is the list of customers on queue in order\n\n"); //printing to my file also
while (temp)                                     //while loop for as long as temp exists
{
    
    printf("Name:%s     ID:%s     hairstyle:%s     cost:%dTL     date of appointment:%02d/%02d/%d time:%02d:%02d\n", temp->person_name,temp->id,temp->hairstyle,temp->price,local->tm_mday,local->tm_mon +1,local->tm_year +1900,local->tm_hour+count,local->tm_min);
    //printing the name,hairstyle and price,customer ID, date and time of appointment
   
    fprintf(file,"Name:%s     ID:%s     hairstyle:%s     cost:%dTL     date of appointment:%02d/%02d/%d time:%02d:%02d\n", temp->person_name,temp->id,temp->hairstyle,temp->price,local->tm_mday,local->tm_mon +1,local->tm_year +1900,local->tm_hour+count,local->tm_min); //printing the name,hairstyle and price,customer ID, date and time of appointment into my textfile

temp = temp->next_node;                                         //shifting the node to another node
count++;                                                     //incrementing the count for each loop
} printf("NULL\n");
}
    
    fclose(file);
    getchar();
}
