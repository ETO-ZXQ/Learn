#include<iostream>
#include<cmath>
using namespace std;
int main()
{
float a,b,c,p;
double s,x;
cout<<"����"<<endl;
cin>>a>>b>>c;
if((a+b)>c&&(a+c)>b&&(b+c)>a&&fabs(a-b)<c&&fabs(a-c)<b&&fabs(b-c)<a) {
p=(a+b+c)/2;
x=p*(p-a)*(p-b)*(p-c);
s=sqrt(x);
cout<<"�����ε����Ϊ"<<s;} 
else cout<<"�������� �޷�����������";
return 0;
}
