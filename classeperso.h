///////////////////////////////////////////////////////////////////////////////////////////////////
// les classses suivantes sont pour les non-utilisateurs de magie
///////////////////////////////////////////////////////////////////////////////////////////////////

class ClasseNonMagicien{
    public :

    int pv, force, endurance;

    bool saitlire, saitecrire, saitnaviguer, saitchevaucher;

};

class ClasseBarbare : public ClasseNonMagicien{

};

class ClasseGuerrier : public ClasseNonMagicien{

};


///////////////////////////////////////////////////////////////////////////////////////////////////
// les classes suivantes sont pour les utilisateurs de la magie
///////////////////////////////////////////////////////////////////////////////////////////////////

class ClasseMagicien{  // ClasseMagicien est classe mère de toutes les autres classes de magicien
    public :

    int mana, pv, force, endurance;

    bool saitlire, saitecrire, saitnaviguer, saitchevaucher;
    bool estmagicien = 1;

    void lancerunsort();

};

// les classes suivantes sont pour les magiciens de lumière

class ClasseMageBlanc : public ClasseMagicien{ // ClasseMageBlanc est classe mère de : ClasseMageElementaire

};

class ClasseMageElementaire : public ClasseMageBlanc{

};

// les classes suivantes sont pour les mages noirs

class ClasseMageNoir : public ClasseMagicien{ // ClasseMageNoir est classe mère de : ClasseNecromancien

};

class ClasseNecromancien : public ClasseMageNoir{

};

class ClasseDemonologiste : public ClasseMageNoir{

};

// les classes suivantes sont pour les druides

class ClasseDruide : public ClasseMagicien{

};

// les classes suivantes sont pour les pretres

class ClassePretre : public ClasseMagicien{

};