//yinlong-whip.c �������澭�����������񹦡�������������
//Edit By Vin On 13/2/2001

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N����������һʽ�����Գ��֡���������̧��$w�������裬���������Ҳ�ɨ��$n",
        "force" : 98,
        "attack": 41,
        "dodge" : 5,
        "parry" : 15,
        "damage": 232,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$Nһʽ���������֡���$w���ñ�ֱ�������ڡ��ƿ�������$n���̶�ȥ",
        "force" : 187,
        "attack": 48,
        "dodge" : 20,
        "parry" : 36,
        "damage": 247,
        "lvl"   : 80,
        "damage_type": "����"
]),
([      "action": "$N�ھ���������$w����ת������ԲȦ��һʽ���������֡����Ӱ������$n����",
        "force" : 231,
        "attack": 65,
        "dodge" : 10,
        "parry" : 55,
        "damage": 393,
        "lvl"   : 100,
        "damage_type": "����"
]),
([      "action": "$N����������һʽ�������ѵ��ơ���$w��$n��ǰ����������ʽ����Ȼ��$l����������",
        "force" : 263,
        "attack": 70,
        "dodge" : 5,
        "parry" : 60,
        "damage": 302,
        "lvl"   : 120,
        "damage_type": "����"
]),
([      "action": "$Nһ���ߺȣ�ʹ�����������ơ���$w����ת������Ӱ�ݺᣬ�����ƻã�����$n",
        "force" : 301,
        "attack": 77,
        "dodge" : 6,
        "parry" : 65,
        "damage": 321,
        "lvl"   : 140,
        "damage_type": "����"
]),
([      "action": "$N���ذα���һʽ�������ֻ��ơ��������鶯���ͣ�����������˷���$n��ѹ��ȥ",
        "force" : 331,
        "attack": 85,
        "dodge" : 12,
        "parry" : 70,
        "damage": 342,
        "lvl"   : 160,
        "damage_type": "����"
]),
([      "action":"$N������ң�һ�С������ơ�������$w��������Ӱ����ɽ������ɨ��$n",
        "force" : 373,
        "attack": 91,
        "dodge" : 17,
        "parry" : 75,
        "damage": 163,
        "lvl"   : 180,
        "damage_type": "����"
]),
([      "action":"$N������ң�һ�С�����ʮ�������ơ�������$w��������Ӱ����ɽ������ɨ��$n",
        "force" : 401,
        "attack": 98,
        "dodge" : 20,
        "parry" : 85,
        "damage": 389,
        "lvl"   : 200,
        "damage_type": "����"
]),
});

string main_skill() { return "jiuyin-shengong"; }

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
        object weapon;


        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("���������һ�����Ӳ��������������ޡ�\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("����������㣬û�а취�����������ޡ�\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ڹ����̫ǳ��û�а취�����������ޡ�\n");

        if ((int)me->query_skill("bagua-dao", 1) < 100)
                return notify_fail("���������Ե����̫ǳ��\n");
                
        if ((int)me->query_skill("bagua-zhang", 1) < 100)
                return notify_fail("�����������ƻ��̫ǳ��\n");                


        if ((int)me->query_skill("whip", 1) < 100)
                return notify_fail("��Ļ����޷����̫ǳ��û�а취�����������ޡ�\n");

        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("yinlong-whip", 1))
                return notify_fail("��Ļ����޷�ˮƽ���������޷���������Ķ��������ޡ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("yinlong-whip",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;


        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 350)
                return notify_fail("�������������\n");

        me->receive_damage("qi", 80);
        me->add("neili", -300);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yinlong-whip/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("yinlong-whip", 1);

        if (damage_bonus < 180 || lvl < 160) return 0;

        if (damage_bonus / 6 > victim->query_con() || random(5)==0)
        {
                victim->receive_wound("qi", (damage_bonus - 140) / 3, me);
                	return RED "$n" HIR "�۹�һ������ǰ����һ��"
                               "����ı޺ۡ�\n" NOR;
        }
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