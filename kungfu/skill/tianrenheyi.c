#include <ansi.h>
// biguan.c

inherit SKILL;

void skill_improved(object me)
{}

int practice_skill(object me)
{
	return notify_fail("��ֻ��ͨ��4ת�ﵽ���˺�һ���Ż����Ź���\n");
}

string *usage_skills = ({ "unarmed", "parry", "dodge","force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}
string perform_action_file(string action)
{
	return __DIR__"tianrenheyi/" + action;
}

int valid_learn(object me)
{
        int level;
        int i;
//       if( !me->query("zhuanbest",1))
//        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");


        for (i = 0; i < sizeof(usage_skills); i++)
                if (me->query_skill(usage_skills[i], 1) < level)
                        return notify_fail("���" + to_chinese(usage_skills[i]) + "����⻹"
                                           "�������޷�����������������˺�һ��\n");

        return 1;
}
string *dodge_msg = ({
        "$n��Ҳ��������$N��һ�ߡ�\n",
        "$n����΢΢һ������$N���ˡ�\n",
        "$n�������һ�Σ�$N��Ȼ�޷�������ֻ���Ա���\n",
        "$n����һ�񣬽��������н�������ȫ��������\n",
});

mapping *action = ({
([      "action":"$N����һ̽����ʱ������Х���������ֺ��޻��ɵĲ���$n$l",
        "force" : 510,
        "attack": 190,
        "dodge" : 100,
        "parry" : 90,
        "damage": 180,
        "weapon": HIW "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action":"$N˫����ץ���ó�ǧ���ҫ�۵Ľ�⣬��������$n��$l",
        "force" : 510,
        "attack": 185,
        "dodge" : 90,
        "parry" : 120,
        "damage": 175,
        "weapon": HIW "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action":"$N����һת��ȭͷЯ�ż�����ת�������ӳ����������磬��������������$n",
        "force" : 530,
        "attack": 75,
        "dodge" : 90,
        "parry" : 110,
        "damage": 200,
        "weapon": HIW "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action":"$N�Ʋ���ǰ��һ�Ʋ�������������$n��$l�������ж�ʱ����һ��̶��ı���",
        "force" : 525,
        "attack": 85,
        "dodge" : 85,
        "parry" : 115,
        "damage": 185,
        "weapon": HIW "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action":"$N����һ�࣬һ�����������һ��������������ʱ����ӿ��$n��$l��",
        "force" : 530,
        "attack": 65,
        "dodge" : 90,
        "parry" : 115,
        "damage": 200,
        "weapon": HIW "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action":"$N˫�ֺ�ȭ������ſ���ֻ�������͡��ƿ�֮����ʮ������һ������$n��$l",
        "force" : 540,
        "attack": 80,
        "dodge" : 115,
        "parry" : 120,
        "damage": 280,
        "weapon": HIW "�����޼���" NOR,
        "damage_type":  "����"
]),
});


mapping query_action(object me, object weapon)
{
        return weapon ? action[random(sizeof(action))] :
                        action[random(sizeof(action))];
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
