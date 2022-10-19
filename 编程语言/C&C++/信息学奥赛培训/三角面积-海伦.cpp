#include<iostream>
#include<cmath>
using namespace std;
int main()
{
float a,b,c,p;
double s,x;
cout<<"输入"<<endl;
cin>>a>>b>>c;
if((a+b)>c&&(a+c)>b&&(b+c)>a&&fabs(a-b)<c&&fabs(a-c)<b&&fabs(b-c)<a) {
p=(a+b+c)/2;
x=p*(p-a)*(p-b)*(p-c);
s=sqrt(x);
cout<<"三角形的面积为"<<s;} 
else cout<<"参数错误 无法构成三角形";
return 0;
}
