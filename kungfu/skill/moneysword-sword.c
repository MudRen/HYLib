// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xnono
// ��������
// ����̡�����������
// 6550749
// ����
// sword
// ���ƽ���





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N������Σ����ֵķ���˦����һ��գ����еĳ���ֱ��$n�ĸ�����ȥ",
"force" :60,
"dodge" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "�вƽ���"
]),
// ZHAOSHI :1

([
"action" :"$N����һԾ�����ֵ�$wѸ�ٽ��������֣�һ��ͣ�����һ���벻���ĽǶȴ���$n��ĳ��",
"force" :90,
"dodge" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "͵������"
]),
// ZHAOSHI :2

([
"action" :"look",
"force" :120,
"dodge" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "ǧɽ��ˮ"
]),
// ZHAOSHI :3

([
"action" :"$Nʹ���������ڡ�������$w����������������಻�ϻ���$n����ۣ�",
"force" :150,
"dodge" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "������"
]),
 });
// ZHAOSHI :4
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"���ƽ���"+"��\n");
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
    level = (int)me->query_skill("moneysword-sword",1);
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
