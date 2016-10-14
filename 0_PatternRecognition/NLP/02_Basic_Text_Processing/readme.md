##Regular Expression##
- a formal language for specifying text strings
- Disjunctions
    - Letters inside square brackets [  ],  ex: [ wW ]
    - Ranges [A-X]
    - Negations:  [^Ss]
    - the pipe |: a|b|c = [abc]
    - ? : optional previous char
    - * : 0 or more of previous char
    - + : 1 or more of previous char
    - . : 1 any char
    - Anchors
        - ^: begin
        - $: end
- Errors
    - type 1: matching strings that we should not have matched
    - type 2: not match strings that we should have matched

##Text Normalization
- Segmeneting/tokenizing words in running text
- Normalizing word formats
- Segmenting sentences in running text

- How many words?
    - type:  an element of the vocabulary
    - token: an instance of that type in running text

- Language issues:
    - Chinese
    - Japanese etc

- Algorithm
    - Maximum Matching Word Segmentation Algorithm
        - keynote: find the longest word in dictionary that matches the string starting at point
        - not suitable for English but works well in Chinese

##Word Normalization and Stemming##
###Normalization 
- normalize terms
    - match U.S.A. and USA
- Case Folding
    - reduce all letters to lower case
    
- Lemmatization
    - find correct dictionary headword form
    - reduce inflections or variant forms to base form
- Morphology
    - the smalling meaningful units that make up words

##Sentence Segmentation and Decision Trees
- Ambiguous
    - '.'
        - EndofSentence
        - percents
        - abbreviations


