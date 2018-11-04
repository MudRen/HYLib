#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N����$w�տ���Ю�ź���������һ�С�����ÿÿ����ֱȡ$n�ĸ���Ҫ��",
    "damage": 600,
    "force": 300,
    "dodge" : 50,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "����ÿÿ"
]),
([  "action" : "$N����һԾ������$w�����Х��һ�С����ֳ��ա��������$n$l��ȥ",
    "damage": 600,
    "force": 300,
    "dodge" : 45,
    "damage_type" : "����",
    "lvl" : 10,
    "skill_name" : "���ֳ���"
]),
([  "action" : "$N����$w������������һ�С�ԨԴ������������㿳��$n$l",
    "damage": 600,
    "force": 300,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl" : 20,
    "skill_name" : "ԨԴ����"
]),
([  "action" : "$Nʹ��һ�С����ɳ��ڡ�������$w�趯�����洸�ƣ�����һ���̳�����������$n��$l",
    "damage": 600,
    "force": 500,
    "dodge" : 35,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : "���ɳ���"
]),
([  "action" : "$N����������ת��΢�ף�$N��$n¶����������æ����",
    "damage": 680,
    "force": 500,
    "dodge" : 30,
    "parry" : 54,
    "damage_type" : "����",
    "lvl" : 55,
    "skill_name" : "�ط�ת��"
]),
([  "action" : "$N����΢��������ͬһʱ�������������ҿ����崸����$n",
    "damage": 640,
    "force": 500,
    "dodge" : 25,
    "parry" : 66,
    "damage_type" : "����",
    "lvl" : 68,
    "skill_name" : "�崸����"
]),
});

int valid_enable(string usage) { return usage=="hammer" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 50)
   return notify_fail("����ڹ��ķ���򲻹����޷�ѧ��ѩ������\n");
    if ((int)me->query("max_neili") < 150)
   return notify_fail("�������̫�����޷�����ѩ������\n");
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
    level = (int)me->query_skill("tiexue-hammer", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "hammer")
   return notify_fail("��ʹ�õ��������ԡ�\n");    if ((int)me->
query("qi") < 30)
    if ((int)me->query("qi") < 50)
    return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("���������������ѩ������\n");
    me->receive_damage("qi", 25);
return 1;
}
string perform_action_file(string action)
{
    return __DIR__"tiexue-hammer/" + action;
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
        weapon = me->query_temp("weapon");

level2= (int) me->query_skill("tiexue-hammer",1);             
if (weapon)
{

        if (random(3)==1 && me->query_skill("tiexue-hammer",1)>100
        && (string)weapon->query("skill_type") == "hammer"
        && me->query_skill_mapped("force") == "guiyuan-tunafa"
        )
        {
        if (!victim->is_busy())
        victim->start_busy(3);
        return HIY"$N�����,$n�޷�����Ҳ�޷�����!!\n"NOR;
        }
        if( damage_bonus > 30 && random(level2)>60
        && (string)weapon->query("skill_type") == "axe"
        && me->query_skill_mapped("force") == "guiyuan-tunafa"
        && random(2)==0) {
        victim->receive_wound("qi", (random(damage_bonus)+150));
        return HIY"$n������$lҪ����Ѫ����һ��!!\n"NOR;
        }
}
}

