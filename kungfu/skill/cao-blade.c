// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hxsd
// С����
// ��������������ū
// 8000000
// ����
// blade
// �޵е�





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N����һԾ������$wһ�С����к�ء���׼$n��$lбб�̳�һ��",
"force" :60,
"dodge" :40,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "�޵�һ"
]),
// ZHAOSHI :1

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :90,
"dodge" :60,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "�޵ж�"
]),
// ZHAOSHI :2

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :120,
"dodge" :80,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "�޵���"
]),
// ZHAOSHI :3

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :150,
"dodge" :100,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "�޵���"
]),
// ZHAOSHI :4

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :180,
"dodge" :120,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "�޵���"
]),
// ZHAOSHI :5

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :210,
"dodge" :140,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "�޵���"
]),
// ZHAOSHI :6

([
"action" :"creatskill blade cao �޵е� 7",
"force" :240,
"dodge" :160,
"damage_type": "����",
"lvl" : 7,
"skill_name" : "�޵���"
]),
// ZHAOSHI :7

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :270,
"dodge" :180,
"damage_type": "����",
"lvl" : 8,
"skill_name" : "�޵���"
]),
// ZHAOSHI :8

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :300,
"dodge" :200,
"damage_type": "����",
"lvl" : 9,
"skill_name" : "�޵���"
]),
// ZHAOSHI :9

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :330,
"dodge" :220,
"damage_type": "����",
"lvl" : 10,
"skill_name" : "�޵���"
]),
// ZHAOSHI :10

([
"action" :"$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
"force" :360,
"dodge" :240,
"damage_type": "����",
"lvl" : 11,
"skill_name" : "�޵���"
]),
 });
// ZHAOSHI :11
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�޵е�"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
string query_skill_name(int level)
{
        int i;
//        for(i = sizeof(action)-1; i >= 0; i--)
//                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level = (int)me->query_skill("cao-blade",1);
//        for(i = sizeof(action); i > 0; i--)
//                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade") return notify_fail("��ʹ�õ��������ԡ�\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
