// SKILL zhemei-shou.c

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *action_msg = ({
		 ""+(order[random(13)])+"$N��������һָͻ�����ںϽ�����ָ�����壬�ṹ�Ͻ������ƺ�ΰ��ָָ������$n"NOR"",
		 ""+(order[random(13)])+"$N���������������������Ե��������������ݺᣬ�������У���·�����븫���ϳ�һ·����$n"NOR"",
		 ""+(order[random(13)])+"$N˫���Եý������أ�ʹ��ʱԽ��Խ��ɬ�������趯һ�����ȣ�����Խ��Խ�أ�����ֹ��"NOR"",
		 ""+(order[random(13)])+"$Nʮָ̽�������ֻ�����������Ʈ���л�ȥ��$n��������ȴ�̺������ҵķ�����ʽ"NOR"",
		 ""+(order[random(13)])+"$N˫�������˦�������������޹ǣ��鶯֮������һ�ƣ���һ�����Ƶ�$n����һ����Ҳ��������"NOR"",
});

mapping *action = ({
([	"action" : "$Nһ��"+(order[random(13)])+"����÷��Թ��"NOR"��˫�ֺ�ӣ�ץ��$n",
	"force" : 130,
	"dodge" : 20,
	"damage" : 210,
	"lvl" : 0,
	"skill_name" : "��÷��Թ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"���ƻ���Գ"NOR"������ԾȻ����ץ��$n��ͷ��",
	"force" : 150,
	"dodge" : 20,
	"damage" : 220,
	"lvl" : 10,
	"skill_name" : "�ƻ���Գ�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"����ɽһ�����ı̡�"NOR"��˫�ַ׷ɣ�$nֻ���ۻ�����",
	"force" : 150,
	"dodge" : 30,
	"damage" : 230,
	"lvl" : 30,
	"skill_name" : "��ɽһ�����ı�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��÷��ѩ�串��ƻ��"NOR"��˫�ֺϻ���$nֻ���޴��ɱ�",
	"force" : 150,
	"dodge" : 30,
	"damage" : 245,
	"lvl" : 40,
	"skill_name" : "÷��ѩ�串��ƻ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��������÷��ѩ�ҡ�"NOR"��˫��ƮȻץ��$n",
	"force" : 250,
	"dodge" : 30,
	"damage" : 250,
	"lvl" : 50,
	"skill_name" : "������÷��ѩ��",
	"damage_type" : "����"
]),

([	"action" : "$N˫��ƽ�٣�һ��"+(order[random(13)])+"������������ŪӰ��"NOR"����$n",
	"force" : 300,
	"dodge" : 35,
	"damage" : 280,
	"lvl" : 60,
	"skill_name" : "����������ŪӰ",
            "damage_type" : "����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"����������ֱ���ۡ�"NOR"������$n���ƺ�$n��ȫ��������",
	"force" : 350,
	"dodge" : 30,
	"damage" : 200,
	"lvl" : 70,
	"skill_name" : "��������ֱ����",
	"damage_type" : "����"
]),

([	"action" : "$N������Σ�����һ��"+(order[random(13)])+"������δ�϶��Ⱦ���"NOR"����$n��ͷ��",
	"force" : 350,
	"dodge" : 30,
	"damage" : 250,
	"lvl" : 80,
	"skill_name" : "����δ�϶��Ⱦ�",
           "damage_type" : "����"
]),
([	"action" : "$Nʩ��"+(order[random(13)])+"������Ц�졹"NOR"�����ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"force" : 400,
	"dodge" : -10,
	"damage" : 250,
	"lvl" : 90,
	"skill_name" : "����Ц��",
            "damage_type" : "����"
]),
([	"action" : "$Nʩ��"+(order[random(13)])+"����ʯ��١�"NOR"������һ������$n",
	"force" : 450,
	"dodge" : -20,
	"damage" : 350,
	"lvl" : 100,
	"skill_name" : "��ʯ���",
            "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"|| usage=="hand"; }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ��÷�ֱ�����֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�����ɽ��÷�֡�\n");

        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("��������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("��������ƻ��̫ǳ��\n");
		
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,lvl_temp;
	level = (int) me->query_skill("zhemei-shou",1);
	lvl_temp = random((int)me->query_skill("zhemei-shou", 1));

	if ( lvl_temp > 80 && random(3) >1 )
	{
		if ( lvl_temp <= 100 )
			return ([
				"action": HIC"$N����һ�䣬������������֮����������Ϣ����$n�ġ�����Ѩ����������ȭ�ͻ�����������$n�ؿڵġ�����Ѩ��"NOR,
				"damage_type": "����",
				"dodge": 100,
		"damage": 600,
				"force": 360,
			]);

		if ( lvl_temp <= 120 )
			return ([
				"action": HIG"$N��������һ��������һ���ھ��������м���������һǰһ�����$n"NOR,
				"damage_type": "����",
		"damage": 600,
				"dodge": 100,
				"force": 400,
			]);

		if ( lvl_temp <= 140 )
			return ([
				"action": HIB"$N����ת�˸�СȦ���ȿ���׼����ֻ��ָ����$n���󣬴�Ĵָ��Сָ���ű㼴��£����ס$n���ţ�$n��ʱ��������"NOR,
				"damage": 100,
				"damage_type": "����",
		"damage": 600,
				"dodge": 100,
				"force": 450,
			]);

		if ( lvl_temp <= 160 )
		{
				return ([
					"action": HIW"$N˫����ץ��ʹ������ɽ��÷�֡��ĸ����书��ץ�д��ۣ����м��ƣ�����$n�����Ŵ�Ѩ"NOR,
					"damage_type": "����",
		"damage": 600,
					"dodge": 120,
					"force": 500,
				]);


		}

		return
		([
		"action": HIR"��ʱ$N����������������ң�����ַ��ӵ����쾡�£������������ۣ���������\n"
			 "Ȼ����ң����ѧ��������������Ȼ��Ȼ��Ҳʹ�˳�������ʹ�����������տ̶�\n"
			 "$N�������գ��Թ���$nҪ����ֱ����$n���òҿ��ޱ�"NOR,
		"damage_type": "����",
		"damage": 500,
		"dodge": 600,
		"force": 550,
		]);

	}
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������ɽ��÷�֡�\n");
        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("��������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("��������ƻ��̫ǳ��\n");
	me->receive_damage("qi", 45);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("beiming-shengong", 1);
if (lvl==0)
        lvl  = me->query_skill("bahuang-gong", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
}
                return HIR "$n" HIR "��һֻ�ֱۣ���$N�������ۣ���ʹ����!!\n" NOR;
        }
        else if (random(4)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));

return HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;
        }
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bahuang-gong",1);
        level2= (int) me->query_skill("bahuang-gong",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (damage2>= 3800) damage2 = 3800;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "bahuang-gong")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
me->add("neili",damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIR"$NͻȻ����,$nȫ����������ˮ��ԴԴ����������$N������\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}