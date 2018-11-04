// ���콣��
// write by snkboy
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action": "$N���⽣â������һ�С����캮â��������$w�󿪴��أ���âֱ��$n��$l",
        "force" : 250,
        "attack": 150,
        "dodge" : 50,
        "parry" : 50,
        "damage": 351,
        "lvl"   : 0,
        "skill_name" : "���캮â",
        "damage_type" : "����"
]),
([      "action": "$N��â���£�����$wһ�С������������������������ֱ����$n��$l",
        "force" : 270,
        "attack": 180,
        "dodge" : 60,
        "parry" : 60,
        "damage": 378,
        "lvl"  : 30,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ���񽣷������������ƽ���������ʵ��׷ɣ��ó�����ǹ�Ʈ��$n",
        "force" : 280,
        "attack": 220,
        "dodge" : 80,
        "parry" : 80,
        "damage": 347,
        "lvl"   : 50,
        "skill_name" : "�񽣷���",
        "damage_type" : "����"
]),
([      "action": "$N�ӽ��ֻ�����������ǰԾ����$wһʽ��Ⱥа���ס�����������֮�ƣ�����$n",
        "force" : 290,
        "attack": 231,
        "dodge" : 81,
        "parry" : 83,
        "damage": 355,
        "lvl"   : 80,
        "skill_name" : "Ⱥа����",
        "damage_type" : "����"
]),
([      "action": "$N���ֽ�ָ��ת������һŤ������$wһ�ǡ�������ħ�����¶��ϴ���$n��$l",
        "force" : 300,
        "attack": 275,
        "dodge" : 95,
        "parry" : 95,
        "damage": 393,
        "lvl"   : 150,
        "skill_name" : "������ħ",
        "damage_type" : "����"
]),
(["action": HIR "$N��ɫ�������أ���������$w"NOR""HIR"��ͻȻԾ������һ��ʹ��һ�С����첻������\n����$w"NOR""HIR"�������ϻ���һ�������Ļ��ߴ���$n��$l" NOR,    
         "damage": 350,  
         "attack": 300,  
         "dodge": 100,  
         "parry": 100,  
         "lvl": 150,  
         "damage_type": "����",  
         "skill_name": "���첻��",  
]), 
(["action": HIY "$N����Ծ��˫���ս�����ͷ��ʹ�����콣�����塰˭�����桱���⿴�Ƽ�򵥵���һ����\n�����صĽ���ֱ��$n��$l��ȥ"NOR,  
         "damage": 300,  
         "attack": 350,  
         "dodge": 120,  
         "parry": 120,  
         "lvl": 220,  
         "damage_type": "����",  
         "skill_name": "˭������",  
])
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{


        if ((int)me->query("int") < 30) 
                return notify_fail("�����������ԶҲѧ�������콣����\n"); 

        if ((int)me->query("con") < 20)  
                return notify_fail("������ǲ��ʺ��������콣����\n"); 

        if ((int)me->query("max_neili") < 250)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("bagua-dao", 1) < 100)
                return notify_fail("���������Ե����̫ǳ��\n");

        if ((int)me->query_skill("yanxing-dao", 1) < 100)
                return notify_fail("������е����̫ǳ��\n");

        if ((int)me->query_skill("bagua-zhang", 1) < 100)
                return notify_fail("�����������ƻ��̫ǳ��\n");   
                
        if ((int)me->query_skill("jinding-zhang", 1) < 100)
                return notify_fail("��Ľ����ƻ��̫ǳ��\n");
                
        if ((int)me->query_skill("tiangang-zhi", 1) < 100)
                return notify_fail("������ָѨ�����̫ǳ��\n");                

        if ((int)me->query_skill("zhutian-bu", 1) < 100)
                return notify_fail("������컯�����̫ǳ��\n");                

        if ((int)me->query_skill("huifeng-jian", 1) < 100)
                return notify_fail("��Ļط���������̫ǳ��\n");     
                
        if ((int)me->query_skill("sword", 1) < 50)
                return notify_fail("��Ļ����������̫ǳ��\n");

        if (me->query_skill("sword", 1) < me->query_skill("yitian-jian"))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������콣����\n");

        return 1;
}

mapping query_action(object me, object weapon) 
{
        int i, level; 
        level = (int) me->query_skill("yitian-jian", 1); 
         for (i = sizeof(action); i > 0; i--) 
                 if (level > action[i - 1]["lvl"]) 
                         return action[NewRandom(i, 5, level / 5)]; 
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/*
mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("yitian-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}
*/

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("����������������콣����\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("����������������콣����\n");

        me->receive_damage("qi", 50);
        me->add("neili", -60);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus) 
{
         mixed result; 
         object weapon; 


         if (objectp(weapon) && ((string)weapon->query("id") == "yitian jian" || (string)weapon->query("id") == "sky sword") && random(2)==0) 
         {
         victim->receive_damage("qi", me->query_skill("yitian-jian") / 2+20); 
         victim->receive_damage("jing", me->query_skill("yitian-jian") / 5+20); 
         victim->receive_wound("qi", me->query_skill("yitian-jian") / 5+20); 
         return WHT "$N�������콣����ʱ�����ʤ������֮��������Х������$n" 
                WHT "$nֻ����Ѫ���ڣ����ۡ����³�һ����Ѫ��\n" NOR; 
         }

         if (damage_bonus < 60 || random(3)==0)
         {
                victim->receive_wound("qi", (damage_bonus ) / 3+10, me);
                	return "$n"NOR""HIR"ֻ��һ����������ֻ��"NOR"$n"HIR"����Ǿ�¶��һ˿Ѫɫ��\n" NOR;
         }




         if (damage_bonus > 60  && random(2)==0) 
         { 
                victim->receive_wound("qi", (damage_bonus ) / 3+10, me);
                	return "$n"NOR""MAG"ֻ��һ����������ֻ��"NOR"$n"MAG"Ѫð���ɣ��ѱ�$N�Ľ������ˣ�\n" NOR;

         } 
}


string perform_action_file(string action)
{
        return __DIR__"yitian-jian/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
		//ob->add("qi", 10000);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N �������죬�������¶�ׯ����������������Ǳ����
������������ض�����̩��������϶��Ҿ����������֮���ʱ����!��\n"NOR;
msg += "$N��ɫһ��,�ָ���Щ������\n",  
           message_vision(msg, me, ob);
           return j;
} 
}