#include <iostream>
#include <memory>

using namespace std;

#if 0
class Bad
{
public:
    std::shared_ptr<Bad> GetPtr() {
        // error 因为这样会造成2个非共享的share_ptr指向同一个对象，未增加引用计数导对象被析构两次
        return std::shared_ptr<Bad>(this);
    }
    ~Bad() {
        cout << "~B call" << endl;
    }
};

int main()
{
    std::shared_ptr<Bad> bp1(new Bad);
    std::shared_ptr<Bad> bp2 = bp1->GetPtr();

    cout << "bp1 count:" << bp1.use_count() << endl;
    cout << "bp2 count:" << bp2.use_count() << endl;
    // Bad 对象会被析构两次，导致内存错误
    return 0;
}
#endif

class Good : public enable_shared_from_this<Good>
{
public:
    std::shared_ptr<Good> GetPtr() {
        return shared_from_this();
    }

    ~Good() {
        cout << "~Good() call" << endl;
    }
};

int main()
{
    std::shared_ptr<Good> gp1(new Good);
    std::shared_ptr<Good> gp2 = gp1->GetPtr();

    cout << "gp1 count:" << gp1.use_count() << endl;
    cout << "gp2 count:" << gp2.use_count() << endl;
}
