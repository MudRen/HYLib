#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([      "action": "$N��ǰб��һ����һ��"+(order[random(13)])+"���������"NOR"������$wֱ��$n�ĺ�",
        "force" : 126,
        "parry" : 3,
        "dodge" : 5,
        "damage": 221,
        "lvl"   : 0,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action": "$N����ǰ��һ��"+(order[random(13)])+"������ǧ�"NOR"�������������ޣ�$w��������$n��$l��ȥ",
        "force" : 149,
        "parry" : 13,
        "dodge" : 10,
        "damage": 225,
        "lvl"   : 30,
        "skill_name" : "����ǧ��",
        "damage_type":  "����"
]),
([      "action": "$Nһʽ"+(order[random(13)])+"�����б��¡�"NOR"������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
        "force" : 167,
        "parry" : 12,
        "dodge" : 15,
        "damage": 231,
        "lvl"   : 50,
        "skill_name" : "���б���",
        "damage_type":  "����"
]),
([      "action": "$N��������Ծ��һʽ"+(order[random(13)])+"��������⡹"NOR"��������ˮ��һкǧ�����$nȫ��",
        "force" : 187,
        "parry" : 23,
        "dodge" : 19,
        "damage": 245,
        "lvl"   : 70,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N����ǰ��һ��"+(order[random(13)])+"������ǧ�"NOR"�������������ޣ�$w��������$n��$l��ȥ",
        "force" : 197,
        "parry" : 31,
        "dodge" : 27,
        "damage": 256,
        "lvl"   : 90,
        "skill_name" : "����ǧ��",
        "damage_type":  "����"
]),
([      "action":"$N����$w�й�ֱ����һʽ"+(order[random(13)])+"������һ�롹"NOR"��������Ϣ�ض�׼$n��$l�̳�һ��",
        "force" : 218,
        "parry" : 49,
        "dodge" : 35,
        "damage": 263,
        "lvl"   : 110,
        "skill_name" : "����һ��",
        "damage_type":  "����"
]),
([      "action":"$N����$wһ����һʽ"+(order[random(13)])+"���ǹ�����"NOR"��������Ϣ�ػ���$n��$l",
        "force" : 239,
        "parry" : 52,
        "dodge" : 45,
        "damage": 272,
        "lvl"   : 130,
        "skill_name" : "�ǹ�����",
        "damage_type":  "����"
]),
([      "action":"$N����$wбָ���죬��â���£�һʽ"+(order[random(13)])+"��ӳ��������"NOR"����׼$n��$lбб����",
        "force" : 257,
        "parry" : 55,
        "dodge" : 51,
        "damage": 288,
        "lvl"   : 150,
        "skill_name" : "ӳ������",
        "damage_type":  "����"
]),
([      "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ"+(order[random(13)])+"���������ȡ�"NOR"����$n���ʺ�",
        "force" : 282,
        "parry" : 63,
        "dodge" : 55,
        "damage": 205,
        "lvl"   : 170,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action":"$N���Ƶ�����һʽ"+(order[random(13)])+"��Ӱ����ԡ�"NOR"��$w�Ի���Ծ�����缲�������$n���ؿ�",
        "force" : 331,
        "parry" : 76,
        "dodge" : 65,
        "damage": 222,
        "lvl"   : 190,
        "skill_name" : "Ӱ�����",
        "damage_type":  "����"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹�������ѧϰ���½��衣\n");

        if (me->query_skill("sword", 1) < 80)
                return notify_fail("��Ļ���������򲻹�������ѧϰ���½��衣\n");

        if (me->query("max_neili") < 1000)
                return notify_fail("�����������������ѧϰ���½��衣\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liuyue-jian", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������½��衣\n");

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
        level = (int) me->query_skill("liuyue-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 80)
                return notify_fail("����������������½��衣\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("����������������½��衣\n");

        me->receive_damage("qi", 60);
        me->add("neili", -60);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liuyue-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("beiming-shengong",1);
        level2= (int) me->query_skill("beiming-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "beiming-shengong")
{

if (victim->query("neili") >= damage2)
{
victim->add("neili",-damage2);
me->add("neili",damage2);
}
	return HIW"$NͻȻʹ����ڤ��,$nȫ����������ˮ��ԴԴ����������$N������!\n"NOR;
}

        lvl  = me->query_skill("tianyu-qijian", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(6)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
victim->apply_condition("ss_poison", 10 +
		victim->query_condition("ss_poison"));
}
                return HIW "$n" HIW "�������˼���������!!\n" NOR;
        }

        else if (random(5)==0)
        {
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
}
                return HIG "$n" HIG "��һ������Ҫ������Ѫ�ɳ�!!\n" NOR;

}                        }
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 10) / 2 );
		return  HIG "$n" HIG "����ڤ��һ���³�һ�����Ѫ!!\n" NOR;
	}
}