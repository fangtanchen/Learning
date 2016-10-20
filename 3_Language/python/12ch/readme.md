
[TOC]

#XML#
## Diving In ##
- Application
    - syndication feeds: lists latest articles on a blog, forum, or other frequently-updated website.

##A short-intro in XML##
- XML
    - a generalized way of describing hierarchical structured data
    - start tags and end tags: <foo> </foo>
    - elements can be nested to any depth
    - only have one root element
    - elements can have attributes, quoted by single or double quotes
    - elements can have text content
    - namespace
        - use xmlns declaration to define a default namespace
        - use an xmlns:prefix declaration to define a namespace
            - associated it with a prefix
            - <atom:feed xmlns:atom="fdaf">
    - containing character encoding information
        - <?xml version='1.0' encoding='utf-8'?>
## The structure of an atom feed
- is designed to capture all of this information in a standard format
- top level: root element

## Parsing XML
- traditional DOM and SAX parsers
- ElementTree
    - xml.etree.ElementTree.parse(..)
    - getroot()
    - represents XML elements as {namespace}localname
    - Elements are Lists
    - Attributes are Dicts
        - attrib
## Searching for Nodes within an XML document
- ElementTree 
    - root.findall('{http://www.w3.org/2005/Atom}feed')
        - find in direct children
    - all_links = tree.findall('//{http://www.w3.org/2005/Atom}link')
        - search for descendant elements




