#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from players
    printf("Please input a player number between 2 and 4\n");

    int num_players;
    do
    {
        num_players = atoi(get_string("Number of players: "));
    }
    while (num_players < 2 || num_players > 4);

    int p_num = 1;
    string words[num_players];


    for (int i = 0; i < num_players; i++)
    {
        string word = get_string("Player %i %s", p_num, ": ");
        words[i] = word;
        p_num++;
    }

    // Score word
    int scores[num_players];

    for (int f = 0; f < num_players; f++)
    {
        scores[f] = compute_score(words[f]);
    }

    // Prints the winner
    int flag = 0;

    for (int i = 0; i < num_players; i++)
    {
        for (int j = i + 1; j < num_players; j++)
        {
            if (scores[i] == scores[j])
            {
                flag = 1;
                i += 1;
                j += 1;
                printf("There was a tie! between players %d and %d\n", i, j);

            }
        }
    }

    if (flag == 0)
    {
        int big = scores[0];
        int pos = 1;

        for (int l = 1; l < num_players; l++)
        {
            if (big < scores[l])
            {
                big = scores[l];
                pos = l + 1;
            }
        }
        printf("The winner is: Player %i\n", pos);
    }

}

int compute_score(string word)
{
    // Compute and return score for string
    int scores = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            scores += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            scores += POINTS[word[i] - 'a'];
        }
    }
    return scores;
}
