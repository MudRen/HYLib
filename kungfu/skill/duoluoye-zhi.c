/* 
   duoluoye-zhi.c ����Ҷָ
   �ͷ�����(fengyun-shou)����
   ���Է���֮���������족��
   2/3/98 by snowman
*/

inherit SKILL;
 
mapping *action = ({
(["action" :"$Nһʽ���������졹��������ָ�������������������һ�����ز���$n$l",
  "force" : 100,
  "dodge" : 25,
  "lvl" : 0,
  "weapon" : "����",
  "skill_name" : "��������",
  "damage_type" : "����"
]),
(["action" :"$N���Ц��ʹ���������졹��������΢�࣬��ָ����״�����Юһ�ɼ����ľ�������$n",
  "force" : 150,
  "dodge" : 15,
  "lvl" : 20,
  "weapon" : "ָ��",
  "skill_name" : "������",
  "damage_type" : "����"
]),
(["action" :"$Nһʽ��ҹĦ�졹���������д󿪴��أ�����Ʈ���鶯����Ȼһָ���������$n$l��",
  "force" : 200,
  "dodge" : 15,
  "lvl" : 40,
  "weapon" : "ָ��",
  "skill_name" : "ҹĦ��",
  "damage_type" : "����"
]),
(["action" :"$Nʹ��һ�С������졹������������������ס$n�����ӣ�����һ�ӣ�һָ����$n$l",
  "force" : 250,
  "dodge" : 10,
  "lvl" : 60,
  "weapon" : "ָ��",
  "skill_name" : "������",
  "damage_type" : "����"
]),
(["action" :"$N˫�ֱ�Բ���������У��������졹������һ��ָ���Ϯ$n������������ʵ���޼᲻��",
  "force" : 300,
  "dodge" : 5,
  "lvl" : 80,
  "weapon" : "ָ��",
  "skill_name" : "������",
  "damage_type" : "����"
]),
(["action" :"$N��$n������ָ�����������������Х֮�������С����������졹����ʵʵ������ʤ��",
  "force" : 350,
  "dodge" : -5,
  "lvl" : 100,
  "weapon" : "ָ��",
  "skill_name" : "����������",
  "damage_type" : "����"
]),
});
 
int valid_enable(string usage) { return  usage=="finger" || usage=="parry"; }
 
int valid_combine(string combo){
        if(this_player()->query_skill("duoluoye-zhi", 1) > 100
	   && this_player()->query_int() > 20)
   	         return combo=="fengyun-shou";
}

 
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                 return notify_fail("������Ҷָ������֡�\n");
        if ((int)me->query_skill("yijinjing", 1) < 140)
                 return notify_fail("����׽�ڹ���򲻹����޷�ѧ����Ҷָ��\n");
        if ((int)me->query("max_neili") < 2000)
		return notify_fail("�������̫�����޷�������Ҷָ��\n");
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
        level   = (int) me->query_skill("duoluoye-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
 
int practice_skill(object me)
{
        if ((int)me->query("jing") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�����������������Ҷָ��\n");
        me->receive_damage("jing", 45);
        me->add("neili", -15);
        return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"duoluoye-zhi/" + action;
}



