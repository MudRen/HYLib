// yitian-tulong.c ��������������
// xQin 9/1/98
// Under Modify

#include <ansi.h>
#include <combat.h>

inherit SKILL;
//inherit F_SSERVER;

int raozhi(object me, object victim, object weapon, int damage);
string *taijin = ({"���һ�����", "��������", "����������", "�����Ǿ���", "���������", "��մ����", "�����־���", "�����־���","�귭", "����","����","����","����","����"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

nomask int parry_available() { return 1; }
string *parry_msg = ({
	"$p����һ�ɾ���Ϯ���ؿڣ�����$Wһ��������һ����Ʋ���պ÷�ס��$P$w�����ơ�\n",
	"Σ��֮�У�$p��$W��$P��$w��һ����һ�������������ɵıܹ�����һ�����ǡ��䡹�־��е�һ�ꡣ\n",
	"$p$W���ӣ�����ʹ��һ�ǡ������־�����ס$P��$w��$WһƲһ�㣬���ӽ��ƴ���\n",
	"����$p$Wʹһ�С������־��е���Ʋ������$P�����ƣ��ԼӲ�������ǧ��һ��֮�ʣ�תΣΪ����\n",
});

string query_parry_msg(object weapon, object victim)
{
        object ob;

        if (!objectp(ob = victim->query_temp("weapon")) )
                return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", random(2)?"����":"����");
        else
                return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", ob->name());
}

mapping *action_unarmed = ({
([      "action":"$N���Ƽ�̽����ָ��ץ�����������������$n��$l",
        "force" : 260,
        "dodge" : 40,
        "parry" : 20,
        "damage": 250,
        "damage_type":  "����"
]),
([      "action":"$N�����ĳ������ƶ����κ���������������б�����ִ�������������",
        "force" : 280,
        "dodge" : 40,
        "parry" : 20,
        "damage": 290,
        "lvl" : 112,
        "damage_type":  "����"
]),
([      "action":"$Nһ�����ֲ������������ף�������������ƽƽ��ɨ������$n��̫��Ѩ",
        "force" : 260,
        "dodge" : 40,
        "parry" : 20,
        "damage": 300,
        "damage_type":  "����"
]),
([      "action":"$Nٿ��Ծ�𣬷����ǰ������һ��һ�ӣ�ȴ�ǡ��졹�־���һƲ",
        "force" : 260,
        "dodge" : 40,
        "parry" : 20,
        "damage": 310,
        "damage_type":  "����"
]),
([      "action":"$N����һ�䣬˫�Ʒ��裬��������ѩ������಻���������õ����ǡ�Ī���־�",
        "force" : 200,
        "dodge" : 80,
        "parry" : 20,
        "damage": 320,
        "damage_type":  "����"
]),
([      "action":"$Nת����������ȭ�ͳ���ȴ�ǡ��¡��־���һֱ���ĵ�һ��������$n��$l",
        "force" : 220,
        "dodge" : 130,
        "parry" : 20,
        "damage": 250,
        "damage_type":  "����"
]),
([      "action":"$N�����㣬�������磬���������ٿ����ʹһ���������־��е�һ����ץ��$n",
        "force" : 240,
        "dodge" : 180,
        "parry" : 20,
        "damage": 320,
        "damage_type":  "ץ��",
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :)
]),
([      "action":"$N˫��һ�㣬�������࣬ʹ��һ�С������־��е�һ��ֱ���������ڰ���м�������",
        "force" : 360,
        "dodge" : 110,
        "parry" : 20,
        "damage": 320,
	"weapon": "����",
        "damage_type":  "����"
]),
([      "action":"$N��Хһ��������ֱ���������������ǽ���â����ʸӦ��������Ͼ�����粻���ɣ���һֱ���ǡ��桹�ֵ�����һ��",
        "force" : 300,
        "dodge" : 140,
        "parry" : 20,
        "damage": 420,
	"weapon": "����",
        "damage_type":  "����"
])
});

mapping *action_weapon = ({
([      "action" : "$N�������飬������磬$w�������������һ��������б��$n",
        "force" : 200,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 320,
        "damage_type" : "����",
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :)
]),
([      "action" : "$N������������»����������磬$wһת������$n��$l�����¿���֮�ʣ���Ʈ��������",
        "force" : 250,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 340,
        "damage_type" : "����"
]),
([      "action" : "$N��������̤�ϣ��������֣�����ʵʵ�������Ϲ�â��˸�������͵ķ�����΢����",
        "force" : 250,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 360,
        "damage_type" : "����"
]),
([      "action" : "$Nٿ��Ծ�𣬷����ǰ��$wһ��һ�ӣ�ȴ�ǡ��졹�־���һƲ",
        "force" : 200,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 380,
        "damage_type" : "����"
]),
([      "action" : "$N$wһ��ʹһ�С�˭���־������������Ҳ�����ʱ����绯Ϊ��ǧ�����⣬��ס$n����",
        "force" : 270,
        "dodge" : 130,
        "parry" : 20,
        "damage" : 380,
        "damage_type" : "����"
]),
([      "action" : "$Nת��������$w�ͳ���ȴ�ǡ��¡��־���һֱ������$n��$l",
        "force" : 300,
        "dodge" : 130,
        "parry" : 20,
        "damage" : 440,
        "damage_type" : "����"
]),
([      "action" : "ͻȻ��$N$wʹ�С������־��е�һ�����͵�һ�죬����$n$l",
        "force" : 350,
        "dodge" : 115,
        "parry" : 20,
        "damage" : 460,
        "damage_type" : "����"
]),
([      "action" : "$N˫��һ�㣬�������࣬ʹ��һ�С������־��е�һ��ֱ������$w�ڰ���м�������",
        "force" : 400,
        "dodge" : 130,
        "parry" : 20,
        "damage" : 480,
        "damage_type" : "����"
]),
([      "action" : "$N����$w����ʯ��������������$n��̨Ѩһ·˳��ֱ�£�ʹ���ǡ��桹�־�������һ��һֱ�������鷨�еĲ��ʣ������ǻ�����ţ��",
        "force" : 450,
        "dodge" : 135,
        "parry" : 20,
        "damage" : 400,
        "damage_type" : "����"
])
});

