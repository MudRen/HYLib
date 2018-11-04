// xingyi-zhng ��ת������
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С����α�Ӱ����˫�ֻ��˸���Ȧ������$n��$l",
        "force" : 260,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 180,
        "lvl" : 0,
        "skill_name" : "���α�Ӱ",
        "damage_type" : "����"
]),
([      "action" : "$N�����鰴������ʹһ�С����ǵ�㡹����$n��$l��ȥ",
        "force" : 350,
        "dodge" : 10,
        "damage" : 180,
        "lvl" : 40,
        "skill_name" : "���ǵ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫����ȭ����ǰ��󻮻���һ�С������Ƕ�������$n��$l",
        "force" : 400,
        "dodge" : 15,
        "parry" : 5,
        "damage" : 180,
        "lvl" : 80,
        "skill_name" : "�����Ƕ�",
        "damage_type" : "����"
]),
([      "action" : "$N�����黮������һ�ǡ��嶷�ǳ�������$n������",
        "force" : 450,
        "dodge" : 20,
        "parry" : 0,
        "damage" : 180,
        "lvl" : 100,
        "skill_name" : "�嶷�ǳ�",
        "damage_type" : "����"
]),
([      "action" : "$Nʩ�����������ǡ������ֻ���$n��$l�����ֹ���$n���ɲ�",
        "force" : 480,
        "dodge" : 20,
        "lvl" : 110,
        "damage" : 180,
        "skill_name" : "��������",
        "damage_type" : "����"
]),                                                   
([      "action" : "$NԾ���ڰ�գ�˫�ƾ�������磬һʽ��׷�Ǹ��¡�Ѹ���ޱȵ�����$n",
        "force" : 500,
        "dodge" : 35,
        "damage" : 180,
        "parry" : -10,
        "lvl" : 150,
        "skill_name" : "׷�Ǹ���",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
/*
int valid_combine(string combo,object me) { 
         object me;
         me = this_player();
       if ((me->query("family/family_name") == "����Ľ��") && (me->query("family/generation") == 2))
     return combo=="canhe-zhi"; 
}
*/
int valid_combine(string combo)  
{
         object me = this_player();
         mapping myfam = (mapping)me->query("family");

                 return combo=="canhe-zhi";
}
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ת�����Ʊ�����֡�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("�����Ԫ����򲻹����޷�ѧ��ת�����ơ�\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷�����ת�����ơ�\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        string msg;
        level   = (int) me->query_skill("xingyi-zhang",1);
        
        if (me->query_skill("xingyi-zhang",1) > 200
             && me->query_skill("parry",1) > 80
             && random(10) >7){
                switch(random(4)){
                        case 3: msg = HIR"$N˫��������ǰ�����λ�������㽫��"HIW"����"HIR"������$n��̴��Ѩ"NOR; break;
                        case 2: msg = HIG"������$N������ƣ�����һ�������¶�����Ϯ��$n��С��"NOR; break;
                        case 1: msg = HIR"ֻ��$N���������������һԾ�����������������$n��ͷ��"NOR; break;
                        case 0: msg = HIY"$N�ڿ���һ����ת��Я��"HIR"����֮��"HIY"��, ˫�ư���$n�ĵ���"NOR; break;
                      
                }    
                return([      
                        "action": msg,        
                        "force" : 600+random(150),
                        "dodge" : 20,
                        "damage" : 600+random(150),
                        "damage_type" : me->query_temp("mr_riyue")?"����":"����",
                ]);
        }
            
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("���������������ת�����ơ�\n");
        me->receive_damage("jing", 25);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xingyi-zhang/" + action;
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