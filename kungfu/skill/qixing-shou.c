// �����������ࡢ���������ᡢ��Ȩ����⡢������ҡ�����߿�����ɣ���ת�ڱ�
// ������Χ�����У���������Ȩ����Ϊ���������ҡ��Ϊ�񡣡�ʷ�ǡ�����顷��
// �ء��������ǣ���ν�����⣬������������Я���ǣ�����϶���������ס���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N������ָ�ֿ���΢΢һ����һʽ������ָ������$n������ҪѨ",
        "force" : 100,
        "dodge" : 15,
        "damage": 185,
        "lvl"   : 0,
        "damage_type" : "����",
        "skill_name" : "����ָ"
]),
([      "action": "$N��������$n��һʽ������ָ����������ָ����$n����ǰ��Ѩ",
        "force" : 130,
        "dodge" : 20,
        "damage": 180,
        "lvl"   : 30,
        "damage_type" : "����",
        "skill_name" : "����ָ"
]),
([      "action": "$Nʹһʽ������ָ���������鹥����ָбǰ����������$n�ļ羮Ѩ",
        "force" : 170,
        "dodge" : 25,
        "damage": 190,
        "lvl"   : 60,
        "damage_type" : "����",
        "skill_name" : "����ָ"
]),
([      "action": "$N΢΢�������ƹ��ϣ�һʽ����Ȩָ������������$n����ͻѨ",
        "force" : 190,
        "dodge" : 25,
        "damage": 195,
        "lvl"   : 80,
        "damage_type" : "����",
        "skill_name" : "��Ȩָ"
]),
([      "action": "$Nʹһʽ�����ָ������Ӱ����������$n����͵�����$n�Ĵ�׵Ѩ",
        "force" : 220,
        "dodge" : 30,
        "damage": 190,
        "lvl"   : 100,
        "damage_type" : "����",
        "skill_name" : "���ָ"
]),
([      "action": "$Nʩ��������ָ����˫������һ��������$n�Ļ��ǡ���ᡢ�Ϲ�������Ѩ",
        "force" : 250,
        "dodge" : 35,
        "damage": 195,
        "lvl"   : 120,
        "damage_type" : "����",
        "skill_name" : "����ָ"
]),
([      "action": "$Nһʽ��ҡ��ָ�����Ӹ����£�����һ����������$n�İٻ��Ѩ",
        "force" : 280,
        "dodge" : 40,
        "damage": 195,
        "lvl"   : 140,
        "damage_type" : "����",
        "skill_name" : "ҡ��ָ"
]),
([      "action": "$Nʩչ������Ὺ�ơ���˫�ּ�����һ�����ľ�������$n�������¸���ҪѨ",
        "force" : 320,
        "dodge" : 45,
        "damage": 170,
        "lvl"   : 160,
        "damage_type" : "����",
        "skill_name" : "��Ὺ��"
])
});

int valid_enable(string usage)
{
	return usage == "hand" ||  usage == "parry";
}
int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����Ƿ����ֱ�����֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ���Ƿ����֡�\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷������Ƿ����֡�\n");

        if ((int)me->query_skill("hand", 1) < 80)
                return notify_fail("��Ļ����ַ�̫��޷�ѧϰ���Ƿ����֡�\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("qixing-shou", 1))
                return notify_fail("������ַ���򲻹����޷�������������Ƿ����֡�\n");

        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("qixing-array",1);
        level2= (int) me->query_skill("xiantian-qigong",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{

	victim->start_busy(3);
	return HIR"$N̤���ţ���ƫ��,$n˫��һ��,��֪���Ӧ��!\n"NOR;
}
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("qixing-shou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 5, level / 5)];

}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
                return notify_fail("�������̫���ˣ��޷������Ƿ����֡�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������̫���ˣ��޷������Ƿ����֡�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -53);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qixing-shou/" + action;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("qixing-array",1);
        level2= (int) me->query_skill("xiantian-qigong",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xiantian-qigong")
{

	ob->start_busy(3);

msg = HIG"$N������λ����ƫ��,$n˫��һ��,��֪���Ӧ��!\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}