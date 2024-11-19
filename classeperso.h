// les classses suivantes sont pour les non-utilisateurs de magie

class ClasseBarbare{

};

class ClasseGuerrier{

};

// les classes suivantes sont pour les utilisateurs de la magie

class ClasseMagicien{  // ClasseMagicien est classe mère de toutes les autres classes de magicien
    protected :

    int mana, pv, force, endurance;

    bool saitlire, saitecrire, saitnaviguer, saitchevaucher;

    void lancerunsort();

};

class ClasseMageBlanc : public ClasseMagicien{ // ClasseMageBlanc est classe mère de : ClasseMageElementaire

};

class ClasseMageElementaire : public ClasseMageBlanc{

};

class ClasseMageNoir : public ClasseMagicien{ // ClasseMageNoir est classe mère de : ClasseNecromancien

};

class ClasseNecromancien : public ClasseMageNoir{

};

class ClasseDemonologiste : public ClasseMageNoir{

};