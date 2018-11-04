/* 
   boluomi-shou.c ��������
   ��Ħڭָ(mohe-zhi)����
   ���Է���֮�����ȡ���
   2/3/98 by snowman
*/

inherit SKILL;
 
mapping *action = ({
(["action" :"$N˫�ֺ�ʮ���ϣ���һʽ����ʩʽ��������ھ��ѱƵ��´����ɣ���$n�������",
  "force" : 100,
  "dodge" : 35,
  "lvl" : 0,
  "skill_name" : "��ʩʽ",
  "damage_type" : "����"
]),
(["action" :"$N����������Ϸ���ѹ�������������$n��ǰ������ã����н������ֽ�ʽ�������Ǳ仯����",
  "force" : 150,
  "dodge" : 20,
  "lvl" : 10,
  "skill_name" : "�ֽ�ʽ",
  "damage_type" : "����"
]),
(["action" :"$N��ͷ���磬ʹ������ʽ�����У�����ǰ$n���Ų��ʣ�������ȴ����˫�֣��Ż��ĳ�",
  "force" : 200,
  "dodge" : 15,
  "lvl" : 20,
  "skill_name" : "����ʽ",
  "damage_type" : "����"
]),
(["action" :"$N�������ˣ�һ�С�����ʽ����˫�ۻζ������ƬƬ��Ӱ��һ������$n���ƹ�ȥ",
  "force" : 250,
  "dodge" : 10,
  "lvl" : 40,
  "skill_name" : "����ʽ",
  "damage_type" : "����"
]),
(["action" :"$Nһʽ������ʽ���������������������ƽ����ˮ��һ�������$n����ѹ������",
  "force" : 300,
  "dodge" : 5,
  "lvl" : 80,
  "skill_name" : "����ʽ",
  "damage_type" : "����"
]),
(["action" :"$N˫�ۻӶ����ó�һ��������ӡ���ԡ�����ʽ����$n����������������ȴ�������쳣",
  "force" : 350,
  "dodge" : 5,
  "lvl" : 100,
  "skill_name" : "����ʽ",
  "damage_type" : "����"
]),
});
 
int valid_enable(string usage) { return  usage=="hand" || usage=="parry"; }
 
int valid_combine(string combo){
        if(this_player()->query_skill("boluomi-shou", 1) > 100
	   && this_player()->query_int() > 20)
   	         return combo=="mohe-zhi";
}

 
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                 return notify_fail("���������ֱ�����֡�\n");
        if ((int)me->query_skill("yijinjing", 1) < 140)
                 return notify_fail("����׽�ڹ���򲻹����޷�ѧ�������֡�\n");
        if ((int)me->query("max_neili") < 2000)
		return notify_fail("�������̫�����޷����������֡�\n");
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
        level   = (int) me->query_skill("boluomi-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
 
int practice_skill(object me)
{
        if ((int)me->query("jing") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("��������������������֡�\n");
        me->receive_damage("jing", 45);
        me->add("neili", -15);
        return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"boluomi-shou/" + action;
}



