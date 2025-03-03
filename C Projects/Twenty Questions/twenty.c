#include "bst.h"
#include <ctype.h>

struct node* create_game_tree()
{
    struct node* root = NULL;
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");
    return root;
}

void play_game(struct node* root)
{
    struct node* current = root;
    char input;

    printf("Think of a fruit or vegetable. I will try to guess it!\n");

    while (current != NULL)
    {
        if (current->question[0] != '\0')
        {
            //internal node, ask a question
            printf("%s (y/n): ", current->question);
            scanf(" %c", &input);
            input = tolower(input); //just converting any input to lowercase, helps compatibility

            if (input == 'y')
            {
                current = current->left;
            }
            else if (input == 'n')
            {
                current = current->right;
            }
            else
            {
                printf("Invalid input! Please enter 'y' or 'n'.\n");
            }
        }
        else
        {
            //leaf node, make a guess
            printf("%s (y/n): ", current->guess);
            scanf(" %c", input);
            input = tolower(input);

            if (input = 'y')
            {
                printf("I win!\n");
            }
            else
            {
                printf("You win!\n");
            }
            return; //game over
        }
    }
}


int main()
{
    struct node* game_tree = create_game_tree();
    char input;

    printf("Welcome! Press 'q' to quit or any other key to continue:\n");

    while (1) {
        scanf(" %c", &input);
        if (tolower(input) == 'q') {
            printf("Bye Bye!\n");
            break;
        }
        play_game(game_tree);
        printf("\nPress 'q' to quit or any other key to play again:\n");
    }

    free_tree(game_tree);
    return 0;
}