// jinyu-quan.c ����ȭ
#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([	"action" : "$Nһ�С������á���˫ȭһ��һ��, ��$n��ȥ",
	"force"  : 120,
	"dodge"  : 10,
	"damage" : 220,
	"lvl"    : 0,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С������Ͻ𡹣��ó�һƬȭӰ��������磬����$n��ͷ��",
	"force"  : 140,
	"dodge"  : 20,
	"damage" : 130,
	"lvl"    : 20,
	"skill_name" : "�����Ͻ�",
	"damage_type" : "����"
]),
([	"action" : "$N��Ӱ����Ʈ������΢Ц��һ�С��������񡹣���������$n��$l",
	"force"  : 150,
	"dodge"  : 20,
	"damage" : 145,
	"lvl"    : 40,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��������⡹��˫ȭһ�ϣ�$nֻ��������$N��ȭӰ",
	"force"  : 160,
	"dodge"  : 25,
	"damage" : 160,
	"lvl"    : 60,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����$nһת���������ߣ�ȭ����磬��������$n������һ��
���������á�",
	"force"  : 170,
	"dodge"  : 30,
	"damage" : 160,
	"lvl"    : 80,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "ֻ��$Nһ�������˲���������Σ�ͻȻ�Ϳ��������ѵ�$n��ǰ��
��ȭ���������Ⱦ������ף�Ѹ����ף�һ�С���ʯ�ɽ𡹻���$n��ǰ��",
	"force"  : 180,
	"dodge"  : 35,
	"damage" : 180,
	"lvl"    : 100,
	"skill_name" : "��ʯ�ɽ�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��ڿ���𡹣�����$n���ƺ�$n��ȫ����ȭӰ����",
	"force"  : 280,
	"dodge"  : 30,
	"damage" : 200,
	"lvl"    : 120,
	"skill_name" : "�ڿ����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="wuluo-zhang"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("��Ŀ���������򲻹����޷�������ȭ��\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level,a,b,c,d,e;
        level   = (int) me->query_skill("jinyu-quan",1);
        a = me->query("neili");
// ע�⣬ȡ��������ʱҪע��ĳЩ�ķ�����������ʱ���ԡ�
        b = me->query_str();
        c = me->query_dex();
        d = me->query_con();
        e = me->query("jiali");
        if (a > 2000) a= 2000;
        if (a < 500) a= 500;
        if (level > 200) level = 200 + (level-200)/10;    
        if (random((int)me->query_skill("cuff")) >= 100 
         && ((int)me->query("neili") >= 500 )          
         && (me->query_skill_prepared("cuff") == "jinyu-quan")
         && random(10)> 5 ) {
               return ([
                "action":HIY"$N����һ�Σ��漴��ȭ������������ȭ�ƽ�������ǰ������������ʮ��������"NOR,
                "parry":(int)me->query_skill("parry", 1)/8,
                "dodge":(int)me->query_skill("dodge", 1)/6,
                "force": 650,
                "damage": 650,
                "damage_type": "����"
               ]);
        }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if (damage_bonus <10) damage_bonus=10;
      if( random(me->query_skill("jinyu-quan",1)) > 90 ) 
{
	  victim->receive_wound("qi", damage_bonus/2);
        return HIR "$n��һƬȭӰ����ʱ˫��һ�ڣ�\n" NOR;
}
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N ����һ������ʩչ��һ��ָ�����Դ���ָ���鲼ȫ��! ��ɫ������ˡ�\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"��$N�Ĵ���ָ������! ��������� "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$n��������̫��ȭ������������������\n",  
           message_vision(msg, me, ob);
           return j;
}      
}
