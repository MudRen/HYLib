// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// mylove
// ����������
// ���ŵھŴ�����
// 24763463
// ����
// sword
// ����͸�ǽ�





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N��Ȼ����һ�䣬���еĳ���������������Ӱ���ֱ�Ϯ��$n��ҪѨ����һ��������Ѩ",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "����͸�ǽ�"
]),
// ZHAOSHI :1

([
"action" :"$N��Ȼ����һ�䣬���еĳ���������������Ӱ���ֱ�Ϯ��$n��ҪѨ����һ�����н�Ѩ",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "����͸�ǽ���"
]),
// ZHAOSHI :2

([
"action" :"$N��Ȼ����һ�䣬���еĳ���������������Ӱ���ֱ�Ϯ��$n��ҪѨ����һ��������Ѩ",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "����͸�ǽ���"
]),
// ZHAOSHI :3

([
"action" :"$N��Ȼ����һ�䣬���еĳ���������������Ӱ���ֱ�Ϯ��$n��ҪѨ�����Ľ�������Ѩ",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "����͸�ǽ���"
]),
// ZHAOSHI :4

([
"action" :"$N��Ȼ����һ�䣬���еĳ���������������Ӱ���ֱ�Ϯ��$n��ҪѨ�����彣���Ϲ�Ѩ",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "����͸�ǽ���"
]),
// ZHAOSHI :5

([
"action" :"$N��Ȼ����һ�䣬���еĳ���������������Ӱ���ֱ�Ϯ�����ǵ�ҪѨ�����������������꣡",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "����͸�ǽ���"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"����͸�ǽ�"+"��\n");
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
    level = (int)me->query_skill("mysword-sword",1);
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
