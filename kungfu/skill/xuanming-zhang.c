
// create by rcwiz 2003 for yanhuang online 

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : "$Nʹ��һ�С�ѩ��ãã����˫�ƶ�Ȼ����������˿˿�������$n��$l",
        "force" : 100,
        "attack": 25,
        "dodge" : 15,
        "parry" : 20,
        "damage": 110,
        "lvl"   : 0,
        "skill_name" : "ѩ��ãã",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��һ�С���ڤ��ɽ�������ƻ��أ��������Ĵ��ż���֮������$n��$l",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 15,
        "damage": 120,
        "lvl"   : 30,
        "skill_name" : "��ڤ��ɽ",
        "damage_type" : "����"
]),
([      "action" : "$N�ֽ�һ����һ�С�����ŭ�š���˫������ǵذ�����$n��$l",
        "force" : 160,
        "attack": 45,
        "dodge" : 20,
        "parry" : 20,
        "damage": 125,
        "lvl"   : 60,
        "skill_name" : "����ŭ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�ա�������硹��˫���ĳ��������磬��Ȼ����������Ϣ������$n��$l",
        "force" : 180,
        "attack": 50,
        "dodge" : 20,
        "parry" : 30,
        "damage": 130,
        "lvl"   : 80,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N����һԾ��һ�С�������ԭ�������ƿ�����������$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 135,
        "lvl"   : 100,
        "skill_name" : "������ԭ",
        "damage_type" : "����"
]),
([      "action" : "$N��Цһ����һ�С���ɽ��������˫��һ�����ƺ�Ȼ�������߻���$n��$l",
        "force" : 280,
        "attack": 95,
        "dodge" : 25,
        "parry" : 25,
        "damage": 155,
        "lvl"   : 120,
        "skill_name" : "��ɽ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�ѩԭ���¡������μ��Σ�һԾ����$n��ǰ�����ƴ��ų��캮������$n��$l",
        "force" : 320,
        "attack": 110,
        "dodge" : 30,
        "parry" : 30,
        "damage": 170,
        "lvl"   : 140,
        "skill_name" : "ѩԭ����",
        "damage_type" : "����"
]),
([      "action" : "$N���쳤Х��һ�С�������ڤ����˫���Ʒ���ǧ�Ų����ĺ���������$n��$l",
        "force" : 360,
        "attack": 135,
        "dodge" : 30,
        "parry" : 35,
        "damage": 195,
        "lvl"   : 150,
        "skill_name" : "������ڤ",
        "damage_type" : "����"
]),
([      "action" : "$N����Ȼһ�䣬ʹ��һʽ������ڤڤ������Ӱǧ����ã���$n�޷�����",
        "force" : 420,
        "attack": 150,
        "dodge" : 30,
        "parry" : 75,
        "damage": 140,
        "lvl"   : 160,
        "skill_name" : "����ڤڤ",
        "damage_type" : "����"
]),
([      "action" : "$N����һ����Х��һʽ�������������˫��Я������ű���ֱֱ����$n",
        "force" : 450,
        "attack": 185,
        "dodge" : 40,
        "parry" : 80,
        "damage": 260,
        "lvl"   : 180,
        "skill_name" : "�������",
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
        return usage=="strike" || usage=="parry" || usage == "unarmed";
}
int valid_combine(string combo) { return combo=="dulong-shenzhua" || combo == "diwangquan"; }
int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ڤ���Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹����޷���ϰ��ڤ���ơ�\n");

        if (me->query("con") < 28)
                return notify_fail("��������ǲ��㣬�޷�������ڤ���ơ�\n");
 
	if ((int)me->query_skill("shenlong-xinfa", 1) < 25)
		return notify_fail("��������ķ���򲻹����޷�ѧ��ڤ����.\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 100)
		return notify_fail("��������ȷ���򲻹����޷�ѧ��ڤ����.\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������̫�����޷���ϰ��ڤ���ơ�\n");

        if ((int)me->query_skill("strike", 1) < 100)
                return notify_fail("��Ļ����Ʒ���򲻹����޷�����ڤ���ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("xuanming-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷������������ڤ���ơ�\n");

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
        int i, level;
        level   = (int) me->query_skill("xuanming-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query("con") < 28)
                return notify_fail("��������ǲ��㣬�޷�������ڤ���ơ�\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 100)
		return notify_fail("��������ȷ���򲻹����޷�ѧ��ڤ����.\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("���������������ڤ���ơ�\n");

        me->receive_damage("qi", 80);
        me->add("neili", -80);
        return 1;
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
                victim->apply_condition("xuanming_poison",20);
                victim->start_busy(3);
                me->add("neili", -20);
                return HIW "$n" HIW "��Ȼ�е�һ��Ī���Ķ��ģ��������������ģ�ȫ��̱����Ƥ���ϡ�\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"xuanming-zhang/" + action;
}

