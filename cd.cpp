#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ans = false;
int findanswer2(ll p,ll q,ll r,ll a,ll b,ll c)
{
  int temp=1;
  ll add=(p*b-a*q);
  if((p-q)==0||(add%(p-q))!=0)
  { 
    return 0;
  }
  add/=(p-q);
  ll sub=a-add;
  if(p==0||(sub%(p))!=0)
  {
    return 0;
  }
  sub/=p;
  ll p1=p,q1=q,r1=r;
  r+=add;
  if(r==c)
  {
    temp+=1;
    return temp;
  }
  p=p1,q=q1,r=r1;
  r*=sub;
  if(r==c)
  {
    temp+=1;
    return temp;
  }
  p=p1,q=q1,r=r1;
  r=r*sub+add;
  if(r==c)
  {
    temp+=1;
    return temp;
  }



  p=p1,q=q1,r=r1;
  sub=a-b;
  if((p-q)==0||(sub%(p-q))!=0)
  {
    return 0;
  }
  sub/=(p-q);
  add=a;
  if(sub==0||(add%(sub))!=0)
  {
    return 0;
  }
  add/=sub;
  add-=p;
  r+=add;
  if(r==c)
  {
    temp+=1;
    return temp;
  }
  p=p1,q=q1,r=r1;
  r*=sub;
  if(r==c)
  {
    temp+=1;
    return temp;
  }
  p=p1,q=q1,r=r1;
  r=(r+add)*sub;
  if(r==c)
  {
    temp+=1;
    return temp;
  }
  return 0;

}
int findanswer(ll p,ll q,ll r,ll a,ll b,ll c)
{
  int temp=1;
  ll diff=c-r;
  if(a==0&&b==0)
  {
    temp+=1;
    return temp;
  }
  if((p-a)==q-b)
  {
    temp+=1;
    return temp;
  }
  if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
  {
    if(a/p==b/q)
    {
      temp+=1;
      return temp;
    }
  }
  ll p1=p,q1=q,r1=r;
  p+=diff;
  if((p-a)==q-b)
  {
    temp+=1;
    return temp;
  }
  if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
  {
    if(a/p==b/q)
    {
      temp+=1;
      return temp;
    }
  }
  p=p1,q=q1,r=r1;
  q+=diff;
  if((p-a)==q-b)
  {
    temp+=1;
    return temp;
  }
  if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
  {
    if(a/p==b/q)
    {
      temp+=1;
      return temp;
    }
  }
  p=p1,q=q1,r=r1;
  p+=diff;
  q+=diff;
  if((p-a)==q-b)
  {
    temp+=1;
    return temp;
  }
  if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
  {
    if(a/p==b/q)
    {
      temp+=1;
      return temp;
    }
  }
  p=p1,q=q1,r=r1;
  if((r!=0)&&(c%r)==0)
  {
    ll mult=c/r;
    if((p-a)==q-b)
    {
      temp+=1;
      return temp;
    }
    if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
    {
      if(a/p==b/q)
      {
        temp+=1;
        return temp;
      }
    }
    p=p1,q=q1,r=r1;
    p*=mult;
    if((p-a)==q-b)
    {
      temp+=1;
      return temp;
    }
    if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
    {
      if(a/p==b/q)
      {
        temp+=1;
        return temp;
      }
    }
    p=p1,q=q1,r=r1;
    q*=mult;
    if((p-a)==q-b)
    {
      temp+=1;
      return temp;
    }
    if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
    {
      if(a/p==b/q)
      {
        temp+=1;
        return temp;
      }
    }
    p=p1,q=q1,r=r1;
    p*=mult;
    q*=mult;
    if((p-a)==q-b)
    {
      temp+=1;
      return temp;
    }
    if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
    {
      if(a/p==b/q)
      {
        temp+=1;
        return temp;
      }
    }
  }
  return 0;
}

void sol()
{
  ll p,q,r,a,b,c;
  cin>>p>>q>>r>>a>>b>>c;
  if(p==a&&q==b&&r==c)
  { ans  = true;
    cout<<0<<endl;
    return;
  }
  if(a==0&&b==0&&c==0)
  {ans  = true;
      cout<<1<<endl;
      return;
  }
  if((p-a)==q-b&&(q-b)==r-c)
  {ans  = true;
    cout<<1<<endl;
    return;
  }
  if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0&&(r!=0)&&(c%r)==0)
  {
    if(a/p==b/q&&b/q==c/r)
    {ans  = true;
      cout<<1<<endl;
      return;
    }
  }
  if((p!=a&&q==b&&r==c)||(p==a&&q!=b&&r==c)||(p==a&&q==b&&r!=c))
  {ans  = true;
    cout<<1<<endl;
    return;
  }
  if(p!=a&&q!=b&&r==c)
  {
    if(a==0&&b==0)
    {ans  = true;
      cout<<1<<endl;
      return;
    }
    if((p-a)==q-b)
    {ans  = true;
      cout<<1<<endl;
      return;
    }
    if((p!=0)&&(a%p)==0&&(q!=0)&&(b%q)==0)
    {
      if(a/p==b/q)
      {ans  = true;
        cout<<1<<endl;
        return;
      }
    }ans  = true;
    cout<<2<<endl;
    return;
  }
  if(p!=a&&q==b&&r!=c)
  {
    if(a==0&&c==0)
    {ans  = true;
      cout<<1<<endl;
      return;
    }
    if((p-a)==r-c)
    {ans  = true;
      cout<<1<<endl;
      return;
    }
    if((p!=0)&&(a%p)==0&&(r!=0)&&(c%r)==0)
    {
      if(a/p==c/r)
      {ans  = true;
        cout<<1<<endl;
        return;
      }
    }ans  = true;
    cout<<2<<endl;
    return;
  }
  if(p==a&&q!=b&&r!=c)
  {
    if(b==0&&c==0)
    {ans  = true;
      cout<<1<<endl;
      return;
    }
    if((q-b)==r-c)
    {ans  = true;
      cout<<1<<endl;
      }
    }//cout<<ans<<" ";
    int tt = findanswer2(p,q,r,a,b,c);
  int ty = findanswer(p,q,r,a,b,c);
 if(tt || ty) cout<<2<<"\n";
 else cout<<3<<"\n";
}
int main(){
    int t; cin>>t;
    while(t--){
        sol();
        ans = 0;
    }
}