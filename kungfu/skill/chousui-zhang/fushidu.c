// ��ʬ��
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        
       object co,weapon;
        /* i, j;
        i = me->query_skill("chousui-zhang", 1);
        j = me->query_skill("strike")/2;*/

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("����ʬ����ֻ����ս���жԶ���ʹ�á�\n");
weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "staff")
		return notify_fail("�������ֲ���ʹ�����������\n");		

        if( (int)me->query_skill("chousui-zhang", 1) < 220 )
                return notify_fail("������޶��ƻ�������죬ʹ��������ʬ����������\n");

        if( (int)me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("��Ļ�������Ϊ����������ʹ�á���ʬ������\n");
        if((int)me->query_skill("poison",1)<120)
           return notify_fail("����������޷�ʹ�ø�ʬ����\n"); 
           co=present("corpse",me);       
        if (!co)
        return notify_fail("������û��ʬ�壬���ʹ�ø�ʬ��!\n");

                                                                         

        if( (int)me->query("max_neili") < 1000) 
                return notify_fail("������̫����ʹ��������ʬ������\n");      

        if( (int)me->query("neili") < 300)
                return notify_fail("����������̫����ʹ��������ʬ������\n");
       message_vision(BLU"\n$Nһ����Ц������ͻ����Ю��һ��ʬ��������һ����������ĳ����������ܣ�������Ż��\n"NOR,me);
       call_out("destroying", 1, co);
//         if (!target->is_killing(me))
//me->kill_ob(target);
//       target->kill_ob(me);
       me->add("neili", -250);
       if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/5*3&&
            me->query_str() > (int)target->query_str()/3*2) 
      { 
       message_vision(HIB"\n$n���˹���������������޴룬�����޼���ֻ��ɢ���Ŷ����ʬ�壬�������Լ����ϡ�\n"NOR, me, target);
       target->set_temp("last_damage_from", "��ʬ������");
       target->unconcious();
       return 1;  
        }
        else if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4&&
          me->query_str() > (int)target->query_str()/2) 
        {
          message_vision(HIB"\n$n ���²��ã���æ����ֱ�𣬸�ʬ�������ӹ���û�д��С�\n"NOR,me,target);
          tell_object(target,HIB"\n ����Ȼ��ʱ�ܿ��˶�ʬ����һ���ȳ�����ǣ��������˾綾�ˡ�\n"NOR);
// no condition fs_poison, change to xx_poison (by xbd)
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("corpse_poison",60);
target->apply_condition("fire_poison",60);

          target->apply_condition("xx_poison", random(100) + 
           (me->query_skill("poison", 1)/10) +
           target->query_condition("xx_poison"));
         me->start_busy(5);
        target->start_busy(1);
        return 1;
      }
       message_vision(HIB"\n$n ���г���һ����Х��˫�������������Ѷ�ʬ����������·��\n"NOR,me,target);
       tell_object(me,HIB"\n ���ã���ʬ��������,����Ȼ�㿪��������Ҳ����������塣\n"NOR);
// no condition fs_poison, change to xx_poison (by xbd)
                 me->apply_condition("xx_poison", random(3) + 
           (me->query_skill("poison", 1)/10) +
           me->query_condition("xx_poison"));
       return 1;
 }          

void destroying(object obj)
{
        destruct(obj);
        return;
}
  
