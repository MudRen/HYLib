// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// zbz
// С��Ů
// ���չ����Ĵ�����
// 2380738
// Ů��
// unarmed
// �ƻ��





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N����һԾ,һ�С�����ٵء���׼$n��$lбб����һ��",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "����ٵ�"
]),
// ZHAOSHI :1

([
"action" :"$N���һ����һ�С��������ա�һ��������$n$l��ȥ��",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "��������"
]),
// ZHAOSHI :2

([
"action" :"$N����ȫ��Ĺ����������������µġ��������ա�,��վŸ���������,����$n����������·",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "��������"
]),
// ZHAOSHI :3

([
"action" :"$N��������ʹϧ�����Ƿ�ŭ������������������һ�������ֺ���һ�ƣ�����$n��ȥ�������ƻ�󷨵�һʽ���������项",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "��������"
]),
// ZHAOSHI :4

([
"action" :"$N���λ���һֻ����ɷ�һ�ɳ��죬һ�С�������졹���ó��������˷���$n����������·",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "�������"
]),
 });
// ZHAOSHI :5
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"�ƻ��"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�ƻ��"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("yihun-unarmed",1);
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
