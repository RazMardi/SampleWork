##Simple Entity Component System (Object Oriented Approach)

A simple Entity component system using a basic factory to constuct entities and components. The Factory requires each component to be 
placed inside a map during the init phase.

Type deduction occurs through the GetComponent(CPT_TYPE) function. In order to deduce the type a GETCPT call is required. 

I highly recommend looking at Mike Acton's talk on Data Oriented Design here: https://www.youtube.com/watch?v=rX0ItVEVjHc 

Please note, this implementation follows a **Object Oriented approach**. I am currently in the process of researching and implementing a **Data Oriented System**.

For alternative ways and more advanced topics regarding type deduction refer "Type Reflection in C++" or "C++ MetaProgramming"

