A simple Entity component system using a basic factory to constuct entities and components. The Factory requires each component to be 
placed inside a map during the init phase;

  "typedef Component* (*ComponentType)();"
  "typedef std::unordered_map <CPT_TYPE, ComponentType> CPTCreatorMap;"

Another alternative is to register the components upon creation to the factory in their respective constructors;
  "(*Factory::GetCreatorMap())[CPT_Transform] = Transform::Create;"

Type deduction occurs through the GetComponent(CPT_TYPE) function. In order to deduce the type a GETCPT call is required. 

For alternative ways and a more advanced topic refer to the "Reflection" directory.
