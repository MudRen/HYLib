// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// dhxy
// ������
// �����ɵڶ�������
// 100000000
// Ů��
// hand
// ������





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·;$N����һԾ����������һ�С����к�ء���׼$n��$lбб�̳�һ��",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "����һʽ"
]),
// ZHAOSHI :1

([
"action" :"$N�������ó���2��",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "�����ʽ"
]),
// ZHAOSHI :2

([
"action" :"$N�������ó���3��",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "������ʽ"
]),
// ZHAOSHI :3

([
"action" :"$N�������ó���4��",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "������ʽ"
]),
// ZHAOSHI :4

([
"action" :"$N�������ó���5��",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "������ʽ"
]),
// ZHAOSHI :5

([
"action" :"$N�������ó���6��",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "������ʽ"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"������"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "hand" || usage=="parry"; }
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
    level = (int)me->query_skill("wuqingshou-hand",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
