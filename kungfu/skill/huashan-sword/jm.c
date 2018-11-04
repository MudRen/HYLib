// jianmang.c 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;                                        
void check_fight(object me, object target, int improve);
private int remove_effect(object me, int improve);

string *name1 = ({ "����Ѩ", "���Ѩ", "����Ѩ", "����Ѩ", "����Ѩ", "�Ϲ�Ѩ",
                   "���Ѩ", "̫��Ѩ", "����Ѩ", "��ǿѨ", "��̨Ѩ" });

int perform(object me)
{       
        string msg, name, name2;
        int damage;

        object target;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( me->is_busy())
                return notify_fail("��������æ���ء�\n"); 
        if( !me->is_fighting() )
                return notify_fail("����â��ֻ����ս����ʹ�á�\n");
        if( !target || !target->is_character() ||!me->is_fighting(target) )
                return notify_fail("����â��ֻ����ս���жԶ���ʹ�á�\n");
        if( target->query("qi") <= 50 && me->is_fighting(target) )
                return notify_fail("������û�б�Ҫ�á���â�����������ˡ�\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "huashan-sword")
             return notify_fail("�������޷�ʹ�á���â���������ˡ�\n");

        if(  me->query_temp("perform") 
        ||   me->query_temp("perform2")
        ||   me->query_temp("perform3") )
             return notify_fail("�����������š���â���ء�\n");

        if( (int)me->query_skill("huashan-sword", 1) < 90 ||
            (int)me->query_skill("sword", 1) < 90 ||
            (int)me->query_str() < 25   ||
            (int)me->query_dex() < 25)  
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á���â����\n");

         if((int)me->query_skill("zixia-shengong", 1) < 80)
            return notify_fail("�����ϼ����Ϊ�������޷����򡸽�â���ľ��衣\n");


        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������̫�����޷�ʹ�ó�����â����\n");
        
        if( (int)me->query("neili") < 200 )
                return notify_fail("�������������\n");
                
        name = name1[random(sizeof(name1))];    
        name2 = weapon->query("name");
        msg =  HIC"\n$N���ֽ���һת������"+name2+"ֱ������ʱʹ$N��һƬ���������֣�����һ֧��â����$n��"+name+"��\n" NOR;
        
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3)
        {                
                msg += HIR "���һ�����У�$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;   
                target->start_busy(2);
                me->add("neili", -200);
                me->set_temp("perform", 1);
                if( (int)me->query_skill("huashan-sword", 1) > 110
                &&  (int)me->query("neili") > 300
                  &&  me->is_fighting(target) 
                &&  me->query_skill_mapped("sword") == "huashan-sword"
                &&  (string)weapon->query("skill_type") == "sword" ) 
                {
                        call_out("perform2", 0, me);    
                }
                else 
                {
                        me->delete_temp("perform");
                }
        } 
        else 
        {
                me->start_busy(2);
                me->add("neili", -100);
                me->delete_temp("perform");
                target->add("neili", -50);
                target->start_busy(1);
                msg += HIY"\n$p���һ�����ã�ȫ������һ�ݣ�˳�����˿�ȥ��\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}                   
                                       
int perform2(object me)
{
        string msg, name, name2;
        int damage;   
        object target;
        object weapon = me->query_temp("weapon");
if (!me)  return notify_fail("���Ѿ������ˡ�\n");
        if (!weapon)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
 return notify_fail("��û��������\n");
}

        name2 = weapon->query("name");
        
        if( !target ) target = offensive_target(me);   
        name = name1[random(sizeof(name1))];
        if (!target)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
 return notify_fail("�����Ѿ������ˡ�\n");
}
       
        msg = MAG"\n����$N̤ǰһ����"+name2+"�����ĵڶ�֧��â���յ���$n��"+name+"����Ѩ�������֮�\n"NOR;        
        
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {
                me->start_busy(1);
                target->start_busy(1);
                me->delete_temp("perform");
                damage = (int)me->query_skill("huashan-sword", 1);
                damage = (int)me->query_skill("sword", 1) +damage;
                damage = (int)me->query_skill("zixia-shengong", 1) +damage;
                damage = damage + random(damage/2);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -300);
                me->set_temp("perform2", 1);
                if( damage < 300 ) msg += HIY"������ۡ���һ��������$n"+name+"����\n"NOR;
                else if( damage < 400 ) msg += HIY"������ۡ���һ���̽�$n��"+name+"��ʹ$p�������������˼�����\n"NOR;
                else if( damage < 500 ) msg += HIY"��������͡���һ����"+name2+"����$n"+name+"�̳�һ��Ѫ��ģ����Ѫ������\n"NOR;
                else msg += HIR"���ֻ����$nһ���Һ���"+name2+"����$p��"+name+"�Դ���������Ѫ�������أ���\n"NOR;

                if(  (int)me->query_skill("huashan-sword", 1) > 135
                && (int)me->query("neili", 1) > 300
                &&  me->is_fighting(target) 
                &&  me->query_skill_mapped("sword") == "huashan-sword"
                &&  (string)weapon->query("skill_type") == "sword")                
                {
                        call_out("perform3", 0, me);                                  
                }
                else 
                {
                        me->delete_temp("perform"); 
                        me->delete_temp("perform2");
                }
        } 
        else 
        {       me->start_busy(2);
                me->add("neili", -150);                
                me->delete_temp("perform");
                me->delete_temp("perform2");                          
                target->start_busy(1);
                msg += HIY"����$pһ�����Ʒ���ԶԶ�Ķ��˿�ȥ��\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}                                                       

int perform3(object me)
{
        int skill;
        string msg, name, name2;
        object weapon = me->query_temp("weapon");
        object target;
if (!me)  return notify_fail("���Ѿ������ˡ�\n");
        if (!weapon)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
 return notify_fail("��û��������\n");
}
        name2 = weapon->query("name");
        skill = (int)me->query_skill("huashan-sword", 1);                
        skill = skill/10;
        if( !target ) target = offensive_target(me);
        name = name1[random(sizeof(name1))];
        if (!target)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
 return notify_fail("�����Ѿ������ˡ�\n");
}
       
        msg = HIW "\n������$N����"+name2+"��������֧��â��ֻ��һ����âֱ��$n������ɨ��$n��"+name+"��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                                                                       
                call_out("check_fight", 1, me, target);                                 
                me->add("neili", -300);
                me->delete_temp("perform2");              
                me->set_temp("perform3");
                msg += HIR "$nֻ�������澭��������ϢΪ֮һ����ȫ��������Ȼ�᲻�����ˣ�\n" NOR;
                me->add_temp("apply/attack", skill);
                me->add_temp("apply/dodge",  skill);
                me->add_temp("apply/parry",  skill);  
                target->start_busy(1);
                me->start_busy(3);
                target->add("neili", -300);                 
        }
        else 
        {
                me->start_busy(2);
                me->add("neili", -250);
                me->delete_temp("perform2");        
                target->start_busy(2);
                msg += HIY"\n$p��Ϣδ������$P���з����Ľ�â������������æ��Ծ�����ߣ��Ǳ��رܿ���\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

void check_fight(object me, object target, int improve) 
{ 
        object weapon;      


        if (!me)
{
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
      me->delete_temp("perform");                                                    
      me->delete_temp("perform2");                                                    
      me->delete_temp("perform3");                                                    
remove_effect(me, improve);
 return notify_fail("�����Ѿ������ˡ�\n");
}
        if( target->query("qi") <= 50 && me->is_fighting(target) )         
        { 
                remove_effect(me, improve); 
                tell_object(me, HIY"�Է��Ѿ�������Ӧ�������·������������ˡ�\n"NOR);                
        } 
        
        else if (!present(target->query("id"), environment(me)) 
        &&  me->is_fighting(target) ) 
        { 
                remove_effect(me, improve);
                tell_object(me, HIY"�Է��Ѿ�������Ӧ�������·������������ˡ�\n"NOR);                
        }                                                
        
        else if( !living(target) || !present(target->query("id"),environment(me)) ) 
        { 
                remove_effect(me, improve);                                           
                tell_object(me, HIY"�Է��Ѿ�������Ӧ�������·������������ˡ�\n"NOR);
        } 
        
        else if( !me->is_fighting() || !living(me) || me->is_ghost() ) 
        { 
                remove_effect(me, improve);                                                           
                tell_object(target, HIY"���Ѿ�������Ӧ�˶Է�����·������������ˡ�\n"NOR);                          
        } 
        
        else if( !objectp(weapon = me->query_temp("weapon")) 
        || me->query_skill_mapped("sword") != "huashan-sword"
        || (string)weapon->query("skill_type") != "sword" ) 
        { 
                remove_effect(me, improve);             
                tell_object(target, HIY"���Ѿ�������Ӧ�˶Է�����·������������ˡ�\n"NOR);                
                tell_object(me, HIY"�Է��Ѿ�������Ӧ�������·������������ˡ�\n"NOR);
        }

         else call_out("check_fight", 1, me, target, improve); 
         
}
private int remove_effect(object me, int skill)
{     
      skill = (int)me->query_skill("huashan-sword", 1)/10;                
      me->add_temp("apply/attack", -skill);
      me->add_temp("apply/dodge",  -skill);
      me->add_temp("apply/parry",  -skill);  
      me->delete_temp("perform3");                                                    
      tell_object(me, HIY"�Է��Ѿ�������Ӧ�������·������������ˡ�\n"NOR);      
      return 0;
}
