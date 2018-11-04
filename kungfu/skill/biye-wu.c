// biye-wu.c ��Ҷ�����
#include <ansi.h>
inherit SKILL;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"tmzhuihun_poison",
"tmpili_poison",
"zm_poison",
});



mapping *action = ({
([	"action" : "$N˫��������ƮƮһʽ��Ҷ�䡹��������Ҷ����$n��$l��ȥ",
	"force" : 60,
        "damage" : 190,
	"dodge" : 82,
	"skill_name" : "Ҷ��",
	"lvl" : 0,
        "damage_type" : "����"
]),
([	"action" : "$N���Ϊ���ģ��ҽ�һ����˫�ֽ�����裬����Ҷ���ɣ����ǡ�Ҷ�衹����$n��$l����",
	"force" : 80,
	"dodge" : 80,
"damage" : 190,
	"skill_name" : "Ҷ��",
	"lvl" : 20,
        "damage_type" : "����"
]),
([	"action" : "$N����߸�Ծ������������ǰ���ұ�΢����ʹһ�С�ҶƮ�㡹����$n��$l�����Ŵ�ȥ",
	"force" : 100,
	"dodge" : 82,
"damage" : 190,
	"skill_name" : "ҶƮ��",
	"lvl" : 40,
        "damage_type" : "����"
]),
([	"action" : "$N΢һ�˾���˫����¶��һʽ����Ҷ������$n�������¶�������������Ӱ֮��",
	"force" : 200,
	"dodge" : 94,
"damage" : 190,
	"skill_name" : "��Ҷ",
	"lvl" : 60,
        "damage_type" : "����"
]),
([	"action" : "$N˫��ƽ̯�����ƻ��������磬��������ǰ�Ƴ���\n�Ʒ�����ƿ�����һ�С���֦��������֦������ֱ��$n���Ѷ�ȥ",
	"force" : 300,
	"dodge" : 96,
"damage" : 300,
	"skill_name" : "��֦",
	"lvl" : 80,
        "damage_type" : "����"
]),
([	"action" : "$NͻȻ���ƣ��ɸ�����ǰ�����Ƴ����Ʒ����Σ�һʽ��Ҷ�糱����һƬ����ֱ��$n",
	"force" : 500,
"damage" : 300,
	"dodge" : 88,
	"skill_name" : "Ҷ�糱",
	"lvl" : 100,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ҷ����������֡�\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 30)
		return notify_fail("��ı����ķ���򲻹����޷�ѧ��Ҷ����衣\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����Ҷ����衣\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

///* ----------------
//mapping query_action(object me, object weapon)
//{
//	return action[random(sizeof(action))];
//}
//-------------------*/

mapping query_action(object me, object weapon)
{
	int i, level;
    level   = (int) me->query_skill("biye-wu",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ҷ����衣\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"biye-wu/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("biyun-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "biyun-xinfa")
{
            victim->receive_damage("qi",20);
            victim->receive_wound("qi",15 + random(10));
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$NͻȻ���ƣ�Ȼ��Ѹ�ٷ���! ���о�Ȼ�ж�ɰ�����Ʒ羡Ȼ��������ɫ�ģ�$nӲ��ͷƤ������Ӳ�ӣ���������о޶���!\n";
}
 
}