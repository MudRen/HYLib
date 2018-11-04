// luoying-shenjian.c ��Ӣ��

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" :"$N��ǰһ����˫�ƶ�Ȼ��һ�����Ʒ��أ�����б�ɣ�����һ�С�����էչ��������$n��$l",
        "force" : 150,
        "dodge" : 0, 
        "parry" : -10, 
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "����էչ",
        "damage_type" : "����"
]),
([      "action" :"$N�����ֲ������ƻ��⣬ʹ��һ�С��ط�������������䲻��ǿ������ȴ�紺�����棬�޿ײ��룬����$n����",
        "force" : 180,
        "dodge" : 10, 
        "parry" : -5, 
        "damage": 20,
        "lvl" : 8,
        "skill_name" : "�ط����",
        "damage_type" : "����"
]),
([      "action" :"$N����һ�㣬Ծ�����࣬һʽ�����Ƿɻ������ڰ������ת����Ȧ�ӣ���ջ��ƣ���$n��ͷ����",
        "force" : 220,
        "dodge" : 25, 
        "parry" : -5, 
        "damage": 25,
        "lvl" : 16,
        "skill_name" : "���Ƿɻ�",
        "damage_type" : "����"
]),
([      "action" :"$N����۽���ȥ��ʹ��һ�С��꼱��񡹣��������٣�˫�Ʒ����罣����$n���������ʮ���ƣ�$n��ʱ��æ����",
        "force" : 250,
        "dodge" : 20, 
        "parry" : -15, 
        "damage": 30,
        "lvl" : 24,
        "skill_name" : "�꼱���",
        "damage_type" : "����",
	"weapon" : "�Ʒ�"
]),
([      "action" :"$N����һ�ڳ�����˫��֮�������ĵ�����Ȼһ�֣�һ�С��Ǻ����졹��һ�������ƾ���Ȼ����$n��$l",
        "force" : 290,
        "dodge" : 15, 
        "parry" : -5, 
        "damage": 35,
        "lvl" : 32,
        "skill_name" : "�Ǻ�����",
	"weapon" : "�ƾ�",
        "damage_type" : "����"
]),
([      "action" :"$N˫��΢��������²���������һ�С������׷ɡ���ֻ��$N˫�ۻӶ�������˷�������Ӱ��Ѹ�����׵ػ���$n",
        "force" : 330,
        "dodge" : 20, 
        "parry" : -10, 
        "damage": 40,
        "lvl" : 40,
        "skill_name" : "�����׷�",
	"weapon" : "����",
        "damage_type" : "����"
]),
([      "action" :"$N΢΢һЦ��ʹ��һ�С�����׷�¡�����������ǰ������������ת����סȫ��ͻȻ���ƺ�����������һ������Ӱ���ٵػ���$n��$l",
        "force" : 380,
        "dodge" : 25, 
        "parry" : -10, 
        "damage": 45,
        "lvl" : 48,
        "skill_name" : "����׷��",
        "damage_type" : "����"
]),
([      "action" :"$N�ֱ�΢�ͻȻ����һ����ͷ�����䣬����һʽ�������®���������㱻������һ�ɷ�Բ������������֮��",
        "force" : 400,
        "dodge" : 10, 
        "parry" : 25, 
        "damage": 50,
        "lvl" : 56,
        "skill_name" : "�����®",
        "damage_type" : "����"
]),
([      "action" :"$N��ָ��£��������Ե��һ�С����ƺ�ȡ�������Ϊ�����Ʒ�������������죬���ʯ�����$n������������",
        "force" : 350,
        "dodge" : 25, 
        "parry" : -5, 
        "damage": 60,
        "lvl" : 64,
        "skill_name" : "���ƺ��",
	"weapon" : "�Ʒ�",
        "damage_type" : "����"
]),
([      "action" :"$N����������ʹ��һ�С��׺羭�졹�������������£�����$nü�ģ���������������˳��һ��������һ�䣬��ֱ���⣬ת��$n��$l",
        "force" : 390,
        "dodge" : 20, 
        "parry" : -5, 
        "damage": 70,
        "lvl" : 72,
        "skill_name" : "�׺羭��",
        "damage_type" : "����"
]),
([      "action" :"$N����������²ȳ��Ź����Է�λ��˫�ƻ�������һʽ���������������������ȣ�����$n��$l������������˫�ƾ�����һ���������",
        "force" : 450,
        "dodge" : -20, 
        "parry" : 30, 
        "damage": 80,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :"$Nһ����Х���������ߣ�ʹ��һʽ����Ӣ���졹���������Ʒ׷ɣ�������һʵ�������һʵ�����������罣����Ʈ�����ɣ�$nȫ��Ҫ����һ�����ܹ���",
        "force" : 420,
        "dodge" : 25, 
        "parry" : -10, 
        "damage": 90,
        "lvl" : 90,
	"weapon" : "�Ʒ�",
        "skill_name" : "��Ӣ����",
        "damage_type" : "����"
]),
    ([  "name":         "��Ӣ�ͷ�",
        "action":       "$Nʹһ�С���Ӣ�ͷס�����������Ʈ������$w����ʵʵ�ó���㽣���׷���������$n$l",
        "force":        100,
		"parry":        5,
        "damage":       40,
		"damage_type":	"����"
	]),
    ([  "name":         "�����һ�",
        "action":       "$N�趯$w��һʽ�������һ�����������$n����һ�Σ�����$w�������佣��Ю�Ż�����������$n��$l",
        "force":        140,
        "parry":        -20,
        "damage":       50,
        "damage_type":  "����"
    ]),
    ([  "name":         "��������",
        "action":       "$N������$nһת������$w����һָ��һʽ���������꡹�ó����콣Ӱ����$n$l�����ӳ�����",
        "force":        180,
		"dodge":        10,
        "damage":       70,
		"damage_type":	"����"
	]),
    ([  "name":         "���Ƿɻ�",
        "action":       "$N����ƮȻ�����ڰ��������һ������Ȼһʽ�����Ƿɻ�������$w�������޵�������$n��$l",
        "force":        210,
		"dodge":		-10,
        "damage":       120,
		"damage_type":	"����"
	]),
    ([  "name":         "������",
        "action":       "$N�������࣬һʽ��ϸ���ɷ��ء�ͷ�½��ϣ�һ�С������䡹����$w���һ����������$n��$l",
        "force":        240,
        "dodge":        10,
        "damage":       120,
	"damage_type":	"����"
    ]),
    ([  "name":         "���컨��",
        "action":       "$Nһ�����ʹ�������컨�꡹������$w�ó����컨�꣬Ѹ����������$n��$l",
        "force":        280,
        "dodge":        15,
        "damage":       140,
	"damage_type":	"����"
    ]),
    ([  "name":         "�仨����",
        "action":       "$N��̾һ��������$w����һ����һʱ���仨���⡹��$w��ȻԾ��ٿ�Ļ��������¶���һ���ƮȻ����$n��$l",
        "force":        320,
        "dodge":        0,
        "damage":       140,
	"damage_type":	"����"
    ]),

});

int valid_learn(object me)
{
	object ob;

    if( (int)me->query_skill("bibo-shengong",1) < 30)
        return notify_fail("��ı̲��񹦻�򻹲�����\n");

    if( (int)me->query("max_neili") < 100 )
        return notify_fail("���������������������Ӣ�񽣡�\n");

	if (!objectp(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword")
		return notify_fail("���������һ�ѽ�����ѧϰ������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object ob;

    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 5 )
        return notify_fail("�����������������û�а취��ϰ��Ӣ�񽣡�\n");

	if (!objectp(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword")
		return notify_fail("���������һ�ѽ�����ϰ��������\n");

    me->receive_damage("qi", 30);
	me->add("force", -5);
    //write("�㰴����ѧ����һ����Ӣ�񽣡�\n");
	return 1;
}

