// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// anima
// ��ϣ��
// �һ����ڶ�������
// 3485243
// ����
// sword
// ����ʮ��֧





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N�·�������Ѫ���ȷ�֮��,���¶��һ�����Ե����������˵�΢Ц,$n������,����ʯ��,$n�Ա�$N����$w����ĳ��",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "����Ϸ����"
]),
// ZHAOSHI :1

([
"action" :"$w�ٿշ����ڿ��л���һ����â����,���ͬʱ,$N����ħ��,˲�佫��������������,$n�о��Լ��·������ڰ��ǵ������ܶ���,$w����������䴩$n������.",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "��â����"
]),
// ZHAOSHI :2

([
"action" :"ħ���ķ�Χ���ڲ�������,$N�����е�$w�ѻ��������Ĺ���ʹ��,$n�����ֶ����������˿�.",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "ħӰ����"
]),
// ZHAOSHI :3

([
"action" :"$w�������,��ʧ����Ӱ����....,$n��$N˲�佻���˰�ȭʮ����,�ƺ��ƾ�����,�ɾ�������Ҫ���Ĺ�ͷ$w�������ʹ���������̴�$n������.",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "������ʹ"
]),
// ZHAOSHI :4

([
"action" :"$w�ٴδ�$N���зɳ�,��!$n��Ϊ$N�ʼ�����,�����ڹ�׼����������һ��,$w��,$N����!!!һֻ����ħ���ĺ���ѹ��$n����,���ƻ�������,ͬ��$w�����ؿ�.",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "˭���"
]),
// ZHAOSHI :5

([
"action" :"�o�f����,ʱ�o�f,�՟o�f,���ߟo�f,���������,�������,�����ռ�֮�o�f.$N���й�һ������$w�����ݻ���$n.",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "�޼��"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"����ʮ��֧"+"��\n");
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
    level = (int)me->query_skill("flowers-sword",1);
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
