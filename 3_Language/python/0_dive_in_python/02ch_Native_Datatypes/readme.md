#Native DataTypes
- Booleans: True or False
- Numbers: integers,floats, fractions or complex numbers
- String: sequence of Unicode characters
- Bytes and byte array:
- Lists: ordered sequences of values
- Tuple: ordered. immutable sequence of values
- Sets: unordered bags of values
- Dictionaries: unordered bags of key-value pairs


## Booleans:
- True and False
- do not treat them as number
## Numbers
- type()
- isinstance(1,int)
### Coercing Integers to Floats and Vice-versa
- float(2)
- int(2.0)
- floating point number are accurate to 15 decimal places
- integers can be arbitrarily large
### Fraction
- import fractions
- fractions.Fraction(1,3)
### Numbers in Boolean Context
- zero values are false
- non-zero values are true

## Lists
- can hold arbitrary objects and can expand dynamically as new items are added
- create lists
    - a_list=['a','b','c']
- obtain value
    - a_list[0]
- slicing a list
    - a_list[i1:i2]
        - a_list[i1] is the first element choose
        - a_list[i2] is the first element throw
- Adding Items
    - a_list=a_list+[..]
        - extra memory
    - append()
        - a item
    - extend()
        - a list
    - insert()
- Seaching value
    - count()
    - 'new' in a_list
    - index()
- Removing items
    - del
    - remove
        - fd
    - pop()
        - calling pop on an empty list raise an exception
- In Boolean Context
    - an empty list is false

##Tuple
- a=("a","b","z")
- an empty tuple is false
- assigning multiple values at once

##Sets
- a={1,2,3}
- a_set=set(a_list)
- add()
- update()
- remove()
- discard()
- in
- union()
- intersection()
- difference()
- symmetric_difference()

## Dictionaries:
- a_dict = {'server': 'db.diveintopython3.org', 'database': 'mysql'} 

