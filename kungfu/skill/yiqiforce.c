#include <ansi.h>
inherit FORCE;
mapping *action = ({
        ([      "action":
"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫһ������$n��$l",
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫһ������$n��$l",
                "force":                250,
                "damage_type":  "����"
        ]),
	([ 	"action":
"$Nʹ��һ�С�������ػ�Ԫ����˫�־۳�һ�Ż�Ԫһ������$n��$l",
                "force":                300,
                "damage_type":  "����"
        ]),
	([	"action":
"$Nʹ��һ�С�������ػ�Ԫ����ȫ���ڿն���ȫ����һ�Ż�Ԫһ������$n��$l",
                "force":                500,
                "damage_type":  "����"
        ]),
});
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
	int force,dmg;
        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
dmg=random(damage_bonus+intp(foo));
                if( random(me->query("combat_exp")) > victim->query("combat_exp")/2)
 {
if (dmg>victim->query("qi")/5) dmg=victim->query("qi")/5;
                        victim->receive_wound("qi",dmg);
                        victim->receive_wound("neili",dmg);
                        return
HIR"$N�Ļ�Ԫһ�����ݻ���$n����Ԫ��������\n"NOR;
                }
        }
        return foo;
}

int valid_enable(string usage) 
{ 
return 	usage=="iron-cloth" ||
	usage=="unarmed" ||
	usage=="force";
}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("��Ԫһ����ֻ����ѧ�ġ�\n");
}

 
int effective_level() { return 50;}

string *absorb_msg = ({
        "$n������ת��˫��΢�����޼᲻�ݵĻ�Ԫһ�������ȶ�����\n",
        "$nʩչ����Ԫһ���������������纮����\n",
        "$n����΢չ����Ԫһ�����������ռ䡣\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n�������ȣ��������飬$N�������ɽ���\n",
        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        "$nʩչ������Ԫ���ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
});
string *parry_msg = ({
        "$n�������ȣ��������飬$N�������ɽ���\n",
        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        "$nʩչ������Ԫ���ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
