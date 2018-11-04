// shenlong-bashi ������ʽ
#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$Nʹһ��"+(order[random(13)])+"����Ӱ��б��"NOR"����������һĨ����$n��$l��ȥ",
	"damage" : 120,
	"parry": 10,
	"force": 100,
        "damage_type" : "����",
	"skill_name" : "��Ӱ��б"
]),
([	"action" : "$N������ȣ�˫��ʹһ��"+(order[random(13)])+"���嶡��ɽ��"NOR"������$n��$l",
	"damage" : 130,
	"parry": 30,
	"damage_type" : "����",
	"skill_name" : "�嶡��ɽ"
]),
([	"action": "$N˳��ʹһ��"+(order[random(13)])+"�����в��ȡ�"NOR"���Ƽ�ת�����ƻ��棬����ֱ��$n",
	"damage" : 140,
	"dodge": 80,
	"parry": 20,
	"force": 200,
	"damage_type": "����",
	"skill_name" : "���в���"
]),
([	"action": "$N�˺󼸲���ͻȻ����һ�ƣ�һ��"+(order[random(13)])+"��������β��"NOR"���ޱȹ���ػ���$n",
	"damage" : 150,
	"dodge": 80,
	"parry": 20,
	"force": 250,
	"damage_type": "����",
	"skill_name" : "������β"
]),
([	"action" : "$Nʹһʽ"+(order[random(13)])+"�������ơ�"NOR"��ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
	"damage" : 150,
	"force" : 250,
        "dodge" : 10,
	"lvl" : 30,
        "damage_type" : "����",
	"skill_name" : "������"
]),
([	"action": "$N����ʹ��"+(order[random(13)])+"��Ǭ��������"NOR"������֧�أ�˫�ȷ�������$n",
	"damage" : 160,
	"dodge": 20,
	"parry": 20,
	"force": 250,
	"damage_type": "����",
	"skill_name" : "Ǭ������"
]),
([	"action": "$N���һ����ʹ��"+(order[random(13)])+"��ͬ���ھ���"NOR"������һ�а�����$n",
	"dodge": 25,
	"parry": 10,
	"damage" : 160,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "ͬ���ھ�"
]),
([	"action": "$N����һ�����������ǳ���״����Ȼ���Ǹ��°�ֱײ��$n",
	"dodge": 80,
	"damage" : 170,
	"parry": 10,
	"force": 400,
	"damage_type": "����",
	"skill_name" : "���Ǹ���"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="huagu-mianzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ʽ������֡�\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 25)
		return notify_fail("��������ķ���򲻹����޷�ѧ������ʽ.\n");
	if ((int)me->query_skill("force", 1) < 25)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ������ʽ��\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("�������̫�����޷���������ʽ��\n");
	if (4*(int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shenlong-bashi",1))
		return notify_fail("��������ķ���򲻹����޷�����ѧ������ʽ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        object target;

        level   = (int) me->query_skill("shenlong-bashi",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if (me->query("gender") == "����")
{
	if( random(4)==1 && random(level) > 250)
	{
		return ([
		"action" : HIR"$nץס$N�ĺ󾱣�һ������$N����������ת����$n��Ҹ��ɦ��һ�ѣ�\n"
		   "$n��������������$N������ס$nҸ�£�����������ת��ץס$n��ڣ�����\n"
		   "����$n�����ӣ������Լ�ͷ��������ˤ��"NOR,
		"force" : 550+random(200),
		"dodge" : 350,
		"damage": 550+random(200),
	"skill_name" : "����ٶ�",
	"damage_type" : "����" ]);
	}
 else	if( random(4)==1 && random(level) > 200)
	{
		return ([
		"action" : HIM"$N�������ϣ�$n������̤ס$N�ĺ�����$N˫��һ����������ݣ�\n"
		   "�ұ�ȴ�������Ӷ�����ͻȻ��һ�������$n�Ŀ�����ȥ��ֻһ����\n"
		   "������ץס$n�ҽ����ף�������$nС����ȥ"NOR,
        	"force" : 500,
        	"dodge" : 100,
        	"parry" : 200,
        	"damage": 500,
	"skill_name" : "³�����",
	"damage_type" : "����"]);
	}
 else	if( random(4)==1 && random(level) > 150)
	{
		return ([
               "action" : HIY"$N˫�۷��ڱ���ͻȻ˫��ʮָ���𣬸��ɰ���֮�Σ��������һײ\n"
		   "ʮָ��ץ��$n���ز���$n���һ����$NͻȻһ�������������Ծ��\n"
		   "˫��һ�֣��ѿ���$n��ͷ��ͬʱ˫�ְ�ָѹס$n̫��Ѩ��ʳָ��ü����ָ����"NOR,
        	"force" : 450,
        	"dodge" : 100,
        	"parry" : 200,
        	"damage": 450,
	"skill_name" : "���ཱུ��",
	"damage_type" : "����"
]);
	}
}
	if (me->query("gender") == "Ů��")
{
	if( random(4)==1 && random(level) > 250)
	{
		return ([
		"action" : HIW"$N����΢����������Ť�����㷴�ߣ���$n��С����ȥ��$n������ܣ�\n"
		   "$N˳�Ʒ�������������§ס$nͷ���������ս���׼$n���ģ�һ����ȥ"NOR,
		"force" : 550+random(200),
		"dodge" : 350,
		"damage": 550+random(200),
	"skill_name" : "��������",
	"damage_type" : "����" ]);
	}
 else	if( random(4)==1 && random(level) > 200)
	{
		return ([
                 "action" : HIC"$N�����Ե���$n�������̤ס$N�ĺ�����$N���Դ��������Լ����ؿ����䣬\n"
		   "˳���ڵ���һ�������$n�Ŀ�������������ս�����$n�ĺ���"NOR,
		"force" : 500,
        	"dodge" : 100,
        	"parry" : 200,
        	"damage": 500,
	"skill_name" : "С�����",
	"damage_type" : "����"]);
	}
 else	if( random(4)==1 && random(level) > 150)
	{
		return ([
               "action" : HIG"$N������ǰ���ߣ�˳��һ�������ϵĽ�����$n���ʺ��ȥ"NOR,
        	"force" : 450,
        	"dodge" : 100,
        	"parry" : 200,
        	"damage": 450,
	"skill_name" : "�������",
		"damage_type" : "����"
]);
	}
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}
 
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("�������������������ʽ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"shenlong-bashi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
{
	victim->apply_condition("snake_poison",15);
	victim->apply_condition("chanchu_poison",15);
	victim->apply_condition("ill_fashao",10);
	victim->apply_condition("ill_kesou",10);
	victim->apply_condition("ill_shanghan",10);
	victim->apply_condition("ill_zhongshu",10);
	victim->apply_condition("ill_dongshang",10);
 victim->apply_condition("xuanming_poison",10);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N������У�ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ�$nͷһ��,��Ѫ���!\n";
}

 

}