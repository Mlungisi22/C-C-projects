/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include<set>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;


vector<pair<string,int> > getchildren(pair<string,int> s){				//This function returns the children of a node it is given
	
	vector<pair<string,int> > neighbour;								//initilise a vectore to keep the child nodes
	
/*	vector< vector<char> > board;
	
	int count = 0;
	for(int i=0;i<3;i++){
		vector<char> row;
		for(int j=0;j<3;j++){
			
			row.push_back(p.first[i+count]);
			
			count++;
		}
		board.push_back(row);
		count--;
		
	}*/
	
	int index;									
	for(int i=0;i<s.first.length();i++){							//find # in the string/ state
		if(s.first[i]=='#'){
			index=i;
		}
	}
	
	int row,col;													//give position of # in terms of row and col
	row=floor(index/3);
	col=index-row*2-row;
	
	vector<string> moves;												//initilise a vector to keep all possible moves you could make from that state
	
	string moveP[] = {"UP","DOWN","LEFT","RIGHT"};
	

	
		if(row>0){
			moves.push_back(moveP[0]);
		}
		if(row<2){
			moves.push_back(moveP[1]);
		}
		if(col>0){
			moves.push_back(moveP[2]);
		}
		if(col<2){
			moves.push_back(moveP[3]);
		}
		
	
	s.second++;			
				
	for(int k=0;k<moves.size();k++){
		pair<string,int> p=s;
		if(moves.at(k)=="RIGHT"){
			swap(p.first[index],p.first[index+1]);
			neighbour.push_back(p);	
		}else if(moves.at(k)=="LEFT"){
			string s=p.first;
			swap(p.first[index],p.first[index-1]);
			neighbour.push_back(p);
			
			
		}else if(moves.at(k)=="UP"){
			swap(p.first[index],p.first[index-3]);
			neighbour.push_back(p);
		}else if(moves.at(k)=="DOWN"){
			swap(p.first[index],p.first[index+3]);
			neighbour.push_back(p);
		}
			
	}
	
	return neighbour;
	
	
}

int BFS(string begin, string end){
	
	set<string> visited ;									//vector to store visited nodes
	pair<string, int> node;											//a pair of state and cost
	queue<pair<string,int> > frontier;								//queue to keep nodes we are visiting next
	node.first=begin;												//initilise queue with start state
	node.second=0;
	frontier.push(node);
	
	if(node.first==end){
		return 0;
	}																//check goal state
	while(true){													//loop until termination
		
		if(frontier.empty()){										//check if queue is empty and if it is it means we didn't find the goal state else:
		
			return -1;
		}else{														
		
			node = frontier.front();								//set node to whatever is at the front
			frontier.pop();											//pop the node from queue
			visited.insert(node.first);							//push node to expliroed vector

			vector<pair<string,int> > child = getchildren(node);	//create vector to store children of node
			
			for(int j=0;j<child.size();j++){						//for each child set a boolean to false
				bool isPresent=false;
				if(visited.find(child.at(j).first) != visited.end()){
					isPresent=true;
				}
				
				//bool isPresent = (find(explored.begin(), explored.end(), child.at(j)) != explored.end());
				if(!isPresent){										
					if(child.at(j).first==end){					
						return child.at(j).second;					//if the child has not been visited check if its the goal state and return the cost of that child if it is.
					}
					frontier.push(child.at(j));						
				
				}
				
				
			}
			
		}
	}

}

int main(){
	
	string start;cin>>start;
	string end;cin>>end;
	
	
	
	int i=BFS(start, end);
	if(i!=-1){
		cout<<i<<endl;
	}else{
		cout<<"not found"<<endl;
	}
	return 0;
}
