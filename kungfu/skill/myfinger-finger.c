// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// mylove
// ����������
// ���ŵھŴ�����
// 24763020
// ����
// finger
// ü��ָ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N��ȻһЦ������ʳָ����̽����һʽ��ü�����项������$n��ӡ��Ѩ��$N����һԾ�����ֽ�������һ�С���Ϭһָ������׼$n��̫��Ѩ��ȥ��",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "ü��ָ"
]),
// ZHAOSHI :1

([
"action" :"$N����һ��������˫��ʳָ������һʽ����Ϭָ��������$n��̫��Ѩ��",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "��Ϭָ"
]),
// ZHAOSHI :2

([
"action" :"$N����һԾ��������ָһ�С���ħ����׼$n��$lбб�̳�",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "��ħһָ"
]),
// ZHAOSHI :3

([
"action" :"$N�ٺ���Цһ����˫��һ�С�Ǭ���޼�������׼$n������бб��ȥ��",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "Ǭ��ָ"
]),
// ZHAOSHI :4

([
"action" :"$N˫��ʮָ�趯��ɣ�ʹ�������������������죬$n��ʱ����ľ����������֪���Ӧ����",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "�������"
]),
// ZHAOSHI :5

([
"action" :"���װ�����������������˫�֣�һ�С�������Ұ�������ֱ��$n",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "������Ұ"
]),
// ZHAOSHI :6

([
"action" :"$N΢̽˫�ۣ�ƾ��һ��,ʹ������������ݣ�",
"force" :240,
"damage" :160,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "��������"
]),
// ZHAOSHI :7

([
"action" :"$Nһ����Х����Ȼ̽��ʮָʹ����������Ԩ�ݣ��ó��������׷���������������$n��",
"force" :270,
"damage" :180,
"damage_type": "����",
"lvl" : 7,
"skill_name" : "������Ԩ"
]),
// ZHAOSHI :8

([
"action" :"$N΢΢����ʹ��ü��ָ��ѧ������ָ������������Ӱ������$n��",
"force" :300,
"damage" :200,
"damage_type": "����",
"lvl" : 8,
"skill_name" : "����ָ"
]),
 });
// ZHAOSHI :9
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"ü��ָ"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"ü��ָ"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "finger" || usage=="parry"; }
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
    level = (int)me->query_skill("myfinger-finger",1);
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
