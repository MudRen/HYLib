// room: dong-2.c
// zqb


inherit ROOM;
#include <ansi.h>
string look_bei();
void create()
{
        set("short", HIR"��Ȼ��Ѩ"NOR);
        set("long", @LONG
    ��ʯ��ϵ��Ȼ���ɣ���֮�����˹������ʯ�Ҵ���ʮ������������
ȥ�����ڹ���ʮ��ߺ��ǣ��������ԣ���̬���в�ͬ���еĺ���ɢ���ڵأ�
�е�ȴ�Ծ�������Σ�����Щ��̳��λ֮����ÿ�ߺ���֮�Զ����ű��У���
�����þߣ��䱦������ڴ�����һ��ʯ��(bei)��
LONG
        );
        set("exits", ([
            "out" : __DIR__"dong-3",
        ]));
        set("item_desc",([
        "bei"         :       (: look_bei :),
    ]));

        set("objects", ([
           
        __DIR__"obj/haigu" : 1,  
        __DIR__"obj/ycj" : 1,      
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}
string look_bei()
{
        return
        "\n"
"    �   �ö�������Ʒ��\n"    
        "\n"
RED"        ����Ī�֣�    \n"NOR
        "\n";
}
void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
      object me;
      me=this_player();

      if ((int)me->query_temp("marks/baowu")) 
      {
      if ((int)me->query_str() < 30)
          return notify_fail("��������������޷���ʯ���ƿ���\n");
      if (arg !="bei") 
          return notify_fail("��Ҫ��ʲô����\n");
      write("������������������˿�������ʯ�������������ƿ���\n");
      message("vision",me->name() + "˫���������������ʯ����������ƿ�������¶��һ���ڶ�������ڡ�\n", environment(me),({me}));
      set("exits/enter", __DIR__"taijie-1");
      remove_call_out("close_passage");
      call_out("close_passage", 5);
      return 1;
      }
      return notify_fail("��������\n");
}


void close_passage()
{
      object room;

      if( !query("exits/enter") ) return;
      message("vision", "ʯ������¡¡�������������ƻ�ԭ����\n", this_object() );
      delete("exits/enter");
}


