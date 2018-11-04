// yunlong-jian.c ������

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([	"action":"\n$Nʹһʽ"+(order[random(13)])+"������˳��Ȼ��"NOR"������$w����΢�񣬻ó�һ���׹����$n��$l",
	"force" : 120,
        "dodge" : 10,
	"damage": 125,
	"lvl" : 0,
	"skill_name" : "����˳��Ȼ",
	"damage_type":	"����"
]),
([	"action":"\n$N����ǰ��ʹ��"+(order[random(13)])+"����ȥ�����С�"NOR"�������������ޣ�$w��������$n��$l��ȥ",
	"force" : 140,
        "dodge" : 10,
	"damage": 140,
	"lvl" : 8,
	"skill_name" : "��ȥ������",
	"damage_type":	"����"
]),
([	"action":"\n$Nһʽ"+(order[random(13)])+"��־�����Զ��"NOR"������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
	"force" : 160,
        "dodge" : 15,
	"damage": 610,
	"lvl" : 15,
	"skill_name" : "־�����Զ",
	"damage_type":	"����"
]),
([	"action":"$N��������Ծ��һʽ"+(order[random(13)])+"�������γ���"NOR"��������ˮ��һкǧ�����$nȫ��",
	"force" : 180,
        "dodge" : 20,
	"damage": 175,
	"lvl" : 20,
	"skill_name" : "�����γ�",
	"damage_type":	"����"
]),
([	"action":"$N����$w�й�ֱ����һʽ"+(order[random(13)])+"�����Ǳ��ҹ��"NOR"��������Ϣ�ض�׼$n��$l�̳�һ��",
	"force" : 220,
        "dodge" : 15,
	"damage": 190,
	"lvl" : 30,
	"skill_name" : "���Ǳ��ҹ",
	"damage_type":	"����"
]),
([	"action":"$N����$wһ����һʽ"+(order[random(13)])+"������ϸ������"NOR"��������Ϣ�ػ���$n��$l",
	"force" : 250,
        "dodge" : 15,
	"damage": 210,
	"lvl" : 40,
	"skill_name" : "����ϸ����",
	"damage_type":	"����"
]),
([	"action":"\n$N����$wбָ���죬��â���£�һʽ"+(order[random(13)])+"��������������"NOR"����׼$n��$lбб����",
	"force" : 280,
        "dodge" : 25,
	"damage": 235,
	"lvl" : 50,
	"skill_name" : "����������",
	"damage_type":	"����"
]),
([	"action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ"+(order[random(13)])+"������һ��졹"NOR"����$n���ʺ�",
	"force" : 320,
        "dodge" : 15,
	"damage": 255,
	"lvl" : 60,
	"skill_name" : "����һ���",
	"damage_type":	"����"
]),
([	"action":"$N���Ƶ�����һʽ"+(order[random(13)])+"�����Ļ�������"NOR"��$w�Ի���Ծ�����缲�������$n���ؿ�",
	"force" : 380,
        "dodge" : 15,
	"damage": 260,
	"lvl" : 70,
	"skill_name" : "���Ļ�����",
	"damage_type":	"����"
]),
([	"action":"\n$N����һ���εض���һʽ"+(order[random(13)])+"��������ͬ�ԡ�"NOR"��$w�ó������Ӱ����$n����Χס",
	"force" : 420,
        "dodge" : 15,
	"damage": 270,
	"lvl" : 80,
	"skill_name" : "������ͬ��",
	"damage_type":	"����"
]),
([	"action":"$N�������Ʈ�䣬һʽ"+(order[random(13)])+"�����֪���⡹"NOR"������$wƽָ����������$n����",
	"force" : 450,
        "dodge" : 15,
	"damage": 280,
	"lvl" : 90,
	"skill_name" : "���֪����",
	"damage_type":	"����"
]),
([	"action" : "$N����΢����������һ��"+(order[random(13)])+"���ߴ���ʤ����"NOR"���йǽ�����쫷�����$nȫ��",
	"force" : 500,
        "dodge" : 15,
	"damage": 290,
	"lvl" : 100,
	"skill_name" : "�ߴ���ʤ��",
	"damage_type":	"����"
]),
([	"action" : "$Nļ��ʹһ��"+(order[random(13)])+"����Ҷ����ɽ��"NOR"����ʱ�����м���Ѫ������$nȫ��",
	"force" : 500,
        "dodge" : 25,
	"damage": 350,
	"lvl" : 110,
	"skill_name" : "��Ҷ����ɽ",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("��������񹦻��̫ǳ��\n");
	if ((int)me->query_skill("yunlong-xinfa", 1) < 20)
		return notify_fail("��������ķ����̫ǳ��\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
       if (((int)me->query_skill("baihua-cuoquan", 1)+200) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("��İٻ���ȭ̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-zhua", 1)+100) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("�������צ̫���ˡ�\n");
       if (((int)me->query_skill("wuhu-duanmendao", 1)+200) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("����廢���ŵ�̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("���������̫���ˡ�\n");
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
	level   = (int) me->query_skill("yunlong-jian",1);
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
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("��������񹦻��̫ǳ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�����������������������\n");
       if (((int)me->query_skill("baihua-cuoquan", 1)+200) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("��İٻ���ȭ̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-zhua", 1)+100) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("�������צ̫���ˡ�\n");
       if (((int)me->query_skill("wuhu-duanmendao", 1)+200) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("����廢���ŵ�̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("���������̫���ˡ�\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("yunlong-jian", 1))
               return notify_fail("���������̫���ˡ�\n");

	me->receive_damage("qi", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"yunlong-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("yunlong-jian", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "yunlong-shengong" )
                return;
        if (lvl < 120 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
 if (random(4)==0)
        {
flvl=random(lvl)+50;
        if (random(4)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-random(lvl));
victim->add("eff_qi",-random(lvl));
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
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIR"$N"+HIR+"$N���־۳ɻ�צ״! ����Ѫ��ץ��һ��ץס$n��"+ xue_name[random(sizeof(xue_name))] +NOR;
           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}


           return j;
}      
