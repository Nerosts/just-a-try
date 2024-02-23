#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	virtual ~Person(){}
//};
//
//class Child :public Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }//子类进行重写了
//};
//
//class A
//{
//public:
//	virtual A* f() 
//	{ 
//		return new A; 
//	}
//};
//
//class B:public A
//{
//public:
//	virtual B* f()
//	{
//		return new B;
//	}
//};
//
//void test1()
//{
//	Person* p = new Person;//基类的指针
//	p->BuyTicket();//调用BuyTicket
//
//	Child ch;
//	p = &ch;//现在基类的指针指向了子类
//	p->BuyTicket();
//}

class Person {
public:
    virtual ~Person()
    {
        cout << "~Person()" << endl;
    }
};

class Student : public Person {
public:
    virtual ~Student()
    {
        cout << "~Student()" << endl;
    }
};

void test2()
{
    Person* p1 = new Person;
    Person* p2 = new Student;

    delete p1;
    delete p2;
}

//class Car 
//{
//public:
//    virtual void Drive() {}
//};
//
//class Benz :public Car 
//{
//public:
//    virtual void Drive() override {}
//};


class Car//抽象类，不能实例化出对象
{
public:
    virtual void Drive() = 0; // 纯虚函数
};

class Car1 :public Car
{
public:
    virtual void Drive() // 必须重写基类虚函数，派生类才能实例化出对象
    {
        cout << "Car1-舒适" << endl;
    }
};

class Car2 :public Car
{
public:
    virtual void Drive()
    {
        cout << "Car2-操控" << endl;
    }
};

void test3()
{
    Car* p1 = new Car1;
    p1->Drive();

    Car* p2 = new Car2;
    p2->Drive();
}

//class Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Func1()" << endl;
//    }
//private:
//    int _base = 1;
//};

class Base
{
public:
    virtual void Func1()
    {
        cout << "虚函数Base::Func1()" << endl;
    }
    virtual void Func2()
    {
        cout << "虚函数Base::Func2()" << endl;
    }
    void Func3()
    {
        cout << "不虚Base::Func3()" << endl;
    }
private:
    int _base = 1;
};

//class Derive : public Base
//{
//public:
//    //virtual void Func1()
//    //{
//    //    cout << "虚函数Derive::Func1()" << endl;
//    //}
//private:
//    int _derive = 2;
//};

//class Person {
//public:
//    virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//    virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person& p)
//{
//    p.BuyTicket();
//}
//
//void test4()
//{
//    Person Mike;
//    Func(Mike);
//
//    Student Johnson;
//    Func(Johnson);
//}

//class A {
//public:
//    virtual void func1()
//    {
//        cout << "A::func1" << endl;
//    }
//    virtual void func2()
//    {
//        cout << "A::func2" << endl;
//    }
//private:
//    int _a;
//};
//
//class B :public A {
//public:
//    virtual void func1()
//    {
//        cout << "B::func1" << endl;
//    }
//    //这里B自己又多加了两个虚函数
//    virtual void func3()
//    {
//        cout << "B::func3" << endl;
//    }
//    virtual void func4()
//    {
//        cout << "B::func4" << endl;
//    }
//private:
//    int _b;
//};

typedef void(*vfptr)();

void printvf(vfptr* ptr)
{
    for (int i = 0; ptr[i] != nullptr; ++i)//以空指针结束
    {
        // 依次打印虚表各元素
        printf(" 第%d个虚函数地址 :%p", i + 1, ptr[i]);
        // 把虚表各元素赋值给函数指针f
        vfptr f = ptr[i];
        // 调用函数
        f();
    }
    cout << endl;
}

class Base1
{
public:
    virtual void func1() { cout << "Base1::func1" << endl; }
    virtual void func2() { cout << "Base1::func2" << endl; }
private:
    int b1;
};

class Base2
{
public:
    virtual void func1() { cout << "Base2::func1" << endl; }
    virtual void func2() { cout << "Base2::func2" << endl; }
private:
    int b2;
};

class Derive : public Base1, public Base2
{
public:
    virtual void func1() { cout << "Derive::func1" << endl; }
    //自己又加上两个fun3，会在哪个虚表里填上呢
    virtual void func3() { cout << "Derive::func3" << endl; }
private:
    int d1;
};

int main()
{
    Derive dd;
    Base1* b1 = &dd;
    Base2* b2 = &dd;
    printvf((vfptr*)(*(int*)b1));

    printvf((vfptr*)(*(int*)b2));
    return 0;
}
