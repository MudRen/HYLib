//Cracked by Kafei
// liuhe-dao.c  ������ϵ���
// qfy September 10, 1996

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N���һ��������$w�󿪴��أ������ӵ�ʹ�����Ǳ����졹��ն��$n��$l",
        "force" : 120,
        "dodge" : 2,
        "parry" : 2,
        "damage": 255,
        "lvl" : 0,
        "skill_name" : "�Ǳ�����",
        "damage_type":  "����"
]),
([      "action":"$N�˵���磬һ�С����Ǻ�ɽ�������ưԵ�֮��������$n��������Ϳ�����",
        "force" : 200,
        "dodge" : 0,
        "parry" : 5,
        "damage": 200,
        "lvl" : 10,
        "skill_name" : "���Ǻ�ɽ",
        "damage_type":  "����"
]),
([      "action":"$Nһ�š����է�ϡ���ͻȻ����$n���࣬Ѹ�͵�������ն����ʽ��Ȼ�ϳ�һ��ԲȦ",
        "force" : 230,
        "dodge" : 0,
        "parry" : 5,
        "damage": 240,
        "lvl" : 25,
        "skill_name" : "���է��",
        "damage_type":  "����"
]),
([      "action":"$N���챯Ц���漴�ӵ�ն��һʽ������޳�����$w��Ϊһ˿˿���⣬����$n$l",
        "force" : 280,
        "dodge" : 5,
        "parry" : 10,
        "damage": 250,
        "lvl" : 35,
        "skill_name" : "����޳�",
        "damage_type":  "����"
]),
([      "action":"$Nʩչ���ͺ�����������$n������$w���ſ�Ұ���磬�����ޱȵ���������",
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
	"damage": 300,
        "lvl" : 45,
        "skill_name" : "�ͺ�����",
        "damage_type":  "����"
]),
([      "action":"$N��ɫׯ�أ��ӵ�ʹ�����������ҡ���$w���϶�����$n����������һ�������׺䶥",
        "force" : 360,
        "dodge" : 0,
        "parry" : 5,
        "damage": 300,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
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
        int i, level, num=0;
	object ob;
//        object weapon;
        level = (int)me->query_skill("liuhe-dao",1);
	ob = me->select_opponent();
if (!ob) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
if (!me) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


	if ( me->query_temp("lianhuan") 
&& me->query_skill_mapped("blade") == "liuhe-dao"
&& objectp(weapon = me->query_temp("weapon"))
&&living(ob)
//&& me!=ob
&& !me->query_temp("dsauto"))
{
	   num = 1+random(2);
if ( (string)weapon->query("skill_type") == "blade"
&& !me->query_temp("dsauto")
&& !me->is_busy()
)
{
//if (random(2)==0) ob->start_busy(3);
ob->start_busy(2);
if (num<1) num=1;
if (num>3) num=3;
  	   for (i=1; i<num; i++) {
						if(!ob)
						{
						break;
						}
//						if(me=ob)
//						{
//						break;
//						}

						if(!me)
						{
						break;
						}

						if(!living(ob))
						{
						break;
						}
	   message_vision(YEL"\n$N����������������"+chinese_number(num+1)+"����\n"NOR, me);
						if(ob && me)
						{
me->set_temp("dsauto",1);

		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
me->delete_temp("dsauto");
}
}
//}
	   }
        }
	
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_skill("liuhe-dao",1) < 199)
           return notify_fail("�����ֻ�ܴ��ڶ��ټ�ʱ��ѧϰ��\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
        
}

string perform_action_file(string action)
{
        return __DIR__"liuhe-dao/" + action;
}