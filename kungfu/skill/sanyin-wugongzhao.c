//sanyin-wugongzhao.c �������ץ
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$Nצ����ף��ǽ�¡�����϶���˺��$n��$l",
    "force" : 120,
    "dodge" : 10,
    "damage": 230,
    "damage_type" : "ץ��"
]),
([  "action" : "$N˫�ֺ������֣�צצ���Ȱ�ץ��$n��$l",
    "force" : 150,
    "dodge" : 20,
    "damage": 245,
    "damage_type" : "ץ��"
]),
([  "action" : "$N����Χ$nһת��צӰ�ݺ�����������$n��$lץ��",
    "force" : 180,
    "dodge" : 30,
    "damage": 255,
    "damage_type" : "ץ��"
]),
([  "action" : "$Nһ���ֽУ�һצ���ֱ��$n�������",
    "force" : 440,
    "dodge" : 50,
    "damage": 500,
    "lvl"   : 100,
    "skill_name" : "Ψ�Ҷ���" ,
    "damage_type" : "ץ��"
]),
([      "action": "$Nһʽ������̲�����������Σ����ֻ�צ�����μ��£�ͻȻ��$n�ı����Ѩץȥ",
        "dodge": 5,
        "force": 150,
    "damage": 155,
        "lvl" : 4,
        "damage_type": "ץ��"
]),

([      "action": "$N����һ�Σ�ʮָ���裬Ю��һ�ɴ�ָ��ð����������$n��$l������ȥ",
        "dodge": 15,
        "force": 190,
    "damage": 155,
        "lvl" : 14,
        "weapon" : "ָ��",
        "damage_type": "����"
]),

([      "action": "$Nһʽ���������������צָ�����ֱ�һ�ӣ����־Ϳ���$n���ʺ�Ҫ��",
        "dodge": 5,
        "force": 280,
    "damage": 255,
        "lvl" : 23,
        "limb" : "�ʺ�",
        "damage_type": "ץ��"
]),

([      "action": "$N��Ʈ�����Ի�$n����������бб̽�������ݵ�ץ��$n��$l",
        "weapon" : "��צ",
        "dodge": 10,
        "force": 230,
        "damage" : 240,
        "lvl" : 44,
        "damage_type": "ץ��"
]),

([      "action": "$Nһʽ������β����ʮָ����������ɭɭ���⣬����ʵʵ��Ϯ��$n��ȫ��ҪѨ",
        "dodge": 7,
        "force": 300,
    "damage": 155,
        "lvl" : 63,
        "damage_type": "����"
]),

([      "action": "$N������Ц������ɳ���ʮָ�������֣��������ޣ�������ץ��$n��$l",
        "dodge": 15,
        "force": 380,
    "damage": 155,
        "lvl" : 85,
        "damage_type": "ץ��"
]),

([      "action": "$N��Цһ���������з緢��һ�㣬˫�������趯����������צӰֱϮ$n��$l",
        "weapon" : "��צ",
        "damage" : 230,
        "dodge": 10,
        "force": 420,
        "lvl" : 101,
        "damage_type": "ץ��"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="chousui-duzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("���������צ������֡�\n");
        if ((int)me->query("max_neili") < 200)
            return notify_fail("�������̫�����޷����������צ��\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("sanyin-wugongzhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	object* ob;
	int i,skill,damage;

	skill = me->query_skill("sanyin-wugongzhao",1);
                if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������������צ��\n");
	me->receive_damage("qi", 30);
        me->add("neili", -20);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{

	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 10) / 2 );
		return HIR "��������������һ�����죬�����ǹ����������\n" NOR;
	}
}
string perform_action_file(string action)
{
    return __DIR__"sanyin-wugongzhao/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("huagong-dafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$Nʹ��������,$n��������ѩ���ڻ�һ������ʧ�ˡ���\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}