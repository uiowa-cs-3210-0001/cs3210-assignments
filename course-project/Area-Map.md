# Area map

Area map is a two-dimensional grid of characters, where each character describes the geographical makeup of the space it's occupying or, alternatively, designates the current position of a living organism.

Specifically, the space character (` `) represents open space, the tilde character (`~`) represents water, and the hash character (`#`) represents an obstacle. Living organisms (plants and animals) are referenced using their corresponding one-letter identifiers as defined in the [list of species](Species.md).

Here's an example of a 49x13 area map ([source](input/map.txt)) that corresponds to [this](input/species.txt) list of species:

```
~~~                            ###          aaaaa
~~   D             B   B      ###       C     aaa
~~          aa aaa   B      ###      aa         a
~~~          aaa aaa       ###   D   aaa         
~~~~~~        aaa aaa     ###                A   
~~~~~~~~         aaa      ###          ~~   A    
~~~~~~~~~        A        ###        ~~~~~~      
~~~~~~~~~       A          ###       ~~~~~~~     
~~~~~~~~         B   C                 ~~~~~~    
~~~~~~~                  bbbb        bb ~~~~~~   
~~~~~   C      aaaa      bb  bb       bb   ~~~   
~~~~  C       aaa aa               D   b    ~    
~~~          aaa aaa      bbbbbb      bb      C   
```
