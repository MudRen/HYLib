 //enmeiryu.c
#include <ansi.h>
inherit SKILL;


string *parry_msg = ({
                "$nһ�ѵ�ס$N�������������һ�ƣ���$N����˦�˳�ȥ��������������\n",
                "$n��$N����ʱ������һ��������ͻȻʹ��һ�С���������һͷײ��$N�Ķ��\n",
        "$N�ۿ���Ҫ������$n��һ˲�䣬$nһ�С��������һԾ����������һ�С� \n",
        "$n����$N�����ļ�϶��ͻȻ�۽���һȭ����$N�����ţ��á����䡹��������һ�С� \n",
        "$nͻȻ��ָ����$N��˫�ۣ�$N����֮��ֻ��ֹͣ����������һ�С�ָ������ \n",
        "$nһ����Һ����$N���۾���һ�С���ϼ�������$N�Ĺ����� \n", 
});
string *unarmed_parry_msg = ({
                "$nһ�ѵ�ס$N�������������һ�ƣ���$N����˦�˳�ȥ��������������\n",
                "$n��$N����ʱ������һ��������ͻȻʹ��һ�С���������һͷײ��$N�Ķ��\n",
        "$N�ۿ���Ҫ������$n��һ˲�䣬$nһ�С��������һԾ����������һ�С� \n",
        "$n����$N�����ļ�϶��ͻȻ�۽���һȭ����$N�����ţ��á����䡹��������һ�С� \n",
        "$nͻȻ��ָ����$N��˫�ۣ�$N����֮��ֻ��ֹͣ����������һ�С�ָ������ \n",
        "$nһ����Һ����$N���۾���һ�С���ϼ�������$N�Ĺ����� \n",
});
        mapping *action = ({
        ([      "action":               
"$Nһ�С���ն������$n��$l�� ",
                "dodge":                90,
                "parry":                70,
                "damage":                150,
                "damage_type":  "����",
                "name":         "��ն",
        ]),
        ([      "action":               
"$N�Ƶ��۽�$n��˫ȭ����$n���·��ϣ�������һ�С����h���� ",
                "dodge":                50,
                "parry":                70,
                "damage":                300,
                "damage_type":  "����",
                "name":         "���h",
                
        ]),
        ([      "action":               
"$Nһ�С����ߡ�����$n�����ڲ࣬������̤ǰһ�����ⲿ��������$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "����",
                "name":         "����",
        ]),
        ([      "action":               
"$Nһ�С�˷�⡹����ȭ��$n����ȭ�ܿ�������ͻȻ����$n��$l�� ",
                "dodge":                10,
                "parry":                50,
                "damage":                120,
                "damage_type":  "����",
                "name":         "˷��",
        ]),
        ([      "action":               
"$N���һ�������¡�������ͻȻ���һ��������֧�أ�$n������ԥ֮�䣬
$N�������ѵ�������$n��$l�� ",
                "dodge":                20,
                "parry":                100,
                "damage":                80,
                "damage_type":  "����",
                "name":         "����",
        ]),
        ([      "action":           
"$Nʹ����һ�С���������˫�־�ס$n���½󣬵�ϥ����$n��$l�� ",
                "dodge":                80,
                "parry":                10,
                "damage":                270,
                "damage_type":  "����",
                "name":         "����",
        ]),     
        ([      "action":           
"$N���һ��ʹ��һ�С����ơ���ͻȻ����$n��������һ������������֧�أ� 
˫���Ƽ��������$n�ľ����� ",
                "dodge":                20,
                "parry":                30,
                "damage":                470,
                "damage_type":  "����",
                "name":         "����",
        ]),            
        ([      "action":           
"$Nһ��ת����������$n�����ţ�$n�����мܣ�$NͻȻ���С��ϵ硹��
��$n��С���� ",
                "dodge":                150,
                "parry":                10,
                "damage":                100,
                "damage_type":  "����",
                "name":         "�ϵ�",
        ]),                    
    
        });

int valid_enable(string usage) { return usage == "hand" ||  usage == "parry" ; }
int valid_combine(string combo) { return combo=="xuanhualiu-quanfa"; }


mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return __DIR__"enmeiryu/" + action;
}
int valid_learn(object me)
{

    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("��½��Բ����ȭ��������֡�\n");
    if ((int)me->query_skill("aikido", 1) < (int)me->query_skill("enmeiryu", 1))
   return notify_fail("��Ŀ��ֵ���򲻹����޷�ѧ��\n");

    if ((int)me->query_skill("xuanhualiu-quanfa", 1) < 10)
   return notify_fail("���������ȭ����򲻹����޷�ѧ��\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 10)
   return notify_fail("���ɱ���ķ���򲻹����޷�ѧ��\n");
    if ((int)me->query_skill("ninjitsu", 1) < 100)
   return notify_fail("���������򲻹����޷�ѧ��\n");

    if ((int)me->query("max_neili") < 50)
   return notify_fail("�������̫�����޷���½��Բ����ȭ����\n");
   
        return 1;
}  
 
int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("���ɱ���ķ���򲻹���\n");

    if ((int)me->query("qi") < 70)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 70)
   return notify_fail("�������������½��Բ����ȭ����\n");
    me->receive_damage("qi", 60);
    me->add("neili", -60);
    return 1;

}   
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
string msg;
	int level, jiali, time,level2;
	object weapon;
        lvl  = me->query_skill("shayi-xinfa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "shayi-xinfa" && lvl > 300 && random(8)==0)
{
flvl=random(lvl)*3+150;
                  msg = HIR"�����ؾ�!��$N�Լ����ٵ�����,�ڵ�һ����,$nû�����ֿ���ʱ����ڶ���! \n"NOR;
if (random(3)==0) msg = HIR"�����ջ���!����$N�����ؾ�����������Զ��������$n,�����ֲ�Զ���빥���Ĳ��� ��\n"NOR;
if (random(3)==1) msg = HIR"���������!����$Nθװ�ʹ�,�û�ʯ�Ƶļ�������������,$n������Ļ������!! \n"NOR;
if (random(3)==2) msg = HIR"���ɺ׷���!����$Nʹ�����ֱ�Ӵ��ڵ�ȭ��֮һ����$n! ���߷��Ѷ���һ��!!\n"NOR;

if (victim->query("qi") > flvl)
{
victim->start_busy(2+random(3));
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);

}
                return msg;
        }

	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shayi-xinfa",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 50 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"ֻ��$n$l����Ѫֱ�����ѱ�����ȭ�����˿���!\n"NOR;
        }

}