// ��������ȭ   
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": HIW"$N����ͻȻ������$n��$l�������ƣ���кˮ����ʽ��Ȼ���������ɣ�\n"
"����ȴ����������"HIC"���Դ����Ʒ����䣬����΢�ʶ�筴�����"NOR,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
        "damage_type": "����"
]),
([      "action": HIC"$N����ͻȻ�Ķ�����������ǧ�������ߣ��������дܶ�����Ȼ�����������\n"
"�ݲ����֣�Ҳ���˵У�$N����������������"HIM"��������ͨ���Է���ջ�ҡ���ƽ��ۡ���"NOR,
        "dodge": 15,
        "parry": 20,
        "force": 18,
        "damage": 160,
        "damage_type": "����"
]),
([      "action": HIM"$N�����´�����ָ�������$n��$l������ͻת���������Լձ߷����ֻ���$n��$l��\n"
"���������������������"HIB"�������ҷ������壬���˶�����ȥ�ߡ���"NOR,
	"dodge": 10,
	"parry": 15,
	"force": 12,
        "damage": 160,
	"damage_type": "����"
]),
([      "action": HIB"$N����һб��˫�����գ���ʽһ�䣬���д��أ�$N����������\n"
HIY"��������������ϣ�����б������⡣��"NOR,
        "dodge": 15,
	"parry": 11,
	"force": 16,
        "damage": 160,
	"damage_type": "����"
]),
([      "action": HIY"$N�����ѻط����Σ�����ͻ��б�Ӷ�������$n��$l������\n"
HIG"������ס����ʶ������������δ�ء���"NOR,
	"dodge": 21,
	"parry": 21,
	"force": 20,
        "damage": 160,
	"damage_type": "����"
]),
([      "action": HIG"$N΢΢һЦ������ͻȻ����һƬ��Ӱ����ס��ȫ����ʮ������Ѩ���������\n"
HIW"����ǰ��ɫӦ��ϧ��¥�ϻ�֦Ц���ߡ���������Ӱ��һָ����$n��$l��"NOR,
	"dodge": 15,
	"parry": 12,
	"force": 25,
	"damage_type": "����"
]),

