# List of species

Each line in the list represents a single species, starting with the species category (`plant`, `herbivore`, `omnivore`), followed by a one-letter species identifier, followed by the list of the species' characteristics. The list of characteristics differs between the plants and the animals:

| Grammar | Example |
| ---------- | ---------- |
| `plant` _\<one-letter id\> \<regrowth coefficient\> \<energy points\>_ | `plant a 2 10` |
| `herbivore` _\<one-letter id\>_ `[` _\<food chain\>_ `]` _\<max energy level\>_  | `herbivore A [a, b] 20` |
| `omnivore` _\<one-letter id\>_ `[` _\<food chain\>_ `]` _\<max energy level\>_  | `omnivore C [A, D] 40` |

Here's an example list of species that can be used together with [this area map](input/map.txt):

```
plant a 1 5
plant b 3 10
herbivore A [a, b] 20
herbivore B [b] 15
omnivore C [A, D] 40
omnivore D [A, B, C] 30
```
