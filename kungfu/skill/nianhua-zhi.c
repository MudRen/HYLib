// nianhua-zhi.c -�黨ָ
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N����̧�ۣ���ָ���˸���Ȧ��һʽ��ƿ�����⡹����$n��$l",
        "force" : 60,
        "dodge" : 15,
        "lvl" : 0,
        "skill_name" : "ƿ������",
        "damage_type" : "����"
]),
([      "action" : "$N�������У�һʽ����÷�������ָ��Ҹ������ָ��$n����ǰ",
        "force" : 70,
        "dodge" : 25,
        "lvl" : 0,
        "skill_name" : "��÷����",
        "damage_type" : "����"
]),
([      "action" : "$N����б�У����ְ��ƣ�����һʽ�������ʾơ�����$n��$l����",
        "force" : 90,
        "dodge" : 35,
        "lvl" : 0,
        "skill_name" : "�����ʾ�",
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀ΢����һʽ��¶��б������˫�ֻû���ǧ�ٸ�ָӰ������$n��
$l",
        "force" : 120,
        "dodge" : 45,
        "damage": 140,
        "lvl" : 9,
        "skill_name" : "¶��б��",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ�����³��ء������ƻ�ס�������бָ���죬���Ƶ���$n��
$l",
        "force" : 160,
        "dodge" : 55,
        "damage": 140,
        "lvl" : 18,
        "skill_name" : "���³���",
        "damage_type" : "����"
]),
([      "action" : "$N˫��ƽ����ǰ��ʮָ�濪��һʽ��Ҷ����������ָ��$n�������Ѩ
",
        "force" : 210,
        "dodge" : 20,
        "damage": 255,
        "lvl" : 27,
        "skill_name" : "Ҷ������",
        "damage_type" : "����"
]),
([      "action" : "$N˫�Ʒ��ɣ�һʽ�������𡹣�ָ�˱ų�����������������$n��ȫ
��",
        "force" : 270,
        "dodge" : 25,
        "damage": 260,
        "lvl" : 36,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��������˪������ָ���У�һ����������ٱ�ĵ�����������$n
��$l��ȥ",
        "force" : 340,
        "dodge" : 30,
        "damage": 280,
        "lvl" : 149,
        "skill_name" : "������˪",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��٤Ҷ΢Ц����˫��ʳָ���棬ָ�����һ�����������$n��
$l",
        "force" : 420,
        "dodge" : 35,
        "damage": 300,
        "lvl" : 159,
        "skill_name" : "٤Ҷ΢Ц",
        "damage_type" : "����"
]),
([      "action" : "$N����������ǰ��һʽ�������黨��������ʳָ��סĴָ���������
$nһ��",
        "force" : 510,
        "dodge" : 50,
        "damage": 320,
        "lvl" : 200,
        "skill_name" : "�����黨",
        "damage_type" : "����"
]),
([	"action" : "$N����̧�ۣ���ָ���˸���Ȧ��һʽ��������ʽ������һ��������$n��$l",
	"force" : 150,
        "dodge" : 135,
            "damage": 225,
        "weapon" : "ָ��",
	"lvl" : 5,
	"skill_name" : "������ʽ",
	"damage_type" : "����"
]),
([	"action" : "$N����������ǰ��һ�С�������ʽ������ָ��Ҹ��������������������$n��$l",
	"force" : 170,
        "dodge" : 115,
            "damage": 225,
        "weapon": "ָ��",
	"lvl" : 15,
	"skill_name" : "������ʽ",
        "damage_type" : "����"
]),
([	"action" : "$N���΢Ц������б�У�����פ����ǽ������һʽ������ʽ������$n$l���",
	"force" : 200,
        "dodge" : 125,
        "weapon": "ָ��",
	    "damage": 225,
	"lvl" : 25,
	"skill_name" : "����ʽ",
        "damage_type" : "����"
]),
([	"action" : "$N˫Ŀ΢������¶��Ц��һʽ����Ҷʽ�����û���ǧ�ٸ�ָӰ������$n$l",
	"force" : 230,
        "dodge" : 125,
	"weapon": "ָ��",
	    "damage": 225,
	"lvl" : 35,
	"skill_name" : "��Ҷʽ",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ�������ʽ�������ƻ�ס�������бָ�������ƣ����ŲŻ�������$n$l",
	"force" : 260,
        "dodge" : 115,
	    "damage": 225,
	"weapon": "ָ��",
	"lvl" : 45,
	"skill_name" : "�����ʽ",
        "damage_type" : "����"
]),
([	"action" : "$N΢Ц֮����˫��ƽ����ǰ��ʮָ�濪��һʽ���ȳ���ʽ����ָ��$n�������Ѩ",
	"force" : 280,
        "dodge" : 120,
	    "damage": 225,
	"weapon": "ָ��",
	"lvl" : 65,
	"skill_name" : "�ȳ���ʽ",
        "damage_type" : "����"
]),
([	"action" : "$N˫�Ʒ��ɣ�һʽ����������ʽ����΢Ц����ָ�˱ų������ᾢ������$n",
        "force" : 250,
        "dodge" : 115,
	    "damage": 225,
	"weapon": "ָ��",
	"lvl" : 85,
	"skill_name" : "��������ʽ",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�Ħڭ����ʽ������ָ����������һ����ϸ���������������$n��$l��ȥ",
        "force" : 300,
        "dodge" : 110,
	    "damage": 225,
	"weapon": "ָ��",
	"lvl" : 115,
	"skill_name" : "Ħڭ����ʽ",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�ʮ��٤Ҷʽ������Цһ����˫��ʳָ���棬ָ������һ����������ḧ��$n$l",
        "force" : 350,
        "dodge" : 55,
	    "damage": 225,
	"weapon": "ָ��",
	"lvl" : 135,
	"skill_name" : "ʮ��٤Ҷʽ",
        "damage_type" : "����"
]),
([	"action" : "$N����������ǰ��һʽ��Ħ�о���ʽ����΢Ц������ʳָ��סĴָ���������$nһ��",
        "force" : 400,
        "dodge" : 55,
    "damage": 225,
	"weapon": "ָ��",
	"lvl" : 155,
	"skill_name" : "Ħ�о���ʽ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanhua-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���黨ָ������֡�\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
                return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�黨ָ��\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����黨ָ��\n");
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
        level   = (int) me->query_skill("nianhua-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������黨ָ��\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"nianhua-zhi/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
	victim->receive_wound("qi", damage);
}
	return HIR"ֻ��$n$l�ƺ�һ�����³�һ����Ѫ���ѱ��׽�Ļ�������������!\n"NOR;
}
}