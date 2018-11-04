inherit SKILL;

mapping *action = ({
([     "action" : "$N����$w����һ�С��ΰݱ�������бб��$n��$l�ϴ�ȥ",
       "force" : 120,
        "dodge" : 10,
        "parry" : 5,
       "damage": 300,
       "lvl" : 0,
       "skill_name" : "�ΰݱ���",
       "damage_type" : "����"
]),
([     "action" : "$N����������$nһ�й��������ǲ������ܣ����������������,һ�С����ӷ������͵�ת��ˢ��һ��������$n��$l",
       "force" : 180,
        "dodge" : 10,
        "parry" : 10,
       "damage": 350,
       "lvl" : 15,
       "skill_name" : "���ӷ���",
       "damage_type" : "����"
]),
([     "action" : "$N���󻬿�������ˢ��һ����$w���֣�һ�С��ɹ��ظʡ�����ͷ��$n��$l��ȥ",
       "force" : 210,
        "dodge" : 15,
        "parry" : 15,
       "damage": 300,
       "lvl" : 30,
       "skill_name" : "�ɹ��ظ�",
       "damage_type" : "����",
]),
([     "action" : "$NͻȻ�����뵶��һ�С�ɳɮ�ݷ𡹣�˫�ƻ��������һ�죬����$n���ؿڡ���$nһ����һ̽�֣�����ץס����",
       "force" : 300,
        "dodge" : 10,
        "parry" : 10,
       "damage": 340,
       "lvl" : 45,
       "skill_name" : "ɳɮ�ݷ�",
       "damage_type" : "����"
]),
([     "action" : "$N$wһ��һ�С�����ժ�ġ��������������ѽ�$n������ס,��Ȼһ��ն��$n������",
       "force" : 320,
        "dodge" : 10,
        "parry" : 5,
       "damage": 360,
       "lvl" : 60,
       "skill_name" : "����ժ��",
       "damage_type" : "����"
]),
([     "action" : "$N��ǰһ�ˣ�һ�С����ӻ�ͷ����˳�ƻع�$W��ˢ��һ�£����¶��ϵ�ն��$n$l",
       "force" : 350,
        "dodge" : 10,
        "parry" : 5,
       "damage": 380,
       "lvl" : 75,
       "skill_name" : "���ӻ�ͷ",
       "damage_type" : "����"
]),
([     "action" : "$N̤��������һ�С����б��¡����ص�һ��������$wһ��һ�ᣬ��$n��$l��ȥ",
       "force" : 360,
        "dodge" : 15,
        "parry" : 15,
       "damage": 320,
       "lvl" : 100,
       "skill_name" : "���б���",
       "damage_type" : "����",
]),
([     "action" : "$N���ڰ�գ�ʹһ�С�ҹ��̽����,�ھ�����$w֮�ϣ�������������������㿳��$N��$l",
       "force" : 370,
        "dodge" : 15,
        "parry" : 10,
       "damage": 340,
       "lvl" : 120,
       "skill_name" : "ҹ��̽��",
       "damage_type" : "����",
]),
([     "action" : "$Nͷһ�ͣ������ܿ����У�һ�С��ݷ�������,$w���ż������һ������$n��ɨ��ȥ",
       "force" : 380,
        "dodge" : 15,
        "parry" : 10,
       "damage": 360,
       "lvl" : 140,
       "skill_name" : "�ݷ�����",
       "damage_type" : "����",
]),
([     "action" : "$Nб����ݣ��˵�$n����࣬һ�С�������������������������$n��$l��ȥ",
       "force" : 385,
        "dodge" : 25,
        "parry" : 5,
       "damage": 380,
       "lvl" : 160,
       "skill_name" : "��������",
       "damage_type" : "����",
]),
([     "action" : "$Nһ�С�ɳŸ�Ӳ�����$w��ʵ���ã������ʵ,��$n��ȫ���ȥ",
       "force" : 390,
        "dodge" : 15,
        "parry" : 15,
       "damage": 400,
       "lvl" : 180,
       "skill_name" : "ɳŸ�Ӳ�",
       "damage_type" : "����",
]),
([     "action" : "$N���һ����ʹ�С��˷��ص�ʽ������ǰһ����������Ϊ�ᣬת�˸�Ȧ�ӣ���$w����$n�����˰˰���ʮ�ĵ��������ݺᣬѸ�ײ��ɵ�",
       "force" : 400,
        "dodge" : 10,
        "parry" : 15,
       "damage": 400,
       "lvl" : 200,
       "skill_name" : "�˷��ص�ʽ",
       "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }


int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 50)
               return notify_fail("�������������ϰ���ҵ�����\n");
       if ((int)me->query_skill("blade", 1) < 100)
               return notify_fail("��ĵ������̫ǳ������ϰ�����ס�\n");
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
       level   = (int) me->query_skill("hujia-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "blade")
               return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 350)
		return notify_fail("���������������\n");
       if ((int)me->query("jing") < 150)
               return notify_fail("����������������ҵ�����\n");
	me->receive_damage("qi", 300);
	me->receive_damage("jing", 100);
       return 1;
}
string perform_action_file(string action)
{
        return __DIR__"hujia-daofa/" + action;
}