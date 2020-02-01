#include<iostream>

using namespace std;

//枚举类
//这样定义的枚举实现了类型安全，首先他不能够被隐式的转换为整数，
// 同时也不能够将其与整数数字进行比较，更不可能对不同的枚举类型的枚举值进行比较。
// 但相同枚举值之间如果指定的值相同，那么可以进行比较

enum class new_enum:unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100,
};

//而我们希望获得枚举值的值时，将必须显式的进行类型转换，不过我们可以通过重载 << 这个算符来进行输出
//收藏一下
template<typename T>
ostream& operator<<(typename enable_if<is_enum<T>::value,ostream>::type& stream, const T&e)
{
    return stream<< static_cast<typename underlying_type<T>::type>(e);
}
int main()
{
    if(new_enum::value3 == new_enum::value4)
    {
        std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
    }

    cout<<new_enum::value4<<endl;//重载<<之前非法

}
