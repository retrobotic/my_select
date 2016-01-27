# my_select

#### **/!\ Warning /!\**
This is a first year Epitech project, it is therefore subjected to the "C Norm" wich is a programming style convention created by the school.
Some restriction of this norm are for example "max 25 lines per function and 5 functions per file", "only one instruction per line", "no global variables"
"no system function (recode them to use them)", etc...
The full epitech norm : https://youtrack.jetbrains.com/_persistent/norme-en.pdf?file=74-190945&v=0&c=true
So if some part of the code seems weird in their syntax, it's probably due to this norm.

The goal of this project was to write a program that take a series of parameters, display them and allow the user to move within 
the list of argument with the arrow keys and to select and remove them. The enter key validate and return the chosen arguments in the shell
(to do a "set" for example). 

|input|output|
|-----|------|
|Non selected choice | Normal text|
|Selected choice | Video inverse text|
|Cursor position | Underlined text|

Example of usage:
````
rm `./my_select *`
````

|Allowed functions: |
|-------------------|
| open              |
| close             |
| write             |
| malloc            |
| free              |
| all Ncurse library|

## Grade : 22/20 (I made the bonuses)
