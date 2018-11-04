#include <ansi.h>
inherit SKILL;

mapping *action=({
([	"action" : "$N���ͣ��Ҽ�ߣ�����б����������һʽ�����б��¡���˫�Ƽ�����$n�ļ�ͷ",
        "force" : 60,
        "attack": 5,
        "dodge" : 40,
        "parry" : 5,
        "damage": 112,
        "lvl"   : 0,
	"skill_name" : "���б���",
	"damage_type" : "����"
]),
([	"action" : "$N�����ֽ���ʹ�С��ͻ���׮������������$n��$l���������Ʊ�ȭ��ֱ����ǰ��",
        "force" : 80,
        "attack": 11,
        "dodge" : 43,
        "parry" : 6,
        "damage": 117,
        "lvl"   : 20,
	"skill_name" : "�ͻ���׮",
	"damage_type" : "����"
]),
([	"action" : "$N����Ȼһ�䣬ʹ��һʽ���������á�����Ӱǧ����ã���$n�޷�����",
        "force" : 100,
        "attack": 8,
        "dodge" : 45,
        "parry" : 8,
        "damage": 116,
        "lvl"   : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N��������һ�������ơ��ο�̽צ��б������׼$n��$l�ĳ�һ����Ӱ���������ŷ���",
        "force" : 120,
        "attack": 15,
        "dodge" : 47,
        "parry" : 11,
        "damage": 111,
        "lvl"   : 60,
	"skill_name" : "�ο�̽צ",
	"damage_type" : "����"
]),
([	"action" : "$N���ƻ��˸�ȦȦ���������仯�������Ƴ���һ�С�����ץצ��ֱȡ$n��$l",
        "force" : 140,
        "attack": 24,
        "dodge" : 49,
        "parry" : 13,
        "damage": 115,
        "lvl"   : 90,
	"skill_name" : "����ץצ",
	"damage_type" : "����"
]),
([	"action" : "$N����ͻȻ�ſ�������Ϊצ��ֱ����Ϊ��ɨ��һ�С��ݼ����١�����$n��$l�к���ȥ",
        "force" : 160,
        "attack": 28,
        "dodge" : 54,
        "parry" : 18,
        "damage": 118,
        "lvl"   : 120,
	"skill_name" : "�ݼ�����",
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��������׹�ء���������շ��𣬴ӿ��е�ͷ��$n��$l���ƹ���",
        "force" : 190,
        "attack": 31,
        "dodge" : 53,
        "parry" : 23,
        "damage": 115,
        "lvl"   : 150,
	"skill_name" : "����׹��",
	"damage_type" : "����"
]),
([	"action" : "$Nǰ���߳������Ƚż��أ�һʽ��˫�����š�������ֱ����˫˫����$n����������·",
        "force" : 210,
        "attack": 33,
        "dodge" : 55,
        "parry" : 25,
        "damage": 113,
        "lvl"   : 180,
	"skill_name" : "˫������",
	"damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return usage == "strike" || usage == "parry" || usage == "unarmed";
}

int valid_combine(string combo)
{
	return combo == "bagua-quan";
}

string main_skill() { return "baihua-cuoquan"; }

int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");

        if (me->query("max_neili") < 150)
                return notify_fail("��������������޷���ϰ�����ơ�\n");

        if ((int)me->query_skill("linji-zhuang", 1) < 60)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("bagua-zhang", 1))
                return notify_fail("��Ļ����Ʒ�������ޣ��޷���������İ����ơ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("bagua-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 100 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if( (int)me->query("neili") < 80 )
                return notify_fail("������������ˡ�\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 60)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");

        me->receive_damage("qi", 80);
        me->add("neili", -50);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bagua-zhang/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
		//ob->add("qi", 10000);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N �������죬�������¶�ׯ����������������Ǳ����
������������ض�����̩��������϶��Ҿ����������֮���ʱ����!��\n"NOR;
msg += "$N��ɫһ��,�ָ���Щ������\n",  
           message_vision(msg, me, ob);
           return j;
} 
}