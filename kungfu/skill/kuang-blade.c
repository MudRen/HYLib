//kuangfeng-blade ��絶��
// Made by deaner
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N����$w��ӣ�һ��"+HIW"����ƽ�˾���"NOR+"������ƽ��ʵ��Ѹ�ٵ���
$n��$l��ȥ",
    "force" : 150,
    "dodge" : 10,
    "lvl" : 0,
    "skill_name" : "��ƽ�˾�",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIW"��������ӿ��"NOR+"���ҽ�һ�㣬$w��������������ӿ$n��
$l",
    "force" : 170,
    "dodge" : 35,
    "damage" : 20,
    "lvl" : 3,
    "skill_name" : "������ӿ",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIY"�������ơ�"NOR+"���ֱ�һ�գ�����һ�����϶���ն��
$n",
    "force" : 190,
    "dodge" : 25,
    "damage" : 25,
    "lvl" : 5,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIC"��������ɢ��"NOR+"��������ˣ�$wȴ����ǰ����һ��Բ��
������$n��$l",
    "force" : 210,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 10,
    "skill_name" : "������ɢ",
    "damage_type" : "����"
]),
([  "action" : "$N���������ϣ�һ��"+HIW"��������ড�"NOR+"������$n��ǰ��$w�Ϳ�
$n��$l",
    "force" : 230,
    "dodge" : 20,
    "damage" : 150,
    "lvl" : 20,
    "skill_name" : "�������",
    "damage_type" : "����"
]),
([  "action" : "$N���ٻ���$w��ʹ��һ��"+RED"�����в���"NOR+"������һƬ��������
$n��$l",
    "force" : 260,
    "dodge" : 15,
    "damage" : 165,
    "lvl" : 30,
    "skill_name" : "���в���",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIC"���絶˪����"NOR+"��ֻ�����쵶����˸�����ص�Ӱ��$n��
ȫ��ӿȥ",
    "force" : 290,
    "dodge" : 20,
    "damage" : 185,
    "lvl" : 40,
    "skill_name" : "�絶˪��",
    "damage_type" : "����"
]),
([  "action" : "$Nʹһ��"+HIW"����۵糸��"NOR+"��$w��������Ӱ��$n��$lӿȥ",  
    "force" : 320,
    "dodge" : 40,
    "damage" : 105,
    "lvl" : 60,
    "skill_name" : "��۵糸",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIB"������Ʈҡ��"NOR+"��$w������˸�������ƻ�����ر�$n��
$l",
    "force" : 350,
    "dodge" : 10,
    "damage" : 125,
    "lvl" : 80,
    "skill_name" : "����Ʈҡ",
    "damage_type" : "����"
]),
([  "action" : "$NŲ��С�ˣ�һ��"+HIC"���绨ѩ�¡�"NOR+"������$w���赭д�ػӳ�һ
�����漴�֡��ৡ���
����������������������$n��$l",
    "force" : 400,
    "dodge" : 20,
    "damage" : 150,
    "lvl" : 100,
    "skill_name" : "�绨ѩ��",
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

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
    level   = (int) me->query_skill("kuang-blade",1);
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
    if ((int)me->query("qi") < 100)
    return notify_fail("���������������絶����\n");
    me->receive_damage("qi", 80);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"kuang-blade/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
	int damage;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("kuang-blade",1);
        level2= (int) me->query_skill("kuang-blade",1);

level2= (int) me->query_skill("kuang-blade",1);             
	if (random(3)==1 && me->query_skill("kuang-blade",1)>300)
	{
	if( damage_bonus > 20 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)));
	return HIM"$N�����ݺ�! һ������������$n��$l�������Ѫ��!\n"NOR;
        }
}
}