#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "message.h"

int main ( int argc, char** argv ) {
	FILE *make;
	FILE *diary;
	int runs;
	int run = 1; //boolean switch if user enters "Exit"

	make = fopen("make.txt", "a+");
	runs = fgetc(make);
	fclose(make);
	//as of now only holds 1 number which will change every time the 
	//program runs

	if(runs > 0){
		runs += 1;
	}
	else {
		runs += 2;
	}

	make = fopen("make.txt", "w+");
	fputc(runs, make);
	fclose(make);

	char header[] = "Session ";
	char headerNum[(runs % 10)+1];
	char newLine[] = "\r\n";
	sprintf(headerNum, "%d", runs);
	strcat(header, headerNum);
	strcat(header, newLine);

	diary = fopen("Diary.txt", "a"); //opens file and adds new session header
	fputs(header, diary);
	fclose(diary);

	header[11 + (runs % 10)] ='n'; //changes the r in header (from newLine) to an n
	printf("%s",header);
	
	while(run != 0){
		printf("%d. ", messageNum);
		getMessage();
		if (checkMessage() != 0){
			writeMessage();
		}
		else {
			run = 0;
		}
	}
	return 0;
}