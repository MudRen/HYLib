//npc�书��������!!
//npc�书��������!!
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
//inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "action" : "$N��ϥ���������ֺ�ʮ��һʽ"+(order[random(13)])+"���衹"NOR"��˫ȭ���ƶ���������$n��$l",
    "force" : 180,
    "dodge" : 55,
    "damage": 170,
    "lvl" : 0,
    "skill_name" : "��",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ"+(order[random(13)])+"��ϼ��"NOR"��˫�������»���ȭ�����棬��ž����",
    "force" : 200,
    "dodge" : 55,
    "damage": 170,
    "lvl" : 20,
    "skill_name" : "ϼ",
    "damage_type" : "����"
]),
([  "action" : "$N�ڿշ���һʽ"+(order[random(13)])+"��Ϣ����"NOR"��˫��˫���������$n�޿ɶ��",    
    "force" : 230,
    "dodge" : 55,
    "damage": 200,
    "lvl" : 40,
    "skill_name" : "Ϣ��",
    "damage_type" : "����"
]),
([  "action" : "$N˫���麬����Ե�³���һʽ"+(order[random(13)])+"��������"NOR"��������$n�Ƴ�",
    "force" : 270,
    "dodge" : 55,
    "damage": 220,
    "lvl" : 60,
    "skill_name" : "����",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ"+(order[random(13)])+"���޳���"NOR"������$n����ǰ���",    
    "force" : 320,
    "dodge" : 50,
    "damage": 215,
    "lvl" : 80,
    "skill_name" : "�޳�",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ"+(order[random(13)])+"��ɲ�ǡ�"NOR"������ʮָ���$n��ȫ����ʮ����ҪѨ",
    "force" : 380,
    "dodge" : 55,
    "damage": 225,
    "lvl" : 90,
    "skill_name" : "ɲ��",
    "damage_type" : "����"
]),
([  "action" : "$N��Ŀ���ӣ�˫��������һʽ"+(order[random(13)])+"����������"NOR"������˷������������ǵ�
����",
    "force" : 450,
    "dodge" : 55,
    "damage": 235,
    "lvl" : 100,
    "skill_name" : "������",
    "damage_type" : "����"
]),
([  "action" : "$N��Ц��Ц��˫ȭ�����޶���һʽ"+(order[random(13)])+"��Ӱ������"NOR"����Ȼ����$n��ǰ��",
    "force" : 530,
    "dodge" : 50,
    "damage": 150,
    "lvl" : 60,
    "skill_name" : "Ӱ����",
    "damage_type" : "����"
]),
(["action" :"$N˫��һ�ӣ���һʽ"+(order[random(13)])+"��Ӱ�衹"NOR"�������ͨ��֮�ƣ�ȭ��������������ֱ��$n��ȥ",
  "force" : 150,
  "dodge" : 55,
    "damage": 215,
  "lvl" : 5,
  "skill_name" : "Ӱ��",
  "damage_type" : "����"
]),
(["action" :"$N�������������һ�գ�����һ����ǽ������������ȭ������$n��һ��"+(order[random(13)])+"��ɽ�ڡ�"NOR"��ǽ����",
  "force" : 200,
  "dodge" : 110,
    "damage": 215,
  "lvl" : 15,
  "skill_name" : "ɽ��",
  "damage_type" : "����"
]),
(["action" :"$Nһ����ʽ"+(order[random(13)])+"����׵����"NOR"��˫ȭ���������������ಢ����׼$n$lһʽ�ӳ��������쳣",
  "force" : 220,
  "dodge" : 115,
    "damage": 115,
  "lvl" : 25,
  "skill_name" : "��׵��",
  "damage_type" : "����"
]),
(["action" :"$Nʹ��һ��"+(order[random(13)])+"��������"NOR"��˫�������Ӷ���ȭ����ſ��е�ʨ�Ӻ���������ɽ��Ϯ��$n",
  "force" : 240,
  "dodge" : 120,
    "damage": 215,
  "lvl" : 45,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"$N��������һʽ"+(order[random(13)])+"��ֱʽ��"NOR"�������������һȭ���棬������ǰ�ˣ����������ϻ�$n",
  "force" : 260,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 65,
  "skill_name" : "ֱʽ",
  "damage_type" : "����"
]),
(["action" :"$N�ӳ���ȭ������$n�����⻨ȭ֮��ʱ��һ�ɾ��籬��������$p�ؿڣ�������ʵ��"+(order[random(13)])+"��������"NOR"",
  "force" : 280,
  "dodge" : 110,
    "damage": 215,
  "lvl" : 75,
  "skill_name" : "����",
  "damage_type" : "����"
]),
(["action" :"$N���̷𾭣����һ��"+(order[random(13)])+"��бʽ��"NOR"��ֱ��$nǰ�أ�ȭ�������������������������˿������",
  "force" : 300,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 85,
  "skill_name" : "бʽ",
  "damage_type" : "����"
]),
(["action" :"ֻ��$N��ʮ����������"+(order[random(13)])+"����ʽ��"NOR"һ��Ϊ��������Ϊȭ����������ȫ������ѹ��$n",
  "force" : 450,
  "dodge" : 115,
    "damage": 215,
  "lvl" : 105,
  "skill_name" : "��ʽ",
  "damage_type" : "����"
]),
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="unarmed" ||usage=="parry"; }     


