#include<iostream>
#include<pthread.h>
using namespace std;

void* fun(void* arg){
    unsigned long *tid = (unsigned long* ) arg;

    //pthread_equal 比较两个线程值 不相等返回0相等返回1
    pthread_equal(pthread_self(), *tid) ? cout<< "yes"<< endl : cout<< "no"<< endl;
    return nullptr;
}


int main()
{

    pthread_t tid;
    pthread_create(&tid, nullptr, fun, (void*)(pthread_self()));
    pthread_join(tid, nullptr);

    return 0;
}
