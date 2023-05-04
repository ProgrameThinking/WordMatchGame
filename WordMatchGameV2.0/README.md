
# To the people looking through this version:

## Here is the functions that I have implemented：
***
The challenger is the game player, and registered and logged-in players can play the word elimination game in the system. The difficulty of each level should increase, which can be reflected in one or more of the following three conditions: 
* 1. The difficulty of the words can increase or remain the same (i.e. the length of the words becomes longer or remains the same);  
* 2. The number of rounds increases (i.e. the number of words to be passed increases, for example, in the first three levels, only one word needs to be passed to complete the level, while in later levels, two, three, or even more words need to be passed to complete the level);  
* 3. The display time of the words becomes shorter (the display time becomes shorter with the increase of levels). \

The player will gain a certain amount of experience points for each level they pass. The experience points will be determined by the level number and the time spent on passing the level. When the accumulated experience points reach a certain level, the player's level will increase. If the player fails to pass a level, they need to try again.

The game comes with a built-in word bank, and registered question setters can add new words to the system, which will expand the word bank. However, existing words cannot be added again (the words in the word bank form a word pool, but it is recommended to organize and store them based on the length of the words. Each time a question is generated, the system randomly selects a word with an appropriate length from the word pool according to the difficulty level of the level). Every time a question is successfully added, the number of questions added by the question setter will be updated. The level of the question setter will be upgraded based on the number of successfully added questions.

Please refer to the code and design report for detailed design.
