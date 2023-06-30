/*
Check if the brackets are balanced or not.

T.C - O(N)
S.C - O(N)
*/

bool isValidParenthesis(string expression)
{
    stack<char> st;
    for(char c : expression) {
        if(c == '(' || c == '{' or c == '[')
            st.push(c);
        else {
          if (st.empty())
            return false;

          int t = st.top();
          if ((t == '(' && c == ')') 
          or (t == '[' && c == ']') 
          or (t == '{' && c == '}'))
            st.pop();
          else 
            return false;  
        }
    }

    if(st.empty())
        return true;
    return false;
}