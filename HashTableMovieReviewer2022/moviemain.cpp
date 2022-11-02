#include <iostream>
#include <fstream>
#include "shphashtable.h"

using namespace std;

void loadReviews(shphashtable& table, string filename){
    ifstream f(filename);
    string line;
    int score;
    while(f >> score){
        getline(f, line);
        string word = "";
        for (int i=0; i<line.length(); i++){
            if (line[i] == ' '){
                if (word != "") table.put(word, score);
                word = "";
            }
            else word += line[i];
        }
    }
}

void guessRating(shphashtable& reviews, string review){
    string word = "";
    double sum = 0;
    int count = 0;
    for (int i=0; i<review.length(); i++){
        if (review[i] == ' '){
            if (word != ""){
                if (reviews.contains(word)){
                    sum += reviews.getAverageScore(word);
                    count++;
                }
            }
            word = "";
        }
        else word += review[i];
    }
    sum += reviews.getAverageScore(word);
    count++;

    cout << "The average score for that review is " << 1.0*sum/count << endl;

}

int main() {
    cout << "Hello, Movie Reviews!" << endl;
    shphashtable reviews(10007);

    loadReviews(reviews, "reviews.txt");


    reviews.printStats();
    string response;
    cout << "Enter a review: ";
    getline(cin, response);
    guessRating(reviews, response);



    return 0;
}