#include <ansi.h>
// huagu-mianzhang ��������
inherit SKILL;

mapping *action = ({
([  "action" : "$N����΢�Σ�һ�С���������ǡ���ʮָ��ꪣ�����$n��˫������",
    "force" : 200,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl"   : 0,
    "skill_name" : "���������" ,
]),
([  "action" : "$N������磬ʮָ΢΢������һ�С������Ѻ��ѡ�ץ��$n��ǰ��",  
    "force" : 220,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 20,
    "skill_name" : "�����Ѻ���" ,
]),
([  "action" : "$N˫�ֺ������֣�һ�С����紵�䳾�������Ȱ��ץ��$n�ļ�ͷ",  
    "force" : 250,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl"   : 40,
    "skill_name" : "���紵�䳾" ,
]),
([  "action" : "$N���ֵ��ػ��������ּ�����һ�С�����ӳ��ɳ�����͵�ץ��$n�Ķ�
ͷ",
    "force" : 290,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl"   : 60,
    "skill_name" : "����ӳ��ɳ" ,
]),
([  "action" : "$Nʹһ�С�ɭȻ���ķ�������������ľ��磬ײ��$n",
    "force" : 340,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl"   : 80,
    "skill_name" : "ɭȻ���ķ�" ,
]),
([  "action" : "$N���ޱ��飬˫�ۺ�����ҵؼ��ӣ�ʹ���������ֹǺ�����ʮָ    
���������Ѹ���ޱȵ�Ϯ��$nȫ�������Ѩ",
    "force" : 460,
    "parry" : 5,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl"   : 100,
    "skill_name" : "�����ֹǺ�" ,
]),
([  "action" : "$Nʹ������ɳƮ���꡹����Ȼ������ϣ�����$n��ת��Ȧ��$n����  
�����Ҽ䣬$N����Ȼͣ��$n������ֻ���һ����Ȧ���������ֳ����Ȧ��ץ$n�ĺ�",  
    "force" : 430,
    "parry" : 20,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 120,
    "skill_name" : "��ɳƮ����" ,
]),
([  "action" : "$NͻȻ˫��ƽ�٣�$nһ�������ڲ²�䣬���$Nವ�һ�½�˫��    
�ջ���ǰ������һ�С��׹����޺�������ָ�繳��ֱץ��$n������",
    "force" : 400,
    "dodge" : 35,
    "damage_type" : "����",
    "lvl"   : 140,
    "skill_name" : "�׹����޺�" ,
]),
([      "action": "$Nʹһ�С����߰�β����ȫ����Ȼһ������$nˤ���ڵ�",
	"dodge": 130,
	"parry": 10,
	"force": 20,
	"skill_name" : "���߰�β",
	"damage_type": "����"
]),
([      "action": "$N����������һ�С���������մ��$n������ͬʱչ��ҡ�򣬺��$n��ǰ��",
	"dodge": 15,
	"parry": 20,
	"force": 130,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action": "$N�����ⷭ���������ϣ������ڷ����ķ����ϣ�һ�С�˫����β����\n"
		  "ץס$n���ֱۣ��������",
	"dodge": 10,
	"parry": 10,
	"force": 130,
	"skill_name" : "˫����β",
	"damage_type": "����"
]),
([      "action": "$N˫�ƽ��棬ʹһ�С�˫�����项������$n���ֱۣ��ҽ�ǰ��$n����С��",
	"dodge": 15,
	"parry": 30,
	"force": 160,
	"skill_name" : "˫������",
	"damage_type": "����"
]),
([      "action": "$N���������ڹ����������$n���ֱۣ�������ȭ����ֱ��$n���沿��"
		   "һ�С��������̡�",
	"dodge": 10,
	"parry": 10,
	"force": 150,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action": "$N�ҽ���㣬��������$n�����棬ͬʱ�ҽŷ���$n��������������ߡ�",
	"dodge": 10,
	"parry": 20,
	"force": 160,
	"skill_name" : "�������",
	"damage_type": "����"
]),
([      "action": "$N�����鰴$n������ͻȻ�����ڲ���š�����ձ�����һ�ǡ�������ġ�\n"
		  "�ͻ�$n��$l",
	"dodge": 20,
	"parry": 20,
	"force": 180,
	"skill_name" : "�������",
	"damage_type": "����"
]),
([      "action": "$N���߿粽��һ�С����Ը�ɽ��������$n���ɲ�",
	"dodge": 25,
	"parry": 10,
	"force": 120,
	"skill_name" : "���Ը�ɽ",
	"damage_type": "����"
]),
([      "action": "$N��ϥ��$n����ϥ��ʹһ�С��ض�ɽҡ�������䲻��ʹ$nʧȥ����",
	"dodge": 25,
	"parry": 20,
	"force": 150,
	"skill_name" : "�ض�ɽҡ",
	"damage_type": "����"
]),
([      "action": "$N�ٳ���ȭ��$n�ұ۹�����һ�С�ֱ����̶�����߹�������ֱѹ$n������",
	"dodge": 30,
	"parry": 20,
	"force": 160,
	"skill_name" : "ֱ����̶",
	"damage_type": "����"
]),
([      "action": "$N����ȭ���������Լ����ұ���ǰ���Ϸ���$n���ұۣ�һ�С�����������",
	"dodge": 20,
	"parry": 30,
	"force": 120,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action": "$N�����Ҳ���˫�ְڶ��Ի�$n��һ�С�ˮ�����¡���\n"
		  "�������ֵ��ڻ��º��$n������",
	"dodge": 20,
	"parry": 20,
	"force": 160,
	"skill_name" : "ˮ������",
	"damage_type": "����"
]),
([      "action": "$N���������������ת����׵������һ�ǡ����߾��ɡ���\n"
		  "�Բ��ɿ���֮������$n��ȫ��",
	"dodge": 15,
	"parry": 20,
	"force": 180,
	"skill_name" : "���߾���",
	"damage_type": "����"
]),
([      "action": "$N��������$n���ֱ��ഥ��ͻȻ������$n����\n"
		  "ʹ����������ɽ������������$n",
	"dodge": 25,
	"parry": 30,
	"force": 150,
	"skill_name" : "������ɽ",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }  

int valid_combine(string combo) { return combo=="shenlong-bashi"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("���������Ʊ�����֡�\n");
	if (2*(int)me->query_skill("shenlong-xinfa",1) <(int)me->query_skill("shenlong-bashi",1))
		return notify_fail("��������ķ���򲻹����޷�����ѧ�������ơ�\n");
    if ((int)me->query_skill("force", 1) < 50)
   return notify_fail("����ڹ��ķ���򲻹������������ƻ��߻���ħ��\n");
    if ((int)me->query("max_neili") < 300)
   return notify_fail("�������̫�����޷����������ơ�\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
    if(level >= action[i-1]["lvl"])
        return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int)me->query_skill("huagu-mianzhang",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 8)
        return notify_fail("��������������������ơ�\n");
    if (me->query_skill("jiuyin-zhua", 1) < 60)
        me->receive_damage("qi", 15);
    else
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"huagu-mianzhang/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        int amount;
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
        if((int)me->query_skill("huagu-mianzhang")>100)
{
        if( random(damage_bonus) > (int)victim->query_skill("force") / 2
        &&  !victim->query_temp("hgmz") )  {
                victim->set_temp("hgmz", 1);
                amount = 5 * damage_bonus/( 1 + victim->query_con()) + 1;
				amount = amount/100;
                victim->add_temp("apply/strength", -amount);
                victim->start_busy(3);
                victim->start_call_out( (: call_other, __FILE__, "remove_effect", victim, me, amount :), (int)me->query_skill("huagu-mianzhang", 1) / 20);
                message_vision(HIB"\n$N��ʱͷ��Ŀѣ����ʱ����Ż�£���䡰���������Ĳ�ס������\n"NOR, victim);
        }
}
}

void remove_effect(object victim, object me, int amount)
{
        victim->delete_temp("hgmz");
        victim->add_temp("apply/strength", amount);
        message_vision(HIB"\n$N�ظ�����Ѫ��ӿ�����ۡ���һ����������Ѫ��������ˮ��������˳�����\n"NOR, victim);
        if( me )
        victim->receive_wound("qi", amount * 10 + random(amount * 10));
        else
        victim->receive_wound("qi", amount * 10 + random(amount * 10));
}

