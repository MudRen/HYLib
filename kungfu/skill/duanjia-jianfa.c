//�μҽ���

inherit SKILL;

mapping *action = ({
([      "action" : "$N�������˸�����������$wƽƽ�ݳ���һʽ�������Ͻ�ֱ��$n��ǰ��",
        "force" : 150,
        "dodge" : -5,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ��$w��һ���벻���ĽǶ�ͻȻ������һʽ���̼�������ֱ��$n������",
        "force" : 180,
        "dodge" : -5,
        "damage" : 45,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������ڿա�������Ծ�ڰ�գ�$w��������� ��ֱ��$n��ͷ��",
        "force" : 220,
        "dodge" : 20,
        "damage" : 55,
        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N����б�ӣ�����ָ��$n�ĸ�����һ�С���Ԩ���ԡ������¶��ϣ�����$n",
        "force" : 270,
        "dodge" : -15,
        "damage" : 70,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N˫����أ�б�ɶ�����$w����$n��$l,��һ�С�Цָ���ϡ�",
        "force" : 330,
        "dodge" : -15,
        "damage" : 90,
        "lvl" : 80,
        "damage_type" : "����"
]),
([      "action" : "$N��Хһ�����ὣ�������͸������֮�⣬���ǶμҲ���֮�ء���¹��ԭ����������ס$n��ȫ��",
        "force" : 280,
        "dodge" : 15,
        "damage" : 100,
        "lvl" : 90,
        "damage_type" : "����"

]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
//int valid_combine(string combo) { return combo=="murong-daofa"; }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("qiantian-yiyang", 1) < 20)
                return notify_fail("���Ǭ��һ�����̫ǳ��\n");
 //       if ((int)me->query_skill("parry", 1) < 10)
   //             return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("duanjia-jianfa",1);
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
        if ((int)me->query("jingli") < 40)
                return notify_fail("��������������μҽ�����\n");
        me->receive_damage("jingli", 20);
        return 1;
}
string perform_action_file(string action)
{
	return __DIR__"duanjia-jianfa/" + action;
}

