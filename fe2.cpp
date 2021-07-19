#include<iostream>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define all(v) v.begin()+1,v.end()
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5+10;

struct pt{
    LL l,r;
    pt(LL x, LL y){
      l=x; r=y;
    }
    pt(){}
};

struct node{
  pt key;
  node *left,*right;
};

node* newNode(pt key){
  node* temp =  (struct node*)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

node* insert(node* root, pt key){
  if(root==NULL)
    return newNode(key);
  if(key.r < root->key.l)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);

  return root;
}

node* minNode(node* node){
    struct node* current = node; 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

node* deleteNode(node* root, pt key){
  if(root==NULL) return root;

  if(key.r  < root->key.l)
    root->left = deleteNode(root->left, key);
  else if( key.l > root->key.r)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL && root->right == NULL)        
            return NULL;
    else if(root->left == NULL){
      node *temp  = root->right;
      free(root);
      return temp;
    }else if(root->right == NULL){
      node *temp  = root->left;
      free(root);
      return temp;
    }
        node* succParent = root;
        node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        root->key = succ->key;
 
        delete succ;
        return root;
  }
    return root;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout<<root->key.l<<" "<<root->key.r<<"\n"; 
        inorder(root->right);
    }
}
void search(node* root, pt &key, LL &d, LL x){
    if(root==NULL) return;
    if(root->key.l<=x && root->key.r>=x){
        d=0; key.l=root->key.l;
        key.r = root->key.r;
    }
    else if(root->key.l> x){
        if(root->key.l-x <d || (root->key.l-x == d && key.l>root->key.r)){
           d = root->key.l-x;
           key.l = root->key.l;
           key.r = root->key.r;
        }
        search(root->left,key,d,x);
    }
    else {
        if(x-root->key.r <d || (x-root->key.r == d && key.l>root->key.r)){
           d = x-root->key.r;
           key.l = root->key.l;
           key.r = root->key.r;
        }
        search(root->right,key,d,x);
    }
}

bool cmp(pt a , pt b){
    return (a.l<b.l || (a.l==b.l && a.r<=b.r));
}

void merge(pt array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    pt *leftArray = new pt[subArrayOne],
         *rightArray = new pt[subArrayTwo];
 
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (cmp(leftArray[indexOfSubArrayOne] , rightArray[indexOfSubArrayTwo])) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 
void mergeSort(pt array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 

int main(){
    fastio;
    int t=1; cin>>t; int T=1;
    while(t--){
      node* root = NULL;
      int n,m; cin>>n>>m;
      pt v[n];
      LL vv[m];
      LL ans[m];
      FOR(i,0,n){
        cin>>v[i].l>>v[i].r;
      }
      FOR(i,0,m) cin>>vv[i];
      mergeSort(v,0,n-1);
      int l = n/2-1,r=n/2;
      while(1){
        if(l>=0) root = insert(root,pt(v[l].l,v[l].r));
        if(r<n) root = insert(root,pt(v[r].l,v[r].r));
        if(l<0 && r>=n) break;
        l--;r++;
      }
    //  inorder(root);
      FOR(i,0,m){
        LL x=vv[i];// cin>>x;
        LL d = 1e18;
        pt p = pt(1e18, 1e18);
        search(root,p,d,x);
        root = deleteNode(root, pt(p.l,p.r));
        LL k=x-d>=p.l && x-d<=p.r?x-d:x+d;
        ans[i] = k;
     //   cout<<k<<" ";
        if(p.l == p.r) continue;
        if(p.l == k)
          root = insert(root,pt(k+1,p.r));
        else if(p.r==k)
          root = insert(root,pt(p.l,k-1));
        else {
          root = insert(root,pt(p.l,k-1));
          root = insert(root,pt(k+1,p.r));
        }
      //  cout<<i<<"= \n";        
       // cout<<p.l<<" "<<p.r<<" "<<d<<" "<<k<<";; \n";

       // inorder(root); cout<<"\n***\n";
      }
      cout<<"Case #"<<T++<<": ";
      for(int i =0;i<n;i++) cout<<ans[i]<<" "; 
      cout<<"\n";
    }
}
