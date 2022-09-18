#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

int globalId = 100;
class Person
{
    int id;
    string name;
    float salary;

public:
    Person()
    {
        this->name = "";
        this->salary = -1.1;
        this->id = -1;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    Person(string name, float salary)
    {

        setName(name);
        setSalary(salary);
        id = globalId;
        globalId++;
    }
    void display()
    {
        cout << this->name << " | " << this->id << " | " << this->salary << endl;
    }
};

int main()
{

    Stack<Person> st;
    Person a("rakib", 142.55);
    Person b("sifat", 120.55);
    Person c("rifat", 162.55);
    Person d("nahid", 192.55);
    Person e("siraz", 196.55);
    Person f("rakayet", 196.55);
    Person g("saidul", 196.55);
    // Person h("emitaj", 196.55);
    // Person i("jashim", 196.55);
    // Person j("riku", 196.55);


    st.push(a);
    st.push(b);
    st.push(c);
    st.push(d);
    st.push(e);
    st.push(f);
    st.push(g);
    // st.push(h);
    // st.push(i);
    // st.push(j);



    Person obj;
    obj = st.mid();
    obj.display();
    cout<<st.size()<<endl;
    // cout << st.top() << endl;
    // Persons ps("sakib", 250.4);

    // Persons ps2("rakib", 350.4);
    // // Persons ps3("rifat", 450.4);
    // // Persons ps4("sifat", 550.4);

    // st.push(ps);
    // st.push(ps2);
    // cout<<st.top();
    // // st->push(ps3);
    // // st->push(ps4);

    return 0;
}