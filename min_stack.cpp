//MinStack in O(1)
class MinStack {
public:
    vector<int> a, b;
    MinStack() {   //constructor
        a = b = {};
    }

    void push(int x) {
        a.push_back(x);
        if(b.empty()) b.push_back(x);  //first element
        else {
            int newMin = min(x, *b.rbegin());  //min of added value and last element in b
            b.push_back(newMin);
        }
    }

    void pop() {
        a.pop_back();
        b.pop_back();
    }

    int top() {
        return *a.rbegin();
    }

    int getMin() {
       return *b.rbegin();   //gives you min value of stack till that point after popping
    }
};

//b is the duplicate variable to push back only the min values of stack a, values in descending order
//*b.rbegin() --> gives the last element
//while popping b gives always the min value in stack as its top values
