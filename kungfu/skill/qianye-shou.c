// qianye-shou.c ����ǧҶ��
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nһʽ���Ϻ���𡹣�������Σ���������ͻȻ����$n�ı����Ѩ
",
    "force" : 100,
    "dodge" : 10,
    "lvl" : 0,
    "skill_name" : "�Ϻ����",
    "damage_type" : "����"
]),
([      "action" : "$N����һ�Σ�һʽ����������������������$n�ļ�ͷ����ȭ����$n��
�ؿ�",
    "force" : 110,
    "dodge" : 10,
    "lvl" : 10,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([      "action" : "$Nһʽ�����������������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
    "force" : 130,
    "dodge" : 20,
    "damage": 5,
    "lvl" : 20,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([      "action" : "$N�������У�����ֱ����һʽ�������Ӱ������Ʈ��������$n����
��",
    "force" : 160,
    "dodge" : 20,
    "damage": 10,
    "lvl" : 30,
    "skill_name" : "�����Ӱ",
    "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ��ˮ��׽�¡�����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
    "force" : 200,
    "dodge" : 30,
    "damage": 15,
    "lvl" : 38,
    "skill_name" : "ˮ��׽��",
    "damage_type" : "����"
]),
([      "action" : "$N˫ȭ���裬һʽ������ȥ���������ֻ��ۣ�£��Ȧ״���ͻ�$n����
�",
    "force" : 250,
    "dodge" : 30,
    "damage": 20,
    "lvl" : 45,
    "skill_name" : "����ȥ��",
    "damage_type" : "����"
]),
([      "action" : "$Nһʽ��ˮ�ݳ�û����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",  
    "force" : 310,
    "dodge" : 40,
    "damage": 25,
    "lvl" : 51,
    "skill_name" : "ˮ�ݳ�û",
    "damage_type" : "����"
]),
([      "action" : "$N˫�ֱ�ȭ��һʽ����������������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮ
һ��",
    "force" : 380,
    "dodge" : 40,
    "damage": 30,
    "lvl" : 56,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([      "action" : "$Nһʽ������տա���ȭ���������֣��������ޣ�����������$n�ĵ�
��",
    "force" : 460,
    "dodge" : 40,
    "damage": 40,
    "lvl" : 60,
    "skill_name" : "����տ�",
    "damage_type" : "����"
]),
([	"action" : "$Nһʽ�����ֽ�ӡ����˫��̧���������ϣ�����Ĵָָ������Ӵ�����ǰ����",
	"force" : 80,
        "dodge" : 35,
	"lvl" : 15,
	"skill_name" : "���ֽ�ӡ",
	"damage_type" : "����"
]),
([	"action" : "$N����ӡ��̧������ת�ƣ�һʽ��������������ȫ������ֱ��˫����$n�ķ���γ�",
	"force" : 80,
        "dodge" : 25,
	"lvl" : 5,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ�������ඥ��������ͬʱ����ת�ƣ����ֳ�©��״�������������ƣ�����$n����",
	"force" : 250,
        "dodge" : 55,
	"lvl" : 25,
	"skill_name" : "�����ඥ",
        "damage_type" : "����"
]),
([	"action" : "$N�������ֵ���ǰ��������˫�ֺ�ʮ�����������Ŀտ����������������С�۳�һֱ��ֱ��$n",
	"force" : 100,
        "dodge" : 50,
	"lvl" : 25,
	"skill_name" : "˫�ֺ�ʮ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ����ָǬ�����������ɿ�ת�ƣ�������ָ����ǰ������ȴ�������£�����$n$l",
	"force" : 90,
        "dodge" : 55,
	"lvl" : 45,
	"skill_name" : "��ָǬ��",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ������������������ǰ������������չ����$n��ƽ����������������һ˦",
        "force" : 100,
        "dodge" : 30,
	"lvl" : 45,
	"skill_name" : "������",
        "damage_type" : "ˤ��"
]),
([	"action" : "$N����һ�߷ֿ���һ����ǰ�·���չ��һʽ��˫���º������ֱ۱�ã���$n��ǰӡ�˲���ʮ��",
        "force" : 130,
        "dodge" : 130,
	"lvl" : 65,
	"skill_name" : "˫���º�",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��������������ȫ������ֱ����ָ����$n���㣬Ȼ��ȫ���������ɣ����ָֻ�����ǰ��ʮ",
        "force" : 160,
        "dodge" : 120,
	"lvl" : 65,
	"weapon" : "ָ��",
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ���޺���ɽ��������һ�߷ֿ���һ����$n�����չ��ͬʱ������ת��󷽣���$pˤ�˳�ȥ",
        "force" : 390,
        "dodge" : 55,
	"lvl" : 85,
	"skill_name" : "�޺���ɽ",
        "damage_type" : "ˤ��"
]),
([	"action" : "$Nһʽ�������ɽ����ָ�����ϣ������ͬ�ߣ�������ֱ������һ�ӣ���$n�����Ƴ�",
        "force" : 420,
        "dodge" : 50,
	"lvl" : 85,
	"skill_name" : "�����ɽ",
        "damage_type" : "����"
]),
([	"action" : "$N���ֻ������䣬��������ת��$n������һʽ������С�����������ص����͵طž�",
        "force" : 400,
        "dodge" : 55,
	"lvl" : 105,
	"skill_name" : "����С��",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }      

int valid_combine(string combo) { return combo=="longzhua-gong"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("������ǧҶ�ֱ�����֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ����ǧҶ�֡�\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷�������ǧҶ�֡�\n");
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
    level   = (int) me->query_skill("qianye-shou",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("�����������������ǧҶ�֡�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"qianye-shou/" + action;
}
mixed hit_ob(object me, object target)
{
    string msg;
    int j;
    j = me->query_skill("qianye-shou", 1);
   
    if( (!random(8)) && !target->is_busy() && j > 150 &&
       me->query_skill("buddhism,1") >180 &&
       me->query("neili") > 1000 && me->query("max_neili") > 2500 &&
       me->query("combat_exp") > random(target->query("combat_exp"))){
       msg = CYN"$N��ƮƮ�ĳ�һ�ƣ��Ƶ���;����Ȼ΢΢ҡ�Σ���ʱһ�Ʊ����ƣ����Ʊ����ƣ����Ʊ���ơ�\n"NOR;
       msg += "���$nֻ��ٵ���̣�$N����Ʊ�ʮ���ƣ������û�Ϊ��ʮ���ơ�\n";
       msg +="$n ����������������Ӱ���ں��ġ�\n";
        target->receive_damage("qi",j/2*(me->query_skill("buddhsim",1)/30));               
        message_vision(msg, me, target);
        }
}