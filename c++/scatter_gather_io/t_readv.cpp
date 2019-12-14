#include <iostream>
#include <sys/uio.h>
#include <fcntl.h>

using namespace std;


struct test{
    
    int x;
    char str[10];
};

int main(int argc,char** argv){

    int fd = -1;
    struct iovec iov[3];

    struct test myTest; //first buffer
    int c;              //seconf buffer
    char new_str[20] = "0";//third buffer


    if(argc != 2){
        
        cout << "para error,no file name" << endl;
        return -1;
    }
    
    fd = open(argv[1],O_RDONLY);
    if(-1 == fd){
    
        cout << "open file " << argv[1] << "error" <<endl;
        return -1;
    }

    int total_require = 0;
    iov[0].iov_base = &myTest;
    iov[0].iov_len = sizeof(struct test);

    total_require += iov[0].iov_len;

    iov[1].iov_base = &c;
    iov[1].iov_len = sizeof(c);

    total_require += iov[1].iov_len;

    iov[2].iov_base = new_str;
    iov[2].iov_len = 20;

    
    total_require += iov[2].iov_len;

    int num =  readv(fd,iov,3);
    if(-1 == num){
        
        cout << "readv error" << endl;
        return -1;
    }
    
    if(num < total_require){
    
        cout << "read bytes fewer than request" << endl;
    }


    cout << "total bytes request:" << total_require << endl;
    cout << "readv bytes :" << num << endl;


    cout << "information" << endl;
    cout << "myTest" << myTest.x << endl;
    cout << "myTest" << myTest.str << endl;

    cout << "c:" << c << endl;

    cout << "new_str:" << new_str << endl;
    return 0;
}
