// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xlssi
// ЦĪ��
// �ɻ�С��
// 8556053
// ����
// unarmed
// ��ȭ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nһ��ʼ�ʶ�����,˫ȭƽƽ����$n����������·,���ϲ�ŭ����,���к�ɨ����,ƽ���ķ��İ���",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "ʼ�ʶ�����"
]),
// ZHAOSHI :1

([
"action" :"$N���о������,һʽ����ն����,��ȭΪ��,Ю��һ���治�����ھ�,����$n��$l",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "����ն����"
]),


// ZHAOSHI :2

([
"action" :"$N���ƻ�����ȭ,���һ���,��Ȼ˫�����,����$n��$l,һʽ�ϵ¶��������˶���Ŀѣ,�޴��м�.",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "�ϵ¶�����"
]),
// ZHAOSHI :3

([
"action" :"$Nһʽ�ĵ��¼ں�,��¶����֮ɫ,˫�ֻ�����$n��ȥ,������������֮��",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "�ĵ��¼ں�"
]),
// ZHAOSHI :4

([
"action" :"$N�ĳ��ֺ�Ȼȫ�ް�����,����ɱ��,����ս��,��$n��������,�������",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "̫��������"
]),
// ZHAOSHI :5

([
"action" :"$N˫����ת���,һ����̫���������,$n��Բ���ɽԱ��ȷ��Χ",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "��������"
]),
// ZHAOSHI :6

([
"action" :"$N����Ϊ��,ֱ��$n��$l,һʽ�乭�������ųɼ�˼��ƽ�����µĿ��",
"force" :240,
"damage" :160,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "�乭���"
]),
// ZHAOSHI :7

([
"action" :"��Ȼ���һƬ��ɱ,$N����Ԫ�ɱ����Ȼ����,����ɱ���ھ�ֱ��$n��$l",
"force" :270,
"damage" :180,
"damage_type": "����",
"lvl" : 7,
"skill_name" : "ɱ��"
]),
// ZHAOSHI :8

([
"action" :"$N����Ϣ��תȫ��,�޴���й,���һ��,������ʹ���˻�ȭ�Ĳ���֮��----��Ǭʢ��,",
"force" :300,
"damage" :200,
"damage_type": "����",
"lvl" : 8,
"skill_name" : "��Ǭʢ��"
]),
// ZHAOSHI :9

([
"action" :"$N��ǰ��δ��,�������Լ��Ļ�ȭ,�����ޱ�,һȭ����$n��$l",
"force" :330,
"damage" :220,
"damage_type": "����",
"lvl" : 9,
"skill_name" : "��ȭ"
]),
// ZHAOSHI :10

([
"action" :"$Nһ�о�,�ʵ������������,ֱָ$n",
"force" :360,
"damage" :240,
"damage_type": "����",
"lvl" : 10,
"skill_name" : "��"
]),
// ZHAOSHI :11

([
"action" :"$Nһ����,$nֻ����$N�������޴�����,������ʱ,������������",
"force" :390,
"damage" :260,
"damage_type": "����",
"lvl" : 11,
"skill_name" : "��"
]),
// ZHAOSHI :12

([
"action" :"$Nһ����,�Ѿ�����ػ�Ϊһ��,�޷���϶,������������$n",
"force" :420,
"damage" :280,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "��"
]),
// ZHAOSHI :13

([
"action" :"$Nһ����,���ΰθ�����,������֮��,˫ȭ����$n�Ķ���",
"force" :450,
"damage" :300,
"damage_type": "����",
"lvl" : 13,
"skill_name" : "��"
]),
// ZHAOSHI :14

([
"action" :"$N��ͷڤ�룬һ�к�,����������,����$n",
"force" :480,
"damage" :320,
"damage_type": "����",
"lvl" : 14,
"skill_name" : "��"
]),
// ZHAOSHI :15

([
"action" :"$Nһ����˫�ƻγ�ǧ����Ӱ��$n��$l����������֮��",
"force" :510,
"damage" :340,
"damage_type": "����",
"lvl" : 15,
"skill_name" : "��"
]),
// ZHAOSHI :16

([
"action" :"$N����ǰ��һ����,�������ȣ��Կ������һ��ת���Ѿ�ת����$n�������ָ������$n��ȫ��ҪѨ",
"force" :540,
"damage" :360,
"damage_type": "����",
"lvl" : 16,
"skill_name" : "��"
]),
// ZHAOSHI :17

([
"action" :"$Nһ����,$n������·,��Ȼ$N�ó�����һ˿",
"force" :570,
"damage" :380,
"damage_type": "����",
"lvl" : 17,
"skill_name" : "��"
]),
// ZHAOSHI :18

([
"action" :"$Nһ�������޵�,˫ȭ����$n��$l",
"force" :600,
"damage" :400,
"damage_type": "����",
"lvl" : 18,
"skill_name" : "�����޵�"
]),
// ZHAOSHI :19

([
"action" :"$Nһ�������,��Ů��״,$n��������,����һ�����,�Ѿ�������������",
"force" :630,
"damage" :420,
"damage_type": "����",
"lvl" : 19,
"skill_name" : "�����"
]),
 });
// ZHAOSHI :20
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"��ȭ"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"��ȭ"+"��\n");
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
    level = (int)me->query_skill("emperor-unarmed",1);
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
