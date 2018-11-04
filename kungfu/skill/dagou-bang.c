// dagou-bang.c �򹷰���

#include <ansi.h>;
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"ǿ��Ѩ","�縮Ѩ","����Ѩ","��̨Ѩ","����Ѩ",}); 

string  *msg = ({

"$N����$w���Ӹ�����ʹһ��"+(order[random(13)])+"����ݾ��ߡ�"NOR"����$n��$l",

"$N����$w���һζ���һ��"+(order[random(13)])+"������Ѱ�ߡ�"NOR"��$n��$l��ȥ",

"$Nʩ��"+(order[random(13)])+"���������졹"NOR"��$w����������$n��ȥ",

"$Nʹ��һ��"+(order[random(13)])+"������˫Ȯ��"NOR"�����ð����Ȼ����ɨ$n��$l",

"$Nٿ�����$w����ͷ����$n��$l�ϣ�һ��"+(order[random(13)])+"��ѹ�繷����"NOR"���������°���",

"$N����$w�߸�����һ��"+(order[random(13)])+"������������"NOR"������$n��$l",

"$N����$w��ɨ���ң�һ��"+(order[random(13)])+"��ɨ�ظϹ���"NOR"������һƬ��Ӱ",

"$N�ֱ�һ�죬����$w��$n�������һ��"+(order[random(13)])+"�����Ŵ򹷡�"NOR"",
 
"$N$w���Եݳ���һ��"+(order[random(13)])+"������·��"NOR"������බ�Բ�������б˦",

"$Nһ��"+(order[random(13)])+"����۵�����"NOR"������$w���������������$n��$l",

});


int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query_skill("staff", 1) < 30)
                return notify_fail("��Ļ�������̫��, ����᲻�˴򹷰�����\n");

