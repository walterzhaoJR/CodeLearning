#include<iostream>
#include <unistd.h>

using namespace std;

int main(){

    int fd = 0;
    char temp_file_path[] = "/tmp/walter_XXXXXX";//必须以XXXXXX结尾，数组的原因是可变长，修改XXXXXX让文件名字唯一
    fd = mkstemp(temp_file_path);
    if(-1 == fd){
        return -1;
    }

    cout << "create temp file ok" << endl;
    
    sleep(10);
    unlink(temp_file_path);


    if(-1 == close(fd)){
    
        cout << "close error" << endl;
    }

    return 0;
}
