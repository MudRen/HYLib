//Cracked by Kafei
// feiyu-bian.c �������澭���޷�
// xQin 8/99 ����������ƮƼ��

#include <ansi.h>
#include <combat.h>

inherit SKILL;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int special(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action" : "�����ֻ����Ӱ������$N�����ǰ��һ��$w��$nӭ��������������׵���������",
	"damage_type" : "����"
]),
([	"action" : "$N�����죬�޷���ã�������$w�������߲��������Ӱ�·�佫������ֱ��$n$l",
	"damage_type" : "����"
]),
([	"action" : "$N���е�$w����һ����˿������û������������Ӻ����������������ˣ���$n����Ʈ������",
	"damage_type" : "����"
]),
([	"action" : "ͻȻ֮�䣬$N����һ��һ�Σ��������ɣ�$w���Ҽ缱˦��󣬶��ػ���$n$l����������������ʸ�ö���",
	"damage_type" : "����"
]),
([	"action" : "$N���ش�$n����һ����������δ����Ȼ�������������۾�һ�㣬$w˵���㵽��ֱָ$n��$l",
	"damage_type" : "����"
]),
([	"action" : "ֻ��$N��Ӱ���ߺ��ͣ�Ʈ���鶯������޷���$w�ؽ����������籩�����$n����",
	"damage_type" : "����"
]),
([	"action" : "$N���ڰ�գ���һֻ��װ�����˻����£��������ޱȣ�$w��������׼$n�����������ȥ������Ѹ��֮��",
	"damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage == "whip" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");


	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, force, dodge, neili;
	object target = offensive_target(me);

	i = random(sizeof(action));
	force = me->query_skill("force");
	dodge = me->query_skill("dodge");
	neili = me->query("neili");
if (!force) force=10;
if (!dodge) dodge=10;
if (!neili) neili=10;
if (target && me)
{
	if( me->query_temp("perform/chanrao/"+target->name()) )
	{
		me->add("neili", -15);
		me->add("jing", -5);
		me->add_temp("perform/chanrao/"+target->name(), -1);

		if( me->query_temp("perform/chanrao/"+target->name()) < 1 )
		{
			me->delete_temp("perform/chanrao");
			target->start_busy(1);
		}
		else target->start_busy(2);
	}
}
	if( objectp(me->query_temp("secondary_weapon")) )
	{
		force /= 2;
		neili /= 2;
	}

	return ([
		"action": action[i]["action"],
		"force" : (random(force)+force)/2,
		"damage": 150+(random(neili)+neili)/100,
		"dodge" : (random(dodge)+dodge)/10,
		"damage_type": action[i]["damage_type"],
		]);
}

int practice_skill(object me)
{
	notify_fail("��ֻ������ʦ��ѧ�ķ������������ܵ�ˮƽ��\n");
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weapon;
weapon = me->query_temp("weapon");
if (me && victim)
{
if (random((int)me->query_skill("feiyu-bian"))>180)
{
victim->receive_damage( "qi", random(400));
victim->receive_wound( "qi", random(200));
                victim->start_busy(1 + random(3));
	return HIR"$N����һ����"+ weapon->name() +
	HIC"��ʱ���ʮ������СС��Ȧ�ӣ��ÿ��Ѽ���\n���ַ��������������¶����һ�Ѷ̵�������$n��\n"NOR;
}
if (random(10)>7)
{
	return HIB"$n����$N������޷�����紵������ˮ�͸�Ƽ��ʵ���˼�������ʱ�������������У�����һ����\n"NOR;
}
}
}



string perform_action_file(string action)
{
	return __DIR__"feiyu-bian/" + action;
}