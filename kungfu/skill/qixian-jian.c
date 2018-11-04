#include <ansi.h>
#include <skill.h>

inherit SKILL;

string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 

mapping *action_unarmed = ({
([      "action": "$Nʹһ�С�������������˫����Ȼ�����������б�������ء���һ����һ���������һ�����$n��$l",
        "force" : 350,
        "attack": 80,
        "dodge" : 75,
        "parry" : 55,
        "damage": 270,
        "lvl" : 0,
        "weapon" : HIW "���ν���" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nʹ��һ�С���������������ָ����һ�̣�����������ֱ����������ʱ���ɽ����������㿳��$n",
        "force" : 370,
        "attack": 81,
        "dodge" : 65,
        "parry" : 65,
        "damage": 272,
        "lvl" : 40,
        "weapon" : HIW "���ν���" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$Nһ�����ȣ���Ȼһ�С������������������$n���һ������ʱһ�ɾ����������ƿ�֮��Ϯ��$p$l",
        "force" : 410,
        "attack": 85,
        "dodge" : 55,
        "parry" : 55,
        "damage": 288,
        "lvl" : 80,
        "weapon" : HIW "���ν���" NOR,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action": "$N˫���ͷ��ĳ��������ݺᣬ����һʽ�����̾�ɲ����ɲʱ���쬡��ƿ�����Ȼ���죬����$n$l",
        "force" : 430,
        "attack": 79,
        "dodge" : 65,
        "parry" : 35,
        "damage": 183,
        "lvl" : 120,
        "weapon" : HIW "�������ν���" NOR,
        "skill_name" : "���̾�ɲ",
        "damage_type" : "����"
]),
([      "action": "$Nƾ��һָ��һ�С��������项ббϮ�������ƶ�Ȼ����������²�������â����$n��$l",
        "force" : 460,
        "attack": 75,
        "dodge" : 91,
        "parry" : 85,
        "damage": 278,
        "lvl" : 160,
        "weapon" : HIW "�������ν���" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$N˫������һ�֣�ʹһ�С��������ơ�����������Ū���������һ�����彣����ֱӿ$n$l��ȥ",
        "force" : 490,
        "attack": 105,
        "dodge" : 35,
        "parry" : 24,
        "damage": 298,
        "lvl" : 200,
        "weapon" : HIW "�������ν���" NOR,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$N��Ȼ���о������䣬һ�С��Ǻ�������ʹ������ʱ���ɴ����ޱȵĽ�����ָ�⼤�������ֱ��$n",
        "force" : 480,
        "attack": 95,
        "dodge" : 75,
        "parry" : 75,
        "damage": 293,
        "lvl" : 240,
        "weapon" : HIW "�������ν���" NOR,
        "skill_name" : "�Ǻ�����",
        "damage_type" : "����"
]),
});


