//jiuyin-baiguzhao.c
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N��צ��Σ���צ������һ�С�������ǡ�ֱ����$n��$l",
    "force" : 320,
    "dodge" : 10,
    "damage": 30,
    "lvl"   : 0,
    "skill_name" : "�������" ,
	"damage_type" : "ץ��"
]),
([  "action" : "$N˫��������צ��צצ����$n������������������$n��$lץ��",
    "force" : 380,
    "dodge" : 20,
    "damage": 45,
    "lvl"   : 20,
    "skill_name" : "��������" ,
	"damage_type" : "ץ��"
]),
([  "action" : "$N����Χ$nһת��ʹ�������޵�������$n��$l����ȫ������צӰ��",
    "force" : 440,
    "dodge" : 30,
    "damage": 55,
    "lvl"   : 40,
    "skill_name" : "���޵���" ,
	"damage_type" : "ץ��"
]),
([  "action" : "$Nʹһ�С������ơ���˫צ�ó�����צӰץ��$nȫ��",
    "force" : 520,
    "dodge" : 40,
    "damage": 70,
    "lvl"   : 60,
    "skill_name" : "������" ,
	"damage_type" : "ץ��"
]),
([  "action" : "$N����������һ�С�Ψ�Ҷ���˫צ������$n�������",
    "force" : 620,
    "dodge" : 50,
    "damage": 100,
    "lvl"   : 100,
    "skill_name" : "Ψ�Ҷ���" ,
    "damage_type" : "ץ��"
]),
([  "action" : "$N����΢�Σ�һ�С���˼����ǡ���ʮָ��ꪣ�����$n��˫������",
    "force" : 200,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl"   : 0,
    "skill_name" : "��˼�����" ,
]),
([  "action" : "$N������磬ʮָ΢΢������һ�С������Ѻ��ѡ�ץ��$n��ǰ��",  
    "force" : 220,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 10,
    "skill_name" : "�����Ѻ���" ,
]),
([  "action" : "$N˫�ֺ������֣�һ�С���ָ�Ʋ����������Ȱ��ץ��$n�ļ�ͷ",  
    "force" : 250,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl"   : 20,
    "skill_name" : "��ָ�Ʋ���" ,
]),
([  "action" : "$N���ֵ��ػ��������ּ�����һ�С����µ����ա����͵�ץ��$n�Ķ�
ͷ",
    "force" : 290,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl"   : 31,
    "skill_name" : "���µ�����" ,
]),
([  "action" : "$Nʹһ�С��������ķ�������������ľ��磬ײ��$n",
    "force" : 340,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl"   : 43,
    "skill_name" : "�������ķ�" ,
]),
([  "action" : "$NͻȻ˫��ƽ�٣�$nһ�������ڲ²�䣬���$Nವ�һ�½�˫��    
�ջ���ǰ������һ�С�ɭȻ���׹ǡ�����ָ�繳��ֱץ��$n������",
    "force" : 400,
    "dodge" : 35,
    "damage_type" : "����",
    "lvl"   : 56,
    "skill_name" : "ɭȻ���׹�" ,
]),
([  "action" : "$Nʹ���������Բ�ɢ������Ȼ������ϣ�����$n��ת��Ȧ��$n����  
�����Ҽ䣬$N����Ȼͣ��$n������ֻ���һ����Ȧ���������ֳ����Ȧ��ץ$n�ĺ�",  
    "force" : 430,
    "parry" : 20,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 71,
    "skill_name" : "�����Բ�ɢ" ,
]),
([  "action" : "$N���ޱ��飬˫�ۺ�����ҵؼ��ӣ�ʹ���������ѻ��֡���ʮָ    
���������Ѹ���ޱȵ�Ϯ��$nȫ�������Ѩ",
    "force" : 460,
    "parry" : 5,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl"   : 87,
    "skill_name" : "�����ѻ���" ,
]),
([  "action" : "$N������ӣ������������磬һ�����������$N�������ѱ�����  
ɫ�����ż��о���ʩչ����צ�ֹ������������ŵ�צӰ����$n��ͷ��",
    "force" : 520,
    "parry" : 10,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 110,
    "skill_name" : "צ�ֹ�����" ,
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�������׹�צ������֡�\n");
        if ((int)me->query("max_neili") < 200)
            return notify_fail("�������̫�����޷��������׹�צ��\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("jiuyin-baiguzhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	object* ob, obj;
	int i,skill,damage;

	skill = me->query_skill("jiuyin-baiguzhao",1);
	if (me->query("qi") < 250)
		return notify_fail("�������̫���ˡ�\n");
	if (me->query("jing") < 60)
		return notify_fail("��ľ���̫���ˡ�\n");
	if (me->query("neili") < 250)
		return notify_fail("������������������׹�צ��\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("�����������������ˡ�\n");
	if( environment(me)->query("sleep_room") )
		return notify_fail("������������ű�����Ϣ��\n");
        if( !objectp(obj=present("corpse", environment(me))))
		return notify_fail("�������׹�ץ����ʬ�塣\n");
        if( skill > 100 && me->query("shen") > -100)
		return notify_fail("����а���书��������������ġ�\n");
	me->receive_damage("qi", 40);
	me->receive_damage("jing", 30);
	me->add("neili", -100);
	tell_room(environment(me), 
HIB"ֻ��"+me->query("name")+"������Ȧ�¹���������ת���������߰˰㻨�������������һ�죬�۵�
һ�죬�����ֱָ�������ʬ������š���������ָ"HIR"Ѫ����"HIB"���Ὣ������\n");
//	ob = all_inventory(environment(me));
//	for(i=0; i<sizeof(ob); i++)
//	{
//		if( !living(ob[i]) || ob[i]==me ) continue;
//		if(skill+random(skill/2)<(int)ob[i]->query("con")*2) continue;
//		damage = skill - ((int)ob[i]->query("neili") );
//		if( damage > 0 )
//		{
//			ob[i]->receive_damage("qi", damage );
//			if( (int)ob[i]->query("neili") < skill * 2 )
//				ob[i]->receive_wound("qi", damage);
//			tell_object(ob[i], 
//HIB"��Ȼ��ǰ��Ӱ���裬�������ǰһ������ֱϮ���ţ�ȫ����Ȼ�е�Ҫ��˺�ѿ�һ����\n"NOR);
//		}
//		if( userp(ob[i]) ) ob[i]->fight_ob(me);
//		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
//	}
	return 1;
}
void skill_improved(object me)
{
    tell_object(me, HIR "���Ȼ���ĵ�����һ�ɶ��ɱ��ɱ��ɱ����Ҫɱ�������ˣ�\n" NOR );
if (random(2)==0)
    me->add("shen", -(me->query_skill("jiuyin-baiguzhao", 1)));

}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
if (random(10)>8)
{
victim->apply_condition("jy-poison",5);
}
		victim->receive_wound("qi", (damage_bonus - 100) / 3 );
		return HIR "��������������һ�����죬�����ǹ����������\n" NOR;
	}
}

string perform_action_file(string action)
{
    return __DIR__"jiuyin-baiguzhao/" + action;
}
