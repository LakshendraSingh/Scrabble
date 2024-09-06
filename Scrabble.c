#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
//important libraries

// scores of each letter
int Marks[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//prototype of function to compute score
int compute_score(string w);

int main (void)
{
    //get user input
    string w1 = get_string("Player 1 Enter Your Word : ");
    string w2 = get_string("Player 1 Enter Your Word : ");

// send w1, w2 user inputs to function top compute scores
    int s1 = compute_score(w1);
    int s2 = compute_score(w2);

// display result
    if (s1 > s2)
    {
        printf("Player 1 wins!\n");
    }
    else if (s1 < s2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// compute score of a word
int compute_score(string w)
{
    //set starting score to 0
    int score = 0;
    //itterate through each letter of the word until the last letter
    for (int i = 0, len = strlen(w); i < len ; i++)
    {
        if (isupper(w[i]))
        {
            //add points to score of player after checking with Marks array (for upper case letters)
            score += Marks[w[i]-'A'];
        }
        else if (islower(w[i]))
        {
            //add points to score of player after checking with Marks array (for lower case letters)
            score += Marks[w[i]-'a'];
        }
    }
    return score;
}
