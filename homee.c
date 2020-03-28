#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
#include<pthread.h>
#include<stdlib.h>

int i=100,s=0;
int p[1000][2];
int q=0;
int runn(){
while(i<1001){

	
	p[s][0]=i;
	p[s][1]=0;
	i++;
	s++;
}
}
int allocates(){
	int d=0,aloc=1;
	for(d=0;d<1000;d++){
		if(p[d][1]==0){
			p[d][1]=1;
			aloc=0;
			break;
		}
		
	}
	return aloc?-1:d;
}
void releasepid(int pos){
	printf("in release\n");
	p[pos][1]=0;
}
void *gthread(void *l){
	int pid=*(int *)l;
	int idp=allocates();
	if(idp==-1){
		printf("no id available\n");
		q=-1;
	}else{
		printf("id assigned to thread%d %d\n",pid,idp);
		int s=rand()%(((10-1)+1)+1);
		//printf("%d",s);
	
		sleep(s);
		printf("process slept for %d seconds\n",s);
		releasepid(idp);
	}
	pthread_exit(NULL);
}

int main(){
	runn();
	pthread_t n[4];
	
	srand(time(NULL));
	 int m=0;
		for(m=0;m<4;m++){
			pthread_create(&(n[m]),NULL,gthread,(void*)&m);
			
			
			
		}
		int v=0;
		for(v=0;v<4;v++){
			pthread_join(n[v],NULL);
			//return 0;

		}

}

