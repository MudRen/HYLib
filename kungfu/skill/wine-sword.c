// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// wine
// ��ơ
// ����Ľ�ݵڶ�������
// 2189260
// ����
// sword
// ��ơ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N�ս�����$wһ�С���ɪԹңҹ����������$n��$l",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "��ɪԹңҹ"
]),
// ZHAOSHI :1

([
"action" :"$Nһ�С����ҷ��갧������$w����ͷ�ϸ�����$n",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "���ҷ��갧"
]),
// ZHAOSHI :2

([
"action" :"$N��ǰ����һ��������$wʹ�����µ��ų��ǡ�ֱȡ$n�ĺ�",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "�µ��ų���"
]),
// ZHAOSHI :3

([
"action" :"$N���һ����ʹ������������̨������$wб�̣��ۿ�Ҫ����$n����磬��âͽת��$l",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "��������̨"
]),
// ZHAOSHI :4

([
"action" :"$N����$w����һ�֣�ʹ������������ĺ�����Ű���ɨ��$n",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "��������ĺ"
]),
// ZHAOSHI :5

([
"action" :"$N���𽣾������е�$w����������ʹ����������δ����̽��$n$l",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "������δ��"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"��ơ"+"��\n");
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
    level = (int)me->query_skill("wine-sword",1);
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
