/* dictlookup.c
 * sourcefile for dictlookup, a program implementing a dictionary and assoc-
 * iated functions.
 *
 * An example program from Kochan, Stephen G., "Programming in C 3rd ed.,"
 * Sams publishing, page 220.
 *
 * Programmer: Mark Crapser.
 *
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct entry
{
    char word[15];
    char definition[50];
};

int lookup(const struct entry dictionary[], const char search[],
        const int entries);



int main(int argc, char *argv[]) {

    const struct entry dictionary[100] =
    {{"aardvark", "a burrowing African animal"          },
        {"abyss", "a bottomless pit"                    },
        {"acumen", "mentally sharp; keen"               },
        {"addle", "to become confused"                  },
        {"aerie", "a high nest"                         },
        {"affix", "to append; attach"                   },
        {"agar", "a jelly made from seaweed"            },
        {"ahoy", "a nautical call of greeting"          },
        {"aigrette", "an ornimental cluster of feathers"},
        {"ajar", "partially opened"                     }};

    char word[10];
    int entries = 10;
    int entry;

    printf("\nEnter word: ");
    scanf("%14s", word);

    entry = lookup(dictionary, word, entries);

    if(entry != -1)
        printf("%s\n", dictionary[entry].definition);
    else
        printf("Sorry, the word %s is not in my dictionary.\n", word);


    return(0);
}



int lookup(const struct entry dictionary[], const char search[],
        const int entries) {

    int i = 0;

   for(i = 0; i < entries; ++i)
      if(strcmp(search, dictionary[i].word))
              return(i);

    return(-1);
}













