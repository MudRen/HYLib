// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// danyingzi
// �����
// �һ����ڶ�������
// 7722248
// ����
// strike
// �����ֽ�





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N����Ϊ����ʹ��һʽ��׷�硹���������ߣ�����Ѹ�ͣ�������磬��$n����ʽ���ǲ������ܣ���ֱ�����ܵߵ�С����",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "׷��"
]),
// ZHAOSHI :1

([
"action" :"$N�ڿշ��𣬴ӿն�����һʽ�����ա���˫���罣�������������$n�޿ɶ�أ�ֱ����$n����",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "����"
]),
// ZHAOSHI :2

([
"action" :"$Nָ��һͦ����������һ��������һʽ�����¡�����ͨ��֮�ƣ��ֽ��������ϣ��ƾ���ֱ��$nС����ȥ��",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "����"
]),
// ZHAOSHI :3

([
"action" :"$Nһʽ��ժ�ǡ�����������������$n��ȫ����ʮ����ҪѨ��",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "ժ��"
]),
// ZHAOSHI :4

([
"action" :"$N���ӵ�����Ĵ��˰��Ȧ�ӣ��ֱ�һͦ����������һ����������������������������â���Ƴ��߰���������������Ʒ�ͻʢ��һʽ�����衹����$n��С������",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "����"
]),
// ZHAOSHI :5

([
"action" :"$Nʩչ�������¡������ոֽ���ɫ������$nֻ����һ����ȴ��һ����Ӱ�������ΰ�Ϯ���Լ����ؿڣ����Լ�ȴû����$N��ʱ�����֣�����",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "����"
]),
// ZHAOSHI :6

([
"action" :"$N�趯˫�ƣ�һ�С���Х����������������磬�˽���һ������$n�����䣡",
"force" :240,
"damage" :160,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "��Х"
]),
// ZHAOSHI :7

([
"action" :"$N���ƻ�����һ�С��Ǻ������Ʒ����ƣ����������е��ؿڣ����˲�֪�ֽ����Ժη���",
"force" :270,
"damage" :180,
"damage_type": "����",
"lvl" : 7,
"skill_name" : "�Ǻ�"
]),
// ZHAOSHI :8

([
"action" :"$N�Ų��������ģ�������ҡҡ��׹��ʵ����ȾŹ���һ�С���������ƽƽ�������������޵ش���$n����ţ�",
"force" :300,
"damage" :200,
"damage_type": "����",
"lvl" : 8,
"skill_name" : "����"
]),
// ZHAOSHI :9

([
"action" :"$NһХ���죬ʩչ������Ʈѩ����$n��ǰ�·�ͻȻ�����������$N��һ�Ƽ�����������ǰ�ˣ����������ϻ�$N��$n�Ѿ��ֲ���$Nʹ���ǽ����ƣ�",
"force" :330,
"damage" :220,
"damage_type": "����",
"lvl" : 9,
"skill_name" : "Ʈѩ"
]),
 });
// ZHAOSHI :10
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"�����ֽ�"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�����ֽ�"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== "strike" || usage=="parry"; }
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
    level = (int)me->query_skill("wanxiang-strike",1);
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
