// ���齣��
// Modified by rcwiz Oct.1997
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "name"  : "��÷�綹",
        "action": "$N����$wһ����һ��"+(order[random(13)])+"����÷�綹��"NOR"ʹ��������������ǧ����$n��$l��ȥ",
        "force" : 70,
	"attack": 10,
	"parry" : 5,
        "dodge" : 10,
        "damage": 130,
        "lvl"   : 0,
        "damage_type":  "����"
]),
([      "name"  : "���г���",
        "action": "$N�����죬һ��"+(order[random(13)])+"�����г�����"NOR"��ʹ������$wֱָ$n$l",
        "force" : 120,
	"attack": 20,
	"parry" : 15,
        "dodge" : 20,
        "damage": 140,
        "lvl"   : 20,
        "damage_type":  "����"
]),
([      "name"  : "���է��",
        "action": "$N����$w��ת�������ƹ��ǹ���������ͻת������$n�������ƺ�������ǧ�п�",
        "force" : 160,
	"attack": 25,
	"parry" : 20,
        "dodge" : 30,
        "damage": 45,
        "lvl"   : 140,
        "damage_type":  "����"
]),
([      "name"  : "ͬ������",
        "action": "$N��̾һ�����粽��ǰ��ʹһ��"+(order[random(13)])+"��ͬ��������"NOR"������$wб�̶��������ز������Ľ�������֮����",
        "force" : 280,
	"attack": 60,
	"parry" : 10,
        "dodge" : 10,
        "damage": 250,
        "lvl"   : 60,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
    object ob;

    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������û�а취�����齣����\n");

    if (me->query_skill("huashan-sword", 1) < 100)
        return notify_fail("�㻪ɽ������򲻹����޷������齣����\n");

    if (me->query_skill("fanliangyi-dao", 1) < 100)
        return notify_fail("�㷴���ǵ�����򲻹����޷������齣����\n");
    if (me->query_skill("feiyan-huixiang", 1) < 100)
        return notify_fail("���������򲻹����޷������齣����\n");
    if (me->query_skill("hunyuan-zhang", 1) < 100)
        return notify_fail("���Ԫ�ƻ�򲻹����޷������齣����\n");
    if (me->query_skill("poyu-quan", 1) < 100)
        return notify_fail("����ʯ����ȭ��򲻹����޷������齣����\n");
    if (me->query_skill("kuangfeng-jian", 1) < 100)
        return notify_fail("����콣��򲻹����޷������齣����\n");
                                   


    if (! (ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "sword" )
        return notify_fail("���������һ�ѽ�����ѧϰ���齣����\n");

    if (me->query_skill("sword", 1) < me->query_skill("chongling-jian", 1))
	return notify_fail("��Ļ�������������ޣ��޷���������ĳ��齣����\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level = (int) me->query_skill("chongling-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 60)
        return notify_fail("�������̫�ͣ�û�а취��ϰ���齣����\n");

    if (me->query_skill("huashan-sword", 1) < 100)
        return notify_fail("�㻪ɽ������򲻹����޷������齣����\n");
                
    if ((int)me->query("neili") < 40)
        return notify_fail("�������������û�а취��ϰ���齣����\n");

    me->receive_damage("qi", 50);
    me->add("neili", -31);
    return 1;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	int damage;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("chongling-jian", 1);
        if (random(me->query_skill("chongling-jian",1)) < 100 ||		             me->query_skill("force",1) < 100 )
        return 0;

	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("zixia-shengong",1);
        level2= (int) me->query_skill("zixia-shengong",1);
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "zixia-shengong")
{
if (random(2)==0)
{
	victim->start_busy(2);
}
else 	victim->receive_wound("qi", (random(damage_bonus))+200);
                  return random(2) ? HIR "$N" HIR "������ϼ�񹦣�һ��������������ɣ�,$n˫��һ��,��֪����Ǻ�!\n" NOR:
                                     HIR "$N" HIR "��������,����" + weapon->name() + HIR "���������۾�һ�㣬����ӳ�����,$n˫��һ��,��֪����Ǻ�!\n"NOR;
}
	weapon = me->query_temp("weapon");
level2= (int) me->query_skill("zixia-shengong",1);             
	if (random(3)==1 && me->query_skill("zixia-shengong",1)>300)
	{
	if( damage_bonus > 50 && random(level2)>100) {
	victim->receive_wound("qi", (random(damage_bonus)+20));
	return HIG"$N���������Ž�ʽһ�䣬������������ҫ�۵Ĺ�â�������һƬãã�Ľ�Ļ!\n"NOR;
        }
}

}
string perform_action_file(string action)
{
        return __DIR__"chongling-jian/" + action;
}