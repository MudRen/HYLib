// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// cash
// ��Ʊ
// ������̵���������
// 8120595
// ����
// unarmed
// ҪǮ��





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"��Ʊ���־���$nǮ",
"force" :50,
"dodge" :10,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "���־���Ǯ"
]),
// ZHAOSHI :1

([
"action" :"��Ʊ��ȥ����$n��Ǯ",
"force" :80,
"dodge" :-10,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "��ȥ������Ǯ"
]),
// ZHAOSHI :2

([
"action" :"��Ʊ��Ҫ$n��Ǯ",
"force" :100,
"dodge" :-20,
"damage_type": "����",
"lvl" : 20,
"skill_name" : "��ҪǮ"
]),
// ZHAOSHI :3

([
"action" :"$n������ƱһЩͭ��",
"force" :130,
"dodge" :-30,
"damage_type": "����",
"lvl" : 30,
"skill_name" : "����ҪǮ"
]),
// ZHAOSHI :4

([
"action" :"$n������ƱһЩ����",
"force" :150,
"dodge" :-50,
"damage_type": "����",
"lvl" : 40,
"skill_name" : "�ٸ�Ǯ"
]),
// ZHAOSHI :5

([
"action" :"$n������ƱһЩ����",
"force" :180,
"dodge" :-60,
"damage_type": "����",
"lvl" : 50,
"skill_name" : "��Ҫ��Ǯ"
]),
// ZHAOSHI :6

([
"action" :"$n������ƱһЩ��Ʊ",
"force" :200,
"dodge" :-80,
"damage_type": "����",
"lvl" : 60,
"skill_name" : "�͸�Ǯ"
]),
// ZHAOSHI :7

([
"action" :"��Ʊ����$nһЩͭ��",
"force" :220,
"dodge" :-90,
"damage_type": "����",
"lvl" : 80,
"skill_name" : "��Ǯ"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"ҪǮ��"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"ҪǮ��"+"��\n");
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
    level = (int)me->query_skill("cash-unarmed",1);
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
