// banruo-zhang.c ������
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n
����������·",
    "force" : 250,
    "dodge" : 5,
    "damage": 260,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "��ճ���"
]),
([  "action" : "$N���ƻ�һ��Բ��һʽ��������ա�������б������������$n����ǰ
��Ѩ",
    "force" : 260,
    "dodge" : 5,
    "damage": 260,
    "damage_type" : "����",
    "lvl" : 12,
    "skill_name" : "�������"
]),
([  "action" : "$Nʹһʽ���ƶ����롹�����������������ɺ����һ��˦����ն��$n
��$l",
    "force" : 270,
    "dodge" : 5,
    "damage": 260,
    "damage_type" : "����",
    "lvl" : 18,
    "skill_name" : "�ƶ�����"
]),
([  "action" : "$N���ƻ��أ���ȭ�����󷢣�һʽ����������������������$n��$l",
    "force" : 285,
    "dodge" : 5,
    "damage": 260,
    	    "damage_type" : "����",
    "lvl" : 24,
    "skill_name" : "��������"
]),
([  "action" : "$Nʹһʽ������ء���ȫ�������ת��˫��һǰһ���͵�����$n
���ؿ�",
    "force" : 200,
    "dodge" : 5,
    "damage": 260,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : "�����"
]),
([  "action" : "$N���Ʊ�������һ������һʽ�����б��¡���˫�Ƽ�����$n�ļ�ͷ",
    "force" : 220,
    "damage": 2260,
    "dodge" : 5,
    "damage_type" : "����",
    "lvl" : 36,
    "skill_name" : "���б���"
]),
([  "action" : "$N���ϸ߸�Ծ��һʽ����ɽ��ˮ�����Ӹ����£���������$n��ȫ��",
    "force" : 240,
    "dodge" : 20,
    "damage": 260,
    "damage_type" : "����",
    "lvl" : 42,
    "skill_name" : "��ɽ��ˮ"
]),
([  "action" : "$Nʹһʽ��ժ�ǻ�����������������˫�����֣�һ������$n��$l�ȥ",
    "force" : 370,
    "dodge" : 10,
    "damage": 260,
    "damage_type" : "����",
    "lvl" : 48,
    "skill_name" : "ժ�ǻ���"
]),
([  "action" : "$N�������»��أ�һʽ����������������Ȼ��Ϊ�������꣬����$n",
    "force" : 310,
    "dodge" : 30,
    "damage": 260,
    "damage_type" : "����",
    "lvl" : 54,
    "skill_name" : "��������"
]),
([  "action" : "$Nһʽ����շ�ħ����˫�ֺ�ʮ������$n΢΢һҾ��ȫ���ھ������
����ӿ����",
    "force" : 360,
    "dodge" : 10,
    "damage": 360,
    "damage_type" : "����",
    "lvl" : 60,
    "skill_name" : "��շ�ħ"
]),
([	"action" : "$N���Ƚż��ض�����һʽ������𡹣����ƺ�ʮ�����ֱ��������$nȫ��",
	"force" : 300,
        "dodge" : 25,
	"damage": 360,
	"damage_type" : "����",
	"lvl" : 5,
	"skill_name" : "�����"
]),
([	"action" : "$N���ƻ�һ��Բ���أ�һʽ�����������������ƻ���б������������$n$l",
	"force" : 230,
        "dodge" : 15,
        "damage": 260,
        "damage_type" : "����",
        "weapon" : "��Ե",
	"lvl" : 15,
	"skill_name" : "��������"
]),
([	"action" : "$Nʹһʽ�����޹����������������������ɺ����һ��˦�ģ�����$n��ǽ����",
	"force" : 270,
        "dodge" : 10,
        "damage": 260,
        "damage_type" : "����",
	"lvl" : 35,
	"skill_name" : "���޹���"
]),
([	"action" : "$N���ƻ��أ���ȭ������һʽ�����ҵ�ϡ�������������������ƻ�������$n$l",
	"force" : 360,
        "dodge" : 15,
        "damage_type" : "����",
	"damage": 260,
	"lvl" : 55,
	"skill_name" : "���ҵ��"
]),
([	"action" : "$Nʹһʽ����ת���֡���ȫ�������ת������ɾ�˫��һǰһ���͵ذ���$n���ؿ�",
        "force" : 260,
        "dodge" : 10,
        "damage": 360,
        "damage_type" : "����",
	"lvl" : 65,
	"skill_name" : "��ת����"
]),
([	"action" : "$N���Ʊ�������һ������һʽ����ϲ���¡���ȫ�����������������˫�Ƽ���$n",
        "force" : 300,
        "dodge" : 25,
        "damage": 260,
        "damage_type" : "����",
	"lvl" : 85,
	"skill_name" : "��ϲ����"
]),
([	"action" : "$N���ϸ߸�Ծ��һʽ�����������������Ӹ����£���ɢ������������������$n��ȫ��",
        "force" : 340,
        "dodge" : 10,
        "damage": 360,
        "damage_type" : "����",
	"lvl" : 105,
	"skill_name" : "�������"
]),
([	"action" : "$Nʹһʽ����˳��������˲�侢��������$P˫���������֣�һ������$n��$lնȥ",
        "force" : 380,
        "dodge" : 110,
        "damage": 360,
        "damage_type" : "����",
        "weapon" : "�ֵ�",
	"lvl" : 125,
	"skill_name" : "��˳����"
]),
([	"action" : "$N�������»��أ�һʽ���սԻ����ĳ�����Ӱ���ص����������ޱ��������$n",
        "force" : 400,
        "dodge" : 115,
        "damage_type" : "����",
	"damage": 360,
	"lvl" : 155,
	"skill_name" : "�սԻ���"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }   

int valid_combine(string combo) { return combo=="yizhi-chan"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("�������Ʊ�����֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�����ơ�\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷��������ơ�\n");
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
        int i, level, neili, ljz, sxz, strike;
    level = (int)me->query_skill("banruo-zhang", 1);
        neili = me->query("neili");
        sxz = me->query_skill("banruo-zhang", 1);
        ljz = me->query_skill("banruo-zhang", 1);
 	strike = me->query_skill("strike", 1);
        if (ljz > 79 && sxz > 79 && strike > 79 && neili > 500 
            && random(me->query_int()) > 24 ){
                me->add("neili", -60);
                if(random(10) < 4 )
                return ([
                "action":HIY
    "��ʱ��,�����羲���ƺ�ƽ�̣������Լ��������$N����б���������γɲ�ɫ�⻷��
$N�����Լ�����Ӱ�����س�������ɫ�����ϡ�"HIC"���⻷���˶�����Ӱ�ڻ��С�"HIY",ʹ����
"HIW"�����ƾ�ѧ"HIY"���𶥷�⡻"NOR,
	        "weapon" : HIY"�𶥷��"NOR,
                "force": 800,
                "dodge": 15,
                "parry": 15,
                "damage": 800,
                "damage_type": "����"]);
          }
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("������������������ơ�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"banruo-zhang/" + action;
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