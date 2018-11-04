// taiji-quan.c ̫��ȭ
// ���Ӳ�ͬ���ܼ�����Ӧ��ѧϰ����ʹ����������, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()
#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";


/*string taiji_names = ({
        "���һ�����",
        "����������",
        "����������",
        "�����Ǿ���",
        "���������",
        "��մ����",
        "�����־���",
        "�����־���",
        "�����־���",
        "�귭",
        "����",
        "����",
        "����",
        "����",
        "����",
});*/
string *taijin = ({"���һ�����", "��������", "����������", "�����Ǿ���", "���������", "��մ����", "�����־���", "�����־���","�귭", "����","����","����","����","����"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$Nʹһ��"+(order[random(13)])+"����ȸβ��"NOR"��˫�ֻ��˸���Ȧ������$n��$l",
	"force" : 100,
	"dodge" : 150,
	"skill_name" : "��ȸβ",
	"lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"�����ޡ�"NOR"�������������£���������ӳ�������$n��$l",
	"force" : 220,
	"dodge" : 148,
	"skill_name" : "����",
	"lvl" : 5,
	"damage_type" : "����"
]),
([	"action" : "$N���ֻ��գ������ɹ����ƣ���������ʹһ��"+(order[random(13)])+"��������ʽ��"NOR"����$n��$l��ȥ",
	"force" : 240,
	"dodge" : 46,
	"skill_name" : "������ʽ",
	"lvl" : 10,
        "damage_type" : "����"
]),
([	"action" : "$N˫�ֻ������������ϣ��������£�ʹһ��"+(order[random(13)])+"���׺����᡹"NOR"���ֻ�$n�����ź�$l",
	"force" : 260,
	"dodge" : 144,
	"skill_name" : "�׺�����",
	"lvl" : 15,
        "damage_type" : "����"
]),
([	"action" : "$N��������ǰ���£�����΢ת������һ����Ȧ��ʹһ��"+(order[random(13)])+"��§ϥ�ֲ���"NOR"������$n��$l",
	"force" : 380,
	"dodge" : 142,
	"skill_name" : "§ϥ�ֲ�",
	"lvl" : 20,
        "damage_type" : "����"
]),
([	"action" : "$N�������������������ںϣ�ʹһ��"+(order[random(13)])+"���ֻ����á�"NOR"����$n��$l��ȥ",
	"force" : 300,
	"dodge" : 140,
	"skill_name" : "�ֻ�����",
	"lvl" : 25,
        "damage_type" : "����"
]),
([	"action" : "$N���ֱ��ƺ�����ǰ����ȭ�����´�����һ��"+(order[random(13)])+"����׿�����"NOR"������$n��$l",
	"force" : 320,
	"dodge" : 138,
	"skill_name" : "��׿���",
	"lvl" : 30,
        "damage_type" : "����"
]),
([	"action" : "$N���ǰ̤�벽������ʹһ��"+(order[random(13)])+"�������롹"NOR"��ָ������$n��$l��ȥ",
	"force" : 540,
	"dodge" : 136,
	"skill_name" : "������",
	"lvl" : 35,
        "damage_type" : "����"
]),
([	"action" : "$N��"+(order[random(13)])+"����ͨ�ۡ�"NOR"�����һ���������������Ͼ�����Ʋ������$n��$l��ȥ",
	"force" : 360,
	"dodge" : 134,
	"skill_name" : "��ͨ��",
	"lvl" : 40,
        "damage_type" : "����"
]),
([	"action" : "$N��������ԣ�ת�����������·ֱ�ӳ�������ʹһ��"+(order[random(13)])+"��б��ʽ��"NOR"������$n��$l",
	"force" : 380,
	"dodge" : 132,
	"skill_name" : "б��ʽ",
	"lvl" : 45,
        "damage_type" : "����"
]),
([	"action" : "$N�����鰴������ʹһ��"+(order[random(13)])+"���������š�"NOR"����$n��$l��ȥ",
	"force" : 500,
	"dodge" : 130,
	"skill_name" : "��������",
	"lvl" : 50,
        "damage_type" : "����"
]),
([	"action" : "$N˫����ȭ����ǰ��󻮻���һ��"+(order[random(13)])+"��˫������"NOR"����$n��$l",
	"force" : 520,
	"dodge" : 128,
	"skill_name" : "˫����",
	"lvl" : 55,
        "damage_type" : "����"
]),
([	"action" : "$N�����黮������һ��"+(order[random(13)])+"��ָ�ɴ���"NOR"����$n���ɲ�",
	"force" : 540,
	"dodge" : 126,
	"skill_name" : "ָ�ɴ�",
	"lvl" : 60,
        "damage_type" : "����"
]),
([	"action" : "$Nʩ��"+(order[random(13)])+"������ʽ��"NOR"�����ֻ���$n��$l�����ֹ���$n���ɲ�",
	"force" : 560,
	"dodge" : 124,
	"skill_name" : "����ʽ",
	"lvl" : 65,
        "damage_type" : "����"
]),
([	"action" : "$N�ɱ۴��֣�����ǰ����������ʹһ��"+(order[random(13)])+"�����֡�"NOR"������$n��$l",
	"force" : 380,
	"dodge" : 122,
	"skill_name" : "����",
	"lvl" : 70,
        "damage_type" : "����"
]),
([	"action" : "$N������������ʹһ��"+(order[random(13)])+"���𼦶�����"NOR"����$n��$l��ȥ",
	"force" : 400,
	"dodge" : 120,
	"skill_name" : "�𼦶���",
	"lvl" : 75,
        "damage_type" : "����"
]),
([	"action" : "$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ��"+(order[random(13)])+"����̽��"NOR"",
	"force" : 420,
	"dodge" : 118,
	"skill_name" : "��̽��",
	"lvl" : 80,
        "damage_type" : "����"
]),
([	"action" : "$N����ʹһʽ��"+(order[random(13)])+"����Ů����"NOR"��������$n��$l��ȥ",
	"force" : 440,
	"dodge" : 116,
	"skill_name" : "��Ů����",
	"lvl" : 85,
        "damage_type" : "����"
]),
([	"action" : "$N���־���ǰ��������ǰƲ����ʹһ��"+(order[random(13)])+"������Ʋ����"NOR"����$n��$l��ȥ",
	"force" : 460,
	"dodge" : 114,
	"skill_name" : "����Ʋ��",
	"lvl" : 90,
        "damage_type" : "����"
]),
([	"action" : "$N�����鰴������ʹһ��"+(order[random(13)])+"��ת����ȡ�"NOR"����$n��$l��ȥ",
	"force" : 480,
	"dodge" : 112,
	"skill_name" : "�������",
	"lvl" : 95,
        "damage_type" : "����"
]),
([	"action" : "$N�������ϻ�������������ʹһ��"+(order[random(13)])+"����������"NOR"����$n��$l��ȥ",
	"force" : 400,
        "damage" : 50,
	"dodge" : 110,
	"skill_name" : "��������",
	"lvl" : 100,
        "damage_type" : "����"
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"���Դ���"NOR"������§��ϥ���������´���$n��$l",
	"force" : 420,
        "damage" : 180,
	"dodge" : 8,
	"skill_name" : "�Դ�",
	"lvl" : 110,
        "damage_type" : "����"
]),
([	"action" : "$N˫���ȱ�����״�����طֿ������������£�һ��"+(order[random(13)])+"��Ұ����ס�"NOR"����$n��$l�����Ŵ�ȥ",
	"force" : 400,
        "damage" : 100,
	"dodge" : 116,
	"skill_name" : "Ұ�����",
	"lvl" : 120,
        "damage_type" : "����"
]),
([	"action" : "$N��������ǰ���£��ұ�΢����ʹһ��"+(order[random(13)])+"��������ɽ��"NOR"����$n��$l��ȥ",
	"force" : 400,
        "damage" : 100,
	"dodge" : 114,
	"skill_name" : "������ɽ",
	"lvl" : 130,
        "damage_type" : "����"
]),
([	"action" : "$N˫�־��¸�����������ǰ����ʮ��״��һʽ"+(order[random(13)])+"��ʮ���֡�"NOR"����$n��$l��ȥ",
	"force" : 420,
	"dodge" : 112,
	"skill_name" : "ʮ����",
	"lvl" : 140,
        "damage_type" : "����"
]),
([	"action" : "$N���̤һ���鲽��˫�ֽ����ʮ��ȭ��һ��"+(order[random(13)])+"���������ǡ�"NOR"����$n��$l��ȥ",
	"force" : 440,
	"dodge" : 110,
	"skill_name" : "��������",
	"lvl" : 150,
        "damage_type" : "����"
]),
([	"action" : "$N��������ڳ���������ֱ���ұ�΢����ʹһ��"+(order[random(13)])+"������"NOR"����$n��$l�����Ŵ�ȥ",
	"force" : 460,
        "damage" : 100,
	"dodge" : 112,
	"skill_name" : "�����",
	"lvl" : 160,
        "damage_type" : "����"
]),
([	"action" : "$N˫���쿪������Ϊ�ᣬ����������һ����Բ����\nһ��"+(order[random(13)])+"��ת�������"NOR"����$n�������¶�������������Ӱ֮��",
	"force" : 480,
        "damage" : 100,
	"dodge" : 114,
	"skill_name" : "ת�����",
	"lvl" : 170,
        "damage_type" : "����"
]),
([	"action" : "$N˫����ȭ�����ֻ����������ʣ����ֻ�����ǰ�Ƴ���\nȭ�������һ��"+(order[random(13)])+"���乭�仢��"NOR"��ֱ��$n���Ѷ�ȥ",
	"force" : 490,
        "damage" : 100,
	"dodge" : 116,
	"skill_name" : "�乭�仢",
	"lvl" : 180,
        "damage_type" : "����"
]),
([	"action" : "$N˫������ǰ���ƣ��ɸ�����ǰ�����Ƴ���һ��"+(order[random(13)])+"������Ʊա�"NOR"��һ�ɾ���ֱ��$n",
	"force" : 500,
        "damage" : 100,
	"dodge" : 118,
	"skill_name" : "����Ʊ�",
	"lvl" : 200,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫��ȭ������֡�\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ̫��ȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���̫��ȭ��\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/* ----------------
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
-------------------*/

mapping query_action(object me, object weapon)
{
	int i, level;
	string msg;
	level = (int) me->query_skill("taiji-quan",1);
msg = random(2)==1?HIW"ֻ��$N���鶥�������ذα����������Ρ�����׹�⣬˫�ֱ��˸�̫��ʽ��ԲȦ����������̫�����Ѵ������һ���Ķ������ľ��磬\n���ʹ����̫��ȭ�е�"NOR:
HIW"ɲʱ��$N����̫��ȭּ�С����ɷ��ɣ���չδչ�������ⲻ�ϡ��ľ�΢����֮����ʹ��һ������������ˮ�������ޱȡ�\n���ʹ����̫��ȭ�е�"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
        if ( level > 250 
        && random(level) > 200
        && random(10)>5)
        	return ([  
                	"action" : msg,
                	"force" :  500,
                	"dodge":   100,
                	"damage":   500,
                	"parry":   100,
                	"damage_type" : random(2)==1?"����":"����",
        	]);
        	
        if (random(me->query_con()) > 25 && random(20) >= 15 &&
        level > 200 && me->query("neili") > 600){   
           me->add("neili", -30);    
              return ([
                "action": HIW"$N����������������Ŀ������$n��������$p������£������������ɽ��ȴ����������"NOR,
                "force" : 500,
                "dodge" : 200,
                "damage" : 550,
                "damage_type" : "����",
                "skill_name" : "������",
                "lvl" : 200,
                ]); 
        }         

        if (random(me->query_con()) > 25 && random(20) >= 15 &&
        level > 200 && me->query("neili") > 600){   
           me->add("neili", -30);    
              return ([
                "action": HIW"$N����������������Ŀ������$n��������$p������£������������ɽ��ȴ����������"NOR,
                "force" : 500,
                "dodge" : 200,
                "damage" : 550,
                "damage_type" : "����",
                "skill_name" : "������",
                "lvl" : 200,
                ]); 
        }         
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������̫��ȭ��\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
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
           if (!ob->is_busy() && random(3)==0)
{
                ob->start_busy(3);  
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

mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg;
    int j,damage;
    j = me->query_skill("taiji-quan", 1);
   
    if( damage_bonus < 100 ) return 0;
    if(random(20) >= 13 && !victim->is_busy() && j > 120 &&
       me->query("neili") > victim->query("neili") &&
       me->query_skill_mapped("parry") == "taiji-quan" &&
        me->query_skill("taiji-shengong", 1) > 50 &&
       me->query_skill_mapped("unarmed") == "taiji-quan" &&
       me->query("neili") > 600 && me->query("max_neili") > 1200 &&
        j > random(victim->query_skill("dodge",1))){
        switch(random(4)){
            case 0 :
               msg = YEL"$N�������־���ճ��ճ�棬�����Ѵ�ס$n�����ɾ��漴������\n"NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/10);
               break;
             case 1 :
               msg = YEL"$N�����־���˫��һȦ���籧̫����һ���ۻ��ޱȵ����������һ�����У�\n"NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/10);
                break;
            case 2 :
               msg = YEL"$N��ճ���־���˫�ֻ�������Ȧ��Χ��һ������һ����̫��ԲȦ����������\n"NOR;
                damage = damage_bonus/4 + random(damage_bonus)/5;
                                if ((int)victim->query("jing")<=damage+10) 
                                 { victim->set("jing",10); }
                                 else {
                 victim->receive_damage("jing", damage); 
                                 }
           if (!victim->is_busy())
{
                victim->start_busy(2);  
}
                me->add("neili", -20);     
               break;
            case 3 :
               msg = YEL"������$N����̫��ȭ��ճ����������������ʽ���뽫$n���Ӵ��ᣡ\n"NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
                if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/10);
               break;
            }
        switch(random(4)){
         case 0 : msg += HIR"���$n����������ǰһ�壬�����������ʼվ����\n"NOR; break;
         case 1 : msg += HIR"���$n����������ԭ�ؼ�ת���߰��£���ת���ݣ������Ĵ���\n"NOR; break;
         case 2 : msg += HIR"��ʱ���׵�$n����ײײ�������������㲻�ȣ������оƻ��ԡ�\n"NOR; break;
         case 3 : msg += HIR"$n��ʹ��ǧ��׹֮����ס���Σ�ȴ�������͵�ͨ�죬���ɼ����Ǳ���״��\n"NOR; break;
         }
        message_vision(msg, me, victim);
        }
}	