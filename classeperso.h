

class ClasseBarbare{

};

class ClasseGuerrier{

};

// les classes suivantes sont pour les utilisateurs de la magie

class ClasseMagicien{  // ClasseMagicien est classe mère de toutes les autres classes de magicien

};

class ClasseMageBlanc : public ClasseMagicien{

};

class ClasseMageNoir : public ClasseMagicien{ // ClasseMageNoir est classe mère de : ClasseNecromancien

};

class ClasseNecromancien : public ClasseMageNoir{

};

class ClasseDemonologiste : public ClasseMageNoir{

};