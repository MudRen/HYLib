//Cracked by Kafei
// luoyan-jian.c ��ɽ�ɽ������ط����㽣��
// maco 1999.1.13

#include <ansi.h>
#include <combat.h>
inherit SKILL;

int yunwu(object me, object victim, object weapon, int damage);

mapping *action = ({
([      "action":"$N����$w���������ͻȻ���ڿ���һ����һ�С�Ȫ��ܽ�ء������а�������֮����$w��·������ȣ���̼侹Ȼ���Ƶ���$n����",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage": 115,
        "lvl" : 0,
        "skill_name" : "Ȫ��ܽ��",
        "damage_type":  "����"
]),
([      "action":"$Nȫ�����Է�������·��ʹ��һ�С������ϸǡ����仯Ī��ع���$n�����ƾ���˿�������Ѱ",
        "force" : 200,
        "dodge" : 5,
        "parry" : 5,
        "damage": 215,
        "lvl" : 10,
        "skill_name" : "�����ϸ�",
        "damage_type":  "����"
]),
([      "action":"$N����$w�ζ�����ʯ��������ʹ��������������������$n���Ƶ��ľ���ѣ����֪$N�������˶�����",
        "force" : 260,
        "dodge" : 8,
        "parry" : 8,
        "damage": 130,
        "lvl" : 20,
        "skill_name" : "ʯ������",
        "damage_type":  "����"
]),
([      "action":"$N$w������仯������һ�С���������������������֮���£������޶�������׽����$n����һ���ۻ����ң��ٸ����Ӧ��",
        "force" : 330,
        "dodge" : 10,
        "parry" : 15,
        "damage": 140,
        "lvl" : 30,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action":"$NͻȻ��������б��ܳ���ʹ�������ף�ڡ�������$w�����Ȼ֮���������⻷��ת����ʱ֮���ѽ�$n����һ�Ž���֮��",
        "force" : 410,
        "dodge" : 10,
        "parry" : 10,
        "damage": 250,
        "lvl" : 50,
        "skill_name" : "���ף��",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
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
        string *msg1,*msg2;
        msg1 = ({
		HIW"$N����$w"+HIW"�������裬��������������ʵʵ�����˶�Ŀ���仯�Ź�֮����$n�������º�Ȼ��"NOR,
		HIW"$N����$w"+HIW"ԽʹԽ�죬һ�ס��ٱ�ǧ�ú�ɽ����ʮ��ʽ�������ƾ���ӿ��$n���ɵ�ĿΪ֮ѣ��"NOR,
		HIW"����$N����$w"+HIW"���б�ã�������ȣ��廨���ţ�������$n������ǰ����һƬ���������ȥ��"NOR,
        });
        msg2 = ({
		HIR"����һ�����Ѫ��$w"+HIR"�½��˳�����$n��Ų��Ծ�������мܣ�ʼ���Ѳ���$N�Ľ������֣���Ѫ���������ܽ�����һ����Ȧ��$N���Ѵ̳�һ����"NOR,
		HIY"$Nһ����ռ�Ȼ����������������һ��$w"+HIY"�������ߣ�������������$n�Ĺ����д�����ȥ��ֻ�Ƶ�$n�������ˣ�"NOR,
		HIY"$n����һ������֮�£��������ˣ�$N����$w"+HIY"������������������������������䣬�仯�켫��"NOR,

        });
	if(me->query_temp("yunwu") && me->query_temp("yunwu_hit") ){
        me->add("neili", -20);
	me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 500,
        "damage_type":"����"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 550,
	"post_action": (: yunwu :),	
        "damage_type":"����"]);
        }


        level   = (int) me->query_skill("luoyan-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_skill("luoyan-jian",1) < 199)
           return notify_fail("�����ֻ�ܴ��ڶ��ټ�ʱ��ѧϰ��\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
}


int yunwu(object me, object victim, object weapon, int damage)
{

if (!victim) return 0;
if (!me) return 0;

        if(damage==RESULT_DODGE || damage==RESULT_PARRY) return 1;

	   else if ( !living(victim) && victim->query_skill("force") > 100 ) {
                message_vision(HIR"\n����$n�˿���һ��Ѫ����ӿȪ�����������ԭ��$p�н�������δ��������Ѫ�Ƶô��˿��м���������ȹ��죬�ֿɲ���\n" NOR, me,victim);
		me->delete_temp("yunwu");
                return 1;
	   }
	else{
if (!victim) return 0;
if (!me) return 0;
if (me->is_busy() ) return 0;
//if (victim=me) return 0;
	me->add("neili", -30);
        victim->start_busy(2);
        victim->receive_damage("qi", random(30)+20);
	me->set_temp("yunwu_hit", 1);
	if(victim && me)
        {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
	}
}


string perform_action_file(string action)
{
        return __DIR__"luoyan-jian/" + action;
}
