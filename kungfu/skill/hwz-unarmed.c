// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hwz
// Ե���
// ؤ���ʮ�˴�����
// 3563217
// ����
// unarmed
// Ե





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ��Ե��Ե��Ե��ʱ��������ֱ��������$n����������·",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "Ե��Ե��"
]),
// ZHAOSHI :1

([
"action" :"$N����һԾ��һ�С��κδ�Եȴ���Ρ���׼$n��$lֱֱ����һȭ",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "Ե��ʱ"
]),
// ZHAOSHI :2

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ��������л����ʱ��������ֱ��������$n����������·",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "�κδ�Ե"
]),
// ZHAOSHI :3

([
"action" :"$N˫��Ѹ�ٵĻ���һ����Բ�����Ƚż��أ�һʽ��Ե�������������������ֱ��������$n������",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "ȴ����"
]),
 });
// ZHAOSHI :4
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"Ե"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"Ե"+"��\n");
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
    level = (int)me->query_skill("hwz-unarmed",1);
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
