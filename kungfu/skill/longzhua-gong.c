// longzhua-gong.c ��צ��
// modified by Venus Oct.1997
inherit SKILL;
#include <combat.h>
#include <ansi.h>

mapping *action = ({
([      "action" : "$N˫����������϶���ͬץ��ʹһ�С�����ʽ����Ѹ��֮����ֱ����$n����̫��Ѩ",
        "force" : 120,
        "dodge" : 5,
    "damage": 225,
        "lvl"   : 0,
        "skill_name" : "����ʽ" ,
        "damage_type" : "����"
]),
([      "action" : "$N˫��һ��Ȧת��ʹ�С�����ʽ��������ٿ������������$n���ԡ��縮Ѩ��",
        "force" : 130,
        "dodge" : 5,
        "damage": 215,
        "lvl"   : 6,
        "skill_name" : "����ʽ" ,   
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ�С�����ʽ����������̽������Ю��һ�ɾ��磬ֱ����$n��硰ȱ��Ѩ��",
        "force" : 150,
        "dodge" : 10,
        "damage": 215,
        "lvl"   : 12,
        "skill_name" : "����ʽ" ,       
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С�����ʽ����������ָ��$n��$l��ץ���£��ַ�������Ѹ�汸���Ƶ�����֮��",
        "force" : 180,
        "dodge" : 10,
        "damage": 210,
        "lvl"   : 18,
        "skill_name" : "����ʽ" ,     
        "damage_type" : "ץ��"
]),
([      "action" : "$N�͵��������һ�С�׽Ӱʽ����$n�˽��������ý�Ѹ�ݣ����ƷǷ�",
        "force" : 220,
        "dodge" : 15,
        "damage": 210,
        "lvl"   : 24,
        "skill_name" : "׽Ӱʽ" ,               
        "damage_type" : "ץ��"
]),
([      "action" : "��������һ�죬$N�ұۼ����������ָ΢΢���²�����һ�С�����ʽ��ץ��$n��$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 215,
        "lvl"   : 30,
        "skill_name" : "����ʽ" ,               
        "damage_type" : "ץ��"
]),
([      "action" : "$N���������������ڻӣ���Ȼ��Ϊһ�С���ɪʽ��ץ��$n$l������������ٱ",
        "force" : 300,
        "dodge" : 25,
        "damage": 220,
        "lvl"   : 45,
        "skill_name" : "��ɪʽ" ,               
        "damage_type" : "ץ��"
]),
([      "action" : "$N˫�֡�����ʽ������������������Ӱ�ɿգ�˫צ���裬˲Ϣ֮�䣬�ѽ�$nѹ�Ƶ��޴�����",
        "force" : 350,
        "dodge" : 25,
        "damage": 225,
        "lvl"   : 50,
        "skill_name" : "����ʽ" ,               
        "damage_type" : "ץ��"
]),
([      "action" : "$N̤�ϼ���������һ�С�����ʽ����������$n$lץ����������һץ������ָ��ñ�ֱ�����������Ѽ�",
        "force" : 400,
        "dodge" : 30,
        "damage": 225,
        "lvl"   : 55,
        "skill_name" : "����ʽ" ,               
        "damage_type" : "ץ��"
]),
([      "action" : "$N����һ������������ʵ����������׾��������ʽ��������ɽ��ʹ������",
        "force" : 460,
        "dodge" : 40,
        "damage": 230,
        "lvl"   : 60,
        "skill_name" : "����ʽ" ,       
        "damage_type" : "ץ��"
]),
([      "action" : "$Nһ��ԭ�ȸ���·�ӣ���������ȱʽ����צ·�����а������ᣬʵ�ѵ��˷�豹��棬¯����ľ���",
        "force" : 520,
        "dodge" : 40,
        "damage": 250,
        "lvl"   : 70,
        "skill_name" : "��ȱʽ" ,
        "damage_type" : "����"
]),
([      "action" : "�ں��������У�$Nʹһ�С�����ʽ����˫���繳��ꫣ�����$n��$l",
    "force" : 100,
    "dodge" : 5,
        "damage": 225,
    "lvl"   : 0,
    "skill_name" : "����ʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N�͵���ǰԾ����һ�С�׽Ӱʽ���������߳���˫��ץ��$n������",
    "force" : 110,
    "dodge" : 5,
    "damage": 225,
    "lvl"   : 6,
    "skill_name" : "׽Ӱʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С�����ʽ������$n��$l",    
    "force" : 120,
    "dodge" : 10,
    "damage": 225,
    "lvl"   : 12,
    "skill_name" : "����ʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N���������������ڻӣ�һ�С�����ʽ������$n�ؿ�",
    "force" : 140,
    "dodge" : 10,
    "damage": 210,
    "lvl"   : 18,
    "skill_name" : "����ʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N�������գ�����������ɽ��һ�С�����ʽ�����͵ػ���$n��$l",  
    "force" : 160,
    "dodge" : 15,
    "damage": 210,
    "lvl"   : 24,
    "skill_name" : "����ʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N�ڲ���ǰ�����ֻ��أ�����̽����һ�С�����ʽ������$n���ɲ�",
    "force" : 190,
    "dodge" : 15,
    "damage": 215,
    "lvl"   : 30,
    "skill_name" : "����ʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ�С�����ʽ����������$n��$l",
    "force" : 220,
    "dodge" : 20,
    "damage": 215,
    "lvl"   : 35,
    "skill_name" : "����ʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N������ǰ������Ҹ�º��գ���ָ�繳��һ�С���ȱʽ������$n�Ķ�
��",
    "force" : 260,
    "dodge" : 20,
    "damage": 20,
    "lvl"   : 40,
    "skill_name" : "��ȱʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N����б��$n����֮�䣬һ�С�����ʽ��������ȡĿ�����ַ���$n��
�ɲ�",
    "force" : 300,
    "dodge" : 25,
    "damage": 220,
    "lvl"   : 45,
    "skill_name" : "����ʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$Nһ����ָ$n�Ľ�����һ�С��ὣʽ����һ������ץ��$n���еĳ���
",
    "force" : 350,
    "dodge" : 25,
    "damage": 225,
    "lvl"   : 50,
    "skill_name" : "�ὣʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С�����ʽ��ʹ
$n��������",
    "force" : 400,
    "dodge" : 30,
    "damage": 225,
    "lvl"   : 55,
    "skill_name" : "����ʽ" ,
    "damage_type" : "����"
]),
([      "action" : "$Nǰ���ŵأ�һ�ֶ����צ��һ��ָ�أ�һ�С�׷��ʽ����������$n
��ȫ��",
    "force" : 460,
    "dodge" : 40,
    "damage": 330,
    "lvl"   : 60,
    "skill_name" : "׷��ʽ" ,
    "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }     

int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("����צ��������֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ��צ����\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷�����צ����\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action); i > 0; i--)
   if(level >= action[i-1]["lvl"])
      return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
        string *msg;
        msg = ({
                HIR"\n$Nһץ���У���ץ���������Ƹ���Ѹ�ݸ��ͣ�" NOR,
                HIR"\n$N��צ��ԴԴ������һ����գ��ּ�����������" NOR,
                HIR"\n$n�Ŷ�����У�$N����������ץ���켫�ݼ���"NOR,
        });
    level   = (int) me->query_skill("longzhua-gong",1);
        if (random(level) > 250 && me->query_skill("force") > 200 && me->query("neili") >= 600)
         {
		return ([
		"action": HIR"$N��צ��ԴԴ������һ����գ��ּ�����������"NOR,
		"force" : 460+random(40),
		"dodge" : 20,
		"damage": 460+random(20),
		"damage_type" : "����" ]);
	}
else        if (random(level) > 200 && me->query_skill("force") > 200 && me->query("neili") >= 400)
         {
		return ([
		"action": HIC"$Nһץ���У���ץ���������Ƹ���Ѹ�ݸ��ͣ�"NOR,
		"force" : 400+random(40),
		"dodge" : 20,
		"damage": 400+random(20),
		"damage_type" : "����" ]);
	}
else        if (random(level) > 150 && me->query_skill("force") > 150 && me->query("neili") >= 200)
         {
		return ([
		"action": HIY"$n�Ŷ�����У�$N����������ץ���켫�ݼ���"NOR,
		"force" : 500+random(40),
		"dodge" : 20,
		"damage": 500+random(20),
		"damage_type" : "����" ]);
	}

    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("���������������צ����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"longzhua-gong/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
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
	victim->receive_wound("qi", damage);
}
	return HIR"ֻ��$n$l�ƺ�һ�����³�һ����Ѫ���ѱ��׽�Ļ�������������!\n"NOR;
}
}