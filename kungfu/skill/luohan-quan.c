// luohan-quan.c �޺�ȭ
// modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([      "action" : "$N�����ϲ���һʽ����ݺ��ܡ��������ַֿ�����ȭΪ�ƣ�����$n��
$l",
    "force" : 180,
    "dodge" : 5,
    "lvl" : 0,
    "skill_name" : "��ݺ���",
    "damage_type" : "����"
]),
([      "action" : "$N�����̤��ȫ����ת��һ�С����ﳯ�����������͵ز���$n��$l",
    "force" : 200,
    "dodge" : 10,
    "lvl" : 8,
    "skill_name" : "���ﳯ��",
    "damage_type" : "����"
]),
([      "action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С����Ӷ�Ӧ����˫ȭ��$n��$l��
ȥ",
    "force" : 220,
    "dodge" : 15,
    "lvl" : 15,
    "skill_name" : "���Ӷ�Ӧ",
    "damage_type" : "����"
]),
([      "action" : "$N����Ȧ���������⵱�أ����ڳ��ϣ�һ�С�ƫ�����ǡ�����$n��
$l",
    "force" : 260,
    "dodge" : 20,
    "lvl" : 24,
    "skill_name" : "ƫ������",
    "damage_type" : "����"
]),
([      "action" : "$Nʹһ�С��ຣ��ͷ��������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
    "force" : 300,
    "dodge" : 25,
    "lvl" : 33,
    "skill_name" : "�ຣ��ͷ",
    "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ�����һ�ǡ�Юɽ���������Ƴ���磬һ�����е�$n������",
    "force" : 360,
    "dodge" : 30,
    "lvl" : 42,
    "skill_name" : "Юɽ����",
    "damage_type" : "����"
]),
([      "action" : "$Nʩ��������������˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ
��",
    "force" : 420,
    "dodge" : 35,
    "lvl" : 50,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([      "action" : "$N����ڿۣ�����������һʽ�������������˫�����밴��$n���ؿ�
",
    "force" : 480,
    "dodge" : 40,
    "lvl" : 58,
    "skill_name" : "�������",
    "damage_type" : "����"
]),
([	"action" : "$Nһʽ��������ʽ�������屣��վ�������Ʋ��䣬˫��ƽ��ǰ����˫��ǰ̽��˫����ȭ��ץ��$n����",
	"force" : 50,
        "dodge" : 30,
	"lvl" : 2,
	"skill_name" : "������ʽ",
        "damage_type" : "����"
]),
([	"action" : "$N�����̤��һ�С�ƽ�����ơ���������Ȼ����վ�������Ʋ��䣬���ֻ��ƣ���ǰֱ�����",
	"force" : 60,
        "dodge" : 20,
	"lvl" : 5,
	"skill_name" : "ƽ������",
        "damage_type" : "����"
]),
([	"action" : "$N�ҽ�ԭ�ض岽�����̤ǰ�����������ǲ�������һ�С���ű��ҡ����������Һ�������",
	"force" : 170,
        "dodge" : 15,
	"lvl" : 25,
	"skill_name" : "��ű���",
        "damage_type" : "����"
]),
([	"action" : "$Nȫ����ǰ��һ�С��������ҡ���������ǰֱ�����䣬����ͬʱ����Ӳ�ӣ���Ȼ��������",
	"force" : 80,
        "dodge" : 112,
	"lvl" : 25,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N���ƻ�ס���󲻶�������ԭ�����ⷭ��ץ�ɣ������ɵ���ơ������ֲ�����������$nֱ�ж���",
	"force" : 100,
        "dodge" : 15,
	"lvl" : 45,
	"weapon" : "����",
	"skill_name" : "�ɵ����",
	"damage_type" : "����"
]),
([	"action" : "$N�ҽ��Ͻ������¶׳��񻷲����������ַ�ȭһʽ���������ҡ���ǰ���䣬���Ƹ����ƶ���",
        "force" : 120,
        "dodge" : 118,
	"lvl" : 45,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N�����񻷲������������������ֿ��������Ϸ�����˳�Ʋ��֡����Բ�˿����$n$l�ɳ�",
        "force" : 140,
        "dodge" : 21,
	"lvl" : 65,
	"skill_name" : "˳�Ʋ���",
        "damage_type" : "����"
]),
([	"action" : "$N�Ĳ�˿�����²�ѹ������ԭ����������˫����ӡ���������������$nֱ�Ŷ���",
        "force" : 260,
        "dodge" : 24,
	"lvl" : 64,
	"skill_name" : "˫�����",
        "damage_type" : "����"
]),
([	"action" : "$N���ҽż�ع�����ϥ����ǰֱ����������ϥ���ơ���˳����ȭ���������ַ���ǰ��",
        "force" : 280,
        "dodge" : 24,
	"lvl" : 84,
	"skill_name" : "��ϥ����",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С��Ʋ����ҡ�������΢��������˫������ͬʱ��Ȧ������ǰ�ɳ�����������ǰ�У���ȭ˳����ǰ����$n",
        "force" : 300,
        "dodge" : 24,
	"lvl" : 105,
	"skill_name" : "�Ʋ�����",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="unarmed" ||usage=="parry"; }      

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail("���޺�ȭ������֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
       return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�޺�ȭ��\n");
    if ((int)me->query("max_neili") < 50)
       return notify_fail("�������̫�����޷����޺�ȭ��\n");
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
    level   = (int) me->query_skill("luohan-quan",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("��������������޺�ȭ��\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"luohan-quan/" + action;
}
