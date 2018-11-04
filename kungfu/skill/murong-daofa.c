// murong-daofa.c Ľ�ݵ���

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N���һ�������С���һ�С�����ǵ���׳־�����������϶�����$n��$l��ȥ",
        "force" : 160,
        "dodge" : 10,
        "damage": 230,
        "lvl" : 0,
        "skill_name" : "����ǵ���׳־",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��䵶��ת��Ǭ����������$w�ڿ��м���ת����Ȧ������$n��$l",
        "force" : 200,
        "dodge" : 10,
        "damage": 260,
        "lvl" : 30,
        "skill_name" : "�䵶��ת��Ǭ��",
        "damage_type" : "����"
]),
([      "action" : "$N��һ����һ�С�ң����ǧ��ѩ��,$wֱ��$n�ľ���նȥ",
        "force" : 260,
        "dodge" : 5,
        "damage": 290,
        "lvl" : 70,
        "skill_name" : "ң����ǧ��ѩ",
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�׳־���������������������⻯����㷱�ǣ���$n��$l��ȥ",
        "force" : 300,
        "dodge" : 5,
        "damage": 220,
        "lvl" : 100,
        "skill_name" : "׳־����������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }


int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 10)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
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
        level   = (int) me->query_skill("murong-daofa",1);
        
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                if(random(level) >= 145){
return ([
                "action":GRN+action[NewRandom(i, 20, level/5)]["action"]+NOR,
                "damage":level+random(250),
                "damage_type": "����",
                "dodge": level/3+random(50),
                "force": level+300+random(100),
                ]);
        } else {
                        return action[NewRandom(i, 20, level/5)];
}
}
}
}
/*
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("murong-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
*/

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jing") < 40)
                return notify_fail("�������������Ľ�ݵ�����\n");
		if ((int)me->query("neili") < 15)
                return notify_fail("�������������Ľ�ݵ�����\n");
        me->receive_damage("jing", 25);
		me->add("neili",-8);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"murong-daofa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   object weapon = me->query_temp("weapon");
	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 ) 
{
        victim->receive_wound("qi", damage_bonus/2 );
        return HIR "ֻ��һ���Һ���һ����Ѫ��$n�����е��˿������\n" NOR;	
}
   if(me->query_temp("lianhuan") && !me->query_temp("lianhuan_hit")
      && me->query_skill_prepared("finger") == "canhe-zhi"
      && me->query_skill_mapped("finger") == "canhe-zhi"
      && objectp(weapon)) {
        me->set_temp("lianhuan_hit", 1);
        weapon->unequip();
        if (random(2)==0) victim->start_busy(2);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);  
        weapon->wield();
        me->add("neili", -30);
        me->delete_temp("lianhuan_hit");
        me->add_temp("lianhuan", -1);
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shenyuan-gong",1);
        skill = me->query_skill("shenyuan-gong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenyuan-gong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "shenyuan-gong" || me->query_skill_mapped("force") == "shenyuan-gong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"����������$n�͹����ʹ������������$n�ĳ�����������$n�������������У�\n"NOR;
ob->start_busy(3);
if (random(2)==0)
{
msg += HIC"$N"+HIC+"ʹ�����ƶ�ת��$n����Ī�����������;ת�˷���ֱ���Լ�Ϯ��!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}

}

           message_vision(msg, me, ob);
           return j;
}      
}

