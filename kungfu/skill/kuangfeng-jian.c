//kuangfeng-jian ���콣
// Made by deaner
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N����Ծ������$w��ӣ�ն��$n��",
    "damage" : 350,
    "dodge"  : 10,
    "lvl"   : 0,
    "skill_name" : "��ƽ�˾�",
    "damage_type" : "����"
]),
([  "action" : "$N����$w�����������Σ���$n���ұ����ն��",
    "damage" : 370,
    "dodge" : 35,
    "force" : 20,
    "lvl"   : 20,
    "skill_name" : "������ӿ",
    "damage_type" : "����"
]),
([  "action" : "$N����һ����ˢˢˢˢ�Ľ�����$n�أ������������Ĵ�����",
    "damage" : 390,
    "dodge" : 25,
    "force" : 25,
    "lvl"   : 40,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$N����һ����Х��б����ǰ��$w����ֱ����Ѹ���ޱȣ�����$n��$l",
    "damage" : 310,
    "dodge" : 15,
    "force" : 35,
    "lvl"   : 60,
    "skill_name" : "������ɢ",
    "damage_type" : "����"
]),
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
    "lvl" : 10,
    "skill_name" : "������ӿ",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIY"�������ơ�"NOR+"���ֱ�һ�գ�����һ�����϶���ն��
$n",
    "force" : 190,
    "dodge" : 25,
    "damage" : 25,
    "lvl" : 20,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIC"��������ɢ��"NOR+"��������ˣ�$wȴ����ǰ����һ��Բ��
������$n��$l",
    "force" : 210,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 32,
    "skill_name" : "������ɢ",
    "damage_type" : "����"
]),
([  "action" : "$N���������ϣ�һ��"+HIW"��������ড�"NOR+"������$n��ǰ��$w�Ϳ�
$n��$l",
    "force" : 230,
    "dodge" : 20,
    "damage" : 50,
    "lvl" : 45,
    "skill_name" : "�������",
    "damage_type" : "����"
]),
([  "action" : "$N���ٻ���$w��ʹ��һ��"+RED"�����в���"NOR+"������һƬ��������
$n��$l",
    "force" : 260,
    "dodge" : 15,
    "damage" : 65,
    "lvl" : 58,
    "skill_name" : "���в���",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIC"���罣˪����"NOR+"��ֻ�����콣����˸�����ؽ�Ӱ��$n��
ȫ��ӿȥ",
    "force" : 290,
    "dodge" : 20,
    "damage" : 85,
    "lvl" : 71,
    "skill_name" : "�罣˪��",
    "damage_type" : "����"
]),
([  "action" : "$Nʹһ��"+HIW"����۵糸��"NOR+"��$w��������Ӱ��$n��$lӿȥ",  
    "force" : 320,
    "dodge" : 40,
    "damage" : 105,
    "lvl" : 86,
    "skill_name" : "��۵糸",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+HIB"������Ʈҡ��"NOR+"��$w������˸�������ƻ�����ر�$n��
$l",
    "force" : 350,
    "dodge" : 10,
    "damage" : 125,
    "lvl" : 101,
    "skill_name" : "����Ʈҡ",
    "damage_type" : "����"
]),
([  "action" : "$NŲ��С�ˣ�һ��"+HIC"���绨ѩ�¡�"NOR+"������$w���赭д�ػӳ�һ
�����漴�֡��ৡ���
����������������������$n��$l",
    "force" : 400,
    "dodge" : 20,
    "damage" : 150,
    "lvl" : 120,
    "skill_name" : "�绨ѩ��",
    "damage_type" : "����"
]),
([      "action" : "$N��Ӱ��˫�����⸡����ת��������9������$n��$l��ȥ",
        "force" : 220,
        "dodge" : 10,
        "parry" : 5,
        "damage": 215,
        "lvl" : 0,
        "skill_name" : "���罣��",
        "damage_type" : "����"
]),
([      "action" : "$N����｣����$n���ߣ�����֮�죬������˼������$w�Ѹ���$n���������",
        "force" : 230,
        "dodge" : 10,
        "parry" : 10,
        "damage": 220,
        "lvl" : 12,
        "skill_name" : "���罣��",
        "damage_type" : "����"
]),
 ([      "action" : "$N����$w����һ�٣����������ǻ��գ�����������ˢ��һ�����϶�����$n����",
        "force" : 240,
        "dodge" : 5,
        "parry" : 5,
        "damage": 225,
        "lvl" : 18,
        "skill_name" : "���罣��",
        "damage_type" : "����"
]),
([      "action" : "$N���ַ�ִ�������ὣһն��$wֱ��$n�ľ��л�ȥ",
        "force" : 260,
        "dodge" : 5,
        "parry" : 5,
        "damage": 230,
        "lvl" : 24,
        "skill_name" : "���罣��",
        "damage_type" : "����",
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 

int valid_learn(object me)
{
//    mapping myfam;
//    myfam = (mapping)me->query("family");
//    if(!myfam || myfam["master_id"] != "feng buping")
//        return notify_fail("���޷������ѧϰ���콣��\n");
    if ((int)me->query("max_neili") < 300)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("force", 1) < 60)
        return notify_fail("����ڹ��ķ����̫ǳ��\n");
    if ((int)me->query_skill("dodge", 1) < 60)
        return notify_fail("����Ṧ���̫ǳ��\n");
    if ((int)me->query_dex() < 25)
        return notify_fail("�������������\n");
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
    level   = (int) me->query_skill("kuangfeng-jian",1);
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
    if ((int)me->query("qi") < 30)
        return notify_fail("����������������콣��\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"kuangfeng-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
	int damage;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("zixia-shengong",1);
        level2= (int) me->query_skill("zixia-shengong",1);
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "zixia-shengong")
{
if (random(2)==0)
{
	victim->start_busy(2);
}
else 	victim->receive_wound("qi", (random(damage_bonus))+200);
                  return random(2) ? HIR "$N" HIR "������ϼ�񹦣�һ��������������ɣ�,$n˫��һ��,��֪����Ǻ�!\n" NOR:
                                     HIR "$N" HIR "��������,����" + weapon->name() + HIR "���������۾�һ�㣬����ӳ�����,$n˫��һ��,��֪����Ǻ�!\n"NOR;
}
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("zixia-shengong",1);             
	if (random(3)==1 && me->query_skill("zixia-shengong",1)>300)
	{
	if( damage_bonus > 50 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)));
	return HIM"$N�����ݺ�! һ������������$n��$l�������Ѫ��!\n"NOR;
        }
}
}