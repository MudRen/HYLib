//Cracked by Kafei
// dangyang-qiangfa.c ���ǹ�� (maco)
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$Nʹ�С�������������ǹ�Ϻ�ӧ�������������ǹ������$n$lֱ����ȥ",
        "force" : 140,
        "dodge" : 10,
        "damage": 60,
        "lvl" : 8,
        "skill_name" : "��������", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "����"
]),
([      "action":"$N��ת$w��һ�С��׺羭�졹��б���Ʋ���ǹ���𴦣�ԲԲһ�ź�Ӱ��ǹ����һ�㺮�⼲��$n����",
        "force" : 170,
        "dodge" : 20,
        "damage": 70,
        "lvl" : 20,
        "skill_name" : "�׺羭��", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "����"
]),
([      "action":"$N����$wһ����ʹ��һ�С�����һ���㡹��$wͦ�ñ�ֱ��Ѹ�����׵ش���$n��$l",
        "force" : 220,
        "dodge" : 10,
        "damage": 80,
        "lvl" : 30,
        "skill_name" : "����һ����", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "����"
]),
([      "action":"$Nͦ��$w��һ�С����ͷ������ӧ������ǹ��������$n$l�㵽",
        "force" : 270,
        "dodge" : 0,
        "damage": 100,
        "lvl" : 40,
        "skill_name" : "���ͷ", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "����"
]),
([      "action":"$Nһ�С�������ŭ����ˢˢˢ������ǹ�����̶�������ӧ�Ұڣ�$w�������죬����һ�����Ȧ�ӣ���ס��$n���¸�·",
        "force" : 330,
        "dodge" : 30,
        "damage": 140,
        "lvl" : 50,
        "skill_name" : "������ŭ", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "����"
]),
([      "action":"$N̤��һ����ʹ��һ�С������Ⱥ����$w������磬������ƥ����$n��$l��ȥ",
        "force" : 350,
        "dodge" : 40,
        "damage": 160,
        "lvl" : 8,
        "skill_name" : "�����Ⱥ", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "����"
]),
([      "action":"$Nʹ��$w��һʽ���в��Ż������ܡ��̡����������������ܡ��գ�ǹ������������ӧ������㣬·�����������$n��ʩ�͹�",
        "force" : 400,
        "dodge" : 60,
        "damage": 200,
        "lvl" : 8,
        "skill_name" : "�в��Ż�", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "����"
])
});

int valid_enable(string usage) { return usage == "club" || usage == "parry"; }
int valid_learn(object me) { return 1; }

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
        level   = (int) me->query_skill("yangjia-qiang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������ǹ��\n");
        me->receive_damage("qi", 80);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"/yangjia-qiang" + action;
} 




