/* 
   jingang-zhang.c ��������
   �ͼ���צ(jimie-zhua)����
   ȡ�ԡ������˲����ȡ�
   2/3/98 by snowman
*/
#include <ansi.h>
inherit SKILL;
 
mapping *action = ({
([      "action" :"$N��Ȼ΢Ц��һʽ������������˫�ֺ�ʮ��ǰ΢΢һ�ݣ�һ�ɰ������ƶ���������$n��$l",
         "force" : 200,
         "dodge" : 35,
         "damage": 260,
         "lvl" : 0,
         "skill_name" : "������",
         "damage_type" : "����"
]),
([      "action" :"$N��ɫ������һʽ�����𴫷���������$n��������ֵ�ȭ����ǰһ�������ֳ���ֱ��$n�ĺ���",
         "force" : 140,
         "dodge" : 25,
         "damage": 260,
         "lvl" : 10,
         "skill_name" : "���𴫷�",
         "damage_type" : "����"
]),
([      "action" :"$Nһ����Ц��һʽ����ڤ�ѻ꡹˫ȭ���ٽ������ʮ���ƣ��ƴ������������죬��$n��ס���ˣ�ƣ���м�",
         "force" : 200,
         "dodge" : 20,
         "damage": 260,
         "lvl" : 20,
         "skill_name" : "��ڤ�ѻ�",
         "damage_type" : "����"
]),
([      "action" :"$N���װ������У�һʽ��������������˫����꣬һǰһ��Ю��һ����������$n",
         "force" : 240,
         "dodge" : 20,
         "damage": 360,
         "lvl" : 30,
         "skill_name" : "��������",
         "damage_type" : "����"
]),
([      "action" :"$Nһʽ����ɢ��ħ������ü��Ŀ֮�䣬ͻȻ˫��ֱ��ֱ�£������·��������ħһ�㹥��$n����ǰ���",
         "force" : 260,
         "dodge" : 15,
         "damage": 360,
         "lvl" : 40,
         "skill_name" : "��ɢ��ħ",
         "damage_type" : "����"
]),
([      "action" :"$Nһʽ�����෨�ࡹ��������Σ�����һ�䣬�ѻ�����ʮ����Ӱ������ӡ��$n��ȫ�����ҪѨ",
         "force" : 280,
         "dodge" : 10,
         "damage": 360,
         "lvl" : 60,
         "skill_name" : "���෨��",
         "damage_type" : "����"
]),
([      "action" :"$N����Ծ�𣬰���г��־޴���Ӱ��ͻȻһʽ���������ơ���ͷ�½��ϣ���ת�Ÿ���������˫�ƶ�ס$n",
         "force" : 300,
         "dodge" : 5,
         "damage": 360,
         "lvl" : 80,
         "skill_name" : "��������",
         "damage_type" : "����"
]),
([      "action" :"$Nׯ����������������һ������ȫ���·�΢΢���𣬵ͺ�һ����һʽ�����ȼ��֡����������ȶ���������$n��ǰ��",
         "force" : 350,
         "dodge" : 0,
         "lvl" : 100,
         "damage": 360,
         "skill_name" : "���ȼ���",
         "damage_type" : "����"
])
});
 
int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }
 
int valid_combine(string combo){
        if(this_player()->query_skill("jingang-zhang", 1) > 100
	   && this_player()->query_int() > 20)
   	         return combo=="jimie-zhua";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ȭ������֡�\n");
        if ((int)me->query_skill("yijinjing", 1) < 140)
                return notify_fail("����׽�ڹ���򲻹����޷�ѧ����ȭ��\n");
        if ((int)me->query("max_neili") < 2000)
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
         int i, level;
         level   = (int) me->query_skill("jingang-zhang",1);
         for(i = sizeof(action); i > 0; i--)
                 if(level > action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}
 
int practice_skill(object me)
{
         if ((int)me->query("jing") < 50)
                 return notify_fail("�������̫���ˡ�\n");
         if ((int)me->query("neili") < 20)
                 return notify_fail("�����������������ȭ��\n");
         me->receive_damage("jing", 45);
         me->add("neili", -15);
         return 1;
}
 
string perform_action_file(string action)
{
         return __DIR__"jingang-zhang/" + action;
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