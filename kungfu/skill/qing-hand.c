// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// qing
// ����Ũ
// [35m���ϵ�һŮ��[2;37;0m
// 19649265
// Ů��
// hand
// ���������





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nһ�С���Ӱ���Ρ��������߳�����$n�������ɿ��⣬����$N˲��ǰ�����ɣ����ѻ���$n�ؿڣ�����δ�������ֳ���һ������ɨ��$n����",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "��Ӱ����"
]),
// ZHAOSHI :1

([
"action" :"����������Ӱ���裬$n�������ѱ��ȷ�˺��һƬƬ��ɢ����ϣ�$N����һԾ��һʽ��������硹������������Ƚ�������$n�ؿ�",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "�������"
]),
// ZHAOSHI :2

([
"action" :"����ɨ��Ҷ����$N���Ⱥ�ɨ$n���ţ�$n��æ�е�ͷ�ܹ����������ѱ�ɨ�䣬�Ǳ�����������$N����$n������������������һ�������ͷ�ɨ���ŵװ�ֱ��$n�°�",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "��ɨ��Ҷ"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"���������"+"��\n");
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
    level = (int)me->query_skill("qing-hand",1);
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
