#include <iostream>
#include <fcntl.h>
using namespace std;

int main(){
    
    int fd = open("./a",O_RDWR);
    if(-1 == fd){
        cout << "open file error" << endl;
        return -1;
    }
    else{
    
        int flag = fcntl(fd,F_GETFL);
        if(-1 == flag){
        
            cout << "get file control error" << endl;
            return -1;
        }
        else{
            int assess_mode = flag & O_ACCMODE;
            if(assess_mode == O_WRONLY || assess_mode == O_RDWR){
            
                cout << "the file is writable" << endl;
            }
        }
        
        //修改文件的属性
        flag |= O_APPEND;
        if(fcntl(fd,F_SETFL,flag) == -1){
            cout << "set file control error" << endl;
        }
        else{
        
            cout << "set file control success" << endl;
        }
    }



    return 0;
}