if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("��Ļ���������Ϊ������\n");
       if (((int)me->query_skill("liuhe-zhang", 1)+200) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("��������Ʒ�̫���ˡ�\n");
       if (((int)me->query_skill("fengmo-zhang", 1)+100) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("��ķ�ħ�ȷ�̫���ˡ�\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)+300) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("�����ң��̫���ˡ�\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������������\n");
        
    if ((me->query_skill("dagou-bang",1)>20) && (me->query_skill("begging",1)<101))
        if (me->query_skill("dagou-bang", 1) > me->query_skill("begging", 1)+20)
        return notify_fail("�򹷰�����Ҫ��Ӧ�ȼ��Ľл����\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
                i=me->query_skill("begging",1);
                level=me->query_skill("dagou-bang",1);
        if (i>140) i=140+i/10;
                if (level>140) level=140+level/10;

        if ( random(10) > 6
        &&      ( (int)me->query_skill("staff", 1) >= 120 ) 
        &&      ( (int)me->query_skill("dagou-bang", 1) >= 120 )
        &&      ( (int)me->query_skill("force",1) >= 120 )
        &&      ( (int)me->query("neili") >= 500 )
         ) {
                me->add("neili", -50);
                return ([
                "action": HIG"$N�������һ����â������$wʹ��"RED""+(order[random(13)])+"�������޹���"NOR""HIG"������ǵذ㹥��$n"NOR,
                "damage": 500,
                "dodge":50,
                "parry":80,
                "force": 600,
                "damage_type": "����"]);
        }
return ([
                "action":msg[random(sizeof(msg))],
                "damage":random(50)+i/2+level/2+190,
                "parry":random(i/8)+50+random(level/8),
                                "dodge":random(i/5)+60,
                "force":level+i/2+160+random(50),
                "damage_type": "����",
        ]);
       
}

int practice_skill(object me)
{
        object weapon;
     if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("jing") < 40)
                return notify_fail("��������������򹷰�����\n");  

        if ((int)me->query("neili") < 140)
                return notify_fail("��������������򹷰�����\n");  
if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("��Ļ���������Ϊ������\n");
       if (((int)me->query_skill("liuhe-zhang", 1)+200) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("��������Ʒ�̫���ˡ�\n");
       if (((int)me->query_skill("fengmo-zhang", 1)+100) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("��ķ�ħ�ȷ�̫���ˡ�\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)+300) < (int)me->query_skill("dagou-bang", 1))
               return notify_fail("�����ң��̫���ˡ�\n");
        me->receive_damage("jing",30);
        me->add("neili", -35);  
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg,name;
    int i,j,damage,a,p;
    object weapon, weapon1;     
         name = xue_name[random(sizeof(xue_name))];
    weapon = me->query_temp("weapon");
    weapon1 = victim->query_temp("weapon");
    i = me->query_skill("begging", 1);
    j = me->query_skill("dagou-bang", 1);
a=me->query("combat_exp", 1);
p=victim->query("combat_exp", 1);
    if( damage_bonus < 10 ) return 0;

if (me->query_skill_mapped("force") != "huntian-qigong")
return 0;
 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
return 0; 

if (!victim) return;

    if(j > 100 &&
       me->query_skill_mapped("parry") == "dagou-bang" &&
       me->query("neili") > 400 && me->query("max_neili") > 1000
        &&  random(j) > 150
        && random(a) > random(p)/3 ){
       if (random(4)>1){
              switch(random(4)){
            case 0 :
               message_vision(HIG"$N"+weapon->name()+"�ӳ����ԡ����־��ŵ�ɨȥ��һ���У������������������̣������������\n"NOR,me, victim);
               if (!victim->is_busy()) victim->start_busy(3);
                           if (!random(2))
                           message_vision(HIR"$n������������"+weapon->name()+"��������һ����������һ�����˵ص��ˡ�\n"NOR,me, victim);             
               else
                           message_vision(HIR"$n��δ��أ���"+weapon->name()+"����һ��һ��$n���㲻ס������һ��ˤ����\n"NOR,me, victim);             
               break;
            case 1 :
                message_vision(HIG"$Nʹ���������־�������������"+weapon->name()+"���籩���Ĵ�ȥ��\n"NOR,me, victim);
                damage = damage_bonus/10 + random(damage_bonus)/3;
if (victim->query("qi") >damage/3)
{
                victim->receive_danage("qi",damage/3);
                                victim->receive_wound("qi", damage/3);
}
                //me->add("neili", -damage/6);
                            break;
                        case 2 :
              message_vision( HIG"$Nʹ���������־�������"+weapon->name()+"ֱ��ֱ�£��㶫������������$n��Ҫ����ȥ��\n"NOR,me, victim);
                damage = damage_bonus/5 + random(damage_bonus)/10;
                if (victim->query("qi") > damage/2)
                victim->receive_wound("qi", damage/2);
                //me->add("neili", -damage/4);
              break;
            case 3 :
             message_vision( HIG"$N�����ٱ䣬ʹ���ˡ�ת���־�������"+weapon->name()+"������һ�ű�Ӱ���͵�$n���ĸ���ҪѨ��\n"NOR,me, victim);
                           if((!random(5)))
                                {
                                if (!victim->is_busy()) victim->start_busy(3);
                                //me->add("neili",-40);
                               if (victim->query("qi") > me->query_skill("dagou-bang",1)/5+damage_bonus/5)
{
                                victim->receive_damage("qi", me->query_skill("dagou-bang",1)/5+damage_bonus/4);
                                victim->receive_wound("qi", me->query_skill("dagou-bang",1)/5+damage_bonus/4);       
}
                                 message_vision(HIR"$n��"+weapon->name()+"����"RED+name+HIR"�����˵��ˣ�\n" NOR,me, victim);
                        }                 
               break;
            }
           } else if (weapon1 && random(20)<7) 
                   {
             switch(random(2)){
            case 0 :
                           if (random(2)!=1){ 
                message_vision( HIG"$N"+weapon->name()+"����������"+weapon1->name()+"����֮�������������־���˳������ǣ��! \n"NOR,me, victim);
               } else {
              message_vision( HIG"$N"+weapon->name()+"���أ�ʹ�������־�����ס"+weapon1->name()+"����˦������$n��������������"+weapon1->name()+"��! \n"NOR,me, victim);
                           }
                           if (!victim->is_busy()) victim->start_busy(3);
                           if (!random(4)){
                         message_vision( HIR"$nֻ��"+weapon1->name()+"�������ַɳ���һ�����ղ�ס�����б������Է����˹�ȥ��\n"NOR,me, victim);            
               weapon1->unequip();
               weapon1->move(environment(victim));
                           }
                           break;
            case 1 :
              message_vision( HIG"$Nʹ���������־�,"+weapon1->name()+"�ӵ�����"+weapon->name()+"���򶫣�"+weapon1->name()+"������"+weapon->name()+"�浽������Ӱ���Σ������ƵС�\n"NOR,me, victim);
               damage = damage_bonus/10 + random(damage_bonus)/5;
                                if ((int)victim->query("jing")<=damage) 
                                 { victim->set("jing",0); }
                                 else {
if (victim->query("jing") >damage)
                 victim->receive_damage("jing", damage); 
                                 }
                if (!victim->is_busy()) victim->start_busy(3);
                //me->add("neili", -damage);    
                           break;
                          }
                  }
           }
        if (random(5)==0)
        {
                victim->receive_wound("qi", (damage_bonus - 30) , me);
return HIY "ֻ��������һ����"+victim->name()+"�������İ�Ӱɨ���ڵأ�\n" NOR;
        }
}
int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        int j,neili,neili1,skill,skill1,a,p;

	object weapon;
        string msg,dodge_skill,*limbs;
        int i,  level,level2,  q;
        
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        neili = me->query("neili");
        neili1 = ob->query("neili");
        skill = me->query_skill("dagou-bang",1);
        skill1 = me->query_skill("xianglong-zhang",1);
a=me->query("combat_exp", 1);
p=ob->query("combat_exp", 1);

        limbs = ob->query("limbs");
        level = me->query_skill("dagou-bang", 1);
level2 = me->query_skill("dagou-bang", 1);

        if (  level2 > 100
        && random(3)==1 && me->query_skill_mapped("force") == "huntian-qigong"){
//if (1==1){
	
             msg = HIY"$N����ʹ�����־������־�����$n��֪����!\n"NOR;
             //if (!ob->is_busy())
             ob->start_busy(2+random(2));
           message_vision(msg, me, ob);
               }

if (me->query_skill_mapped("force") != "huntian-qigong")
return damage;

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
return damage; 


        


        if( living(me) 
         && random(skill)+20 > 180
         && skill > 100 
         && neili > 500 
         && random(a) > random(p)/3
         && me->query_skill_mapped("parry") == "dagou-bang"
         && living(ob)
         && wp 
         && random(20)>12){
            me->add("neili", -(random(50)));
         if(wp1){                    
            message_vision( HIG "$Nһ�и���������$nʹ�����⡱�־�����ӰƮƮ����ʱ���Լ�\n"
                + "��ǰ����֮�ؾ�����ס�ˡ�$N����֮�£�ֻ�к���һ�������۱仯��\n" NOR,ob,me);
         if( me->is_busy()){
            me->start_busy(1);
if (!ob->is_busy())
            ob->start_busy(3);
         }
         j = -damage;
        }           
        else{
           message_vision( HIG "$N����ָ��Ҫ����$n����ͻȻ��Ӱ������"
                   + wp->name() + HBGRN "һ�ơ��⡱�־������������޷���\n"
                   + "�����ѱ����ص�����һ�¡�$N��æ������������ɫб�������Ͼ�����һ���亹��\n" NOR,ob,me );
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
                 ob->receive_damage("qi", damage/2 > 0?damage/2:10, me);
                 ob->receive_wound("qi", damage/6 > 0?damage/10:2, me);
}
                 j = -damage;            
        }
        return j;
    }          
}
