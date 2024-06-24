/******************************************************************************************************************************************************
 * 
 * *FILE NAME : myHeader.h
 *
 * *DESCRIPTION : Contains all the HeaderFiles , MACROS , Structures used for CDR APPLICATION
 *
 * *REVISION HISTORY :
 * 
 * *DATE                                             NAME                                 REFERENCE                         REASON              
 * -----------------------------------------------------------------------------------------------------------------------------------------------------
 *  07 APR 2023                                    Group 5                                 new file                          initial
 *******************************************************************************************************************************************************
 *
 * *****************************************************************************************************************************************************
 * <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><>><><><><><>><><<><><><><><><><>><><><<><>
 * ---------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef myHeader_h
#define myheader_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<pthread.h>

#define MAXBUFF 1024
#define PORTNO 65534 
#define MAX_LINE_LENGTH 1024
struct User
{
    char msisdn[20];
    char opbrandname[64];
    char opmmc[20];
    char caltype[10];
	char dur[10];
	char down[10];
	char upload[10];
    char thirdparmsisdn[10];
    char thirdparmmc[10];
};
struct interop
{
	char opmmc[20];
	char opname[20];
	long int incomingcall;
	long int outgoingcall;
	long int incomingsms;
	long int outgoingsms;
	long int downloaded;
	long int uploaded;
}typedef IP;

int signUp(char [],char []);
int logIn(char [],char []);
void dataProcess(struct User *, IP *);
char * customerbilling(struct User *,char []);
char * customerbillingfile(struct User *,char []);
char * interoperatorbilling(IP *,char []);
char * interoperatorbillingfile(IP *);




#endif