([      "action" : "$nץס$N�ĺ󾱣�һ������"+(order[random(13)])+"������ٶ���"NOR"�� $N���ַ�ת����$n��Ҹ��ɦ��һ�ѣ�\n"
                   "$n��������������$N������ס$nҸ�£�����������ת��ץס$n��ڣ�����\n"
                   "����$n�����ӣ������Լ�ͷ��������ˤ��"NOR,
        "force" : 50,
        "dodge" : 5,
        "parry" : 10,
        "damage": 160,
        "lvl" : 0,
        "skill_name" : "����ٶ�",
        "damage_type" : "����"
]),
([      "action" : "$N�������ϣ�$n����̤ס$N�ĺ�����"+(order[random(13)])+"��³�������"NOR"��$N˫��һ��,�������,\n"
                   "�ұ�ȴ�������Ӷ�����ͻȻ��һ�������$n�Ŀ�����ȥ��ֻһ����\n"
                   "������ץס$n�ҽ����ף�������$n�"+(order[random(13)])+"�����ȥ",
        "force" : 60,
        "dodge" : 20,
        "parry" : 20,
        "damage": 190,
        "lvl" : 10,
        "skill_name" : "³�����",
        "damage_type" : "����"
]),
([      "action" : "$N˫�۷��ڱ���ͻȻ˫��ʮָ���𣬸��ɰ���֮�Σ��������һײ\n"
                   "ʮָ��ץ��$n���ز���$n���һ����$NͻȻһ�������������Ծ��\n"
                   "˫��һ�֣�����$n��ͷ��"+(order[random(13)])+"�����ཱུ����"NOR"��ͬʱ˫�ְ�ָѹס$n̫��Ѩ,ʳָ��ü,��ָ����",
        "force" : 100,
        "dodge" : 30,
        "parry" : 30,
        "damage": 210,
        "lvl" : 20,
        "skill_name" : "���ཱུ��",
        "damage_type" : "����"
]),
([      "action" : "$N����΢����������Ť,���㷴��,"+(order[random(13)])+"������������"NOR",��$nС����ȥ,$n�������,\n"
                   "$N˳�Ʒ�������������§ס$nͷ���������ս���׼$n���ģ�һ����ȥ",
        "force" : 70,
        "dodge" : 5,
        "parry" : 10,
        "damage": 200,
        "lvl" : 0,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N�����Ե�,$n�������̤ס$N�ĺ�����"+(order[random(13)])+"��С����¡�"NOR",$N���Դ��������Լ����ؿ�����,\n"
                   "˳���ڵ���һ�������$n�Ŀ�������������ս�����$n�ĺ���",
        "force" : 80,
        "dodge" : 20,
        "parry" : 20,
        "damage": 220,
        "lvl" : 10,
        "skill_name" : "С�����",
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ����,˳��һ����"+(order[random(13)])+"��������衹"NOR",���ϵĽ�����$n���ʺ��ȥ",
        "force" : 120,
        "dodge" : 30,
        "parry" : 30,
        "damage": 260,
        "lvl" : 20,
        "skill_name" : "�������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="xuanming-zhang" || combo == "dulong-shenzhua"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����������ȭ������֡�\n");
	if ((int)me->query("max_neili") < 1200)
		return notify_fail("�������̫���ˣ��޷���ϰ��������ȭ��\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 180)
		return notify_fail("��������ķ���򲻹����޷�ѧ��������ȭ.\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 180)
		return notify_fail("��������ȷ���򲻹����޷�ѧ��������ȭ.\n");

	if ((int)me->query_skill("dulong-shenzhua", 1) < 180)
		return notify_fail("��Ķ�����צ����򲻹����޷���������ȭ.\n");

	if ((int)me->query_skill("huagu-mianzhang", 1) < 180)
		return notify_fail("��Ļ������ƻ�򲻹����޷�ѧ��������ȭ.\n");

	if ((int)me->query_skill("shedao-qigong", 1) < 180)
		return notify_fail("����ߵ��湦��򲻹����޷�ѧ��������ȭ.\n");

	if ((int)me->query_skill("shenlong-bashi", 1) < 180)
		return notify_fail("���������ʽ��򲻹����޷�ѧ��������ȭ.\n");

	if ((int)me->query_skill("xuanming-zhang", 1) < 180)
		return notify_fail("�����ڤ���ƻ�򲻹����޷�ѧ��������ȭ.\n");

	if ((int)me->query_skill("yixingbu", 1) < 180)
		return notify_fail("������β�����򲻹����޷�ѧ��������ȭ.\n");

	if ((int)me->query_skill("qingshe-sword", 1) < 80)
		return notify_fail("������߽�����򲻹����޷�ѧ��������ȭ.\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return
notify_fail("��������ȭֻ����ѧ�ġ�\n");
}

int effective_level() { return 20;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return -30;
}
int black_white_ness()
{
        return 30;
}

mixed hit_ob(object me, object victim, int damage_bonus)
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

        if (random(7)==0  && me->query("neili") >= 100)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
                victim->apply_condition("xuanming_poison",20);
                victim->start_busy(3);
                me->add("neili", -20);
                return HIW "$n" HIW "��Ȼ�е�һ��Ī���Ķ��ģ��������������ģ�ȫ��̱����Ƥ���ϡ�\n" NOR;
        }
        if( damage_bonus < 50 ) return 0;

        if( random(damage_bonus/10) > victim->query_str() || random(10)==0) {
                victim->receive_wound("qi", (damage_bonus - 60) / 2+20 );
                switch(random(3)) {
                        case 0: return HIR"������"+(order[random(13)])+"��������"HIR"��һ�����죬�����ǹ����������\n"NOR;
                        case 1: return RED"$N����һ�£�$n��$l����"+(order[random(13)])+"������"RED"����һ�����죡\n"NOR;
                        case 2: return HIY"ֻ����$n��$l"+(order[random(13)])+"������"HIY"����һ�� ...\n"NOR;
                }
        }
}

string perform_action_file(string action)
{
        return __DIR__"diwangquan/" + action;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("diwangquan", 1)  % 10 == 0 ) {
                tell_object(me,
                        HIW "\n��ͻȻ����һ������������ͷ��ֻ����������̫��Ĳ�ƽ��....\n\n"
 NOR);
                me->add("score", 1);
        } else
                me->add("score", 1);
}

string *parry_msg = ({
	"$n����һ����������ճ��$N��$w��һ����\n",
        "$n����΢΢һ�࣬�Ѷ㿪$N�Ĺ��ơ�\n",
        "$n����һ����˫��һ�ŵأ�ȫ����$N�Ĺ�����Χ��\n",
});

string *unarmed_parry_msg = ({
        "$n����΢΢һ�࣬�Ѷ㿪$N�Ĺ��ơ�\n",
	"$n˫ȭ���䣬��סȫ��Ҫ����\n",
        "$n˫�ּ�ץ$N������$N���еı����������ֶ�����\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

