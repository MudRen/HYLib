// tianyu-qijian.c �����潣
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action":"$Nʹһʽ"+(order[random(13)])+"������һ�ߡ�"NOR"������$w����΢�񣬻ó�һ���������$n��$l",
	"force" : 120,
        "dodge" : 110,
	"damage": 240,
	"lvl" : 0,
	"skill_name" : "����һ��",
	"damage_type":	"����"
]),
([	"action":"$N����ǰ��ʹ��"+(order[random(13)])+"�����羪�硹"NOR"������$w����һ����������$n��$l",
	"force" : 140,
            "dodge" : 110,
	"damage": 240,
	"lvl" : 9,
	"skill_name" : "���羪��",
	"damage_type":	"����"
]),
([	"action":"$N����$wһ����һ��"+(order[random(13)])+"�����ھ��졹"NOR"��ббһ�������ó�������$n��$l",
	"force" : 160,
           "dodge" : 115,
	"damage": 250,
	"lvl" : 18,
	"skill_name" : "���ھ���",
	"damage_type":	"����"
]),
([	"action":"$N���н����ॳ���һ����һʽ"+(order[random(13)])+"��������ġ�"NOR"��һ���������$n��$l",
	"force" : 180,
            "dodge" : 110,
	"damage": 260,
	"lvl" : 27,
	"skill_name" : "�������",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ"+(order[random(13)])+"��ŭ���񻨡�"NOR"������$w�������������ʹ$n�Ѷ���ʵ���޿ɶ��",
	"force" : 220,
            "dodge" : 151,
	"damage": 280,
	"lvl" : 36,
	"skill_name" : "ŭ����",
	"damage_type":	"����"
]),
([	"action":"$N����$wбָ���죬��â���£�һʽ"+(order[random(13)])+"���Ż����ա�"NOR"����׼$n��$lбб����",
	"force" : 260,
            "dodge" : 115,
	"damage": 200,
	"lvl" : 44,
	"skill_name" : "�Ż�����",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ"+(order[random(13)])+"�������ѩ��"NOR"�����󼱶�������������⣬����$n��$l",
	"force" : 320,
            "dodge" : 115,
	"damage": 255,
	"lvl" : 52,
	"skill_name" : "�����ѩ",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ"+(order[random(13)])+"����ӵ�к��"NOR"��$w��ն�������缲�������$n���ؿ�",
	"force" : 380,
            "dodge" : 115,
	"damage": 300,
	"lvl" : 60,
	"skill_name" : "��ӵ�к",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ"+(order[random(13)])+"������ɺ硹"NOR"��$wͻȻ���������һƬ���Χ��$nȫ��",
	"force" : 380,
            "dodge" : 115,
	"damage": 350,
	"lvl" : 60,
	"skill_name" : "����ɺ�",
	"damage_type":	"����"
])
});
string *hit_msg = ({ 
        HIY"\n$Nǰ�н��䣬����������ǰ����������һʽ������˷������಻����\n"NOR,
        HIC"\n�Է�����㵼䣬ȴ��$N�Ľ�����������ǰ�����������������䣬���ͱ��ˣ�\n"NOR,
        HIR"\nֻ��$N��Ӱһ����������Ȼ�۽��Է������н�����˸���������죡\n"NOR,
        HIM"\nȴ��$Nһ��δ����������������ǰ��֮��ȴͬʱ����ٶ�֮���������ͬʱ������\n"NOR,
        HIG"\n����$N�ֱ۶�����ֻ��һ������֮������ڶ������ƿն�����������ǰ��\n"NOR,
        HIB"\n�����ţ�$N����һ���������������ǰ�󣬵����漸��ͬʱ����ٶ�֮�������Ա�\n"NOR,
        HIW"\nһգ�ۼ�$N��������������ǰ���������ޣ���ڶ������ڵ���ʯ�������ǰ��\n"NOR,
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");

        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("��������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("��������ƻ��̫ǳ��\n");
        if ((int)me->query_skill("liuyue-jian", 1) < 80)
		return notify_fail("������½�����̫ǳ��\n");


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
	level   = (int) me->query_skill("tianyu-qijian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������潣��\n");
       if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("��������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("��������ƻ��̫ǳ��\n");
        if ((int)me->query_skill("liuyue-jian", 1) < 80)
		return notify_fail("������½�����̫ǳ��\n");
	me->receive_damage("qi", 45);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
       object weapon;
        string amsgs;

        weapon = me->query_temp("weapon");
        lvl  = me->query_skill("tianyu-qijian", 1);
        flvl = me->query("jiali");

        if ( me->query_temp("09_pfm/zhu")
             && me->query_temp("09_pfm/zhu") > 0
             && weapon
             && weapon->query("skill_type") == "sword"
             && !me->query_temp("09_pfm/zhu_hit_done") )
        {
                amsgs = hit_msg[random(sizeof(hit_msg))];
                me->add("neili", -40);
                me->add_temp("09_pfm/zhu", -1);
                message_vision(amsgs, me);
                me->set_temp("09_pfm/zhu_hit_done", 1);
                if (random(3)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1); 
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1); 
                me->delete_temp("09_pfm/zhu_hit_done");
        }

if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(6)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
victim->apply_condition("ss_poison", 10 +
		victim->query_condition("ss_poison"));
}
                return HIW "$n" HIW "�������˼���������!!\n" NOR;
        }

        else if (random(5)==0)
        {
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
}
                return HIR "$n" HIR "��һ������Ҫ������Ѫ�ɳ�!!\n" NOR;

}                        }
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bahuang-gong",1);
        level2= (int) me->query_skill("bahuang-gong",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (damage2>= 3800) damage2 = 3800;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "bahuang-gong")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
me->add("neili",damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIR"$NͻȻ����,$nȫ����������ˮ��ԴԴ����������$N������\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}