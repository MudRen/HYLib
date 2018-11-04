// dusha-zhang.c ��ɰ�� ҩ����
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
([      "action": "$N˫�ֲ�ס�غ���������ֱ۹ؽڿ������죬����һ��������ž��һ�³�$n$l��ȥ",
        "force" : 80,
        "attack": 28,
        "dodge" : 10,
        "parry" : 5,
        "damage": 160,
        "lvl"   : 0,
        "damage_type": "����"
]),
([      "action": "$N���δ춯���������������ų�$n�������ƣ�һ�ƿ���һ�ƣ�һ������һ��",
        "force" : 130,
        "attack": 35,
        "dodge" : 10,
        "parry" : 10,
        "damage": 167,
        "lvl"   : 30,
        "damage_type": "����"
]),
([      "action": "$N���ر�צΪ�ƣ����Ӳ������ұ۶�����Ǳ��������һ�Ƴ�$n$l��ȥ",
        "force" : 170,
        "attack": 37,
        "dodge" : 20,
        "parry" : 25,
        "damage": 165,
        "lvl"   : 60,
        "damage_type": "����"
]),
([      "action": "$Nһ����Х������Ʈ�磬����������е�ֿ������$n����δ������������Ѹ���Ѽ�",
        "force" : 220,
        "attack": 42,
        "dodge" : 30,
        "parry" : 35,
        "damage": 273,
        "lvl"   : 90,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo) { return combo=="lansha-shou"; }

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("dusha-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level / 5)];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ɰ�Ʊ�����֡�\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�����ɰ�ơ�\n");

        if ((int)me->query("max_neili") < 450)
                return notify_fail("�������̫�����޷�����ɰ�ơ�\n");

        if (me->query_skill("strike", 1) < me->query_skill("dusha-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ķ�ɰ�ơ�\n");
        if (me->query_skill("biyun-xinfa", 1) < 50 && me->query_skill("wudu-shengong", 1) < 50)
                return notify_fail("��ı����ڹ�ˮƽ���ޣ��޷���������Ķ�ɰ�ơ�\n");
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˣ�����Ϣһ�°ɡ�\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("���������������ɰ�ơ�\n");

        if (me->query_skill("dusha-zhang", 1) < 50)
                me->receive_damage("qi", 30);
        else
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

        level = (int) me->query_skill("dusha-zhang",1);
        level2= (int) me->query_skill("dusha-zhang",1);

	
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
 return WHT "$N" WHT "ͻȻ���ƣ�Ȼ��Ѹ�ٷ���! ���о�Ȼ�ж�ɰ�����Ʒ羡Ȼ��������ɫ�ģ�\n" WHT "$n" WHT "��Ȼ�е�һ��Ī���Ķ��ģ�ȫ��̱����Ƥ���ϡ�!\n"NOR;
}


}

string perform_action_file(string action)
{
        return __DIR__"dusha-zhang/" + action;
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
if (damage2>= 3800) damage2 = 3800;
	level = (int) me->query_skill("dusha-zhang",1);
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
