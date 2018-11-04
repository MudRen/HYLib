// yizhi-chan.c һָ��
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action" : "$N˫ָ��£��һʽ�������������������ϣ�������һǰһ�����$n
���ظ���",
    "force" : 160,
    "dodge" : -5,
    "parry" : -5,
    "damage": 310,
    "lvl" : 0,
    "skill_name" : "�������",
    "damage_type" : "����"
]),
([      "action" : "$N���ƻ��أ�һʽ��������ա���������ָǰ���˸��뻡���͵�һ
˦������$n��$l",
    "force" : 120,
    "dodge" : 10,
    "parry" : 15,
    "damage": 230,
    "lvl" : 20,
    "skill_name" : "�������",
    "damage_type" : "����"
]),
([      "action" : "$N����������һʽ�����Ź�ɡ���˫��ʳָ�˲������һ����������
��$n��ȫ��ҪѨ",
    "force" : 240,
    "dodge" : 20,
    "parry" : 20,
    "damage": 260,
    "lvl" : 40,
    "skill_name" : "���Ź��",
    "damage_type" : "����"
]),
([      "action" : "$N��ϥ������һʽ�����ޱߡ���������ȭ���⣬����Ĵֱָ����ң
ң����$nһ��",
    "force" : 480,
    "dodge" : 40,
    "parry" : 30,
    "damage": 290,
    "lvl" : 60,
    "skill_name" : "���ޱ�",
    "damage_type" : "����"
]),
([	"action" : "$N˫ָ��£��һʽ�����а����������������ϣ�������һǰһ����$n$l",
	"force" : 300,
        "dodge" : 30,
	"damage": 290,
	"weapon": "����ָ��",
	"lvl" : 5,
	"skill_name" : "���а���",
	"damage_type" : "����"
]),
([	"action" : "$N���ƻ��أ���Цһʽ��СƷ��������������ָǰ���˸��뻡������һ˦������$n$l",
        "force" : 350,
        "dodge" : 10,
        "damage": 290,
        "weapon": "����ָ��",
	"lvl" : 25,
	"skill_name" : "СƷ����",
        "damage_type" : "����"
]),
([	"action" : "$N����������һʽ�����ް�������˫��ʳָ�˲������һ����⣬����$n��ȫ��ҪѨ",
        "force" : 400,
        "dodge" : 10,
        "damage": 290,
        "weapon": "����ָ��",
	"lvl" : 45,
	"skill_name" : "���ް���",
        "damage_type" : "����"
]),
([	"action" : "$N��ϥ������һʽ���Ź��������ȫ������ܲ���������ȭ���⣬����Ĵֱָ����ңң����$nһ��",
        "force" : 450,
        "dodge" : -5,
        "weapon": "����ָ��",
	"damage": 290,
	"lvl" : 65,
	"skill_name" : "�Ź����",
        "damage_type" : "����"
]),
([	"action" : "$N��¶���࣬�������֣�����һ�µ����Ħڭ��������ƾ���������ߣ���������$n",
        "force" : 400,
        "dodge" : 15,
        "weapon": "����ָ��",
	"damage": 290,
	"lvl" : 105,
	"skill_name" : "Ħڭ����",
        "damage_type" : "����"
]),
([	"action" : "$N����𾭣���Ϣ���������������͹ģ�������գ�����ָһʽ����հ�����������$n��ȥ",
        "force" : 500,
        "dodge" : 20,
        "weapon": "����ָ��",
	"damage": 290,
	"lvl" : 155,
	"skill_name" : "��հ���",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }    

int valid_combine(string combo) { return combo=="banruo-zhang"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("��һָ��������֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧһָ����\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷���һָ����\n");
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
    level   = (int) me->query_skill("yizhi-chan",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("�������������һָ����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"yizhi-chan/" + action;
}

mixed hit_ob(object me, object target)
{
    string msg;
    int j;
    j = me->query_skill("yizhi-chan", 1);
   
    if( random(20) >= 15 && !target->is_busy() && j > 100 &&
       me->query("neili") > target->query("neili") &&
       me->query("neili") > 1000 && me->query("max_neili") > 1500 &&
        j > random(target->query_skill("dodge",1))){
          switch(random(2)){
            case 0 :
               msg = "$N����������һʽ�����Ź�ɡ���˫��ʳָ�˲������һ������������$n��ȫ��ҪѨ��\n";
               msg += "$nֻ��ȫ��һ�飬�ѱ���һ�С����Ź�ɡ����У�\n"; 
               target->start_busy(3);
               break;
            case 1 :
               msg = "$N˫ָ��£��һʽ�������������������ϣ�������һǰһ�����$n���ظ��䣡\n";
               msg += "���$n��Ѫһ�ͣ��ѱ����ڵ��á�\n";
               target->start_busy(3);
               break;
            
            }         
        message_vision(msg, me, target);
        }
}