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
class programmer : public  virtual employee
{
protected:
    int departmentNo;

public:
    programmer() {}
    programmer(int jobid, int dno)
    {
        departmentNo = dno;
        jobId = jobid;
    }
    void getDetail()
    {
        cout << "Job id is " << jobId << endl;
        cout << "Salary is " << salary << endl;
        cout << "Department no is " << departmentNo << endl;
    }
};
class accountant : public virtual  employee
{
protected:
    int departmentNo;

public:
    accountant() {}
    accountant(int jobid, int dno)
    {
        departmentNo = dno;
        jobId = jobid;
    }
    void getDetail()
    {
        cout << "Job id is " << jobId << endl;
        cout << "Salary is " << salary << endl;
        cout << "Department no is " << departmentNo << endl;
    }
};
// class child : public accountant, public programmer{
//     public:
//         child(int a, int b): accountant( a,  b){
//             accountant :: getDetail();
//             cout<<jobId;
//         }
//         child(){}
// };
int main()
{

    programmer p(112, 2);
    p.getDetail();

    accountant ac(113, 3);
    ac.getDetail();

    // child c(23,4);
    return 0;
}