#include<iostream>
#include<unistd.h>
using namespace std;

void* fun(void* arg){
    cout<< "子线程："<< pthread_self()<< endl;
    return nullptr;
}

int main()
{
    cout<< "主线程："<< pthread_self()<< endl;

    pthread_t tid;
    pthread_create(&tid, nullptr, fun, nullptr);

    //为了让主线程不释放资源其实没有必要让主线程用sleep阻塞 这样浪费cup时间 可以用 pthread_exit来让主线程退出 但是不会释放资源
    //参数是退出时携带的数据 当前子线程的主线程会得到这个数据 不需要时nullptr
    pthread_exit(nullptr);
    return 0;
}
