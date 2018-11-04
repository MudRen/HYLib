// juehu-shou.c -����������
#include <ansi.h>
inherit SKILL;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

string *taijin = ({"���һ�����", "��������", "����������", "�����Ǿ���", "���������", "��մ����", "�����־���", "�����־���","�귭", "����","����","����","����","����"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$Nһʽ����ţ�����������ƻ�צ����ָ�繳�����۵ɵ�ͨ�죬ֱ��$n���ɲ�",
        "force" : 680,
        "damage" : 600,
        "dodge" : 36,
        "lvl" : 0,
        "skill_name" : "��ţ����",
        "damage_type" : "ץ��"
]),
([      "action" : "$N��֫���أ�ͷ���״�������������������ͻȻ��֫����һ���Ѵܵ�$n���£������͵��ϴ�����һʽ����ƣ������",
        "force" : 620,
        "damage" : 600,
        "dodge" : 30,
        "lvl" : 30,
        "skill_name" : "��ƣ����",
        "damage_type" : "����"
]),
([      "action" : "$N���ָ߸߾���������磬һʽ��׳ʿ���󡹣����۾ͳ�$n�����忳ȥ",
        "force" : 260,
        "damage" : 600,
        "dodge" : 15,
        "lvl" : 50,
        "skill_name" : "׳ʿ����",
        "damage_type" : "����"
]),
([      "action" : "$NһԾ����ֱ��$n��˫�����£�˫����ס$n�ľ�����һŤ����˫�ֳɹ���֮�ƣ���$n���ɲ��ݺ���ȥ������һʽ����Ҷ�����",
        "force" : 600,
        "damage" : 600,
        "dodge" : 39,
        "lvl" : 80,
        "skill_name" : "��Ҷ���",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһʽ����ǰ���󡹣�����һ��Ϊ������ֻ�����������ư㳯$n�ĺ������ɲ���ȥ",
        "force" : 660,
        "damage" : 600,
        "dodge" : 32,
        "lvl" : 120,
        "skill_name" : "��ǰ����",
        "damage_type" : "����"
]),
([      "action" : "$Nȫ��ؽ�žž���죬�����ֽ��һʽ�����Ӿ��������ӥצץ��$nȫ��Ҫ����˲������ӥצ�ֺ�Ϊһצֱ��$n���ɲ�ץ��",
        "force" : 600,
        "damage" : 600,
        "dodge" : 35,
        "lvl" : 150,
        "skill_name" : "���Ӿ���",
        "damage_type" : "ץ��"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry" || usage=="unarmed"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����������ֱ�����֡�\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 40)
                return notify_fail("���̫���񹦻�򲻹����޷�ѧ���������֡�\n");
         if ((int)me->query_skill("wudang-mianzhang", 1) < 100)
                return notify_fail("����䵱���ƻ��̫ǳ��\n");
         if ((int)me->query_skill("raozhi-roujian", 1) < 20)
                return notify_fail("�����ָ�ὣ���̫ǳ��\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷������������֡�\n");
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
        level   = (int) me->query_skill("juehu-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������������֡�\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 40)
                return notify_fail("���̫���񹦻�򲻹����޷�ѧ���������֡�\n");
         if ((int)me->query_skill("wudang-mianzhang", 1) < 100)
                return notify_fail("����䵱���ƻ��̫ǳ��\n");
         if ((int)me->query_skill("raozhi-roujian", 1) < 20)
                return notify_fail("�����ָ�ὣ���̫ǳ��\n");

        me->receive_damage("jing", 25);
        me->add("shen", -10);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"juehu-shou/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 30 ) return 0;

        if( random(3)==0 ) {
                victim->add("qi", -damage_bonus*2);
                victim->receive_wound("qi", (damage_bonus ) / 2 );
                return HIR "$n���˿ڱ�$N����һץ����Ѫ�Ľ���\n";
        }
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

        if( random(me->query("combat_exp")) > ob->query("combat_exp")/3
           && !ob->is_busy()
           && me->query_skill_mapped("parry") == "taiji-quan"
         && me->query_skill_mapped("unarmed") == "taiji-quan"
           && skill > 200)
            {
             msg = HIG"$pֻ�����̸�·��ȫ����$P˫�Ƶ�����֮�£��޿����ܣ��޿ɵ�����ֻ���˾��ڱ���Ӳ������һ�ƣ�
ͬʱ�ұ۽��ӣ�ֻ�����˸���һ�У��ɸ����ܾ���֮�֡�\n"NOR;
             if(random(20) >= 13 && me->query("neili") > 600){
                   msg += HIR"����$N˫��һȦ���籧̫����һ���ۻ��ޱȵ����������һ�����У�ֻ����$p��ԭ�ؼ�ת�߰��£�
��ת���ݣ������Ĵ���������ʹ����ǧ��׹��֮����ס���Σ�ȴ�������͵�ͨ�죬�Ǳ���״��\n"NOR;
                   ob->receive_damage("qi", me->query_skill("taiji-quan", 1)*2);
                   ob->receive_damage("jing", me->query_skill("taiji-quan", 1)/3);
  if( !ob->is_busy() )
{
                   ob->start_busy(2+random(2));
}
                   me->add("neili", -20);
                   }
             else 
{
  if( !me->is_busy() )
{
             me->start_busy(1+random(2));
}
             msg += HIY"$N������Ϣ΢�ϣ�����һ�С�б���ơ�����$N������ƫ���Լ�Ҳ�˿�������\n"NOR;
}
             message_vision(msg, me, ob);
             return 1;
        }
      if(me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("unarmed") == "taiji-quan"
         && me->query_skill_mapped("parry") == "taiji-quan"
         && me->query_skill("taiji-shengong", 1) > 50
         && neili > 100 
         && skill > 50 
         && living(me)
         && !ob->query("env/invisibility")
         && random(10) >= 3)
         {         
         if(wp1) msg = "$N˫��������̫��ԲȦ��$n��"+wp1->name()+"��һ�ƣ�";
         else msg = "$N˫�ֻ������������̫��ԲȦ��";
if (damage>50)
{
         if(neili >= neili1 + damage){
         		if( weapon ) msg = "$N����һ������$n��"+weapon->name()+"��˳��һת����������һ�ư���$p���ߣ�\n";
         		else msg = "$N����һ������ס$n������˳��һ�ƣ�����������$p�ľ���ȫ��������ȥ��\n";
              msg += "���$n��������̫��ȭ������������������\n",              

              ob->receive_damage("qi", damage/2+ob->query("jiali")*2, me);
              ob->receive_wound("qi", ob->query("jiali"), me);
}
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "����");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -8000;
              }             
           else if(neili >= neili1/2+random(neili1/2)+random(damage)){
              		if( weapon ) msg = "$N����һת��һ����������ǧ��֮�ɾ������Ŀ���$n�ݽ����"+weapon->name()+"��\n";
         		else msg = "$N����һ��������һת����������ǧ��֮�ɾ���$n������ж��һ�ԣ�\n"; 
            msg += "���$n��������̫��ȭ��������ж��һ�ԣ�\n", 
              j = -8000;
              }
           else if(neili > neili1/2+damage){
        	if( weapon ) msg = "$N�鼱֮�£�������ǧ��һ������$n�ݽ����"+weapon->name()+"֮�ԣ�ж����$pһ���־�����\n";
         	else msg = "$N��æ˫��һ�ӣ���������ǧ��֮�ɾ���$n������ж����һ���֣�\n";  

              msg += "���$n��������̫��ȭ��������ж����һ���֣�\n", 
              j = -(damage/3+random(damage));               
              }
           else{
        	if( weapon ) msg = "$N�������ǣ��ý�������֮��ʹ����΢�࣬��"+weapon->name()+"�����Լ���\n";
         	else msg = "$N��æ�ý�������֮�����ϣ���Ҫж��һ���־�����\n";  

              msg += "���$n��������̫��ȭ��������ж����һС�룡\n", 
              j = -damage/3; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}

