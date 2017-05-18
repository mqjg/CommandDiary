#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define buff 100
char a[buff];
int messageNum = 1;

void getMessage() {
	fgets(a, buff, stdin);
}

void writeMessage() {
	//char b[buff + (messageNum % 10)+1 + 6]; //adds space for message number a period, a space and \r\n
	char b[(messageNum % 10) + 1 + 2];
	FILE *fp;

	sprintf(b, "%d. ", messageNum); //adds message number to line & period.
	strcat(b,a);
	strcat(b, "\r\n");

	fp = fopen("Diary.txt", "a"); //opens file
	fputs(b, fp);
	fclose(fp);

	messageNum += 1;
}

int checkMessage() {
	char c[5] = {'E','x','i','t','\n'};
	return strcmp(a,c);
}

