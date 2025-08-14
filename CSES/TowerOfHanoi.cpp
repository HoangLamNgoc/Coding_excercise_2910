#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;

void Sol(int n) {
    vector<pair<int,int>> moves;
    stack<int> left, mid, right;

    long long dem = 0;
    const int maxN = 1e4;

    left.push(maxN);
    right.push(maxN);
    mid.push(maxN);

    for ( int i = n; i >= 1; --i) {
        left.push(i);
    }

    while ((int)right.size() != n + 1) {
        dem++;

        if (dem % 2 == 1) {
            if (n % 2 == 0) {
                if (left.top() == 1) {
                    mid.push(left.top());
                    left.pop();
                    moves.push_back({1,2});
                }
                else if (mid.top() == 1) {
                    right.push(mid.top());
                    mid.pop();
                    moves.push_back({2,3});
                }
                else {
                    left.push(right.top());
                    right.pop();
                    moves.push_back({3,1});
                }
            }
            else {

                if (left.top() == 1) {
                    right.push(left.top());
                    left.pop();
                    moves.push_back({1,3});
                }
                else if (right.top() == 1) {
                    mid.push(right.top());
                    right.pop();
                    moves.push_back({3,2});
                }
                else {
                    left.push(mid.top());
                    mid.pop();
                    moves.push_back({2,1});
                }
            }
        }

        else {
            if (mid.top() != 1 && (mid.top() < left.top() || mid.top() < right.top())) {
                if (mid.top() < left.top()) {
                    left.push(mid.top());
                    mid.pop();
                    moves.push_back({2,1});
                }

                else {
                    right.push(mid.top()); mid.pop();
                    moves.push_back({2,3});
                }
            }
            else if (right.top() != 1 && (right.top() < left.top() || right.top() < mid.top())) {
                if (right.top() < mid.top()) {
                    mid.push(right.top());
                    right.pop();
                    moves.push_back({3,2});
                }
                 else {
                    left.push(right.top());
                    right.pop();
                    moves.push_back({3,1});
                }
            }
            else if (left.top() != 1 && (left.top() < mid.top() || left.top() < right.top())) {
                if (left.top() < right.top()) {
                    right.push(left.top());
                    left.pop();
                    moves.push_back({1,3});
                }
                 else {
                    mid.push(left.top()); 
                    left.pop();
                    moves.push_back({1,2});
                }
            }
        }
    }
    cout << dem << endl;

    for (auto [u,v] : moves) {
        cout << u << " " << v << endl;
    }
}



int main()
{
    cin >> n;
    Sol(n);
    return 0;
}
