// wudu-shenzhang.c �嶾����
// By Kayin@ CuteRabbit Studio 99-4-16 13:34 new
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
        "dodge": 30,
        "force": 840,
        "damage": (int)this_player()->query_skill("wudu-shenzhang",1),
        "damage_type": "����"
]),
([      "action": "$NͻȻ����������$n��˫�Ʒ�������$n��$l",
        "dodge": 10,
        "force": 840,
        "damage": (int)this_player()->query_skill("wudu-shenzhang",1),
        "damage_type": "����"
]),
([	"action": "$N�������������֣������ޱȵ�ץ��$n��$l",
	"dodge": -20,
	"force": 840,
	"damage": (int)this_player()->query_skill("wudu-shenzhang",1),
	"damage_type": "����"
]),
([	"action": "$N˫�����,��������$n��$l",
	"dodge": 10,
	"force": 840,
	"damage": (int)this_player()->query_skill("wudu-shenzhang",1),
	"damage_type": "����"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

mapping query_action(object me, object weapon)
{
	int i, level;
    level   = (int) me->query_skill("wudu-shenzhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}


int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���嶾���Ʊ�����֡�\n");
	if ((int)me->query_skill("yunu-xinfa", 1) < 10)
		return notify_fail("�����Ů�ķ���򲻹����޷������޶��ơ�\n");
	if ((int)me->query("max_neili") < 60)
		return notify_fail("�������̫�����޷����嶾����");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 8)
		return notify_fail("��������������嶾���ơ�\n");
	if (me->query_skill("wudu-shenzhang", 1) < 50)
		me->receive_damage("qi", 20);
	else
		me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( damage_bonus < 100 ) return 0;
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		return HIB "���������项һ�����죬"+victim->name()+"��й����Ƥ�򻺻���̱����\n" NOR;
	}

        if( me->query_skill("yunu-xinfa") > 10 ) {
            victim->apply_condition("wuduz_poison", (me->query_skill("wudu-shenzhang")/10) + 1 +
            victim->query_condition("wuduz_poison"));
	}
	
}
string perform_action_file(string action)
{
	return __DIR__"wudu-shenzhang/" + action;
}

