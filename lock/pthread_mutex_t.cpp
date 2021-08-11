#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;
int num = 1;


//新建一个互斥锁
pthread_mutex_t mutex;

void* fun(void* arg){
    for(int i = 0; i < 50; ++i){
	//上锁
	pthread_mutex_lock(&mutex);
	cout<< "fun: "<< num++<< endl;
	//解锁
	pthread_mutex_unlock(&mutex);
    }
    return nullptr;
}

int main()
{

    pthread_t tid;
    pthread_create(&tid, nullptr, fun, nullptr);
    //pthread_detach(tid);
    
    for(int i = 0; i < 50; ++i){
	pthread_mutex_lock(&mutex);
	cout<< "main: "<< num++<< endl;
	pthread_mutex_unlock(&mutex);
    }

    //先让两个线程跑完 之后释放锁
    pthread_join(tid, nullptr);

    //释放互斥锁
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
