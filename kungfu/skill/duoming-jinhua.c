// duoming-jinhua.c ������
// congw

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit SKILL;

mapping *action = ({
([	"action" : "$N�鲽������һ�С������á�������$w����$n��$l",
	"force" : 160,
	"dodge" : 20,
	"parry" : 10,
	"damage" : 345,
        "lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ����һ����������Σ�����$wʹ��һʽ�����컨�꡹ֱ��$n��$l",
	"force" : 170,
	"dodge" : 25,
	"parry" : 20,
	"damage" : 360,
        "lvl" : 10,
	"damage_type" : "����"
]),
([	"action" : "$N��������һ�죬������Ȼ����һ��$w��ʹ��һʽ�������ǡ�����$n��$l",
	"force" : 180,
	"dodge" : 30,
	"parry" : 30,
	"damage" : 370,
        "lvl" : 20,
	"damage_type" : "����"
]),
([	"action" : "$N˫ϥ�³�������$wʹ��һʽ���绨ѩ�¡������¶��ϼ���$n��$l",
	"force" : 190,
	"dodge" : 45,
	"parry" : 40,
	"damage" : 380,
        "lvl" : 30,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���Ʈ�����$w�Կ��л���һ���󻡣�ƽƽ����$n��$lֱ���ȥ",
	"force" : 200,
	"dodge" : 55,
	"parry" : 55,
	"damage" : 390,
        "lvl" : 40,
	"damage_type" : "����"
]),
([	"action" : "$N����һԾ��������ɣ�һ�С���Ůɢ����������$w������㺮��$n��$l�����ȥ",
	"force" : 310,
	"dodge" : 65,
	"parry" : 75,
	"damage" : 300,
        "lvl" : 50,
	"damage_type" : "����"
]),

([	"action" : "$N����ת������$wһ����һ�С��ϳ���������$n��$l",
	"force" : 230,
	"dodge" : 100,
	"parry" : 100,
	"damage" : 320,
        "lvl" : 80,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������𻨡���$w����������꣬�ֵػ���$n��ȫ��",
	"force" : 300,
	"dodge" : 200,
	"parry" : 200,
	"damage" : 350,
        "lvl" : 100,
	"damage_type" : "����"
]),

});


int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 50)
		return notify_fail("��ı����ڹ����̫ǳ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i,j, level;
      int p;      
      i = random(me->query_skill("throwing"))+50;
      if(i<120) i = 120;
      j = random((int)me->query_skill("duoming-jinhua",1))+40;
      if(j<120) j = 120;
      p = ((int)me->query_skill("force",1))/3 + me->query_con();
      if(p>100) p=100;
      if(j>200
      && random(10)>5){
        return ([
                "action":WHT"$NͻȻ����һ��,���Ծ������ȥ���ȼ������ڿ����������߳����ȣ��漴��������
�������ݰ����������������������ͻȻ��$N���Ϸ���������⣬�罵�����
��â���ɡ������������߿Х����$n������һƬ��ɫ����֮�С�\n"NOR,
                "damage":(i+j)/2+random((int)me->query_con())+600,
                "damage_type": "����",
                "dodge": random(100)+40,
                "force": random(320)+200+(i+j)/2+p,
//                "action":action[NewRandom(i, 20, level/5)]["action"],
                ]);
}

	level   = (int) me->query_skill("duoming-jinhua",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������𻨡�\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"duoming-jinhua/" + action;
}
