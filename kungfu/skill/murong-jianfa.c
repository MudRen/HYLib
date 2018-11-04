// murong-jiafa Ľ�ݽ���

#include <ansi.h>;
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N������ָ��һʽ"+(order[random(13)])+"��ϴ��������"NOR"��˫�ź�������������ֱ��$n�Ȳ�",
        "force" : 100,
        "dodge" : 120,
        "damage" : 180,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N̤ǰ�����������ʵ������ʹһʽ"+(order[random(13)])+"�����������"NOR"ֱ��$n������",
        "force" : 100,
        "dodge" : 115,
        "damage" : 160,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"���������"NOR"�����ⶶ����佣�����ֱ����$n���������Ҷ�",
        "force" : 140,
        "dodge" : 115,
        "damage" : 180,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N�����ڣ�����ָ��$n��������һ��"+(order[random(13)])+"������Ī����"NOR"����������ǧ��һ�㣬��ɨ$n��$l",
        "force" : 200,
        "dodge" : 110,
        "damage" : 200,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N˫����أ�ʹ�����Ϸɣ�����ֱ��$n��һ��"+(order[random(13)])+"���ﻢ���¡�"NOR"�������й���ƽ��$n��$l",
        "force" : 260,
        "dodge" : 105,
        "damage" : 220,
        "lvl" : 80,
        "damage_type" : "����"
]),
([      "action" : "$N��Цһ�����ὣб����һ��"+(order[random(13)])+"����ש����"NOR"���������$n��$l",
        "force" : 300,
        "dodge" : 105,
        "damage" : 240,
        "lvl" : 100,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 80)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("murong-daofa", 1) < 80)
                return notify_fail("���Ľ�ݵ������̫ǳ��\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 80)
                return notify_fail("������������̫ǳ��\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 80)
                return notify_fail("��Ķ�ת�����ƻ��̫ǳ��\n");


        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("murong-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 80)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("murong-daofa", 1) < 80)
                return notify_fail("���Ľ�ݵ������̫ǳ��\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 80)
                return notify_fail("������������̫ǳ��\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 80)
                return notify_fail("��Ķ�ת�����ƻ��̫ǳ��\n");

        if ((int)me->query("jing") < 20)
                return notify_fail("�������������Ľ�ݽ�����\n");
		if ((int)me->query("neili") < 20)
                return notify_fail("�������������Ľ�ݽ�����\n");
        me->receive_damage("jing", 20);
		me->add("neili",-15);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"murong-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   object weapon = me->query_temp("weapon");

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