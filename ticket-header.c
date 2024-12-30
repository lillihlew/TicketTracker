
    /***********************************************************************
     * Names: Lilli Lewis and Maritza Mozo                                 *
     * Assignment name: Ticket Tracker                                     *
     *                                                                     *
     * Assignment for 4/28/23                                              *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     We heavily recycled code from namelist.c, which Lilli worked on *
     *     with Declan. We took code from namelist.c that the original     *
     *     author used, as well.                                           *
     *   Help obtained                                                     *
     *     Professor Johnson answered our questions in class.              *
     *     Kevin Johanson, Anthony Sherrell, and Andi Chestovich helped us *
     *        realize we needed a temporary pointer.                       *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Lilli Lewis and Maritza Mozo                           *
     ***********************************************************************/



/*Functions for ticket-tracker*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ticket-header.h"

void printMenu()//prints a menu of user's options
  /* precondition: none
   postcondition: prints a menu of options */
{
  printf("Please enter 1-7 corresponding to an option from the menu below: \n");
  printf("\t1. Create a new tracking ticket \n");
  printf("\t2. Assign a new ticket to a technician for handling\n");
  printf("\t3. Mark a ticket complete\n");
  printf("\t4. Print a list of new tickets\n");
  printf("\t5. Print a list of assigned tickets\n");
  printf("\t6. Print a list of completed tickets\n");
  printf("\t7. Exit the program \n");
}


void
addTicket (ticket_t ** firstPtr, int ticket_number)//adds a ticket to new list
  /* precondition: firstPtr is an initialized list and ticket_number is an 
     initialized number
   postcondition: will add a ticket to the new list with criteria specified by 
     the user. */
{
  ticket_t * newTick = (ticket_t*) malloc (sizeof (ticket_t));
  ticket_t * currPtr;
  ticket_t * prevPtr;
  
  if(newTick == NULL){ //if malloc couldn't allocate space for newTick
    perror("Unable to allocate ticket\n");
    return;
}
  else{
    printf("Please enter company identifier: ");
    scanf("%s", newTick->identifier);
    printf("\nPlease enter error code: ");
    scanf("%s", newTick->err);
    printf("\n");
    strcpy(newTick->status, "new");
    strcpy(newTick->technician, "unassigned");

    /*if list is empty, put newTick at the beginning of the list*/
    if(*firstPtr == NULL){
      newTick->num = ticket_number;
      newTick->next = *firstPtr;
      *firstPtr = newTick;
    }

    /*list is not empty, put newTick at the end of the list*/
    else {
      newTick->num = ticket_number;
      currPtr = (*firstPtr)->next; //set current ticket to search
      prevPtr = *firstPtr; //ticket before current ticket
      while (currPtr != NULL){
        prevPtr = currPtr; //move to next ticket
        currPtr = prevPtr->next; //keep pointer to previous ticket
      }//while
      newTick->next = prevPtr->next;
      prevPtr->next = newTick;
    }//else if (list is not empty)
  }//else if (malloc could allocate space)
  printf("Ticket #%d added to end of list\n", newTick->num);
  return;
}//addTicket


void assignTicket(ticket_t ** firstPtr, ticket_t ** firstAssignedPtr) //assigns ticket to technician and moves ticket to assigned list
  /* precondition: firstPtr is an initialized list and firstAssignedPtr is anothe 
     initialized list.
   postconditoin: will move the first ticket in the firstPtr list to the 
     firstAssigned Ptr list.*/
{
  ticket_t * currPtr;
  ticket_t * tempPtrAssigned = *firstAssignedPtr;
  if (*firstPtr == NULL) //checks if the list of new tickets is null                                   
    {
      printf("No new tickets to be assigned.\n");  
    }
  else
  {
    printf("Please enter the name of the techinician:\n");     
    scanf("%s", (*firstPtr)->technician); //stores user's input into technician    
    strcpy((*firstPtr)->status, "assigned"); //changes status of new ticket to assigned
    printf("New status: %s\n", (*firstPtr)->status);
    printf("Tech's name: %s\n", (*firstPtr)->technician);

    currPtr = *firstPtr;
    *firstPtr = (*firstPtr)->next;
    //currPtr has our item

    if (tempPtrAssigned == NULL) //checks if assigned list is null
      {
         tempPtrAssigned = currPtr; //stores the new assigned ticket as the first item in the list
         tempPtrAssigned->next = NULL;
         *firstAssignedPtr = tempPtrAssigned;
      }
    else {
      ticket_t * curr;
      ticket_t * prev;
      curr = tempPtrAssigned->next;//curr is next item
      prev = tempPtrAssigned;//prev is previous item
      while(curr!=NULL){
        prev=curr;
        curr=prev->next;
      }// at end of loop, curr is null and prev is right before null
      currPtr->next = prev->next;//make currPtr next point to null
      prev->next = currPtr;//make prev next point to item we're putting in

      *firstAssignedPtr = tempPtrAssigned;
    }//else if assigned list isn't null

  }//else if new tickets list isn't null
  return;//returns to main
}//assignTicket


