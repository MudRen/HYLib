// TIE@FY3
// blood-sword.c
#include <ansi.h>
inherit SKILL;
mapping *action = ({
       ([     "name":             "ƽ��",
              "action":		"$Nƽ��$w��Ю��������콣�����$n��$l",
              "dodge":            20,
              "damage":           50,
              "damage_type":      "����"
	]),
       ([     "name":             "ͻ��",
              "action":		"$N��$wб����ߣ�����̤��������$n��$l�������",
              "dodge":            10,
              "parry" :           30,
              "damage":           150,
              "damage_type":	"����"
	]),
       ([     "name":             "��ͻ��",
		"action":		"$N����ƽ��$w�������³������㣬������֮�ƴ���$n��$l",
              "dodge":            50,
              "parry":            100,
              "damage":           200,
              "damage_type":      "����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("�������������û�а취ѧ"RED"Ѫ�½���"NOR"��\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30
	||	(int)me->query("neili") < 5 )
		return notify_fail("�����������������û�а취��ϰ"RED"Ѫ�½���"NOR"��\n");
	me->receive_damage("jing", 30);
	me->add("neili", -5);
	//write("�㰴����ѧ����һ��"RED"Ѫ�½���"NOR"��\n");
	return 1;
}

int effective_level() { return 12;}



int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 30;
}
int black_white_ness()
{
	return 100;
}


string perform_action_file(string action)
{
        return __DIR__"blood-sword/" + action;
}


