#include "Factory.h"

int main()
{
    Factory::Create();
    Factory::Init();

    Entity* temp = Factory::CreateEntity();
    temp->AddComponent(CPT_Transform);
    temp->AddComponent(CPT_RigidBody);

    std::cout << temp->GETCPT(Transform)->GetName() << std::endl;
    std::cout << temp->GETCPT(RigidBody)->GetName() << std::endl;

    delete temp;
    Factory::Destroy();
    return 0;
}