#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

// Define the Taxi structure
struct Taxi {
    int id;
    char driver[20];
    char category[20];
    char plate[7];
    char color[20];
    float rate;
    float minCharge;
    char state; // 'A' for available, 'R' for in a ride
    struct Taxi* next; // Self-referential 

}*list; //  a pointer to a linked list of struct Taxi



//void addTripCar() 1
void addTripCar(){

struct Taxi *head = NULL , *current ; 
FILE* fp;
fp = fopen("Taxies.txt", "r");
if( fp == NULL)
//perror("Error opening file\n");
return ;
int numOfLines = 0 ;
int c;
while ((c = getc(fp)) != EOF) 
if( c == '\n' ) numOfLines++;
fclose(fp);

//#############

FILE* ff;
ff = fopen("Taxies.txt", "r"); if( ff == NULL)
return ;
int cc;
while ((cc = getc(ff)) != '\n');// to ignore the header line in file
int i ;
for( i=0;i<numOfLines-1;i++){
struct Taxi *temp = (struct Taxi*) malloc(sizeof(struct Taxi));
 fscanf(ff, "%d %s %s %s %s %f %f ", &(temp->id) , temp->driver , temp->category , temp->plate , temp->color , &(temp->rate) , &(temp->minCharge) );
temp->state = 'A' ;
temp->next = NULL;
if( head == NULL)
{
head = temp ;
current = head ;
}
else
{
current->next = temp ; current = current->next ; }
}// end for

list = head ;
fclose(ff);

}
//______________________________________________________________________


//void setTripCar (char* category, float* rate) 2
void setTripCar(char *category , float *rate) {
if( list == NULL)
{
printf("empty list\n");
 return ;
}

struct Taxi *current = list ;

while( current != NULL){
if( strcmp( current->category , category ) == 0 && current->rate == *rate) {
current->state = 'R' ;
return ; // out of method ( because we want to set first one only)
}
current = current->next ;
}

}
//______________________________________________________________________


//void writeCarsInRide (char* fileName) 3

//______________________________________________________________________


//printList() 4

//______________________________________________________________________



int main() {
   

    

    // Call the function addTripCar to read the content  of the given text file: “Taxies.txt”, 
    addTripCar();
    printf("The Available Trip cars:\n");
    printList();
    printf("--------------------------------------------------------------------------------------------------------------\n");

    int i;
    // Call the function setTripCar with the given information
    char *Categorys[]={"Business","Family","Family","standard","standard"};
    float rates[] = {4.5,5.0,4.0,3.4,5.0};
    for( i = 0 ; i < 5 ; i++)
    setTripCar(*(Categorys+i),(rates+i));

    // Call the function writeCarsInRide to update the txt file with cars in trip.
    char *fileName ="Taxies.txt";
    writeCarsInRide(fileName);

    // Call the function printList to print the cars information
    printf("The Cars in Ride:\n");
    printList();

    
    return 0;
}
