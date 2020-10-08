#include <bits/stdc++.h> 
using namespace std; 
bool fcompare(pair<int, pair<int, int> > p, 
				pair<int, pair<int, int> > p1) 
{ 
	if (p.second.second != p1.second.second) 
		return (p.second.second > p1.second.second); 
	else
		return (p.second.first < p1.second.first); 
} 

void sortByFrequency(int arr[], int n) 
{ 
	unordered_map<int, pair<int, int> > hash; 
	for (int i = 0; i < n; i++) { 
		if (hash.find(arr[i]) != hash.end()) 
			hash[arr[i]].second++; 
		else
			hash[arr[i]] = make_pair(i, 1); 
	} 

	auto it = hash.begin(); 

	vector<pair<int, pair<int, int> > > b; 
	for (it; it != hash.end(); ++it) 
		b.push_back(make_pair(it->first, it->second)); 

	sort(b.begin(), b.end(), fcompare); 

	for (int i = 0; i < b.size(); i++) { 
		int count = b[i].second.second; 
		while (count--) 
			cout << b[i].first << " "; 
	} 
} 

int main() 
{   int n; cin>>n;
	int arr[n] ; 
    for(int i=0;i<n;i++) cin>>arr[i];
	sortByFrequency(arr, n); 

	return 0; 
} 
