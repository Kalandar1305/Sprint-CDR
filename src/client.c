#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

//MACROS
#define PORTNO 65534 
#define MAXBUFF 1024


int main()
{
	int sfd = 0, retValue=0;

	int fflag=0;
	

	struct sockaddr_in serv_address;

	char msg[MAXBUFF] = {0,};

	sfd = socket(AF_INET,SOCK_STREAM,0);

	if(sfd < 0)
	{
		perror("socket() ");
		exit(EXIT_FAILURE);
	}
	printf("\nSocket created\n");

	memset(&serv_address,'\0',sizeof(serv_address));

	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	retValue = connect(sfd,(struct sockaddr *)&serv_address, sizeof(serv_address));

	if(retValue < 0)
	{
		perror("connect()");
		exit(EXIT_FAILURE);
	}

	printf("\nClient connected to the server\n");

	while(1)
	{
		system("clear");
		bzero(msg,MAXBUFF);
		printf("------------------> CALL DATA RECORD <------------------\n");
		printf("\n\n1. Signup\n2. Login\n3. exit\nchoice: ");

		bzero(msg,MAXBUFF);
		scanf("%s",msg);
		if(atoi(msg)==1)
		{
			write(sfd,msg,strlen(msg));
			bzero(msg,MAXBUFF);
			read(sfd,msg,MAXBUFF);
			printf("\n\n%s ",msg);
			bzero(msg,MAXBUFF);
			scanf("%s",msg);
			write(sfd,msg,strlen(msg));
			bzero(msg,MAXBUFF);
			read(sfd,msg,MAXBUFF);
			printf("\n%s ",msg);
			bzero(msg,MAXBUFF);
			scanf("%s",msg);
			write(sfd,msg,strlen(msg));
			bzero(msg,MAXBUFF);
			read(sfd,msg,MAXBUFF);
			if(strcmp(msg,"1")==0)
			{
				printf("\n\nSign up successful!\n\n");
				printf("\nPlease login now!\n\n");
			}
			else
			{
				printf("\n\nSign up failed!\n\n");
			}
			sleep(3);
		}
		else if(atoi(msg)==2)
		{
			write(sfd,msg,strlen(msg));
			bzero(msg,MAXBUFF);
			read(sfd,msg,MAXBUFF);
			printf("\n\n%s ",msg);
			bzero(msg,MAXBUFF);
			scanf("%s",msg);
			write(sfd,msg,strlen(msg));
			bzero(msg,MAXBUFF);
			read(sfd,msg,MAXBUFF);
			printf("\n%s ",msg);
			bzero(msg,MAXBUFF);
			scanf("%s",msg);
			write(sfd,msg,strlen(msg));
			bzero(msg,MAXBUFF);
			read(sfd,msg,MAXBUFF);
			if(atoi(msg)==1)
			{
				printf("\n\nLog in successful!\n\n");
				sleep(3);
				while(1)
				{
					system("clear");
					printf("\n---------------> PROCESSING MENU <----------------");
					printf("\n\n1.Process CDR file\n2.Print/Search for Billing Information\n3.Logout\nchoice:");
					bzero(msg,MAXBUFF);
					scanf("%s",msg);
					if(atoi(msg)==1 || atoi(msg)==2)
					{
						if(atoi(msg)==1)
						{
						
							write(sfd,msg,strlen(msg));
							read(sfd,msg,MAXBUFF);
							if(atoi(msg)==1)
							{
								fflag=1;
								printf("\n\nProcessing data successful!\n\n");
								sleep(3);
							}
							else if(atoi(msg)==2)
							{
								printf("\n\nFailed to process the data!\n\n");
								sleep(3);
							}
							else
							{
								fflag=1;
								printf("\n\nData already processed!\n\n");
								sleep(3);
							}
						}
						else
						{
							if(fflag==0)
							{
								printf("\n\nPlease process the data first!\n\n");
								sleep(3);
							}
							else
							{
								write(sfd,msg,strlen(msg));
								bzero(msg,MAXBUFF);
								read(sfd,msg,MAXBUFF);
								printf("%s",msg);
								bzero(msg,MAXBUFF);
								scanf("%s",msg);
								if(atoi(msg)==1)
								{
									write(sfd,msg,strlen(msg));
									bzero(msg,MAXBUFF);
									read(sfd,msg,MAXBUFF);
									system("clear");
									printf("%s",msg);
									bzero(msg,MAXBUFF);
									scanf("%s",msg);
									write(sfd,msg,strlen(msg));
									if(atoi(msg)==1)
									{
										bzero(msg,MAXBUFF);
										read(sfd,msg,MAXBUFF);
										printf("%s ",msg);
										bzero(msg,MAXBUFF);
										scanf("%s",msg);
										write(sfd,msg,strlen(msg));
										bzero(msg,MAXBUFF);
										read(sfd,msg,MAXBUFF);
										if(strcmp(msg,"User not exist!")==0)
										{
											printf("\n\nUser not exist!\n\n");
											sleep(3);
										}
										else
										{
											system("clear");
											printf("\n\nCustomer Billing:\n");
											printf("\n\n%s\n\n",msg);
											sleep(10);
										}
									}	
									else if(atoi(msg)==2)
									{
										bzero(msg,MAXBUFF);
										read(sfd,msg,MAXBUFF);
										printf("%s ",msg);
										bzero(msg,MAXBUFF);
										scanf("%s",msg);
										write(sfd,msg,strlen(msg));
										bzero(msg,MAXBUFF);
										read(sfd,msg,MAXBUFF);
										if(strcmp(msg,"failed")==0)
										{
											printf("\n\nFailed!\n\n");
											sleep(3);
										}
										else
										{
											system("clear");
											printf("\n\nCustomer Billing file Downloaded successfully!\n\n");
											sleep(5);
										}
									}
									else
									{
										printf("\n\nWrong choice!\n\n");
										sleep(3);
									}
								}
								else if(atoi(msg)==2)
								{

									write(sfd,msg,strlen(msg));
									bzero(msg,MAXBUFF);
									read(sfd,msg,MAXBUFF);
									system("clear");
									printf("%s",msg);
									bzero(msg,MAXBUFF);
									scanf("%s",msg);
									write(sfd,msg,strlen(msg));
									if(atoi(msg)==1)
									{
										bzero(msg,MAXBUFF);
										read(sfd,msg,MAXBUFF);
										printf("%s ",msg);
										bzero(msg,MAXBUFF);
										scanf("%s",msg);
										write(sfd,msg,strlen(msg));
										bzero(msg,MAXBUFF);
										read(sfd,msg,MAXBUFF);
										if(strcmp(msg,"Inter operator not found!")==0)
										{
											printf("\n\nInter operator not Found!\n\n");
											sleep(3);
										}
										else
										{
											system("clear");
											printf("\n\nInter operator Billing:\n");
											printf("\n\n%s\n\n",msg);
											sleep(10);
										}
									}
									else if(atoi(msg)==2)
									{
										bzero(msg,MAXBUFF);
										read(sfd,msg,MAXBUFF);
										if(strcmp(msg,"no")==0)

										{
											printf("\n\nFailed!\n\n");
											sleep(3);
										}
										else
										{
											system("clear");
											printf("\n\nInter operator Billing Downloaded Successful!\n\n");
											sleep(5);
										}
									}
									else
									{
										printf("\n\nWrong choice!\n\n");
										sleep(3);
									}
								}
								else
								{
									printf("\n\nWrong choice!\n\n");
									bzero(msg,MAXBUFF);
									sleep(3);
								}
							}
						}
					}
					else if(atoi(msg)==3)
					{
						write(sfd,msg,MAXBUFF);
						printf("\n\nLog out successful!\n\n");
						bzero(msg,MAXBUFF);
						sleep(3);
						system("clear");
						break;
					}
					else
					{
						printf("\n\nWrong choice!\n\n");
						sleep(3);
						bzero(msg,MAXBUFF);
						system("clear");
					}
				}
			}
			else
			{
				printf("\n\nLogin failed!\n\n");
				sleep(3);
				bzero(msg,MAXBUFF);
				system("clear");
			}
		}
		else if(atoi(msg)==3)
		{
			write(sfd,msg,strlen(msg));
			printf("\n\nThankyou!\n\n");
			system("clear");
			close(sfd);
			break;
		}
		
		else
		{
			bzero(msg,MAXBUFF);
			printf("\n\nWrong choice!\n\n");
			sleep(3);
			system("clear");
		}
	}	

	return 0;
}

