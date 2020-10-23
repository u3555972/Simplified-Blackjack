# C-Blackjack
C++ Blackjack program for COMP2113 Project.

**Chan, Cheuk Hang (3035559725)**

**Shah, Aashana Chetan (3035552155)**

**Game Description: Blackjack**

The goal of the game is to try to get as close as possible to the number 21, inclusively. To do this, each player will be dealt 2 regular cards (2 - A). J, Q, K are all worth 10 while A can be 1 or 11. The rest of the numbers represent its own number. The sum of the points is how much the hand is worth. At the beginning of each round, the player can ask for 1 more card to improve their hand or they can “stay”, keeping their hand. The player closes to 21, or has a sum of 21 with the least amount of cards wins! If the player exceeds 21, then they are “busted” (loses match).

Each player (including 1 opponent) starts with $10,000. Each match’s minimum betting from each player is $1,000. After players receive their initial cards, they can “raise” to bet more money. The other player will have to either match the amount or can “raise” higher. After the other player raises, the 1st player will have to match it and the round commences. Whoever does not want to match loses the round immediately and loses money. Once a round is matched, players can either request a card or reveal or fold (forfeit match). However, if a player cannot pay the minimum or match because they do not have enough money, they must use all their remaining money.

Once one of the players loses all his/her money after a match, they lose. Then, the game ends. The player can choose to restart.

1) Generation of random game sets or events \n
    Random shuffle of the stored cards will occur so as to deal the cards randomly
    The additional cards requested will also be dealt randomly
    Random seed (using the time) for random shuffle
2) Data structures for storing game status
    The amount of money the player has and the amount the computer has will be stored such as to know how much money can be bet. The game may continue until one or     both of the players run out of money. 
        The money will be stored as an integer in the game
        The amount of money used in a game will also be stored as an integer
    The array will also store the cards received and as such the sum can be calculated after each round for each player.
    An array is used to store the different types of cards there are (52 of them).
        The cards will be removed and added to the players array depending on the random shuffle. 
    The user name will also be stored in the string format.
3) Dynamic memory management
    A dynamic array is requested as the length of the game is unknown. After each round the player is prompted to continue playing or quit and after each round.             With each round, additional memory is required to store the money and the cards.
        The cards will first be taken back using the destructor and using pointers and dynamic memory, the new cards will be stored.
    With each additional card requested, additional memory is required.
4) File input/output (e.g., for loading/saving game status)
    Program creates a save file for a user under their name (Output)
        Save file stores how much money they have (both user and AI)
    Program loads save file for a user under their name (Input)
        Save file stores include how much money they have (both user and AI)
        Loads that amount of money to start the game
    Program stores in a file which round the player on (Output)
    Program stores in a file how many matches a player has won so far (Output)
    Program stores in a file how many games have been won so far
        Includes player name and how many games
5) Program codes in multiple files
    File #1: Main Display
        Basically prints out the introduction to the game
        For example, “Welcome to Blackjack!”
    File #2: New user
        If user is new, create a new file with user’s name and give them $10,000
    File #3: Random generator and dealing
        File will use a random seed and shuffle the deck as well as deal the cards to players
    File #4: Display own cards
        Uses array to display cards
    File #5: Request cards
        Can request one extra card and add it to array
    File #6: Raise or stay or match
        Player can raise or stay or match the amount of money
    File #7: Sum calculation
        Calculates the value of each player’s hand
        If it exceeds 21, that player loses
        If both exceeds 21, both players lose money
    File #8: Start another match
    File #9: Display Game Over
        If one of the players runs out of money after a match, they lose the entire game!
    File #10: Display high scores
        Displays which player has won the most games and how many games they have won

