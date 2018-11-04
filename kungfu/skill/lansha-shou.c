// lansha-shou.c ��ɰ�� ҩ����
// Edit By Vin On 26/2/2001

#include <ansi.h>
inherit SKILL;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"yf_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"snake_poison",
"wugong_poison",
"zhizhu_poison",
"xiezi_poison",
"chanchu_poison",
});
mapping *action = ({
([      "action" : "$N��ǰһ����˫�ƶ�Ȼ����������˿˿�������$n��$l",
        "force" : 100,
        "attack": 25,
        "dodge" : 15,
        "parry" : 20,
        "damage": 110,
        "damage_type" : "����"
]),
([      "action" : "$N���ƻ��أ��������Ĵ��ż���֮������$n��$l",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 15,
        "damage": 120,
        "damage_type" : "����"
]),
([      "action" : "$N˫���ĳ��������磬��Ȼ����������Ϣ������$n��$l",
        "force" : 180,
        "attack": 50,
        "dodge" : 20,
        "parry" : 30,
        "damage": 130,
        "damage_type" : "����"
]),
([      "action" : "$N�ֽ�һ��������һԾ�����ƿ�����������$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 135,
        "damage_type" : "����"
]),
([      "action" : "$N��Цһ����˫��һ�����ƺ�Ȼ�������߻���$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 235,
        "damage_type" : "����"
]),
([      "action" : "$N���μ��Σ�һԾ����$n��ǰ�����ƴ��ų��캮������$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 135,
        "damage_type" : "����"
]),
([      "action" : "$N���쳤Х��˫���Ʒ���ǧ�Ų����ĺ���������$n��$l",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 135,
        "damage_type" : "����"
]),
([      "action" : "$N����Ȼһ�䣬��Ӱǧ����ã���$n�޷�����",
        "force" : 250,
        "attack": 45,
        "dodge" : 15,
        "parry" : 20,
        "damage": 125,
        "damage_type" : "����"
]),
([      "action" : "$N����һ����Х��˫��Я������ű���ֱֱ����$n",
        "force" : 330,
        "attack": 35,
        "dodge" : 25,
        "parry" : 20,
        "damage": 115,
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

int valid_combine(string combo) { return combo == "lansha-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ɰ�ֱ�����֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷���ϰ��ɰ�֡�\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷���ϰ��ɰ�֡�\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("lansha-shou", 1))
                return notify_fail("��Ļ����ַ�ˮƽ���ޣ��޷������������ɰ�֡�\n");
        if (me->query_skill("biyun-xinfa", 1) < 50 && me->query_skill("wudu-shengong", 1) < 50)
                return notify_fail("��ı����ڹ�ˮƽ���ޣ��޷���������Ķ�ɰ�ơ�\n");
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
        level   = (int) me->query_skill("lansha-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("���������������ɰ�֡�\n");

        me->receive_damage("qi", 40);
        me->add("neili", -60);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

	int level, jiali, time,level2;
	object weapon;

        int lvl;
        int flvl;
	int damage,damage2;
object target;

        level = (int) me->query_skill("lansha-shou",1);
        level2= (int) me->query_skill("lansha-shou",1);

	
if (random(6)==0 && level>=150 && (me->query_skill_mapped("force") == "wudu-shengong"  || me->query_skill_mapped("force") == "biyun-xinfa"))
{
            victim->receive_damage("qi",random(level)+10);
            victim->receive_wound("qi",15 + random(50));
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIB "$N" HIB "ͻȻ���ƣ�Ȼ��Ѹ�ٷ���! ���о�Ȼ�ж�ɰ�����Ʒ羡Ȼ��������ɫ�ģ�\n" HIB "$n" HIB "��Ȼ�е�һ��Ī���Ķ��ģ�ȫ��̱����Ƥ���ϡ�!\n"NOR;
}


}

string perform_action_file(string action)
{
        return __DIR__"lansha-shou/" + action;
}

int ob_hit(object ob, object me, int damage)
{

        int lvl;
        int flvl;
	int level, jiali, time,level2,damage2;
	       int neili, neili2;
  string msg,dodge_skill,*limbs;
	object weapon;
object target;
damage2= (int) ob->query("neili",1)/10;
if (damage2>= 2800) damage2 = 2800;
	level = (int) me->query_skill("lansha-shou",1);
if (random(7)==0 && level>=150 && (me->query_skill_mapped("force") == "wudu-shengong"  || me->query_skill_mapped("force") == "biyun-xinfa")	)

{
if (!ob->is_busy()) ob->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
msg = HIG"$Nʹ��������������$n��������Ѫ��ȫ����˺�����˺ܶ࣡!\n"NOR;
            message_vision(msg, me, ob);
}
return damage;
}
