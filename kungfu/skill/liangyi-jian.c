//liangyi-jian.c ���ǽ���
// modified by Venus Oct.1997

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "name":   "��������",
    "action" : "$N���⽣â������һ��"+(order[random(13)])+"���������ء�"NOR"������$w�����´󿪴��أ�
һ����������$n��$l",
    "force" : 120,
    "dodge" : 120,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������",
    "action" : "$N����Ȧת��һ��"+(order[random(13)])+"������������"NOR"������$wƽչ�´̣�һ�����Ữ
��$n��$l",
    "force" : 120,
    "dodge" : 120,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "Ԩ����ǳ",
    "action" : "$N��������������������������$wʹ��һʽ"+(order[random(13)])+"��Ԩ����ǳ��"NOR"����$n��
$l",
    "force" : 140,
    "dodge" : 115,
    "damage" : 350,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "ˮ�����",
    "action" : "$N������ָ��������ת��һ��"+(order[random(13)])+"��ˮ����ơ�"NOR"ֱȡ$n��$l",
    "force" : 150,
    "dodge" : 115,
    "damage" : 280,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "�ƺ�����",
    "action" : "$N��â���£��������ߣ�����$wʹ��һʽ"+(order[random(13)])+"���ƺ����¡�"NOR"���������
����$n��$l",
    "force" : 130,
    "dodge" : 125,
    "damage" : 300,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "���ѵ�ׯ",
    "action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
"+(order[random(13)])+"�����ѵ�ׯ��"NOR"ԾԾ����Ʈ��$n��$l",
    "force" : 120,
    "dodge" : 125,
    "damage" : 320,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������",
    "action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ"+(order[random(13)])+"���������ǡ�"NOR"������
����֮�ƣ�����$n��$l",
    "force" : 110,
    "dodge" : 115,
    "lvl" : 0,
    "damage" : 400,
    "damage_type" : "����"
]),
([      "name":   "��ϵ�̳�",
    "action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ��"+(order[random(13)])+"����ϵ�̳���"NOR"����
���ϴ���$n��$l",
    "force" : 150,
    "dodge" : 135,
    "damage" : 400,
    "lvl" : 0,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry");}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 800)
		return notify_fail("�������������\n");
        if( (int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("��������޼�������Ϊ����������ʹ������ˮ��! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("���Ѹ�׽����������ң��޷�ʹ������ˮ�䣡\n");
   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("��û���������޼���\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20 && (int)me->query_skill("xuantian-wuji", 1)<20 )
		return notify_fail("��ı����ڹ����̫ǳ��\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("liangyi-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
     return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;
        if( (int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("��������޼�������Ϊ����������ʹ������ˮ��! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 100 )
                return notify_fail("���Ѹ�׽����������ң��޷�ʹ������ˮ�䣡\n");
   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("��û���������޼���\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("����������������ǽ�����\n");
    me->receive_damage("qi", 10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"liangyi-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",level*2+300);
        victim->receive_wound("qi",level*3+300);
	return HIB"$N��̤���Բ�,����̫�Ҿ�,$Nһ����Х��$n˫��һ�ڣ��³�һ����Ѫ!\n"NOR;
}
}