class MyQueue {
    stack<int> s1; // for push
    stack<int> s2; // for pop/peek

public:
    MyQueue() {

    }

    void push(int x) { // O(1)
        s1.push(x);
    }

    int pop() { // amortized O(1)
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int ans = s2.top();
        s2.pop();
        return ans;
    }

    int peek() { // amortized O(1)
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

