#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
 string *parry_msg = ({
                        "$n�������ƣ���������Ц̸������ūѪ�������е�$v���¶��ϣ�������$N��$w��\n",
                        "$n��������ƾ������������Ъ�������е�$v����ܲ�͸�磬��$N��$w�������⡣\n",
                        "$n�������е�����Ī���а�������ͷ���ձ��С������е�$v����������գ�������$N��$w��\n",
                        "$n���е�$vһ����ǹ��������$N��$w�������ȥ��\n",
});

 string *unarmed_parry_msg = ({
                        "$nʹ��һ�С�ŭ����ڡ��������е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
                        "$nʹ��һ�С�׳�����ҡ�����������ʧ��һ��ǹӰ֮�С�\n",
                        "$n����ת��$vֱ��$N��˫�֡�\n",
                        "$n�����е�$vһ�����������ǹӰ���ȵ�$N�������ˡ�\n",
});

mapping *action = ({

        ([      "action":               
"$N����$w������������Ϻ��£�����һ��"+(order[random(13)])+"��ŭ����ڡ�"NOR"��ǹ�淺��һƬ���⣬����$n��$l!",
                "damage":               370,
                "dodge":                40,
                "parry":                40,
                "force":                300,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ������������ʹ��һ��"+(order[random(13)])+"��������Ъ��"NOR"�����ν����繭����$wΪ������$nһ���������������$n��",
                "damage":               360,
                "dodge":                70,
                "parry":                30,
                "force":                350,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����������ȴ��$n���֮�ʣ�ʹ��һ��"+(order[random(13)])+"��̧���ۣ����쳤Х��"NOR"������ǹ����������������$n$l��",
                "damage":               360,
                "dodge":                30,
                "parry":                60,
                "force":                375,                
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ע$w����򵥵��ĺỮ��ȥ��һ��ƽ����"+(order[random(13)])+"��׳�����ҡ�"NOR"����$N���о�����˹������",
                "damage":               380,
                "dodge":                60,
                "parry":                40,
                "force":                375,           
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ�Σ�ת����ߣ�ͻȻһ��"+(order[random(13)])+"��Ī���У���������ͷ���ձ��С���"NOR"��Ҹ�´̳���$n����ʱ��ǹ�������߰�̵�$n��ǰ��",
                "damage":               360,
                "dodge":                30,
                "parry":                60,
                "force":                350,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�߾٣���������һʽ"+(order[random(13)])+"�������ܣ���δѩ��"NOR"����ֱ�����£�$n������������¯����֪���롣",
                "damage":               360,
                "dodge":                30,
                "parry":                60,
                "force":                350,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
                       ([      "action":               
                                        "$N��������: "+(order[random(13)])+"������ͷ��ʰ��ɽ�ӣ������ڡ���"NOR"������$w��ת��ǹ��\n�������ϣ�ֱ��$n��$l��ȥ",
                                "dodge":                32,
                                "parry":                20,
                                "force" :               340,
                "damage":               360,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N��̾����"+(order[random(13)])+"�������ܣ���δѩ�����Ӻޣ���ʱ�𣡡�"NOR"������$w�γ�����\nǹӰ����Ȼһǹ��$n��$l��ȥ",
                                "dodge":                30,
                                "parry":                40,
                                "force":               315,
                "damage":               360,
                           "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N�����ɫ��������"+(order[random(13)])+"����ʮ��������������"NOR"ǹ��ͻת����$n������ɨȥ",
                                "dodge":                30,
                                "parry":                30,
                                "force":               350,
                "damage":               360,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nһ����Х��"+(order[random(13)])+"���ݳ�����̤�ƺ���ɽȱ����"NOR"����̤����ǰ����������$w\nƽƽ�ݳ���ֱȡ$n��$l",
                                "force":                330,
                                "dodge":                20,
                                "parry":                30,
                "damage":               360,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N��ͷ��Ŷ��"+(order[random(13)])+"����ǧ��·�ƺ��¡�"NOR"������$w�����㣬��ؽ�������\n��$nɨ��һ��ǹӰ",
                                "dodge":                30,
                                "parry":                30,
                                "force":               330,
                "damage":               360,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N�����������е���"+(order[random(13)])+"��׳־���ͺ�²�⡹"NOR"�����г�ǹ������ң����Ʋ�����ļȻ��\n����$n��$l��ȥ",
                                "dodge":                56,
                                "parry":                13,
                                "force":               310,
                "damage":               360,
                                "damage_type":  "����"
                        ]),
});
 
int valid_enable(string usage) { return  (usage == "club") || (usage =="parry"); }
 
int valid_learn(object me)
{
           mapping fam  = me->query("family");
         if ((int)me->query("max_neili") < 1500)
                return notify_fail("�������������\n");

if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("��Ļ���������Ϊ������\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 150)
               return notify_fail("��������Ʒ�̫���ˡ�\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 150)
               return notify_fail("��ķ�ħ�ȷ�̫���ˡ�\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 150)
               return notify_fail("�����ң��̫���ˡ�\n");
       if (((int)me->query_skill("dagou-bang", 1)) < 150)
               return notify_fail("��Ĵ򹷰�̫���ˡ�\n");
       if (((int)me->query_skill("chansi-shou", 1)) < 150)
               return notify_fail("�������̫���ˡ�\n");
       if (((int)me->query_skill("suohou-gong", 1)) < 150)
               return notify_fail("��Ĳ�˿������̫���ˡ�\n");
                              
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������̫�����޷�����\n");
   
   
         return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"yuejia-qiang/" + action;
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
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("yuejia-qiang",1);

         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}
 mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("huntian-qigong",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "huntian-qigong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIG"$Nʹ��һ�С�׳�����ҡ�����������ʧ��һ��ǹӰ֮��!\n"NOR;
}
if (damage_bonus <20) damage_bonus=20;
      if( random(me->query_skill("yuejia-qiang",1)) > 150 ) 
{
	  victim->receive_wound("qi", (damage_bonus)/2+120);
        return HIR "$Nʹ��һ�С�ŭ����ڡ��������е�$w����ܲ�͸��!\n"NOR;
}
}

int practice_skill(object me)
{
         object weapon;
if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("��Ļ���������Ϊ������\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 150)
               return notify_fail("��������Ʒ�̫���ˡ�\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 150)
               return notify_fail("��ķ�ħ�ȷ�̫���ˡ�\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 150)
               return notify_fail("�����ң��̫���ˡ�\n");
       if (((int)me->query_skill("dagou-bang", 1)) < 150)
               return notify_fail("��Ĵ򹷰�̫���ˡ�\n");
       if (((int)me->query_skill("chansi-shou", 1)) < 150)
               return notify_fail("�������̫���ˡ�\n");
       if (((int)me->query_skill("suohou-gong", 1)) < 150)
               return notify_fail("��Ĳ�˿������̫���ˡ�\n");
      		
         if (!objectp(weapon = me->query_temp("weapon"))
                  || (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԡ�\n");
         if ((int)me->query("jing") < 70)
                return notify_fail("�������������\n");
         if ((int)me->query("neili") < 40)
                return notify_fail("�������������\n");
                
 me->receive_damage("jing", 30);           
         if((int)me->query_skill("yuejia-qiang",1)> 200)
 me->add("neili",-10);

         return 1;
}



int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        int j,neili,neili1,skill,skill1,a,p;

	object weapon;
        string msg,dodge_skill,*limbs,wpname;
        int i,  level,level2,  q;
        
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        neili = me->query("neili");
        neili1 = ob->query("neili");
        skill = me->query_skill("yuejia-qiang",1);
        skill1 = me->query_skill("yuejia-qiang",1);
a=me->query("combat_exp", 1);
p=ob->query("combat_exp", 1);

        limbs = ob->query("limbs");
        level = me->query_skill("yuejia-qiang", 1);
level2 = me->query_skill("yuejia-qiang", 1);
if (wp)
{
wpname=wp->query("name");
        if (  level2 > 100
        && random(3)==1 && me->query_skill_mapped("force") == "huntian-qigong"){
//if (1==1){
	
             msg = HIY"$N�������ƣ���������Ц̸������ūѪ�������е�"+wpname+"���¶��ϣ������˼���ǹ������$n��֪����!\n"NOR;
             ob->start_busy(2+random(2));
           message_vision(msg, me, ob);
               }

if (me->query_skill_mapped("force") != "huntian-qigong")
return damage;

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
return damage; 

        if( living(me) 
         && random(skill)+20 > 180
         && skill > 100 
         && neili > 500 
         && random(a) > random(p)/3
         && me->query_skill_mapped("parry") == "yuejia-qiang"
         && living(ob)
         && wp 
         && random(20)>12){
            me->add("neili", -(random(50)));
         if(wp1){                    
             msg = YEL "$N��������ƾ������������Ъ�������е�"+wpname+"����ܲ�͸�磬��$n�������⡣\n" NOR;
           message_vision(msg, me, ob);
         if( me->is_busy()){
            me->start_busy(1);
if (!ob->is_busy())
            ob->start_busy(3);
         }
         j = -damage;
        }           
        else{
             msg = GRN "$N�������е�����Ī���а�������ͷ���ձ��С������е�"+wpname+"����������գ�������$N��\n" NOR;
           message_vision(msg, me, ob);

           if( me->is_busy()){
                 me->start_busy(1);
if (!ob->is_busy())
                 ob->start_busy(3);
            }
            else
                 if (!ob->is_busy())
                 ob->start_busy(3);
if (ob->query("qi") > damage/2)
{
                 ob->receive_damage("qi", random(level2)+30);
                 ob->receive_wound("qi", random(level2)+30);
}
                 j = -damage;            
        }

}
        return j;
    }          
}
