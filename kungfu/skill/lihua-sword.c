// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// lting
// �L���滨
// �����滨���滨����
// 5007289
// Ů��
// sword
// �����滨





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N����ббһ����ѩ�������$n���ŵ������滨���㣬��㱼��ĳ�������һ�����͸����滨����Ʈ����ǰ��",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "���滨���֡�"
]),
// ZHAOSHI :1

([
"action" :"$N����������Ů��Я澣����滨һ֦��Ц�ݿɾϣ��ݻ������������콣���к���һŮ�ӣ��������裬Ȼ��������ֱ��$n��ԭ�Ǻ���Ӥ����",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "�������黨��"
]),
// ZHAOSHI :2

([
"action" :"$N���΢¶������һ�����ӭ�������$n˫�۳��أ�����δ��֮�䣬���о����Ķ��滨�����̻�䣬�������ܾ��Ƶ�һ�������",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "���綯�滨��"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�����滨"+"��\n");
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
    level = (int)me->query_skill("lihua-sword",1);
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
