
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
     *     We borrowed code from our scheme list lab with makerfile.       *
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

/*Ticket Header File with function prototypes headers, struct definition and 
  macros for length */

//including libraries if necessary
#ifndef __STDIO_H__
#define __STDIO_H__
#endif
#ifndef __STRING_H__
#define __STRING_H__
#endif
#ifndef __STDLIB_H__
#define __STDLIB_H__
#endif
#ifndef __TICKET_HEADER_H__
#define __TICKET_HEADER_H__
#endif

//creating macros to regulate ticket array sizes
#define ID_SIZE 10
#define ERR_SIZE 20
#define STATUS_SIZE 15
#define TECH_SIZE 30

//creating ticket struct
typedef struct ticket ticket_t;
struct ticket{
  int num;
  char identifier[ID_SIZE];
  char err[ERR_SIZE];
  char status[STATUS_SIZE];
  char technician[TECH_SIZE];
  ticket_t * next;
};
  
//declaring addTicket
void
addTicket (ticket_t ** firstPtr, int ticket_number);
/* precondition: firstPtr is an initialized list and ticket_number is an 
     initialized number
   postcondition: will add a ticket to the new list with criteria specified by 
     the user. */

//declaring printMenu
void printMenu();
/* precondition: none
   postcondition: prints a menu of options */

//assigning ticket
void assignTicket(ticket_t ** firstPtr, ticket_t ** firstAssignedPtr);
/* precondition: firstPtr is an initialized list and firstAssignedPtr is anothe 
     initialized list.
   postconditoin: will move the first ticket in the firstPtr list to the 
     firstAssigned Ptr list.*/

//declaring print 
void print(ticket_t * first);
/* precondition: first is an initizlized list
   postcondition: prints a nicely formatted list with all information specified 
     for each ticket */

//prints list of assigned tickets
void printAssigned(ticket_t *firstAssignedPtr);
/* precondition: first is an initizlized list
   postcondition: prints a nicely formatted list with all information specified 
     for each ticket */

//prints list of complete tickets
void printComplete(ticket_t *firstCompletePtr);
/* precondition: first is an initizlized list
   postcondition: prints a nicely formatted list with all information specified 
     for each ticket */

//marks a ticket as complete
void markComplete(int ticket_number, int assigned_tickets, ticket_t ** firstCompletePtr, ticket_t ** firstAssignedPtr);
/* precondition: ticket number and assigned tickets must be initialized numbers,
     and first complete ptr and first assigned ptr must be initialized lists. 
   postcondition: moves a ticket form the assigned list to the complete list.*/
