// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hxsd
// С����
// ��ɽ�ɵ�ʮ�Ĵ�����
// 20000000
// ����
// sword
// ��Ʊ��





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N����С����һ��$N��$n",
"force" :50,
"dodge" :20,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "����"
]),
// ZHAOSHI :1

([
"action" :"$N����$nһЩ����",
"force" :80,
"dodge" :10,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "����"
]),
// ZHAOSHI :2

([
"action" :"$N����$nһЩ����",
"force" :100,
"dodge" :10,
"damage_type": "����",
"lvl" : 20,
"skill_name" : "����"
]),
// ZHAOSHI :3

([
"action" :"$N����$nһЩ����",
"force" :130,
"dodge" :5,
"damage_type": "����",
"lvl" : 30,
"skill_name" : "����"
]),
// ZHAOSHI :4

([
"action" :"$N����$nһЩ����",
"force" :150,
"dodge" :-5,
"damage_type": "����",
"lvl" : 40,
"skill_name" : "����"
]),
// ZHAOSHI :5

([
"action" :"$N����$nһЩ��Ļ",
"force" :180,
"dodge" :-5,
"damage_type": "����",
"lvl" : 50,
"skill_name" : "��Ļ"
]),
// ZHAOSHI :6

([
"action" :"$N����$nһЩ����",
"force" :200,
"dodge" :-10,
"damage_type": "����",
"lvl" : 60,
"skill_name" : "����"
]),
// ZHAOSHI :7

([
"action" :"$N����$nһЩ�ƽ�",
"force" :220,
"dodge" :-10,
"damage_type": "����",
"lvl" : 80,
"skill_name" : "�ƽ�"
]),
// ZHAOSHI :8

([
"action" :"$N",
"force" :20,
"dodge" :-10,
"damage_type": "����",
"lvl" : 100,
"skill_name" : "��"
]),
// ZHAOSHI :9

([
"action" :"$N",
"force" :30,
"dodge" :30,
"damage_type": "����",
"lvl" : 15,
"skill_name" : "��"
]),
// ZHAOSHI :10

([
"action" :"$N",
"force" :240,
"dodge" :240,
"damage_type": "����",
"lvl" : 19,
"skill_name" : "��"
]),
// ZHAOSHI :11

([
"action" :"$N",
"force" :260,
"dodge" :260,
"damage_type": "����",
"lvl" : 20,
"skill_name" : "����"
]),
 });
// ZHAOSHI :12
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"��Ʊ��"+"��\n");
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
    level = (int)me->query_skill("cash-sword",1);
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
