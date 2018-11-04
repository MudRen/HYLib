// sanhua-zhang.c ɢ����
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N���Ʊ���һʽ������ݾ�����˫�Ʊ�����£���������$n��$l
",
    "force" : 180,
    "dodge" : 5,
    "parry" : 20,
    "damage": 10,
    "lvl" : 0,
    "skill_name" : "����ݾ�",
    "damage_type" : "����"
]),
([      "action" : "$N��ָ������һʽ�����ж���ܰ���������ƴ��巭�ɣ�����$n��$l��
ȥ",
    "force" : 260,
    "dodge" : 10,
    "parry" : 15,
    "damage": 20,
    "lvl" : 20,
    "skill_name" : "���ж���ܰ",
    "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ���ﺨ��˪�塹���������У�����է��է�ϣ��͵ز���$n��
$l",
    "force" : 340,
    "dodge" : 15,
    "parry" : 20,
    "damage": 30,
    "lvl" : 40,
    "skill_name" : "�ﺨ��˪��",
    "damage_type" : "����"
]),
([      "action" : "$N˫��Ѫ�죬һʽ��������÷�������ó�����÷����䣬������$n
��ȥ",
    "force" : 420,
    "dodge" : 20,
    "parry" : 30,
    "damage": 40,
    "lvl" : 60,
    "skill_name" : "������÷��",
    "damage_type" : "����"
]),
([	"action" : "$N���Ʊ��������һʽ��"HIG"����ݾ�"NOR"��������������£��������縧�壬����Ʈ��$n",
        "force" : 140,
        "dodge" : 25,
	"lvl" : 0,
	"skill_name" : "����ݾ�",
        "damage_type" : "����"
]),
([	"action" : "$N��ָ������һʽ��"GRN"���ж���ܰ"NOR"��������˫�ƴ��巭�ɣ������Ľ���������$n���ɶ�ȥ",
        "force" : 200,
        "dodge" : 115,
        "lvl" : 35,
	"skill_name" : "���ж���ܰ",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��"HIY"�ﺨ��˪��"NOR"�����������У�����է��է�ϣ����ڷ���ҡ�ڣ����ḧ��$n$l",
        "force" : 250,
        "dodge" : 110,
        "lvl" : 65,
	"skill_name" : "�ﺨ��˪��",
        "damage_type" : "����"
]),
([	"action" : "$N˫��ѩ�ף�һʽ��"HIW"������÷��"NOR"�����������Ƽ�ó�����÷����䣬������$nƮȥ",
        "force" : 300,
        "dodge" : 15,
        "lvl" : 105,
	"skill_name" : "������÷��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }    

int valid_combine(string combo) { return combo=="nianhua-zhi"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("��ɢ���Ʊ�����֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧɢ���ơ�\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷���ɢ���ơ�\n");
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
    level   = (int) me->query_skill("sanhua-zhang",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("�������������ɢ���ơ�\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"sanhua-zhang/" + action;
}
