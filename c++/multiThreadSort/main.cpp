

#include <iostream>
#include <pthread.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int > array;

void getData(string dataFileName,vector<int>&array)
{
    //fstream dataFile("/Users/walter/Desktop/data.txt",ios::in | ios::binary);
    fstream dataFile(dataFileName,ios::in | ios::binary);
    if(dataFile.is_open())
    {
        string line = "";
        string temp = "";
        while(getline(dataFile,temp))
        {
            line += temp;
        }

        string token = "";
        int index = 0;
        int num = 0;
        //切割
        while(line.size())
        {
            index = line.find(" ");
            token = line.substr(0,index);
            line = line.substr(index+1);
            num = atoi(token.c_str());
            array.emplace_back(num);

            if(-1 == index)
            {
                break;
            }
        }
    }
    else
    {
        cout << "dataFile open error" << endl;
        return ;
    }
}

void* merge(vector<int >& array,int l,int mid,int r)
{
    vector<int > templ;
    vector<int > tempr;

    int sizel = mid-l+1;//左边的元素数
    int sizer = r-mid;

    int i=0,j=0;
    for(i=0;i<sizel;i++)
    {
        templ.emplace_back(array[l+i]);
    }

    for(i=0;i<sizer;i++)
    {
        tempr.emplace_back(array[mid+1+i]);
    }

    i=0;
    int k = l;

    while(i<sizel && j<sizer)
    {
        if(templ[i]<=tempr[j])
        {
            array[k++] = templ[i++];
        }
        else
        {
            array[k++] = tempr[j++];
        }
    }

    while(i<sizel)
    {
        array[k++] = templ[i++];
    }

    while(j<sizer)
    {
        array[k++] = tempr[j++];
    }
}

void* merge_sort(void*arg)
{
    int*temp = (int*)arg;
    int l = temp[0];//排序下限
    int r = temp[1];//排序上限

    //人== l不需要排序
    if(l<r)
    {
        pthread_t sort1;
        pthread_t sort2;

        //线程传递给函数的参数
        int arg1[2] = {0};
        int arg2[2] = {0};

        int mid = (l+r)/2;
        arg1[0]= l;
        arg1[1] = mid;
        arg2[0]= mid+1;
        arg2[1] = r;

        pthread_create(&sort1, nullptr,merge_sort,arg1);
        pthread_create(&sort2, nullptr,merge_sort,arg2);

        /* 这里必须等待两部分数组都已排序完毕，才能进行归并，
        所以这里调用 pthread_join 使得线程同步 */
        pthread_join(sort1, nullptr);
        pthread_join(sort1, nullptr);

        //此时进行归并
        merge(array,l,mid,r);
        pthread_exit(0);
    }
}
int main(int argc,char**argv)
{
    if(2 != argc)
    {
        cout<<"argc error"<<endl;
        cout<<"./main dataFileName"<<endl;
        exit(1);
    }

    string dataFileName = argv[1];
    getData(dataFileName,array);

    for(auto data:array)
    {
        cout<<data<<" ";
    }
    cout<<endl;

    //要出递给排序线程的参数
    int arg[2];
    arg[0] = 0;
    arg[1] = array.size()-1;

    pthread_t sort;
    pthread_create(&sort, nullptr,merge_sort,arg);

    pthread_join(sort, nullptr);

    for(auto data:array)
    {
        cout<<data<<" ";
    }
    cout<<endl;

    return 0;
}
