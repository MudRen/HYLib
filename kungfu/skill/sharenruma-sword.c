// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// taotao
// Ľ����
// ����Ľ�ݵ���������
// 1870207
// ����
// sword
// ɱ�����齣��





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"HIW $Nһ����Ц����������һʽ��������ԡ�����Ӱ��Ȼ��һ��Ϊ��,����$w����,�����������ʵʵ,ֱ��$n��$l",
"force" :60,
"dodge" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "�������"
]),
// ZHAOSHI :1

([
"action" :"$Nһ����Х�����γ�����������������,�㲻մ�ص�ͽȻ�����߳�,$n��֪�Է��Ǻ����⣬���뻹�Ǳ�֮Ϊ�������̤��һ������ǰ�׹⼱��������$w����Ȱ�����$nȫ��ŵ���Ѩ,���ǡ�������ڡ�",
"force" :90,
"dodge" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "�������"
]),
// ZHAOSHI :2

([
"action" :"$N����ͻȻ����ʮ������,һʽ����ʬ���⡹,����$w�ƺ���������бб����$n,$n����ʽ��׾,��������һ��,ͻȻ$w����һ��,Ѹ���ޱȵ�ֱȡ$n���ɲ�",
"force" :120,
"dodge" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "��ʬ����"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"ɱ�����齣��"+"��\n");
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
    level = (int)me->query_skill("sharenruma-sword",1);
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
