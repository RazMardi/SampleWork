A simple Entity component system using a basic factory to constuct entities and components. The Factory requires each component to be 
placed inside a map during the init phase.

Type deduction occurs through the GetComponent(CPT_TYPE) function. In order to deduce the type a GETCPT call is required. 

For alternative ways and more advanced topics regarding type deduction refer "Type Reflection in C++" or "C++ MetaProgramming"

