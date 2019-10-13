#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void chittagong();//prototypes
void feni();
void akhaura();
void rajshahi();
void ishurdi();
void tangile(); 

void main()
{
	int ch,i,count=0;
	int Day,Month,Year;
	char c;
	for(;;){
		printf("\n\n\t\t\tWELLCOME TO BANGLADESH RAIL-WAY\n");
		{//start date
			struct tm *Sys_T = NULL;
			time_t Tval = 0;
			Tval = time(NULL);
			Sys_T = localtime(&Tval);
			Day=Sys_T->tm_mday;
			Month=Sys_T->tm_mon+1;
			Year=1900 + Sys_T->tm_year;
			printf("\nDate: ");
			printf("%d-", Day);
			printf("%d-", Month);
			printf("%d", Year);
		}//end date();
		printf("\n\nPlease, Enter Your Card");
		getch();
		printf("\n\nEnter Your PIN: ");
		for(i=0;i<4;i++){
			c=getch();
			printf("*");
		}
		system("cls");
		printf("Stations\n--------");
		printf("\n1.Chittagong\n2.Feni\n3.Akhaura\n4.Rajshahi\n");
		printf("5.Ishurdi\n6.Tangile\n\nChose your Destination: ");
		scanf("%d",&ch);
		switch (ch){
		case 1:
			chittagong();
			break;
		case 2:
			feni();
			break;
		case 3:
			akhaura();
			break;
		case 4:
			rajshahi();
			break;
		case 5:
			ishurdi();
			break;
		case 6:
			tangile();
			break;
		default:
			printf("Invalid selection! Try again:\n");
			break;
		}
	}
}//main closed

