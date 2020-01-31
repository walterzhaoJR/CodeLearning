#include <iostream>
#include <list>
using namespace std;

class Observer
{
public:
  Observer() {}
  virtual ~Observer() {}
  virtual void Update(std::string message) = 0;
};

class ConcreteObserver : public Observer
{
public:
  ConcreteObserver(std::string name) : m_name(name) {}
  virtual ~ConcreteObserver() {}
  void Update(std::string message) {
    cout << m_name << " knows the message:" << message << endl;
  }
private:
  std::string m_name;
};

class Subject
{
public:
  virtual int AddObserver(Observer* ob) = 0;
  virtual void DeleteObserver(Observer* ob) = 0;
  virtual void Notify(std::string message) = 0;
};

class ConcreteSubject : public Subject
{
public:
  int AddObserver(Observer* ob) {
    ob_list.push_back(ob);
    return 0;
  }

  void DeleteObserver(Observer* ob) {
    ob_list.remove(ob);
  }

  void Notify(std::string message) {
    for (auto o : ob_list) {
     o->Update(message);
    }
  }
private:
  std::list<Observer*> ob_list;
};

int main()
{
  ConcreteSubject sub;
  ConcreteObserver* ob[10];
  for (int i = 0; i < 10; ++i) {
    ob[i] = new ConcreteObserver("walter" + std::to_string(i+1));
    sub.AddObserver(ob[i]);
  }

  sub.Notify("happy new year");

  for (auto o : ob) {
    delete o;
  }

  return 0;
}
