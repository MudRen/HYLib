// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xlssi
// ЦĪ��
// ��ȸ¥���ڶ�������
// 2000196
// ����
// blade
// Ӣ�۵�





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nʹ��Ӣ�۰˵��е�����ʽ�����������������е�$w����һ������ն��$n��$l",
"force" :60,
"dodge" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "��������"
]),
// ZHAOSHI :1

([
"action" :"$N��һ����һ�С��������ɡ����е�$w�ó����쵶��,ɢ��$n��$l",
"force" :90,
"dodge" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "��������"
]),
// ZHAOSHI :2

([
"action" :"$N�����ת�����е�$wһ�С������緢������ͬһ���������$n��$lб",
"force" :120,
"dodge" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "�����緢"
]),
// ZHAOSHI :3

([
"action" :"$N��Ӱ�ζ������������ң�һ�С�һ�򵱹ء������е�$w������·ͻȻ����$n��$l",
"force" :150,
"dodge" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "һ�򵱹�"
]),
// ZHAOSHI :4

([
"action" :"$N��˫�ŵ�أ���������һ�С�����Ī�С�ȫ��ת��һ�ŵ������$n��$l",
"force" :180,
"dodge" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "����Ī��"
]),
// ZHAOSHI :5

([
"action" :"$N�������ϣ�һ�С��Ѿ����족����һ��$n���벻���ĽǶ�����$n��$l",
"force" :210,
"dodge" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "�Ѿ�����"
]),
// ZHAOSHI :6

([
"action" :"$N���һ��,�����е�$w�������,$w��������,һ�С�Ӣ��ĩ·���������ޱߵ�Ӱ��$n��$l����Χס",
"force" :240,
"dodge" :160,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "Ӣ��ĩ·"
]),
// ZHAOSHI :7

([
"action" :"$Nʹ��Ӣ�۰�ʽ�е�����ʽ��˭��Ӣ�ۡ������������е�$w��Ϊһ��,���֮��ֻ��$NЦ��,Ц���к�Ȼһ��Ѹ���ޱȵؿ���$n��$l",
"force" :270,
"dodge" :180,
"damage_type": "����",
"lvl" : 7,
"skill_name" : "˭��Ӣ��"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"Ӣ�۵�"+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
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
    level = (int)me->query_skill("heroblade-blade",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade") return notify_fail("��ʹ�õ��������ԡ�\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
