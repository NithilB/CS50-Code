// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        int tile = get_int("Tile to move: ");

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    // TODO
    int count = (d*d)-1;
    int one = 1;
    int two = 2;

    if(((d*d)-1) % 2 == 0){
        
        for (int r = 0; r < d; r++){
            for (int c = 0; c < d; c++){
                if (count > 0){
                    board[r][c] = count;
                    count--;
                }
            }
        }
        
    } else {
        
        for (int a = 0; a < d; a++){
            for (int b = 0; b < d; b++){
                if (count > 0){
                    board[a][b] = count;
                    count--;
                }
            }
        }

        board[d-1][d-2] = two;
        board[d-1][d-3] = one;

    }
    
    board[d-1][d-1] = -1;
}

// Prints the board in its current state
void draw(void)
{
    // TODO
    for(int a = 0; a < d; a++){
        for(int b = 0; b < d; b++){
            if(b == (d-1)){
              printf("%i", board[a][b]);
            } else {
              printf("%i ", board[a][b]);
            }
        }
        printf("\n");
    }
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    // TODO
    int x = 0;
    int y = 0;
    
    for(int r = 0; r < d; r++){
        for(int c = 0; c < d; c++){
            if(tile == board[r][c]){
                x = r;
                y = c;
            }
        }
    }
    
    for(int a = 0; a < d; a++){
        for(int b = 0; b < d; b++){
            if(-1 == board[a][b]){
                if((x + 1 == a && y == b) || (x - 1 == a && y == b) || (x == a && y == b - 1) || (x == a && y == b + 1)){
                    
                    board[a][b] = board[x][y];
                    board[x][y] = -1;
                    return true;
                    
                }
                
            }
        }
    }
    
    return false;
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    // TODO
    int count = 0;
    int won[d][d];
    
    for (int r = 0; r < d; r++){
        for (int c = 0; c < d; c++){
            if (count < ((d*d)-1)){
                won[r][c] = count;
                count++;
            }
        }
    }
    
    int w = 0;
    for (int a = 0; a < d; a++){
        for(int b = 0; b < d; b++){
            if(board[a][b] == won[a][b]){
                w++;
            }
        }
    }
    
    if(w == ((d*d)-1)){
        return true;
    }
    
    return false;
}
