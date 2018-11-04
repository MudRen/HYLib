//dulong-shenzhua for xuanming gu
//create by rcwiz 2003


inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action": "$Nȫ��������죬һʽ����аצ����Ѹ�͵�ץ��$n��$l",
        "force" : 100,
        "attack": 20,
        "dodge" : 5,
        "parry" : 15,
        "damage": 110,
        "lvl" : 0,
        "skills_name" : "��аצ",
        "damage_type" : "����"
]),
([      "action": "$N����ֱ����˫��ƽ�죬һʽ������צ����˫צһǰһ��£��$n��$l",
        "force" : 120,
        "attack": 40,
        "dodge" : 10,
        "parry" : 22,
        "damage": 115,
        "lvl" : 30,
        "skills_name" : "����צ",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ������צ����ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
        "force" : 150,
        "attack": 50,
        "dodge" : 10,
        "parry" : 28,
        "damage": 120,
        "lvl" : 60,
        "skills_name" : "����צ",
        "damage_type" : "����"
]),
([      "action": "$N˫צ���ڶ�����ʹһʽ��˫��Ϸ�����ֱ�Ϯ��$n����Ҹ����",
        "force" : 180,
        "attack": 55,
        "dodge" : 15,
        "parry" : 35,
        "damage": 135,
        "lvl" : 80,
        "skills_name" : "˫��Ϸ",
        "damage_type" : "����"
]),
([      "action": "$N�������һʽ������צ����������£�ץ��$n���ؿ�",
        "force" : 220,
        "attack": 65,
        "dodge" : 20,
        "parry" : 38,
        "damage": 145,
        "lvl" : 100,
        "skills_name" : "����צ",
        "damage_type" : "����"
]),
([      "action": "$Nһʽ������צ��������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
        "force" : 250,
        "attack": 60,
        "dodge" : 25,
        "parry" : 45,
        "damage": 160,
        "lvl" : 120,
        "skills_name" : "����צ",
        "damage_type" : "����"
]),
([      "action": "$N��������צ�����һʽ�������ա���˫צ���ն�����ץ��$n",
        "force" : 290,
        "attack": 75,
        "dodge" : 25,
        "parry" : 52,
        "damage": 185,
        "lvl" : 140,
        "skills_name" : "������",
        "damage_type" : "����"
]),
([      "action": "$N�ڿն���һʽ��������צ��������ж�ʱ�Գ�һ������צӰ������$n",
        "force" : 320,
        "attack": 80,
        "dodge" : 40,
        "parry" : 60,
        "damage": 180,
        "lvl" : 160,
        "skills_name" : "������צ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage == "claw" || usage == "parry" || usage == "unarmed"; }

int valid_combine(string combo) { return combo=="xuanming-zhang" || combo == "diwangquan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��������צ��������֡�\n");

        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("����ڹ���򲻹����޷�ѧ������צ����\n");

        if ((int)me->query("max_neili") < 550)
                return notify_fail("���������Ϊ���㣬�޷�ѧ������צ����\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 85)
		return notify_fail("��������ķ���򲻹����޷�ѧ������צ��.\n");

	if ((int)me->query_skill("huagu-mianzhang", 1) < 125)
		return notify_fail("��Ļ������ƻ�򲻹����޷�ѧ������צ��.\n");


        if ((int)me->query_skill("claw", 1) < (int)me->query_skill("dulong-shenzhua", 1))
                return notify_fail("��Ļ���ץ�����ˮƽ���ޣ��޷���������Ķ�����צ����\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("dulong-shenzhua",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") ||
            me->query_temp("secondary_weapon"))
                return notify_fail("����������ϰ��\n");
	if ((int)me->query_skill("shenlong-xinfa", 1) < 85)
		return notify_fail("��������ķ���򲻹����޷�ѧ������צ��.\n");

	if ((int)me->query_skill("huagu-mianzhang", 1) < 125)
		return notify_fail("��Ļ������ƻ�򲻹����޷�ѧ������צ��.\n");
        if ((int)me->query("qi") < 80)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("���������������\n");

        me->receive_damage("qi", 60);
        me->add("neili", -67);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dulong-shenzhua/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("shenlong-xinfa",1);
        level2= (int) me->query_skill("shenlong-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "shenlong-xinfa")
{
	victim->apply_condition("snake_poison",15);
	victim->apply_condition("chanchu_poison",15);
	victim->apply_condition("ill_fashao",10);
	victim->apply_condition("ill_kesou",10);
	victim->apply_condition("ill_shanghan",10);
	victim->apply_condition("ill_zhongshu",10);
	victim->apply_condition("ill_dongshang",10);
 victim->apply_condition("xuanming_poison",10);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N������У�ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ�$nͷһ��,��Ѫ���!\n";
}
        lvl  = me->query_skill("xuanming-zhang", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "shenlong-xinfa" ||
            me->query("neili") < 300)
                return;
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
                victim->apply_condition("xuantian_han",20);
                me->add("neili", -20);
return HIW "$n" HIW "��Ȼ�е�һ��Ī���Ķ��ģ��������������ģ�ȫ��̱����Ƥ���ϡ�\n" NOR;
        }

}

