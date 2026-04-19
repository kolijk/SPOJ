#include <iostream>

//Sign is letter or number or $
bool var1(char sign) {

    if (sign == '$' || (sign >= '0' && sign <= '9') || (sign >= 'A' && sign <= 'Z') || (sign >= 'a' && sign <= 'z')) { 
        return true;
    }

    return false;
}

//Sign is number
bool var2(char sign) {

    if (sign >= '0' && sign <= '9') {
        return true;
    }

    return false;
}

//Sign is samogloska
bool var3(char sign) {

    if (sign == 'a' || sign == 'e' || sign == 'i' || sign == 'o' || sign == 'u' || sign == 'y' || sign == 'A' || sign == 'E' || sign == 'I' || sign == 'O' || sign == 'U' || sign == 'Y') {
        return true;
    }

    return false;
}

std::string remove_sign(int pos, std::string txt) {
    std::string bufor;

    for (int x = 0; x < txt.size(); x++) {
        if (x != pos) {
            bufor += txt[x];
        }
    }

    return bufor;
}

std::string prepareVariable(std::string variableName, int lengthVariableNameMax) {
    
    std::string result = variableName;

    //var1
    if (result.size() > lengthVariableNameMax) {
        for (int x = result.size() - 1; x > 0 && result.size() > lengthVariableNameMax; x--) {
            if (var1(result[x]) == false) {
                result = remove_sign(x, result);
            }
        }

    }

    //var2
    if (result.size() > lengthVariableNameMax) {
        for (int x = result.size() - 1; x > 0 && result.size() > lengthVariableNameMax; x--) {
            if (var2(result[x]) == true) {
                result = remove_sign(x, result);
            }
        }
    }

    //var3
    int firstSamogloskaReached = -1;
    return1:
    if (result.size() > lengthVariableNameMax) {
        for (int x = 0; x < result.size() && result.size() > lengthVariableNameMax; x++) {
            if (var3(result[x]) == true) {
                if (firstSamogloskaReached == -1) {
                    firstSamogloskaReached = x;
                }
                else {
                    if (x != firstSamogloskaReached) {
                        result = remove_sign(x, result);
                        goto return1;
                    }
                }
            }
        }
    }

    //var4
    for (int x = result.size() - 2; x > 0 && result.size() > lengthVariableNameMax; x--) {
        result = remove_sign(x, result);
    }


    return result;

}

int main()
{
    
    std::string variableName;
    int lengthVariableNameMax;

    std::cin >> lengthVariableNameMax;
    std::cin >> variableName;

    std::cout <<prepareVariable(variableName, lengthVariableNameMax)<<std::endl;

}
