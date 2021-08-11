#include<iostream>
#include<pthread.h>
using namespace std;

void* fun(void* arg){
    cout<< pthread_self()<< endl;
    return nullptr;
}

int main()
{

    pthread_t tid;
    pthread_create(&tid, nullptr, fun, nullptr);


    //设置子线程和主线程分离 这样子线程的资源就有系统回收不是主线程回收
    pthread_detach(tid);

    pthread_exit(nullptr);

    return 0;
}
