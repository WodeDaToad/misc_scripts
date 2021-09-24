// this script returns a binary representation of a decimal number
// can be edited for other representations, such as hexidecimal

#include <iostream>
#include <string>

std::string binaryRep(int now){
    if(now == 0){
        return "";
    }else{
        return (binaryRep(now/2) + std::to_string(now%2));
    }
}

std::string binaryString(char* asdf, int siz){
    std::string outp;
    std::string addition;
    for(int c = 0; c < siz; c++){
        int now = *(asdf + c);
        addition = (binaryRep(now));
        int count = 0;
        for(; addition[count] != '\0'; count++){
            continue;
        }
        for(; count < 8; count++){
            addition = '0' + addition;
        }
        outp += (addition + ' ');
    }
    return outp;
}

int main(){
    std::string asciistring = "I like the album, BMV!";
    int isze = 22;
    char *asciichar = new char(isze);
    for(int c = 0; c < isze; c++){
        *(asciichar + c) = asciistring[c];
    }
    
    std::cout << binaryString(asciichar, isze);
    return 0;
}
