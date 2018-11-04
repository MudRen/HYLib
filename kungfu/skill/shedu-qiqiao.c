// shedu-qiqiao.c
#include <ansi.h>;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N��ָ�ӳ���һʽ"+(order[random(13)])+"������ͦ��"NOR"������$n����Ե",
        "force" : 80,
        "damage" : 80,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "����ͦ��",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��֮������һָ��һʽ"+(order[random(13)])+"���������š�"NOR"��ָ��$n����ǰ",
        "force" : 100,
        "damage" : 80,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�����������Ѩ������һʽ"+(order[random(13)])+"�����߰�β��"NOR"����$n��$l����",
        "force" : 120,
        "damage" : 80,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "���߰�β",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀŭ�ӣ�һʽ"+(order[random(13)])+"�����߲�ʳ��"NOR"��˫ָ����$n�Ķ�����硢�ۡ��ء���",
        "force" : 150,
        "dodge" : 5,
        "damage" : 80,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "���߲�ʳ",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ"+(order[random(13)])+"���������С�"NOR"�������������⣬��ָ���Ƶ���$n��$l",
        "force" : 180,
        "dodge" : 15,
        "damage" : 80,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N���������ʮָ�濪��һʽ"+(order[random(13)])+"�����߳�����"NOR"��Сָ����$n��̫ԨѨ",
        "force" : 200,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "���߳���",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ų�������������һʽ"+(order[random(13)])+"��ǧ�߲���"NOR"����$n��ȫ��",
        "force" : 220,
        "dodge" : 25,
        "damage": 220,
        "lvl" : 80,
        "skill_name" : "ǧ�߲���",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���߶����ɱ�����֡�\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹����޷�ѧ�߶����ɡ�\n");

        if ((int)me->query("max_neili") < 350)
                return notify_fail("�������̫�����޷����߶����ɡ�\n");

        if ((int)me->query_skill("poison") < 30)
                return notify_fail("��Ļ���������򲻹����޷�ѧ�߶����ɡ�\n");

        if ((int)me->query_skill("finger")*3 < (int)me->query_skill("shedu-qiqiao"))
                return notify_fail("��Ļ���ָ��ˮƽ���ޣ��޷�����������߶����ɡ�\n");

        if ((int)me->query_skill("poison")*2 < (int)me->query_skill("shedu-qiqiao"))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������߶����ɡ�\n");

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
        level   = (int) me->query_skill("shedu-qiqiao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 55)
                return notify_fail("��������������߶����ɡ�\n");

        me->receive_damage("qi", 52);
        me->add("neili", -44);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shedu-qiqiao/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
       int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	       int neili, neili2;
 
	object weapon;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "wudu-shengong")
{
if (!victim->is_busy()) victim->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
 return HIG "$Nʹ���嶾�񹦣�������$n��������Ѫ��ȫ����˺�����˺ܶ࣡!\n";
}
}