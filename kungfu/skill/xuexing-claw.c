// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// taotao
// ������
// ؤ��ڶ�ʮ������
// 2003513
// ����
// claw
// Ѫ��צ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nһ�ְ�ס$n����һ�ְ�ס��򢣬����һ�֣���$n�°�˺������",
"force" :60,
"dodge" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "���°�"
]),
// ZHAOSHI :1

([
"action" :"$N����$n��һ��ҧס$n�ĺ���������һ��$n��ʳ�ܣ����ܣ�Ѫ��ȫ����˺��ϣ���ã���һ��������",
"force" :90,
"dodge" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "ҧѪ��"
]),
// ZHAOSHI :2

([
"action" :"$N��ָ���$n����ǣ�����һ���⿪ͷ�ǣ���$n�Խ�һ��ץ�˳��������˼���",
"force" :120,
"dodge" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "ץ�Խ�"
]),
// ZHAOSHI :3

([
"action" :"$Nһ����ס$n������ҧ��$n�ظ��������ھͿеü����߹ǣ����¾Ͱ�$n�ظ�����˺���������ķε����������ɼ�",
"force" :150,
"dodge" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "������"
]),
// ZHAOSHI :4

([
"action" :"$Nһ����Ц����ס$n������ץס$n˫�֣�ž��һ��������Ӳק���������ֱ����������Ӵ�Ѫ��ģ�����׹�ɭɭ",
"force" :180,
"dodge" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "ק�ֱ�"
]),
// ZHAOSHI :5

([
"action" :"$N��ס$n�ı���һ�þ�������һ�����죬$n�ļ�׵�Ƕϳ�ʮ�߶�ʮ�˽أ�$N�ٴ�$n������Ѫ���ܵس�����������ģ���ļ�׵��",
"force" :210,
"dodge" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "��׵"
]),
// ZHAOSHI :6

([
"action" :"$Nץס$n�����ȣ�ʹ��һ˺����$n˺����Ƭ����Ѫ�Ľ���$n������ϡ���������һ��",
"force" :240,
"dodge" :160,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "˺˫��"
]),
 });
// ZHAOSHI :7
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"Ѫ��צ"+"��\n");
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
    level = (int)me->query_skill("xuexing-claw",1);
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
