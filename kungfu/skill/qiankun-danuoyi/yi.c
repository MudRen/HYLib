// yi.c Ǭ����Ų�ơ��ơ��־�
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, string target)
{
        object ob;
     string msg;
        if(!target)
             return notify_fail("����ѶԷ��ľ���Ų����˭��\n");
        if(!objectp(ob = present(target, environment(me))))
             return notify_fail("����û������Ų�Ƶ�Ŀ������ˡ�\n");

        if(!me->is_fighting())
                return notify_fail("��û�ڴ�ܣ���ʲô�ƣ�\n");


        if ((int)me->query_skill("jiuyang-shengong", 1) < 100)
                return notify_fail("��ľ����񹦻�򻹲�����С���߻���ħ��\n");

        if(!ob->is_character()) 
                return notify_fail("�����һ�㣬�ǲ��������\n");

//       if(userp(ob)) 
//                return notify_fail("�㲻���Ƶ���ͨ�������ȥ!\n");

        if(!living(ob))
		return notify_fail(ob->name()+"�Ѿ��޷�ս���ˡ�\n"); 
	if(ob==me) return notify_fail("�㲻�ܹ����Լ���\n");               

        if(!ob->is_fighting(me) || !me->is_fighting(ob) )
                return notify_fail("��û�к�������ء�\n");

        if(me->query_skill("qiankun-danuoyi", 1) < 120 )
                return notify_fail("���Ǭ����Ų�ƻ�������죬����ʹ�á��ơ��־���\n");
        if(me->query_skill_mapped("parry") != "qiankun-danuoyi")
                return notify_fail("��û��ʹ��Ǭ����Ų����Ϊ�н����޷�ʹ�á��ơ��־���\n"); 
        if((int)me->query("neili") < 800 )
                return notify_fail("�������������\n");
        if((int)me->query_skill("force") < 200 )
                return notify_fail("���ơ��־���Ҫ�����ڹ�����������������󻹲�����\n");
        me->add("neili", -50);
        tell_object(me, BLU"�㰵��Ǭ����Ų�ơ��ơ��־�����ͼҪ�ѶԷ���һ�е�����ת�Ƶ�"+ob->name()+"���ϣ�\n"NOR); 
        me->set_temp("yi_ob", ob->query("id"));     
msg = HIR+me->name()+HIB"һɲ�Ǽ仯��Ϊ��ļ���ת�ۣ���ʹ����Ǭ����Ų���ķ��ĵ��߲��񹦣�\n";
        me->start_busy(1);
        message_vision(msg, me, target);


        return 1;
}
