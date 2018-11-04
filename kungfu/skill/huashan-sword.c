// huashan-sword.c
// Modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action":"$Nһ��"+(order[random(13)])+"�����Ƴ�ᶡ�"NOR"�������鶯��ӯ������$w����$n��$l",
        "force" : 150,
        "dodge" : 15,
        "parry" : 5,
        "damage": 115,
        "lvl" : 0,
        "skill_name" : "���Ƴ��",
        "damage_type":  "����"
]),
([      "action":"$Nʹ��"+(order[random(13)])+"���з����ǡ�"NOR"�����Ʒ���������ڲ�������ţ�����$n��$l",
        "force" : 180,
        "dodge" : 15,
        "parry" : 5,
        "damage": 125,
        "lvl" : 9,
        "skill_name" : "�з�����",
        "damage_type":  "����"
]),
([      "action":"$N��������һ��"+(order[random(13)])+"����������"NOR"��$w���϶��»���һ���󻡣���$n������ȥ",
        "force" : 220,
        "dodge" : 18,
        "parry" : 8,
        "damage": 130,
        "lvl" : 18,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$N��ǰ����һ���������ھ�������$wʹ��"+(order[random(13)])+"���׺���ա�"NOR"�������޳��ֱ��$n",
        "force" : 250,
        "dodge" : 10,
        "parry" : 10,
        "damage": 135,
        "lvl" : 25,
        "skill_name" : "�׺����",
        "damage_type":  "����"
]),
([      "action":"$N���е�$w������ҵ�һ�Σ�ʹ��"+(order[random(13)])+"������ӭ�͡�"NOR"���ź�������ֱ��$n��$l",
        "force" : 280,
        "dodge" : 15,
        "parry" : 15,
        "damage": 140,
        "lvl" : 32,
        "skill_name" : "����ӭ��",
        "damage_type":  "����"
]),
([      "action":"$N����Ծ��һʽ"+(order[random(13)])+"�������ա�"NOR"���������콣Ӱ��$w��$n�����ȥ",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 145,
        "lvl" : 40,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$N�������У�$w�Ƴ�ѩ����â���ӳ�"+(order[random(13)])+"���ޱ���ľ��"NOR"��һ������һ���׵ع���$n",
        "force" : 350,
        "dodge" : 10,
        "parry" : 10,
        "damage": 155,
        "lvl" : 48,
        "skill_name" : "�ޱ���ľ",
        "damage_type":  "����"
]),
([      "action":"$N�����й�ֱ���������������;��Ȼת�����ϣ�"+(order[random(13)])+"����ɽ������"NOR"�˵��Ǳ���޷�",
        "force" : 390,
        "dodge" : 5,
        "parry" : 5,
        "damage": 265,
        "lvl" : 55,
        "skill_name" : "��ɽ����",
        "damage_type":  "����"
]),
([      "action":"$N����б��һ����һ��"+(order[random(13)])+"���Ű�ɭɭ��"NOR"�����ɭȻ��������$n��Χ����",
        "force" : 410,
        "dodge" : 8,
        "parry" : 8,
        "damage": 275,
        "lvl" : 62,
        "skill_name" : "�Ű�ɭɭ",
        "damage_type":  "����"
]),
([      "action":"$N˫������$w����â������һʽ"+(order[random(13)])+"����˫�޶ԡ�"NOR"��Ԧ�����Ҿ��׵���$n���",
        "force" : 450,
        "dodge" : 10,
        "parry" : 10,
        "damage": 285,
        "lvl" : 70,
        "skill_name" : "��˫�޶�",
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
    object ob;
//   if( (string)me->query("gender") != "Ů��" )
//   return notify_fail("��������������ֻ��Ů�Ӳ��������书��\n");
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("�������������û�а취����ɽ������\n");
   if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
        return notify_fail("��ɽ�������������ϼ�񹦲�������\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("���������һ�ѽ�������������\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
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

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30
    ||      (int)me->query("neili") < 5 )
        return notify_fail("�����������������û�а취��ϰ��ɽ������\n")
;
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    //write("�㰴����ѧ����һ�黪ɽ������\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

/*
void skill_improved(object me)
{
    if( (int)me->query_skill("nine-moon-sword", 1)  % 10 == 0 ) {
   tell_object(me,
      RED "\n��ͻȻ����һ������������ͷ��ֻ������ɱ��....\n\n"NOR);
   me->add("bellicosity", 2000);
    } else
   me->add("bellicosity", 200);
}
string perform_action_file(string action)
{
    return CLASS_D("ninemoon") + "/ninemoonsword/" + action;
}
*/

string perform_action_file(string action)
{
        return __DIR__"huashan-sword/" + action;
}
