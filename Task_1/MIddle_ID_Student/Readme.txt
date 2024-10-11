The program goes works with the standard library of c plus plus . It shows you  a menu and you choose which option you want. the options are "Converting male into general speech", "Top 10 players" ,  "Drawing some pattern " and " Comparing two files" .



The First option  goes around taking one line from you and convert it into a general speech. It converts it to the opposite pronoun which it has in the pair .as it breaks the whole line into strings and put them in a vector . then loop on each one and see weather is it male pronoun or not. if it is male pronoun , it adds on the male pronoun the word "or" and the female pronoun . then you output the answer with the new changes.


The Second option goes around taking the name of players and their scores and put them in a vector and filtering them to make the top 10 are considered only . and you can show  the list too. Also , you can get the highest score of a certain player you enter his name . this goes through a menu to choose from that sub-options. This is done through struct of "player"(user-defined).
the player contains some attributes as its name and its score. Also, it contains some features as adding a player info (name , score) , printing players and also getting the high score of the player. we put the players  in a vector and check.
 

The Third option talks about drawing a pattern . The Time that code takes is 2 power n as we call twice in the recursive function. The draw goes under certain pattern. The pattern flow is 
when we call the first call it goes under multiple divisions till it reaches the smallest number of power of 2 which is "1". then in every single call it tries to print all the smallest numbers of power of 2 . so the sequence you print the number of power of 2 for the first time then that number print all the smaller numbers of power of 2 .  we take the number that we recurse with it which will be the max number that appears as power of 2 , also it takes the spaces as to start with zero spaces or otherwise. Of course, with some validations.


The Fourth option is about taking 2 files and compare that two files weather are identical or not according to (word to word comparison) or (character to character comparison). The type of comparison are valid and the user chooses which one is suitable. In both comparisons there are some cases are handled and each one according to the type of comparison . For Example , when there is a file subset from a file . if it is in the normal case and there is a difference it prints the difference and the number of line . Of course , there is a validation if the file is in the directory or not. 


The program goes in that flow without ending till the user exit the program.


 