//������ :) just an example
string  *special_msg = ({
HIY"$N������������»����������磬$wһת������$n��$l�����硰�족�ֵ�һ��"NOR,
HIY"����$N˫��һ�㣬�������࣬һ�С��족�־��еĵڶ��ᣬ��$w�ڰ���м�������"NOR,
HIY"$Nٿ��Ծ�𣬷����ǰ��$wһ��һ�ӣ�ȴ�ǡ��족�־���һƲ"NOR,
HIY"$N˳��ʹ�����족�ֵ�һ�࣬$wɨ��$n$l����������֮��"NOR,
});


int valid_enable(string usage) 
{ 
    return usage == "cuff" || usage == "parry" || usage == "unarmed"|| usage == "sword"; 
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

mapping query_action(object me, object weapon)
{
        object victim;
        string *limbs, *msg, limb, msg1, msg2;

        if( !victim && me->is_fighting() ) victim = offensive_target(me);
//        limbs = victim->query("limbs");
//        limb = limbs[random(sizeof(limbs))];
if (victim && me && victim!=me)
{

	msg = ({
		HIW "ͻȻ��$N$w"HIW"�ƿգ�����$n"+limb+"��������;������΢������Ȼ���˹�ȥ��б��$p$l" NOR,
		HIY "$N�������Ž���������$w"HIY"��ס������ͻȻƽ�̣����⼱��������������δ�����һ��������$n�����ߴ�ҪѨ" NOR,
		HIC "$N����$w"HIC"������ǰ�������������һ�����Ρ�$n����һ��ɭɭ������ֱ�ƹ���" NOR,
	});

        msg1 = "�����һ�����죬$w����������ֱ����$p��$l";
        msg2 = "����$P�������֣�����һ�����������׵���$p$l����";

        if(me->query_temp("raozi_attack")){
                me->add("neili", -(me->query("jiali")));
		me->add("jing", -(me->query("jiajin")));
                return ([
        	"action": me->query_temp("raozi_attack")==1?msg1:msg2,
        	"force" : 550+random(200),
        	"dodge" : 60,
        	"parry" : 20,
        	"damage" : 500+random(500),
        	"damage_type": me->query_temp("raozi_attack")==1?"����":"����",
		]);
                }
        if(me->query_temp("tian") > 4) me->delete_temp("tian");
        if(me->query_temp("tian")){
                me->add_temp("tian", 1);
                me->add("neili", -20);
        	return ([
        	"action": special_msg[me->query_temp("tian")-2],
        	"force" : 450+random(200),
        	"dodge" : 60,
        	"parry" : 20,
        	"damage" : 500+random(500),
        	"damage_type":"����",
		]);
		}
	 if (random(me->query_temp("raozhi")) > 100 ) {
		me->add("neili", -50);
        	return ([
        	"action": msg[random(sizeof(msg))],
        	"force" : 550+random(300),
        	"dodge" : 110,
        	"parry" : 320,
        	"damage" : 500+random(600),
        	"damage_type":"����",
		"post_action": (: raozhi :)
		]);
		}
}

        if (!weapon)
		return action_unarmed[random(sizeof(action_unarmed))];
        else
		return action_weapon[random(sizeof(action_weapon))];
       
}

int valid_learn(object me)
{
        if ((int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("��ġ�̫���񹦡����̫ǳ��\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) > 1)
                return notify_fail("���С���Ȼ�����ơ�ѧ�������!\n");

        if ((int)me->query_skill("taiji-quan", 1) < 200)
                return notify_fail("��ġ�̫��ȭ�����̫ǳ��\n");
        if ((int)me->query_skill("juehu-shou", 1) < 200)
                return notify_fail("������������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("wudang-mianzhang", 1) < 200)
                return notify_fail("����䵱���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("raozhi-roujian", 1) < 200)
                return notify_fail("�����ָ�ὣ���̫ǳ��\n");
        if (me->query_skill("yitian-tulong",1) > 299)
        return notify_fail("������ͷ��һƬ���ң�������ᡸ�������������ľ������ڡ�\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);
return 1;
}

int practice_skill(object me)
{
        if ((int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("��ġ�̫���񹦡����̫ǳ��\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) > 1)
                return notify_fail("���С���Ȼ�����ơ�ѧ�������!\n");

        if ((int)me->query_skill("taiji-quan", 1) < 200)
                return notify_fail("��ġ�̫��ȭ�����̫ǳ��\n");

        if ((int)me->query_skill("juehu-shou", 1) < 200)
                return notify_fail("������������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("wudang-mianzhang", 1) < 200)
                return notify_fail("����䵱���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("raozhi-roujian", 1) < 200)
                return notify_fail("�����ָ�ὣ���̫ǳ��\n");
        if ((int)me->query("jing") < 200)
                return notify_fail("��ľ������������书��\n");
        if ((int)me->query("qi") < 200)
                return notify_fail("����������������书��\n");
        if ((int)me->query("neili") < 200)
                return notify_fail("����������������书��\n");
        me->receive_damage("qi", 100);
        me->receive_damage("jing", 100);
        me->add("neili", -100);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yitian-tulong/" + action;
}

int raozhi(object me, object victim, object weapon,int damage)
{
	int sword, force, ap, dp;
	string *limbs, limb, result, str, type;

	sword = me->query_skill("sword");
	force = me->query_skill("force");
        ap = (sword + force + me->query("combat_exp")/2000) * (99+random(5));
        dp = (victim->query_skill("dodge") + victim->query_skill("parry") + victim->query("combat_exp")/2000) * 100;

//        limbs = victim->query("limbs");
//        limb = limbs[random(sizeof(limbs))];
        type = random(2)?"����":"����";
        
	if( damage < 0 && ap > dp ) 
	{
/*
           	damage = me->query_temp("apply/damage") + me->query_str() + me->query("jiali") + me->query("jiajin");
		damage = damage + random(force + sword) /10 ;
		if(me->query("neili") > random(victim->query("neili")*2) ) damage = damage + random(damage);
           	victim->receive_damage("qi", damage, me);
                if( random(damage) > (int)victim->query_temp("apply/armor"))
		victim->receive_wound("qi", damage - (int)victim->query_temp("apply/armor"), me); 

                me->add("neili", -(me->query("jiali")));
		me->add("jing", -(me->query("jiajin")));
*/

		if (type == "����") me->set_temp("raozi_attack", 1);
                else me->set_temp("raozi_attack", 2);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
                me->delete_temp("raozi_attack");

/*
		message_vision("�����һ�����죬"+weapon->name()+"����������ֱ����$p"+limb+"����\n",me,victim);
		else 
		message_vision("����$P�������֣�����һ�����������׵���$p"+limb+"��������\n",me,victim);

           	result = COMBAT_D->damage_msg(damage, type);
           	result = replace_string( result, "$l", limb);
           	result = replace_string( result, "$w", weapon->name());
           	str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));

           	message_vision(result, me, victim);
           	message_vision("( $N"+str+" )\n", victim);
*/
		return 1;
	}

	return 1;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("taiji-quan", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
              
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "taiji-shengong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (ob->query("qi")>= damage2 )
{
	ob->receive_wound("qi", damage2);
}
msg = HIG"$N �籧̫����һ���ۻ��ޱȵ����������һ����������\n"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
msg += HIY"$n"+HIY+"������ ��̫���񹦽������� �������Լ����� ��\n"NOR;
//msg += "$n��������̫��ȭ������������������\n",  
           message_vision(msg, me, ob);
           return j;
}       
	if(me->query("combat_exp") > ob->query("combat_exp")*2/3
    	&& !me->query_temp("weapon")
    	&& me->query_skill_mapped("parry") == "yitian-tulong"
    	&& me->query_skill("taiji-shengong", 1) > 120
    	&& me->query_skill("yitian-tulong",1) > 120
    	&& me->query("neili") > 500 
    	&& living(me)
    	&& random(10) >= 6)
    {
    	message_vision(HIM"����$N����ʹһ�С��䡹�־��е��ҹ�������$n����֮�ƣ�����ʹһ�С������־��е���Ʋ���������ԼӲ��������˷���ֻ��$N������裬�����������У��������������$n���������һ�㡣�����á��ڡ���һ�죬$n���ʵʵ��ˤ�ڵ��ϣ�\n"NOR,me,ob);         
if (ob->query("qi") > damage)
{
         ob->receive_damage("qi", damage/2+ob->query("jiali")*2, me);
         ob->receive_wound("qi", ob->query("jiali"), me);
if (!ob->is_busy())
         ob->start_busy(2);
}
         COMBAT_D->report_status(ob);
         return 500;
    }
    return 1;          
}