int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("�������������û�а취���ձ���������\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 200)
   return notify_fail("���ɱ���ķ���򲻹���\n");

 if ((int)me->query_skill("xuanhualiu-quanfa", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("���������ȭ����򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("aikido", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("��ĺ�������򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("wuxing-dun", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("������жݻ�򲻹����޷�ѧ��\n");

   if( (string)me->query_skill_mapped("force")!= "shayi-xinfa")
        return notify_fail("�ձ��������������ɱ���ķ���������\n");

    return 1;
}

int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 100)
   return notify_fail("���ɱ���ķ���򲻹���\n");

 if ((int)me->query_skill("xuanhualiu-quanfa", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("���������ȭ����򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("aikido", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("��ĺ�������򲻹����޷�ѧ��\n");

 if ((int)me->query_skill("wuxing-dun", 1) < (int)me->query_skill("shiren-quanfa", 1))
   return notify_fail("������жݻ�򲻹����޷�ѧ��\n");

        if( (int)me->query("qi") < 100
        ||      (int)me->query("neili") < 100 )
                return notify_fail("�����������������û�а취��ϰ�ձ���������\n");
        me->receive_damage("qi", 80);
        me->add("neili", -80);
        //write("�㰴����ѧ����һ���ձ���������\n");
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
    object ob;
    ob = me->select_opponent();
if (!ob) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
if (!me) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

    level   = (int) me->query_skill("shiren-quanfa",1)/10;
    if (!userp(me) || (int)me->query_skill("shayi-xinfa", 1) > 10)
{
if (  me->query_skill_mapped("parry") == "shiren-quanfa"
&&  !me->is_busy()
&&living(ob)
&& !me->query_temp("dsauto")
&& !me->query_temp("sc_hama")
&& random(me->query_skill("shiren-quanfa",1))> 180
)
{
	 message_vision(HIW"\n�����ؾ�!��$N�Լ����ٵ�����,�ڵ�һ����,$nû�����ֿ���ʱ����ڶ���! \n"NOR, me,ob);
me->set_temp("dsauto",1);
	me->add_temp("apply/attack", (level*2));
	me->add_temp("apply/damage", (level*4));
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	me->add_temp("apply/attack", -(level*2));
	me->add_temp("apply/damage", -(level*4));
me->delete_temp("dsauto");
}
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

string perform_action_file(string action)
{
    return __DIR__"shiren-quanfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shiren-quanfa",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 50 && random(level2)>150 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"ֻ��$n$l����Ѫ�񱼣��ѱ������������˿���!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("shiren-quanfa", 1);

//        if( me->is_busy()) return 1;

        if( me->is_busy()) return 1;
        if( damage < 10 ) return 1;
    if ((int)me->query_skill("shayi-xinfa", 1) < 10 && userp(me)) return 1;
        if (  random(level) > 150
         && me->query_skill_mapped("parry") =="shiren-quanfa"
         && me->query_skill("unarmed") > 150
         && random(me->query_skill("unarmed",1)) > 150
           ){
         msg = HIG"$N���$n�Ĺ��ơ�����һ����ͻ������!!!��\n"NOR;
            message_vision(msg, me, ob);
            if ( random(3) == 0 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"�� ���ջ���! ����$N�����ؾ�����������Զ��������$n,�����ֲ�Զ���빥���Ĳ��� ��\n"NOR;
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
         msg = HIR"���ɺ׷���!����$Nʹ�����ֱ�Ӵ��ڵ�ȭ��֮һ����$n! ���߷��Ѷ���һ��!!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/20);
}
else
{
ob->add("qi",-4000);
ob->add("qi",-4000);
}

msg += damage_msg(damage, "����");
            }
else  if (random(3)==2 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"���������!����$Nθװ�ʹ�,�û�ʯ�Ƶļ�������������,$n������Ļ������!! \n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("eff_qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
}
else
{
ob->add("qi",-3500);
ob->add("qi",-3500);
}
msg += damage_msg(damage, "����");
            }
else
           msg = HIG"$n�ϵ���������,���˿�������������!��\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
