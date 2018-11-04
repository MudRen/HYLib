#include <ansi.h>

#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 


mapping *action=({
([      "action" : "$Nһ��" HIY "�������ǬΪ���š�" NOR "���建���ζ���Χ��$n�������ƣ���Ȼ"
                   "Ѹ������б�����������ɻ��Σ�����$n��$l",
        "force" : 130,
        "attack": 21,
        "dodge" : 70,
        "parry" : 65,
        "damage": 114,
        "lvl"   : 0,
        "skill_name" : "�����ǬΪ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" WHT "���������Ϊ���š�" NOR "������������˫�Ʋ�ͣ�Ļ�������Ȼ��"
                   "��һ��������߸�Ծ������$n��$l����һ������",
        "force" : 170,
        "attack": 25,
        "dodge" : 83,
        "parry" : 76,
        "damage": 117,
        "lvl"   : 30,
        "skill_name" : "�������Ϊ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" YEL "���������Ϊ���š�" NOR "����������ˮ��Ʈ��������˫������Ʈ"
                   "������Ȼ����˫��զ�֣��ֱ�������������빥��$n",
        "force" : 190,
        "attack": 28,
        "dodge" : 95,
        "parry" : 88,
        "damage": 120,
        "lvl"   : 60,
        "skill_name" : "�������Ϊ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" HIW "���������Ϊ���š�" NOR "ٿ������$n��ǰ�������ո���ͷ������"
                   "�£��ƺ��Ե�û����ɣ�һ�����������������$n",
        "force" : 230,
        "attack": 35,
        "dodge" : 107,
        "parry" : 98,
        "damage": 123,
        "lvl"   : 90,
        "skill_name" : "�������Ϊ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" HIR "�������ӿ������š�" NOR "ͻȻ�������࣬ͷ�½��ϣ��������ӣ�"
                   "����һֻ�ڿ��������ķ�����һ������$n",
        "force" : 270,
        "attack": 40,
        "dodge" : 129,
        "parry" : 113,
        "damage": 127,
        "lvl"   : 120,
        "skill_name" : "�����ӿ�������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" MAG "������Ӷ������š�" NOR "�������ݼ�ת��չ���ṦΧ��$n������"
                   "�ߣ���Ȼ�������һ������$n��$l",
        "force" : 320,
        "attack": 48,
        "dodge" : 154,
        "parry" : 118,
        "damage": 138,
        "lvl"   : 150,
        "skill_name" : "����Ӷ�������",
        "damage_type" : "����"
]),
([      "action" : "$N����ǰ��һ��" CYN "��������������š�" NOR "�������ȣ��Կ����������"
                   "һֻչ�᰿��Ĵ���������һԾ�Ѿ�����$n��������������\n��$n�Ĵ�׵Ѩ",
        "force" : 360,
        "attack": 61,
        "dodge" : 153,
        "parry" : 131,
        "damage": 145,
        "lvl"   : 180,
        "skill_name" : "�������������",
        "damage_type" : "����"
]),
([      "action" : "$N����һŤ�������Ŷ�׼$n��ʹ��һ��" HIM "�����̾��������š�" NOR "����$n"
                   "��γ��У�$N�ı�����������۾������ܼ�ʱ���ܣ���\nȻ$N��������$n�ؿڿ�ȥ��"
                   "˫��ͻȻ��Ҹ�������ֱ��$n��$l",
        "force" : 380,
        "attack": 73,
        "dodge" : 155,
        "parry" : 135,
        "damage": 157,
        "lvl"   : 220,
        "skill_name" : "���̾���������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

int valid_combine(string combo) { return combo=="baihua-cuoquan" ; }

int valid_learn(object me)
{
       if (((int)me->query_skill("houquan", 1)) < 120)
               return notify_fail("��ĺ�ȭ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-zhua", 1)) < 120)
               return notify_fail("�������צ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shou", 1)) < 120)
               return notify_fail("���������̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shengong", 1)) < 120)
               return notify_fail("���������̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-shenfa", 1)) < 120)
               return notify_fail("���������̫���ˡ�\n");

       if (((int)me->query_skill("baihua-cuoquan", 1)) < 120)
               return notify_fail("��İٻ���ȭ̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-jian", 1)) < 120)
               return notify_fail("���������̫���ˡ�\n");

       if (((int)me->query_skill("wuhu-duanmendao", 1)) < 120)
               return notify_fail("����廢���ŵ�̫���ˡ�\n");

       if (((int)me->query_skill("yunlong-bian", 1)) < 120)
               return notify_fail("��������޷�̫���ˡ�\n");


        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����������Ʊ�����֡�\n");

        if (me->query("max_neili") < 1200)
                return notify_fail("��������������޷���ϰ��������ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("bazhen-zhang", 1))
                return notify_fail("��Ļ����Ʒ�������ޣ��޷���������İ�������ơ�\n");

        return 1;
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
        level = (int)me->query_skill("bazhen-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 85);
        me->add("neili", -60);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bazhen-zhang/" + action;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("bazhen-zhang",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (random(level)+100) );	
        return HIW "�����������!!����$N���߰��ԣ��������� ˫�ƴ���$n��"+ xue_name[random(sizeof(xue_name))] +"!! $n�³�һ����Ѫ!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 50 ||  (int)me->query_temp("kongming")  )
	{

        victim->receive_wound("qi", damage_bonus/2+10 );	
        return RED "���������!!һ����Ѫ��$n���������!\n" NOR;
  }
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bazhen-zhang",1);
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

if ( random(3) == 0 && random(level) > 180){
         msg = YEL"$N���$n�Ĺ��� ʩ�������ƻ�Ӱ��������һ����˫��ͬʱ����$n��\n"NOR;
         msg += YEL"$n�е�˫��һ������Ȼ���ܶ���!!��\n"NOR;
ob->start_busy(4);

message_vision(msg, me, ob);
}

           return j;
}      
