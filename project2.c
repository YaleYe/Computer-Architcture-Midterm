#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int Array[100];
	int oddSum = 0;
	int oddCount = 0;
	int oddAvg = 0;
	int evenSum = 0;
	int evenCount = 0;
	int evenAvg = 0;
	//Generate 100 numbers
    srand(time(NULL));
	for(int index=0; index <= 100;index++){
		int num = 0;          //init the num
		num = rand()%100 + 1; //range of(0,100)
		Array[index] = num;}
	//create a child process
	int state = fork();
	//child process if state is 0
	if(state<0){
		printf("fork failed\n");}
	
	//child process if state is 0
	else if(state ==0){
		sleep(1);
		for(int index2 = 0;index2 <= 100 ; index2++){
            if(Array[index2] % 2 != 0){
				oddSum += Array[index2];
				oddCount += 1;}
        }
		oddAvg = oddSum / oddCount;
		printf("Your avgerage of odd number is %d",oddAvg);
		printf("Hello,I'm the Child Process!\n");
		printf("child process,pid = %u\n",getppid());}
	//parent process if state > zero
	else{	
		for(int index3 = 0;index3 <= 100 ; index3++){
            if(Array[index3] % 2 == 0){
				evenSum += Array[index3];
				evenCount += 1;
            }
		}
		evenAvg = evenSum / evenCount;
		printf("Your avgerage of even number is %d\n",evenAvg);
		printf("Hello,I'm the Parent Process!\n");
		printf("parent process,pid = %u\n",getppid());
	     }
		return 0;
}


