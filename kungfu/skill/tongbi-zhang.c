#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹ��һ�С������Ⱥ����˫�ƺ�ʮ��ֱֱײ��$n��ǰ��",
        "force"  : 120,
        "attack" : 25,
        "damage" : 125,
        "dodge"  : 10,
        "lvl"    : 0,
        "damage_type" : "����",
        "skill_name"  : "�����Ⱥ",
]),
([      "action" : "$Nʹ��һ�С� ����������������Ծ��˫�����ģ�����$n",
        "force"  : 170,
        "attack" : 30,
        "damage" : 125,
        "dodge"  : 15,
        "lvl"    : 25,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "ֻ��$Nʹ��һ�С��绢��ɽ��������һչ����������ֱȡ$n",
        "force"  : 220,
        "attack" : 35,
        "damage" : 125,
        "dodge"  : 5,
        "lvl"    : 50,
        "damage_type" : "����",
        "skill_name"  : "�绢��ɽ",
]),
([      "action" : "$Nʹ��һ�С�����͸�ǡ���ŭ��һ����һ�Ƶ�ͷ����$n��$l",
        "force"  : 250,
        "attack" : 40,
        "damage" : 125,
        "dodge"  : 25,
        "lvl"    : 80,
        "damage_type" : "����",
        "skill_name"  : "����͸��",
]),
([      "action" : "$Nʹ��һ�С��������롹���ͳ���ǰ�����������㹥��$n",
        "force"  : 280,
        "attack" : 45,
        "damage" : 125,
        "dodge"  : 15,
        "lvl"    : 100,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$Nʹ��һ�С�������������������˫������ɨ��$n��$l",
        "force"  : 320,
        "attack" : 50,
        "damage" : 125,
        "dodge"  : 15,
        "lvl"    : 120,
        "damage_type" : "����",
        "skill_name"  : "������",
]),
([      "action" : "$Nʹ��һ�С������������������Ծ��˫��ǰ�����������$n",
        "force"  : 340,
        "attack" : 55,
        "damage" : 125,
        "dodge"  : 20,
        "lvl"    : 140,
        "damage_type" : "����",
        "skill_name"  : "��������",
]),
([      "action" : "$Nʩչ�����ֻء���������������г���������Ӱ����$n��$l",
        "force"  : 360,
        "attack" : 65,
        "dodge"  : 25,
        "damage" : 125,
        "lvl"    : 160,
        "damage_type" : "����",
        "skill_name"  : "���ֻ�",
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ͨ�������Ʊ�����֡�\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("����ڹ����̫ǳ��\n");



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
        level = (int) me->query_skill("tongbi-zhang", 1);

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int practice_skill(object me)
{
        object weapon;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ͨ�������Ʊ�����֡�\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("�������������������ͨ�������ơ�\n");

        if ((int)me->query("neili") < 40)
                return notify_fail("�������������������ͨ�������ơ�\n");

        me->receive_damage("qi", 35);
        me->add("neili", -30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tongbi-zhang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N����һ������������һƬ��Ҷ���Ʈ��,$nͷһ�裬��֪����!\n"NOR;

victim->start_busy(3);

                return msg;
}
}