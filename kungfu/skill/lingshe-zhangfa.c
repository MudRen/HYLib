//lingshe_zhangfa.c �����ȷ�

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action": "$Nʹ��һ��"+(order[random(13)])+"�����߳�����"NOR"������$w�󿪴���ɨ��$n��$l",
	"force" : 150,
	"dodge": 50,
	"damage": 150,
	"lvl" : 1,
	"skill_name" : "���߳���",
	"damage_type": "����"
]),
([	"action": "$N����$w������죬һ��"+(order[random(13)])+"��ҡͷ��β��"NOR"��$n��$l��ȥ",
	"force" : 200,
	"dodge": 50,
	"damage": 200,
	"lvl" : 20,
	"skill_name" : "ҡͷ��β",
	"damage_type": "����"
]),
([	"action": "$N����$w���Ӹ�����ʹһ��"+(order[random(13)])+"�������½���"NOR"����$n��$l",
	"force" : 220,
	"dodge": 50,
	"damage": 230,
	"lvl" : 30,
	"skill_name" : "�����½�",
	"damage_type": "����"
]),
([	"action": "$Nһ��"+(order[random(13)])+"������ͦ��"NOR"������$w����ɨ��$n��$l",
	"force" : 280,
	"dodge": 50,
	"damage": 236,
	"lvl" : 40,
	"skill_name" : "����ͦ��",
	"damage_type": "����"
]),
([	"action": "$Nʹ��һ��"+(order[random(13)])+"���������ߡ�"NOR"��$w�����ػ���$n��$lɨȥ",
	"force" : 300,
	"dodge": 50,
	"damage": 300,
	"lvl" : 50,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([	"action": "$N����$wһ�ӣ�ʹ��һ��"+(order[random(13)])+"���߲����ҡ�"NOR"���������ɨ��$n��$l",
	"force" : 350,
	"dodge": 50,
	"damage": 348,
	"lvl" : 60,
	"skill_name" : "�߲�����",
	"damage_type": "����"
]),
([	"action": "$Nʹ��һ��"+(order[random(13)])+"��������ɽ��"NOR"���߾�����$w����ͷ����$n��$l",
	"force" : 440,
	"dodge":  50,
	"damage": 354,
	"lvl" : 80,
	"skill_name" : "������ɽ",
	"damage_type": "����"
]),
([	"action": "$Nʹ��һ��"+(order[random(13)])+"�����߳�����"NOR"������$w��һ̽��ֱɨ$n��$l",
	"force" : 480,
	"dodge": 53,
	"damage": 400,
	"lvl" : 100,
	"skill_name" : "���߳���",
	"damage_type": "����"
]),

});

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
	level   = (int) me->query_skill("lingshe-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
//	return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 70)
		return notify_fail("�������������\n");
        if ((int)me->query_skill("lingshe-quan", 1) < 60)
                return notify_fail("�������ȭˮƽ���ޡ�\n");
        if ((int)me->query_skill("shexing-diaoshou", 1) < 60)
                return notify_fail("������ε���ˮƽ���ޡ�\n");
        if ((int)me->query_skill("hamagong", 1) < 50)
                return notify_fail("��ĸ�󡹦������졣\n");

	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query_skill("lingshe-quan", 1) < 60)
                return notify_fail("�������ȭˮƽ���ޡ�\n");
        if ((int)me->query_skill("shexing-diaoshou", 1) < 60)
                return notify_fail("������ε���ˮƽ���ޡ�\n");
        if ((int)me->query_skill("hamagong", 1) < 50)
                return notify_fail("��ĸ�󡹦������졣\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������ȷ���\n");
	me->receive_damage("qi", 20);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl,flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;
target=victim;
        level = (int) me->query_skill("hamagong",1);
        level2= (int) me->query_skill("hamagong",1);
        lvl = me->query_skill("lingshe-zhangfa",1);
        flvl = me->query_skill("lingshe-zhangfa",1);


       if (flvl * 2 + random(lvl) > victim->query_skill("force") && random(2)==0)
       {
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
	        return;
        if (!me->query_temp("weapon") )
       	        return; 
              victim->apply_condition("snake_poison",20);
              victim->add("eff_qi",-random(lvl)+1);
                return HIR "ֻ��$nʹ����һ����ȴ�Ǳ����ȶ��˵�С��ҧ�˸����ţ�\n" NOR;
       }

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
{
	target->apply_condition("snake_poison",5);
	target->apply_condition("chanchu_poison",5);
	target->apply_condition("qx_snake_poison",3);
if (!target->is_busy()) target->start_busy(2);	
 return HIR "$N��ת����������һ�䣬һ�ڶ�������$n�³�!$nͷһ�裬��֪���� ��\n";
}

        if( random(me->query_skill("hamagong",1)) > 10 ) 
	{
	victim->apply_condition("snake_poison", random(me->query_skill("hamagong",1)/10) + 1 +
	victim->query_condition("snake_poison"));
        tell_object(victim, HIG "����ñ����еĵط�һ����ľ��\n" NOR );
        tell_object(victim, HIG "ԭ���Ǳ���ͷ�ܳ��Ķ���ҧ��һ�ڣ�\n" NOR );
	}
if (me->query_temp("hmg_dzjm") && random(4)>2 )
{
        victim->receive_damage("qi", damage_bonus/2);
        victim->receive_wound("qi", damage_bonus/2);
 return HIR "$N��ת��������$n�ſ�һҧ!$n�˿�һ������Ѫ�����\n";
}

}

string perform_action_file(string action)
{
    return __DIR__"lingshe-zhangfa/" + action;
}
