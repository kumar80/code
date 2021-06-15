#include<bits/stdc++.h>
using namespace std;
int slabs(int gross_income){
    if(gross_income < 400000)
        return 0;
    if(gross_income <= 150000)
        return 1;
    else if(gross_income <= 300000)
        return 2;
    else if(gross_income <= 800000)
        return 3;
    else if(gross_income <= 10000000) 
        return 4;
    else 
        return 5;
}

int main(){
    int gross_income,i=0;
    cin>>gross_income;
    vector<double>taxable_income(5);
    vector<double>tax_rate(5);
    taxable_income[0]=150000;
    taxable_income[1]=150000;
    taxable_income[2]=200000;
    taxable_income[3]=9200000;
    taxable_income[4]=10000000;
    tax_rate[0]=0;
    tax_rate[1]=2.5;
    tax_rate[2]=10;
    tax_rate[3]=25;
    tax_rate[4]=30;
    int slabs_count = slabs(gross_income);
    double total_tax=0;
    for(int i=0 ; i<slabs_count; i++ ){
        total_tax += (taxable_income[i]*tax_rate[i])/100;
    }
    cout<<fixed<<total_tax;
}
