// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// qing
// ����Ũ
// [35m���ϵ�һŮ��[2;37;0m
// 11768727
// Ů��
// unarmed
// �����Ʒ�





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nʹ��һʽ�������ϻء���һ���׹��ѵ�$n��ü������$N����һת����һʽ����Ҷ�Է��꡹��$nȫ�������ڽ����С�",
"force" :60,
"damage" :40,
"damage_type": "����",
"lvl" : 0,
"skill_name" : "�����ϻ�"
]),
// ZHAOSHI :1

([
"action" :"ֻ��$N����һ�䣬��ʱ�����������֣����������������罭�Ϻ�����ʽ����������˫�ƺ������ˣ�$n������·",
"force" :90,
"damage" :60,
"damage_type": "����",
"lvl" : 1,
"skill_name" : "�������"
]),
// ZHAOSHI :2

([
"action" :"$N�ڰ��һ��Ư���Ļ�����������ʽ�������γ�����������δ�����������̣���������һ���̹⴩��$n����",
"force" :120,
"damage" :80,
"damage_type": "����",
"lvl" : 2,
"skill_name" : "�����γ�"
]),
// ZHAOSHI :3

([
"action" :"ֻ��$N�������ڿ��л���һ�������Ļ��ߣ�һʽ����ҶƮ�㡹�������ĳ��žŰ�ʮһ�ƣ�������ӰƮ���Ҷ���䣬$n����˲���Ѥ��������",
"force" :150,
"damage" :100,
"damage_type": "����",
"lvl" : 3,
"skill_name" : "��ҶƮ��"
]),
// ZHAOSHI :4

([
"action" :"$N��̾һ��������΢΢һɨ��һʽ�����է�𡹷�����$n��ʱ�е����������������ɲ������������Ȥ������������������",
"force" :180,
"damage" :120,
"damage_type": "����",
"lvl" : 4,
"skill_name" : "���է��"
]),
// ZHAOSHI :5

([
"action" :"$N�п��������������أ�˫���ֻӣ������Ʒ���ʮ��ʽ�ռ��������ﺮ��Ȼ������������һʱ��������$n�����´�����ƣ�����һʱ��������$n�����ٳ�����",
"force" :210,
"damage" :140,
"damage_type": "����",
"lvl" : 5,
"skill_name" : "�ﺮ��Ȼ"
]),
// ZHAOSHI :6

([
"action" :"$Nһ�С���Ӱ���Ρ��������߳���$nȴ�������ɿ��⣬����$N˲��ǰ�����ɣ����ѻ���$n�ؿڣ�����δ�������ֳ���һ������ɨ��$n����",
"force" :240,
"damage" :160,
"damage_type": "����",
"lvl" : 6,
"skill_name" : "��Ӱ����"
]),
// ZHAOSHI :7

([
"action" :"����������Ӱ���裬$n�������ѱ��ȷ�˺��һƬƬ��ɢ����ϣ�$N����һԾ��һʽ��������硹������������Ƚ�������$n�ؿ�",
"force" :270,
"damage" :180,
"damage_type": "����",
"lvl" : 7,
"skill_name" : "�������"
]),
// ZHAOSHI :8

([
"action" :"����ɨ��Ҷ����$N���Ⱥ�ɨ$n���ţ�$n��æ�е�ͷ�ܹ����������ѱ�ɨ�䣬�Ǳ�����������$N����$n������������������һ�������ͷ�ɨ���ŵװ�ֱ��$n�°�",
"force" :300,
"damage" :200,
"damage_type": "����",
"lvl" : 8,
"skill_name" : "��ɨ��Ҷ"
]),
// ZHAOSHI :9

([
"action" :"$N�������ڰ�ռ�����ת����Ȼһ����ת���·������ͣ��죡�棡�ˣ�Ը��$N����Ѿ�����$n���ؿڣ��ҽ�ȴֱ���Ըǣ�����Ҫ�Ǳ����У�$n�ǵ߼�ɵ",
"force" :330,
"damage" :220,
"damage_type": "����",
"lvl" : 9,
"skill_name" : "������Ը"
]),
// ZHAOSHI :10

([
"action" :"��Ȼ����ؼ�һƬ�ž���$Nһͷ����ĳ������Ժ󾲾�ɢ�䣬С�������ƣ������棡�ˣ��⣡$N�ĳ����ٴ�Ʈ��������$n��û�����$N�ĳ���",
"force" :360,
"damage" :240,
"damage_type": "����",
"lvl" : 10,
"skill_name" : "��������"
]),
// ZHAOSHI :11

([
"action" :"ֻ��$Nһͷ�������Ժ���費ͣ����ӰƮ���䣬��棡�ң��⣡�����߳�һʮ���ȣ�$nһ���ѣ��ȴֻ��$N��ԭ��˫�ֺ�ʮ���·����ϵ��£�Ψ�����",
"force" :390,
"damage" :260,
"damage_type": "����",
"lvl" : 11,
"skill_name" : "��������"
]),
// ZHAOSHI :12

([
"action" :"$n�������⣬�������ܣ�$N���һ�������󱲣��󵨣�����һ�С�ȱ�¹���ͩ������ָ�ſ���ֱץ$n�������",
"force" :420,
"damage" :280,
"damage_type": "����",
"lvl" : 12,
"skill_name" : "ȱ�¹���ͩ"
]),
// ZHAOSHI :13

([
"action" :"$n�ۿ��ܾ��Ѷ�����ߴߴ�����У�$Nһ���ȶϣ������죡������һʽ��©���˳���������$n����һ��������ȥ",
"force" :450,
"damage" :300,
"damage_type": "����",
"lvl" : 13,
"skill_name" : "©���˳���"
]),
// ZHAOSHI :14

([
"action" :"$n����һԾ�����ӵ����ɿ��⣬$Nһʽ�����˶���������˲������$n��ǰ����û��Ϣ��������Ϭ��һָ�㵽$nü��",
"force" :480,
"damage" :320,
"damage_type": "����",
"lvl" : 14,
"skill_name" : "���˶�����"
]),
// ZHAOSHI :15

([
"action" :"$N�������������Ʈ��º�Ӱ����˲��Χ��$n��ת�žŰ�ʮһȦ��$nһ���ۻ����ң��ε��ڵ�",
"force" :510,
"damage" :340,
"damage_type": "����",
"lvl" : 15,
"skill_name" : "Ʈ��º�Ӱ"
]),
// ZHAOSHI :16

([
"action" :"$N����������ʩ�������Ṧ������ȴ��ͷ����˲����$n��ǰ����ƶ���$nһ���ѣ��Ż������",
"force" :540,
"damage" :360,
"damage_type": "����",
"lvl" : 16,
"skill_name" : "����ȴ��ͷ"
]),
// ZHAOSHI :17

([
"action" :"$N��ת����������������䣬��ȥ���ɣ���������$Nһʽ����įɳ���䡹��ȫ����������һ��ǿ���������ֱ��$n",
"force" :570,
"damage" :380,
"damage_type": "����",
"lvl" : 17,
"skill_name" : "��įɳ����"
]),
 });
// ZHAOSHI :18
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��"+"�����Ʒ�"+"������֡�\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������̫�����޷���"+"�����Ʒ�"+"��\n");
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
    level = (int)me->query_skill("qing-unarmed",1);
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
