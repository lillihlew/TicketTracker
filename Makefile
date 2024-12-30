# File:          Makefile
# Author:        Lilli Lewis and Martiza Mozo
# Created:       20 April 2008
# Simplified:    27 April 2023
# Acknowledgement:  adapted from an example by Marge Coahran then from Henry Walker
#----------------------------------------------------------------------------
# Use the clang compiler
CC = clang

# Set compilation flags
#   -ansi       check syntax against the American National Standard for C
#   -g          include debugging information
#   -Wall       report all warnings
#   -std=gnu99  use the GNU extensions of the C99 standard
CFLAGS = -ansi -g -Wall -std=gnu99

#----------------------------------------------------------------------------
# build rules:
#
# Each rule takes the following form  (Note there MUST be a tab,
# as opposed to several spaces, preceeding each command.
#
# target_name:  dependency_list
#	command(s)

all: ticket

# List program components, what they depend on, and how to compile or link each

ticket:  ticket.o ticket-header.o
	clang -o ticket ticket.o ticket-header.o 

ticket.o:  ticket.c ticket-header.h
	clang -c ticket.c

ticket-header.o:  ticket-header.c ticket-header.h
	clang -c ticket-header.c 

#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   the built program, object files, old emacs source versions, and core dumps.

clean:
	rm -f list *.o *~ core*
