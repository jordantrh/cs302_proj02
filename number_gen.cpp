
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {

    // 10
    ofstream of = ofstream("in_10.txt");
    int size = 10;

    for (int i = 0; i < size; i++) {
        of << rand() % 10000 << '\n';
    }


    // 100
    of = ofstream("in_100.txt");
    size = 100;

    for (int i = 0; i < size; i++) {
        of << rand() % 10000 << '\n';
    }


    // 1,000
    of = ofstream("in_1grand.txt");
    size = 1000;

    for (int i = 0; i < size; i++) {
        of << rand() % 10000 << '\n';
    }


    // 10,000
    of = ofstream("in_10grand.txt");
    size = 10000;

    for (int i = 0; i < size; i++) {
        of << rand() % 10000 << '\n';
    }


    //100,000
    of = ofstream("in_100grand.txt");
    size = 100000;

    for (int i = 0; i < size; i++) {
        of << rand() % 10000 << '\n';
    }


    //1,000,000
    of = ofstream("in_1mil.txt");
    size = 1000000;

    for (int i = 0; i < size; i++) {
        of << rand() % 10000 << '\n';
    }


    //10,000,000
    of = ofstream("in_10mil.txt");
    size = 10000000;

    for (int i = 0; i < size; i++) {
        of << rand() % 10000 << '\n';
    }

}