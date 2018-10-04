#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


unsigned randomPos(char * array);

unsigned getSize(char * array);

unsigned compareChar(char * array, char c);

char selectChar(char array []);

void printString(char * array);


//select a char from that position we got before in the random pos func
//making sure that that char isn't used more than once in our new password
void printPass (char *);
void build_Pass(char letters [], unsigned size);


int main(){
	srand((unsigned) time(0));


	char * completecharset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_-+=|\\/<>:;";
	char * onlyalphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	char * charset1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@.-_";			

	//unsigned size = getSize(alphanums);
	//unsigned size = getSize(onlalphanums);
	//debug
	//printf("the size of alphanums is: %d\n", size);			
	//char selected = selectChar(alphanums, randomPos(alphanums));
	unsigned pwsize = 10;
	printf("Printing passwords with all chars used: \n");
	build_Pass(completecharset, pwsize);
	
	printf("Printing passwords with only letters and nums used: \n");

	build_Pass(onlyalphanum, pwsize);
	
	printf("Printing passwords with chars '@', '-', '_', '.', letters and nums used: \n");

	build_Pass(charset1, pwsize);

	return 0;
}

//get size of string of chars to choose
//from and choose a random place to start from in the array.

unsigned randomPos(char * array){
	

	unsigned position;
	position = rand() % getSize(array)-1;
	return position;
}

unsigned randomNum( unsigned a){
	unsigned aNum;
	srand((unsigned) time(0));
	
	aNum = rand() % 1000;
	

}
unsigned getSize(char * array){

char * ptr = array;
unsigned count =0; 
	
	//debug  printf("first char is: %c\n", *ptr);
	//printf("\nIN GET SIZE!!!");
	//printf("\ngetting address of ptr!!!!! %p", &ptr, "<-----ptr");
	if ( ptr == NULL) { 
		return 0;
	
	}
	else{
	while( *ptr){
		//debug
		//printf("the next char is: %c\n", *ptr);
		ptr++; 
		
		count++;
	
	}
	
	//	printf("\nthe size of the array is: %d\n", count);

	return count;
	}
}


char selectChar(char array []){


	unsigned pos;
	char addtoPass;
	pos = randomPos(array);
	//printf("in selectChar\n");
	
	//printf("array pos is: %d",pos);
	
	
	addtoPass = array[pos];
	
	//printf("\nprint me before returning this char: %c\n", addtoPass);
	//printf("\nposition is %d", pos);
	return addtoPass;
	

}

void build_Pass(char letters [], unsigned size){

	char newPass [size];
	unsigned count =0;
	char selected;
	unsigned pos;
	unsigned used;
	//search for a new char to add to the password
	// selected = selectChar(letters, pos);
// 	printf("\nselected char is: %c", selected);
// 	
	
	
	for (count; count < size; count++){
		
		selected = selectChar(letters);
		used = compareChar(newPass, selected);

		if( used == 0){
	
			newPass[count]= selected;

		}
		else{
			while(used == 1){ 
				selected = selectChar(letters);
				used = compareChar(newPass, selected);
			}
		
		}
	}

	printf("\n your new password is: ");
	puts(newPass);
}
//compare uses of the char in the new password we're building

void printString(char * myCharArray){

	char * ptr = myCharArray;
	char * next = ptr++;
	unsigned count = 0;
	
	while(*ptr != '\0'){
	
		ptr = next;
		next++;
		printf("%c",*ptr); 
	}
	
	
	
}
unsigned compareChar(char * array, char c){

	//a character cannot have been selected more than twice
	//if it is selected twice than we cannot select this char and we return 1 for selected
	//if not return 0
	
	int count =0;
	int times =0;
	//char * ptr = array;
	
	if(array[0] != ' '){
		while(count < getSize(array)){
			if (c == array[count])
				{
					times++;
					return (times == 2);
				}
				
			count++;
		}
		
		return 0;
	}
	
	return 0;
}