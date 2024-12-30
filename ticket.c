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

//including necessary libraries
#include "ticket-header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
main(int argc, char * argv[])
{
  /*pointer to first list item, it's null but it's how we'll build the list*/
  ticket_t * first = NULL;
  int choice;
  int ticket_number = 1;
  int assigned_tickets = 0;
  ticket_t * firstAssigned = NULL;
  ticket_t * firstComplete = NULL;
    
  printf("\nThis program assists the user in ticket-based error tracking.\n\n");

  while(1){
  printMenu();
  printf("Please enter desired option: \n");

  scanf("%d", &choice);
    
  switch(choice){
  case 1: addTicket(&first, ticket_number);
    //create a new tracking ticket
    ticket_number++;
    break;
  case 2: assignTicket(&first, &firstAssigned);
    assigned_tickets++;
    //assign a new ticket to a technician for handling
    break;
  case 3: markComplete(ticket_number, assigned_tickets, &firstComplete, &firstAssigned);
    //Mark a ticket complete
    break;
  case 4: print(first);
    //Print a list of new tickets
    break;
  case 5: printAssigned(firstAssigned);
    //Print a list of assigned tickets
    break;
  case 6:  printComplete(firstComplete);
    //Print a list of completed tickets
    break;
  case 7: printf("Exiting. Thank you for using this program. Have a nice day!\n");
    return 0;
    break;
  default: printf("Please try again with a number 1-7.\n");//for incorrect input
    return 0;
    break;
  }//switch
  }//while

  return 0;
}//main
