#include <ansi.h>

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string *pictures = ({"�ľ�����","�������","��������","�����ˮ","�ǻ��չ�","��������","��ʬ����", "ӹ������" });

void remove_effect(object me, int amount);

int perform(object me, object target)
{
      string picture;
        int skill;
      int i, j, z;       
     i = me->query_skill("anranxiaohun-zhang", 1)/5;
     j = me->query_skill("yunv-xinfa", 1)/3; 
     z = me->query_skill("anranxiaohun-zhang",1)/2; 
     picture = pictures[random(sizeof(pictures))];
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ȼֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ʹ�Ʋ���ʹ�ã�\n");	
			
        if( (int)me->query("max_neili") < 1500 )
		return notify_fail("���������ۺ���ʹ����Ȼ��\n");

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");
    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("��Ҫ����Ů�ķ���Ϊ�ڹ������á�\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

       if(me->query_temp("anran")) 
// updated ����->��Ȼ (by xbd)
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 

        if( (int)me->query("jing")  < 200 )
		return notify_fail("��ľ�������\n");

        if( (int)me->query("neili")  < 600 )
		return notify_fail("������û���㹻������ʹ�á�\n");

        if( (int)me->query_skill("anranxiaohun-zhang", 1) < 150 )
		return notify_fail("��Ļ�û�����޷��������Ȼ�˵С�\n");

       if (me->query("eff_qi")+1000 >=me->query("max_qi"))
        return notify_fail("�������ڵ��ľ�����ʹ�÷��ӳ���Ȼ������\n"); 

       if(me->query_skill("yunv-xinfa", 1) < 200 )   
// updated ����->��Ȼ (by xbd)
                return notify_fail("�����Ů�ľ���Ϊ�������޷�ʹ�á���Ȼ��������\n");  


        if (me->query("neili") < 800)
        return notify_fail("�������������\n");
        if (me->query("jing") < 800)
        return notify_fail("��ľ���������\n");

        skill = me->query_skill("anranxiaohun-zhang") / 2;
        me->add("neili", -(me->query_skill("unarmed")+100));
        me->add("jing", -300);
        message_vision(YEL "$Nʹ����Ȼ���꣬�����������Ʋ��ɵ���ԴԴ������������ɽ�������ѹ��$n��\n" NOR, me, target);
        message_vision(HIY"$N����������ݾ�����Ȼ����,����������,һ����Ȼ֮�����Ķ���.û����ɵĻ��������ĳ�һ��"+picture+",
�����Ʒ缤��,�л��㱣�����ԼԼ��ɲʱ��Ȼ��������������,�Ʋ��ɵ�.\n"NOR,me,target);
        me->add_temp("apply/strength", i);
        me->add_temp("apply/attack", j); 
        me->set_temp("anran", 1);

        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill/2);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{        
      int i, j, z;       
     i = me->query_skill("anranxiaohun-zhang", 1)/5;
     j = me->query_skill("yunv-xinfa", 1)/3; 
     z = me->query_skill("anranxiaohun-zhang",1)/2; 
    me->add_temp("apply/strength", -i);
    me->add_temp("apply/attack", -j);
        me->delete_temp("anran");
// updated ����->��Ȼ (by xbd)
    tell_object(me, HIR"�㡸��Ȼ������������ϣ����ص���.\n" NOR);
        message_vision(YEL "\n$N���Ʒ�����Ҳ�ָ�Ѱ���ˡ�\n" NOR, me);
        
}
