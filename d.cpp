/*
author: Apoorv Singh
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef vector <long long> vi;
typedef pair <long long, long long> pii;
#define pb push_back   
#define all(c) c.begin(), c.end()
#define For(i, a, b) for (long long i = a; i < b; ++i)
#define Forr(i, a, b) for (long long i = a; i > b; --i)
#define um unordered_map
#define F first
#define S second
#define int long long
#define inf LLONG_MAX
#define endl "\n"
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;    
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

template <class X>
void printarr(X arr[], int n) 
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

template <typename X> ostream& operator << (ostream& x,const vector<X>& v){ for (X a : v) x << a << ' '; return x;} 
template <typename X, typename Y> ostream& operator << (ostream& x, const vector< pair<X, Y> >& v) {for (pair <X, Y> it : v) x << it.first << ' ' << it.second << endl; return x;} 
template <typename T, typename S> ostream& operator << (ostream& os, const map<T, S>& v) { for (pair <T, S> it : v) os << it.first << " => " << it.second << endl; return os; }
 
template <class T, class cmp = less<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
 
int modulo = 1e9 + 7;

int fpow(int a, int n) 
{
    int ans = 1;
    while (n) 
    {
        if (n&1) ans = (ans*a)%modulo;
        a = (a*a)%modulo; n = n >> 1;
    }
    return ans;
}

signed main() 
{
    fast_io();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while (t--)
    {
        int r,c; cin >> r >> c;
        string arr[r];
        int cnt = 0;
        For(i,0,r)
        {
            cin >> arr[i];
            For(j,0,c) 
            {
                if (arr[i][j] == 'A') 
                    ++cnt;
            }
        }
        if (cnt == 0)
        {
            cout << "MORTAL" << endl;
            continue;
        }
        if (cnt == r*c)
        {
            cout << 0 << endl;
            continue;
        }
        if (min(r,c) == 1)
        {
            if (arr[0][0] == 'A' or arr[r-1][c-1] == 'A')
                cout << 1 << endl;
            else
                cout << 2 << endl;
            continue;
        }
        int full_filled = 0;
        For(i,0,r)
        {
            int curr = 0, cnt = 0;
            For(j,0,c)
            {
                if (arr[i][j] == 'A')
                    ++cnt;
            }
            if (cnt == c)
            {
                if (i == 0 or i == r-1)
                    curr = 2;
                else
                    curr = 1;
            }
            full_filled = max(full_filled, curr);
        }
        For(j,0,c)
        {
            int curr = 0, cnt = 0;
            For(i,0,r)
            {
                if (arr[i][j] == 'A')
                    ++cnt;
            }
            if (cnt == r)
            {
                if (j == 0 or j == c-1)
                    curr = 2;
                else
                    curr = 1;
            }
            full_filled = max(full_filled, curr);
        }
        if (full_filled == 2)
        {
            cout << 1 << endl;
            continue;
        }
        if (full_filled == 1)
        {
            cout << 2 << endl;
            continue;
        }
        if (arr[0][0] == 'A' or arr[0][c-1] == 'A' or arr[r-1][c-1] == 'A' or arr[r-1][0] == 'A')
        {
            cout << 2 << endl;
            continue;
        }
        int edge = 0;
        For(j,0,c)
        {
            if (arr[0][j] == 'A' or arr[r-1][j] == 'A')
            {
                edge = 1;
                break;
            }
        }
        For(i,0,r)
        {
            if (arr[i][0] == 'A' or arr[i][c-1] == 'A')
            {
                edge = 1;
                break;
            }
        }
        if (edge) cout << 3 << endl;
        else cout << 4 << endl;
    }
    return 0;
}
