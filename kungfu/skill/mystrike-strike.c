// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// bwd
// �ƿ�����
// ؤ��ڶ�ʮ������
// 4897392
// ����
// strike
// �ҵ��Ʒ�





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
"skill_name" : "�ξ��˱�"
]),
// ZHAOSHI :1

([
"action" :"$N��䶹����Щ�����ˣ������̱ǵ�ζ����$n����������·;$N��䶹����Щ�����ˣ������̱ǵ�ζ����$n��$lбб�̳�һ��",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "�����ٷ�"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"�ҵ��Ʒ�"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�ҵ��Ʒ�"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "strike" || usage=="parry"; }
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
    level = (int)me->query_skill("mystrike-strike",1);
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
