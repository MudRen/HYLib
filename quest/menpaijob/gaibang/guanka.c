inherit ROOM;

#include <ansi.h>
void create()
{
      set("short","�ؿ�");
      set("long",@LONG
���ﱻ��ʱ���һ���ؿ���һ���佫��ָ�Ӽ���ؤ��ĵ��Ӷ������ο�
���м�飬���տ��Թ���������Աһ�ɲ���ͨ�������������˻����ں���
���佫���ۡ��������ɹſ�Ҫ�����ˣ����ڽ��ϡ�
LONG);
        set("valid_startroom",1);
           set("no_dazuo",1);
           set("renshu",0);
        set("objects",([
                __DIR__"huwei" : 1,
"/d/city/npc/xunbucao" : 2,
//                __DIR__"hua" : 1,
        ]));
        set("exits",([
                "south"  : "d/xiangyang/caodi6",
                "north"  : "d/xiangyang/southgate2",
                "east"  : "d/xiangyang/southgate3",
        ]));
        set("outdoors", "�ؿ�");

        setup();
}

int valid_leave(object me, string dir)
{

        if (me->query_temp("shouwei"))
        return notify_fail("�������������������ܵ����߶���\n");
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");
        if (me->is_busy()) 
        return notify_fail("������������!\n");


        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_quit","halt");
        add_action("do_quit","quit");
         add_action("do_shouwei","shouwei");
}

int do_shouwei()
{
        object me=this_player();
//         me=this_player();
        object* ob;
        int i;
//        ob = users();
//        for (i=sizeof(ob); i>5; i--)
//        {
//                if (ob[i-1]->query_temp("shouwei"))
//                return notify_fail("�������ֻҪ������ء�\n");
//        }
//         if (query("renshu")>=3)
//              return notify_fail("�������ֻҪ�������ء�\n");
            if (!(me->query_temp("xhjob_start")))
                   return notify_fail("��û�б�ָ�ɵ�������������Ҫ������£�\n");
            if (me->query_temp("shouwei"))
                   return notify_fail("�����������ؿ�ͨ����\n");
          message_vision(HIC"$N���Ӿ��񣬿�ʼ������ߵ�ÿһ�����ˡ�\n"NOR, me);

         me->apply_condition("xhquest", 7);
              add("renshu",1);
            me->set_temp("shouwei",1);
          return 1;
}
int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ĵ��ػ���\n");
        return 1;
}
