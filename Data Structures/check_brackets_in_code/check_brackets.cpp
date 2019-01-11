#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int flag = 0;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket b (next,position);
            // b.type = next;
            // b.position = position;
            opening_brackets_stack.push(b);
            // counter = position;
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty()){
                std::cout<<position+1<<"\n";
                flag = 1;
                break;
            }else{
                Bracket check = opening_brackets_stack.top();
                if(check.Matchc(next)){
                    opening_brackets_stack.pop();
                }else{
                    std::cout<<position+1<<"\n";
                    flag = 1;
                    break;
                }
                // if(next == ')'){
                //     if(check.type == '('){
                //         opening_brackets_stack.pop();
                //     }else{
                //         std::cout<<position+1<<"\n";
                //         flag = 1;
                //         break;
                //     }
                // }else if(next == ']'){
                //     if(check.type == '['){
                //         opening_brackets_stack.pop();
                //     }else{
                //         std::cout<<position+1<<"\n";
                //         flag = 1;
                //         break;
                //     }
                // }else{
                //     if(check.type == '{'){
                //         opening_brackets_stack.pop();
                //     }else{
                //         std::cout<<position+1<<"\n";
                //         flag = 1;
                //         break;
                //     }
                // }
            }
        }
    }

    // Printing answer, write your code here
    if(flag == 0){
        if(opening_brackets_stack.empty()){
            std::cout<<"Success"<<"\n";
        }else{
            Bracket c = opening_brackets_stack.top();
            std::cout<< c.position + 1<<"\n";
        }
    }

    return 0;
}
