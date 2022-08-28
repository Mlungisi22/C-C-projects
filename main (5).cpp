#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<array>

using namespace std; 

int gethash(std::string input){
    char inputs[10];
    int count=-1;
    for(char letter:input){
        count++;
        inputs[count]=letter;
        if(letter=='#'){
            return count;
        }
    }
    return count;
} 

std::string swapping(std::string input,std::string direction){
    
    char inuts[10];
    std::string answer="";
    int incr=-1;
    for(char word:input){
        incr++;
        inuts[incr]=word;
    }
    char swapA,swapB;
    
    
    int location=gethash(input);
    if(direction=="UP"){
        //shift hash UP
        switch(location){
            case 3:
                swapA=inuts[0];
                swapB=inuts[location];
                inuts[location]=swapA;
                inuts[0]=swapB;
                break;
            case 4:
                swapA=inuts[1];
                swapB=inuts[location];
                inuts[location]=swapA;
                inuts[1]=swapB;
                break;
            case 5:
                swapA=inuts[2];
                swapB=inuts[location];
                inuts[location]=swapA;
                inuts[2]=swapB;
                break;  
            case 6:
                swapA=inuts[3];
                swapB=inuts[location];
                inuts[location]=swapA;
                inuts[3]=swapB;
                break;
            case 7:
                swapA=inuts[4];
                swapB=inuts[location];
                inuts[location]=swapA;
                inuts[4]=swapB;
                break;
            case 8:
                swapA=inuts[5];
                swapB=inuts[location];
                inuts[location]=swapA;
                inuts[5]=swapB;
                break;
            default:
                return input;
            }
        for(int i=0;i<sizeof(inuts);i++){
            answer+=inuts[i];
            }
        return answer;
        
    }
    else if (direction=="DOWN"){
            //shift hash down swap with buttom element
        switch (location) {
            case 0:
                swapA = inuts[3];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[3] = swapB;
                break;
            case 1:
                swapA = inuts[4];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[4] = swapB;
                break;
            case 2:
                swapA = inuts[5];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[5] = swapB;
                break;
            case 3:
                swapA = inuts[6];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[6] = swapB;
                break;
            case 4:
                swapA = inuts[7];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[7] = swapB;
                break;
            case 5:
                swapA = inuts[8];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[8] = swapB;
                break;
            default:
                return input;
        }
        for(int i=0;i<sizeof(inuts);i++){
            answer+=inuts[i];
        }
        return answer;
        
    }

    else if (direction == "LEFT") {
        //shift has to the left swap with left eleement
        switch (location) {
            case 1:
                swapA = inuts[0];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[0] = swapB;
                break;
            case 2:
                swapA = inuts[1];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[1] = swapB;
                break;
            case 4:
                swapA = inuts[3];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[3] = swapB;
                break;
            case 5:
                swapA = inuts[4];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[4] = swapB;
                break;
            case 7:
                swapA = inuts[6];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[6] = swapB;
                break;
            case 8:
                swapA = inuts[7];
                swapB = inuts[location];
                inuts[location] = swapA;
                inuts[7] = swapB;
                break;
            default:
                return input;
        }
        for(int i=0;i<sizeof(inuts);i++){
            answer+=inuts[i];
            }
        return answer;
        
    }
    else if(direction=="RIGHT"){
            //shift has to the right swap with right eleement
            if (location==2 || location==5 || location==8) {
                //do nothing 
            }
            else {
                switch (location) {
                case 0:
                    swapA = inuts[1];
                    swapB = inuts[location];
                    inuts[location] = swapA;
                    inuts[1] = swapB;
                    break;
                case 1:
                    swapA = inuts[2];
                    swapB = inuts[location];
                    inuts[location] = swapA;
                    inuts[2] = swapB;
                    break;
                case 3:
                    swapA = inuts[4];
                    swapB = inuts[location];
                    inuts[location] = swapA;
                    inuts[4] = swapB;
                    break;
                case 4:
                    swapA = inuts[5];
                    swapB = inuts[location];
                    inuts[location] = swapA;
                    inuts[5] = swapB;
                    break;
                case 6:
                    swapA = inuts[7];
                    swapB = inuts[location];
                    inuts[location] = swapA;
                    inuts[7] = swapB;
                    break;
                case 7:
                    swapA = inuts[8];
                    swapB = inuts[location];
                    inuts[location] = swapA;
                    inuts[8] = swapB;
                    break;
                default:
                    return input;
                }
            }
        for(int i=0;i<sizeof(inuts);i++){
            answer+=inuts[i];
        }
        return answer;
        
    }
    else{
            return input;
        }    
}

std::string availableactions(string actions){
    int location=gethash(actions);
    string store="";
    switch(location){
        case 0:
            store+="DOWN,RIGHT";
            return store;
            break;
        case 1:
            store+="DOWN,LEFT,RIGHT";
            return store;
            break;
        case 2:
            store+="DOWN,LEFT";
            return store;
            break;
        case 3:
            store+="UP,DOWN,RIGHT";
            return store;
            break;
        case 4:
            store+="UP,DOWN,LEFT,RIGHT";
            return store;
            break;
        case 5:
            store+="UP,DOWN,LEFT";
            return store;
            break;
        case 6:
            store+="UP,RIGHT";
            return store;
            break;
        case 7:
            store+="UP,LEFT,RIGHT";
            return store;
            break;
        case 8:
            store+="UP,LEFT";
            return store;
            break;
        default:
            store+="UP,DOWN,LEFT,RIGHT";
            return store;
    }
}

void splitstr(string str, string deli = ",")
{
    int start = 0;
    int end = str.find(deli);
    while (end != -1) {
        cout << str.substr(start, end - start) << endl;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    cout << str.substr(start, end - start);
}
void print(std::string input){
   
    std::cout<<"\n";
    int counter=0;
    for(char letters:input){
        counter++;
        std::cout<<letters;
        std::cout<<" ";
        if(counter==3||counter==6||counter==9){
            std::cout<<"\n";
        }
    }
}
int main(){
    std::string inputs;
    std::cin>>inputs;
    std::string direction;
    std::cin>>direction;
    int cost = 1;
    string option=availableactions(inputs);
    //splitstr(option);
    
    int location=gethash(inputs);//finding hash
    std::cout<<cost;
    std::string postmovement=swapping(inputs,direction);//the string after the move
    print(postmovement);//display the string 
    return 0;
}
