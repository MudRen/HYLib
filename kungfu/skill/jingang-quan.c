// jingang-quan.c -����ȭ
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N��ϥ���������ֺ�ʮ��һʽ������������˫ȭ���ƶ���������$n��$l",
    "force" : 280,
    "dodge" : 5,
    "damage": 260,
    "lvl" : 0,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ���һ�׶����˫�������»���ȭ�����棬��ž����",
    "force" : 200,
    "dodge" : 5,
    "damage": 270,
    "lvl" : 20,
    "skill_name" : "�һ�׶",
    "damage_type" : "����"
]),
([  "action" : "$N�ڿշ���һʽ���˷��꡹��˫��˫���������$n�޿ɶ��",    
    "force" : 330,
    "dodge" : 15,
    "damage": 300,
    "lvl" : 40,
    "skill_name" : "�˷���",
    "damage_type" : "����"
]),
([  "action" : "$N˫���麬����Ե�³���һʽ�������ס���������$n�Ƴ�",
    "force" : 370,
    "dodge" : 5,
    "damage": 220,
    "lvl" : 60,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ����ָɽ��������$n����ǰ���",    
    "force" : 320,
    "dodge" : 10,
    "damage": 315,
    "lvl" : 80,
    "skill_name" : "��ָɽ",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ�������ɡ�������ʮָ���$n��ȫ����ʮ����ҪѨ",
    "force" : 380,
    "dodge" : 25,
    "damage": 325,
    "lvl" : 90,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$N��Ŀ���ӣ�˫��������һʽ����������������˷������������ǵ�
����",
    "force" : 450,
    "dodge" : 15,
    "damage": 335,
    "lvl" : 100,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$N��Ц��Ц��˫ȭ�����޶���һʽ������Ц������Ȼ����$n��ǰ��",
    "force" : 530,
    "dodge" : 20,
    "damage": 350,
    "lvl" : 60,
    "skill_name" : "����Ц",
    "damage_type" : "����"
]),
(["action" :"$N˫��һ�ӣ���һʽ���������������ͨ��֮�ƣ�ȭ��������������ֱ��$n��ȥ",
  "force" : 350,
  "dodge" : 15,
  "damage": 360,
  "lvl" : 5,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"$N�������������һ�գ�����һ����ǽ������������ȭ������$n��һ�С���˼����ǽ����",
  "force" : 300,
  "dodge" : 110,
  "damage": 360,
  "lvl" : 15,
  "skill_name" : "��˼",
  "damage_type" : "����"
]),
(["action" :"$Nһ����ʽ����ҵ����˫ȭ���������������ಢ����׼$n$lһʽ�ӳ��������쳣",
  "force" : 320,
  "dodge" : 115,
  "damage": 360,
  "lvl" : 25,
  "skill_name" : "��ҵ",
  "damage_type" : "����"
]),
(["action" :"$Nʹ��һ�С������˫�������Ӷ���ȭ����ſ��е�ʨ�Ӻ���������ɽ��Ϯ��$n",
  "force" : 340,
  "dodge" : 120,
  "damage": 360,
  "lvl" : 45,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"$N��������һʽ���������������������һȭ���棬������ǰ�ˣ����������ϻ�$n",
  "force" : 360,
  "dodge" : 115,
  "damage": 360,
  "lvl" : 65,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"$N�ӳ���ȭ������$n�����⻨ȭ֮��ʱ��һ�ɾ��籬��������$p�ؿڣ�������ʵ�ġ����ڡ�",
  "force" : 380,
  "dodge" : 110,
  "damage": 360,
  "lvl" : 75,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"$N���̷𾭣����һ�С������ֱ��$nǰ�أ�ȭ�������������������������˿������",
  "force" : 360,
  "dodge" : 115,
  "lvl" : 85,
  "damage": 360,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"ֻ��$N��ʮ���������⡸������һ��Ϊ��������Ϊȭ����������ȫ������ѹ��$n",
  "force" : 450,
  "dodge" : 115,
  "damage": 360,
  "lvl" : 105,
  "skill_name" : "����",
  "damage_type" : "����"
]),
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="unarmed" ||usage=="parry"; }     

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("������ȭ������֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
   return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ����ȭ��\n")
;
    if ((int)me->query("max_neili") < 50)
   return notify_fail("�������̫�����޷�������ȭ��\n");
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
    level   = (int) me->query_skill("jingang-quan",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[random(i)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("�����������������ȭ��\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"jingang-quan/" + action;
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
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"ֻ��$n$l�ƺ�һ�����³�һ����Ѫ���ѱ��׽�Ļ�������������!\n"NOR;
}
}