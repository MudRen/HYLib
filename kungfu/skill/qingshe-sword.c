// fonxansword.c

#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
        ([      "action":               
"$Nʹһ��"+(order[random(13)])+"�����߿��衹"NOR"������$w���Ż������⣬����һ�����߰����$n��$l",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����߽����е�"+(order[random(13)])+"����Ӱ�����"NOR"������������ն��$n��$l",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ��"+(order[random(13)])+"��������Ӱ��"NOR"�����ζ�Ȼ��շɳ����ߣ����е�$wͽȻն��$n��$l",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ"+(order[random(13)])+"�����ߵ�����"NOR"��׼$n��$l�͵Ĵ̳�����",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ��"+(order[random(13)])+"��ѩ�ط��ߡ�"NOR"��׼$n��$lбб�̳�һ��",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ����Ȼ�任���£�һ��"+(order[random(13)])+"�����߻�����"NOR"����$n��$l",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "����"
        ]),
        ([      "action":               

"$N����$w����һ�֣�ʹһ��"+(order[random(13)])+"�������ǳǡ�"NOR"���ֶ�׼$n$lһ����ȥ",
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ��"+(order[random(13)])+"����Ӱ�ܲ���"NOR"����һ���⻡����$n��$l",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "����"
        ]),
([  "action":"$Nʹһʽ��"+BLK+"��������"+NOR+"��������$w���죬���캮�⣬���з���֮����������ӿ��$n��$l",
    "force" : 120,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : BLK "��������" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����ǰ��ʹ����"+RED+"����ɻ�"+NOR+"��������$w��ʱ��â���䣬����������ѩ������$n��$l",
    "force" : 140,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : RED "����ɻ�" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wһ����һ�С�"+GRN+"��Ӱ����"+NOR+"����$w������ɨ��Ҷ�㼱����$n��$l",
    "force" : 160,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : GRN "��Ӱ����" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$w���ॳ���һ����һʽ��"+BLU+"����Ѱʳ"+NOR+"����$wͷ�Ͻ����������£�����֮���������ױ���$n��$l",
    "force" : 180,
    "lvl" : 47,
    "skill_name" : BLU "����Ѱʳ" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+MAG+"���絹��"+NOR+"��������$w�����������ϣ��˵��ޱȶ���ʹ$n�Ѷ���ʵ���޿ɶ��",
    "force" : 220,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : MAG "���絹��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$w,һʽ��"+BLU+"���޵���"+NOR+"�����·�һ�����εĺ�����$n��$lбб����",
    "force" : 260,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : BLU "���޵���" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+HIR+"����ʧɫ"+NOR+"����$w����������罭�ӵ�к����â�����޾���$n���ؿڵ�ȥ",
    "force" : 380,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : HIR "����ʧɫ" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+YEL+"����ɽ�"+NOR+"����$w�����һ����ȫ��������ע����֮�ϣ��������է����$n��ȥ",
    "force" : 380,
        "dodge": 30,
        "parry": 10,
        "force": 40,
        "damage": 160,
    "skill_name" : HIY "����ɽ�" NOR,
    "damage_type":  "����"
])
});

int valid_learn(object me)
{
        object ob;


//        if( (string)me->query_skill_mapped("force")!= "wudu-force")
 //               return notify_fail("���߽�����������嶾�ķ���������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫���ˣ��޷���ϰ\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 80)
		return notify_fail("��������ķ���򲻹���\n");

	if ((int)me->query_skill("shenlong-tuifa", 1) < 80)
		return notify_fail("��������ȷ���򲻹���\n");

	if ((int)me->query_skill("dulong-shenzhua", 1) < 80)
		return notify_fail("��Ķ�����צ����򲻹���\n");

	if ((int)me->query_skill("huagu-mianzhang", 1) < 80)
		return notify_fail("��Ļ������ƻ�򲻹���\n");

	if ((int)me->query_skill("shedao-qigong", 1) < 80)
		return notify_fail("����ߵ��湦��򲻹���\n");

	if ((int)me->query_skill("shenlong-bashi", 1) < 80)
		return notify_fail("���������ʽ��򲻹���\n");

	if ((int)me->query_skill("xuanming-zhang", 1) < 80)
		return notify_fail("�����ڤ���ƻ�򲻹���\n");

	if ((int)me->query_skill("yixingbu", 1) < 80)
		return notify_fail("������β�����򲻹���\n");



        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 300
        ||      (int)me->query("neili") < 300 )
                return 
notify_fail("�����������������û�а취��ϰ���߽�����\n");
        me->receive_damage("qi", 80);
        me->add("neili", -30);
        write("�㰴����ѧ����һ�����߽�����\n");
        return 1;
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

        if (random(7)==0 && me->query("neili") >= 100)
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
                switch(random(2)) {
                        case 0: return HIR"$Nʹ��һ�С������ΰ˷�������������������Ӱ��������$n��$l��\n"NOR;
                        case 1: return RED"$Nʹ��һ�С����߷���ҧ������������һ�����磡������$n��$l��\n"NOR;
                }
        }
}

string perform_action_file(string action)
{
        return __DIR__"qingshe-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({

        "$nʹ��һ�С����߷���ҧ�������е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ��������������$N��$w�������⡣\n",
        "$nʹ��һ�С������ΰ˷��������е�$v����������Ӱ��������$N��$w��\n",
        "$n���е�$vһ����һ�С��������项����$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С�������졹����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С�������졹��$vֱ��$N��˫�֡�\n",
        "$n�����е�$v�������������������������ߣ��ȵ�$N�������ˡ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


int learn_bonus()
{
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 15;
}
