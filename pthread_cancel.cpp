#include<iostream>
#include<pthread.h>
using namespace std;

void* fun(void* arg){
    //不会成功输出输出时调用系统调用被杀死
    cout<< "yes"<< endl;
    return nullptr;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, fun, nullptr);

    //杀死子线程 如果子线程做了系统调用就是退出
    pthread_cancel(tid);

    return 0;
}
