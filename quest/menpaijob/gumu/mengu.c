// Room: /d/death/inn1.c
 
#include <ansi.h>
inherit ROOM;
 
int do_leave(object ob);
 
void create()
{
        set("short", "�ɹŴ������");
        set("long", @LONG
�ɹŴ�����������в����ɹű�,��������,��������Ҵ���,�㿴
������ɹ���,���ɵ����﷢Ŭ,��Ҫ�ɵ�����,������ȥ�����书
�ƺ�����,��������ӵĻ�,�����ļ�(leave).
LONG );
 
       set("objects", ([
               "/quest/menpaijob/gumu/guan" : 1,
]) );

//        set("no_clean_up", 0);
        setup();
//	replace_program(ROOM);
}
 
void init()
{
        add_action("do_leave","leave");
}

int do_leave(object ob)
{
        ob = this_player();
        if(ob->query("kill_gumu") == 1)
{
        ob = this_player();
          if (ob->is_busy())
        return notify_fail("��������æ���ء�\n");
         if (ob->is_fighting() )
         return notify_fail("�������Ӳ��ˣ�\n");
        write(HIW"������һ��,������������򲻹��ɹ���,ֻ�ܳ�����.\n");
        ob->move("/d/xiangyang/southgate2");
        ob->set("kill_gumu", 0);
        ob->apply_condition("menpai_busy",1+random(8));
        write(HIR"�������ӳ����ɹž���Ӫ.\n"NOR);
        return 1;
}
        if(ob->query("kill_gumu") == 0) 
{
        ob = this_player();
          if (ob->is_busy())
        return notify_fail("��������æ���ء�\n");
         if (ob->is_fighting() )
         return notify_fail("�������Ӳ��ˣ�\n");
        write(HIW"�����������,��Ц����,�ó�����.\n");
        ob->move("/d/xiangyang/southgate2");
        write(HIR"�������ӳ����ɹž���Ӫ.\n"NOR);
        return 1;
}
        if(!ob->query("kill_gumu")) 
{
        ob = this_player();
          if (ob->is_busy())
        return notify_fail("��������æ���ء�\n");
         if (ob->is_fighting() )
         return notify_fail("�������Ӳ��ˣ�\n");
        write(HIW"�����������,��Ц����,�ó�����.\n");
        ob->move("/d/xiangyang/southgate2");
        write(HIR"�������ӳ����ɹž���Ӫ.\n"NOR);
        return 1;
}
}