mapping *action_sword = ({
([      "action": "$Nʹһ�С�����������������$w����һ�����������һ�����$n��$l",
        "force" : 140,
        "attack": 60,
        "dodge" : 15,
        "parry" : 25,
        "damage" : 250,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action": "$N��ָ��$w��һ����һ�С����������������������ʱ����һ����������Х��ն��$n��$l",
        "force" : 150,
        "attack": 80,
        "dodge" : 60,
        "parry" : 5,
        "damage" : 270,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action": "$Nһ�С����������������$w��â��ʱ�������ߣ��⻪���䣬ֱֱ����$n��$l",
        "force" : 200,
        "attack": 80,
        "dodge" : 0,
        "parry" : 10,
        "damage" : 290,
        "lvl" : 80,
        "damage_type" : "����",
]),
([      "action": "$N����$wһʽ�����̾�ɲ����׼$n��$lһ���̳�������ɲʱ�����ݺᣬ�Ʋ��ɵ�",
        "force" : 250,
        "attack": 80,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 292,
        "lvl" : 120,
        "damage_type" : "����",
]),
([      "action": "$N��$wƾ��һָ��һ�С��������项ֱֱ�̳������ⶸȻ����������²�������â����$n��$l",
        "force" : 225,
        "attack": 63,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 203,
        "lvl" : 160,
        "damage_type" : "����",
]),
([      "action": "$N����$w����һ�֣�ʹһ�С��������ơ��������ڽ������ᵯ������ʱһ�ɽ���ֱӿ$n$l��ȥ",
        "force" : 250,
        "attack": 80,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 220,
        "lvl" : 200,
        "damage_type" : "����",
]),
([      "action": "$N��Ȼ���о������䣬һ�С��Ǻ���������һ�ɴ����ޱȵĽ�����$w�ϼ��������ֱ��$n",
        "force" : 300,
        "attack": 100,
        "dodge" : -15,
        "parry" : -15,
        "damage" : 240,
        "lvl" : 240,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) 
{  
        return usage == "unarmed"
            || usage == "parry"
            || usage == "sword"
            ; 
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 270)
                return notify_fail("����ڹ���򲻹����޷������������ν���\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("�������̫�����޷������������ν���\n");

        if ((int)me->query_skill("unarmed", 1) < 180)
                return notify_fail("��Ļ���ȭ�Ż�򲻹����޷������������ν���\n");

        if ((int)me->query_skill("sword", 1) < 180)
                return notify_fail("��Ļ���������򲻹����޷������������ν���\n");
        if( (int)me->query_skill("xuantian-wuji", 1) < 160)
                return notify_fail("��������޼�������Ϊ����������ʹ������ˮ��! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 180 )
                return notify_fail("���Ѹ�׽����������ң��޷�ʹ������ˮ�䣡\n");
        if( (int)me->query_skill("liangyi-jian", 1) < 180 )
                return notify_fail("������ǽ����������ң��޷�ʹ������ˮ�䣡\n");

   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("��û���������޼���\n");


        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action_unarmed)-1; i >= 0; i--)
                if(level >= action_unarmed[i]["lvl"])
                        return action_unarmed[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("qixian-jian", 1);

        if ( ! weapon)
        {                
             for(i = sizeof(action_unarmed); i > 0; i--)
                     if(level >= action_unarmed[i-1]["lvl"])
                             return action_unarmed[NewRandom(i, 20, level/5)];
        }        
        else
             for(i = sizeof(action_sword); i > 0; i--)
                     if(level > action_sword[i-1]["lvl"])
                             return action_sword[NewRandom(i, 20, level/5)];        
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("��������������������ν���\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("��������������������ν���\n");
        if( (int)me->query_skill("xuantian-wuji", 1) < 160)
                return notify_fail("��������޼�������Ϊ����������ʹ������ˮ��! \n");
        if( (int)me->query_skill("xunlei-jian", 1) < 180 )
                return notify_fail("���Ѹ�׽����������ң��޷�ʹ������ˮ�䣡\n");
        if( (int)me->query_skill("liangyi-jian", 1) < 180 )
                return notify_fail("������ǽ����������ң��޷�ʹ������ˮ�䣡\n");

   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("��û���������޼���\n");
        me->receive_damage("qi", 60);
        me->add("neili", -100);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name, weapon;
        name = xue_name[random(sizeof(xue_name))];
    
        if (me->query_skill("qixian-jian", 1) < 180
           || me->query("max_neili") < 2500
           || me->query("neili") < 500
          )
                return 0;

        if (damage_bonus < 50)
                return 0;
    if(me->query_skill_mapped("force") != "xuantian-wuji" )
        return 0;
if (random(3)==0)
{

        if (!victim->is_busy())
        victim->start_busy(2);
        me->add("neili", -50);
        victim->receive_damage("qi", me->query_skill("qixian-jian", 1) / 3 + damage_bonus / 3);
        victim->receive_wound("qi", me->query_skill("qixian-jian", 1) / 5 + damage_bonus / 5);
                return HIW "ֻ��һ�󴾺��������$N" HIW "��������$n" HIY "��" + name + "��"
                       NOR + HIW "��ʱ��������������ȫ�������Ҵܲ�ֹ��\n" NOR;
}
}

string perform_action_file(string action)
{
      return __DIR__"qixian-jian/" + action;
}
