#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	short m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12;
	int w,y=0;
	const unsigned short A=300;
	cin>>m1>>m2>>m3>>m4>>m5>>m6>>m7>>m8>>m9>>m10>>m11>>m12;
    if((A-m1)<0) cout<<"-1"<<endl;
	else 
	{
		y=y+(A-m1)/100*100;
		w=(A-m1)%100;
		if((A+w-m2)<0) cout<<"-2"<<endl;
		else
		{
		    y=y+(A+w-m2)/100*100;
			w=(A+w-m2)%100;
			if((A+w-m3)<0) cout<<"-3"<<endl;
			else
			{
				y=y+(A+w-m3)/100*100;
				w=(A+w-m3)%100;
				if((A+w-m4)<0) cout<<"-4"<<endl;
				else
				{
					y=y+(A+w-m4)/100*100;
					w=(A+w-m4)%100;
					if((A+w-m5)<0) cout<<"-5"<<endl;
			        else
			        {
				        y=y+(A+w-m5)/100*100;
						w=(A+w-m5)%100;
				        if((A+w-m6)<0) cout<<"-6"<<endl;
			            else
			            {
				            y=y+(A+w-m6)/100*100;
							w=(A+w-m6)%100;
				            if((A+w-m7)<0) cout<<"-7"<<endl;
			                else
			                {
				                y=y+(A+w-m7)/100*100;
								w=(A+w-m7)%100;
				                if((A+w-m8)<0) cout<<"-8"<<endl;
			                    else
			                    {
				                    y=y+(A+w-m8)/100*100;
									w=(A+w-m8)%100;
				                    if((A+w-m9)<0) cout<<"-9"<<endl;
			                        else
			                        {
				                        y=y+(A+w-m9)/100*100;
										w=(A+w-m9)%100;
				                        if((A+w-m10)<0) cout<<"-10"<<endl;
			                            else
			                            {
				                            y=y+(A+w-m10)/100*100;
											w=(A+w-m10)%100;
				                            if((A+w-m11)<0) cout<<"-11"<<endl;
			                                else
			                                {
				                                y=y+(A+w-m11)/100*100;
												w=(A+w-m11)%100;
				                                if((A+w-m12)<0) cout<<"-12"<<endl;
			                                    else
		                                        {
		                                        	y=y+(A+w-m12)/100*100;
				                                    w=(A+w-m12)%100;
				                                    cout<<1.2*y+w<<endl;
				                                }
				                            }
				                        }
				                    }
				                }
				            }
				        }
				    }
				}
			}
		}	
	} 
	return 0;
}
