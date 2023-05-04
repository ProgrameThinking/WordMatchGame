# To the people looking through this version:

## Here are the requirements for the word match system.
***
* The Word Match Game consists of two types of participants: players and testers (who add words to the game). 
* The game rules are as follows: in each round of the game, the program will display a word based on the level 
of difficulty, and after a certain amount of time, the word will disappear. Player need to input the word that 
was just displayed and disappeared in the corresponding area. If the player inputs the word correctly (i.e. the 
word entered by the player is exactly the same as the word displayed, including capitalization), they pass the round.

## Here is the functionality that I have implemented.
***
The requirements for the attributes of the challenger include: the challenger's name, the number of levels that have been passed, the challenger's experience points, and the challenger's level. Other attributes can be added if necessary. The requirements for the attributes of the questioner include: the questioner's name, the number of questions asked by the questioner, and the level. Other attributes can be added as needed.

###Specific functions include:

* Implement local registration and login for challengers and questioners.
* The program supports multiple registrations, and only one person can log in at the same time.
* Implement game rules: 
    - The questioner adds words to the game. 
    - In each level of the game, the program will display a word according to the difficulty of the level. After a certain period of time, the word will disappear. The player needs to enter the word that was just displayed and disappeared in the corresponding place. If the player enters correctly, the level is passed.
    - Any role can query all players and testers, and search for corresponding players and testers according to their attributes.
    - Challengers can be ranked based on the number of levels passed, experience, level, etc., while questioners can be ranked based on the number of questions asked and their level.

Please refer to the code and design report for detailed design.