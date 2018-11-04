#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"Ӧ�ַ�"NOR);
        set("long", @LONG
���ɽ��߷�Ӧ�ַ壬ɽ��ֱ����ϼ����ΰ׳�������ﺮ��̹ǣ�
�����ű�ѩ�������洵��������ɽ·�ϵĻ�ѩ���ѽ�������������治
ס�ش򻬡�
LONG);
        set("outdoors", "dali");

        set("exits", ([             
           "east" : __DIR__"yaotai",
        ]));

        setup();
}

void init()
{
       object me = this_player();
       mapping my_fam  = me->query("family");

       if( random(me->query_skill("dodge",1)) <= 40 && me->query("kar") <5){
               me->receive_damage("qi", 100);
               me->receive_wound("qi",  100);
               message_vision(HIR"$Nһ��С�Ľ���һ����... ��...��\n"NOR, me);
               me->move(__DIR__"ylf1");
               message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع��˹������ֹ�µµ�ع�����ȥ��\n"NOR, environment(me), me);               
               me->move(__DIR__"dc1");
               message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع��˹������ֹ�µµ�ع�����ȥ��\n"NOR, environment(me), me);
               me->move(__DIR__"dc2");
               message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع��˹������ֹ�µµ�ع�����ȥ��\n"NOR, environment(me), me);
               me->move(__DIR__"dc3");
               tell_object(me, HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
               message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
               me->start_busy(2);
               }
            
   else{
       if (my_fam)
       if (my_fam["family_name"] == "����μ�"&&random(10)<2) { 
       me->set_temp("wait", 1);
       call_out("do_wait", 30 + random(10), me);
	   }
       }
}

void do_wait(object me)
{
        if (!me) return;
        if(environment(me) && me->query_temp("wait") && 
           me->query_skill("literate", 1) > 100){
           tell_object(me,HIY"\n��վ�ڷ嶥��������ȥ��ֻ�������ϼ����ҫ��ǧ�������ɽ�壬
�ɰ���䣬������ϴ����¶���飬�������⡣\n"NOR);
           me->del_temp("wait");
           me->add("potential", random(3));
		   me->set("jing",me->query("max_jing"));
           message_vision("\n$Nվ����������������˿�����ֻ������һƬ������������ˬ��\n", me);
          
          }
}

int valid_leave(object me)
{
        if (me->query_temp("wait"))
                me->delete_temp("wait");     
        return 1;
}
