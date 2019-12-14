#include<iostream>
<<<<<<< HEAD
#include <error.h>
using namespace std;

int main(){
        
    int fd = open("/data/test.cpp",O_RDONLY);
    if(-1 == fd){
        
        perror("open");
        cout << strerror(errno);
    }
    else{
    
        cout << "ok";
    }

    return 0;

}

=======
#include<error.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<fstream>

using namespace std;

int main(){


    //使用两种形式输出errmsg
    cout << "start error" << endl;
    int fd = open("/data/test.cpp",O_RDONLY);
    if(-1 == fd){
        cout << "errmsg strerror:" << strerror(errno) << endl;
        cout<< "perror" ;
        perror("open");
    }
    else{
    
        cout << "ok" << endl;
    }
    
    return 0;
}
>>>>>>> e2d3968f1cd3fb6a90e2e8a692b1573c9f97101b
