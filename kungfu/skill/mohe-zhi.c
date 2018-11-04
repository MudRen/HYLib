/* 
   mohe-zhi.c Ħڭָ
   �Ͳ�������(boluomi-shou)����
   �������С��Դȶ��ģ�Ħڭ������һ�䡣
   2/3/98 by snowman
*/


inherit SKILL;

mapping *action = ({
([	"action" : "$N����һ�ڣ�������ǰ����������ʳָ����һ�����ԡ��֣��������$n$l",
	"force" : 100,
        "dodge" : 25,
	"lvl" : 0,
	"skill_name" : "��",
	"damage_type" : "����"
]),
([	"action" : "$N����ʳָ�������˸����ȡ��֣�������ָ΢��������Ϊ���ģ�����$nһ��",
	"force" : 130,
        "dodge" : 20,
        "weapon" : "ָ��",
	"lvl" : 20,
	"skill_name" : "��",
        "damage_type" : "����"
]),
([	"action" : "$N˫�ƺ�ʮ������΢Ƿ��˫ָ��һ���ȡ��֣���Ʋ����������������֦�㣬����$n$l",
	"force" : 150,
        "dodge" : 15,
        "weapon" : "ָ��",
	"lvl" : 30,   
        "skill_name" : "��",
        "damage_type" : "����"
]),
([	"action" : "$N˫��Сָ��$n�Ӷ����������㣬����˫ָ��£��һ��б����ƴ����һ�����ġ���",
	"force" : 180,
        "dodge" : 20,
        "weapon" : "˫ָ",
	"lvl" : 50,
	"skill_name" : "��",
        "damage_type" : "����"
]),
([	"action" : "$N�������У��ó�����ָӰ���·�侹Ȼ�γ���һ����Ħ���֣�����$n�����ȥ��Խ��Խ��",
	"force" : 210,
        "dodge" : 5,
	"lvl" : 60,
	"skill_name" : "Ħ",
        "damage_type" : "����"
]),
([	"action" : "$N����ʳָ������ڿ���д������ڭ�������������ݣ�����$n���һ��ʱ�������һ������",
	"force" : 240,
        "dodge" : 10,
        "weapon" : "ָ��",
	"lvl" : 70,
	"skill_name" : "ڭ",
        "damage_type" : "����"
]),
([	"action" : "ֻ��$N��ָ������������ָ���ڿ������᲻ɢ���γ�һ�����ޡ��֣�����$n����ѹ��",
	"force" : 270,
        "dodge" : 0,
	"lvl" : 80,
	"skill_name" : "��",
        "damage_type" : "����"
]),
([	"action" : "$N˫ȭ��£���г�һ����������������������$n��ͻȻ�°���һ�䣬����һָ�ƿջ���",
	"force" : 300,
        "dodge" : 5,
	"lvl" : 100,
	"skill_name" : "��",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo){
        if(this_player()->query_skill("mohe-zhi", 1) > 100
	   && this_player()->query_int() > 20)
   	         return combo=="boluomi-shou";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��Ħڭָ������֡�\n");
        if ((int)me->query_skill("yijinjing", 1) < 100)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧĦڭָ��\n");
        if ((int)me->query("max_neili") < 1200)
		return notify_fail("�������̫�����޷���Ħڭָ��\n");

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
	level   = (int) me->query_skill("mohe-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������Ħڭָ��\n");
	me->receive_damage("jing", 40);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
         return __DIR__"mohe-zhi/" + action;
}
