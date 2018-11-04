#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹ��һ�С����İ�ץ��������ץ��$n��$l",
                "dodge":                -300,
                "parry":                -110,
                "force":                200,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nʹ��һ�С��������ץ�������ֻ�ָΪצ����������$n��$l",
                "dodge":                -100,
                "parry":                -200,
                "force":                170,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nʹ�������׹�צ�ġ�צ�����꡹������Ȱ�����$n��ǰ��һצ����$n��$l",
                "dodge":                -300,
                "parry":                -220,
                "force":                150,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N˫��һ��ʹ�����޵ۿ�צ������׼$n��$l����ץ��",
                "dodge":                -510,
                "parry":                -200,
                "force":                290,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N����ָ�ױ�ͻ�������Ƴ���һ�С����������󡹣�ץ��$n$l",
                "dodge":                -200,
                "parry":                -200,
                "force":                170,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nʹ�������������ǡ���˫��ͬʱ��$n��$l��צ����",
                "dodge":                -100,
                "parry":                -100,
                "force":                180,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N����������һ�С�а������צ��˫�۲����ݳ�",
                "parry":                -400,
                "force":                320,
                "damage_type":  "ץ��"
        ]),
});

int valid_learn(object me)
{
        if( (string)me->query("gender") != "Ů��" )
                return notify_fail("�����׹�צ��ֻ��Ů�Ӳ��������书��\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�������׹�צ������֡�\n");
        if( (int)me->query_skill("nine-moon-force", 1) < 10 )
                return 
notify_fail("��ľ����ľ�����㣬�޷��������׹�צ��\n");
        if( (int)me->query("max_neili") < 100 )
                return notify_fail("�������̫�����޷��������׹�צ��\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }
int effective_level() { return 20;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("neili") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 110 ) return 0;

        if( random(damage_bonus/10) > victim->query_str() ) {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                switch(random(3)) {
                        case 0: return "��������������һ�����죬�����ǹ����������\n";
                        case 1: return "$N����һ�£�$n��$l������������һ�����죡\n";
                        case 2: return "ֻ����$n��$l��������һ�� ...\n";
                }
        }
}
 
string perform_action_file(string action)
{
   return __DIR__"ninemoonclaw/" + action;
}


string *parry_msg = ({
        "$n�����ָ��һ�С���ʯΪ��������$N��$w���εļ���ָ�У�\n",
	"$n����һ����˫��������ץ��$N���е�$w�ƺ�ͻȻ�����������������ö��ò��ȡ�\n",
	"$n��������һץ��һ�С����ӵ�������������һƬ��Ҷһ����$N$w��������Ʈ����\n",
	"$n˫צ����һ��һ����һ�С�������ǡ�������$N���е�$w����˫צ֮�ϣ�\n",
});

string *unarmed_parry_msg = ({
        "$n˫�۱�����һ�С���צ�ѻ꡹����$N˫�����д�Ѩȫ������צ�£�\n",
	"$n���һת����$N���벻���ĽǶ���Ȼ�ػ���һ�С�����զ�֡���$N���ˡ�\n",
	"$n��ָ΢����һ�С��޿ײ��롹��һ����ɭɭ��ָ��ֱ��$N�����š�\n",
	"$n˫�ֽ���һ�С���ؽ�������$NȦ��צ��֮�¡�\n",	
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -30;
}

