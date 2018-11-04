// wuliang-jianfa.c ��������

inherit SKILL;

mapping *action = ({
([     "action" : "$Nδ������δ�ϣ���Ȼ���ƣ������ڰ����΢΢һ����һ������������б��$n$l",
       "force" : 240,
       "damage" : 30,
       "lvl" : 0,
       "damage_type" : "����"
]),
([     "action" : "$N�������ã�ʹ�С�������ޡ��������Ҳ������ν����̷�ס",
       "force" : 270,
        "dodge" : 5,
       "damage" : 35,
       "lvl" : 15,
       "damage_type" : "����"
]),
([     "action" : "$Nһ�С�˳ˮ���ۡ������������$n��$l��ȥ",
       "force" : 290,
        "dodge" : 5,
       "damage" : 40,
       "lvl" : 20,
       "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 100)
               return notify_fail("�������������\n");
       if ((int)me->query_skill("wuliang-shengong", 1) < 20)
               return notify_fail("��������񹦻��̫ǳ��\n");
       return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
       level   = (int) me->query_skill("wuliang-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
               return notify_fail("��ʹ�õ��������ԡ�\n");
       if ((int)me->query("jingli") < 50)
               return notify_fail("�����������������������\n");
       me->receive_damage("jingli", 35);
       return 1;
}
