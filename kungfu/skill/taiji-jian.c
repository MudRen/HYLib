// taiji-jian.c ̫����
// cleansword 2/15/96
// Marz 5/21/96
#include <ansi.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string *dir = ({
"����",
"����",
"���",
"�Ҳ�",
"����",
});
string *taijin = ({"���һ�����", "��������", "����������", "�����Ǿ���", "���������", "��մ����", "�����־���", "�����־���","�귭", "����","����","����","����","����"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([  "action" : "$N�鲽������һ�С�"+HIM+"���ѵ�ˮ"+NOR+"��������$w���������һ��������$n��$l",
    "force" : 160,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 0,
    "damage_type" : "����"
]),
([  "action" : "$N��ǰ����һ�������ֽ���������$wʹ��һʽ��"+YEL+"ָ����"+NOR+"��ֱ��$n��$l",
    "force" : 170,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 10,
    "damage_type" : "����"
]),
([  "action" : "$N��������һ�죬���ֽ���������$wʹ��һʽ��"+WHT+"�����"+NOR+"������$n��$l",
    "force" : 180,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 15,
    "damage_type" : "����"
]),
([  "action" : "$N˫ϥ�³�������$wʹ��һʽ��"+BLU+"̽��ʽ"+NOR+"�������¶��ϼ���$n��$l",
    "force" : 190,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 26,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIW+"�����Ӳ�"+NOR+"����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
    "force" : 100,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 37,
    "damage_type" : "����"
]),
([  "action" : "$N���������һš��һ�С�"+BLK+"������β"+NOR+"��������$w������$n��$l��ȥ",
    "force" : 110,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 48,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+RED+"��"+NOR+"��ɨ����һ�С�"+RED+"��"+NOR+"��ɨ��������ƽָ��һ���ǳɺ�ɨ$n��$l",
    "force" : 120,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 50,
    "damage_type" : "����"
]),
([  "action" : "$N������ϥ������$wбָ��һ�С�"+HIC+"����Ͷ��"+NOR+"������$n��$l",
    "force" : 130,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 60,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+CYN+"������ˮ"+NOR+"����$w���¶��ϻ���һ���󻡣�ƽƽ�ػ���$n��$l",
    "force" : 140,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 70,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ����"+RED+"��"+NOR+"����"+HIW+"��"+NOR+"����$w��������ԲȦ������ֱ�������಻�ϻ���$n��$l",
    "force" : 150,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 80,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+MAG+"����Ҷ"+NOR+"����$w����ػ�������Բ����Ѹ�ٵ���$n��$l��ȥ",
    "force" : 160,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 100,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"����ͷ"+NOR+"����$w����һ������ҸߵĴ󻡣�бб��ն��$n��$l",
    "force" : 170,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 120,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ����"+HIR+"ʨ��ҡͷ"+NOR+"����$w�������󻮳�һ�����֣���$nȦ������",
    "force" : 180,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 141,
    "damage_type" : "����"
]),
([  "action" : "$N���̤ʵ���ҽ���㣬һ�С�"+HIW+"����ָ·"+NOR+"��������$w����һ�Ž���������$n��$l",
    "force" : 190,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 162,
    "damage_type" : "����"
]),
([  "action" : "$N����Ծ��һ�С�"+CYN+"Ұ������"+NOR+"����$w�ڰ���л�ΪһȦ��â������$n��$l",
    "force" : 200,
"damage" : 100,
	"dodge" : 116,
	"parry" : 116,
    "lvl" : 184,
    "damage_type" : "����"
]),
([  "action" : "$N����ǰ���󹭣�һ�С�"+HIR+"����ʽ"+NOR+"��������$wֱ��$n��$l",
    "force" : 210,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 205,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"С����"+NOR+"������������һ�죬���ֽ���������$wƽƽ����$n��$l��ȥ",
    "force" : 220,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 210,
    "damage_type" : "����"
]),
([  "action" : "$N������ϣ�һ�С�"+HIW+"��Գ�׹�"+NOR+"��������$wбб����$n��$l��ȥ",
    "force" : 230,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 220,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+RED+"ӭ�絧��"+NOR+"����$w���������һ�ӣ�$nȴ����һ�ɾ���ӭ��Ϯ����",
    "force" : 240,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 225,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"˳ˮ����"+NOR+"����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ��",
    "force" : 250,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 230,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"���Ǹ���"+NOR+"����$w����$n��$l",
    "force" : 260,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 235,
    "damage_type" : "����"
]),
([  "action" : "$NͻȻ�̶���������һ�С�"+BLU+"��������"+NOR+"����$w���¶��ϵ���$n��$l��ȥ",
    "force" : 270,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 240,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIG+"����ʽ"+NOR+"����$w���¶������컮��һ���󻡣�ƽƽ����$n��$l��ȥ",
    "force" : 300,
"damage" : 100,
	"dodge" : 116,
	"parry" : 116,

    "lvl" : 245,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"�Ʒ��붴"+NOR+"����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
    "force" : 320,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 250,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"����չ��"+NOR+"��������Ծ������$w����$n��$l",
    "force" : 330,
"damage" : 100,
	"dodge" : 116,
	"parry" : 116,
    "lvl" : 255,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+BLK+"���ֽ�"+NOR+"����$w����һƬ���̣�ƽƽ����$n��$l��ȥ",
    "force" : 350,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 260,
    "damage_type" : "����"
]),
([  "action" : "$N��������棬������ǰһ�ˣ�һ�С�"+BLU+"�����п�"+NOR+"����$w��$n��$l��ȥ",
    "force" : 360,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 265,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"��ɨ÷��"+NOR+"��������Ծ�ڰ�գ�����$wɨ��$n��$l",
    "force" : 380,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 260,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIC+"ȴ���齣"+NOR+"�������Ծ����أ�$w�س飬���ֹ���$n��$l",
    "force" : 400,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 270,
    "damage_type" : "����"
]),
([  "action" : "$N���Ȱ�����ף�һ�С�"+WHT+"����Ʊ�"+NOR+"����������ָ��ת������$n��$l",
    "force" : 420,
"damage" : 100,
	"parry" : 116,
	"dodge" : 116,
    "lvl" : 280,
    "damage_type" : "����"
]),
([  "action" : "$N����š���������鱧��һ�С�"+HIY+"����հ��"+NOR+"����$w�й�ֱ��������$n��$l",
    "force" : 450,
	"parry" : 116,
"damage" : 100,
	"dodge" : 116,
    "lvl" : 300,
    "damage_type" : "����"
]),
});


