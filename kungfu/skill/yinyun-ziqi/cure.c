// cure.c��������

#include <ansi.h>
// inherit F_CLEAN_UP;

int exert(object me, string arg)
{
	object ob;

        ob = present(arg, environment(me));
        if (!userp(ob)) return notify_fail("��Ҫ��˭�˹�����ѽ��\n");
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ��˭�˹�����ѽ��\n");

        if( me->is_fighting() )
                return notify_fail("ս���в��ܾ��������ˣ�\n");

        if( me->is_busy() )
                return notify_fail("����æ���أ�\n");
  
        if ((int)me->query_skill("yinyun-ziqi", 1) < 120)
                return notify_fail("�����������Ϊ��������\n");

        if ((int)me->query_skill("taoism", 1) < 140)
                return notify_fail("��ĵ����ķ���Ϊ��������\n");

        if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 2 )
                return notify_fail("������Ԫ�������޷�����������\n");

    if( ob==me ) {
        if( (int)me->query_condition("juehu_hurt") <= 0 )
                return notify_fail("�㲢û�����ˣ�\n");
        if( (int)me->query_skill("taoism",1)<150 )
                return notify_fail("�������Ϊ�������Լ����ˣ�\n");

        write( HIW "����ϥ���������ص����ʼ�߽�ȫ��������ͨ����Ѩ��\n" NOR);
        message("vision",
                HIR + me->name() + "��ϥ��������ɫԽ��Խ�죬�����졣\n" NOR,
                environment(me), me);
        if(me->query("neili",1)< 1400||me->query("jingli",1)<700)
        {write(RED "��ͻȻ�������٣��������ѣ�����������ʱʧ�أ����彩Ӳ�ص��ڵ��ϡ�\n" NOR);
         me->start_busy(10);
         me->add("max_neili",-20);
         me->set("neili",1);
         me->set("jingli",1);
         write(HIY "ԭ����������֧���˹��߻���ħ!\n"NOR);
         message("vision",
                HIY + me->name() + "��ɫ��䣬��֫��Ӳ��һͷ���ڵ��ϣ������������١�\n" NOR,
                environment(me), me);
         }
        else
        {write(RED "�㵤������Խ��Խ�࣬�о�Խ��Խ�ȣ�Ѩ��֮�����絶�\n��--!����һ����ȫ�������ڴ�ͨ������ů�������������!\n" NOR);
         message("vision",
                RED + me->name() + "��--!�³�һ����Ѫ����ɫҲ�������������۾������䣬���ɱ��ӡ�\n" NOR,
                environment(me), me);
         me->clear_condition("juehu_hurt");
         if (me->query("genderbak")== "����")
             me->set("gender","����");

         me->start_busy(3);
         me->set("neili",1);
         me->set("jingli",1);
         me->add("max_neili",-(430-(int)me->query_skill("yinyun_ziqi",1)-(int)me->query_skill("taoism",1)));
         me->add("combat_exp", 10*((int)me->query_skill("yinyun_ziqi",1)+(int)me->query_skill("taoism",1)));
         }
     }
     else
     {
	if( (int)arg->query_condition("juehu_hurt") <= 0 )
            return notify_fail(ob->query("name")+"��û�����ˣ�\n");

        message_vision(HIY"$N�����ķ���$n�İٻ�Ѩ�ϣ�������ζ�������������֮��!\n"NOR,me,ob);
        if(me->query("neili",1)< 1300||me->query("jingli",1)<650)
        {write(RED "��ͻȻ�������٣��������ѣ�����������ʱʧ�أ����彩Ӳ�ص��ڵ��ϡ�\n" NOR);
         me->start_busy(10);
         me->add("max_neili",-15);
         me->add("max_jingli",-10);
         me->set("jingli",1);
         me->set("neili",1);
         write(HIY "ԭ����������֧���˹��߻���ħ!\n"NOR);
         tell_object(ob, RED "���Ȼ�е���ͷ������������Ĵ��Ҵڣ�������ʹ���ѹ����¡�\n" NOR );
         message("vision",
                HIY + me->name() + "��ɫ��䣬��֫��Ӳ��һͷ���ڵ��ϣ������������١�\n" NOR,
                environment(me), me);
         ob->add("max_jingli",-5);
         ob->unconcious();
         }
        else
        {write(RED "���𽥼�����������ٻ㣬���ζ����۵��ֱ�����Ѩ��\n"NOR);
         tell_object(ob, RED "��е�һ�������ɰٻ���룬���ζ����۵��ֱ�������Ѩ��ȫ�������ѵ���\nԭ�ȵ�����֮���ʱ����!\n"NOR );
         ob->clear_condition("juehu_hurt");
         if (ob->query("genderbak")== "����")
             ob->set("gender","����");
         message_vision(RED"$N��--!�³�һ���Ⱥ��Ѫ����ɫ�ָ��˺���\n"NOR, ob);
         ob->add("max_jingli",-5);
         me->start_busy(3);
         me->set("jingli",1);
         me->set("neili",1);
         me->add("max_neili",-(int)(420-(int)me->query_skill("yinyun_ziqi",1)-(int)me->query_skill("taoism",1))/2);
         me->add("combat_exp", 4*((int)me->query_skill("yinyun_ziqi",1)+(int)me->query_skill("taoism",1)));
         }
     }
      return 1;
}