void markComplete(int ticket_number, int assigned_tickets, ticket_t ** firstCompletePtr, ticket_t ** firstAssignedPtr)//marks assigned ticket as complete and switches it to the correct list
/* precondition: ticket number and assigned tickets must be initialized numbers,
     and first complete ptr and first assigned ptr must be initialized lists. 
   postcondition: moves a ticket form the assigned list to the complete list.*/
{
  int search;
  ticket_t * currPtr;
  ticket_t * prevPtr;
  ticket_t * tempPtrAssigned = *firstAssignedPtr;
  ticket_t * tempPtrComplete = *firstCompletePtr;
  int highestTicketNumber = ticket_number;

  
  if (tempPtrAssigned == NULL)
    printf("No assigned tickets to be completed.\n\n");
  
  else {
    printf("Please enter a ticket number: ");
    scanf("%d", &search);//store input as search
    ticket_t * temp;

       if ((search > assigned_tickets)||(search < 1))//covering too high or low
     {
       printf("Ticket %d is not located in the assigned list and cannot be moved to completed.\n", search);
     }
       
       else if (tempPtrAssigned->num == search)//if ticket is first item
      {
        strcpy(tempPtrAssigned->status, "complete");//update status of ticket to complete
        temp = tempPtrAssigned;//our ticket is now in temp
        if (tempPtrAssigned == NULL)
          *firstAssignedPtr = NULL;
        else
          *firstAssignedPtr = tempPtrAssigned->next;
        temp->next = NULL;
        if (tempPtrComplete == NULL){//if complete list was empty
          temp->next = NULL;
          tempPtrComplete = temp;
          *firstCompletePtr = tempPtrComplete;
        }//end if complete list was empty
        else
          {//if complete list was not empty
          ticket_t * current = tempPtrComplete->next;
          ticket_t * previous = tempPtrComplete;
          while (current != NULL){
            previous = current;
            current = previous->next;
          }//at end of this, current will be pointing to null
          previous->next = temp;
          *firstCompletePtr = tempPtrComplete;
        
        }//else if complete list was not empty
      }//end if ticket is first item
    //above handles all cases where we are searching for the first item in the assigned list.
    //below will handle cases where we are looking for a different item.

    else if (search < highestTicketNumber) {
    // else {
      ticket_t * prev;
      ticket_t * curr;

      curr = tempPtrAssigned->next;
      prev = tempPtrAssigned;

    while((curr->num != search) && (curr!=NULL)){
      prev=curr;
      curr=prev->next;
    } //while. at the end, curr is either pointing to NULL or its num is search
    
     if (curr->num == search){//curr has our ticket
      strcpy(curr->status, "complete");//update status of ticket to complete
      // printf("New status: %s\n", curr->status);
      prev->next = curr->next;

      if (tempPtrComplete == NULL) //checks if complete list is null
      {
         tempPtrComplete = curr; //stores the new complete ticket as the first item in the list
         tempPtrComplete->next = NULL;
         *firstCompletePtr = tempPtrComplete;
      }

      else if (curr != NULL){//complete list is not null
        currPtr = tempPtrComplete->next;//currptr is next item
        prevPtr = tempPtrComplete; //prevptr is previous item
        while (currPtr !=NULL){
          prevPtr = currPtr;
          currPtr = prevPtr->next;
        }//at end of loop, currPtr is null and prevptr is right before null
        curr->next = prevPtr->next;//make curr (our item) next point to null
        prevPtr->next = curr;//make prev ptr next pont to the item
        
        *firstCompletePtr = tempPtrComplete;
      }
      *firstAssignedPtr = tempPtrAssigned;
      
     }
     else
       {
         printf("Ticket is not in assigned list.\n");
       }
    }
  }

  
return; //returns to main
} //markComplete


void print(ticket_t *first)//prints list of new tickets
/* precondition: first is an initizlized list
   postcondition: prints a nicely formatted list with all information specified 
     for each ticket */
{
  printf ("The items on the new list are:\n\n");

  for (ticket_t * current = first ; current != NULL ; current = current->next ) {
    printf("Ticket #%d\n", current->num);
    printf("\t Company Identifier:%s\n", current->identifier);
    printf("\t Error:%s\n", current->err);
    printf("\t Status:%s\n", current->status);
    printf("\t Technician:%s\n", current->technician);
  }

  printf ("\nEnd of List\n\n");
  return; //returns to main
}


void printAssigned(ticket_t *firstAssignedPtr)//prints list of assigned tickets
/* precondition: first is an initizlized list
   postcondition: prints a nicely formatted list with all information specified 
     for each ticket */
{
  printf ("The items on the assigned list are:\n\n");

  for (ticket_t * current = firstAssignedPtr ; current != NULL ; current = current->next ) {
    printf("Ticket #%d\n", current->num);
    printf("\t Company Identifier:%s\n", current->identifier);
    printf("\t Error:%s\n", current->err);
    printf("\t Status:%s\n", current->status);
    printf("\t Technician:%s\n", current->technician);
  }

  printf ("\nEnd of List\n\n");
  return; //returns to main
}

void printComplete(ticket_t *firstCompletePtr)//prints list of completed tickets
/* precondition: first is an initizlized list
   postcondition: prints a nicely formatted list with all information specified 
     for each ticket */
{
  printf ("The items on the complete list are:\n\n");

  for (ticket_t * current = firstCompletePtr ; current != NULL ; current = current->next ) {
    printf("Ticket #%d\n", current->num);
    printf("\t Company Identifier:%s\n", current->identifier);
    printf("\t Error:%s\n", current->err);
    printf("\t Status:%s\n", current->status);
    printf("\t Technician:%s\n", current->technician);
  }

  printf ("\nEnd of List\n\n");
  return; //returns to main
}






