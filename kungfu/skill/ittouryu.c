 //mimicat@fy4
//ittouryu.c
//һ��������
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
                "$nһ�С��з�������Ϊ����������$N�Ĺ��ơ�\n",
                "$nͻȻ�ӻ����ͳ�һ�Ѷ̵�����������������һ����ס��$N�Ĺ�����\n",
});
string *unarmed_parry_msg = ({
                "$nһ�С��з�������Ϊ����������$N�Ĺ��ơ�\n",
                "$nͻȻ�ӻ����ͳ�һ�Ѷ̵�����������������һ����ס��$N�Ĺ�����\n",
});
        mapping *action = ({
                ([      "action" : 
                "$N˫�ֳֵ����߾ٹ�����ͻȻ��$n����һ�С�����������$w������֮��ֱ��$n��Ҫ����ȥ",
                        "dodge" : 10,
                        "parry" : 20,
                        "damage" : 320,
                        "damage_type" : "����",
                ]),
                ([      "action" : 
                "$Nһ�С��������͵ػӶ�$w��$n��ͷ���£�$n����һ������$w�ĵ����������ĵ�Ϯ��$n",
                        "dodge" : 17,
                        "parry" : 14,
                        "damage" : 320,
                        "damage_type" : "����",
                ]),
                ([      "action" : 
                "$N���е�$w���Ⱪ������ᰡ�������һ����ײ��$n",
                        "dodge" : 12,
                        "parry" : 11,
                   "damage" :310,
                        "damage_type" : "����",
                ]),
                ([      "action" : 
                "$N�Ӷ�$w��һ�С�Ҷ�кϡ��������ǣ���㲻��$n",
                        "dodge" : 80,
                        "parry" : 80,
                        "damage" : 340,
                        "damage_type" : "����",
                ]),
                ([      "action" : 
                "$N���е�$w��$n�����ļ�϶�������˽�ȥ��$N���е�$w������һ��������ȥ",
                        "dodge" : 70,
                        "parry" : 70,
                        "damage" : 390,
                        "damage_type" : "����",
                ]),
                ([      "action" : 
                "$N��ͷ���$n��һ����������Ҳ���룬����һ�С����ۡ�$w����������꣬ն��$n���ؿ�",
                        "dodge" : 120,
                        "parry" : 120,
                        "damage" : 320,
                        "damage_type" : "����",
                ]),
        });


int valid_enable(string usage) { return usage == "blade" ||  usage == "parry" ; }



mapping query_action(object me, object weapon)
{
        int i, level;
        object target;

        level   = (int) me->query_skill("ittouryu",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(2)==1 && random(level) > 180)
	{
		return ([
		"action": RED""+(order[random(13)])+"��  ��ͻһʽ! ��"NOR""+HIY"$NͻȻ���٣��̳���ˮƽ��ɨ,׷��������$n!"NOR,
		"force" : 650+random(200),
                "attack" : 50,
		"dodge" : 50,
		"damage": 650+random(200),
	        "skill_name" : "��ͻһʽ!",
		"damage_type" : "����" ]);
	}
	if( random(2)==1 && random(level) > 190)
	{
		return ([
		"action": HIR""+(order[random(13)])+"��  ��ͻ��ʽ! ��"NOR""+HIY"$NͻȻ���٣�����ͷ��,�̳�����$n�˶�����! "NOR,
		"force" : 650+random(200),
                "attack" : 50,
		"dodge" : 70,
		"damage": 650+random(200),
	        "skill_name" : "��ͻ��ʽ!",
		"damage_type" : "����" ]);
	}
	if( random(2)==1 && random(level) > 200)
	{
		return ([
		"action": HIM""+(order[random(13)])+"��  ��ͻ��ʽ! ��"NOR""+HIY"$NͻȻ���٣����´���,��Ծ���$nʹ����ͻ,�����ǶԿյ���ʽ��"NOR,
		"force" : 650+random(200),
                "attack" : 90,
		"dodge" : 50,
		"damage": 650+random(200),
	        "skill_name" : "��ͻһʽ!",
		"damage_type" : "����" ]);
	}
	if( random(2)==1 && random(level) > 240)
	{
		return ([
		"action": HIW""+(order[random(13)])+"��  ��ͻ��ʽ! ��"NOR""+HIY"$N����$n���������͵Ľ����̳�,�����޴�,������һ�б�ɱ�� ��"NOR,
		"force" : 650+random(200),
                "attack" : 120,
		"dodge" : 50,
		"damage": 650+random(200),
	        "skill_name" : "��ͻһʽ!",
		"damage_type" : "����" ]);
	}
 
  
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

string perform_action_file(string action)
{
        return __DIR__"ittouryu/" + action;
}
int valid_learn(object me)
{
    if ((int)me->query_skill("aikido", 1) < 100)
   return notify_fail("��Ŀ��ֵ���򲻹����޷�ѧ��\n");

    if ((int)me->query_skill("xuanhualiu-quanfa", 1) < 100)
   return notify_fail("���������ȭ����򲻹����޷�ѧ��\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("���ɱ���ķ���򲻹����޷�ѧ��\n");
    if ((int)me->query_skill("ninjitsu", 1) < 100)
   return notify_fail("���������򲻹����޷�ѧ��\n");

    if ((int)me->query_skill("enmeiryu", 1) < 100)
   return notify_fail("���½��Բ����ȭ����򲻹����޷�ѧ��\n");

    if ((int)me->query("max_neili") < 50)
   return notify_fail("�������̫�����޷���һ����������\n");
   
        return 1;
}  
 
int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("���ɱ���ķ���򲻹���\n");

    if ((int)me->query("qi") < 70)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 70)
   return notify_fail("�������������һ����������\n");
    me->receive_damage("qi", 60);
    me->add("neili", -60);
    return 1;

}   
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("shayi-xinfa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "shayi-xinfa" && lvl > 300 && random(8)==0)
{
flvl=random(lvl)*2+150;
                  msg = HIR"���ٹ�Ϯ���� ��"+HIM"$N��������ɱ�����죡\n"NOR;
if (random(5)==0) msg = HIC"���ٹ�壡����"+HIY"$N��������ɱ�����죡��\n"NOR;
if (random(5)==1) msg = HIM"���ٹ��飡����"+HIY"$N��������ɱ�����죡 \n"NOR;
if (random(5)==2) msg = HIC"���ٹ�ͻ������"+HIW"$N��������ɱ�����죡\n"NOR;
if (random(5)==3) msg = HIG"���ٹ�׹������"+HIW"$N��������ɱ�����죡\n"NOR;
if (random(5)==4) msg = HIW"���ٹ�ն������"+HIY"$N��������ɱ�����죡 \n"NOR;	
if (victim->query("qi") > flvl)
{
victim->start_busy(2);
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);

}
                return msg;
}
}