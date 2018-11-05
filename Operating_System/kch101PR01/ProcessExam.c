#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){
	pid_t child;
	int i, n;
	time_t curtime;
	pid_t stat;

	time(&curtime);//curtime 변수에 시간에 대한 정보를 넣기 위해 time()함수를 사용
	stat = getpid();//부모일때만 자식프로세스를 생성하기 위해 먼저 부모의 pid값을 받는다.

	for(i=0; i<10; i++)
		if(stat==getpid())//stat내의 변수 값과 현재 getpid()값이 같으면 부모이므로 아래 내용을 실행
			child = fork();//위의 조건이 성립하면 부모이므로 부모가 자식 프로세스를 생성하여 그 값을 child에 저장

	if(child <=-1){//pid값이 -1이면 제대로 실행되지 않은 것이므로 Exception 처리
		printf("Error!\n");
		exit(1);

	}

	else if(child ==0){
		for(n=0; n<100; n++){//자식프로세스가 생성되면 제시된 조건을 출력하기 위한 반복문 설정
			printf("[PID=%d, Count=#%d, PPID=%d] datetime = %s\n",getpid(),n+1, getppid(), ctime(&curtime));
			sleep(0.001);
			}//
	}

	else{//0의 값이 아니면 부모이므로 아래의 실행문 실행
		int state;
		pid_t child_pid;
		for(i=0; i<10; i++){
			child_pid = wait(&state);//현재 위에서 생성한 10개의 자식프로세스가 종료될때 까지 기다리는 실행문
			printf("child has finished: PID =%d\n",child_pid);//10개중 끝나는 어떤 프로세스가 발생하면 좌측의 실행문을 실행하여 끝난 child의 pid값을 출력한다.
		}

	}

	return 0;
}
