// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// yinyan
// ������
// �����ɵڶ�������
// 2151213
// Ů��
// unarmed
// ��������ȭ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N���ֱ��һ��С����������$n��ͷ����$nͷ�����̳�����һ��������һ���Ĵ����",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "������"
]),
// ZHAOSHI :1

([
"action" :"$N�ӿ����׳�һ��СС���ҵ�һ��С��ֱ��$n���£����˽�ȥ��ֻ��$n���ֳ����ȣ������ǹ���Ĳҽ�����",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "����������"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"��������ȭ"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"��������ȭ"+"��\n");
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
    level = (int)me->query_skill("pig-unarmed",1);
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
