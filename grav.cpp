    #include<iostream>
    #include<vector>
    #include<iomanip>
    #include<algorithm>

    using namespace std;

    long double cal(vector<long double>x, vector<long double>m, long double d) {
        int n = x.size();
        long double fl = 0.0, fr = 0.0;
        for (int i = 0; i < n; i++) {
            if(d>x[i]) 
                fl += (m[i] - ((x[i] - d)*(x[i] - d)) ) / ((x[i] - d)*(x[i] - d)) + 1;
            if (d < x[i])
                fr += (m[i] - ((x[i] - d)*(x[i] - d))) / ((x[i] - d)*(x[i] - d)) + 1;
        }
        return -fl + fr;
    }

long double cal1(vector<long double>x, vector<long double>m, long double d) {
        int n = x.size();
        long double fl = 0.0, fr = 0.0;
        for (int i = 0; i < n; i++) {
            if(d>x[i]) 
                fl += (m[i] + ((x[i] - d)*(x[i] - d)) ) / ((x[i] - d)*(x[i] - d)) -1;
            if (d < x[i])
                fr += (m[i] + ((x[i] - d)*(x[i] - d))) / ((x[i] - d)*(x[i] - d)) -1;
        }
        return (abs(-fl + fr)-1e-9);
}

    int main(int argc, char** argv)
    {
        int test_case;
        int T;

        //freopen("input.txt", "r", stdin);
        cin >> T;

        for (test_case = 1; test_case <= T; ++test_case)
        {
            int n; cin >> n;
            vector< long double>x(n), m(n);
            for (int i = 0; i < n; i++) cin >> x[i];
            for (int i = 0; i < n; i++) cin >> m[i];
            long double ans[n];
            for (int j = 0; j < n-1; j++) {
                long double l = x[j], r = x[j + 1], res = 0;
                while (l < r) {
                    long double mid = l + (r-  l) / 2.0;
                    long double net = cal(x, m, mid);
                    if (abs(net) <(double)0.000000000001) {
                        res = mid;
                        break;
                    }
                    if (net < 0) l = mid;
                    else r = mid;
                }
                ans[j] = res;
            }

            cout << "#" << test_case << " " ;
            for(int i=0;i<n-1;i++) cout<< fixed << setprecision(10) << ans[i]<< " ";
            cout<<"\n";

        }
        return 0;//Your program should return 0 on normal termination.
    }