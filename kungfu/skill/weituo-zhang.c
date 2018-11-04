/* 
   weituo-zhang.c Τ����
   ����Ӱ������(ruying-suixingtui)����
   ���ԡ�����ȭ������ȡ��ʮһ��ʮ����ʮ������ʮ��ʽ��
   1/3/98 by snowman
*/

inherit SKILL;

mapping *action = ({
([	"action" : "$N�������ֱ���ɹ�����վ����һ�С�ӭ���мܡ������ַ����ϼܣ�����˳��ѹ���·�",
	"force" : 50,
        "dodge" : 45,
	"lvl" : 0,
	"skill_name" : "ӭ���м�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���ѹ�崷�����ҽ�ԭ�ض岽��ʹ����ת���������������ѹ��������ǰֱ��$n",
	"force" : 60,
        "dodge" : 35,
	"lvl" : 0,
	"skill_name" : "��ѹ�崷",
	"damage_type" : "����"
]),
([	"action" : "$N���š�ת�����ء���˳��������ת֮�ƣ�����ȭ�������ƣ�˫�ֽ��棬��$n��������",
	"force" : 70,
        "dodge" : 25,
	"lvl" : 20,
	"weapon" : "��Ե",
	"skill_name" : "ת������",
	"damage_type" : "����",
]),
([	"action" : "$N�ҽ�����̤����ʹ��������ҷ���һ�С������崷���������ֿ��������ֻ�����$nȦ�����",
	"force" : 80,                                    
        "dodge" : 20,
	"lvl" : 20,
	"skill_name" : "�����崷",
	"damage_type" : "����"
]),
([	"action" : "$Nһʽ��������������������ת�������������������ؿ�ס���ʣ�����˳����$n$l����",
	"force" : 100,
        "dodge" : 25,
	"lvl" : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N��һ�С������崷��������˳����ǰȦ�ɶ���������������ת֮�ƣ����ֻ�����$nֱ������",
        "force" : 120,
        "dodge" : 15,
	"lvl" : 40,
	"skill_name" : "�����崷",
	"damage_type" : "����"
]),
([	"action" : "$N�ҽ������䲽���Խż������棬һ�С��粽���ҡ�������һֱ���粻�����������ҷ�������",
        "force" : 140,
        "dodge" : 15,
	"lvl" : 60,
	"skill_name" : "�粽����",
	"damage_type" : "����"
]),
([	"action" : "$N˫��˳��ת����ԭ�ض岽���ɹ�����վ����һ�С�����б�򡹣����ֻ��ƣ���$n$l����",
        "force" : 160,
        "dodge" : 30,
	"lvl" : 60,
	"weapon" : "����",
	"skill_name" : "����б��",
	"damage_type" : "����"
]),
([ 	"action" : "$N����ԭ�����³���������һ�С�������ҡ�����ȭ�������ϥǰ������������Ӳ��",
        "force" : 180,
        "dodge" : 15,
	"lvl" : 80,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����мܡ�������ų�ֱ���ɹ�����վ������ȭ˳�Ʒ��⣬��$n�ܳ�",
        "force" : 210,
        "dodge" : 20,
	"lvl" : 100,
	"skill_name" : "����м�",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { 
	if(this_player()->query_skill("weituo-zhang", 1) > 150
	   && this_player()->query_int() > 20)
   	         return combo=="shaolin-tantui"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��Τ���Ʊ�����֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��ı����ڹ���򲻹����޷���Τ���ơ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���Τ���ơ�\n");
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
	level   = (int) me->query_skill("weituo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
	  if(level > action[i-1]["lvl"])
	      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������Τ���ơ�\n");
	me->receive_damage("jing", 25);
	me->add("neili", -5);
	return 1;
  }

