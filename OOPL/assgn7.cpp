#include<iostream>
using namespace std;
class division
{
    double x,y;

    public:
    void input();
    void display();
    void divide();
};
void division :: input()
{
    cout<<"Enter Dividend(Numerator) : "<<endl;
    cin>>x;
    cout<<"Enter Divisor(Denominator) : "<<endl;
    cin>>y;
}
void division :: display()
{
    cout<<"Numerator : "<<x<<endl;
    cout<<"Denominator : "<<y<<endl;
    cout<<"Answer: ";
}
void division :: divide()
{
	int a=0;
    try
    {
        if(y!=0)
            cout<<(x/y)<<endl;
        else
            throw(a);
    }
    catch(int a)
    {   
        cout<<"Attempted to divide "<<x<<" by zero\nDivide by Zero Error"<<endl;
    }
}
int main()
{
    division obj;

    obj.input();
    obj.display();
    obj.divide();

    return 0;
}
