#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": HIG"$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l"NOR,
        "dodge": 20,
        "force": 100,
        "damage": 100,	
        "damage_type": "����"
]),
([      "action": HIM"$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l"NOR,
        "dodge": 30,
        "force": 200,
        "damage": 100,	
        "damage_type": "����"
]),
([      "action": HIC"$N˫��Ю��һ��ǿ�����������$n��$l"NOR,
        "dodge": 40,
	"force": 300,
	"damage": 100,	
	"damage_type": "����"
]),
([      "action": HIW"$N����¶�������Ц�ݣ�˫��Я����˪����ɨ$n"NOR,
        "dodge" : 30,
        "attack": 79,
        "parry" : 37,
        "dmage" : 52,
        "force" : 430,
        "damage_type": "����"
]),
([      "action": "$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
        "dodge" : 22,
        "attack": 96,
        "parry" : 34,
        "dmage" : 67,
        "force" : 490,
        "damage_type": "����"
]),
([      "action": "$N�����Ϻ����������֣������ޱȵ�����$n��$l",
        "dodge" : 20,
        "attack": 113,
        "parry" : 10,
        "dmage" : 82,
        "force" : 530,
        "damage_type": "����"
]),
([      "action": HIW"$N�����һЦ��˫�ƴ��������ĺ�������$n��$l"NOR,
        "dodge" : 28,
        "attack": 139,
        "parry" : 36,
        "dmage" : 95,
        "force" : 580,
        "damage_type": "����"
]),
([      "action": "$N����һ����Х���ۼ�ȫ�����������$n",
        "dodge" : 27,
        "attack": 161,
        "parry" : 21,
        "dmage" : 105,
        "force" : 640,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="sanyin-wugongzhao" || combo=="chousui-zhang"; }
mapping query_action(object me)
{
        if (random(me->query_skill("unarmed")) > 100 &&
            me->query_skill("force") > 100 &&
            me->query_skill("xuantian-strike") > 100 &&
            me->query("force") > 1000 ) {
                me->add("force", -100);
                return ([
                "action": HIW"$Nҧ����⣬������Ѫ��˫�ƴ��������ĺ�������$n��$l"NOR,
                "parry": 50,
                "dodge": 50,
                "force": 400,
                "damage": 500,                	
                "damage_type": "����"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����������Ʊ�����֡�\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("��Ļ����󷨻�򲻹����޷�����������ơ�\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("����������צ��򲻹�.\n");



	if ((int)me->query_skill("chousui-zhang", 1) < 120)
		return notify_fail("��ĳ����ƻ�򲻹�.\n");


	if ((int)me->query_skill("tianshan-zhang", 1) < 120)
		return notify_fail("�����ɽ�ȷ���򲻹�.\n");


	if ((int)me->query_skill("zhaixinggong", 1) < 120)
		return notify_fail("���ժ�ǹ���򲻹�.\n");
		
	if ((int)me->query_skill("chanhun-suo", 1) < 120)
		return notify_fail("��Ĳ�������򲻹�.\n");
        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������̫�����޷�����������ơ�");
	return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("���������������������ơ�\n");
        if (me->query_skill("xuantian-strike", 1) < 50)
                me->receive_damage("qi", 45);
	else
                me->receive_damage("qi", 35);
        me->add("neili", -8);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weapon = me->query_temp("weapon");     
        string msg;
        int lvl;
        int flvl;

        lvl  = me->query_skill("xuantian-strike", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
        if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-600);
                return HIY "$n" HIY "�е�������ѩ���ڻ�һ������ʧ�ˡ���\n" NOR;
        }
else
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
victim->apply_condition("xx_poison",20);
victim->apply_condition("x2_sandu",20);
victim->apply_condition("sanpoison",20);
                return HIY "$n" HIY "�е��������Ƹ���һ�㣬ɢ����һ�ɼ���"
               "�ŵĶ������\n" NOR;
        }       


        if (((int)me->query_skill("xuantian-strike", 1)/2) > random((int)victim->query_skill("force", 1)))
        {
                victim->receive_wound("qi", (damage_bonus/5)+60);
                return HIW "$n" HIW "ֻ��һ�󼫺����ĵ����𣬿���������$N" HIW "���ϵı���������\n" NOR;
        }
}

string perform_action_file(string action)
{
    return __DIR__"xuantian-strike/" + action;
}

int effective_level() { return 20;}
 
string *parry_msg = ({
        "$n˫��΢�ϣ���ž����һ����$N��$w����˫��֮�䡣\n",
        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n˫��һ�ӣ�һ�ɴ�����$N�ͳ����⡣\n",
        "$n��һת����������$N����$w���֡�\n",
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
        return -100;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
	return 100;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("xuantian-strike",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$Nʹ��������,$n��������ѩ���ڻ�һ������ʧ�ˡ���\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       



}