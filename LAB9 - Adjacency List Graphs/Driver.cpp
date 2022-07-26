/*
	Title:    Driver.cpp
	Author:   Keegan Farkas
	Date:     April 15, 2022
	Purpose:  To read in values from a file and turn them into a graph
*/
#include <iostream>
#include <fstream>
#include "GraphList.h"
using namespace std;

int main(){
    int numVertices, vertice1, vertice2;

    ifstream infile;
    infile.open("graph.txt");

    if(!infile){
        cerr << "Error opening file.";
        return -1;
    }

    infile >> numVertices;

    GraphList graph(numVertices);

    while(infile >> vertice1 >> vertice2){
        graph.addEdge(vertice1, vertice2);
    }

    graph.printGraph();

    return 0;
}