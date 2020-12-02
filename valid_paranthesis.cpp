class Solution {
public:
    bool isValid(string s) {
        int i=0;
        stack <char> stack; //vector of satck can be used both gives simliar results
        if(s.length() == 0){   //test conditions
        return true;
    }
        if(s.length() == 1){
        return false;
    }
        while(i<s.length())
        {
            if (s[i]==')'|| s[i]=='}'||s[i]==']') //if closing bracket check if top element of
            {  if(stack.size() == 0 ) return false;  //stack is same type's opening bracket
               if(s[i] == '}' && stack.top() != '{') return false;
               if(s[i] == ')' && stack.top() != '(') return false;
               if(s[i] == ']' && stack.top() != '[') return false;
               stack.pop();  //if same type opening bracket is found we found a valid
                 i++;        //sub expression so will pop the stack
                   }
          else{     //if character is opening bracket push it onto stack
              stack.push(s[i]);
                  i++;
          }
        }
         if(stack.empty())  //if stack is empty it implies that we found every opening bracket
            return true;    //with a closing bracket
          else    //if not empty it means it is left oever with unclosed brackets
             return false;
    }
};