int valid_enable(string usage)
{ return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 20)
                return notify_fail("��ġ�̫���񹦡����̫ǳ��\n");

        if ((int)me->query_skill("taiji-quan", 1) < 20)
                return notify_fail("��ġ�̫��ȭ�����̫ǳ��\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
       int  j, damage;
        string str;
        i = random(me->query_skill("force"))+50;
        if(i<100) i = 100;
        if(i>300) i = 300;
        j = random(40)-10;
        damage = (random(6)+1)*55;
        if(damage < 50) damage =50;

// ��ָ�ὣ
        if(me->query_temp("tjj/raozhi") && random(10) > 5){
              switch(random(3)) {
                case 0:
                str = HIR"$N��������ע�ڽ��ϣ���$n"+dir[random(sizeof(dir))]+"��ȥ��ͻȻ��$N�Ľ�����"+dir[random(sizeof(dir))]+"Ȧת����������$n��$l��\n"NOR; break;
                case 1:
                str = HIR"$N���н�������$n" + dir[random(sizeof(dir))] + "��ҪѨ��$n��æ�ر���ȴ��$N����һ�䣬ת������$n ��$l��\n"NOR; break;
                case 2:
                str = HIR"$N$w���裬�����Ҳ�����Ȼ��һ����$n��̴�д�Ѩ��ȥ����δ��$n��ߣ�ͻȻ��ת��$n��" + dir[random(sizeof(dir))]+"��\n"NOR; break;
                }

                if(objectp(weapon))
                        str = replace_string(str, "$w", weapon->name()+HIR);       
                return ([
                        "action":str,
                        "damage":damage*3,
                        "damage_type": "����",
                        "dodge": (j+11)*10,
                        "force": i+random(i/2),
                ]);
        }

        if(me->query_temp("tjj/sanhuan")){
                switch(me->query_temp("tjj/sanhuan")){
                        case 3: str = HIC"$Nʹ�����������¡�����ʽһ�䣬���ָ����ѣ������н������������������һ��Բ����$w"HIC"��$n��������"NOR; break;
                        case 2: str = HIC"Ȼ��$N�ƽ�һ�����������У��������У�ͬ��һ�����Żӳ�����������������һ��ͣ�ٵĺۼ�"NOR; break;
                        case 1: str = HIC"������ӣ�$N���е�$w"HIC"��һ�λӳ�����$n$l���������������������������������ͬ�����ϵ�������֮��"NOR; break;
                        default: str = HIC"$Nʹ�����������¡�����ʽһ�䣬���ָ����ѣ������н������������������һ��Բ����$w"HIC"��$n��������"NOR; break;
                }
                me->add_temp("tjj/sanhuan", -1);      
                return ([
                        "action":str, 
                        "damage":damage*3,
                        "damage_type": "����",
                        "dodge": j+10,
                        "force": i+random(i/2),
                ]);
        }
    level   = (int) me->query_skill("taiji-jian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
if (level>50)
{
//    a_action["dodge"]  = level/5;
//    a_action["parry"]  = level/5;
    a_action["attack"]  = level;
    a_action["damage"] = level/2;
}
    return a_action;

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "sword")
           return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
           return notify_fail("�������������̫��������\n");
        me->receive_damage("qi", 30);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"taiji-jian/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    object weapon, weapon1;     
    weapon = me->query_temp("weapon");
    weapon1= victim->query_temp("weapon");

    if (random(me->query_skill("taiji-jian",1)) < 80 || me->query_skill("force",1) < 150 )
    return 0;
    if (random(me->query_skill("taiji-jian",1)) > 180 &&	
    random(me->query_skill("sword",1))>180 &&
	 me->query_skill("force",1) > 220)
{
        me->add("neili", -50);
  if( !victim->is_busy() )
{        victim->start_busy(2);
}
        return HIY"$n��æ���ң����Ҳ�����\n"NOR;
} 
        if (random(me->query_skill("taiji-jian",1)) > 150 &&
        random(me->query_skill("sword",1))>150 &&
      	me->query_skill("force",1) > 180 )	
{
        victim->add("neili", -400);
	return HIW"$nʹ������������ѳ�̫�����Ľ�Ȧ��\n"NOR;
}
        if (random(me->query_skill("taiji-jian",1)) > 120 &&	
        random(me->query_skill("sword",1))>100 &&  
	  me->query_skill("force",1) > 150 )	
{
  if( !victim->is_busy() )
{        victim->start_busy(2);
}
	return HIG"$n��ʱ�����޴룬��֪����Ǻã�\n"NOR;
 } 

    if(weapon1 && me->query_skill("taiji-jian", 1) > 150 && me->query("jiali")
       && me->query("max_neili") > 800 && me->query("neili") > 800 && random(10) >= 7
       && random(me->query_int()) > 25 
       && me->query_skill_mapped("parry") == "taiji-jian"
       && me->query("combat_exp") > victim->query("combat_exp")){
      message_vision(HIM"$N���ֽ���б����"+weapon->name()+HIM"������Բ��ƽ����$n"+weapon1->name()+HIM"�����ϣ�����������"+weapon1->name()+HIM"��ʱһ����\n"NOR, me,victim);
      if(random(me->query("str")) > victim->query("str")/2
       && random(10)>6)
           {           
           me->add("neili", -50);
           message_vision(HIR"\n$N��ʽ����ɬ�ͣ�ֻ��������"+weapon1->name()+HIR"���Ʋ��ϵ�������������һ���ѳֲ��������ַɳ���\n"NOR, victim);
           weapon1->unequip();
           weapon1->move(environment(victim));
           }
      else{
           message_vision(HIY"$Nһ��ʹ���������˵ò��㣬��"+weapon->name()+HIY"������ת����Ȧ�ӣ�����"+weapon1->name()+HIY"һ����Щ���֣�\n"NOR, victim);
  if( !victim->is_busy() )
{
           victim->start_busy(2);
}
           }
    }
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("taiji-jian", 1);
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

      if(me->query("jiali") && random(skill) > random(ob->query_skill("parry", 1)) 
         && me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("parry") == "taiji-jian"
         && me->query_skill("taiji-shengong", 1) > 50
         && neili > 300 && skill > 50 && living(me)
         && objectp(wp) && wp->query("skill_type")== "sword"
         && !ob->query("env/invisibility"))
         {        
         if(random(2)==1) me->add_temp("fanzhen", 1);    
         if(objectp(wp1)) msg = "$N����"+wp->name()+"бָ��̫��ԲȦ��$n��"+wp1->name()+"��һ�";
         else msg = "ֻ��$Nʹ��������ǧ��֮�ɾ�������б����";
           if(neili >= neili1+random(neili1)+damage){
 if (damage <10 )damage=10;
              msg += "���$n��������������������������\n",
               ob->receive_damage("qi", damage/2, me);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "����");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -8000;
              }             
           else if(neili >= neili1){
              msg += "���$n��������ж��һ�ԣ�\n", 
              j = -8000;
              }
           else if(neili < random(neili1)+damage && neili*2 > random(neili1)+damage){
              msg += "���$n��������ж����һ�룡\n", 
              j = -damage/2;               
              }
           else{
              msg += "���$n������ֻ��ж����һС�룡\n", 
              j = -damage/3; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}
