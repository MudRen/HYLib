// weituo-gun.c Τ�ӹ�
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([	"action" : "$N�������ֱ���ɹ�����վ����һ�С�ӭ���мܡ������ַ����ϼܣ�����˳��ѹ���·�",
	"force" : 90,
        "dodge" : 45,
	"lvl" : 5,
	"skill_name" : "ӭ���м�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���ѹ�崷�����ҽ�ԭ�ض岽��ʹ����ת���������������ѹ��������ǰֱ��$n",
	"force" : 160,
        "dodge" : 35,
	"lvl" : 15,
	"skill_name" : "��ѹ�崷",
	"damage_type" : "����"
]),
([	"action" : "$N���š�ת�����ء���˳��������ת֮�ƣ�����ȭ�������ƣ�˫�ֽ��棬��$n��������",
	"force" : 170,
        "dodge" : 25,
	"lvl" : 25,
	"weapon" : "��Ե",
	"skill_name" : "ת������",
	"damage_type" : "����",
]),
([	"action" : "$N�ҽ�����̤����ʹ��������ҷ���һ�С������崷���������ֿ��������ֻ�����$nȦ�����",
	"force" : 80,                                    
        "dodge" : 120,
	"lvl" : 25,
	"skill_name" : "�����崷",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ��������������������ת�������������������ؿ�ס���ʣ�����˳����$n$l����",
	"force" : 100,
        "dodge" : 125,
	"lvl" : 45,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N��һ�С������崷��������˳����ǰȦ�ɶ���������������ת֮�ƣ����ֻ�����$nֱ������",
        "force" : 120,
        "dodge" : 115,
	"lvl" : 45,
	"skill_name" : "�����崷",
	"damage_type" : "����"
]),
([	"action" : "$N�ҽ������䲽���Խż������棬һ�С��粽���ҡ�������һֱ���粻�����������ҷ�������",
        "force" : 140,
        "dodge" : 115,
	"lvl" : 65,
	"skill_name" : "�粽����",
	"damage_type" : "����"
]),
([	"action" : "$N˫��˳��ת����ԭ�ض岽���ɹ�����վ����һ�С�����б�򡹣����ֻ��ƣ���$n$l����",
        "force" : 160,
        "dodge" : 130,
	"lvl" : 65,
	"weapon" : "����",
	"skill_name" : "����б��",
	"damage_type" : "����"
]),
([ 	"action" : "$N����ԭ�����³���������һ�С�������ҡ�����ȭ�������ϥǰ������������Ӳ��",
        "force" : 180,
        "dodge" : 115,
	"lvl" : 85,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����мܡ�������ų�ֱ���ɹ�����վ������ȭ˳�Ʒ��⣬��$n�ܳ�",
        "force" : 210,
        "dodge" : 120,
	"lvl" : 101,
	"skill_name" : "����м�",
	"damage_type" : "����"
]),
([      "action":"$Nһ�С���ʯ���ġ�������$w�����ѵ�ˮ�㣬������$n������Ҫ����ȥ
",
    "force" : 160,
    "dodge" : 5,
    "parry" : 5,
    "damage": 40,
    "lvl" : 0,
    "skill_name" : "��ʯ����",
    "damage_type":"����"
]),
([      "action":"$N��$wƽ���ؿڣ�һš��һ�С�����ͣ�桹��$w�͵�����$n�ľ���",
    "force" : 180,
    "dodge" : 5,
    "parry" : 10,
    "damage": 65,
    "lvl" : 20,
    "skill_name" : "����ͣ��",
    "damage_type":"����"
]),
([      "action":"$Nһ�С�ƽ�����ɡ���ȫ���������ڵ��ϴ����ת���ٹ���$n���ظ�
���ȥ",
    "force" : 210,
    "dodge" : 5,
    "parry" : 15,
    "damage": 40,
    "lvl" : 60,
    "skill_name" : "ƽ������",
    "damage_type":"����"
]),
([      "action":"$N����һ��������һ�С��������硹��$wЮ��������Ѹ��ɨ��$n������
",
    "force" : 250,
    "dodge" : 15,
    "parry" : 5,
    "damage": 100,
    "lvl" : 60,
    "skill_name" : "��������",
    "damage_type":"����"
]),
([      "action":"$Nһ�С����Ǹ��¡��������һ�����˱Ƴ�һ��ֱ�ߣ����ǰ�����$n
��$l",
    "force" : 300,
    "dodge" : 20,
    "parry" : 15,
    "damage": 110,
    "lvl" : 80,
    "skill_name" : "���Ǹ���",
    "damage_type":"����"
]),
([      "action":"$N˫�ֳֹ����˸���ش�Ȧ��һ�С���ϼ���ա���һ����Բ�����л���
��ײ��$n���ؿ�",
    "force" : 350,
    "dodge" : 20,
    "parry" : 15,
    "damage": 125,
    "lvl" : 100,
    "skill_name" : "��ϼ����",
    "damage_type":"����"
]),
([      "action":"$Nһ�С�Ͷ�޶�������$w�߾٣����������֮�ƶ�׼$n�����鵱ͷ����
",
    "force" : 410,
    "dodge" : 25,
    "parry" : 20,
    "damage": 140,
    "lvl" : 120,
    "skill_name" : "Ͷ�޶���",
    "damage_type":"����"
]),
([      "action":"$NǱ��������һ�С������麣����$w��ʱ�������ɣ�������ֱ��$n����
��",
    "force" : 470,
    "dodge" : 30,
    "parry" : 25,
    "damage": 150,
    "lvl" : 150,
    "skill_name" : "�����麣",
    "damage_type":"����"
]),
});

int valid_enable(string usage) { return  (usage == "club") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
    return 1;
}

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
    level   = (int) me->query_skill("weituo-gun",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("�������������Τ�ӹ���\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"weituo-gun/" + action;
}
