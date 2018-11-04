//Cracked by Kafei
// chang-quan.c �䵱��ȭ
// xQin 12/98

inherit SKILL;

mapping *action = ({
([	"action": "$N����һ����Ƶ������ģ�ʹ�С�����ʽ���ӻ���ȥ",
	"force" : 80,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "����ʽ",
	"damage_type": "����"
]),
([	"action": "$N��ȭһ���������ڡ�������$n��ȥ",
	"force" : 100,
	"dodge" : -5,
	"lvl" : 10,
	"skill_name" : "������",
	"damage_type": "����"
]),
([	"action": "$Nһ����֦���沽��˫ȭ���ֱޡ�����$n$l��ȥ",
	"force" : 135,
	"dodge" : -10,
	"lvl" : 20,
	"skill_name" : "�ֱ�",
	"damage_type": "����"
]),
([	"action": "$N�������ӳ���Ӧ��һ�С�һ���ޡ��ͻ�$n$l����������",
	"force" : 120,
	"dodge" : 15,
	"lvl" : 30,
	"skill_name" : "һ����",
	"damage_type": "����"
]),
([	"action": "$N����̤��һ���������ұۣ�ʹ��һ�С��������������Ʒ�����$n$l��ȥ",
	"force" : 150,
	"dodge" : 10,
	"lvl" : 40,
	"skill_name" : "������",
	"damage_type": "����"
]),
([	"action": "$N������ǰ����������һ�С������֡���������$n��ȥ",
	"force" : 160,
	"dodge" : 30,
	"lvl" : 50,
	"skill_name" : "������",
	"damage_type": "����"
]),
([	"action": "$N˫��һ�֣�ʹ������ƽ�ġ������ӣ��������㣬������$nһȭ��ȥ",
	"force" : 180,
	"dodge" : 15,
	"lvl" : 60,
	"skill_name" : "ӡ��",
	"damage_type": "����"
]),
([	"action": "$N����һ����һ����ӡ�ơ����Ʒ��Ȼ����մ$n$l����һ���̾�������ȥ�ƻ���",
	"force" : 200,
	"dodge" : 0,
	"lvl" : 70,
	"skill_name" : "��ƽ��",
	"damage_type": "����"
]),
([	"action": "$Nͻ�����֣���$n$l��ȥ�����Ʒ������Ѹ鵽$pҸ�£�һ���������¡�����$p��ȥ",
	"force" : 223,
	"dodge" : 5,
	"lvl" : 80,
	"skill_name" : "������",
	"damage_type": "����"
]),
([	"action": "$Nʹ�С����ʽ���������ҽţ�һ��ԧ�������ȣ���������߳���ֱ��$n$l��ȥ",
	"force" : 250,
	"dodge" : 40,
	"lvl" : 90,
	"skill_name" : "���ʽ",
	"damage_type": "����"
]),
([	"action": "$Nһ�������ݲ������������棬̤��һ�����ѵ���$n�Ҽ�֮�࣬����һ�С����֡�����$p$l��ȥ",
	"force" : 280,
	"dodge" : 35,
	"lvl" : 100,
	"skill_name" : "����",
	"damage_type": "����"
]),
([	"action": "$N˫���ڻ���˳��ʹ��һ�С���������$n���������粨����ӿ����",
	"force" : 300,
	"dodge" : 20,
	"lvl" : 110,
	"skill_name" : "����",
	"damage_type": "����"
])
});

int valid_enable(string usage)
{
	return usage=="cuff" || usage=="parry";
}


int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��ϰ��ȭ������֡�\n");


	return 1;
}


int practice_skill(object me)
{
        if (me->query_skill("chang-quan",1) < 99)
           return notify_fail("�����ֻ�ܴ���һ�ټ�ʱ��ѧϰ��\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);
        return 1;
}


mapping query_action(object me, object weapon)
{
        int i, level;
        
        level   = (int) me->query_skill("chang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
