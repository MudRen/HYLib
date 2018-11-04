// zongjue.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_fight(object me);
void remove_effect(object me, int skill);

int exert(object me, object target)
{
        int skill;
        if( target != me ) return
            notify_fail("��ֻ�ܶ��Լ���["+HIG+"�򷨹���"+NOR+"]\n"NOR,);

        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("���Ѿ���������ˡ�\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("���Ѿ�����̫�����ˡ�\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("���Ѿ����˿����޵й��ˡ�\n");
        if( (int)me->query_temp("liuyun") ) 
            return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");
        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");
        if( (int)me->query_temp("powerup") )
        	return notify_fail("���Ѿ����˱���ڹ����ˡ�\n");
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");
        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

	if ((int)me->query_skill("force", 1) < 400)
		return notify_fail("��Ļ����ڹ�̫���ˡ�\n");
        if( (int)me->query("neili") < 500 )
        	return notify_fail("�������������\n");

        if( (int)me->query_temp("hslj/powerup") )
        	return notify_fail("���Ѿ����˹����ˡ�\n");
	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");
        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");
        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");
	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

	me->set_temp("hslj/powerup", 1);
        skill = me->query_skill("force");

        me->add("neili", -me->query("max_neili")/7);

if (skill > 1000) skill = 1000;
        message_combatd(HIM"$N�ۺϱ������⹦���򷨾����ڵ��ǧ�й�����ȫ��\n" NOR, me);
        me->add_temp("apply/armor", skill/2);
  tell_object(me,HIG"��ķ����������!\n"NOR);
        me->add_temp("apply/attack", skill/4);
  tell_object(me,HIG"��Ĺ����������!\n"NOR);
        me->add_temp("apply/dodge", skill/4);
  tell_object(me,HIG"��Ķ����������!\n"NOR);
        me->add_temp("apply/defense", skill/4);
  tell_object(me,HIG"��ķ����������!\n"NOR);
        me->add_temp("apply/damage", skill/3);
  tell_object(me,HIG"���ɱ���������!\n"NOR);
        me->add_temp("apply/strength",skill/20);
  tell_object(me,HIG"������������!\n"NOR);
        me->add_temp("apply/dexerity",skill/20);
  tell_object(me,HIG"����ٶ������!\n"NOR);
        me->add_temp("apply/constitution",skill/20);
  tell_object(me,HIG"��ĸ��������!\n"NOR);
        me->add_temp("apply/intelligence",skill/20);
  tell_object(me,HIG"������������!\n"NOR);
	check_fight(me);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

int check_fight(object me)
{
	if (!me || !(int)me->query_temp("hslj/powerup")) return 0;
        if (!me->is_ghost() && living(me)
            && me->is_fighting() && me->query("neili") > 800
            && me->query_skill_mapped("force") != "jiuyin-zhengong")
        {
                if(me->query("qi") < (int)me->query("max_qi")){
                        message_vision(HIW"$Nͷ��������һ������ָֻ��������ھ����硣\n"NOR,me);
                        me->add("neili", -80);
                        me->add("eff_qi",me->query_skill("force")/2);
			if (me->query("eff_qi") > me->query("max_qi")) me->set("eff_qi", me->query("max_qi"));
                        me->add("qi",me->query_skill("force"));
			if (me->query("qi") > me->query("eff_qi")) me->set("qi", me->query("eff_qi"));
                        }
        }
        call_out("check_fight", 2, me);
        return 1;
}       

void remove_effect(object me, int skill)
{
        me->delete_temp("hslj/powerup");
        me->add_temp("apply/armor", -skill/2);
        me->add_temp("apply/attack", -skill/4);
        me->add_temp("apply/dodge", -skill/4);
        me->add_temp("apply/defense", -skill/4);
        me->add_temp("apply/damage", -skill/3);
        me->add_temp("apply/strength",-skill/20);
        me->add_temp("apply/dexerity",-skill/20);
        me->add_temp("apply/constitution",-skill/20);
        me->add_temp("apply/intelligence",-skill/20);
        tell_object(me, "���["+HIG+"�򷨹���"+NOR+"]������ϡ����ֱ����������\n");
}

