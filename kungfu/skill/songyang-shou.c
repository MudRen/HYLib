// songyang-shou.c  ��������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����΢Ƿ���й�һ�ƻ����ĳ������������Ǵ����ַ�������ʽ����������",
        "force" : 150,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 0,
        "skill_name" : "������"
]),
([      "action" : "$N��ȭ���ƣ���ָ��ץ��һʽȡ����ɽ���ٵġ����ˮ��������$n��Ƭ�̼��ѱ���ʮ��������",
        "force" : 180,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "���ˮ"
]),
([      "action" : "$N���һ����ʹ��һ·���������еġ�����������˫�����·��ɡ��󿪴��أ���������$n",
        "force" : 240,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "������"
]),
([      "action" : "$N�˾��ڱۣ����һ���������֡��������ĳ������ֳ�ץ��ͬʱϮ�������ɾ�����ɽ��������$nѹ�˹���",
        "force" : 440,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 50,
        "skill_name" : "������",
]),
([      "action" : "$N������֮���ͺ�һ����һʽ����ʤ�塹������Ю���ſ�磬��ǰб�ƣ���������ɽ���ư�ѹ��$n",
        "force" : 280,
        "dodge" : 15,
        "damage" : 250,
        "lvl" : 70,
        "skill_name" : "��ʤ��",
         "damage_type" : "����"
]),
([      "action" : "$N˫�ֺ���ץ��������������ȭ�������ƣ��������֣�ʹһ�ס�С�������ַ�������һ�Σ�������$n��$l��ȥ",
        "force" : 230,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 90,
        "skill_name" : "С����"
]),
([      "action" : "$N���������Ȼŭ��һ������ǰһ��������˫�ƺϳɡ�����բ�������ŷ���֮����������$n",
        "force" : 300,
        "dodge" : -5,
        "damage" : 250,
        "damage_type" : "����",
        "lvl" : 110,
        "skill_name" : "����բ"
]),
([      "action" : "$N������ǰ������һ�С�ǧ��Ԩ�������ֻ�ȭΪ�ƣ�����ʮ�㣬����������������$n",
        "force" : 340,
        "dodge" : 10,
        "damage" : 250,
        "damage_type" : "����",
        "weapon" : "��Ե",
        "lvl" : 130,
        "skill_name" : "ǧ��Ԩ"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="hanbing-shenzhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���������ֱ�����֡�\n");
        if ((int)me->query_skill("songshan-qigong", 1) < 20)
                return notify_fail("�����ɽ������򲻹����޷�ѧ�������֡�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����������֡�\n");
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
        level = (int)me->query_skill("songyang-shou", 1);
        
        if (me->query_temp("ss_feiwu") == 2){
            return([      
                   "action": BLU "������$N"BLU"����һתһ�գ���$n"BLU"��û�з�Ӧ����ʱ������ǰ���ڳ����ַ������һʽ����ɽ�ơ���"NOR,        
                   "force" : 550,
                   "dodge" : 40,
        "damage" : 550,
                   "damage_type" : "����",
                   ]);
            }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       
        if ((int)me->query("jing") < 50)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������������֡�\n");
        me->receive_damage("jing", 30);
        me->receive_damage("neili", 5);
        if(me->query_skill("songyang-shou", 1) > 170)
                me->receive_damage("jing", 10);
        if(me->query_skill("songyang-shou", 1) > 190)
                me->receive_damage("neili", 5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"songyang-shou/" + action;
}