// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// tianyu
// ������
// [1;35m���ư��Ϲٰ�������[2;37;0m
// 2219919
// ����
// sword
// ����֮��





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N����һԾ������$wһ�С������һ������׼$n��$lбб�̳�һ��",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "�����һ��"
]),
// ZHAOSHI :1

([
"action" :"$N����һԾ������$wһ�С�����ڶ�������׼$n��$lбб�̳�һ��",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "����ڶ���"
]),
// ZHAOSHI :2

([
"action" :"$N����һԾ������$wһ�С��������������׼$n��$lбб�̳�һ��",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "���������"
]),
// ZHAOSHI :3

([
"action" :"$N����һԾ������$wһ�С�������Ľ�����׼$n��$lбб�̳�һ��",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "������Ľ�"
]),
// ZHAOSHI :4

([
"action" :"$N����һԾ������$wһ�С�������彣����׼$n��$lбб�̳�һ��",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "������彣"
]),
// ZHAOSHI :5

([
"action" :"$N����һԾ������$wһ�С��������������׼$n��$lбб�̳�һ��",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "���������"
]),
// ZHAOSHI :6

([
"action" :"$N����һԾ������$wһ�С�������߽�����׼$n��$lбб�̳�һ��",
"force" :240,
"damage" :160,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "������߽�"
]),
// ZHAOSHI :7

([
"action" :"$N����һԾ������$wһ�С�����ڰ˽�����׼$n��$lбб�̳�һ��",
"force" :270,
"damage" :180,
"damage_type": "����",
"lvl" : 7,
"skill_name" : "����ڰ˽�"
]),
// ZHAOSHI :8

([
"action" :"$N����һԾ������$wһ�С�����ھŽ�����׼$n��$lбб�̳�һ��",
"force" :300,
"damage" :200,
"damage_type": "����",
"lvl" : 8,
"skill_name" : "����ھŽ�"
]),
// ZHAOSHI :9

([
"action" :"$N����һԾ������$wһ�С������ʮ������׼$n��$lбб�̳�һ��",
"force" :330,
"damage" :220,
"damage_type": "����",
"lvl" : 9,
"skill_name" : "�����ʮ��"
]),
// ZHAOSHI :10

([
"action" :"$N����һԾ������$wһ�С������ʮһ������׼$n��$lбб�̳�һ��",
"force" :360,
"damage" :240,
"damage_type": "����",
"lvl" : 10,
"skill_name" : "�����ʮһ��"
]),
// ZHAOSHI :11

([
"action" :"$N����һԾ������$wһ�С�����֮ʮ��������׼$n��$lбб�̳�һ��",
"force" :390,
"damage" :260,
"damage_type": "����",
"lvl" : 11,
"skill_name" : "����֮ʮ����"
]),
 });
// ZHAOSHI :12
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"����֮��"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
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
    level = (int)me->query_skill("ninefive-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
