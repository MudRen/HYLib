// liangyi-jian.c (kunlun) �����������ǽ���
//update by cool 981104
#include <ansi.h>
inherit SKILL;

mapping *man = ({ // 12 ��
([	"action":"$Nһʽ��˳ˮ���ۡ���$N����$wָ���Լ����ؿڣ�����бб�����⣬��������$n��$l",
	"force" : 180,
   "dodge" : 5,
   "parry" : 5,
	"damage": 50,
	"lvl" : 10,
	"skill_name" : "˳ˮ����",
	"damage_type":"����"
]),
([	"action":"$N����΢�࣬���ֺ�ڣ�����$wһ�С���ɨǧ������ֱ��$n�������ȥ",
	"force" : 190,
		  "dodge" : 5,
		  "parry" : 10,
	"damage": 60,
	"lvl" : 20,
	"skill_name" : "��ɨǧ��",
	"damage_type":"����"
]),
([	"action":"$N�����ǰ��$w��Ȼ���䵯�������ⱬ����һ�С��ͱڶ��ơ����͵ش���$n���ؿ�",
	"force" : 200,
		  "dodge" : 10,
		  "parry" : 5,
	"damage": 70,
	"lvl" : 28,
	"skill_name" : "�ͱڶ���",
	"damage_type":"����"
]),
([	"action":"$N�������������ƽ�ƶ�������ָ���������ֽ����첻����һ�С�����ָ·��������$n",
	"force" : 210,
		  "dodge" : 10,
		  "parry" : 10,
	"damage": 80,
	"lvl" : 37,
	"skill_name" : "����ָ·",
	"damage_type":"����"
]),
([	"action":"$N���к��䣬ʹ��һ�С����ɻ�����ȫ��б�ƣ����߰���б����ż����Ю��һ�����ƣ����˼���׽��",
	"force" : 220,
		  "dodge" : 15,
		  "parry" : 20,
	"damage": 90,
	"lvl" : 45,
	"skill_name" : "���ɻ�",
	"damage_type":"����"
]),
([	"action":"$N����$w�������𣬷�����£�һ�С���Įƽɳ�������ߵ��ƣ�����$n��$l",
	"force" : 230,
		  "dodge" : 20,
		  "parry" : 20,
	"damage": 100,
	"lvl" : 53,
	"skill_name" : "��Įƽɳ",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�ľҶ��������$N����$w������бָ���죬���϶��£�����$n��$l",
	"force" : 240,
		  "dodge" : 25,
		  "parry" : 30,
	"damage": 105,
	"lvl" : 60,
	"skill_name" : "ľҶ����",
	"damage_type":"����"
]),
([	"action":"$N��ǰһ����$w΢΢�����������㣬һ�С����Ӳ��ߡ����ն���ʼ�����಻������$n",
	"force" : 250,
		  "dodge" : 20,
		  "parry" : 30,
	"damage": 110,
	"lvl" : 70,
	"skill_name" : "���Ӳ���",
	"damage_type":"����"
]),
([	"action":"$N���ֽ���һ�٣�������ʯ�⣬һ�С��������ơ����ý�����ס$n���б�����$wֱָ$n���ʺ�",
	"force" : 260,
		  "dodge" : 30,
		  "parry" : 30,
	"damage": 120,
	"lvl" : 78,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$N����ؽ�������б����һ�С����ɷ��١�������Ӱ����ֱк��������ס$n�Ϸ�",
	"force" : 270,
		  "dodge" : 25,
		  "parry" : 35,
	"damage": 130,
	"lvl" : 86,
	"skill_name" : "���ɷ���",
	"damage_type":"����"
]),
([	"action":"$Nһʽ��ѩӵ���š���$N���н������ţ�һ����������������$n",
	"force" : 280,
		  "dodge" : 20,
		  "parry" : 35,
	"damage": 140,
	"lvl" : 100,
	"skill_name" : "ѩӵ����",
	"damage_type":"����"
]),
([	"action":"$N�ڿն���ͻȻʹ��һ�С�������ɫ����������Ϣ�ؼ���$n�ı�����ȥ",
	"force" : 300,
    "dodge" : 40,
    "parry" : 25,
	"damage": 155,
	"lvl" : 130,
	"skill_name" : "������ɫ",
	"damage_type":"����"
]),
});
mapping *woman = ({ // 12 ��
([	"action":"$Nһʽ��˳ˮ���ۡ���$N����$w���ؿڻ������������ڣ���������$n��$l",
	"force" : 180,
   "dodge" : 15,
   "parry" : 5,
	"damage": 40,
	"lvl" : 10,
	"skill_name" : "˳ˮ����",
	"damage_type":"����"
]),
([	"action":"$N����ǰ�壬���ֺ�ڣ�����$wһ�С���ɨǧ������ֱ��$n���ؿڴ�ȥ",
	"force" : 190,
		  "dodge" : 5,
		  "parry" : 5,
	"damage": 50,
	"lvl" : 20,
	"skill_name" : "��ɨǧ��",
	"damage_type":"����"
]),
([	"action":"$N�����ǰ������ζ������ⱬ����һ�С��ͱڶ��ơ����͵ش���$n��ͷ��",
	"force" : 200,
		  "dodge" : 15,
		  "parry" : 10,
	"damage": 60,
	"lvl" : 28,
	"skill_name" : "�ͱڶ���",
	"damage_type":"����"
]),
([	"action":"$N�������������ƽ�ƶ��������ֽ�ǰָ������һ�С�����ָ·��������$n",
	"force" : 210,
		  "dodge" : 15,
		  "parry" : 5,
	"damage": 70,
	"lvl" : 37,
	"skill_name" : "����ָ·",
	"damage_type":"����"
]),
([	"action":"$N���к��䣬ʹ��һ�С����ɻ�����ȫ��б�ƣ����߰���б����ż����Ю��һ�����ƣ����˼���׽��",
	"force" : 220,
		  "dodge" : 20,
		  "parry" : 15,
	"damage": 80,
	"lvl" : 45,
	"skill_name" : "���ɻ�",
	"damage_type":"����"
]),
([	"action":"$N����$w����ƽ�̣�����������ң�һ�С���Įƽɳ��������$n",
	"force" : 230,
		  "dodge" : 25,
		  "parry" : 10,
	"damage": 90,
	"lvl" : 53,
	"skill_name" : "��Įƽɳ",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�ľҶ��������$N����$w������бָ��أ����¶��ϣ�����$n��$l",
	"force" : 240,
		  "dodge" : 30,
		  "parry" : 20,
	"damage": 95,
	"lvl" : 60,
	"skill_name" : "ľҶ����",
	"damage_type":"����"
]),
([	"action":"$N�����˺�$w΢΢�����������㣬һ�С����Ӳ��ߡ����ն���ʼ�����಻������$n",
	"force" : 250,
		  "dodge" : 25,
		  "parry" : 25,
	"damage": 105,
	"lvl" : 70,
	"skill_name" : "���Ӳ���",
	"damage_type":"����"
]),
([	"action":"$N���ֽ���һ�٣�������ʯ�⣬һ�С��������ơ����ý��ʵ�ס$n���б�����$wֱָ$n���ʺ�",
	"force" : 260,
		  "dodge" : 30,
		  "parry" : 25,
	"damage": 110,
	"lvl" : 78,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$N����ǰ��������б����һ�С����ɷ��١�������Ӱ����ֱк��������ס$n�Ϸ�",
	"force" : 270,
		  "dodge" : 15,
		  "parry" : 10,
	"damage": 120,
	"lvl" : 86,
	"skill_name" : "���ɷ���",
	"damage_type":"����"
]),
([	"action":"$Nһʽ��ѩӵ���š���$N���н������ţ�һ����������������$n",
	"force" : 280,
		  "dodge" : 25,
		  "parry" : 30,
	"damage": 135,
	"lvl" : 100,
	"skill_name" : "ѩӵ����",
	"damage_type":"����"
]),
([	"action":"$N�ڿն���ͻȻʹ��һ�С�������ɫ����������Ϣ�ؼ���$n�ı�����ȥ",
	"force" : 300,
    "dodge" : 35,
    "parry" : 30,
	"damage": 150,
	"lvl" : 130,
	"skill_name" : "������ɫ",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 800)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 100)
		return notify_fail("��������޼������̫ǳ��\n");
	if ((int)me->query_skill("xunlei-jian", 1) < 80)
		return notify_fail("���Ѹ��ʮ�������̫ǳ��\n");
	return 1;
}

string query_skill_name(int level,object me)
{
		  int i;level;
		level   = (int) me->query_skill("liangyi-jian",1);
               if (me->query("gender")!="Ů��") {
		  for(i = sizeof(man)-1; i >= 0; i--)
					 if(level < man[i]["lvl"])
							return man[i]["skill_name"];
                     } else {
 for(i = sizeof(woman)-1; i >= 0; i--)
					 if(level >= woman[i]["lvl"])
								return woman[i]["skill_name"];
                             }
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("liangyi-jian",1);
	if (me->query("gender")!="Ů��") {
	for(i = sizeof(man); i > 0; i--) {
		if(level > man[i-1]["lvl"]) 
/* {
		if(me->query_temp("shuangjian_hebi")){
                return ([
                "action":HIB+man[NewRandom(i, 20, level/5)]["action"]+NOR,
                "damage":man[NewRandom(i, 20, level/5)]["damage"]+level/3,
                "damage_type": man[NewRandom(i, 20, level/5)]["damage_type"],
		  "skill_name": man[NewRandom(i, 20, level/5)]["skill_name"],
                "dodge": man[NewRandom(i, 20, level/5)]["dodge"]*3/2,
	         "parry": man[NewRandom(i, 20, level/5)]["parry"],
                "force": man[NewRandom(i, 20, level/5)]["force"]+level/3,
                ]);
        } else {
*/
			return man[NewRandom(i,20,level/5)];
//}
//}
}
} else {
for(i = sizeof(woman); i > 0; i--) {
		if(level > woman[i-1]["lvl"]) 
/* {
		if(me->query_temp("shuangjian_hebi"))
	{
                return ([
                "action":MAG+woman[NewRandom(i, 20, level/5)]["action"]+NOR,
                "damage":woman[NewRandom(i, 20, level/5)]["damage"]+level/3,
                "damage_type": woman[NewRandom(i, 20, level/5)]["damage_type"],
		  "skill_name": woman[NewRandom(i, 20, level/5)]["skill_name"],
                "dodge": woman[NewRandom(i, 20, level/5)]["dodge"],
	         "parry": woman[NewRandom(i, 20, level/5)]["parry"]*3/2,
                "force": woman[NewRandom(i, 20, level/5)]["force"]+level/3,
                ]);
        } else {
*/
			return woman[NewRandom(i, 20, level/5)];

//}
//}
}
}
}


int practice_skill(object me)
{
	object weapon;
	int lvl = me->query_skill("liangyi-jian", 1);

	int i = sizeof(man);
	while (i--) if (lvl == man[i]["lvl"]) return 0;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("����������������ǽ�����\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liangyi-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
  int i;

  i=me->query_skill("liangyi-jian",1)/3;
 if(me->query_temp("ly_hebi")&& !me->query_temp("hebi_hit") 
&& me->query_skill_mapped("parry") == "liangyi-jian") {
 me->set_temp("hebi_hit", 1);
  me->add_temp("apply/attack", i);
  COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);  
  me->add_temp("apply/attack", -i);
   me->delete_temp("hebi_hit");
       }
}
