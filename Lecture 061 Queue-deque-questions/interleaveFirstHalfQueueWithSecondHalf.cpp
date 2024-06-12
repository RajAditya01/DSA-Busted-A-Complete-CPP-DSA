//(HW):  https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        stack<int> st;
        int n = q.size() / 2;

        // Step 1: Move the first half of the queue to the stack
        for(int i = 0; i < n; i++){
            int item = q.front();
            q.pop();
            st.push(item);
        }

        // Step 2: Move elements from stack back to queue
        while(!st.empty()){
            int item = st.top();
            st.pop();
            q.push(item);
        }

        // Step 3: Move the first half of the queue to the back of the queue
        for(int i = 0; i < n; i++){
            int item = q.front();
            q.pop();
            q.push(item);
        }

        // Step 4: Interleave the elements
        for(int i = 0; i < n; i++){
            st.push(q.front());
            q.pop();
        }

        while(!st.empty()){
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }

        // Convert queue to vector for returning
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};
