// hunyuan-zhang.c ��Ԫ��

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N�Ʒ缤����˫�ƴ��䣬���������޷���һ�С��ƶ����롹������$n��$l",
        "force" : 170,
        "dodge" : 5,
        "parry" : 5,
	"damage": 170,
        "lvl" : 5,
        "skill_name" : "�ƶ�����",
        "damage_type" : "����"
]),
([      "action" : "$N˫������һ�С����ɴ�䡹��һ�ƻ���$n���ţ���һ��ȴ����$nС��",
        "force" : 230,
        "dodge" : 5,
        "parry" : 10,
	"damage": 170,
        "lvl" : 15,
        "skill_name" : "���ɴ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ������Ī�⣬һ�С���ɽ��ˮ����ǰ�����ң�˲Ϣ֮����$n������ʮ����",
        "force" : 300,
        "dodge" : 15,
        "parry" : 20,
	"damage": 170,
        "lvl" : 25,
        "skill_name" : "��粻��",
        "damage_type" : "����",
]),
([      "action" : "$Nһ����Х������һ�ƣ�һ�С�ɽ��·ת��������ת׾��ȴ��ȥ����죬��$n��$l�ͻ���ȥ��",
        "force" : 280,
        "dodge" : 20,
        "parry" : 25,
	"damage": 170,
        "lvl" : 35,
        "skill_name" : "ɽ��·ת",
        "damage_type" : "����"
]),
([      "action" : "$N���һ����˫�ƽ����������ޣ�Ʈ���һ�С��������á����Ʒ缱������$n��$l",
        "force" : 290,
        "dodge" : 5,
        "parry" : 5,
	"damage": 170,
        "lvl" : 45,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ɽ�Ϻӡ�������һȭ���������ƽ���������ȭ��һ����˫������������$n��$l",
        "force" : 310,
        "dodge" : 5,
	"damage": 175,
        "parry" : 3,
        "lvl" : 55,
        "skill_name" : "��ɽ�Ϻ�",
        "damage_type" : "����"
]),
([      "action" : "$N˫���뻮������˫�����ƣ�һ�С�������ơ���һ����ɽ������������ֱ��$n����",
        "force" : 340,
        "dodge" : 10,
        "parry" : 3,
        "damage": 270,
        "lvl" : 65,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�������ת��һ�С�����Ʈ�졹����Ӱ���裬��ʱ֮�佫$n����˷�����ס��",
        "force" : 400,
        "dodge" : 5,
        "parry" : 0,
	"damage": 270,
        "lvl" : 85,
        "skill_name" : "����Ʈ��",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ�����Ƴ�ᶡ���˫�Ƽ�����һ�ŵ����İ�����������$n��$l",
	"force" : 180,
        "dodge" : 5,
        "parry" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "���Ƴ��",
        "damage_type" : "����"
]),
([	"action" : "$N��ָ�罣��һʽ���׺���ա�������$n��$l��ȥ",
	"force" : 220,
        "dodge" : 10,
        "parry" : 115,
	"damage": 120,
	"lvl" : 10,
	"skill_name" : "�׺����",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ���ƶ����롹������΢��������է��է�ϣ��͵ز���$n��$l",
	"force" : 260,
        "dodge" : 15,
        "parry" : 20,
	"damage": 130,
	"lvl" : 20,
	"skill_name" : "�ƶ�����",
        "damage_type" : "����"
]),
([	"action" : "$N˫����������������һʽ�����ɴ�䡹���ó�������̵����룬������$n��ȥ",
	"force" : 300,
        "dodge" : 20,
        "parry" : 30,
	"damage": 140,
	"lvl" : 30,
	"skill_name" : "���ɴ��",
        "damage_type" : "����"
]),
([	"action" : "$N��������һ�ݣ�ʹ��һʽ������������˫�Ʋ�£����ֱ����$n��$l��ȥ",
	"force" : 340,
        "dodge" : 25,
        "parry" : 20,
	"damage": 150,
	"lvl" : 40,
	"skill_name" : "������",
        "damage_type" : "����"
]),
([	"action" : "$N����һ�䣬ʹһʽ���ޱ���ľ����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
	"force" : 380,
        "dodge" : 25,
        "parry" : 25,
	"damage": 160,
	"lvl" : 50,
	"skill_name" : "�ޱ���ľ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ����ɽ��ˮ�����������أ�������ӯ��ͬʱ��$n��$l��ȥ",
	"force" : 420,
        "dodge" : 30,
        "parry" : 30,
	"damage": 170,
	"lvl" : 60,
	"skill_name" : "��ɽ��ˮ",
        "damage_type" : "����"
]),
([	"action" : "$Nͻ��һ�С��������á���˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
	"force" : 460,
        "dodge" : 30,
        "parry" : 35,
	"damage": 180,
	"lvl" : 70,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��������ơ���˫�������һ����裬�����ѻ���$n��$l��",
	"force" : 500,
        "dodge" : 40,
        "parry" : 45,
	"damage": 190,
	"lvl" : 80,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ������Ʈ�졹����������������˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����",
	"force" : 540,
        "dodge" : 45,
        "parry" : 50,
	"damage": 210,
	"lvl" : 90,
	"skill_name" : "����Ʈ��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }

int valid_combine(string combo) { return combo=="poyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ԫ�Ʊ�����֡�\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ��Ԫ�ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����Ԫ�ơ�\n");
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
        int i,level,f_force;
        f_force=me->query_skill("force");
         if ( random(me->query_skill("hunyuan-zhang",1))> 200 
          && me->query_skill("parry",1) > 200
          && random(10) >5
          ) {
          	
                return ([
                "action": WHT "$N���һ�����������������������ƣ������Ʒ����,����ǧ�Ѹֵ���$nϮȥ��"NOR,
                "force": 600,
                "dodge": 10,
                "parry": 10,
                "damage": 600,
                "damage_type": "����"]);
        }
        if (random(me->query_skill("hunyuan-zhang",1))> 150 
          && me->query_skill("parry",1) > 150
&& random(10) >5
          ) {
                return ([
                "action": WHT "$N˫�ƻû�һƬ��Ӱ����$n�������ڣ�$n��ǰһ������ʱ��֪���롣"NOR,
                "force": 660,
                "dodge": 15,
                "parry": 5,
                "damage": 660,
                "damage_type": "����"]);
        }
        if (random(me->query_skill("hunyuan-zhang",1))> 100 
          && me->query_skill("parry",1) > 100
&& random(10) >5
          ) {
                return ([
                "action": WHT "$N��ɫ���أ�˫����ƮƮ������$n��һ����ɽ�������ھ�����Ϣ����$n�ؿ�ײȥ��"NOR,
                "force": 620,
                "dodge": 5,
                "parry": 10,
                "damage": 660,
                "damage_type": "����"]);
        }
        
       
        level   = (int) me->query_skill("hunyuan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];

}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("���������������Ԫ�ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"hunyuan-zhang/" + action;
}