#include <iostream>
#include <string>

//Funtion for check and return first empty position at stack
int checkLastSignPos(char* stack) {
    for (int x=0; x<=2; x++) {
        if (stack[x] == ' ') {
            return x;
        }
    }
    return -1;
}

//Add or remove sign in stack
void addSignStack(char* stack, char sign) {
    
    int lastEmptyPos = checkLastSignPos(stack);//Get last empty pos in stack

    if (lastEmptyPos > 0) {
        if (stack[lastEmptyPos - 1] != sign) {//If last sign at stack is another sign that sign in argument remove last sign at stack
            stack[lastEmptyPos - 1] = ' ';
        }
        else {
            stack[lastEmptyPos] = sign;//Else add new sign at stack
        }
    }
    else {
        stack[lastEmptyPos] = sign;//Add first sign at stack
    }

}

//Function who check stack for filled full signs
bool checkStack(char* stack, char &sign) {
    if ((stack[0] == stack[1]) && (stack[1] == stack[2])) {
        sign = stack[0];
        return true;
    }
    return false;
}

//Function who reset stack
void resetStack(char* stack) {
    stack[0] = ' ';
    stack[1] = ' ';
    stack[2] = ' ';
}

//Manage all operations on data
std::string prepare(std::string stack) {
    
    std::string result;
    char stackBufor[3] = {' ', ' ', ' '};

    for (int x=0; x<stack.size(); x++) {
        addSignStack(stackBufor, stack[x]);//Adding or remove sign to stack
        char signDominated;
        if (checkStack(stackBufor, signDominated) == true) {//Check for full stack
            if (signDominated == '+') { //If whole stack is filled by sign +
                result += '5'; }
            if (signDominated == '-') {//If whole stack is filled by sign -
                result += '1'; }
            resetStack(stackBufor);//Clear stack
        }
    }

    return result;//Return result
}

int main() {

    std::string stack;
    std::cin >>stack;//Get data
    stack = prepare(stack);
    //Under display result
    if (stack.size() > 0) {
        for (int x=0; x<stack.size(); x++) {
            std::cout <<stack[x]<<" " << std::endl;
        }
    }else {
        std::cout <<"BRAK" << std::endl;
    }
    return 0;
}
