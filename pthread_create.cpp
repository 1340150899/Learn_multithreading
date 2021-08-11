#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

void* func(void* arg){
    cout<<"子线程："<< pthread_self()<< endl;
    return nullptr;
}

int main()
{

    cout<< "主线程："<< pthread_self()<< endl;
    //创建一个线程 第一个参数代表传出参数 是无符号长整型数 线程创建成功 会将线程的id写入到这个指针指向的内存中
    //第二个是线程的属性 一般下使用默认属性 nullptr
    //三函数的指针代表线程要运行的动作 也就是要运行的函数 在子线程中执行
    //四是代表要传入到函数的参数
    pthread_t tid;
    pthread_create(&tid, nullptr, func, nullptr);
    //usleep是以微秒时间单位睡眠（us） 不能让主线程跑的太快就释放资源 这样子线程不会运行
    usleep(10);
    return 0;
}
