#include<iostream>
using namespace std;
int money,cost,mama,flag=1,monthofdeath;  //money�����ڽ�������Ǯ��cost�����ѵ�Ǯ��mama���������������100Ԫ��������flag=1������δ͸֧��monthofdeath���������·� 
int main ()
{
    for(int i=1;i<=12;i++)
    {
        money+=300;  //ÿ���½�������Ǯ��������300 
        cin>>cost;     //��������µĻ��� 
        money-=cost;     // ��������Ǯ��ȥ����µĻ�������ʣ���Ǯ 
           if(money<0)     //��ʣ���ǮС��0, 
           {     
              flag=0;      //���ĵ��£����Ѿ�͸֧ 
              monthofdeath=i;    //��������·� 
              break;            //��ֹѭ�� 
           }
        mama+=money/100;    //ʣ���Ǯ����100��Ϊ�����������100Ԫ������ 
        money%=100;         //��100ȥģʣ���Ǯ��Ϊ�µ��Ҵ��Ǯ         
    }    
    if(flag==1)      //������δ���£�����ֵ���׻�û��͸֧ 
    {
        money+=mama*120;    //ʣ���Ǯ 
        cout<<money;
    }            
    else
    {
        cout<<-monthofdeath;
    }    
    return 0;
}
