#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_start", "start");
       add_action("do_stop", "stop");
}


void create()
{
       set_name(HIW"רҵ�����"NOR, ({"she xiangji", "xiangji"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
        set("long", "����һ̨רҵ�����,������ȫ,����Ч���ر�á�\n");
               set("value", 1000000000);
               set("unit", "̨");
               set("no_get", "С���ѱ��Ҷ���\n"NOR);
       set("env/invisibility",10);
        set("invisibility",10);
        set("no_clean_up",1);

               set_weight(999999999);
       }
}

int do_start(string arg)
{
       object target, where, npc, me;
       me = this_player();
       
       if( wiz_level(me) < 3)
                return notify_fail("��ô���صĶ������㻹�Ǳ���Ϊ�á�\n"); 
    
       if( me->is_busy() || me->is_fighting())
          return notify_fail("����æ���ء�\n");

       if( !arg)
          return notify_fail("��Ҫ��˭�ء�\n");

       if (objectp(target = LOGIN_D->find_body(arg))) 
            where = environment(target);
       else return notify_fail("û�������Ү������\n");
       
       if (!where) return notify_fail("�����������Ʈ��䣬�Ҳ�������\n");
//        if( !environment(me)->query("bwdhpk"))
//        return notify_fail("���˲��ڱ�����\n");       

       
       if (wizardp(target)) return notify_fail("����͵���߼����䣬��Ҫ���ˣ�\n");

       if (target==me) return notify_fail("�Լ�͵���Լ���\n");

       if(objectp(npc = me->query_temp("jingtou2")))
          return notify_fail("���Ѿ���ʹ��������С�\n");
          
       message_vision(HIY"\n$N����˵��������λע�⣬��ͷ��׼"+target->name()+HIY"�����ģ�\n\n" NOR, me);

     npc = new(__DIR__"jingtou2");
       npc->do_setup(me, target);
       me->set_temp("jingtou2", npc);
       me->start_busy(1);
       add("used", 1);
       return 1;
}


int do_stop()
{
        object npc, me;
        me = this_player();
        
        if(!me->query_temp("jingtou2"))
          return notify_fail("�㻹û��������ء�\n");

        npc = me->query_temp("jingtou2");
        if(objectp(npc))
           npc->do_remove();
        message_vision(HIC"\n$N�������������˵�������㲻���չ���\n\n" NOR, me);
        me->delete_temp("jingtou2");
        me->start_busy(1);
        return 1;
}


