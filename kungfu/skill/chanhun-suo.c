#include <ansi.h>

inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N����һ�һ��"+(order[random(13)])+"��ŰĿ��"NOR"������$w���ñ�ֱ��ֱ��$n��˫��",
        "force" : 110,
        "dodge" : 12,
        "parry" : 10,
        "damage": 235,
        "lvl"   : 0,
        "skill_name" : "ŰĿ",
        "damage_type": "����"
]),
([      "action": "$N������ң�һ��"+(order[random(13)])+"���˸Ρ�"NOR"������$w��������Ӱ����ɨ$n����",
        "force" : 140,
        "dodge" : 17,
        "parry" : 15,
        "damage": 250,
        "lvl"   : 20,
        "skill_name" : "�˸�",
        "damage_type": "����"
]),
([      "action": "$N��������һ��"+(order[random(13)])+"�����ġ�"NOR"������$w��һ��ͭ����ֱ��$n�ز�",
        "force" : 180,
        "dodge" : 21,
        "parry" : 19,
        "damage": 243,
        "lvl"   : 40,
        "skill_name" : "����",
        "damage_type": "����"
]),
([      "action": "$N����һ�ӣ�һ��"+(order[random(13)])+"���ߵ���"NOR"������$wֱ����$n����",
        "force" : 215,
        "dodge" : 32,
        "parry" : 27,
        "damage": 258,
        "lvl"   : 60,
        "skill_name" : "�ߵ�",
        "damage_type": "����"
]),
([      "action": "$N�߸�Ծ��һ��"+(order[random(13)])+"�����ǡ�"NOR"������$w��ֱ��$n��ͷ����",
        "force" : 255,
        "dodge" : 42,
        "parry" : 37,
        "damage": 275,
        "lvl"   : 80,
        "skill_name" : "����",
        "damage_type": "����"
]),
([      "action": "$N����һת��һ��"+(order[random(13)])+"���ջ꡹"NOR"������$w��������ڿ�һ���͵���$n��ͷ����",
        "force" : 330,
        "dodge" : 87,
        "parry" : 69,
        "damage": 281,
        "lvl"   : 100,
        "skill_name" : "�ջ�",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ�����ϰ��������\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("��Ļ����󷨻�򲻹�.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("����������צ��򲻹�.\n");



	if ((int)me->query_skill("chousui-zhang", 1) < 120)
		return notify_fail("��ĳ����ƻ�򲻹�.\n");


	if ((int)me->query_skill("tianshan-zhang", 1) < 120)
		return notify_fail("�����ɽ�ȷ���򲻹�.\n");


	if ((int)me->query_skill("zhaixinggong", 1) < 120)
		return notify_fail("���ժ�ǹ���򲻹�.\n");
        if( (int)me->query("max_neili") < 400 )
                return notify_fail("����������㣬û�а취��ϰ��������\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("whip", 1) < 60)
                return notify_fail("��Ļ����޷����̫ǳ��\n");

        if (((int)me->query_skill("whip", 1)+150) < (int)me->query_skill("ruanhong-zhusuo", 1))
                return notify_fail("��Ļ����޷�ˮƽ���������޷���������Ĳ�������\n");


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
        level   = (int) me->query_skill("chanhun-suo",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("��Ļ����󷨻�򲻹�.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("����������צ��򲻹�.\n");
        if ((int)me->query("qi") < 60)
                return notify_fail("���������������������\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("���������������������\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chanhun-suo/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("chanhun-suo", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
        if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-600);
                return HIY "$n" HIY "�е�������ѩ���ڻ�һ������ʧ�ˡ���\n" NOR;
        }
else
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
victim->apply_condition("xx_poison",20);
victim->apply_condition("x2_sandu",20);
victim->apply_condition("sanpoison",20);
                return HIY "$n" HIY "�е��������Ƹ���һ�㣬ɢ����һ�ɼ���"
               "�ŵĶ������\n" NOR;
        }
	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 10) / 2+30 );
		return HIR "$N��ǰ����������$wȦת��磬������Ӱ������$nȫ��! \n" NOR;
	}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("chanhun-suo",1);
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

weapon = me->query_temp("weapon");
if (weapon)
{
        if (  level2 > 150
        && random(5)==1
        && (string)weapon->query("skill_type") == "whip"){
 
            msg = HIW"$n����ʱ��$N����һת ����ȫ��$n�޷�����Ҳ�޷�����!!\n"NOR;
   if (!ob->is_busy())
             ob->start_busy(3);
message_vision(msg, me, ob);
               }


}



}