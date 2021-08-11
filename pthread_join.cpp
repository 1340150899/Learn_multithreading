#include<iostream>
#include<pthread.h>
using namespace std;
struct Tid{
    unsigned long x;
    Tid *next;
    Tid(unsigned long x):x(x),next(nullptr){

    }
};

void* fun(void* arg){
    Tid *x = new Tid(pthread_self());
    pthread_exit(x);
}

int main()
{
    Tid* head = new Tid(pthread_self());
    pthread_t tid;
    pthread_create(&tid, nullptr, fun, nullptr);


    //线程阻塞当运行到这里的时候会一直等待子线程退出
    //第一个参数是等待的线程tid 第二个是配合pthread_exit()中返回的参数 他是一个二级指针用来接收返回的参数
    void* p = nullptr;
    pthread_join(tid, &p);

    head->next = (Tid*) p;
    while(head){
	cout<< head->x<< endl;
	head = head->next;
    }
    return 0;
}