void chittagong()
{
	int ch,ch2,ac=496,count=0,fst=290,svn=150,seat;
	int static bal=9800;
	char name1[20]="Shubarno Express";
	char name2[20]="Mahanagor Provati";
	char dpt1[20]="Dept time 4:20pm";
	char dpt2[20]="Dept time 8:00am";
	char dst[30]="From-To: Dhaka-Chittagong";
	char seat1[10]="AC Class";
	char seat2[10]="1st Class";
	char seat3[15]="Shovon Chair";
	
	for(;;){
		printf("\n\nCurrent balance: %dTk\n\n1.%s\t\t%s\n2.%s\t\t%s\n",bal,name1,dpt1,name2,dpt2);
		printf("\nEnter your choice(Press 0 to exit): ");
		scanf("%d",&ch);
		
		if(count>4){
			printf("\nYou have Expired!Card ID is Locked.\n");
			break;
		}	
		if(ch==1){
			for(;;){
			int static i=1,j=51,k=121,n=50,p=70,q=150;
			printf("\nClass\t\t\tFare\tAvl\n");
			printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
			printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
			printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to Back): ",seat3,svn,q);
			scanf("%d",&ch2);
			
			if(ch2==1){
				if(bal<ac){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=i;
				i++;
				n--;
				if(n<0){
					n=0;
					printf("Sorry,seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name1,dst,seat1,dpt1,seat,ac);
					bal-=ac;
					printf("-------------------------------------------\n");
				count++;
				break;
				}
			}
			else if(ch2==2){
				if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=j;
				j++;
				p--;
				if(p<0){
					p=0;
					printf("Sorry,seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name1,dst,seat2,dpt1,seat,fst);
					bal-=fst;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==3){
				if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=k;
				k++;
				q--;
				if(q<0){
					q=0;
					printf("Sorry,seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name1,dst,seat3,dpt1,seat,svn);
					bal-=svn;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==0)
			break;
			else
				printf("\nInvalid Input\n");
			}
		}//2nd if close

		else if(ch==2){
			for(;;){
				int static i=1,j=71,k=181,n=50,p=70,q=100;
				printf("\nClass\t\t\tFare\tAvl\n");
				printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
				printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
				printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to Back): ",seat3,svn,q);
				scanf("%d",&ch2);
				if(ch2==1){
					if(bal<ac){
						printf("You don't have sufficient money in your account.\n");
						break;
					}
					seat=i;
					i++;
					n--;
					if(n<0){
						n=0;
						printf("Sorry,seat is not avaiable\n");
					}
					else{
						system("cls");
						printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name2,dst,seat1,dpt2,seat,ac);
						bal-=ac;
						printf("-------------------------------------------\n");
						count++;
						break;
				}
				}
				else if(ch2==2){
					if(bal<fst){
						printf("You don't have sufficient money in your account.\n");
						break;
					}
					seat=j;
					j++;
					p--;
					if(p<0){
						p=0;
						printf("Sorry,seat is not avaiable\n");
					}
					else{
						system("cls");
						printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name2,dst,seat2,dpt2,seat,fst);
						bal-=fst;
						printf("-------------------------------------------\n");
						count++;
						break;
					}
				}
				else if(ch2==3){
					if(bal<svn){
						printf("You don't have sufficient money in your account.\n");
						break;
					}
					seat=k;
					k++;
					q--;
					if(q<0){
						q=0;
						printf("Sorry,seat is not avaiable\n");
					}
					else{
						system("cls");
						printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name2,dst,seat3,dpt2,seat,svn);
						bal-=svn;
						printf("-------------------------------------------\n");
						count++;
						break;
					}
				}
				else if(ch2==0)
					break;
				else
					printf("\nInvalid Input\n");
			}
		}
		else if(ch==0){
			system("cls");
			break;
		}
			else
			printf("\nInvalid Input\n");
}
}//end chittagong
void feni()
{
	int ch,count=0,ch2,ac=365,fst=220,svn=125,seat;
	int static bal=7600;
	char name2[20]="Mahanagor Provati";
	char dpt2[20]="Dept time 8:00am";
	char seat1[10]="AC Class";
	char dst[20]="Dhaka-Feni";
	char seat2[10]="1st Class";
	char seat3[15]="Shovon Chair";
	
	for(;;){
		printf("\nCurren balance: %dTk\n\n1.%s\t\t%s\n",bal,name2,dpt2);
		printf("\nEnter your choice(press '0' to Exit): ");
		scanf("%d",&ch);
		if(count>4){
			printf("\nYou have Expired!Card ID is Locked.\n");
			break;
		}
		else if(ch==1){
			for(;;){
				int static i=51,count,j=251,k=311,n=20,p=30,q=60;
				printf("\nClass\t\t\tFare\tAvl\n");
				printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
				printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
				printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to Back): ",seat3,svn,q);
				scanf("%d",&ch2);
				
				if(ch2==1){
					if(bal<ac){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				count=1;
				seat=i;
				i++;
				n--;
				if(n<0){
					n=0;
					printf("Sorry,seat is not avaiable\n");
					}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name2,dst,seat2,dpt2,seat,fst);
					bal-=ac;
					printf("------------------------------------------\n");
					break;
					count++;
				}				
			}
			else if(ch2==2){
				if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=j;
				j++;
				p--;
				if(p<0){
					p=0;
					printf("Sorry,seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name2,dst,seat3,dpt2,seat,svn);
					bal-=fst;
					printf("------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==3){
				if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=k;
				k++;
				q--;
				if(q<0){
					q=0;
					printf("Sorry,seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name2,dst,seat3,dpt2,seat,svn);
					bal-=svn;
					printf("------------------------------------------\n");
					count++;
					break;
				}
			}
			else if(ch2==0)
			break;
			else
				printf("\nInvalid Input\n");
			}	
		}
		else if(ch==0){
			system("cls");
			break;
		}
		else			
			printf("\nInvalid Input\n");
}
}//end feni
void akhaura()
{
	int ch,ch2,count=0,fst=130,svn=90,seat;
	int static bal=6000;
	char name2[20]="Mahanagor Provati";
	char dpt2[20]="Dept time 8:00am";
	char seat1[10]="AC Class";
	char dst[20]="Dhaka-Akhaura";
	char seat2[10]="1st Class";
	char seat3[15]="Shovon Chair";
	
	for(;;){
		printf("\nCurrent balance: %dTk\n\n1.%s\t\t%s\n",bal,name2,dpt2);
		printf("\nEnter your choice(Press '0' to Exit): ");
		scanf("%d",&ch);
		
		if(count>4){
			printf("\nYou have Expired!Card ID is Locked.\n");
			break;
		}	
		if(ch==1){
			for(;;){
			int static i=1,j=141,k=281,n=0,p=10,q=30;
			printf("\nClass\t\t\tFare\tAvl\n");
			printf("1.%s\t\t----\t%d\n",seat1,n);
			printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
			printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to Back): ",seat3,svn,q);
			scanf("%d",&ch2);
			
			if(ch2==1){
				seat=i;
				i++;
				n--;
				if(n<0){
					n=0;
					printf("Sorry,seat is not avaiable\n");
					}				
			}
			else if(ch2==2){
				if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=j;
				j++;
				p--;
				if(p<0){
					p=0;
					printf("Sorry,seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name2,dst,seat2,dpt2,seat,fst);
					bal-=fst;
					printf("------------------------------------------\n");
					count++;
					break;
				}
			}
			else if(ch2==3){
				if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=k;
				k++;
				q--;
				if(q<0){
					q=0;
					printf("Sorry,seat is not avaiable\n");
					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t\t%s\nSeat no: %d\t\tFare: %dTk\n",name2,dst,seat3,dpt2,seat,fst);
					bal-=svn;
					printf("------------------------------------------\n");
				count++;
				break;
				}
			}
			else if(ch2==0)
			break;
			else
				printf("\nInvalid Input\n");
			}	
		}
		else if(ch==0){
			system("cls");
			break;
		}
		else
			printf("\nInvalid Input\n");
}
}//end akhaira
void rajshahi()
{
	int ch,ch2,count=0,ac=465,fst=285,svn=165,seat;
	int static bal=7500;
	char name1[20]="Silk city";
	char name2[20]="Padma express";
	char dpt1[20]="Dept time 2:40pm";
	char dpt2[20]="Dept time 11:45am";
	char dst[30]="From-To: Dhaka-Rajsahi";
	char seat1[10]="AC Class";
	char seat2[10]="1st Class";
	char seat3[15]="Shovon Chair";
	
	for(;;){
		printf("\nCurrent balance: %dTk\n\n1.%s\t\t%s\n2.%s\t\t%s\n",bal,name1,dpt1,name2,dpt2);
		printf("\nEnter your choice(Press '0' to exit): ");
		scanf("%d",&ch);
		if(count>4){
			printf("You have Expired!Card ID is Locked.");
			break;
			}
	 else if(ch==1){
			for(;;){
			
			int static i=1,j=51,k=171,n=30,p=50,q=70;
			printf("\nClass\t\t\tFare\tAvl\n");
			printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
			printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
			printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to back): ",seat3,svn,q);
			scanf("%d",&ch2);
			
			if(ch2==1){
				if(bal<ac){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=i;
				i++;
				n--;
				if(n<0){
					n=0;
					printf("Sorry, seat is not avaiable\n");
					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name1,dst,seat1,dpt1,seat,ac);
					bal-=ac;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==2){
				if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=j;
				j++;
				p--;
				if(p<0){
					p=0;
					printf("Sorry, seat is not avaiable\n");
					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name1,dst,seat2,dpt1,seat,fst);
					bal-=fst;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==3){
				if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=k;
				k++;
				q--;
				if(q<0){
					q=0;
					printf("Sorry, seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name1,dst,seat3,dpt1,seat,svn);
					bal-=svn;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==0)
			break;
			else
				printf("\nInvalid Input\n");
			}
		}//2nd if close

		else if(ch==2){
			for(;;){
		int static i=1,j=51,k=171,n=30,p=50,q=70;
		printf("\nClass\t\t\tFare\tAvl\n");
		printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
		printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
		printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to Back): ",seat3,svn,q);
		scanf("%d",&ch2);
		
		if(ch2==1){
			if(bal<ac){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
			seat=i;
			i++;
			n--;
			if(n<0){
				n=0;
				printf("Sorry, seat is not avaiable\n");
				
			}
			else{
				system("cls");
				printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name2,dst,seat1,dpt2,seat,ac);
				bal-=ac;
				printf("-------------------------------------------\n");
				count++;
			break;
			}			
		}
		else if(ch2==2){
			if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
			seat=j;			
			j++;
			p--;
			if(p<0){
				p=0;
				printf("Sorry, seat is not avaiable\n");				
			}
			else{
				system("cls");
				printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name2,dst,seat2,dpt2,seat,fst);
				bal-=fst;
				printf("-------------------------------------------\n");
				count++;
			break;
			}			
		}
		else if(ch2==3){
			if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
			seat=k;
			k++;
			q--;			
			if(q<0){
				q=0;
				printf("Sorry, seat is not avaiable\n");
			}
			else{
				system("cls");
				printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name2,dst,seat3,dpt2,seat,svn);
				bal-=svn;
				printf("-------------------------------------------\n");
				count++;
			break;
			}
		}
		else if(ch2==0)
		break;		
		else
			printf("\nInvalid Input\n");
			}
		}
		else if(ch==0){
			system("cls");
			break;
		}
		else
			printf("\nInvalid Input\n");
		
}
}//end rajshahi
void ishurdi()
{
	int ch,ch2,count=0,ac=360,fst=180,svn=130,seat;
	int static bal=7500;
	char name1[20]="Silk city";
	char name2[20]="Padma express";
	char dpt1[20]="Dept time 2:40pm";
	char dpt2[20]="Dept time 11:45am";
	char dst[30]="From-To: Dhaka-Ishurdi";
	char seat1[10]="AC Class";
	char seat2[10]="1st Class";
	char seat3[15]="Shovon Chair";
	
	for(;;){
		printf("\nCurrent balance: %dTk\n\n1.%s\t\t%s\n2.%s\t\t%s\n",bal,name1,dpt1,name2,dpt2);
		printf("\nEnter your choice(Press '0' to exit): ");
		scanf("%d",&ch);
		if(count>4){
			printf("You have Expired!Card ID is Locked.");
			break;
			}
	 else if(ch==1){
			for(;;){
			
			int static i=31,j=105,k=241,n=20,p=35,q=50;
			printf("\nClass\t\t\tFare\tAvl\n");
			printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
			printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
			printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to back): ",seat3,svn,q);
			scanf("%d",&ch2);
			
			if(ch2==1){
				if(bal<ac){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=i;
				i++;
				n--;
				if(n<0){
					n=0;
					printf("Sorry, seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name1,dst,seat1,dpt1,seat,ac);
					bal-=ac;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==2){
				if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=j;
				j++;
				p--;
				if(p<0){
					p=0;
					printf("Sorry, seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name1,dst,seat2,dpt1,seat,fst);
					bal-=fst;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==3){
				if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=k;
				k++;
				q--;
				if(q<0){
					q=0;
					printf("Sorry, seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name1,dst,seat3,dpt1,seat,svn);
					bal-=svn;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==0)
			break;
			else
				printf("\nInvalid Input\n");
			}
		}//2nd if close

		else if(ch==2){
			for(;;){
		int static i=31,j=105,k=241,n=20,p=35,q=50;
		printf("\nClass\t\t\tFare\tAvl\n");
		printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
		printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
		printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to Back): ",seat3,svn,q);
		scanf("%d",&ch2);
		
		if(ch2==1){
			if(bal<ac){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
			seat=i;
			i++;
			n--;
			if(n<0){
				n=0;
				printf("Sorry, seat is not avaiable\n");
				
			}
			else{
				system("cls");
				printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name2,dst,seat1,dpt2,seat,ac);
				bal-=ac;
				printf("-------------------------------------------\n");
				count++;
			break;
			}			
		}
		else if(ch2==2){
			if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
			seat=j;			
			j++;
			p--;
			if(p<0){
				p=0;
				printf("Sorry, seat is not avaiable\n");				
			}
			else{
				system("cls");
				printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name2,dst,seat2,dpt2,seat,fst);
				bal-=fst;
				printf("-------------------------------------------\n");
				count++;
			break;
			}			
		}
		else if(ch2==3){
			if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
			seat=k;
			k++;
			q--;			
			if(q<0){
				q=0;
				printf("Sorry, seat is not avaiable\n");
			}
			else{
				system("cls");
				printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name2,dst,seat3,dpt2,seat,svn);
				bal-=svn;
				printf("-------------------------------------------\n");
				count++;
			break;
			}
		}
		else if(ch2==0)
		break;		
		else
			printf("\nInvalid Input\n");
			}
		}
		else if(ch==0){
			system("cls");
			break;
		}
		else
			printf("\nInvalid Input\n");
		
}
}//end ishurdi
void tangile()
{
	int ch,ch2,count=0,ac=00,fst=125,svn=80,seat;
	int static bal=7500;
	char name1[20]="Silk city";
	char name2[20]="Padma express";
	char dpt1[20]="Dept time 2:40pm";
	char dpt2[20]="Dept time 11:45am";
	char dst[30]="From-To: Dhaka-Tangile";
	char seat1[10]="AC Class";
	char seat2[10]="1st Class";
	char seat3[15]="Shovon Chair";
	
	for(;;){
		printf("\n\nCurrent balance: %dTk\n\n1.%s\t\t%s\n2.%s\t\t%s\n",bal,name1,dpt1,name2,dpt2);
		printf("\nEnter your choice(Press '0' to exit): ");
		scanf("%d",&ch);
		if(count>4){
			printf("You have Expired!Card ID is Locked.");
			break;
			}
	 else if(ch==1){
			for(;;){
			
			int static i=0,j=141,k=291,n=00,p=25,q=30;
			printf("\nClass\t\t\tFare\tAvl\n");
			printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
			printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
			printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to back): ",seat3,svn,q);
			scanf("%d",&ch2);
			
			if(ch2==1){  //choose class
				seat=i;
				i++;
				n--;
				if(n<0){
					n=0;
					printf("Sorry, seat is not avaiable\n");					
				}
			}
			else if(ch2==2){
				if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=j;
				j++;
				p--;
				if(p<0){
					p=0;
					printf("Sorry, seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name1,dst,seat2,dpt1,seat,fst);
					bal-=fst;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==3){
				if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
				seat=k;
				k++;
				q--;
				if(q<0){
					q=0;
					printf("Sorry, seat is not avaiable\n");					
				}
				else{
					system("cls");
					printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name1,dst,seat3,dpt1,seat,svn);
					bal-=svn;
					printf("-------------------------------------------\n");
					count++;
				break;
				}
			}
			else if(ch2==0)
			break;
			else
				printf("\nInvalid Input\n");
			}
		}//2nd if close

		else if(ch==2){
			for(;;){
		int static i=0,j=141,k=291,n=00,p=25,q=30;
		printf("\nClass\t\t\tFare\tAvl\n");
		printf("1.%s\t\t%dTk\t%d\n",seat1,ac,n);
		printf("2.%s\t\t%dTk\t%d\n",seat2,fst,p);
		printf("3.%s\t\t%dTk\t%d\n\nChoice(press '0' to exit): ",seat3,svn,q);
		scanf("%d",&ch2);
		
		if(ch2==1){
			seat=i;
			i++;
			n--;
			if(n<0){
				n=0;
				printf("Sorry, seat is not avaiable\n");				
			}			
		}
		else if(ch2==2){
			if(bal<fst){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
			seat=j;			
			j++;
			p--;
			if(p<0){
				p=0;
				printf("Sorry, seat is not avaiable\n");
				
			}
			else{
				system("cls");
				printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name2,dst,seat2,dpt2,seat,fst);
				bal-=fst;
				printf("-------------------------------------------\n");
				count++;
			break;
			}			
		}
		else if(ch2==3){
			if(bal<svn){
					printf("You don't have sufficient money in your account.\n");
					break;
				}
			seat=k;
			k++;
			q--;			
			if(q<0){
				q=0;
				printf("Sorry, seat is not avaiable\n");
			}
			else{
				system("cls");
				printf("\nPrinting ticket\n\n%s\t%s\n%s\t%s\nSeat no: %d\tFare: %dTk\n",name2,dst,seat3,dpt2,seat,svn);
				bal-=svn;
				printf("-------------------------------------------\n");
				count++;
			break;
			}
		}
		else if(ch2==0)
		break;		
		else
			printf("\nInvalid Input\n");
			}
		}
		else if(ch==0){
			system("cls");
			break;
		}
		else
			printf("\nInvalid Input\n");		
}
}//end tangile
//end function
