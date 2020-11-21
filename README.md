# C++ Blackjack
C++ Blackjack program for COMP2113 Project.

**Chan, Cheuk Hang (3035559725)**

**Shah, Aashana Chetan (3035552155)**

**Game Description: Blackjack**

The goal of the game is to try to get as close as possible to the number 21, inclusively. To do this, each player will be dealt 2 regular cards (2 - A). J, Q, K are all worth 10 while A can be 1 or 11. The rest of the numbers represent its own number. The sum of the points is how much the hand is worth. At the beginning of each round, the player can ask for 1 more card to improve their hand or they can “stay”, keeping their hand. The player closes to 21 wins! If the player exceeds 21, then they are “busted” (loses match). If both player and dealers are tied, none of them receives the money and it goes to the "House".

Each player (including 1 opponent) starts with $10,000. Each match’s minimum betting from each player is $1,000. After the player receives their initial cards, they can “raise” to bet more money. The dealer will always match the raised amount, then the round commences. However, if a player cannot pay the minimum or match because they do not have enough money, they must use all their remaining money. Same goes for the dealer.

Once one of the players loses all his/her money after a match, they lose. Then, the game ends. The player can choose to restart.

1) Generation of random game sets or events <br />
    - Random shuffle of the stored cards will occur so as to deal the cards randomly. <br />
    - Random seed (using the time) for random shuffle. <br />
2) Data structures for storing game status <br />
    - The amount of money the player has and the amount the dealer has will be stored to know how much money can be bet. The game may continue until either the player or the dealer runs out of money. <br />
        - The money will be stored as an integer in the game. <br />
        - The amount of money used in a game will also be stored as an integer. <br />
    - The array will also store the cards received and as such the sum can be calculated after each round for each player.  <br />
    - An array is used to store the different types of cards there are (52 of them).  <br />
        - The cards will be removed and added to the players array depending on the random shuffle. <br />
    - The user name will also be stored in the string format.  <br />
3) Dynamic memory management <br />
    - A dynamic array is requested for the string array. By doing this, the main deck, player's deck, and dealer's deck are always updated without needing it to be returned (which caused some problems). <br />
    - With each additional card requested, additional memory is required.<br />
4) File input/output (e.g., for loading/saving game status)<br />
    - Program creates a save file for a user under their name (Output)<br />
        - Save file stores how much money they have (both player and dealer)<br />
    - Program loads save file for a user under their name (Input)<br />
        - Save file stores include how much money they have (both player and dealer)<br />
        - Loads that amount of money to start the game<br />
5) Program codes in multiple files<br />
    - File #1: Main Display<br />
        - Basically prints out the introduction to the game<br />
        - For example, “Welcome to Blackjack!”<br />
    - File #2: Deck <br />
        - Constructs, shuffles, distribute deck to players and calculates the value of each hand
    - File #3: New user<br />
        - If user is new, create a new file with user’s name and give them $10,000<br />
