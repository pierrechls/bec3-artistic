#include <iostream>
#include "Session.hpp"

using namespace std;

Session Session::m_instance=Session(RestClient::headermap session);

Session::Session(RestClient::headermap session) : m_instance(session)
{
    cout<<"Creation"<<endl;
}

Session::~Session()
{
    cout<<"Destruction"<<endl;
}

Session& Session::getInstance()
{
    return m_instance;
}

int main(void)
{
    //1er appel de Instance: on alloue le pointeur SoundManager::m_instance
    SoundManager& ptr1=SoundManager::Instance();
    
    //2eme appel:on se contente de renvoyer le pointeur déjà allouer.
    SoundManager& ptr2=SoundManager::Instance();
  
    //ptr1 et ptr2 pointe sur la même adresse mémoire.
    //On voit donc qu'il ny a bien qu'un seul objet.
    cout<<&ptr1<<"|"<<&ptr2<<endl;

    return 0;
}

