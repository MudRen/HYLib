//wuying-jian ������Ӱ��
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N�ս�����$wһ��"+(order[random(13)])+"����ȥ���硹"NOR"����$n��$l",
        "force" : 280,
        "dodge" : 40,
        "damage" : 280,
        "lvl"    : 0,
        "skill_name" : "��ȥ����", 
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"�������޹⡹"NOR"������$w���´̳���ֱ��$n��ȥ",
        "force" : 280,
        "dodge" : 10,
        "damage" : 280,
        "lvl"    : 20,
        "skill_name" : "�����޹�",
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ��������$wʹ��"+(order[random(13)])+"���������"NOR"ֱ��$n�ĺ�",
        "force" : 300,
        "dodge" : 80,
        "damage" : 300,
        "lvl"    : 40,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N���һ����ʹ��"+(order[random(13)])+"���ľ���ˮ��"NOR"����$wֱ��$n��Ҫ��",
        "force" : 290,
        "dodge" : 60,
        "damage" : 280,
        "lvl"    : 60,
        "skill_name" : "�ľ���ˮ",
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N�������е�$w��ʹ��"+(order[random(13)])+"��������ա�"NOR"�����ֱ��$n",
        "force" : 390,
        "dodge" : 70,
        "damage" : 280,
        "lvl"    : 80,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N�������е�$w��ʹ��"+(order[random(13)])+"������Ҷ�䡹"NOR"��������ֱ��$n",
        "force" : 390,
        "dodge" : 60,
        "damage" : 290,
        "lvl"    : 100,
        "skill_name" : "����Ҷ��", 
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"������������"NOR"������$w�������һ����˸����������$n",
        "force" : 300,
        "dodge" : 80,
        "damage" : 340,
        "lvl"    : 220,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����ʹ������֮����"+(order[random(13)])+"����Ӱ���١�"NOR"������$w�����һ������ǵصĴ���$n",
        "force" : 500,
        "dodge" : 90,
        "damage" : 450,
        "lvl"    : 150,
        "skill_name" : "����Ӱ���١�",
        "damage_type" : "����"
]),
([      "action" : HIY"$Nʹ����Ӱ����֮���վ���[1;36m��������ˮ��[0m,[1;33m����$w��������һ�����$n[0m"NOR,
        "force" : 500,
        "dodge" : 100,
        "damage" : 800,
        "lvl"    : 220,
        "skill_name" : "HIY��������һ��"NOR,
        "damage_type" : "����"
]),



});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
                return notify_fail("��ġ���Ԫһ������򲻹����޷�ѧ����Ӱ��������\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
       return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("����׽�ڹ����̫ǳ��\n");
    if ((int)me->query_skill("riyue-bian", 1) < 150)
       return notify_fail("������±޷����̫ǳ��\n");
    if ((int)me->query_skill("damo-jian", 1) < 150)
       return notify_fail("��Ĵ�Ħ�����̫ǳ��\n");

         if((int)me->query_skill("shaolin-shenfa",1) <120)
      		return notify_fail("�������������㣬����������Ӱ��������\n");              
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������̫�����޷�������Ӱ��������\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("wuying-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 150)
       return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("����׽�ڹ����̫ǳ��\n");
    if ((int)me->query_skill("riyue-bian", 1) < 150)
       return notify_fail("������±޷����̫ǳ��\n");
    if ((int)me->query_skill("damo-jian", 1) < 150)
       return notify_fail("��Ĵ�Ħ�����̫ǳ��\n");
         if((int)me->query_skill("shaolin-shenfa",1) <120)
      		return notify_fail("�������������㣬����������Ӱ��������\n");              
        if ((int)me->query("qi") < 50)
                return notify_fail("�����������������Ӱ��������\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������Ӱ��������\n");
        me->receive_damage("qi", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuying-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"ֻ��$n$l�ƺ�һ�����³�һ����Ѫ���ѱ��׽�Ļ�������������!\n"NOR;
}
        if( damage_bonus < 50 ) return 0;
        if( random(5)==0) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 20) / 2 );
                return HIR "���������꡹һ������һ�����������������Ȼ��$nѪð���ɣ���$N�������ˣ�\n";
        }
        else if( random(damage_bonus/2) > victim->query_str() ) {
                victim->add("qi", -damage_bonus);
                victim->receive_wound("qi", (damage_bonus - 20) / 2 );
                return HIR "���������꡹һ������һ�����������������Ȼ��$nѪð���ɣ���$N�������ˣ�\n";
        }
}


