// // C++ program to build the smallest number by removing n digits from 
// // a given number 
// #include<iostream> 
// #include<vector> 
// using namespace std; 

// // A recursive function that removes 'n' characters from 'str' 
// // to store the smallest possible number in 'res' 
// void buildLowestNumberRec(string str, int n, string &res) 
// { 
// 	// If there are 0 characters to remove from str, 
// 	// append everything to result 
// 	if (n == 0) 
// 	{ 
// 		res.append(str); 
// 		return; 
// 	} 

// 	int len = str.length(); 

// 	// If there are more characters to remove than string 
// 	// length, then append nothing to result 
// 	if (len <= n) 
// 		return; 

// 	// Find the smallest character among first (n+1) characters 
// 	// of str. 
// 	int minIndex = 0; 
// 	for (int i = 1; i<=n ; i++) 
// 		if (str[i] < str[minIndex]) 
// 			minIndex = i; 

// 	// Append the smallest character to result 
// 	res.push_back(str[minIndex]); 

// 	// substring starting from minIndex+1 to str.length() - 1. 
// 	string new_str = str.substr(minIndex+1, len-minIndex); 

// 	// Recur for the above substring and n equals to n-minIndex 
// 	buildLowestNumberRec(new_str, n-minIndex, res); 
// } 

// // A wrapper over buildLowestNumberRec() 
// string buildLowestNumber(string str, int n) 
// { 
// 	string res = ""; 

// 	// Note that result is passed by reference 
// 	buildLowestNumberRec(str, n, res); 

// 	return res; 
// } 

// // Driver program to test above function 
// int main() 
// {   vector<int>v; v.push_back(NULL);
// 	string str = "987654321"; 
// 	int n = 2; 
// 	cout << buildLowestNumber(str, n); 
// 	return 0; 
// } 

/*              |\ | |  ||\ \ /(_~     |~)|_~|\/||_~|\/||~)|_~|~)
				|~\|_|/\||~\ | ,_)     |~\|__|  ||__|  ||_)|__|~\

				   \ //~\| |    |\ |~)|_~    | ||\ ||/~\| ||_~
					| \_/\_/    |~\|~\|__    \_/| \||\_X\_/|__
				(J U S T   L I K E   E V E R Y O N E   E L S E !)

							 __ ,..---.._
							+''''`--''-..`--..__
						   .\ _,/:i--._`:-:+._`.``-._
						  /`.._,,' \   `-.``--:.b....=.
						 |`..__,,..`.    '`.__::i--.-::_
						 )- .....--i'\..      --+`'''-'
					   ,' .'.._,.-'|._-b\
					  /,'<'    V   `oi| \             _.
					 |/ -|,--.." ,'-. ||\..      _.,;:'_<'
					 ''/ |  . ' |\||'\    /-'_/' `.
					|,','|    , .    .-.|:.`.  + .,:..  |
				 ._,:'/ /-\   '^'   -Y"\ |.| || /,+8d| |
				.|/,'| |/':: ':=:' ,'|  | | \|| "+)='  |
				|+,';' /|_/ \     _/ \b':.\  \'| .||   ,'
				,,:-i''_i' | ``-.Y',. ,|`: | \;- | |_,'
		  __   |'| |i:'._ ,'     ,' ,; | |-)-'  __--:b__
		 .P|   | |/,'|\  - ._   /  /   _,Y-   ,:/'  `.  `'".._
		,'|| -','' | ._i._   `':| ,..,'     ,Y;'      \       `- ._
	   |||||,..    | \ '-.._ _,' /       _,b-'         `.         '-.
	   ||||P..i,  .| '....,-' _,'''''-'''               '    _,..    `\
	   +'`   <'/  |`-.....---'                       ._         ,._
		|      |                                    ,'``,:-''''/,--`.
	   Y|.b_,,:  |              ||                 ,;,Y'      /     |.
	 ,' /'----' .'|   ..       |  |         '"   .`Y'     .,-b_....;;,.
	|+|,'     | | \.,  '      ,'  `:.  _     ,/__`     _=:  _,'``-
   / +,'      | /\_........:.'      '"----:::::'Y  .'.|   |||
   |' '      .'/- \                          /'|| || |   |||
   |||      /|     \L                        /'|| ||/ |   |||
   `.|    ,'/       .|                      / ,'||/o;/    |||
	 `..._,,         |                      |/|   '       |||
	   ``-'          |                      |,            |||
					 |          ,.          |             |||
  ,=--------....     |          ""          |             |||
,/,'.            i=..+._             ,..    '..;---:::''- | |
'/|           __....b `-''`---....../.,Y'''''j:.,.._      | `._
.'      _.Y.-'       `..       ii:,'--------' |     :-+. .| | b\
|     .=_,.---'''''--...:..--:'  /         _..-----..:=   | | '|\
|    '-''`'---                  ---'_,,,--''           `,.. |  | \.
 \  .                      ,' _,--''        :dg:      _,/ |||   |  \
`::b\`                 _,-i,-'                 ,..---'    ,|:|  | _|
`'--.:-._      ____,,,;.,'' `--._      ''''''''           |'|' .'  '
	 ``'--....Y''-'              `''--..._..____._____...,' |  'o-'
											 `''''`'''i==_+=_=i__
													 ||'''- '    `.
													  `-.......-''
*/                              
#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define LL long long 
#define mod 1000000007 
#define FOR(i, j, k) for (auto i=j ; i<k ; i++)
#define ROF(i, j, k) for (auto i=j ; i>=k ; i--) 
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

const long long INF = 1e18;
const long long MAX = 1e5+10;
int main(){
	fastio;
	int t=1;// cin>>t;
	while(t--){
		int n; cin>>n;
		for (int i = 1; i*i <= n; i++)
		{
			/* code */
			if(n%i == 0) cout<<i<<" "<<n/i<<"; ";
		}
		
	}
}
