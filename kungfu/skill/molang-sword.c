// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// fen
// ����
// ����˰���ܾ֡��ֳ�
// 5893862
// ����
// sword
// ����ħ�ǽ�





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nһ�����ţ�����$w����һƥħ������$n��$l��",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "ħ��һ"
]),
// ZHAOSHI :1

([
"action" :"$N�������ţ�����$w������ƥħ������$n��$l��",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "ħ�Ƕ�"
]),
// ZHAOSHI :2

([
"action" :"$N�������ţ�����$w������ƥħ������$n��$l��",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "ħ����"
]),
// ZHAOSHI :3

([
"action" :"$N�������ţ�����$w������ƥħ������$n��$l��",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "ħ����"
]),
// ZHAOSHI :4

([
"action" :"$N�������ţ�����$w������ƥħ������$n��$l��",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "ħ����"
]),
// ZHAOSHI :5

([
"action" :"$N�������ţ�����$w������ƥħ������$n��$l��",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "ħ����"
]),
// ZHAOSHI :6

([
"action" :"$N�������ţ�����$w������ƥħ������$n��$l��",
"force" :240,
"damage" :160,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "ħ����"
]),
// ZHAOSHI :7

([
"action" :"$N�������ţ�����$w������ƥħ������$n��$l��",
"force" :270,
"damage" :180,
"damage_type": "����",
"lvl" : 7,
"skill_name" : "ħ�ǰ�"
]),
// ZHAOSHI :8

([
"action" :"$N�������ţ�����$w������ƥħ������$n��$l��",
"force" :300,
"damage" :200,
"damage_type": "����",
"lvl" : 8,
"skill_name" : "ħ�Ǿ�"
]),
// ZHAOSHI :9

([
"action" :"$Nʮ�����ţ�����$w����ʮƥħ������$n��$l��",
"force" :330,
"damage" :220,
"damage_type": "����",
"lvl" : 9,
"skill_name" : "ħ��ʮ"
]),
// ZHAOSHI :10

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :360,
"damage" :240,
"damage_type": "����",
"lvl" : 10,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :11

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :390,
"damage" :260,
"damage_type": "����",
"lvl" : 11,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :12

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :420,
"damage" :280,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :13

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :450,
"damage" :300,
"damage_type": "����",
"lvl" : 13,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :14

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :480,
"damage" :320,
"damage_type": "����",
"lvl" : 14,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :15

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :510,
"damage" :340,
"damage_type": "����",
"lvl" : 15,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :16

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :540,
"damage" :360,
"damage_type": "����",
"lvl" : 16,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :17

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :570,
"damage" :380,
"damage_type": "����",
"lvl" : 17,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :18

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :600,
"damage" :400,
"damage_type": "����",
"lvl" : 18,
"skill_name" : "��ħ��"
]),
// ZHAOSHI :19

([
"action" :"$N�������ţ�����$w����������ħ������$n��$l��",
"force" :630,
"damage" :420,
"damage_type": "����",
"lvl" : 19,
"skill_name" : "��ħ��"
]),
 });
// ZHAOSHI :20
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"����ħ�ǽ�"+"��\n");
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
    level = (int)me->query_skill("molang-sword",1);
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
