#include <bits/stdc++.h>
using namespace std;

class employee
{
protected:
    int jobId;
    float salary;

public:
    employee()
    {
        salary = 1800;
    }
    
};


class programmer : public employee
{
protected:
    int departmentNO;

public:
    programmer()
    {
        departmentNO = 2;
    }
};


class tester : public programmer
{

public:
    tester() {}
    tester(int jobid)
    {
        jobId = jobid;
       
    }
    
    void getDetail()
    {

        cout << "JobId is " << jobId << endl;
        cout << "salary is " << salary << endl;
        cout << "Department no is " << departmentNO << endl;
       
    }
};

int main()
{

    tester p(1152);
    p.getDetail();
    return 0;
}