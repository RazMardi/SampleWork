#include "Entity.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Math.h"

using namespace Core;

// sample usage
int main()
{
    Entity* ePlayer = new Entity("Player");
    ePlayer->AddComponent("Transform");
    ePlayer->AddComponent("RigidBody");
    
    Transform* pTrans = ePlayer->GetComponent<Transform>();
    pTrans->SetScale(Math::Vector3(2.0f, 2.0f, 2.0f));
    pTrans->SetRotation(1.0f, 1.0f, 1.0f);
    pTrans->SetTranslation(5.0f, 5.0f, -10.0f);

    Entity* eMonster = new Entity("Monster");
    eMonster->AddComponent("Transform");
    
    Transform* mTrans = eMonster->GetComponent<Transform>();
    mTrans->SetScale(Math::Vector3(2.0f, 2.0f, 2.0f));
    mTrans->SetRotation(1.0f, 1.0f, 1.0f);
    mTrans->SetTranslation(2.0f, 1.0f, -30.0f);

    mTrans->SetTranslation(mTrans->GetTranslation().Normalize());

    std::cout << (*ePlayer) << std::endl;
    std::cout << (*pTrans) << std::endl;
    std::cout << (*ePlayer->GetComponent<RigidBody>()) << std::endl;

    std::cout << (*eMonster) << std::endl;
    std::cout << (*mTrans) << std::endl;

    return 0;
}