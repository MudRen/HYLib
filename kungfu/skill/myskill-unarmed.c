// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// wall
// ��������
// �һ����ڶ�������
// 3205831
// ����
// unarmed
// ������





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nͻ���ڿն���,����һ����׵Ľ����ơ���������,�ƺ�֮ˮ������......��һʽ�.������Ӱ��ƺ�����һ��ӿ��$n������·.",
"force" :60,
"dodge" :40,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "������"
]),
// ZHAOSHI :1

([
"action" :"$N�������,ȴ�����������ȫ������,һ�ɰ�ɫ��������ȫ������,$Nͻ��˫����ǰ����,ʹ��һʽ��������Ե��ľ�����$n��ͷ����ȥ.",
"force" :90,
"dodge" :60,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "���׷�"
]),
// ZHAOSHI :2

([
"action" :"$N��׼��϶,���һԾ,���Ž����Ƶĵ����䡰���������辡��,Īʹ���׿ն��¡�ʹ������ʽ���˫�ֺϳɾٱ�״,���¶�������$n���ؿ�.",
"force" :120,
"dodge" :80,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "�ն���"
]),
// ZHAOSHI :3

([
"action" :"$Nһ�С���������ˮ������Ծ��ٿ��������$n���˫�ּ���,��һ���������Ҳı�����,ǧ��ɢ��������.������һ��һ�������$n�ı���.����һʽ�.",
"force" :150,
"dodge" :100,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "������"
]),
// ZHAOSHI :4

([
"action" :"$N��¶΢Ц,�ƺ������������һ��,$n�������֮ʱ,һ���.һ��ǿ�����������಻���ѹ���$n��������,$nȴ��֪$N��ʱ����.$N�������������ţ��Ϊ��,����һ�����ٱ���.",
"force" :180,
"dodge" :120,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "��Ϊ��"
]),
// ZHAOSHI :5

([
"action" :"$N������״����ǰ��ʽ�Ͷ�Ϊһ�����л�����һʽ�������ơ���$N�����������᯷��ӣ��������������ƣ���Īͣ����$nֻ�����������޴�����ԥ֮ʱ������ǿ�������Ѿ�����$n��ȫ������",
"force" :210,
"dodge" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "������"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"������"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"������"+"��\n");
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
    level = (int)me->query_skill("myskill-unarmed",1);
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
