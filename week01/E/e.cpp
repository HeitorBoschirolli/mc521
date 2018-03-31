#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        long max_size = 0;
        stack<long> h_stack;
        stack<long> p_stack;
        long size;

        long i = 0;
        while (i < heights.size()) {
            if (h_stack.empty() || heights[i] > h_stack.top()) {
                h_stack.push(heights[i]);
                p_stack.push(i);
                i++;
            }
            else if (heights[i] == h_stack.top()){
                i++;
            }
            else {
                int last_position = -1;
                while((!h_stack.empty()) && (h_stack.top() > heights[i])) {
                    size = h_stack.top() * (i - p_stack.top());
                    if (size > max_size) {
//                        cout << "change: " << i << endl;
//                        cout << "area: " << size << endl;
                        max_size = size;
                    }
                    h_stack.pop();
                    last_position = p_stack.top();
                    p_stack.pop();
                }
                p_stack.push(last_position);
                h_stack.push(heights[i]);
                i++;
            }
        }

        while (!h_stack.empty()) {
//            i = to_do.top() + 1;
            size = h_stack.top() * (i - p_stack.top());
            h_stack.pop();
            p_stack.pop();
            if (size > max_size) {
                max_size = size;
            }
//            while(heights[to_do.top()] > heights[i]) {
//                size = heights[to_do.top()] * (i - to_do.top());
//                if (size > max_size) {
//                        cout << "change: " << i << endl;
//                        cout << "area: " << size << endl;
//                    max_size = size;
//                }
//                to_do.pop();
//            }
        }
        cout << max_size << endl;
    }

    return 0;
}