// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// shazi
// С��
// ���ŵ��ߴ�����
// 76950540
// ����
// claw
// ��Ǵݽ�צ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nһ�ְ�ס$n����һ�ְ�ס����򢣬����һ�֣��������°�˺������",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "����һʽ��"
]),
// ZHAOSHI :1

([
"action" :"$N����$n��һ��ҧס$n�ĺ����������ꡱһ����$n��ʳ�ܡ����ܡ�Ѫ��ȫ����ҧ�˳�����",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "���ڶ�ʽ��"
]),
// ZHAOSHI :2

([
"action" :"$N���μ�������ָ��Ȼ���$n������ǣ�����һ���Ͱ⿪��ͷ�ǣ�¶���׺������Խ���$n����һ������ʹ����ȥ��",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "������ʽ��"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"��Ǵݽ�צ"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "claw" || usage=="parry"; }
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
    level = (int)me->query_skill("cuogucuijin-claw",1);
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
