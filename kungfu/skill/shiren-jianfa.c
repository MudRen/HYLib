//npc�书��������!!
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({

	([	"action":		"$N���е�$wӭ��һ�Σ���������ѽ����������һ��"+(order[random(13)])+"������ն��"NOR"�����ڰ�ؿ���$n��$l",
		"force":		100,
                "damage":               100,
                "dodge" : 40,
                "lvl" : 0,
                "skill_name" : "����ն",
    		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$wӭ����裬һ��"+(order[random(13)])+"�������ġ�"NOR"�󱩷��еĹ�ɳ������$n��$l",
                "damage":               120,
		"force":		120,
                "dodge" : 120,
                "lvl" : 10,
                "skill_name" : "������",
		"damage_type":	"����"
	]),
	([	"action":		"$N���е�$w�����е����ƣ�����"+(order[random(13)])+"�������ϡ�"NOR"���ۺ�ɢ�ؿ���$n��$l",
		"force":		100,
                "damage":               200,
                "dodge" : 120,
                "lvl" : 30,
                "skill_name" : "������",
                "damage_type":	"����"
	]),
	([	"action":		"$N���е�$w�����е����ƣ�����"+(order[random(13)])+"�������ϡ�"NOR"���ۺ�ɢ�ؿ���$n��$l",
		"force":		100,
                "damage":               200,
                "dodge" : 130,
                "lvl" : 30,
                "skill_name" : "������",
                "damage_type":	"����"
	]),

	([	"action":		"$N�ζ����е�$w��ͻȻʹ����"+(order[random(13)])+"����ͻ����"NOR"����������֣�������е���Ҷ��һ����һ����ɢ��$n��$l",
		"force":		200,
                "damage":               200,
                "dodge" : 130,
                "lvl" : 80,
                "skill_name" : "��ͻ��",
                "damage_type":	"����"
	]),
	([	"action":		"$N����ȫ��Ĺ�����"+(order[random(13)])+"����硹"NOR"���е�$w��̹Ǻ�������$n",
		"force":		240,
		"damage":		240,
                "dodge" : 40,
                "lvl" : 100,
                "skill_name" : "���",
                "damage_type":	"����"
	]),
       ([  "action" : "$N����Ծ������$w��ӣ�һʽ"+(order[random(13)])+"���Ӻϰ�ն��"NOR"ն��$n��",
               "damage" : 250,
               "dodge"  : 140,
               "force"  : 250,
               "lvl"   : 110,
               "skill_name" : "�Ӻϰ�ն",
               "damage_type" : "����"
        ]),
       ([  "action" : "$N�߸�Ծ������$w�����������Σ�ʹ��"+(order[random(13)])+"����β����"NOR"��$n���ұ����ն��",
           "damage" : 280,
           "dodge" : 140,
           "force" : 280,
           "lvl"   : 120,
           "skill_name" : "��β��",
           "damage_type" : "����"
       ]),
       ([  "action" : "$N����һ����ʹ��"+(order[random(13)])+"����ֱն��"NOR"��ˢˢˢˢ�ĵ�����$n�أ������������Ĵ�����",
           "damage" : 300,
           "dodge" : 145,
           "force" : 205,
           "lvl"   : 140,
           "skill_name" : "��ֱն",
           "damage_type" : "����"
       ]),
       ([  "action" : "$N����һ����Х��һ��"+(order[random(13)])+"��̤�봹ֱն��"NOR"��б����ǰ��$w����ֱ����Ѹ���ޱȣ�����$n��$l",
           "damage" : 350,
           "dodge" : 145,
           "force" : 205,
           "lvl"   : 160,
           "skill_name" : "̤�봹ֱն",
           "damage_type" : "����"
       ]),
([      "action":"$Nʩչ����"+(order[random(13)])+"������ɱ��"NOR"����$n������$w���ſ�Ұ���磬�����ޱȵ���������",
        "force" : 220,
        "dodge" : 130,
	"damage": 400,
        "lvl" : 200,
        "skill_name" : "����ɱ",
        "damage_type":  "����"
]),
([      "action":"$Nһ��"+(order[random(13)])+"���󻬻�תն��"NOR"��ͻȻ����$n���࣬Ѹ�͵�������ն����ʽ��Ȼ�ϳ�һ��ԲȦ",
        "force" : 230,
        "dodge" : 130,
        "damage": 420,
        "lvl" : 225,
        "skill_name" : "�󻬻�תն",
        "damage_type":  "����"
]),
([      "action":"$N���һ��������$w�󿪴��أ������ӵ�ʹ��"+(order[random(13)])+"���һ���תն��"NOR"��ն��$n��$l",
        "force" : 230,
        "dodge" : 130,
        "damage": 420,
        "lvl" : 230,
        "skill_name" : "�һ���תն",
        "damage_type":  "����"
]),
([      "action":"$N�˵���磬�����ó���"+(order[random(13)])+"������ɱ��"NOR"��"+(order[random(13)])+"�����ɱ��"NOR"��"+(order[random(13)])+"���ٹ�ɱ��"NOR"�����ưԵ�֮��������$n��������Ϳ�����",
        "force" : 500,
        "dodge" : 150,
        "damage": 600,
        "lvl" : 10,
        "skill_name" : "����ն",
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("�������������û�а취���ձ��Ž�����\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 200)
   return notify_fail("���ɱ���ķ���򲻹���\n");

 if ((int)me->query_skill("huoxinliu-jianfa", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("�����Ȼ�������򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("feitian-yujianliu", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("��ķ�����������򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("wuxing-dun", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("������жݻ�򲻹����޷�ѧ��\n");

   if( (string)me->query_skill_mapped("force")!= "shayi-xinfa")
        return notify_fail("�ձ��Ž����������ɱ���ķ���������\n");

    return 1;
}

int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("���ɱ���ķ���򲻹���\n");

 if ((int)me->query_skill("huoxinliu-jianfa", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("�����Ȼ�������򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("feitian-yujianliu", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("��ķ�����������򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("wuxing-dun", 1) < (int)me->query_skill("shiren-jianfa", 1))
   return notify_fail("������жݻ�򲻹����޷�ѧ��\n");

        if( (int)me->query("qi") < 100
        ||      (int)me->query("neili") < 100 )
                return notify_fail("�����������������û�а취��ϰ�ձ��Ž�����\n");
        me->receive_damage("qi", 80);
        me->add("neili", -80);
        //write("�㰴����ѧ����һ���ձ��Ž�����\n");
        return 1;
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

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
        object target;

        level   = (int) me->query_skill("shiren-jianfa",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

    if (!userp(me) || (int)me->query_skill("shayi-xinfa", 1) > 10)
{
	if( random(8)==1 && random(level) > 260)
	{
		return ([
		"action": HIR"�� ˲��ɱ! ��"+HIM"$Nʹ�������ٵ����ؼ��콣�ε�������$nδ��ʹ��ǰ����������!"NOR,
		"force" : 850+random(200),
		"dodge" : 250,
		"damage": 850+random(200),
	        "skill_name" : "˲��ɱ!",
		"damage_type" : "����" ]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIR"���������!��"+HIY"$N�������������ɵ���������ȼ��,��������������,��ȫ�ٻٶ���!!"NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "�����",
		"damage_type": random(2)?"����":"����"]);
	}
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIB"��������!��"+HIY"$N��ץס����ʱ,���������������ڲصĻ�ҩ"NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}

         if( random(8)==1 && random(level) > 150)
	{
		return ([

		"action" : HIM"���ؽ�.����!��"+HIY"$N�������е��,�����ͬʱ����ն���ͻ��գ� "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}
 
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIG"��Ӱ���Ź���!��"+HIY"$N����֮һ���������Լ�,ʹ�Լ����ű��������޵�,��������Ǳ��,������ǿ������ "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "Ӱ���Ź���",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIC"��������!��"+HIY"$N�����ֵĵ��ڱ��󽻸�����,���üٶ�������Ԥ�ϲ����ĵط����� �� "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 250)
	{
		return ([
		"action" : HIW"��������ƽ��!��"+HIY"$N��[һ,��,ʮ]���������[ƽ]�ֽ��������,����ķ�$n,����$n�޷������� "NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "������ƽ��",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIC"�����콣������!��"+HIW"$N����С̫��,������ˮ��ʽ�̳�,�����ٱ�����,˲������С� "NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "���콣������",
		"damage_type": random(2)?"����":"����"]);
	}

  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIG"������˫��!��"+HIW"$N˫���ݺ�ʮ�� ����С̫��ʮ�ֽ������������ƵĹ���$n ��"NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "����˫��!",
		"damage_type": random(2)?"����":"����"]);
	}
}
  
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}




string perform_action_file(string action)
{
        return __DIR__"shiren-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("blade",1);
        level2= (int) me->query_skill("shiren-jianfa",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"ֻ��$n$l����Ѫ�񱼣��ѱ�"+weapon->name()+HIR"ն���������������˿���!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("shiren-jianfa", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
    if ((int)me->query_skill("shayi-xinfa", 1) < 10 && userp(me)) return 1;


        if (  random(level) > 150
         && me->query_skill_mapped("parry") =="shiren-jianfa"
         && weapon
         && weapon->query("skill_type") == "blade"
         && me->query_skill("blade") > 150
         && random(me->query_skill("blade",1)) > 150
           ){
         msg = HIG"$N���$n�Ĺ��ơ�����һ����ͻ������!!!��\n"NOR;
            message_vision(msg, me, ob);
            if ( random(3) == 0 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"�� ˲��ɱ! ����$Nʹ�������ٵ����ؼ��콣�ε�������$nδ��ʹ��ǰ����������!!��\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/15);
}
else
{
ob->add("qi",-5000);
ob->add("qi",-5000);
}

msg += damage_msg(damage, "����");
            }
else  if (random(3)==1 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"���������!����$N�������������ɵ���������ȼ��,��������������,��ȫ�ٻ�$n!!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/20);
msg += damage_msg(damage, "����");
}
else
{
ob->add("qi",-4000);
ob->add("qi",-4000);
msg += damage_msg(damage, "����");
}
            }
else  if (random(3)==2 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"�����콣������!����$N����С̫��,������ˮ��ʽ�̳�,�����ٱ�����,˲�������!! \n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
msg += damage_msg(damage, "����");
}
else
{
ob->add("qi",-3000);
ob->add("qi",-3000);
msg += damage_msg(damage, "����");
}
            }
else
           msg = HIG"$n�ϵ���������,���˿�������������!��\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
