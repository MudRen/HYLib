// dongyang-dao ��Ȼ�����
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([  "action": "$N���һ����һʽ"+(order[random(13)])+"�� ����"NOR"����$wֱ������������һ���",
    "force" : 40,
    "attack": 30,
    "dodge" : 10,
    "lvl"   : 0,
    "damage": 95,
    "skill_name" : "����",
    "damage_type" : "����"
]),
([  "action": "$NͻȻ���У�һʽ"+(order[random(13)])+"�� ����ն��"NOR"����$n��$l",
    "force" : 80,
    "attack": 35,
    "dodge" : 10,
    "damage": 110,
    "lvl"   : 10,
    "skill_name" : "����ն",
    "damage_type" : "����"
]),
([  "action": "$N���е�$w�����任��������һʽ"+(order[random(13)])+"�� ��̡�"NOR"���ͻȻֱ��$n��$l",
    "force" : 110,
    "attack": 40,
    "dodge" : 15,
    "damage": 110,
    "lvl"   : 30,
    "skill_name" : "���",
    "damage_type" : "����"
]),
([  "action": "$N���е�$w��Ȼ��ת��һʽ"+(order[random(13)])+"�� �Ҵ̡�"NOR"����һ�ŵ�Ӱ��ֱ��$n",
    "force" : 130,
    "attack": 45,
    "dodge" : 25,
    "damage": 125,
    "lvl"   : 50,
    "skill_name" : "�Ҵ�",
    "damage_type" : "����"
]),
([  "action": "$N����$wһ����һʽ"+(order[random(13)])+"�� �����ϡ�"NOR"˫�ֳ����������У�����$n��$l",
    "force" : 140,
    "attack": 40,
    "dodge" : 20,
    "damage": 125,
    "lvl"   : 80,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action": "$N��Хһ����һʽ"+(order[random(13)])+"�� �����ϡ�"NOR"���е�$w��ס�Ļζ����������ѵ�����$n",
    "force" : 180,
    "attack": 45,
    "dodge" : 25,
    "damage": 135,
    "lvl"   : 100,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action": "$Nһת��һʽ"+(order[random(13)])+"�� ��硹"NOR"�ѱ���ȫ������$n��ͻȻ˫��һת��$w��$N������˳���",
    "force" : 200,
    "attack": 45,
    "dodge" : 15,
    "damage": 140,
    "lvl"   : 120,
    "skill_name" : "���",
    "damage_type" : "����"
]),
([  "action": "$N��ȻǰϮ��һʽ"+(order[random(13)])+"�� ��ͻ����"NOR"����$w����һ����â�����Ĵ���$n",
    "force" : 210,
    "attack": 50,
    "dodge" : 30,
    "damage": 160,
    "lvl"   : 150,
    "skill_name" : "��ͻ��",
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 

int valid_learn(object me)
{
object ob;
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");

    if ((int)me->query_skill("force") < 30)
        return notify_fail("����ڹ���򲻹���\n");

    if ((int)me->query_skill("blade", 1) < (int)me->query_skill("huoxinliu-jianfa", 1))
        return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������Ȼ�������\n");

   if( (string)me->query_skill_mapped("force")!= "shayi-xinfa")
        return notify_fail("��Ȼ������������ɱ���ķ���������\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "blade" )
        return notify_fail("���������һ�ѵ���������Ȼ�������\n");

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
        object target;

        level   = (int) me->query_skill("huoxinliu-jianfa",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(6)==1 && random(level) > 180)
	{
		return ([
		"action": RED""+(order[random(13)])+"��  ��ͻһʽ! ��"NOR""+HIY"$NͻȻ���٣��̳���ˮƽ��ɨ,׷��������$n!"NOR,
		"force" : 550+random(200),
                "attack" : 50,
		"dodge" : 50,
		"damage": 550+random(200),
	        "skill_name" : "��ͻһʽ!",
		"damage_type" : "����" ]);
	}
	if( random(6)==1 && random(level) > 190)
	{
		return ([
		"action": HIR""+(order[random(13)])+"��  ��ͻ��ʽ! ��"NOR""+HIY"$NͻȻ���٣�����ͷ��,�̳�����$n�˶�����! "NOR,
		"force" : 550+random(200),
                "attack" : 50,
		"dodge" : 70,
		"damage": 550+random(200),
	        "skill_name" : "��ͻ��ʽ!",
		"damage_type" : "����" ]);
	}
	if( random(6)==1 && random(level) > 200)
	{
		return ([
		"action": HIM""+(order[random(13)])+"��  ��ͻ��ʽ! ��"NOR""+HIY"$NͻȻ���٣����´���,��Ծ���$nʹ����ͻ,�����ǶԿյ���ʽ��"NOR,
		"force" : 550+random(200),
                "attack" : 90,
		"dodge" : 50,
		"damage": 550+random(200),
	        "skill_name" : "��ͻһʽ!",
		"damage_type" : "����" ]);
	}
	if( random(6)==1 && random(level) > 240)
	{
		return ([
		"action": HIW""+(order[random(13)])+"��  ��ͻ��ʽ! ��"NOR""+HIY"$N����$n���������͵Ľ����̳�,�����޴�,������һ�б�ɱ�� ��"NOR,
		"force" : 650+random(200),
                "attack" : 120,
		"dodge" : 50,
		"damage": 650+random(200),
	        "skill_name" : "��ͻһʽ!",
		"damage_type" : "����" ]);
	}
 
  
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");

    if ((int)me->query("qi") <750)
        return notify_fail("���������������Ȼ�������\n");

    if ((int)me->query("neili") < 55)
        return notify_fail("���������������Ȼ�������\n");

    me->receive_damage("qi", 60);
    me->add("neili", -42);

    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"huoxinliu-jianfa/" + action;
}
